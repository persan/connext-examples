================================================================================
CPP Hello World Example with RTI Persistence Service
================================================================================

Example publisher/subscriber applications are provided to send and receive 
simple integers. If RTI Persistence Service is running, the data is persisted.

Use the PsHelloWorld.xml file to persist the HelloWorld topic in domain 0.
Adjust this file if you want to use a different domain ID, then use the domain 
ID as a command-line argument with your HelloWorld_publisher and 
HelloWorld_subscriber programs.

Purpose
=======

This example shows how to perform basic publish-subscribe communication using 
DDS_PERSISTENT_DURABILITY_QOS.

How to Compile
==============

Make sure the environment variable NDDSHOME is defined before compiling the 
example.

UNIX-Based Systems
------------------

Use rtiddsgen to generate a makefile for your machine's architecture and 
compiler. For example, if both the publisher and the subscriber application 
will run on Red Hat Enterprise Linux 4 machines, you need to run rtiddsgen
for only that architecture:

    $NDDSHOME/bin/rtiddsgen -language C++ -ppDisable -example i86Linux2.6gcc3.4.3 HelloWorld.idl

You may get messages saying that some files already exist and will not be 
replaced. You can safely ignore those messages, since all the source files for
this example are already provided.

Before compiling, make sure that the desired version of compiler and linker is
in your PATH environment variable.

Then compile by typing:

     make -f makefile_HelloWorld_i86Linux2.6gcc3.4.3

Windows Systems
---------------
Use rtiddsgen to generate the solution and project files for your version of
Visual Studio. For example, if both the publisher and the subscriber 
application will be compiled with Visual Studio 2013, run rtiddsgen for the 
i86Win32VS2013 architecture:

    %NDDSHOME%/bin/rtiddsgen -language C++ -ppDisable -example i86Win32VS2013 HelloWorld.idl

Open the solution file for your architecture with Visual Studio. 
Build the two projects, HelloWorld_publisher and HelloWorld_subscriber, with 
the Release configuration (or Debug settings if you prefer).

Persistent Storage Configuration
================================

RTI Persistence Service can be configured to operate in PERSISTENT or 
TRANSIENT mode. 

If the service operates in TRANSIENT mode (<persistent_storage> tag is not 
used), the received samples will be kept in memory and not in permanent storage. 
In this mode, samples published by a TRANSIENT DataWriter will survive the 
DataWriter's lifecycle but will not survive the lifecycle of RTI Persistence 
Service (unless the persistence service is duplicated).

If the service operates in PERSISTENT mode, the received samples will be stored
into a file system.

In this mode, samples published by a PERSISTENT DataWriter will survive the 
DataWriter's lifecycle, as well as a restart of RTI Persistence Service.

The HelloWorld example will run RTI Persistence Service in PERSISTENT mode and
it will show how to store the samples into files.

The location of the files is specified using the tag <filesystem> in the XML 
configuration file provided with this example.

Within this tag you can specify the directory where the files will be located
using the tag <directory>. By default, files will be located in the current 
working directory.

License File
============

If your RTI Persistence Service distribution requires a license file, you will 
receive one via email after you download the software.
Save the license file in any location of your choice. When 
RTI Persistence Service starts, it will look in these locations until it finds a 
valid license:

1. The file specified with the -licenseFile option when you start RTI 
Persistence Service from the command-line.
2. The file specified in the environment variable RTI_LICENSE_FILE, which you
may set to point to the full path of the license file, including the filename 
(for example, C:\RTI\my_rti_license.dat).
3. The file rti_license.dat in the current working directory.
4. The file rti_license.dat in the directory specified by the environment 
variable NDDSHOME.

How to Run
==========

UNIX-Based Systems
------------------

   1) If you want to run the publisher and subscriber in a domain ID other than 
      0, you have two choices:

      a) You can edit the configuration file PsHelloWorld.xml and replace the
      domain ID specified in the tag <domain_id>.
      b) You can use the command-line option -domainId 

      Note: During the next 2 steps, if you see error messages in the window 
      where you started RTI Persistence Service, please see the Troubleshooting
      section at the end of this file.

   2) Run RTI Persistence Service by typing:

      > ${NDDSHOME}/bin/rtipersistenceservice -cfgFile PsHelloWorld.xml 
        -cfgName HelloWorldFile -restore 0

      On the screen, you will see:
      RTI Persistence Service started

      Note: the files containing the samples will be located in the working 
      directory by default. If you want to change the location you can use the 
      tag <directory> under <filesystem>. 

      With -restore 0, RTI Persistence Service will delete the data persisted in 
      previous executions so that you can start with a clean state.

   5) Run the publisher from the helloWorldPersistence directory
      (replace [domain_id] with the correct value, or omit it to use the default
      domain ID, 0):

      > objs/i86Linux2.6gcc3.4.3/HelloWorld_publisher [domain_id]

      On the screen, you will see:
      Writing HelloWorld, count 0
      Writing HelloWorld, count 1
      ...

   4) Run the subscriber from the helloWorldPersistence directory and verify 
      that it only receives one copy of the data
      (replace [domain_id] with the correct value, or omit it to use the default 
      domain ID, 0):

      > objs/i86Linux2.6gcc3.4.3/HelloWorld_subscriber [domain_id]

      The output will look something like this:
      HelloWorld subscriber sleeping for 4 sec...
         data: 0
         data: 1
         data: 2
         data: 3
      HelloWorld subscriber sleeping for 4 sec...
      ...

      The subscriber should not receive two data values with the same number.

   5) Stop the publisher by pressing CTRL-C.

   6) Start a new subscriber and verify that it receives samples from RTI 
      Persistence Service in the absence of the original publisher.

      > objs/i86Linux2.6gcc3.4.3/HelloWorld_subscriber [domain_id]

      The output will look something like this:
      HelloWorld subscriber sleeping for 4 sec...
         data: 0
         data: 1
         data: 2
         data: 3
         data: 4

   7) Stop RTI Persistence Service and the two subscribers by pressing CTRL-C.

   8) Restart RTI Persistence Service.

      > ${NDDSHOME}/bin/rtipersistenceservice -cfgFile PsHelloWorld.xml 
        -cfgName HelloWorldFile
      RTI Persistence Service started

   9) Start a subscriber and verify that it receives the persisted samples from 
      RTI Persistence Service:

      > objs/i86Linux2.6gcc3.4.3/HelloWorld_subscriber [domain_id]

      The output will look something like this:
      HelloWorld subscriber sleeping for 4 sec...
         data: 0
         data: 1
         data: 2
         data: 3
         data: 4

  10) Stop the persistence service and the subscriber by pressing CTRL-C.


