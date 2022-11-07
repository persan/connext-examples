
HOSTNAME=$(shell hostname)
export PATH:=${PATH}:/usr/dds/bin
CFG_FILE=tcp_transport_lan.xml

HOSTNAME_1=${HOSTNAME}

HOSTNAME_2=nuc-2
HOST2_ROOT=/home/per/shapes.play

TCP_1_HOST:=$(shell nslookup ${HOSTNAME_1} | grep Address | tail -n 1 | cut -f 2 -d " ")
TCP_2_HOST:=$(shell nslookup ${HOSTNAME_2} | grep Address | tail -n 1 | cut -f 2 -d " ")


all:
ifeq ("${HOSTNAME}","${HOSTNAME_1}")
	-@git add .
	-@git commit -a "-mAuto"
	-@killall rtiroutingservice 2>/dev/null 1>&2
	sleep 2
	ssh -Y nuc-2 git -C ${HOST2_ROOT}  pull
	ssh -Y nuc-2 make -C ${HOST2_ROOT}/tcp_transport_lan &
	xterm -geometry 256x24 -e rtiroutingservice -cfgFile ${CFG_FILE}\
	                  -DTCP_1_HOST=${TCP_1_HOST}\
	                  -DTCP_2_HOST=${TCP_2_HOST}\
	                  -cfgName TCP_1\
	                  -identifyExecution\
	                  -remoteAdministrationDomainId 33\
	                  -remoteMonitoringDomainId 34 &
endif

ifeq ("${HOSTNAME}","${HOSTNAME_2}")
	-@killall rtiroutingservice 2>/dev/null 1>&2
	make slave&
endif

slave:
	xterm -geometry 256x24 -e rtiroutingservice -cfgFile ${CFG_FILE} \
	                  -DTCP_1_HOST=${TCP_1_HOST}\
	                  -DTCP_2_HOST=${TCP_2_HOST}\
	                  -cfgName TCP_2\
	                  -identifyExecution\
	                  -remoteAdministrationDomainId 33\
	                  -remoteMonitoringDomainId 34

# Usage: rtiroutingservice [options]
# 
# Options:
#  -D<name>=<value>               Defines a user variable that can be used as an
#                                 alternative replacement for XML environment
#                                 variables, specified in the form $(<name>).
#                                 Note that definitions in the environment
#                                 takes precedence over these definitions.
#                                 This option can be specified multiple times.
#  -appName                       <String> Application name
#                                 Used to identify this execution for 
#                                 remote administration and monitoring,
#                                 and to name the DDS DomainParticipant.
#                                 Default: -cfgName
#  -cfgFile                       <String> Semicolon-separated list of 
#                                 configuration file paths.
#                                 Default: (unspecified)
#  -cfgName                       <String> Name of the configuration to be loaded.
#                                 It must match a <routing_service> 
#                                 tag in the configuration.
#  -convertLegacyXml              <String> Converts the legacy XML specified
#                                 with -cfgFile and produces the result in the
#                                 specified output.
#                                 If no <output_path> is provided, the converted
#                                 file will be in the same path than -cfgFile
#                                 with the suffix 'converted'.
#  -domainIdBase                  <Int> Value to be added to the domain IDs in the
#                                 the domain routes in the configuration file.
#                                 Default: 0
#  -heapSnapshotDir               <String> Output directory where the heap 
#                                 monitoring snapshot are dumped.
#                                 The filename format is 
#                                 RTI_heap_<appName>_<processId>_<index>.log
#                                 Default: current working directory
#  -heapSnapshotPeriod            <Int> Period at which heap monitoring snapshots
#                                 are dumped. Enables heap monitoring if > 0.
#  -help                          Prints this help and exits.
#  -identifyExecution             Appends the host name and process ID to the 
#                                 application name.
#                                 Helps ensures unique names for remote administration
#                                 and monitoring.
#  -ignoreXsdValidation           Loads the configuration even if the XSD
#                                 validation fails.
#                                 Default: false
#  -listConfig                    Prints the available configurations and exits
#  -logFile                       <String> Redirects logging to the specified file.
#  -logFormat                     <String> A mask to configure the format of the log
#                                 messages for both the service and DDS.
#                                 * DEFAULT - Print message, method name, 
#                                             and activity context
#                                 * VERBOSE - DEFAULT + module, thread id and 
#                                             two lines.
#                                 * TIMESTAMPED - VERBOSE + timestamped
#                                 * MINIMAL - Print only message number
#                                             and method name
#                                 * MAXIMAL - Print all available fields
#                                 Default: DEFAULT
#  -maxObjectsPerThread           <Int> Maximum number of Thread-specific
#                                 objects that can be created.
#                                 Default: Same as Connext DDS default for max_objects_per_thread
#  -noAutoEnable                  Use this option if you plan to enable
#                                 the service remotely.
#  -pluginSearchPath              <String> Specifies a directory where plug-in
#                                 libraries are located.
#  -remoteAdministrationDomainId  <Int> Enables remote administration and
#                                 sets the domain ID for communication.
#                                 Default: remote administration is not enabled
#  -remoteMonitoringDomainId      <Int> Enables remote monitoring and
#                                 sets the domain ID for status publication.
#                                 Default: remote monitoring is not enabled.
#  -skipDefaultFiles              Skips attempting to load the default
#                                 configuration files
#                                 Default: (false)
#  -stopAfter                     <Int> Number of seconds the service runs
#                                 before it stops.
#                                 Default: (infinite)
#  -verbosity                     <String> Syntax is <service_level>[:<dds_level>], where:
#                                 <service_level> is the verbosity level for the
#                                 service logs and <dds_level> is the verbosity level
#                                 for the DDS logs. Both can take any of the 
#                                 following values:
#                                 * SILENT
#                                 * ERROR
#                                 * WARN
#                                 * LOCAL
#                                 * REMOTE
#                                 * ALL
#                                 Default: ERROR:ERROR.
#  -version                       Prints the product version and exits.
