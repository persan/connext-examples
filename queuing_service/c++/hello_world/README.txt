===========================================================================
 Example Code -- HelloWorld example of interaction with RTI Queuing Service
===========================================================================

This example is a modified version of the helloWorld example that can
be generated using rtiddsgen with the -example command-line option.
The original example was modified to create a DataWriter that
publishes samples into a SharedReaderQueue and
DataReader(s) that receive samples from the SharedReaderQueue.

This example does not use the Queuing Service Wrapper API that
is only available in .NET

Building C++ Example
====================

Before compiling or running the example, make sure the environment variable
NDDSHOME is defined and it refers to your RTI Connext DDS installation directory.

If running the Security scenario, you need OpenSSL version 1.1.0a or later.

Run rtiddsgen with the -example option and the target architecture of your
choice (e.g., x64Darwin12clang4.1).

Do not use the -replace option. Do not replace the following files included
with this example:
- HelloWorldQueue_publisher.cxx
- HelloWorldQueue_subscriber.cxx
- USER_QOS_PROFILES.xml

This example also shows the unbounded sequence and string feature. This requires
you to generate the code with the -unboundedSupport option.

For example, assuming you want to generate an example for the architecture
x64Darwin12clang4.1, run:

   <RTI connext installation dir>/bin/rtiddsgen -language C++ -namespace -example x64Darwin12clang4.1
             -ppDisable -unboundedSupport HelloWorldQueue.idl

After running rtiddsgen, you will see messages that look like this:

WARN com.rti.ndds.nddsgen.emitters.FileEmitter File exists and will not be overwritten :
./helloWorld/HelloWorldQueue_subscriber.cxx
WARN com.rti.ndds.nddsgen.emitters.FileEmitter File exists and will not be overwritten :
./helloWorld/HelloWorldQueue_publisher.cxx
WARN com.rti.ndds.nddsgen.emitters.FileEmitter File exists and will not be overwritten :
./helloWorld/USER_QOS_PROFILES.xml

This is normal output and is only informing you that the publisher/subscriber
code has not been replaced, which is fine since all the source files for the
example are already provided.

The generated projects will include the publisher and subscriber files
(HelloWorldQueue_publisher.cxx and HelloWorldQueue_subscriber.cxx).

Building C++ Example to run Security scenario
=============================================

To run the Security scenario you will need to add some libraries to the
makefile/solution. Those are:

  * Unix/Makefile:
    - Open the generated makefile and add "-L$(NDDSHOME)/third_party/openssl-<version>/$(TARGET_ARCH)/release/lib"
      and "-lnddssecurity$(SHAREDLIB_SFX)$(DEBUG_SFX)" to the LIBS variable just
      before the first library

    - Add "-lcrypto" to the LIBS variable just after the last library.

  * Visual studio:

    - Since RTI Security Plugins is required, you need to add the libraries
      nddssecurity[z][d].lib and libcrypto.lib to publisher and subscriber project properties
      (Project Properties > Configuration Properties > Linker > Input > Additional Dependencies)

    - You also need to add the directory "%NDDSHOME%\third_party\openssl-<version>\<architecture>\[static_]<debug|release>\lib"
      to publisher and subscriber project properties
      (Project Properties > Configuration Properties > Linker > General > Additional Library Directories)

Windows
-------

To build this example, open the generated solution. Select
from the configuration pull-down menu: Debug, Release, Debug DLL, or Release DLL
where "DLL" is for dynamic linking. The provided projects use the dynamic
openssl library. To use the static version, change the path to
%NDDSHOME%\third_party\openssl-<version>\<architecture>\static_[release|debug]\lib.

QNX
---

To build this example for a QNX platform, you must set the environment variables
QNX_HOST and QNX_TARGET. For example:

setenv QNX_BASE /opt/qnx660
setenv QNX_HOST ${QNX_BASE}/host/linux/x86
setenv QNX_TARGET ${QNX_BASE}/target/qnx6

Linux-based
-----------

To build this example on a UNIX-based system, type the following in a command
shell:

  > make -f makefile_HelloWorld_<architecture>

If using Certicom Security Builder Engine, you cannot use the ecdsa-ecdh shared
secret algorithm together with static linking. If you want to use ecdsa-ecdh,
you must use dynamic linking. Aside from that, all combinations of
static/dynamic libraries and release/debug libraries are supported. Dynamic
uses the QoS profile for specifying the security plugin, and static uses code
for that. Static/release is the default.

To use dynamic, run:

 > make -f makefile_HelloWorld_<architecture> SHAREDLIB=1

To use debug, run:

 > make -f makefile_HelloWorld_<architecture> DEBUG=1


Command-Line Parameters
=======================

HelloWorldQueue_publisher
Usage:
-d <domainId>              default: 0
-q <queueTopicName>        default: HelloWorldTopic
-p <qosProfileName>        default: <none>
-c <sampleCount>           default: 0 - UNLIMITED -
-l <samplePayloadLength>   default: 32

HelloWorldQueue_subscriber
Usage:
-d <domainId>              default: 0
-q <queueTopicName>        default: HelloWorldTopic
-r <sharedSubscriberName>  default: SharedSubscriber
-p <qosProfileName>        default: <none>
-c <sampleCount>           default: 0 - UNLIMITED

