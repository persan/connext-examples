This example explains how to use the Java API for running RTI Routing Service.

The example contains a single source file that creates a Routing Service 
instance. Additionally the example provides build and run scripts for Windows
and Linux or macOS architectures.

You will need to set the following environment variables:
- NDDSHOME
- RTI_EXAMPLE_JDK_HOME: Path to your installation of Java Development Kit. This
  is required to compile the Java sources and run the resulting application.
- RTI_EXAMPLE_ARCH: The architecture for which you run the example 
  (e.g. i86Linux2.6gcc4.4.5). This is required to set the library path for the 
  native libraries on which Routing Service depends.

Building
--------

On Linux or macOS systems:

./build.sh

On Windows systems:

.\build.cmd

Running
-------
On Linux or macOS systems:

./run.sh [configuration-file]

example:

./run.sh MyString.xml

On Windows systems:

.\run.cmd [configuration-file]

example:

./run.cmd MyString.xml

Run a publisher on domain 0 and a subscriber on domain 1; the subscriber will
receive the data being published on domain 0.
