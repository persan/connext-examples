import com.rti.dds.domain.*;
import com.rti.dds.infrastructure.*;
import com.rti.dds.subscription.*;
import com.rti.dds.topic.*;


public class HelloWorldTopicQuerySubscriber {
    
    private HelloWorldTopicQuerySubscriberParams params;
    private DomainParticipant participant;
    private HelloWorldTopicQueryDataReader reader;
    private WaitSet waitSet;
    private ReadCondition topicQueryReadCondition;
    private ReadCondition liveStreamReadCondition;
    private GuardCondition exitCondition;
    private int sampleCount;
    
    static final Duration_t READ_PERIOD = Duration_t.from_seconds(2);
    
    HelloWorldTopicQuerySubscriber(
            HelloWorldTopicQuerySubscriberParams params) {
        
        this.params = params;                
        
        /* Participant. */
        this.participant = DomainParticipantFactory.get_instance().
                create_participant_with_profile(
                    this.params.domainId,
                    "HelloWorldTopicQuery_Library",
                    "HelloWorldTopicQuery_Profile",
                    null,
                    StatusKind.STATUS_MASK_NONE);
        if (this.participant == null) {
            throw new RuntimeException("create participant error");
        }
        HelloWorldTopicQueryTypeSupport.register_type(
                this.participant, 
                HelloWorldTopicQueryTypeSupport.get_type_name());
        
        /* Topic and CFT if required. */
        TopicDescription topicDescription = (TopicDescription) 
                this.participant.create_topic(
                    "Example HelloWorldTopicQuery", 
                    HelloWorldTopicQueryTypeSupport.get_type_name(), 
                    DomainParticipant.TOPIC_QOS_DEFAULT, 
                    null, 
                    StatusKind.STATUS_MASK_NONE);        
        if (params.subscribedInstanceId >= 0) {
            topicDescription = (TopicDescription) 
                    this.participant.create_contentfilteredtopic(
                        HelloWorldTopicQuerySubscriber.class.getName() + "_cft", 
                        (Topic) topicDescription, 
                        "id = " + params.subscribedInstanceId, 
                        null);            
        }
        if (topicDescription == null) {
            throw new RuntimeException("create topic description error");
        }
        
        /* 
         * QoS configuration to enable TopicQueries in DataReader is in file 
         * USER_QOS_PROFILES.xml.
         */                               
        this.reader = (HelloWorldTopicQueryDataReader )
                this.participant.create_datareader_with_profile(
                    topicDescription, 
                    "HelloWorldTopicQuery_Library",
                    "HelloWorldTopicQuery_Profile",
                    null, 
                    StatusKind.STATUS_MASK_NONE);
        if (this.reader == null) {
            throw new RuntimeException("create reader error");
        }               
        
        /* WaitSet and Conditions. */
        this.waitSet = new WaitSet();        
        /* Read Condition for TQ stream only. */
        ReadConditionParams readConditionParams = 
                new ReadConditionParams();
        readConditionParams.stream_kinds = StreamKind.TOPIC_QUERY_STREAM;
        this.topicQueryReadCondition = 
                this.reader.create_readcondition_w_params(readConditionParams);
        if (this.topicQueryReadCondition == null) {
            throw new RuntimeException(
                    "create topic query stream read condition error");
        }                
        /* Read Condition for live stream. */
        readConditionParams.stream_kinds = StreamKind.LIVE_STREAM;
        this.liveStreamReadCondition =
                this.reader.create_readcondition_w_params(readConditionParams);
        if (this.liveStreamReadCondition == null) {
            throw new RuntimeException(
                    "create live steram read condition error");
        }
        
        /* Add a shutdown hook for graceful cleanup. */
        this.exitCondition = new GuardCondition();        
        Runtime.getRuntime().addShutdownHook(new Thread() {
            @Override
            public void run() {      
                HelloWorldTopicQuerySubscriber subscriberApp =
                        HelloWorldTopicQuerySubscriber.this;
                
                /* 
                 * When the hook is invoked, the main thread may be blocked
                 * in the WaitSet, so we need to attach and trigger a special
                 * condition that will force the WaitSet to wake up. 
                 */
                subscriberApp.waitSet.attach_condition(
                        subscriberApp.exitCondition); 
                subscriberApp.exitCondition.set_trigger_value(true);
                try {
                    /* 
                     * The Java application will exit as soon as the the hook
                     * returns, so we wait for the deletion of the DDS entities to 
                     * complete. 
                     */
                    synchronized(subscriberApp) {
                        subscriberApp.wait(10000);
                    }
                } catch (InterruptedException ie) {}
            }
        });
                
    }
    
