
all:bin/helloWorld_publisher

bin/helloWorld_publisher:src/gen/HelloWorld.h Makefile# IGNORE
	gprbuild

src/gen/HelloWorld.h:src/HelloWorld.idl  Makefile# IGNORE
	rm -rf src/gen;mkdir src/gen
	rtiddsgen -d $(dir ${@}) ${<} -language Ada
	chmod -w  src/gen/*

start:
	xterm -e rtipersistenceservice -cfgFile PsHelloWorld.xml -cfgName HelloWorldFile -restore 0 &
