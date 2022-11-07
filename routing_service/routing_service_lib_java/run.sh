#!/bin/sh
###############################################################################
##         (c) Copyright, Real-Time Innovations, All rights reserved.        ##
##                                                                           ##
##         Permission to modify and use for internal purposes granted.       ##
## This software is provided "as is", without warranty, express or implied.  ##
##                                                                           ##
###############################################################################

# You can override the following settings with the correct location of Java
if [ -z "$RTI_EXAMPLE_JDK_HOME" ]; then
    JAVA_PATH=`which java`
else
    JAVA_PATH="$RTI_EXAMPLE_JDK_HOME/bin/java"
fi

# Make sure JAVAC and NDDSHOME are set correctly
test -z "$JAVA_PATH" && echo "java not found" && exit 1
test -z "$NDDSHOME" && echo "NDDSHOME environment variable not set" && exit 1
test -z "$RTI_EXAMPLE_ARCH" && echo "RTI_EXAMPLE_ARCH environment variable not set" && exit 1

# Attempt to set LD_LIBRARY_PATH from which to load native libraries.
# If RTI_EXAMPLE_ARCH is set (e.g. to i86Linux2.6gcc4.1.1), you don't
# have to separately set the LD_LIBRARY_PATH (or DYLD_LIBRARY_PATH in
# Darwin).
if [ `uname` = "Darwin" ]; then
   DYLD_LIBRARY_PATH=${NDDSHOME}/lib/${RTI_EXAMPLE_ARCH}:${DYLD_LIBRARY_PATH}
   export DYLD_LIBRARY_PATH
else
   LD_LIBRARY_PATH=${NDDSHOME}/lib/${RTI_EXAMPLE_ARCH}:${LD_LIBRARY_PATH}
   export LD_LIBRARY_PATH
fi

# Use a configuration file if specified
CFG_FILE=$1

# Ensure this script is invoked from the root directory of the project
test ! -d objs && echo "You must run this script from the example root directory" && exit 0

# set RTI_JAVA_OPTION to -d64 if you are running on 64-bit system using 64-bit
# libraries

# Run example
$JAVA_PATH $RTI_JAVA_OPTION -classpath objs:"$NDDSHOME/lib/java/nddsjava.jar:$NDDSHOME/lib/java/rtiroutingservice.jar" RunRoutingService $CFG_FILE
