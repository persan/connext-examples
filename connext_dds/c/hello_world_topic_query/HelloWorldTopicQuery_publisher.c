#include <stdio.h>
#include <stdlib.h>
#include "ndds/ndds_c.h"
#include "HelloWorldTopicQuery.h"
#include "HelloWorldTopicQuerySupport.h"
#include "HelloWorldTopicQueryUtils.h"

typedef struct CommandLineArguments_t {
    int domain_id;
    int count;
    int lower_instance_id;
    int upper_instance_id;
    int write_period;
    int burst_size;
} CommandLineArguments;

static void CommandLineArguments_initialize(CommandLineArguments *arg)
{
    arg->domain_id = DEFAULT_DOMAIN_ID;
    arg->count = -1;
    arg->lower_instance_id = 0;
    arg->upper_instance_id = -1;
    arg->write_period = 4;
    arg->burst_size = 0;
}

/*
 * Delete all entities
 */
static int HelloWorldTopicQuery_shutdown(DDS_DomainParticipant *participant)
{
    DDS_ReturnCode_t retcode;
    int status = 0;

    if (participant != NULL) {
        retcode = DDS_DomainParticipant_delete_contained_entities(participant);
        if (retcode != DDS_RETCODE_OK) {
            printf("delete_contained_entities error %d\n", retcode);
            status = -1;
        }

        retcode = DDS_DomainParticipantFactory_delete_participant(
        DDS_TheParticipantFactory, participant);
        if (retcode != DDS_RETCODE_OK) {
            printf("delete_participant error %d\n", retcode);
            status = -1;
        }
    }

    /* RTI Connext provides finalize_instance() method on
     domain participant factory for people who want to release memory used
     by the participant factory. Uncomment the following block of code for
     clean destruction of the singleton. */
    /*

     retcode = DDSDomainParticipantFactory_finalize_instance();
     if (retcode != DDS_RETCODE_OK) {
     printf("finalize_instance error %d\n", retcode);
     status = -1;
     }
     */

    return status;
}

static int HelloWorldTopicQuery_start_publisher(CommandLineArguments *cmd_arg)
{
    DDS_DomainParticipant *participant = NULL;
    DDS_Topic *topic = NULL;
    DDS_DataWriter *writer = NULL;
    HelloWorldTopicQueryDataWriter *HelloWorldTopicQuery_writer = NULL;
    HelloWorldTopicQuery *instance = NULL;
    DDS_ReturnCode_t retcode;
    DDS_InstanceHandle_t instance_handle = DDS_HANDLE_NIL;
    const char *type_name = NULL;
    struct DDS_Duration_t send_period = {0, 0};
    int count;

    /* To customize participant QoS, use
     the configuration file USER_QOS_PROFILES.xml */
    participant = DDS_DomainParticipantFactory_create_participant_with_profile(
            DDS_TheParticipantFactory,
            cmd_arg->domain_id,
            "HelloWorldTopicQuery_Library",
            "HelloWorldTopicQuery_Profile",
            NULL /* listener */,
            DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        printf("create_participant_with_profile error\n");
        HelloWorldTopicQuery_shutdown(participant);
        return -1;
    }

    /* Register type before creating topic */
    type_name = HelloWorldTopicQueryTypeSupport_get_type_name();
    retcode = HelloWorldTopicQueryTypeSupport_register_type(
            participant,
            type_name);
    if (retcode != DDS_RETCODE_OK) {
        printf("register_type error %d\n", retcode);
        HelloWorldTopicQuery_shutdown(participant);
        return -1;
    }

    /* To customize topic QoS, use
     the configuration file USER_QOS_PROFILES.xml */
    topic = DDS_DomainParticipant_create_topic(
            participant,
            "Example HelloWorldTopicQuery",
            type_name,
            &DDS_TOPIC_QOS_DEFAULT,
            NULL /* listener */,
            DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        printf("create_topic error\n");
        HelloWorldTopicQuery_shutdown(participant);
        return -1;
    }

    /* To customize data writer QoS, use
     the configuration file USER_QOS_PROFILES.xml. QoS configuration to enable
     TopicQueries is added in the configuration file. */
    writer = DDS_DomainParticipant_create_datawriter_with_profile(
            participant,
            topic,
            "HelloWorldTopicQuery_Library",
            "HelloWorldTopicQuery_Profile",
            NULL /* listener */,
            DDS_STATUS_MASK_NONE);
    if (writer == NULL) {
        printf("create_datawriter_with_profile error\n");
        HelloWorldTopicQuery_shutdown(participant);
        return -1;
    }

    HelloWorldTopicQuery_writer = HelloWorldTopicQueryDataWriter_narrow(writer);
    if (HelloWorldTopicQuery_writer == NULL) {
        printf("DataWriter narrow error\n");
        HelloWorldTopicQuery_shutdown(participant);
        return -1;
    }

    /*
     * Writing logic of the application.
     *
     * There are two write phases:
     * - A single initial burst of burst_size samples.
     * - A periodic phase that writes up to the specified count samples every
     *  write_period.
     */

    /* Create data sample for writing */
    instance = HelloWorldTopicQueryTypeSupport_create_data();
    if (instance == NULL) {
        printf("create data error\n");
        HelloWorldTopicQuery_shutdown(participant);
        return -1;
    }

    send_period.sec = cmd_arg->write_period;
    instance_handle = DDS_HANDLE_NIL;

    /* For a data type that has a key, if the same instance is going to be
     written multiple times, initialize the key here
     and register the keyed instance prior to writing */
    /*
     instance_handle = HelloWorldTopicQuery_writer->register_instance(*instance);
     */

    /* Main loop */

    for (count = 0; (cmd_arg->count < 0) || (count < cmd_arg->count);
            ++count) {

        printf("Writing HelloWorldTopicQuery, count %d\n", count);
        fflush(stdout);
        /* Modify the data to be sent here */
        if (cmd_arg->lower_instance_id >= 0) {
            instance->id = cmd_arg->upper_instance_id < 0
                    ? count % (cmd_arg->lower_instance_id + 1)
                    : count % (cmd_arg->upper_instance_id
                        - cmd_arg->lower_instance_id);
        } else {
            instance->id = count;
        }

        RTI_SNPRINTF(instance->message, 20, "count: %d", count);
        retcode = HelloWorldTopicQueryDataWriter_write(
                HelloWorldTopicQuery_writer,
                instance,
                &instance_handle);
        if (retcode != DDS_RETCODE_OK) {
            printf("write error %d\n", retcode);
        }
        if (count >= cmd_arg->burst_size) {
            NDDS_Utility_sleep(&send_period);
        }
    }

    /*
     retcode = HelloWorldTopicQuery_writer->unregister_instance(
     *instance, instance_handle);
     if (retcode != DDS_RETCODE_OK) {
     printf("unregister instance error " << retcode );
     }
     */

    /* Delete data sample */
    retcode = HelloWorldTopicQueryTypeSupport_delete_data(instance);
    if (retcode != DDS_RETCODE_OK) {
        printf("delete data error %d\n", retcode);
    }

    /* Cleanup and delete delete all entities */
    return HelloWorldTopicQuery_shutdown(participant);
}

