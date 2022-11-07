=====================================================
RTI Connext
Hello_world_xml_dynamic Example Application
=====================================================

How to Compile
==============

Before compiling make sure that the environment variable NDDSHOME is defined 
and that it refers to your RTI Connext installation directory. 


Compiling this Example
======================

Set NDDSHOME to your RTI Connext installation directory.

* Windows Systems

To build this example on Windows, open the appropriate solution files for your
version of Microsoft Visual Studio located in the win32 directory.

* UNIX-based Systems

Type the following in a command where <architecture> is replaced with the string that identifies 
the machine's architecture and compiler. For example, i86Linux2.6gcc4.4.3 identifies a 
Linux 2.6 OS platform that has the 4.4.3 version of the GNU GCC compiler:

  > make -f make/makefile_Hello_<architecture>
  For example:
  make -f make/makefile_Hello_i86Linux2.6gcc4.4.3

You can see a complete list of the architectures you have available by listing the directory:
$NDDSHOME/lib


How to Run
==========

1.  If you compiled dynamically, you need to specify the location
    of the RTI Connext DDS shared libraries.

    For UNIX-based systems, you need to add the directory:
            $NDDSHOME/lib/<architecture>
    to your LD_LIBRARY_PATH.

    For Windows systems, you need to add the the directory:
            %NDDSHOME%\lib\<architecture>
    to your PATH environment variable.

2. On one machine, run the publisher:

   The first parameter must be 'pub' the second parameter is the
   number of samples to send.  If the second parameter is 0 or
   blank the executable will run until interrupted.
   
   UNIX-based Systems:

   ./objs/<architecture>/Hello pub

   Windows Systems:

   objs\<architecture>\Hello.exe pub


4. On another machine or terminal, run the subscriber:

   The first parameter must be 'sub' the second parameter is the
   number of 4-second intervals to run.  If the second parameter is
   0 or blank the executable will run until interrupted.

   UNIX-based Systems:

   ./objs/<architecture>/Hello sub

   Windows Systems:

   objs\<architecture>\Hello.exe sub