Windows Systems
---------------

   1) If you want to run the publisher and subscriber in a domain ID other than 
      0, you have two choices:

      a) You can edit the configuration file PsHelloWorld.xml and replace the
      domain ID specified in the tag <domain_id>.
      b) You can use the command-line option -domainId 

      Note: During the next 2 steps, if you see error messages in the window 
      where you started RTI Persistence Service, please see the Troubleshooting 
      section at the end of this file.


   2) Run RTI Persistence Service by typing:

      > %NDDSHOME%\bin\rtipersistenceservice.bat -cfgFile PsHelloWorld.xml 
      -cfgName HelloWorldFile -restore 0

      On the screen, you will see:
      RTI Persistence Service started

      Note: the files containing the samples will be located in the working 
      directory by default. If you want to change the location you can use the 
      tag <directory> under <filesystem>. 

      With -restore 0, RTI Persistence Service will delete the data persisted in 
      previous executions so that you can start with a clean state.

   3) Run the publisher from the helloWorldPersistence directory 
      (replace [domain_id] with the correct value, or omit it to use the 
      default domain ID, 0):

      > objs\i86Win32VS2013\HelloWorld_publisher [domain_id]

      On the screen, you will see:
      Writing HelloWorld, count 0
      Writing HelloWorld, count 1
      ...

   4) Run the subscriber from the helloWorldPersistence directory and verify 
      that it only receives one copy of the data (replace [domain_id] 
      with the correct value, or omit it to use the default domain ID, 0):

      > objs\i86Win32VS2013\HelloWorld_subscriber [domain_id]

      The output will look something like this:
      HelloWorld subscriber sleeping for 4 sec...
         data: 0
         data: 1
         data: 2
         data: 3
      HelloWorld subscriber sleeping for 4 sec...
      ...

      The subscriber should not receive two data values with the same number.

   5) Stop the publisher by pressing CTRL-C.

   6) Start a new subscriber and verify that it receives samples from 
      RTI Persistence Service in the absence of the original publisher:

      > objs\i86Win32VS2013\HelloWorld_subscriber [domain_id]

      The output will look something like this:
      HelloWorld subscriber sleeping for 4 sec...
         data: 0
         data: 1
         data: 2
         data: 3
         data: 4

   7) Stop RTI Persistence Service and the two subscribers by pressing CTRL-C.

   8) Restart RTI Persistence Service.

      > %NDDSHOME%\bin\rtipersistenceservice.bat -cfgFile PsHelloWorld.xml 
        -cfgName HelloWorldFile
      RTI Persistence Service started

   9) Start a subscriber a verify that it receives the persisted samples from 
      RTI Persistence Service:

      > objs\i86Win32VS2013\HelloWorld_subscriber [domain_id]

      The output will look something like this:
      HelloWorld subscriber sleeping for 4 sec...
         data: 0
         data: 1
         data: 2
         data: 3
         data: 4

  10) Stop RTI Persistence Service and the subscriber by pressing CTRL-C.


Optional Parameters
===================

The publisher and subscriber applications accept two optional arguments:

domain_id: 
For the two applications to communicate, they have to use the same domain ID. 
By default, both Hello World applications use domain ID 0. 
If you want to use a specific domain ID, enter it as the first argument 
(valid IDs are >=0). If you are sharing a machine with others, you may
want to use separate domain IDs.

number_of_samples: 
In the publishing application, the second parameter is used as the number of
samples to publish before terminating. 
In the subscribing application, the second parameter is used as the number of
4-second intervals for which it will sleep/awake before terminating.

For example, this uses domain ID 1 and sends 10 samples:
   > objs\i86Win32VS2013\HelloWorld_publisher 1 10

Please consult the RTI Connext DDS Platform Notes and online documentation 
for details.