Running C++ Example
===================
After building the example using the generated makefile or Visual Studio solution,
you are ready to run the examples. Note that if you linked the example dynamically
you will need to add <RTI Connext Installation dir>/lib/<architecture> and
<RTI Connext Installation dir>/third_party/openssl-<version>/<arch>/<debug/release>/lib
for Unix or <debug/release>/bin for Windows to your path environment variable.
This last one is only required to run the Security scenario.

Note: The following examples are configured to use the UDPv4 built-in transport by
default. In certain cases (e.g. when multicast is not enabled), you might need
to enable the SHMEM transport or add the localhost to the variable NDDS_DISCOVERY_PEERS
to make them work properly:

   (Linux)
   setenv NDDS_DISCOVERY_PEERS 10@localhost

   (Windows)
   set NDDS_DISCOVERY_PEERS=10@localhost


** Scenario 1: 1Producer/1Consumer/1QS UDP VOLATILE **

1. This example requires RTI Queuing Service. In one terminal, from
   the example installation directory, enter:

   <RTI Connext installation dir>/bin/rtiqueuingservice -cfgFile QsHelloWorld.xml
          -cfgName HelloWorldQS

2. On another terminal, run the subscriber.

   The executable is here:

   objs/<architecture>/HelloWorldQueue_subscriber

3. On another terminal, run the publisher.

   The executable is here:

   objs/<architecture>/HelloWorldQueue_publisher

** Scenario 2: 1Producer/1Consumer/1QS UDP PERSISTENT **

1. Delete any previously created database files in the example directory.
2. Run RTI Queuing Service using -cfgName HelloWorldQSPersistence.
3. Run the publisher.
4. Run the subscriber.

** Scenario 3: 1Producer/1Consumer/2ReplicatedQS UDP VOLATILE **

1. Run two RTI Queuing Service instances using -cfgName HelloWorldQSReplication.
2. Run the publisher.
3. Run the subscriber.

NOTE: In this scenario, the first samples might be rejected and the publisher
output will look like this:

Wrote sample with message ID: 1 and sequence number: 1
Received ACK from QS for sample with sequence number: 1 Process result: Rejected
Received ACK from QS for sample with sequence number: 1 Process result: Rejected
Wrote sample with message ID: 1 and sequence number: 2
Received ACK from QS for sample with sequence number: 2 Process result: Rejected
Received ACK from QS for sample with sequence number: 2 Process result: Rejected
Wrote sample with message ID: 2 and sequence number: 3
Received ACK from QS for sample with sequence number: 3 Process result: Accepted
Received ACK from QS for sample with sequence number: 3 Process result: Accepted

This is an expected behavior. When using replicated SharedReaderQueues,
samples are not accepted by RTI Queuing Service instances until the master
election protocol is finished and the master instance has discovered the minimum
number of replicas to reach the quorum. See the "SharedReaderQueue Replication"
section of the RTI Queuing Service User's Manual for more information.

** Scenario 4: 1Producer/1Consumer/2ReplicatedQS UDP PERSISTENT **

1. Delete any previously created database files in the example directory.
2. Run two RTI Queuing Service instances using -cfgName HelloWorldQSPersistenceReplication.
   Make sure you use different -appName argument for each of the instances (e.g. instance1 and instance2)
3. Run the publisher.
4. Run the subscriber.

NOTE: In this scenario, the first samples might be rejected and the publisher
output will look like this:

Wrote sample with message ID: 1 and sequence number: 1
Received ACK from QS for sample with sequence number: 1 Process result: Rejected
Received ACK from QS for sample with sequence number: 1 Process result: Rejected
Wrote sample with message ID: 1 and sequence number: 2
Received ACK from QS for sample with sequence number: 2 Process result: Rejected
Received ACK from QS for sample with sequence number: 2 Process result: Rejected
Wrote sample with message ID: 2 and sequence number: 3
Received ACK from QS for sample with sequence number: 3 Process result: Accepted
Received ACK from QS for sample with sequence number: 3 Process result: Accepted

This is an expected behavior. When using replicated SharedReaderQueues,
samples are not accepted by RTI Queuing Service instances until the master
election protocol is finished and the master instance has discovered the minimum
number of replicas to reach the quorum. See the "SharedReaderQueue Replication"
section of the RTI Queuing Service User's Manual for more information.

** Scenario 5: 1Producer/1Consumer/1QS UDP VOLATILE WITH SECURITY **

1. Run RTI Queuing Service using -cfgName HelloWorldQSSecurity.
2. Run the publisher using -p HelloWorldQueue_Library::HelloWorldQueueSecurityPublisher_Profile.
3. Run the subscriber using -p HelloWorldQueue_Library::HelloWorldQueueSecuritySubscriber_Profile.

If you see in this scenario the following error:

Cryptography_encrypt:error:0607B083:lib(6):func(123):reason(131)

You are likely linking against an older version of OpenSSL. You need version
1.0.1c or later.

For more information, please consult the "RTI Security Plugins Getting Started
Guide".
