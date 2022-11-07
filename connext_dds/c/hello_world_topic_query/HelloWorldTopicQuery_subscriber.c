#include <stdio.h>
#include <stdlib.h>
#include "ndds/ndds_c.h"
#include "HelloWorldTopicQuery.h"
#include "HelloWorldTopicQuerySupport.h"
#include "HelloWorldTopicQueryUtils.h"

typedef struct CommandLineArguments_t {
    int    domain_id;
    int    count;
    int    instance_id;
    int    topic_query_wait_max;
} CommandLineArguments;

static void CommandLineArguments_initialize(
                        CommandLineArguments *arg) {
    arg->domain_id = DEFAULT_DOMAIN_ID;
    arg->count = -1;
    arg->instance_id = -1;
    arg->topic_query_wait_max = 0;
}

CommandLineArguments cmd_arg;

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
    retcode = DDS_DomainParticipantFactory_finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        printf("finalize_instance error %d\n", retcode);
        status = -1;
    }*/


    return status;
}

static void HelloWorldTopicQuery_print_received_sample(
    HelloWorldTopicQuery *sample, struct DDS_SampleInfo *info)
{
    int i;

    if(!DDS_GUID_equals(&info->topic_query_guid, &DDS_GUID_UNKNOWN)) {
       printf("Received TopicQuery sample with GUID ");
       for (i = 0; i < 16; i++) {
           printf("%02X", (int)info->topic_query_guid.value[i]);
       }
   } else {
       printf("Received live sample");
   }
   printf(":");
   HelloWorldTopicQueryTypeSupport_print_data(sample);
   printf("\n");
   fflush(stdout);
}

/*
 * Takes the available samples and prints their content.
 *
 * The operation will determine whether a sample belongs to a TopicQuery
 * stream or to the live stream, and print a header accordingly.
 *
 * Sets is_topic_query_last_sample to true when the last topic query sample is
 * received.
 */
int HelloWorldTopicQuery_process_samples(
    DDS_DataReader *reader, DDS_ReadCondition *read_condition,
    int *sample_count, DDS_Boolean *is_topic_query_last_sample)
{
    struct HelloWorldTopicQuerySeq data_seq =  DDS_SEQUENCE_INITIALIZER;
    struct DDS_SampleInfoSeq info_seq = DDS_SEQUENCE_INITIALIZER;
    HelloWorldTopicQuery *data;
    struct DDS_SampleInfo *info;
    DDS_ReturnCode_t retcode;
    int i;

    HelloWorldTopicQueryDataReader *helloWorldReader =
        (HelloWorldTopicQueryDataReader *)reader;
    if (helloWorldReader == NULL) {
        printf("DataReader narrow error");
        return -1;
    }

    retcode = HelloWorldTopicQueryDataReader_take_w_condition(helloWorldReader,
        &data_seq, &info_seq, DDS_LENGTH_UNLIMITED, read_condition);

    if (retcode == DDS_RETCODE_NO_DATA) {
        return -1;
    } else if (retcode != DDS_RETCODE_OK) {
        printf("take error %d\n", retcode);
        return -1;
    }

    for (i = 0; i < HelloWorldTopicQuerySeq_get_length(&data_seq); ++i) {
        info = DDS_SampleInfoSeq_get_reference(&info_seq, i);
        if (info->valid_data) {
            data = HelloWorldTopicQuerySeq_get_reference(&data_seq, i);
            HelloWorldTopicQuery_print_received_sample(data, info);
            (*sample_count)++;

            if (DDS_GUID_equals(&info->topic_query_guid, &DDS_GUID_UNKNOWN)) {
                /*
                 * If we are processing samples for a TopicQuery, we may
                 * indicate that no more samples are expected if the
                 * corresponding flag is present. Note that such flag will be
                 * set by each DataWriter that accepts the TopicQuery. This
                 * example assumes that an instance is published by only one
                 * DataWriter.
                 */
                if (is_topic_query_last_sample != NULL) {
                    *is_topic_query_last_sample = !(info->flag &
                        DDS_INTERMEDIATE_TOPIC_QUERY_SAMPLE);
                    if (*is_topic_query_last_sample
                            && cmd_arg.instance_id >= 0) {
                        break;
                    }
                }
            }
        }
    }

    retcode = HelloWorldTopicQueryDataReader_return_loan(helloWorldReader,
        &data_seq, &info_seq);
    if (retcode != DDS_RETCODE_OK) {
        printf("return loan error %d\n", retcode);
    }
    return 0;
}

