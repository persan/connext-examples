CFG_FILE=topic_bridge_w_custom_transf.xml
all:
	make -C transformation
	-@killall rtiroutingservice 2>/dev/null 1>&2
	xterm -geometry 256x24 -e rtiroutingservice -cfgFile ${CFG_FILE}\
	                  -DCURDIR=${CURDIR}\
	                  -cfgName example\
	                  -identifyExecution\
	                  -remoteAdministrationDomainId 33\
	                  -remoteMonitoringDomainId 34 &
