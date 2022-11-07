==========================================================================
 Example Code -- Sending commands to RTI Queuing Service via Request/Reply
==========================================================================

See Chapter 5 in Queuing Service User's Manual for details on
Remote Administration

Compiling this Example
=======================
1. Before compiling or running the example, make sure the environment variable
   NDDSHOME is set to the directory where your version of RTI Connext DDS is
   installed.

2. This example requires you to generate code from three different IDL files:
   * ServiceCommon.idl: Contains common definitions for RTI Infrastructure
     Services.
   * QueuingServiceTypes.idl contains the types required to parse
     the CommandReply sent by Queuing Service after executing some commands.
   * ServiceAdmin.idl contains the CommandRequest and
     CommandReply types used by RTI Queuing Service.
     You will need to use the -example command-line
     option to generate the build files.

   Step 1: Run rtiddsgen on ServiceCommon.idl and QueuingServiceTypes.idl:

     $(NDDSHOME)/bin/rtiddsgen -language C++ -namespace \
            -unboundedSupport -qualifiedEnumerator -ppDisable ServiceCommon.idl

     $(NDDSHOME)/bin/rtiddsgen -language C++ -namespace \
            -unboundedSupport -ppDisable QueuingServiceTypes.idl

   Step 2: For example, assuming you want to generate an example for the architecture
     x64Linux2.6gcc4.4.5, run:

     $(NDDSHOME)/bin/rtiddsgen -example x64Linux2.6gcc4.4.5 -language C++ -namespace \
          -unboundedSupport -qualifiedEnumerator ServiceAdmin.idl

     After running rtiddsgen, you will see messages that look like this:

        WARN com.rti.ndds.nddsgen.emitters.FileEmitter File exists and will not be
        overwritten : <Path to examples>/queuing_service/c++/remoteConfig/ServiceAdmin_publisher.cxx

    This is normal output and is only informing you that the publisher code has
    not been replaced, which is fine since all the source files for the example
    are already provided.


   Step 3: Open the makefile/solution generated at step 2 and add the files generated in the
     previous step.

   * Unix/Makefile:
   	- Open the generated makefile and add QueuingServiceTypes.cxx,
          QueuingServiceTypesPlugin.cxx, QueuingServiceTypesSupport.cxx,
          ServiceCommon.cxx, ServiceCommonPlugin.cxx and
          ServiceCommonSupport.cxx to the SOURCES variable

	- Add "-lrticonnextmsgcpp$(SHAREDLIB_SFX)$(DEBUG_SFX)" to the LIBS variable just before the
          first library

    - To build this example on a UNIX-based system, type the following in a command
          shell:

            > make -f makefile_ServiceAdmin_<architecture>

    - To use dynamic libraries, run:

            > make -f makefile_ServiceAdmin_<architecture> SHAREDLIB=1

    - To use debug, run:

            > make -f makefile_ServiceAdmin_<architecture> DEBUG=1

   * Visual studio:

	- Add the generated C++ support files for QueuingServiceTypes.idl
         (QueuingServiceTypes*) and the generated ones for ServiceCommon.idl
         (ServiceCommon*) to the ServiceAdmin_publisher project
         (Project > Add existing item)

	- Since RTI Connext Messaging is required, you need to add the the
          library rticonnextmsgcpp[z][d].lib to the ServiceAdmin_publisher
          properties (Project Properties > Configuration Properties > Linker > Input > Additional Dependencies)

    - To build this example, open the generated solution. Select
          from the configuration pull-down menu: Debug, Release, Debug DLL, or Release DLL
          where "DLL" is for dynamic linking. Right-click on the publisher project and
          choose Build. Do not build the subscriber project since we didn't add the type support files for it.

   The makefile/solution file generates two executables: a publisher and a subscriber.
   This example only needs the publisher executable, which represents a
   Queuing Service command requester.


Running the C++ Example
========================

1. This example requires RTI Queuing Service. For instance, you can run the
   RemoteConfigQS configuration provided in the C++ hello_world example:

       $(NDDSHOME)/bin/rtiqueuingservice -cfgFile <hello_world C++ example path>/QsHelloWorld.xml \
            -cfgName RemoteConfigQS