void HelloWorldTopicQuery_subtract_duration(
    struct DDS_Duration_t *d2, struct DDS_Duration_t *d1)
{
    DDS_Long nanosec_result = 0;
    d2->sec = d2->sec - d1->sec;
    nanosec_result = (DDS_Long)d2->nanosec - (DDS_Long)d1->nanosec;
     if (nanosec_result < 0) {
         d2->sec--;
         d2->nanosec = nanosec_result + 1000000000;
     } else {
         d2->nanosec = nanosec_result;
     }
     if (d2->sec < 0) {
         /* No negative durations */
         d2->sec = 0;
         d2->nanosec = 0;
     }
}

/*
 * Waits and processes samples for a specified wait_time.
 */
void HelloWorldTopicQuery_wait_for_samples_by_time(
    DDS_DomainParticipant *participant, DDS_DataReader *reader,
    DDS_WaitSet *waitset, int *sample_count, struct DDS_Duration_t *wait_time)
{
    struct DDS_ConditionSeq active_conditions = DDS_SEQUENCE_INITIALIZER;
    struct DDS_Time_t time_1, time_2;
    DDS_Boolean is_topic_query_last_sample = DDS_BOOLEAN_FALSE;
    DDS_ReturnCode_t retcode;
    int i;

    while (wait_time->sec > 0) {
        retcode = DDS_DomainParticipant_get_current_time(participant, &time_1);
        if (retcode != DDS_RETCODE_OK) {
            printf("get_current_time error %d\n", retcode);
            return;
        }
        retcode = DDS_WaitSet_wait(waitset, &active_conditions, wait_time);
        if (retcode == DDS_RETCODE_TIMEOUT) {
            printf("Wait timed out!! No conditions were triggered.\n");
            return;
        }
        else if (retcode != DDS_RETCODE_OK) {
            printf("wait error %d\n", retcode);
            return;
        }
        for (i = 0; i < DDS_ConditionSeq_get_length(&active_conditions);
            i++) {
            if (HelloWorldTopicQuery_process_samples(
                reader, (DDS_ReadCondition *) (DDS_ConditionSeq_get(
                    &active_conditions, i)),
                sample_count, &is_topic_query_last_sample) == -1) {
                return;
            }
            if (is_topic_query_last_sample) {
                return;
            }
        }
        DDS_ConditionSeq_finalize(&active_conditions);

        retcode = DDS_DomainParticipant_get_current_time(participant, &time_2);
        if (retcode != DDS_RETCODE_OK) {
            printf("get_current_time error %d\n", retcode);
            return;
        }

        /*Update wait_time by deducting spent time*/
        HelloWorldTopicQuery_subtract_duration((struct DDS_Duration_t *)&time_2,
            (struct DDS_Duration_t *)&time_1);
        HelloWorldTopicQuery_subtract_duration(wait_time,
            (struct DDS_Duration_t *)&time_2);
    }
}

/*
 * Waits until the specified number of samples have been received and
 * processed.
 */
void HelloWorldTopicQuery_wait_for_samples_by_count(DDS_DataReader *reader,
    DDS_WaitSet *waitset, int *sample_count, int max_sample_count)
{
    struct DDS_ConditionSeq active_conditions = DDS_SEQUENCE_INITIALIZER;
    const struct DDS_Duration_t READ_PERIOD = {2,0};
    int i;

    while (max_sample_count < 0 || *sample_count < max_sample_count) {
        DDS_WaitSet_wait(waitset, &active_conditions, &READ_PERIOD);
        for (i = 0; i < DDS_ConditionSeq_get_length(&active_conditions);
            i++) {
            if (HelloWorldTopicQuery_process_samples(reader,
                (DDS_ReadCondition *)(DDS_ConditionSeq_get(
                    &active_conditions, i)),
                sample_count, NULL) == -1) {
                DDS_ConditionSeq_finalize(&active_conditions);
                return;
            }
        }
        DDS_ConditionSeq_finalize(&active_conditions);
    }
}

