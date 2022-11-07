===========================================
Java Hello World Example with WAN transport
===========================================

An example publication and subscription pair to send and receive simple
strings securely over a WAN.

Example certificates for two peers are included.

Purpose
=======

This example shows how to perform basic publish-subscribe communication
using the WAN transport. This includes configuring a securely
authenticated and encrypted channel; example certificates are included
for this purpose.

For convenience, complete source code and a sample makefile for an
architecture have been provided. Generate your own makefile with 
rtiddsgen if you want to run the example on other architectures.

How to Compile and Run
======================

To use this example, you must have a supported version of OpenSSL installed.
It is available from the RTI Customer Portal (http://support.rti.com) and 
www.openssl.org.

Before compiling make sure that the environment variable NDDSHOME is defined 
and that it refers to your RTI Connext DDS installation directory. 

WAN Server Configuration
------------------------

The provided example uses the WAN transport with security disabled.
The WAN transport relies on a rendezvous server based on the STUN protocol in
order to locate peers and establish communication.  Before compiling the example
code, decide where the WAN server will be running and edit the variable
WAN_SERVER that used to set the "dds.transport.wan_plugin.wan.server" property
in both the publisher and subscriber source files.

Before running the example applications, start the WAN server:
    ${NDDSHOME}/bin/rtiwanserver -address <addr> [-port <port>]

A specific interface address should be chosen for the WAN server and must match
the address used when configuring the transport (as specified in the 
WAN_SERVER line defined at the top of the publisher and subscriber source
files). The default port number is 3478.

In order to be used for traversal of Network Address Translation layers (NATs),
the server must be located outside of any NAT layers with a globally-accessible
address.


WAN Locators
------------

The WAN transport does not use simple IP addresses to locate peers.  
A WAN transport locator consists of a WAN ID, which is an arbitrary 
12-byte value, and a bottom 4-byte value that specifies a fallback local 
IPv4 address.  

Locators must be of the form:
    wan://::1:192.168.1.1, which is a 128-bit address in IPv6 notation.

The "wan://" part specifies that the address is for the WAN transport.  

The next part, "::1", specifies the top 12 bytes of the address to be 
11 zero bytes, followed by a byte with value 1 (this corresponds to the 
peer's WAN ID).  

The last part, "192.168.1.1" refers to the peers local IPv4 address, which 
will be used if the peers are on the same local network.

Before running the example applications, the peers list must be configured.
For example:

On the publisher side with WAN_ID 1 (as specified in the WAN_ID line
defined at the top of the publisherMain function in the publisher source file),
the NDDS_DISCOVERY_PEERS must be set to the following value:

On Unix:
    setenv NDDS_DISCOVERY_PEERS wan://::2:<subscriber private IP address>
On Windows:
    set NDDS_DISCOVERY_PEERS=wan://::2:<subscriber private IP address>

On the subscriber side, with WAN_ID 2 (as specified in the WAN_ID line 
defined at the top of the subscriberMain function in the subscriber source file),
the NDDS_DISCOVERY_PEERS must be set to the following value:

On Unix:
    setenv NDDS_DISCOVERY_PEERS wan://::1:<publisher private IP address>
On Windows:
    set NDDS_DISCOVERY_PEERS=wan://::1:<publisher private IP address>


Running RTI Code Generator
--------------------------

Use rtiddsgen to generate a makefile for your machine's architecture.
For example, if both the publisher and the subscriber application
will run on Ubuntu 18.04 or Red Hat Enterprise Linux 8 machines (that have 
the gcc 7.3.0 compiler installed), run rtiddsgen for the 
x64Linux4gcc7.3.0 architecture:

     rtiddsgen -language Java -example x64Linux4gcc7.3.0 HelloWorld.idl

You will get a message saying that some files already exist and will
not be replaced. You can safely ignore those messages, since all the
source files for this example are already provided.

Before compiling, make sure that the desired version of javac compiler
is in your PATH environment variable.

Then compile by typing:

     make -f makefile_HelloWorld_x64Linux4gcc7.3.0

Before running, make sure that the desired version of java compiler
is in your PATH environment variable. 

The NDDS_DISCOVERY_PEERS enviroment variable must be configured as indicated 
in the section WAN locators.

UNIX-based systems
------------------

Before running, make sure that your LD_LIBRARY_PATH includes the path(s) to the 
Connext DDS libraries and to a supported version of the OpenSSL libraries
matching your architecture. For example:

    setenv LD_LIBRARY_PATH ${NDDSHOME}/lib/x64Linux4gcc7.3.0:${LD_LIBRARY_PATH}
    setenv LD_LIBRARY_PATH ${NDDSHOME}/third_party/openssl-<version>/x64Linux4gcc7.3.0/lib:${LD_LIBRARY_PATH}

Run the subscriber by typing:

     make -f makefile_HelloWorld_x64Linux4gcc7.3.0 HelloWorldSubscriber <ARGS="Domain_ID Number_of_Samples">

and run the publisher by typing:

     make -f makefile_HelloWorld_x64Linux4gcc7.3.0 HelloWorldPublisher <ARGS="Domain_ID Number_of_Samples">

Windows systems
---------------

Before running, make sure that your Path includes the path(s) to the 
Connext DDS libraries and to a supported version of the OpenSSL
libraries matching your architecture. For example:

    set Path=%NDDSHOME%\lib\i86Win32VS2013;%Path%
    set Path=%NDDSHOME%\third_party\openssl-<version>\i86Win32VS2013\bin;%Path%

Run the subscriber by typing:

     make <ARGS="Domain_ID Number_of_Samples"> -f makefile_HelloWorld_i86Win32VS2013 HelloWorldSubscriber

and run the publisher by typing:

     make <ARGS="Domain_ID Number_of_Samples"> -f makefile_HelloWorld_i86Win32VS2013 HelloWorldPublisher


Optional
========
Please consult the Platform Notes and online documentation for details.

Both applications accept two optional arguments:

<Domain_ID>: In order for the two applications to communicate, they have
to use the SAME domain ID number. By default, both Hello World applications
use domain ID 0. If you want to use a specific domain ID, enter it as the
first argument (valid IDs are >= 0). If you are sharing a machine with others,
you may want to use separate domain IDs.

<Number_of_Samples>: 
In the publishing application, the second parameter is the number of
samples to publish before terminating. 
In the subscribing application, the second parameter is the number of
4-second intervals for which to sleep/awake before terminating.

