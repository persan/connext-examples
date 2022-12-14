

/* HelloWorldPublisher.java

   A publication of data of type HelloWorld

   This file is derived from code automatically generated by the rtiddsgen 
   command:

   rtiddsgen -language java -example <arch> HelloWorld.idl

   Example publication of type HelloWorld automatically generated by 
   'rtiddsgen'. To test them follow these steps:

   (1) Compile this file and the example subscription.

   (2) Start the subscription on the same domain used for RTI Connext with the command
       java HelloWorldSubscriber <domain_id> <sample_count>
       
   (3) Start the publication on the same domain used for RTI Connext with the command
       java HelloWorldPublisher <domain_id> <sample_count>

   (4) [Optional] Specify the list of discovery initial peers and 
       multicast receive addresses via an environment variable or a file 
       (in the current working directory) called NDDS_DISCOVERY_PEERS.  
       
   You can run any number of publishers and subscribers programs, and can 
   add and remove them dynamically from the domain.
              
   Example:
        
       To run the example application on domain <domain_id>:
            
       Ensure that $(NDDSHOME)/lib/<arch> is on the dynamic library path for
       Java.                       
       
        On Unix: 
             add $(NDDSHOME)/lib/<arch> to the 'LD_LIBRARY_PATH' environment
             variable
                                         
        On Windows:
                    add $(NDDSHOME)\lib\<arch> to the 'Path' environment variable
                        

       Run the Java applications:
       
        java -Djava.ext.dirs=$(NDDSHOME)/class HelloWorldPublisher <domain_id>

        java -Djava.ext.dirs=$(NDDSHOME)/class HelloWorldSubscriber <domain_id>        

       
       
modification history
------------ -------         
*/

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Arrays;

import com.rti.dds.domain.*;
import com.rti.dds.infrastructure.*;
import com.rti.dds.publication.*;
import com.rti.dds.topic.*;
import com.rti.ndds.config.*;

// ===========================================================================

public class HelloWorldPublisher {
    // -----------------------------------------------------------------------
    // Public Methods
    // -----------------------------------------------------------------------
    
    public static void main(String[] args) {
        // --- Get domain ID --- //
        int domainId = 0;
        if (args.length >= 1) {
            domainId = Integer.valueOf(args[0]).intValue();
        }

        // -- Get max loop count; 0 means infinite loop --- //
        int sampleCount = 0;
        if (args.length >= 2) {
            sampleCount = Integer.valueOf(args[1]).intValue();
        }
        
        /* Uncomment this to turn on additional logging
        Logger.get_instance().set_verbosity_by_category(
            LogCategory.NDDS_CONFIG_LOG_CATEGORY_API,
            LogVerbosity.NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
        */
        
        // --- Run --- //
        publisherMain(domainId, sampleCount);
    }
    
    
    // -----------------------------------------------------------------------
    // Private Methods
    // -----------------------------------------------------------------------
    
    // --- Constructors: -----------------------------------------------------
    
    private HelloWorldPublisher() {
        super();
    }
    
    
    // -----------------------------------------------------------------------
    
