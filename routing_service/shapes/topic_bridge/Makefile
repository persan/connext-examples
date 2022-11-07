CFG_FILE=topic_bridge.xml
example:
	-@killall rtiroutingservice 2>/dev/null 1>&2
	xterm -geometry 256x24 -e rtiroutingservice -cfgFile ${CFG_FILE}\
	                  -DCURDIR=${CURDIR}\
	                  -cfgName ${@}\
	                  -identifyExecution\
	                  -remoteAdministrationDomainId 33\
	                  -remoteMonitoringDomainId 34 &
