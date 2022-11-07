======================================================
RTI Limited Bandwidth Plugins
Example Application Using Several Plugins
======================================================

Welcome to RTI Connext!

This example shows the minimum required configuration for enabling all of the
RTI Limited Bandwidth Plugins in the same DomainParticipant:

- Limited Bandwidth Participant Discovery Plugin (LBPD).
- Limited Bandwidth Endpoint Discovery Plugin (LBED).
- Limited Bandwidth RTPS Transport Plugin (LBRTPS) with the Compression
  Real-Time Publish Subscribe Transport Plugin (ZRTPS) as sub-transport.

Note: For more information on the advanced configuration of LBRTPS and ZRTPS,
refer to the examples below:

- connext_dds/c/limited_bandwidth_plugins/lbrtps
- connext_dds/c/limited_bandwidth_plugins/zrtps

Compiling this Example
======================
You must set the environment variable NDDSHOME to your RTI Connext
installation directory.

To build this example on a Windows platform, open the appropriate solution
file for your version of Microsoft Visual Studio in the win32 directory. Select
from the configuration pull-down menu: Debug DLL, or Release DLL where "DLL"
is for dynamic linking (IMPORTANT: static linking is not available for the
Limited Bandwidth Plugins).

To build this example on a Linux system, type the following in a command
shell (for the Limited Bandwidth Plugins you must use dynamic linking):

  > make -f make/makefile_DilStacking_<architecture> SHAREDLIB=1

To use debug, run:

  > make -f make/makefile_DilStacking_<architecture> SHAREDLIB=1 DEBUG=1


Running this Example
====================

Windows
-------
Your PATH must include %NDDSHOME%\lib\<architecture>.

To run this example, type the following in two different command shells, either
on the same machine or on different machines:

  > objs\<architecture>\DilStacking_subscriber.exe
  > objs\<architecture>\DilStacking_publisher.exe

Linux
-----
Your LD_LIBRARY_PATH must include $NDDSHOME/lib/<architecture>.

To run this example, type the following in two different command shells, either
on the same machine or on different machines:

  > objs/<architecture>/DilStacking_subscriber
  > objs/<architecture>/DilStacking_publisher

Accepted parameters
-------------------
This example is a modified version of an rtiddsgen-generated application.
It accepts the following command-line arguments:

 * -d, --domain       <int>   Domain ID the application will use. Default: 0.
                              If you use a Domain ID different than the default
                              one, change the value of the domain_id attribute
                              in the USER_QOS_PROFILES.xml.
 * -s, --sample_count <int>   Number of samples to send/receive before cleanly
                              shutting down. Default: infinite.
 * -v, --verbosity    <int>   How much debugging output to show.
                              Range: 0-3. Default: 1.
 * -h, --help                 Print the information above and exit.
