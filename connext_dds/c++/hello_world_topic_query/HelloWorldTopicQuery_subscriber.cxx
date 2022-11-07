#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>

#include "HelloWorldTopicQuery.h"
#include "HelloWorldTopicQuerySupport.h"
#include "ndds/ndds_cpp.h"
#include "HelloWorldTopicQueryUtils.h"
#include "ndds/ndds_namespace_cpp.h"

using namespace DDS;

/*
 * Class to hold the parsed command line arguments
 */
class CommandLineArguments {
public:
    int    domainId;
    int    count;
    int    instance_id;
    int    topic_query_wait_max;

    CommandLineArguments() {
        domainId  = DEFAULT_DOMAIN_ID;
        count  = -1;
        instance_id = -1;
        topic_query_wait_max = 0;
    }
};


class HelloWorldTopicQuerySubscriber
{
public:
    static const DDS_Duration_t READ_PERIOD;

    HelloWorldTopicQuerySubscriber(CommandLineArguments &arg);
    ~HelloWorldTopicQuerySubscriber();
    void run();

private:
    CommandLineArguments arg;
    DDSDomainParticipant *participant;
    DDSDataReader *reader;
    DDSReadCondition *topic_query_read_condition;
    DDSReadCondition *live_stream_read_condition;
    int sample_count;
    DDS_Boolean is_topic_query_last_sample;
    DDSWaitSet wait_set;

    int subscriber_shutdown();
    int process_samples(DDSReadCondition *);
    void wait_for_samples(DDS_Duration_t wait_max);
    void wait_for_samples(int samples);
    static void print_received_sample(
        HelloWorldTopicQuery *sample, DDS_SampleInfo *info);
    static Duration_t duration(int, unsigned int);

};

const DDS_Duration_t HelloWorldTopicQuerySubscriber::READ_PERIOD =
    DDS_Duration_t::from_seconds(2);


HelloWorldTopicQuerySubscriber::HelloWorldTopicQuerySubscriber(
    CommandLineArguments &cmd_arg) : arg(cmd_arg), participant(NULL),
    reader(NULL), topic_query_read_condition(NULL),
    live_stream_read_condition(NULL), sample_count(0),
        is_topic_query_last_sample(false)
{
    /* To customize the participant QoS, use the configuration file
     * USER_QOS_PROFILES.xml */
    participant = DDSTheParticipantFactory->create_participant_with_profile(
        arg.domainId, "HelloWorldTopicQuery_Library",
        "HelloWorldTopicQuery_Profile", NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        throw std::runtime_error("create_participant_with_profile");
    }

    /* Register the type before creating the topic */
    const char *type_name = HelloWorldTopicQueryTypeSupport::get_type_name();
    DDS_ReturnCode_t retcode = HelloWorldTopicQueryTypeSupport::register_type(
        participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        std::stringstream ss;
        ss << retcode;
        throw std::runtime_error("register_type error " + ss.str());
    }

    /* To customize the topic QoS, use
    the configuration file USER_QOS_PROFILES.xml */
    DDSTopicDescription *topic_description =
        (DDSTopicDescription *)participant->create_topic(
        "Example HelloWorldTopicQuery",
        type_name, DDS_TOPIC_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic_description == NULL) {
        throw std::runtime_error("create_topic");
    }

    /* Set up the content filter and DataReader. To customize the DataReader
     * QoS, use the configuration file USER_QOS_PROFILES.xml. DataReader
     * resource limits related to TopicQueries is added in the
     * configuration file */
    if (arg.instance_id >= 0) {
        char cft_string[15];
        RTI_SNPRINTF(cft_string, 15, "id=%d", arg.instance_id);
        topic_description =
            (DDSTopicDescription *)participant->create_contentfilteredtopic(
            "HelloWorldTopicQuerySubscriber_cft", (DDSTopic *)topic_description,
            cft_string, DDS_StringSeq(0));

        if (topic_description == NULL) {
            throw std::runtime_error("create_contentfilteredtopic");
        }
    }

    reader = participant->create_datareader_with_profile(
            topic_description, "HelloWorldTopicQuery_Library",
            "HelloWorldTopicQuery_Profile", NULL,
            DDS_STATUS_MASK_ALL);
    if (reader == NULL) {
        throw std::runtime_error("create_datareader_with_profile");
    }

    /* Set up Read Conditions */
    DDS_ReadConditionParams read_condition_params =
        DDS_READCONDITIONPARAMS_DEFAULT;

    /* Read Condition exclusively for Topic Query stream */
    read_condition_params.stream_kinds = DDS_TOPIC_QUERY_STREAM;
    topic_query_read_condition = reader->create_readcondition_w_params(
        read_condition_params);
    if (topic_query_read_condition == NULL) {
        throw std::runtime_error("create_readcondition_w_params "
            "topic_query_read_condition");
    }

    /* Read Condition for Live stream */
    read_condition_params.stream_kinds = DDS_LIVE_STREAM;
    live_stream_read_condition = reader->create_readcondition_w_params(
        read_condition_params);
    if (live_stream_read_condition == NULL) {
        throw std::runtime_error("create_readcondition_w_params "
            "live_stream_read_condition");
    }
}


