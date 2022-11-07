all:
	gprbuild

generate:
	-@rm -rf .gen src.dlada/gen
	-@mkdir -p .gen src.dlada/gen
	echo "#include <rti_dl/rti_dl_c.h>" >.gen/gen.c
	gprbuild -P generate.gpr
	cp .gen/*rti_dl_c*.ads src.dlada/gen
	gprbuild -P dds-ada-distloging.gpr
	chmod -w src.dlada/gen/*.ads
