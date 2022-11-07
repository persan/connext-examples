# (c) Copyright, Real-Time Innovations, 2005-2016.
# All rights reserved.
# No duplications, whole or partial, manual or electronic, may be made
# without express written permission.  Any such copies, or
# revisions thereof, must display this notice unaltered.
# This code contains trade secrets of Real-Time Innovations, Inc.
#
# Common example creation parameters.  Override in the example's config.mk
#
#Modification History
#--------------------
#5.3.0,03mar17,djs created
##########################################################################

# include the common example configuration file ndds.4.1/example/config.mk
include ../../config.mk

# override common parameters
RTIDDSGEN_LANG = C++
RTIDDSGEN_MAKEFILE_ONLY = Hello
RTIDDSGEN_ADDITIONAL_RTI_LIBRARIES = "rtidlcpp rtidlc"

ifneq ($(filter $(target),$(RTI_DISTRIBUTEDLOG_ARCHS)),$(target))
  SKIP_GENERATE_EXAMPLE_MAKEFILES = true
  SKIP_BUILD_GENERATED_EXAMPLES = true
  POST_PROCESS_PROJECT = 
endif