2. In a command prompt window, run the publisher/requester application.

       objs/<architecture>/ServiceAdmin_publisher [args]

   [args] can be:
	-d <domainId> -q <serviceName> -o <profileName> [create|delete|get] <resourceIdentifier> {command options}
	-d <domainId>     default: 1
	-q <serviceName>  default: RemoteConfigQS
	-o <profileName>  default: <none>
	{create options}: -s <sessionName> -p <topicName> -t <typeName> -r <replyTypeName>
	-s <sessionName>    default: Session
	-p <topicName>      default: HelloWorldTopic
	-t <typeName>       default: HelloWorld
	{delete options}: <sampleSelector>
	{get options}:    <sampleSelector>

   You must enter create, delete, or get, followed by a [resourceIdentifier] (which is
   described in the Queuing Service User's Manual).

   create   Creates a new shared reader queue.
            After "create [resourceIdentifier]" you may specify the following
            (all are optional):
            -s <sessionName>   Name of session to be used by created queue.
                               (Default: Session)
            -p <topicName>     Topic/queue name. (Default:HelloWorldTopic)
            -t <typeName>      Type of the Topic/queue. (Default: HelloWorld)

   delete   Deletes an existing resource specified by the resource identifier.
            After "delete [resourceIdentifier]" you may specify the following
            (optional):
            [sampleSelector]  When the resource identifies messages in the queues,
                              the sample selector allows you to specify the subset
                              of messages in the queue that will be deleted.
                              (Default: empty)

   get      Retrieves an existing resource specified by the resource identifier.
            After "get [resourceIdentifier]" you may specify the following
             (optional):
            [sampleSelector]  When the resource identifies messages in the queues,
                              the sample selector allows you to specify the subset
                              of messages in the queue that will be retrieved.
                              (Default: empty)
Workflow Use Case
==================

The following steps show how to use the different available commands
and the expected results.

1. Start RTI Queuing Service with remote administration enabled. For instance,
   you can use the configuration file from the RTI Queuing Service hello_world
   C++ example:

     $(NDDSHOME)/bin/rtiqueuingservice -cfgFile <hello_world example path>/QsHelloWorld.xml \
            -cfgName RemoteConfigQS

2. Create a SharedReaderQueue in an existing SharedSubscriber. You can use the
   topic and type names used by your producer and consumer application:

     objs\<architecture>\ServiceAdmin_publisher  \
	  create /domain_participant/DomainParticipant/shared_subscriber/SharedSubscriber \
	  -p HelloWorldTopic -t HelloWorld

3. List all the available queues in the running Queuing service instance. This
   should show you all the queues that were initially in the configuration plus
   the one you just created in step 2:

     objs\<architecture>\ServiceAdmin_publisher get /data

4. Run your producer application and send some messages to the recently created
   queue. (See the Hello World example for details on how to do this.).

5. Retrieve the status of the queue. Make sure that the retrieved status
   information is accurate:

     objs\<architecture>\ServiceAdmin_publisher get \
	/domain_participant/DomainParticipant/shared_subscriber/SharedSubscriber/shared_reader_queue/HelloWorldTopic/status

6. Get all the undelivered messages from the recently created queue. Since
   there are no consumers, you should get as many messages as you sent in step 4:

     objs\<architecture>\ServiceAdmin_publisher get \
	/domain_participant/DomainParticipant/shared_subscriber/SharedSubscriber/shared_reader_queue/HelloWorldTopic/message \
	"@sample_queue_status=UNDELIVERED_MESSAGE_STATUS"

7. Delete all the messages from the recently created queue:

     objs\<architecture>\ServiceAdmin_publisher delete \
	/domain_participant/DomainParticipant/shared_subscriber/SharedSubscriber/shared_reader_queue/HelloWorldTopic/message \
	"@sample_queue_status=UNDELIVERED_MESSAGE_STATUS"

8. Get all the messages from the recently created queue. Since you flushed the
   queue in the previous step, you should get no messages:

     objs\<architecture>\ServiceAdmin_publisher get \
	/domain_participant/DomainParticipant/shared_subscriber/SharedSubscriber/shared_reader_queue/HelloWorldTopic/message \
	"@sample_queue_status=UNDELIVERED_MESSAGE_STATUS OR @sample_queue_status=SENT_MESSAGE_STATUS"

9. Delete the recently created queue:

     objs\<architecture>\ServiceAdmin_publisher delete \
       /domain_participant/DomainParticipant/shared_subscriber/SharedSubscriber/shared_reader_queue/HelloWorldTopic

10. List all the available queues in the running Queuing Service instance.
    This should only show you the queues that were initially in the
    configuration when the service was loaded:

	objs\<architecture>\ServiceAdmin_publisher get /data