/*
 * Delete all entities
 */
int HelloWorldTopicQuerySubscriber::subscriber_shutdown()
{
    DDS_ReturnCode_t retcode;
    int status = 0;

    if (participant != NULL) {
        retcode = participant->delete_contained_entities();
        if (retcode != DDS_RETCODE_OK) {
            std::cout << "delete_contained_entities error " << retcode
                << std::endl;
            status = -1;
        }

        retcode = DDSTheParticipantFactory->delete_participant(participant);
        if (retcode != DDS_RETCODE_OK) {
            std::cout << "delete_participant error " << retcode << std::endl;
            status = -1;
        }
    }

    /* RTI Connext provides the finalize_instance() method on
    domain participant factory for people who want to release memory used
    by the participant factory. Uncomment the following block of code for
    clean destruction of the singleton. */
    /*

    retcode = DDSDomainParticipantFactory::finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        std::cout << "finalize_instance error " << retcode << std::endl;
        status = -1;
    }
    */
    return status;
}

HelloWorldTopicQuerySubscriber::~HelloWorldTopicQuerySubscriber()
{
    std::cout << "Shutting down..." << std::endl;
    subscriber_shutdown();
    std::cout << "Done" << std::endl;
}

Duration_t HelloWorldTopicQuerySubscriber::duration(
    int sec, unsigned int nanosec)
{
    DDS_Duration_t duration = {sec, nanosec};
    return duration;
}

