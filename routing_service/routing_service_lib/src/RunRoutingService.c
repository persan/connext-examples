/*****************************************************************************/
/*         (c) Copyright, Real-Time Innovations, All rights reserved.        */
/*                                                                           */
/*         Permission to modify and use for internal purposes granted.       */
/* This software is provided "as is", without warranty, express or implied.  */
/*                                                                           */
/*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "ndds/ndds_c.h"
#include "routingservice/routingservice_service.h"
#include "MyString.c"

#if (!defined(RTI_VXWORKS) || defined(__RTP__))
// Catch control-C and tell application to shut down
static RTIBool shutdown_requested;

void stop_handler(int value)
{
    shutdown_requested = RTI_TRUE;
    printf("preparing to shut down...\n");
}

void setup_signal_handlers()
{
    shutdown_requested = RTI_FALSE;
    signal(SIGINT, stop_handler);
    signal(SIGTERM, stop_handler);
}
#endif

#ifdef RTI_IOS
extern int routing_service_main(const char * cfg_file)
#else
static int routing_service_main(const char * cfg_file)
#endif
{
    struct DDS_Duration_t wait_period = {4,0};
    struct RTI_RoutingService * routing_service = NULL;
    struct RTI_RoutingServiceProperty property =
            RTI_RoutingServiceProperty_INITIALIZER;

    if (cfg_file != NULL) {
        /* Use a configuration file if specified */
        property.cfg_file = (char *) cfg_file;
    } else {
        /* Use a configuration string */
        property.cfg_strings = MY_STRINGS;
        property.cfg_strings_count = MY_STRINGS_SIZE;
    }

    setup_signal_handlers();

    property.service_name = "RoutingService";

    /* Uncomment this to turn on additional logging
       property.service_verbosity =
            (RTI_LOG_BIT_EXCEPTION | RTI_LOG_BIT_WARN | RTI_LOG_BIT_LOCAL);
       property.dds_verbosity = (RTI_LOG_BIT_WARN);
    */

    /* instanciate routing service */
    routing_service = RTI_RoutingService_new(&property);
    if(routing_service == NULL) {
        perror ("Error: failed to create RoutingService instance\n");
        return -1;
    }

    printf("RoutingService successfully created\n");

    /* start routing service */
    if(!RTI_RoutingService_start(routing_service)) {

        perror ("Error: failed to start RoutingService instance\n");

        RTI_RoutingService_delete(routing_service);

        return -1;
    }

    printf("RoutingService running ...\n");

#ifndef RTI_IOS
    /* wait to be stopped */
    while(!shutdown_requested) {
        NDDS_Utility_sleep(&wait_period);
    }
#else
    /* start routing_service_main() in a thread. */
#endif

    RTI_RoutingService_stop(routing_service);

    RTI_RoutingService_delete(routing_service);

    if (DDS_DomainParticipantFactory_finalize_instance() != DDS_RETCODE_OK) {
        perror ("Error: failed to finalize DomainParticipantFactory\n");
        return -1;
    }

    return 1;
}

#if !(defined(RTI_VXWORKS) && !defined(__RTP__)) && !defined(RTI_PSOS) && !defined(RTI_IOS)
int main(int argc, char *argv[])
{
    char * cfg_file = NULL;
    if (argc >= 2) {
        cfg_file = argv[1];
    }

    return routing_service_main(cfg_file);
}
#endif
