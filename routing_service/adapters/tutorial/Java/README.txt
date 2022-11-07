Example : Using a File Adapter in Java
=======================================
This example explains how to use the Java Adapter API to implement a simple
file adapter. The example provides build and run scripts for Windows and
Linux or macOS architectures.

You will need to set the following environment variables:

    - NDDSHOME: Path to your installation of RTI Connext DDS.

You will need to perform all the steps below from the example directory.

Steps
------

1. Building

    - On Linux and macOS systems:

        ./build.sh

    - On Windows systems:

        .\build.cmd

2. Setup

    Create a file in the example directory with name HelloWorld.txt that contains
    the following content:

    Hello World 1!
    Hello World 2!
    Hello World 3!
    Hello World 4!
    Hello World 5!
    Hello World 6!
    Hello World 7!
    Hello World 8!
    Hello World 9!
    Hello World 10!

    Set the environment variable RTI_LD_LIBRARY_PATH to point to the directory
    that contains the RTI Connext DDS target libraries. Additionally, add the path
    to where the Java Virtual Machine libraries are located.

3. Running

    Run Routing Service as follows:

        rtiroutingservice -cfgFile simple_file_adapter.xml -cfgName file_to_file

    On a successful run, your should notice that it outputs line by line the same
    content you put in HelloWorld.txt.

    Once it stops showing the lines in the terminal, shut down Routing Service and
    confirm there is a file with name HelloWorld_output that contains the same lines
    as the terminal output above.
