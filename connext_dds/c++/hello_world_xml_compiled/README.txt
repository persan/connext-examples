========================================
CPP Hello World Example with XML Configuration
========================================

This example is a modified version of the helloWorld example that can
be generated using rtiddsgen with the -example command-line option.
The original example was modified to use XML configuration capabilities.


How to Compile
==============

Before compiling make sure that the environment variable NDDSHOME is defined 
and that it refers to your RTI Connext DDS installation directory. 


UNIX-based Systems
------------------

Use rtiddsgen to generate a makefile for your machine's architecture and
compiler. For example, if both the publisher and the subscriber application
will run on Ubuntu 18.04 or Red Hat Enterprise Linux 8 machines and you want 
to compile with the gcc 7.3.0 compiler, run rtiddsgen for the 
x64Linux4gcc7.3.0 architecture:

${NDDSHOME}/bin/rtiddsgen -language C++ -example x64Linux4gcc7.3.0 HelloWorld.idl

NOTE: You may get messages saying that some files already exist and will
not be replaced. You can safely ignore those messages, since all the
source files for this example are already provided.

Before compiling, make sure that the desired version of compiler and linker
are in your PATH environment variable.

Then compile by typing:

make -f makefile_HelloWorld_x64Linux4gcc7.3.0


Windows Systems
---------------

Use rtiddsgen to generate the solution and project files for your
version of Visual Studio. For example, if both the publisher and the
subscriber application will be compiled with Visual Studio 2013,
run rtiddsgen for the i86Win32VS2013 architecture:

%NDDSHOME\bin\rtiddsgen -language C++ -example i86Win32VS2013 HelloWorld.idl

Open the solution file for your architecture with Visual Studio. Build the
two projects, HelloWorld_publisher and HelloWorld_subscriber, with the 
Win32 Release setting (or Win32 Debug settings if you prefer).

How to Run
==========

1.  In your library search path, you MUST have the location of 
    the Connext DDS shared libraries, because the applications
    will load the shared object dynamically when they start.

    For UNIX-based systems, you need to add the directory:
            $NDDSHOME/lib/<architecture>
    to your LD_LIBRARY_PATH.

    For Windows systems, you need to add the directory:
            %NDDSHOME%\lib\<architecture>
    to your PATH environment variable.

2. On one machine, run the publisher:

   The executable may receive one argument:
   - Number of samples to send
   
   UNIX-based Systems:

   ./objs/<arch>/HelloWorld_publisher 

   Windows Systems:

   objs\<arch>\HelloWorld_publisher.exe 


4. On another machine or terminal, run the subscriber:

   The executable may receive one argument:
   - Number of samples to receive

   UNIX-based Systems:

   ./objs/<arch>/HelloWorld_subscriber

   Windows Systems:

   objs\<arch>\HelloWorld_subscriber.exe