/*
 * Reading logic of the application.
 *
 * There are two phases:
 * - An initial phase in which the application processes only TopicQuery
 * samples for up to the specified topic_query_wait_max time.
 * - A periodic read phase in which the application processes both
 * TopicQuery and live samples for up to the specified count value.
 */
static int HelloWorldTopicQuery_start_subscriber()
{
    DDS_DomainParticipant *participant = NULL;
    const char *type_name = NULL;
    DDS_Topic *topic = NULL;
    DDS_TopicDescription *topic_description = NULL;
    DDS_DataReader *reader = NULL;
    struct DDS_ReadConditionParams read_condition_params =
        DDS_READCONDITIONPARAMS_DEFAULT;
    DDS_ReadCondition *topic_query_read_condition = NULL;
    DDS_ReadCondition *live_stream_read_condition = NULL;
    DDS_TopicQuery *topic_query = NULL;
    DDS_WaitSet *waitset = NULL;
    struct DDS_Duration_t wait_time = DDS_DURATION_ZERO;
    int sample_count = 0;
    struct DDS_StringSeq expression_param = DDS_SEQUENCE_INITIALIZER;
    DDS_ReturnCode_t retcode;

    /* To customize participant QoS, use
    the configuration file USER_QOS_PROFILES.xml */
    participant = DDS_DomainParticipantFactory_create_participant_with_profile(
        DDS_TheParticipantFactory, cmd_arg.domain_id,
        "HelloWorldTopicQuery_Library", "HelloWorldTopicQuery_Profile",
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        printf("create_participant_with_profile error\n");
        HelloWorldTopicQuery_shutdown(participant);
        return -1;
    }

    /* Register type before creating topic */
    type_name = HelloWorldTopicQueryTypeSupport_get_type_name();
    retcode = HelloWorldTopicQueryTypeSupport_register_type(
        participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        printf("register_type error %d\n", retcode);
        HelloWorldTopicQuery_shutdown(participant);
        return -1;
    }

    /* To customize topic QoS, use
    the configuration file USER_QOS_PROFILES.xml */
    topic = DDS_DomainParticipant_create_topic(
        participant, "Example HelloWorldTopicQuery",
        type_name, &DDS_TOPIC_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        printf("create_topic error\n");
        HelloWorldTopicQuery_shutdown(participant);
        return -1;
    }
    topic_description = DDS_Topic_as_topicdescription(topic);
    /* Set up the content filter and DataReader. To customize the DataReader
     * QoS, use the configuration file USER_QOS_PROFILES.xml. DataReader
     * resource limits related to TopicQueries is added in the
     * configuration file */
    if (cmd_arg.instance_id >= 0) {
        char cft_string[15];
        RTI_SNPRINTF(cft_string, 15, "id=%d", cmd_arg.instance_id);
        topic = (DDS_Topic *)
            DDS_DomainParticipant_create_contentfilteredtopic(
                participant, "HelloWorldTopicQuerySubscriber_cft",
                topic, cft_string, &expression_param);

        if (topic == NULL) {
            printf("create_contentfilteredtopic error\n");
            HelloWorldTopicQuery_shutdown(participant);
            return -1;
        }
        topic_description = DDS_ContentFilteredTopic_as_topicdescription(
            (DDS_ContentFilteredTopic *)topic);
    }

    reader = DDS_DomainParticipant_create_datareader_with_profile(
            participant, topic_description,
            "HelloWorldTopicQuery_Library", "HelloWorldTopicQuery_Profile",
            NULL, DDS_STATUS_MASK_NONE);
    if (reader == NULL) {
        printf("create_datareader_with_profile error\n");
        HelloWorldTopicQuery_shutdown(participant);
        return -1;
    }

    /* Read Condition exclusively for Topic Query stream */
    read_condition_params.stream_kinds = DDS_TOPIC_QUERY_STREAM;
    topic_query_read_condition = DDS_DataReader_create_readcondition_w_params(
        reader, &read_condition_params);
    if (topic_query_read_condition == NULL) {
        printf("create_readcondition_w_params topic_query_read_condition"
            " error\n");
        HelloWorldTopicQuery_shutdown(participant);
        return -1;
    }

    /* Read Condition for Live stream */
    read_condition_params.stream_kinds = DDS_LIVE_STREAM;
    live_stream_read_condition = DDS_DataReader_create_readcondition_w_params(
        reader, &read_condition_params);
    if (live_stream_read_condition == NULL) {
        printf("create_readcondition_w_params "
            "live_stream_read_condition error\n");
        HelloWorldTopicQuery_shutdown(participant);
        return -1;
    }

    /* Create a TopicQuery to receive the samples published before the
    * creation of this reader.*/
    if (cmd_arg.instance_id < 0) {
        topic_query = DDS_DataReader_create_topic_query(
            reader, &DDS_TOPIC_QUERY_SELECTION_SELECT_ALL);
    } else {
        topic_query = DDS_DataReader_create_topic_query(
            reader, &DDS_TOPIC_QUERY_SELECTION_USE_READER_CONTENT_FILTER);
    }
    if (topic_query == NULL) {
        printf("create topic_query error\n");
        HelloWorldTopicQuery_shutdown(participant);
        return -1;
    }

    /* Read first TopicQuery samples. */
    waitset = DDS_WaitSet_new();
    if (waitset == NULL) {
        printf("create waitset error \n");
        HelloWorldTopicQuery_shutdown(participant);
        return -1;
    }
    retcode = DDS_WaitSet_attach_condition(waitset,
        (DDS_Condition*)topic_query_read_condition);
    if(retcode != DDS_RETCODE_OK) {
        printf("attach_condition topic_query_read_condition error %d\n",
            retcode);
        HelloWorldTopicQuery_shutdown(participant);
        return -1;
    }

    printf("HelloWorldTopicQuerySubscriber waiting for the first sample\n");
    fflush(stdout);
    wait_time.sec = cmd_arg.topic_query_wait_max;
    HelloWorldTopicQuery_wait_for_samples_by_time(participant, reader,
        waitset, &sample_count, &wait_time);

    /* Read both live and topic query samples. */
    retcode = DDS_WaitSet_attach_condition(waitset,
        (DDS_Condition*)live_stream_read_condition);
    if(retcode != DDS_RETCODE_OK) {
        printf("attach_condition live_stream_read_condition error %d\n",
            retcode);
        HelloWorldTopicQuery_shutdown(participant);
        return -1;
    }
    HelloWorldTopicQuery_wait_for_samples_by_count(reader, waitset,
        &sample_count, cmd_arg.count);

    retcode = DDS_WaitSet_delete(waitset);
    if (retcode != DDS_RETCODE_OK) {
        printf("delete waitset error %d\n", retcode);
    }

    return HelloWorldTopicQuery_shutdown(participant);
}