/*
 * Prints help on command line accepted by this application
 */
void HelloWorldTopicQuery_print_usage()
{
    printf("Usage: HelloWorldTopicQueryPublisher [options]\n");
    printf("Where arguments are:\n");
    printf("  -h | --help                 "
            "Shows this page\n");
    printf("  -d | --domain <domain_id>   "
            "Sets the DDS domain ID [default=0]\n");
    printf("  -c <count>                  "
            "Sets the number of samples to write [default=-1 (infinite)]\n");
    printf("  -l <lower_instance_id>      "
            "Sets the lower_instance_id [default=0]\n");
    printf("  -u <upper_instance_id>      "
            "Sets the upper_instance_id [default=-1 (no upper limit)]\n");
    printf("  -p <write_period>           "
            "Sets the periodic rate at which the samples are "
            "published [default=4s]\n");
    printf("  -b <burst_size>             "
            "Sets the initial number of samples published [default=0]\n");
}

int main(int argc, char *argv[])
{
    int i;
    CommandLineArguments arg;
    CommandLineArguments_initialize(&arg);

    /* Parse the optional arguments */
    for (i = 1; i < argc; ++i) {
        if (!RTI_STRNCMP(argv[i], "-h", 2)
                || !RTI_STRNCMP(argv[i], "--help", 6)) {
            HelloWorldTopicQuery_print_usage();
            return EXIT_SUCCESS;
        }
        if (!RTI_STRNCMP(argv[i], "-d", 2)
                || !RTI_STRNCMP(argv[i], "--domain", 8)) {
            char *ptr;
            if (HelloWorldTopicQuery_ensure_one_more_argument(argc, i, "-d")
                    == EXIT_FAILURE) {
                return EXIT_FAILURE;
            }
            arg.domain_id = strtol(argv[++i], &ptr, 10);
            if (*ptr != '\0') {
                HelloWorldTopicQuery_print_usage();
                printf(
                        "! Value of --domain argument is not a number: %s\n",
                        argv[i]);
                return EXIT_FAILURE;
            }
            if (arg.domain_id < 0 || arg.domain_id > DOMAIN_ID_MAX) {
                HelloWorldTopicQuery_print_usage();
                printf("! Invalid DDS Domain ID: %d\n", arg.domain_id);
                printf("! The domain ID must be between 0 and %d (inclusive)\n",
                DOMAIN_ID_MAX);
                return EXIT_FAILURE;
            }
            continue;
        }
        if (!RTI_STRNCMP(argv[i], "-c", 2)) {
            char *ptr;
            if (HelloWorldTopicQuery_ensure_one_more_argument(argc, i, "-c")
                    == EXIT_FAILURE) {
                return EXIT_FAILURE;
            }
            arg.count = strtol(argv[++i], &ptr, 10);
            if (*ptr != '\0') {
                HelloWorldTopicQuery_print_usage();
                printf("! Value of -c argument is not a number: %s\n", argv[i]);
                return EXIT_FAILURE;
            }
            if (arg.count <= 0) {
                HelloWorldTopicQuery_print_usage();
                printf("! Invalid value for count argument: %d\n", arg.count);
                return EXIT_FAILURE;
            }
            continue;
        }
        if (!RTI_STRNCMP(argv[i], "-l", 2)) {
            char *ptr;
            if (HelloWorldTopicQuery_ensure_one_more_argument(argc, i, "-l")
                    == EXIT_FAILURE) {
                return EXIT_FAILURE;
            }
            arg.lower_instance_id = strtol(argv[++i], &ptr, 10);
            if (*ptr != '\0') {
                HelloWorldTopicQuery_print_usage();
                printf("! Value of -l argument is not a number: %s\n", argv[i]);
                return EXIT_FAILURE;
            }
            if (arg.lower_instance_id < 0) {
                HelloWorldTopicQuery_print_usage();
                printf(
                        "! Invalid value for lower_instance_id argument: %d\n",
                        arg.lower_instance_id);
                return EXIT_FAILURE;
            }
            continue;
        }
        if (!RTI_STRNCMP(argv[i], "-u", 2)) {
            char *ptr;
            if (HelloWorldTopicQuery_ensure_one_more_argument(argc, i, "-u")
                    == EXIT_FAILURE) {
                return EXIT_FAILURE;
            }
            arg.upper_instance_id = strtol(argv[++i], &ptr, 10);
            if (*ptr != '\0') {
                HelloWorldTopicQuery_print_usage();
                printf("! Value of -u is not a number: %s\n", argv[i]);
                return EXIT_FAILURE;
            }
            if (arg.upper_instance_id < 0) {
                HelloWorldTopicQuery_print_usage();
                printf(
                        "! Invalid value for upper_instance_id argument: %d\n",
                        arg.upper_instance_id);
                return EXIT_FAILURE;
            }
            continue;
        }
        if (!RTI_STRNCMP(argv[i], "-p", 2)) {
            char *ptr;
            if (HelloWorldTopicQuery_ensure_one_more_argument(argc, i, "-p")
                    == EXIT_FAILURE) {
                return EXIT_FAILURE;
            }
            arg.write_period = strtol(argv[++i], &ptr, 10);
            if (*ptr != '\0') {
                HelloWorldTopicQuery_print_usage();
                printf("! Value of -p argument is not a number: %s\n", argv[i]);
                return EXIT_FAILURE;
            }
            if (arg.write_period < 0) {
                HelloWorldTopicQuery_print_usage();
                printf(
                        "! Invalid value for write_period argument: %d\n",
                        arg.write_period);
                return EXIT_FAILURE;
            }
            continue;
        }
        if (!RTI_STRNCMP(argv[i], "-b", 2)) {
            char *ptr;
            if (HelloWorldTopicQuery_ensure_one_more_argument(argc, i, "-b")
                    == EXIT_FAILURE) {
                return EXIT_FAILURE;
            }
            arg.burst_size = strtol(argv[++i], &ptr, 10);
            if (*ptr != '\0') {
                HelloWorldTopicQuery_print_usage();
                printf("! Value of -b argument is not a number: %s\n", argv[i]);
                return EXIT_FAILURE;
            }
            if (arg.burst_size < 0) {
                HelloWorldTopicQuery_print_usage();
                printf(
                        "! Invalid value for burst_size argument: %d\n",
                        arg.burst_size);
                return EXIT_FAILURE;
            }
            continue;
        }
    }

    /* Uncomment this to turn on additional logging
     NDDSConfigLogger::get_instance()->
     set_verbosity_by_category(NDDS_CONFIG_LOG_CATEGORY_API,
     NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
     */

    return HelloWorldTopicQuery_start_publisher(&arg);
}