    /**
     * Takes the available samples and prints their content.
     * 
     * The operation will determine whether a sample belongs to a TopicQuery
     * stream or to the live stream, and print a header accordingly.
     * 
     * @return True if more samples are expected or false otherwise.
     */
    private boolean processSamples(ReadCondition readCondition) {
        HelloWorldTopicQuerySeq receivedSamples = new HelloWorldTopicQuerySeq();
        SampleInfoSeq sampleInfos = new SampleInfoSeq();
        try {
            this.reader.take_w_condition(
                    receivedSamples,
                    sampleInfos,
                    ResourceLimitsQosPolicy.LENGTH_UNLIMITED,
                    readCondition);
            for (int i = 0; i < receivedSamples.size(); i++) {
                HelloWorldTopicQuery sample = (HelloWorldTopicQuery) receivedSamples.get(i);
                SampleInfo info = (SampleInfo) sampleInfos.get(i);
                HelloWorldTopicQuerySubscriber.printReceivedSample(sample, info);
                this.sampleCount++;
                /*
                 * If we are processing samples for a TopicQuery, we may indicate
                 * that no more samples are expected if the corresponding flag is 
                 * present. 
                 * Note that such flag will be set by each DataWriter that
                 * accepts the TopicQuery. This example assumes that an instance is
                 * published by only one DataWriter .
                 */   
                boolean isLastTopicQuerySample = 
                        (info.flag & SampleFlagBits.INTERMEDIATE_TOPIC_QUERY_SAMPLE) == 0;
                boolean isTopicQuerySample = !info.topic_query_guid.equals(GUID_t.GUID_UNKNOWN);
                if (isTopicQuerySample && 
                        isLastTopicQuerySample &&
                        this.params.subscribedInstanceId >= 0) {             
                    return false;
                }
            }
        } catch (RETCODE_NO_DATA rnde) {
        } finally {
            this.reader.return_loan(receivedSamples, sampleInfos);
        }
        
        return true;
    }
    
    /**
     * Waits and processes samples for a maximum amount of time.
     */
    private void waitForSamples(Duration_t maxWait) {
        Duration_t waitTime = new Duration_t(maxWait); 
        ConditionSeq activeConditions = new ConditionSeq();                
        while (waitTime.sec >= 0 && waitTime.nanosec >= 0) {     
            try {                                                  
                long startTime = System.nanoTime();
                this.waitSet.wait(activeConditions, waitTime);
                for (int i = 0; i < activeConditions.size(); i++) {
                    if (this.exitCondition == activeConditions.get(i)) {
                        return;
                    }
                    if (!this.processSamples((ReadCondition) activeConditions.get(i))) {
                        return;
                    }
                }
                waitTime.subtract(Duration_t.from_nanos(
                        System.nanoTime() - startTime));                
            } catch (RETCODE_TIMEOUT rte) {    
                break;
            }
        }
    }
    
    /**
     * Waits until the specified number of samples have been received and 
     * processed.
     */
    private void waitForSamples(int maxSampleCount) {
        ConditionSeq activeConditions = new ConditionSeq();

        while (maxSampleCount < 0 || this.sampleCount < maxSampleCount) {
            try {                
                this.waitSet.wait(activeConditions, READ_PERIOD);
                for (int i = 0; i < activeConditions.size(); i++) {
                    if (this.exitCondition == activeConditions.get(i)) {
                        return;
                    }
                    this.processSamples((ReadCondition) activeConditions.get(i));
                }
            }catch (RETCODE_TIMEOUT rte) {
            }            
        }
    }
    
    
    /**
     * Reading logic of the application.
     *
     * There are two phases: 
     * - An initial phase in which the application processes only TopicQuery
     * samples for up to topicQueryWaitDuration.
     * - A periodic read phase in which the application processes both 
     * TopicQuery and live samples for up to receivedSampleCount samples.
     *
     * @see HelloWorldTopicQuerySubscriberParams
     */
    public void start() {
                        
        /* 
         * Create a TopicQuery to receive the samples published before the
         * creation of this reader. 
         */
        TopicQuerySelection selection;
        /* Explicitly set the expression when the DataReader does not use a CFT. */
        if (this.params.subscribedInstanceId < 0) {
            selection = DataReader.TOPIC_QUERY_SELECTION_SELECT_ALL;            
        } else {
            selection = DataReader.TOPIC_QUERY_SELECTION_USE_READER_CONTENT_FILTER;
        }
        TopicQuery topicQuery = this.reader.create_topic_query(selection);
        if (topicQuery == null) {
            throw new RuntimeException("create topic query error");
        }               
        
        /* Get first TopicQuery samples. */
        this.waitSet.attach_condition(this.topicQueryReadCondition);
        System.out.println("HelloWorldTopicQuerySubscriber waiting for the first sample");
        this.waitForSamples(this.params.topicQueryWaitDuration);   
        /* Read both live and topic query samples. */
        this.waitSet.attach_condition(this.liveStreamReadCondition);
        /* Wait until all of the samples have been received. */
        this.waitForSamples(this.params.receivedSampleCount);      
    }
    
