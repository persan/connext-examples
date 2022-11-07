CFG_FILE=file_bridge.xml
%:
	-@killall rtiroutingservice 2>/dev/null 1>&2
	xterm -geometry 256x24 -e rtiroutingservice -cfgFile ${CFG_FILE}\
	                  -DCURDIR=${CURDIR}\
	                  -cfgName ${@}\
	                  -identifyExecution\
	                  -remoteAdministrationDomainId 33\
	                  -remoteMonitoringDomainId 34 &