void HelloWorldTopicQuerySubscriber::print_received_sample(
    HelloWorldTopicQuery *sample, DDS_SampleInfo *info)
{
     if(!DDS_GUID_equals(&info->topic_query_guid, &DDS_GUID_UNKNOWN)) {
        std::cout << "Received TopicQuery sample with GUID ";
        for (int i = 0; i < 16; i++) {
             std::cout << std::setfill('0') << std::setw(2) << std::hex
                 << (int)info->topic_query_guid.value[i];
        }
    } else {
        std::cout << "Received live sample";
    }
    std::cout << ":";
    HelloWorldTopicQueryTypeSupport::print_data(sample);
    std::cout << std::endl;
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
int HelloWorldTopicQuerySubscriber::process_samples(
    DDSReadCondition *read_condition)
{
    DDS_ReturnCode_t retcode;

    HelloWorldTopicQueryDataReader *helloWorldReader =
        (HelloWorldTopicQueryDataReader *)reader;
    if (helloWorldReader == NULL) {
        std::cout << "DataReader narrow error" << std::endl;
        return -1;
    }

    HelloWorldTopicQuerySeq data_seq;
    DDS_SampleInfoSeq info_seq;
    retcode = helloWorldReader->take_w_condition(
        data_seq, info_seq, DDS_LENGTH_UNLIMITED, read_condition);

    if (retcode == DDS_RETCODE_NO_DATA) {
        return -1;
    } else if (retcode != DDS_RETCODE_OK) {
        std::cout << "take error " << retcode << std::endl;
        return -1;
    }

    HelloWorldTopicQuery data;
    DDS_SampleInfo info;

    for (int i = 0; i < data_seq.length(); ++i) {
        if (info_seq[i].valid_data) {

            data = data_seq.get_at(i);
            info = info_seq.get_at(i);
            HelloWorldTopicQuerySubscriber::print_received_sample(
                &data, &info);
            sample_count++;

            if (!DDS_GUID_equals(&info.topic_query_guid, &DDS_GUID_UNKNOWN)) {
                /*
                 * If we are processing samples for a TopicQuery, we may
                 * indicate that no more samples are expected if the
                 * corresponding flag is present. Note that such flag will be
                 * set by each DataWriter that accepts the TopicQuery. This
                 * example assumes that an instance is published by only one
                 * DataWriter.
                 */
                is_topic_query_last_sample = !(info_seq[i].flag &
                    DDS_INTERMEDIATE_TOPIC_QUERY_SAMPLE);
                if (is_topic_query_last_sample && arg.instance_id >= 0) {
                    break;
                }
            }
        }
    }

    retcode = helloWorldReader->return_loan(data_seq, info_seq);
    if (retcode != DDS_RETCODE_OK) {
        std::cout << "return loan error " << retcode << std::endl;
    }
    return 0;
}

/*
 * Waits and processes samples for a specified wait_time.
 */
void HelloWorldTopicQuerySubscriber::wait_for_samples(DDS_Duration_t wait_time)
{
    DDSConditionSeq active_conditions;
    DDS_ReturnCode_t retcode;
    DDS_Time_t time_1, time_2;

    while (wait_time.sec > 0) {
        retcode = participant->get_current_time(time_1);
        if (retcode != DDS_RETCODE_OK) {
            std::stringstream ss;
            ss << retcode;
            throw std::runtime_error("get_current_time error " + ss.str());
        }
        wait_set.wait(active_conditions, wait_time);
        for (int i = 0; i < active_conditions.length(); i++) {
            if (process_samples(
                (DDSReadCondition *) (active_conditions.get_at(i))) == -1) {
                return;
            }
            if (is_topic_query_last_sample) {
                return;
            }
        }
        retcode = participant->get_current_time(time_2);
        if (retcode != DDS_RETCODE_OK) {
            std::stringstream ss;
            ss << retcode;
            throw std::runtime_error("get_current_time error " + ss.str());
        }
        /*Update wait_time by deducting spent time*/
        wait_time = wait_time - (duration(time_2.sec, time_2.nanosec)
            - duration(time_1.sec, time_1.nanosec));
   }
}

/*
 * Waits until the specified number of samples have been received and
 * processed.
 */
void HelloWorldTopicQuerySubscriber::wait_for_samples(int max_sample_count)
{
    DDSConditionSeq active_conditions;
    while (max_sample_count < 0 || sample_count < max_sample_count) {
        wait_set.wait(active_conditions, READ_PERIOD);
        for (int i = 0; i < active_conditions.length(); i++) {
            if (process_samples(
                (DDSReadCondition *)(active_conditions.get_at(i))) == -1) {
                return;
            }
        }
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
void HelloWorldTopicQuerySubscriber::run()
{
    DDSTopicQuery *topic_query = NULL;
    DDS_ReturnCode_t retcode;

    /* Create a TopicQuery to receive the samples published before the
    * creation of this reader.*/
    if (arg.instance_id < 0) {
        topic_query = reader->create_topic_query(
                TOPIC_QUERY_SELECTION_SELECT_ALL);
    } else {
        topic_query = reader->create_topic_query(
                TOPIC_QUERY_SELECTION_USE_READER_CONTENT_FILTER);
    }
    if (topic_query == NULL) {
        throw std::runtime_error("create_topic_query");
    }

    /* Read first TopicQuery samples. */
    retcode = wait_set.attach_condition(topic_query_read_condition);
    if(retcode != DDS_RETCODE_OK) {
        std::stringstream ss;
        ss << retcode;
        throw std::runtime_error("attach_condition topic_query_read_condition "
            "error " + ss.str());
    }

    std::cout << "HelloWorldTopicQuerySubscriber waiting for the first sample"
            << std::endl;
    wait_for_samples(DDS_Duration_t::from_seconds(arg.topic_query_wait_max));

    /* Read both live and topic query samples. */
    retcode = wait_set.attach_condition(live_stream_read_condition);
    if(retcode != DDS_RETCODE_OK) {
        std::stringstream ss;
        ss << retcode;
        throw std::runtime_error("attach_condition live_stream_read_condition "
            "error " + ss.str());

    }
    wait_for_samples(arg.count);
}

/*
 * Prints help on command line accepted by this application
 */
void HelloWorldTopicQuery_print_usage() {
    std::cout << "Usage: HelloWorldTopicQuerySubscriber [options]" << std::endl;

    std::cout << "Where arguments are:" << std::endl;
    std::cout << "  -h | --help                 "
              << "Shows this page" << std::endl;
    std::cout << "  -d | --domain <domainID>    "
              << "Sets the DDS domain ID [default=0]" << std::endl;
    std::cout << "  -c <count>                  "
              << "Sets the number of samples to receive "
              <<"[default=-1 (infinite)]"
              << std::endl;
    std::cout << "  -i <instance_id>            "
              << "Sets the requested instance_id [default=-1 (all)]"
              << std::endl;
    std::cout << "  -t <topic_query_wait_max>   "
              << "Sets the maximum time up to which the application waits to "
              << "receive replies to the topic query [default=0s]"
              << std::endl;
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    CommandLineArguments arg;
    int i = 0;

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
            HelloWorldTopicQuery_ensure_one_more_argument(
                argc, i, "-d");
            arg.domainId = strtol(argv[++i], &ptr, 10);
            if (*ptr != '\0') {
                HelloWorldTopicQuery_print_usage();
                std::cerr << "! Value of --domain argument is not a number: "
                    << argv[i] << std::endl;
                return EXIT_FAILURE;
            }
            if (arg.domainId < 0 || arg.domainId > DOMAIN_ID_MAX) {
                HelloWorldTopicQuery_print_usage();
                std::cerr << "! Invalid DDS Domain ID: " << arg.domainId
                    << std::endl;
                std::cerr << "! The domain ID must be between 0 and "
                    << DOMAIN_ID_MAX << " (inclusive)" << std::endl;
                return EXIT_FAILURE;
            }
            continue;
        }
        if (!RTI_STRNCMP(argv[i], "-c", 2)) {
            char *ptr;
            HelloWorldTopicQuery_ensure_one_more_argument(
                argc, i, "-c");
            arg.count = strtol(argv[++i], &ptr, 10);
            if (*ptr != '\0') {
                HelloWorldTopicQuery_print_usage();
                std::cerr << "! Value of -c argument is not a number:"
                    << argv[i] << std::endl;
                return EXIT_FAILURE;
            }
            if (arg.count <= 0) {
                HelloWorldTopicQuery_print_usage();
                std::cerr << "! Invalid value for count argument: "
                    << arg.count << std::endl;
                return EXIT_FAILURE;
            }
            continue;
        }
        if (!RTI_STRNCMP(argv[i], "-i", 2)) {
            char *ptr;
            HelloWorldTopicQuery_ensure_one_more_argument(argc, i, "-i");
            arg.instance_id = strtol(argv[++i], &ptr, 10);
            if (*ptr != '\0') {
                HelloWorldTopicQuery_print_usage();
                std::cerr << "! Value of -i argument is not a number:"
                    << argv[i] << std::endl;
                return EXIT_FAILURE;
            }
            if (arg.instance_id < 0) {
                HelloWorldTopicQuery_print_usage();
                std::cerr << "! Invalid value for instance_id argument:"
                    << arg.instance_id << std::endl;
                return EXIT_FAILURE;
            }
            continue;
        }
        if (!RTI_STRNCMP(argv[i], "-t", 2)) {
            char *ptr;
            HelloWorldTopicQuery_ensure_one_more_argument(
                argc, i, "-t");
            arg.topic_query_wait_max = strtol(argv[++i], &ptr, 10);
            if (*ptr != '\0') {
                HelloWorldTopicQuery_print_usage();
                std::cerr << "! Value of -t argument is not a number "
                    <<"argument: "<< argv[i] << std::endl;
                return EXIT_FAILURE;
            }
            if (arg.topic_query_wait_max < 0) {
                HelloWorldTopicQuery_print_usage();
                std::cerr << "! Invalid value for topic_query_wait_max "
                    <<"argument: "<< arg.topic_query_wait_max << std::endl;
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

    try {
        HelloWorldTopicQuerySubscriber helloWorldTopicQuerySubscriber(arg);
        helloWorldTopicQuerySubscriber.run();
    } catch (const std::exception& e) {
        std::cerr << "exception caught: " << e.what() << std::endl;
    }
    return 0;
}