    /**
     * Performs the deletion of the DDS entities.
     */
    public synchronized void stop() {        
        System.out.println("Shutting down...");
        if (this.reader != null) {
            /* Delete any existing ReadCondition and TopicQuery. */
            this.reader.delete_contained_entities();
        }
        if (this.participant != null) {
            this.participant.delete_contained_entities();
            this.reader = null;
            DomainParticipantFactory.get_instance().delete_participant(
                    this.participant);
            this.participant = null;
        }        
        System.out.println("Done");
         /* 
          * This is required in case the shutdown hook is invoked and it's
          * waiting for the stop to complete. 
          */
        this.notify();
    }
            
    private static void printReceivedSample(
            HelloWorldTopicQuery sample,
            SampleInfo info) {   
        StringBuilder output = new StringBuilder();
        if (!info.topic_query_guid.equals(GUID_t.GUID_UNKNOWN)) {
            output.append("Received TopicQuery sample with GUID ");
            output.append(guidToString(info.topic_query_guid));
        } else {
            output.append("Received live sample");
        }
        output.append(sample);
        System.out.println(output);
    }
    
    private static String guidToString(GUID_t guid) {
        
        StringBuilder guidAsString = new StringBuilder();
        for (int i = 0; i < guid.value.length; i++) {
            guidAsString.append(String.format("%1X", guid.value[i]));
        }
        
        return guidAsString.toString();
    }
            
    
    public static void main(String[] args) {
        
        HelloWorldTopicQuerySubscriberParams appParams = 
                new HelloWorldTopicQuerySubscriberParams();
        try { 
             HelloWorldTopicQuerySubscriberParams.parseCommandLine(
                     appParams, 
                     args);
        } catch (Exception e) {
            System.out.println(e.getMessage());
            HelloWorldTopicQuerySubscriberParams.printUsage();
            System.exit(1);
        }
        
        HelloWorldTopicQuerySubscriber subscriberApp =
                new HelloWorldTopicQuerySubscriber(appParams);
        
        subscriberApp.start();   
        subscriberApp.stop();
    }    
}

/**
 * Configuration options of the subscriber application.
 */
class HelloWorldTopicQuerySubscriberParams {

    /* Domain id the participant belongs to. */
    public int domainId = 0;
    /* 
     * Indicates the  number of samples the application shall receive
     * before shutting down. 
     */
    public int receivedSampleCount = -1;
    /* Selects the instance that the application wants to receive data for. */
    public int subscribedInstanceId = -1;
    /* 
     * Indicates an initial time interval the application waits for reception of
     * TopicQuery samples before reading live data. 
     */
    public Duration_t topicQueryWaitDuration = new Duration_t(0, 0);
    
    HelloWorldTopicQuerySubscriberParams () {}

    static void parseCommandLine(
            HelloWorldTopicQuerySubscriberParams params, 
            String[] args) {

        for (int i = 0; i < args.length; i++) {
            switch (args[i]) {
                case "-d":
                case "-domainId":
                    params.domainId = Integer.parseInt(args[++i]);
                    break;
                case "-c":
                case "-sampleCount":
                    params.receivedSampleCount = Integer.parseInt(args[++i]);
                    break;
                case "-i":
                case "-instanceId":
                    params.subscribedInstanceId = Integer.parseInt(args[++i]);
                    break;
                case "-t":
                case "-topicQueryWaitMax":
                    params.topicQueryWaitDuration = Duration_t.from_seconds(
                            Integer.parseInt(args[++i]));
                    break;
                default:                    
                    throw new IllegalArgumentException(
                            "Unrecognized option " + "'" + args[i] +  "'");
            }
        }
    }
    
    static void printUsage() {
        StringBuilder format = new StringBuilder();
        format.append("Usage: HelloWorldTopicQuerySubscriber [options]\n");
        format.append("\t-d <domainId>              default: 0\n");
        format.append("\t-c <count>           default: -1 (infinite)\n");
        format.append("\t-i <instanceId>            default: -1 (all)\n");
        format.append("\t-t <topicQueryWaitMax>     default: 0s\n");
        System.out.print(format);            
    }

}

