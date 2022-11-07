======================================================
RTI Limited Bandwidth Endpoint Discovery Plugin (LBED)
Example Application
======================================================

Welcome to RTI Connext!


Compiling this Example
======================
You must set the environment variable NDDSHOME to your RTI Connext
installation directory.

To build this example on a Windows platform, open the appropriate solution
file for your version of Microsoft Visual Studio in the win32 directory. Select
from the configuration pull-down menu: Debug DLL, or Release DLL where "DLL"
is for dynamic linking (IMPORTANT: static linking is not available for LBED).

To build this example on a Linux system, type the following in a command
shell (for LBED you must use dynamic linking):

  > make -f make/makefile_ExampleLBED_<architecture> SHAREDLIB=1

To use debug, run:

  > make -f make/makefile_ExampleLBED_<architecture> SHAREDLIB=1 DEBUG=1


Running this Example
====================

Windows
-------
Your PATH must include %NDDSHOME%\lib\<architecture>.

To run this example, type the following in two different command shells, either
on the same machine or on different machines:

  > objs\<architecture>\ExampleLBED_subscriber.exe
  > objs\<architecture>\ExampleLBED_publisher.exe

Linux
-----
Your LD_LIBRARY_PATH must include $NDDSHOME/lib/<architecture>.

To run this example, type the following in two different command shells, either
on the same machine or on different machines:

  > objs/<architecture>/ExampleLBED_subscriber
  > objs/<architecture>/ExampleLBED_publisher

Accepted parameters
-------------------
This example is a modified version of an rtiddsgen-generated application.
It has been modified to use the LBED Plugin as explained in the Getting Started
chapter of the RTI Limited Bandwidth Endpoint Discovery Plugin User's Manual.
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


Troubleshooting this Example
============================
Refer to the Troubleshooting section of the Getting Started chapter in the
RTI Limited Bandwidth Endpoint Discovery Plugin User's Manual for further
information.
