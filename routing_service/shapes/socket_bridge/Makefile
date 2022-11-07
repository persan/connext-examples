CFG_FILE=socket_bridge.xml
# HOLD=-hold
%:
	-@killall rtiroutingservice 2>/dev/null 1>&2
	xterm ${HOLD} -geometry 256x24 -e rtiroutingservice -cfgFile ${CFG_FILE}\
	                  -DCURDIR=${CURDIR}\
	                  -cfgName ${@}\
	                  -identifyExecution\
	                  -remoteAdministrationDomainId 33\
	                  -remoteMonitoringDomainId 34 &
dds_to_socket:
socket_to_dds:
socket_to_socket:
socket_test:
