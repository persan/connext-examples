all:
generate:
	-@rm -rf .gen;mkdir -p  .gen
	-@rm -rf src/gen;mkdir -p  src/gen
	echo "#include <routingservice/routingservice_adapter.h>" >.gen/gen.c
	gprbuild -P generate.gpr
	cp .gen/*routingservice_r*.ads src/gen
	gprbuild -P dds-ada-routing.gpr
	chmod -w src/gen/*.ads
claen:
	
