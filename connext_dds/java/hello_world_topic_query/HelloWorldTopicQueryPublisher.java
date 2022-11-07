import com.rti.dds.domain.*;
import com.rti.dds.infrastructure.*;
import com.rti.dds.topic.*;


public class HelloWorldTopicQueryPublisher {
    
    private HelloWorldTopicQueryPublisherParams params;
    private DomainParticipant participant;
    private HelloWorldTopicQueryDataWriter writer;  
    private HelloWorldTopicQuery instance = new HelloWorldTopicQuery();
    private boolean isRunning;    
    
    HelloWorldTopicQueryPublisher(
            HelloWorldTopicQueryPublisherParams params) {
        
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
        
        /* Topic. */
        Topic topic = this.participant.create_topic(
                    "Example HelloWorldTopicQuery", 
                    HelloWorldTopicQueryTypeSupport.get_type_name(), 
                    DomainParticipant.TOPIC_QOS_DEFAULT, 
                    null, 
                    StatusKind.STATUS_MASK_NONE);                
        
        /* 
         * QoS configuration to enable TopicQueries in DataWriter is in file 
         * USER_QOS_PROFILES.xml. 
         */
        this.writer = (HelloWorldTopicQueryDataWriter) 
                this.participant.create_datawriter_with_profile(
                    topic,
                    "HelloWorldTopicQuery_Library",
                    "HelloWorldTopicQuery_Profile",
                    null,
                    StatusKind.STATUS_MASK_NONE);
        if (this.writer == null) {
            throw new RuntimeException("create writer error");
        }                              
        
        /* Add a shutdown hook for graceful cleanup. */
        Runtime.getRuntime().addShutdownHook(new Thread() {
            @Override
            public void run() {      
                HelloWorldTopicQueryPublisher publisherApp =
                        HelloWorldTopicQueryPublisher.this;
                
                /* 
                 * Setting this to false will cause the start() operation to
                 * exit the loop. 
                 */
                publisherApp.isRunning = false;
                try {
                    /* 
                     * The Java application will exit as soon as the the hook
                     * returns, so we wait for the deletion of the DDS entities to 
                     * complete. 
                     */
                    synchronized (publisherApp) {
                        publisherApp.wait(10000);
                    }
                } catch (InterruptedException ie) {
                }
            }
        });
                
    }
    
    private void writeSample(int count) {
        System.out.println("Writing HelloWorldTopicQuery, count " + ++count);
        /* Modify the instance to be written here. */
        if (this.params.lowerInstanceId >= 0) {
            this.instance.id = this.params.upperInstanceId < 0
                    ? count % (this.params.lowerInstanceId + 1)
                    : count % this.params.upperInstanceId - this.params.lowerInstanceId;
        } else {
            this.instance.id = count;
        }
        this.instance.message = "count: " + count;
        InstanceHandle_t instance_handle = InstanceHandle_t.HANDLE_NIL;   
        this.writer.write(instance, instance_handle);
    }       
    
    /**
     * Writing logic of the application.
     * 
     * There are two write phases:
     * - A single initial burst of initialBurstSize samples.
     * - A periodic phase that writes up to sentSampleCount samples every
     *  writePeriod.
     * 
     * @see HelloWorldTopicQueryPublisherParams
     */
    public void start() {
            
        this.isRunning = true;
        /* Initial burst */
        int count;
        for (count = 0; count < this.params.initialBurstSize; count++) {
            this.writeSample(count);
        }
        
        /* Periodic send. */
        while (HelloWorldTopicQueryPublisher.this.isRunning &&
                (this.params.sentSampleCount < 0 ||
                    count < this.params.sentSampleCount)) {            
            try {
                Thread.sleep(this.params.writePeriod.sec * 1000);
            } catch (InterruptedException ix) {
                System.err.println("INTERRUPTED");
                break;
            }
            
            this.writeSample(count);
            count++;
        }
    }
    
    /**
     * Performs the deletion of the DDS entities.
     */
    public synchronized void stop() {        
        System.out.println("Shutting down...");        
        if (this.participant != null) {
            this.participant.delete_contained_entities();
            this.writer = null;
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
    
    public static void main(String[] args) {
        
        HelloWorldTopicQueryPublisherParams appParams = 
                new HelloWorldTopicQueryPublisherParams();
        try { 
             HelloWorldTopicQueryPublisherParams.parseCommandLine(
                     appParams, 
                     args);
        } catch (Exception e) {
            System.out.println(e.getMessage());
            HelloWorldTopicQueryPublisherParams.printUsage();
            System.exit(1);
        }
        
        HelloWorldTopicQueryPublisher publisherApp =
                new HelloWorldTopicQueryPublisher(appParams);
        
        publisherApp.start();   
        publisherApp.stop();
    }    
}

/**
 * Configuration options of the subscriber application.
 */
class HelloWorldTopicQueryPublisherParams {

    /* Domain id the participant belongs to. */
    public int domainId = 0;
    /* Number of samples the application writes before shuting down. */
    public int sentSampleCount = -1;
    /* Selects the instance Id range the application writes samples for. */
    public int lowerInstanceId = 0;
    public int upperInstanceId = -1;
    /* Write period. */
    public Duration_t writePeriod = new Duration_t(4,0);
    /* Number of samples the application writes in burst mode before periodic. */
    public int initialBurstSize = 0;
    
    HelloWorldTopicQueryPublisherParams () {}

    static void parseCommandLine(
            HelloWorldTopicQueryPublisherParams params, 
            String[] args) {

        for (int i = 0; i < args.length; i++) {
            switch (args[i]) {
                case "-d":
                case "-domainId":
                    params.domainId = Integer.parseInt(args[++i]);
                    break;
                case "-c":
                case "-sampleCount":
                    params.sentSampleCount = Integer.parseInt(args[++i]);
                    break;
                case "-l":
                case "-lowInstanceId":
                    params.lowerInstanceId = Integer.parseInt(args[++i]);
                    break;
                case "-u":
                case "-upperInstanceId":
                    params.upperInstanceId = Integer.parseInt(args[++i]);
                    break;
                case "-p":
                case "-period":
                    params.writePeriod = Duration_t.from_seconds(
                            Integer.parseInt(args[++i]));
                    break;    
                case "-b":
                case "-burst":
                    params.initialBurstSize = Integer.parseInt(args[++i]);
                    break;
                default:                    
                    throw new IllegalArgumentException(
                            "Unrecognized option " + "'" + args[i] +  "'");
            }
        }
    }
    
    static void printUsage() {
        StringBuilder format = new StringBuilder();
        format.append("Usage: HelloWorldTopicQueryPublisher [options]\n");
        format.append("\t-d <domainId>              default: 0\n");
        format.append("\t-c <count>                 default: -1 (infinite)\n");
        format.append("\t-l <lowerInstanceId>       default: 0-\n");
        format.append("\t-u <upperInstanceId>       default: -1 (no upper limit)\n");
        format.append("\t-p <period>                default: 4s\n");
        format.append("\t-b <burstSize>             default: 0\n");
        System.out.print(format);            
    }

}