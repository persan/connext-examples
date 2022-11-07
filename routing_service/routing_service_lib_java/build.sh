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
    JAVAC_PATH=`which javac`
else
    JAVAC_PATH="$RTI_EXAMPLE_JDK_HOME/bin/javac"
fi

# Make sure JAVAC and NDDSHOME are set correctly
test -z "$JAVAC_PATH" && echo "javac not found" && exit 1
test -z "$NDDSHOME" && echo "NDDSHOME environment variable not set" && exit 1

JAVA_SOURCES=RunRoutingService.java
# Ensure this script is invoked from the root directory of the project
test ! -f $JAVA_SOURCES && echo "You must run this script from the example root directory" && exit 1

mkdir -p objs

# Builds all files to 'objs'
echo "Building all the sources into 'objs' directory..."
$JAVAC_PATH -d objs -classpath "$NDDSHOME/lib/java/nddsjava.jar:$NDDSHOME/lib/java/rtiroutingservice.jar" $JAVA_SOURCES

