JAVA_SOURCES=$(wildcard *.java)
export CLASSPATH=${NDDSHOME}/lib/java/nddsjava.jar:${NDDSHOME}/lib/java/rtiroutingservice.jar:${CURDIR}/routing_service_lib_java.jar
export LD_LIBRARY_PATH:=${NDDSHOME}/lib/x64Linux4gcc7.3.0/:${LD_LIBRARY_PATH}

build:
	rm -rf .objs;mkdir -p .objs
	javac -d .objs  ${JAVA_SOURCES}
	cd .objs;jar  -c -f ${CURDIR}/routing_service_lib_java.jar .

run:
	java  RunRoutingService ${CFG_FILE}
