=============================================================================
 Example Code -- HelloWorld example to demonstrate the usage of Topic Queries
=============================================================================

This example is a modified version of the helloWorld example that can
be generated using rtiddsgen with the -example command-line option.
The original publisher and subscriber applications have been modified so 
show how to retrieve historical data with Topic Queries.

* HelloWorldTopicQueryPublisher: A publisher application with one transient
local DataWriter that can write and generate history for a subset of instances.
* HelloWorldTopicQuerySubscriber: A subscriber application with one volatile
 DataReader that creates a TopicQuery to retrieve the samples previously 
written by the DataWriter(s) at the same time it receives the new samples.
* USER_QOS_PROFILES.xml: modification of the generated QoS that contains
the proper configuration to enable TopicQuery.
* RsHelloWorldTopicQuery.xml: A Routing Service configuration file with
several service configurations that are required for some of the scenarios
described below.

The example works with a type defined in HelloWorldTopicQuery.idl, which 
requires code generation with rtiddsgen.

Building Java Example
===================

Before compiling or running the example, make sure the environment variable 
NDDSHOME is defined and it refers to your RTI Connext DDS installation directory. 

Run rtiddsgen with the -example option and the target architecture of your 
choice. In this example we will work with the x64Darwin14clang6.0 architecture.
 
Do not use the -replace option. Do not replace the following files included 
with this example:
- HelloWorldTopicQueryPublisher.java
- HelloWorldTopicQuerySubscriber.java
- USER_QOS_PROFILES.xml


For example, assuming you want to generate an example for the architecture 
x64Darwin14clang6.0, run:

   rtiddsgen -language Java -example  x64Darwin14clang6.0 -ppDisable 
             HelloWorldTopicQuery.idl

After running rtiddsgen, you will see messages that look like this:

	WARN com.rti.ndds.nddsgen.emitters.FileEmitter File exists and will not 
        be overwritten : <example_dir>\HelloWorldTopicQueryPublisher.java
	WARN com.rti.ndds.nddsgen.emitters.FileEmitter File exists and will not
        be overwritten : <example_dir>\HelloWorldTopicQuerySubscriber.java
        WARN com.rti.ndds.nddsgen.emitters.FileEmitter File exists and will not 
        be overwritten : <example_dir>\USER_QOS_PROFILES.xml

This is the expected normal output and is only informing you that the 
publisher, subscriber and QoS configuration files have not been replaced, 
which is the desired behavior.

Use the generated makefile to build the applications. In one terminal, enter:
    
    cd <example_dir>
    make -f makefile_HelloWorldTopicQuery_x64Darwin14clang6.0

Running the example applications
================================

To run the example applications you can use the generated makefile. In one
terminal situated in the example directory, run:

* Publisher application
make -f makefile_HelloWorldTopicQuery_x64Darwin14clang6.0 
    HelloWorldTopicQueryPublisher ARGS="[options]"

Where [options]:
-d <domainId>              default: 0
-c <sentSampleCount>       default: -1 - UNLIMITED -
-l <lowerInstanceId>       default: 0-
-u <upperInstanceId>       default: -1 - No upper limit -
-p <periodInSec>           default: 4s
-b <burstSize>             default: 0 - No burst -


* Subscriber application
make -f makefile_HelloWorldTopicQuery_x64Darwin14clang6.0 
    HelloWorldTopicQuerySubscriber ARGS="[options]"

Where [options]:
-d <domainId>              default: 0
-c <receivedSampleCount>   default: -1 - UNLIMITED -
-i <instanceId>            default: -1 - ALL -
-t <topicQueryWaitMax>     default: 0s

Running scenarios
==================
   
