============================================================
RTI Connext DDS Hello_world_xml_compiled Example Application
============================================================

Welcome to Connext DDS.


Compiling this Example
----------------------

Generate the HelloWorld type by running:

  > rtiddsgen -language Java -example <architecture>
              -package com.rti.hello.idl HelloWorld.idl

To build this example, type the following in a command
shell:

  > make -f makefile_HelloWorld_<architecture>


Running this Example
--------------------
To run this example, type the following in two
different command shells, either on the same machine or on different machines:

  > make -f makefile_HelloWorld_<architecture> HelloWorldSubscriber
  > make -f makefile_HelloWorld_<architecture> HelloWorldPublisher

For more information, please consult your "Getting Started Guide."