/*
 * Prints help on command line accepted by this application
 */
void HelloWorldTopicQuery_print_usage() {
    printf("Usage: HelloWorldTopicQuerySubscriber [options]\n");

    printf("Where arguments are:\n");
    printf("  -h | --help                 Shows this page\n");
    printf("  -d | --domain <domainID>    "
              "Sets the DDS domain ID [default=0]\n");
    printf("  -c <count>                  "
              "Sets the number of samples to receive "
              "[default=-1 (infinite)]\n");
    printf("  -i <instance_id>            "
              "Sets the requested instance_id [default=-1 (all)]\n");
    printf("  -t <topic_query_wait_max>   "
              "Sets the maximum time up to which the application waits to "
              "receive replies to the topic query [default=0s]\n\n");
}

int main(int argc, char *argv[])
{
    int i = 0;
    CommandLineArguments_initialize(&cmd_arg);

    /* Parse the optional arguments */
     for (i = 1; i < argc; ++i) {
         if (!RTI_STRNCMP(argv[i], "-h", 2) ||
             !RTI_STRNCMP(argv[i], "--help", 6)) {
             HelloWorldTopicQuery_print_usage();
             return EXIT_SUCCESS;
         }
         if (!RTI_STRNCMP(argv[i], "-d", 2) ||
             !RTI_STRNCMP(argv[i], "--domain", 8)) {
             char *ptr;
             if (HelloWorldTopicQuery_ensure_one_more_argument(
                 argc, i, "-d") == EXIT_FAILURE) {
                 return EXIT_FAILURE;
             }
             cmd_arg.domain_id = strtol(argv[++i], &ptr, 10);
             if (*ptr != '\0') {
                 HelloWorldTopicQuery_print_usage();
                 printf("! Value of --domain argument is not a number: %s\n",
                     argv[i]);
                 return EXIT_FAILURE;
             }
             if (cmd_arg.domain_id < 0 || cmd_arg.domain_id > DOMAIN_ID_MAX) {
                 HelloWorldTopicQuery_print_usage();
                 printf("! Invalid DDS Domain ID: %d\n", cmd_arg.domain_id);

                 printf("! The domain ID must be between 0 and %d (inclusive)"
                     "\n",DOMAIN_ID_MAX);
                 return EXIT_FAILURE;
             }
             continue;
         }
         if (!RTI_STRNCMP(argv[i], "-c", 2)) {
             char *ptr;
             if (HelloWorldTopicQuery_ensure_one_more_argument(
                 argc, i, "-c") == EXIT_FAILURE) {
                 return EXIT_FAILURE;
             }
             cmd_arg.count = strtol(argv[++i], &ptr, 10);
             if (*ptr != '\0') {
                 HelloWorldTopicQuery_print_usage();
                 printf("! Value of -c argument is not a number: %s\n", argv[i]);
                 return EXIT_FAILURE;
             }
             if (cmd_arg.count <= 0) {
                 HelloWorldTopicQuery_print_usage();
                 printf("! Invalid value for count argument: %d\n",
                     cmd_arg.count);
                 return EXIT_FAILURE;
             }
             continue;
         }
         if (!RTI_STRNCMP(argv[i], "-i", 2)) {
             char *ptr;
             if (HelloWorldTopicQuery_ensure_one_more_argument(
                 argc, i, "-i") == EXIT_FAILURE) {
                 return EXIT_FAILURE;
             }
             cmd_arg.instance_id = strtol(argv[++i], &ptr, 10);
             if (*ptr != '\0') {
                 HelloWorldTopicQuery_print_usage();
                 printf("! Value of -i argument is not a number: %s\n",
                     argv[i]);
                 return EXIT_FAILURE;
             }
             if (cmd_arg.instance_id < 0) {
                 HelloWorldTopicQuery_print_usage();
                 printf("! Invalid value for instance_id argument: %d\n",
                     cmd_arg.instance_id);
                 return EXIT_FAILURE;
             }
             continue;
         }
         if (!RTI_STRNCMP(argv[i], "-t", 2)) {
             char *ptr;
             if (HelloWorldTopicQuery_ensure_one_more_argument(
                 argc, i, "-t") == EXIT_FAILURE) {
                 return EXIT_FAILURE;
             }
             cmd_arg.topic_query_wait_max = strtol(argv[++i], &ptr, 10);
             if (*ptr != '\0') {
                 HelloWorldTopicQuery_print_usage();
                 printf("! Value of -t argument is not a number: %s\n", argv[i]);
                 return EXIT_FAILURE;
             }
             if (cmd_arg.topic_query_wait_max < 0) {
                 HelloWorldTopicQuery_print_usage();
                 printf("! Invalid value for topic_query_wait_max "
                     "argument: %d\n", cmd_arg.topic_query_wait_max);
                 return EXIT_FAILURE;
             }
             continue;
         }
     }

    return HelloWorldTopicQuery_start_subscriber();
}