    private static void publisherMain(int domainId, int sampleCount) {

        DomainParticipant participant = null;
        Publisher publisher = null;
        Topic topic = null;
        HelloWorldDataWriter writer = null;
        DomainParticipantQos participant_qos = new DomainParticipantQos();

        String WAN_SERVER = "127.0.0.1";
        String WAN_ID = "1";
        boolean USE_SECURITY = false;
        String WAN_LIB = "nddstransportwan";
        String RTI_EXAMPLES_PATH = "../../../";

        try {
            // --- Create participant --- //
                       
            /* Get default participant QoS from participant factory */
            DomainParticipantFactory.TheParticipantFactory.get_default_participant_qos(
                participant_qos);

            /* Disable builtin transports */
            participant_qos.transport_builtin.mask =
                TransportBuiltinKind.MASK_NONE;

            /* Set up property QoS to load plugin */
            PropertyQosPolicyHelper.add_property(participant_qos.property, 
                "dds.transport.load_plugins", "dds.transport.wan_plugin.wan", false);

            /* library */
            PropertyQosPolicyHelper.add_property(participant_qos.property, 
                "dds.transport.wan_plugin.wan.library",
                WAN_LIB, false);

            /* create function */
            PropertyQosPolicyHelper.add_property(participant_qos.property, 
                "dds.transport.wan_plugin.wan.create_function", "NDDS_Transport_WAN_create", false);

            /* plugin properties */

            /* enable security */
            if (USE_SECURITY) {
                System.out.println("Enabling secure WAN transport");
                PropertyQosPolicyHelper.add_property(
                    participant_qos.property,
                    "dds.transport.wan_plugin.wan.enable_security",
                    "1",
                    false);
                PropertyQosPolicyHelper.add_property(
                    participant_qos.property,
                    "dds.transport.wan_plugin.wan.tls.verify.ca_file",
                    RTI_EXAMPLES_PATH + "/dds_security/cert/dtls_rsa01/ca/rsa01RootCaCert.pem",
                    false);
                PropertyQosPolicyHelper.add_property(
                    participant_qos.property,
                    "dds.transport.wan_plugin.wan.tls.identity.certificate_chain_file",
                    RTI_EXAMPLES_PATH + "/dds_security/cert/dtls_rsa01/identities/rsa01Peer01.pem",
                    false);
            }

            PropertyQosPolicyHelper.add_property(participant_qos.property, 
                "dds.transport.wan_plugin.wan.server", WAN_SERVER, false);

            PropertyQosPolicyHelper.add_property(participant_qos.property, 
                "dds.transport.wan_plugin.wan.transport_instance_id", WAN_ID, false);

            participant = DomainParticipantFactory.TheParticipantFactory.
                create_participant(
                    domainId, participant_qos,
                    null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (participant == null) {
                System.err.println("create_participant error\n");
                return;
            }        
                    
            // --- Create publisher --- //

            /* To customize publisher QoS, use
               participant.get_default_publisher_qos() */
            publisher = participant.create_publisher(
                DomainParticipant.PUBLISHER_QOS_DEFAULT, null /* listener */,
                StatusKind.STATUS_MASK_NONE);
            if (publisher == null) {
                System.err.println("create_publisher error\n");
                return;
            }                   
                
        
            // --- Create topic --- //

            /* Register type before creating topic */
            String typeName = HelloWorldTypeSupport.get_type_name();
            HelloWorldTypeSupport.register_type(participant, typeName);

            /* To customize topic QoS, use
               participant.get_default_topic_qos() */
            topic = participant.create_topic(
                "Example HelloWorld",
                typeName, DomainParticipant.TOPIC_QOS_DEFAULT,
                null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (topic == null) {
                System.err.println("create_topic error\n");
                return;
            }           
                
            // --- Create writer --- //

            /* To customize data writer QoS, use
               publisher.get_default_datawriter_qos() */
            writer = (HelloWorldDataWriter)
                publisher.create_datawriter(
                    topic, Publisher.DATAWRITER_QOS_DEFAULT,
                    null /* listener */, StatusKind.STATUS_MASK_NONE);
            if (writer == null) {
                System.err.println("create_datawriter error\n");
                return;
            }           
                    
                    
            // --- Write --- //

            /* Create data sample for writing */
            HelloWorld instance = new HelloWorld();

            InstanceHandle_t instance_handle = InstanceHandle_t.HANDLE_NIL;
            /* For data type that has key, if the same instance is going to be
               written multiple times, initialize the key here
               and register the keyed instance prior to writing */
            //instance_handle = writer.register_instance(instance);

            final long sendPeriodMillis = 4 * 1000; // 4 seconds

            for (int count = 0;
                 (sampleCount == 0) || (count < sampleCount);
                 ++count) {
                System.out.println("Writing HelloWorld to WAN, count " + count);

                /* Modify the instance to be written here */
                instance.msg = "Hello Wide Area World! (" + count + ")";
            
                /* Write data */
                writer.write(instance, instance_handle);
                try {
                    Thread.sleep(sendPeriodMillis);
                } catch (InterruptedException ix) {
                    System.err.println("INTERRUPTED");
                    break;
                }
            }

            //writer.unregister_instance(instance, instance_handle);

        } finally {

            // --- Shutdown --- //

            if(participant != null) {
                participant.delete_contained_entities();

                DomainParticipantFactory.TheParticipantFactory.
                    delete_participant(participant);
            }
            /* RTI Connext provides finalize_instance()
               method for people who want to release memory used by the
               participant factory singleton. Uncomment the following block of
               code for clean destruction of the participant factory
               singleton. */
            //DomainParticipantFactory.finalize_instance();
        }
    }
}