1. Retrieving historical data when publisher and subscriber communicate 
directly with each other. Publisher provides samples for all the instances and
subscriber does not specify a filter for any particular instance.

    - Run first the publisher application with an initial burst to generate 
    history quickly. For instance, run with "-b 10" to generate at least 10 
    history samples. You should see the output quickly filled with the 
    following messages:

        Writing HelloWorldTopicQuery, count 1
        Writing HelloWorldTopicQuery, count 2
        Writing HelloWorldTopicQuery, count 3
        Writing HelloWorldTopicQuery, count 4
        Writing HelloWorldTopicQuery, count 5
        Writing HelloWorldTopicQuery, count 6
        Writing HelloWorldTopicQuery, count 7
        Writing HelloWorldTopicQuery, count 8
        Writing HelloWorldTopicQuery, count 9
        Writing HelloWorldTopicQuery, count 10

    - Run first the subscriber and observe that the history is retrieved via 
    TopicQuery. With the provided QoS settings in USER_QOS_PROFILES.xml, 
    TopicQuery samples are sent at a rate of 1 sample every second, whereas 
    live data is provided at a default rate of 1 samples every 4 seconds. You 
    should see TopicQuery samples and live samples being printed interleaved 
    in the standard output. 

    The TopicQuery samples will be output as follows:

        Received TopicQuery sample with GUID F0E664CDB2B2E9CBFE1D845C211D1D4:
            id: 0
            message: count: 1

    and interleaved you should see live samples, output as follows:

        Received live sample:
            id: 0
            message: count: 15


2. Retrieving historical data when publisher and subscriber communicate 
directly with each other. Publisher writes samples for a subset of instances
and subscriber has a filter to receive data for a specific instance.


    - Run the publisher with "-b 30 -u 3" to write sample for the instances with 
    ID in range [0, 2] and an initial sample burst of 30 samples, 10 for each 
    instance.

    - Run the subscriber with "-i 1" to set a filter to only receives the 
    instance with ID=1. In the output, you should see only samples for this 
    instance.

    Received TopicQuery sample with  GUID 985BD45B53DBFCEEAD2E997138ED0D4:
        id: 1
        message: count: 1

    Received TopicQuery sample with  GUID 985BD45B53DBFCEEAD2E997138ED0D4:
        id: 1
        message: count: 4

    Received TopicQuery sample with  GUID 985BD45B53DBFCEEAD2E997138ED0D4:
        id: 1
        message: count: 7 

    ...

    interleaved with live samples:

    Received live sample:
        id: 1
        message: count: 31

3. Retrieving historical data when publisher and subscriber communicate 
through a RoutingService. This scenario requires RoutingService with one of
the configurations in the provided RsHelloWorldTopicQuery.xml file.
Publisher provides samples for all the instances and subscriber does not 
specify a filter for any particular instance.

    - Run first the publisher:
        - With "-d 0" to run in domain 0, which is the publication domain configured 
          in RoutingService. 
        - With "-b 10" to run with an initial burst of 10 samples to generate 
          history quickly.

    - Run RoutingService with the "HelloWorldTopicQuery" configuration. 
    This configuration enables TopicQuery propagation for the Topic of this 
    example.
               
        <rti_connext_dds_installation>/bin/rtiroutingservice 
            -cfgFile RsHelloWorldTopicQuery.xml
            -cfgName HelloWorldTopicQuery

    - Run the subscriber with "-d 1" so it runs in domain 1, which is the 
    subscription domain configured in RoutingService. You should see the same 
    behavior than is scenario 1.

4. Retrieving historical data when publisher and subscriber communicate 
through a RoutingService. This scenario requires RoutingService with one of
the configurations in the provided RsHelloWorldTopicQuery.xml file.
Publisher writes samples for a subset of instances. You will have to run
two subscriber with the "-i <instance_id>" option to select a specific instance.

    - Run the publisher 
        - With "-d 0" to run in domain 0, which is the publication domain configured 
          in RoutingService. 
        - With "-u 3" to write sample for the instances with 
          ID in range [0, 2]
        - With "-b 20" to run with an initial burst of 30 samples to generate 
          10 samples per instance of history quickly.

    - Run RoutingService with "HelloWorldTopicQueryWithFilterPopagation" 
    configuration. This configuration enables both TopicQuery and filter 
    propagation for the Topic of this example.

    <rti_connext_dds_installation>/bin/rtiroutingservice 
            -cfgFile RsHelloWorldTopicQuery.xml
            -cfgName HelloWorldTopicQueryWithFilterPropagation

    - Run subscriber 1 with "-i 1" to set a filter to only receives the instance
    with ID=1. In the output, you should see only samples for this instance.

    - Run subscriber 2 with "-i 2" to set a filter to only receives the instance
    with ID=2. In the output, you should see only samples for this instance.

