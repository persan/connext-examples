#include <iostream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <stdlib.h>

#include "HelloWorldTopicQuery.h"
#include "HelloWorldTopicQuerySupport.h"
#include "HelloWorldTopicQueryUtils.h"
#include "ndds/ndds_cpp.h"

/*
 * Class to hold the parsed command line arguments
 */
class CommandLineArguments {
public:
    int    domainId;
    int    count;
    int    lower_instance_id;
    int    upper_instance_id;
    int    write_period;
    int    burst_size;

    CommandLineArguments() {
        domainId  = DEFAULT_DOMAIN_ID;
        count  = -1;
        lower_instance_id = 0;
        upper_instance_id = -1;
        write_period = 4;
        burst_size = 0;
    }
};

class HelloWorldTopicQueryPublisher
{

public:
    HelloWorldTopicQueryPublisher(CommandLineArguments &arg);
    ~HelloWorldTopicQueryPublisher();
    void run();

private:
    CommandLineArguments arg;
    DDSDomainParticipant *participant;
    DDSDataWriter *writer;

    int publisher_shutdown();
};

HelloWorldTopicQueryPublisher::HelloWorldTopicQueryPublisher(
    CommandLineArguments &cmd_arg) : arg(cmd_arg), participant(NULL),
    writer(NULL)
{
    /* To customize participant QoS, use 
    the configuration file USER_QOS_PROFILES.xml */
    participant = DDSTheParticipantFactory->create_participant_with_profile(
        arg.domainId, "HelloWorldTopicQuery_Library",
        "HelloWorldTopicQuery_Profile", NULL /* listener */,
        DDS_STATUS_MASK_NONE);

    if (participant == NULL) {
        throw std::runtime_error("create_participant_with_profile");
    }

    /* Register type before creating topic */
    const char *type_name = HelloWorldTopicQueryTypeSupport::get_type_name();
    DDS_ReturnCode_t retcode = HelloWorldTopicQueryTypeSupport::register_type(
        participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        std::stringstream ss;
        ss << retcode;
        throw std::runtime_error("register_type error " + ss.str());
    }

    /* To customize topic QoS, use 
    the configuration file USER_QOS_PROFILES.xml */
    DDSTopic *topic = participant->create_topic(
        "Example HelloWorldTopicQuery",
        type_name, DDS_TOPIC_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        throw std::runtime_error("create_topic");
    }

    /* To customize data writer QoS, use 
    the configuration file USER_QOS_PROFILES.xml. QoS configuration to enable
    TopicQueries is added in the configuration file. */
    writer = participant->create_datawriter_with_profile(
        topic, "HelloWorldTopicQuery_Library","HelloWorldTopicQuery_Profile",
        NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (writer == NULL) {
        throw std::runtime_error("create_datawriter_with_profile");
    }
}

/*
 * Delete all entities
 */
int HelloWorldTopicQueryPublisher::publisher_shutdown()
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
            std::cout << "delete_participant error " << retcode
                << std::endl;
            status = -1;
        }
    }

    /* RTI Connext provides finalize_instance() method on
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



HelloWorldTopicQueryPublisher::~HelloWorldTopicQueryPublisher()
{
    std::cout << "Shutting down..." << std::endl;
    publisher_shutdown();
    std::cout << "Done" << std::endl;
}

/*
 * Writing logic of the application.
 *
 * There are two write phases:
 * - A single initial burst of burst_size samples.
 * - A periodic phase that writes up to the specified count samples every
 *  write_period.
 */
void HelloWorldTopicQueryPublisher::run()
{
    HelloWorldTopicQueryDataWriter *  HelloWorldTopicQuery_writer
        = HelloWorldTopicQueryDataWriter::narrow(writer);
    if (HelloWorldTopicQuery_writer == NULL) {
        throw std::runtime_error("HelloWorldTopicQueryDataWriter::narrow");
    }

    /* Create data sample for writing */
    HelloWorldTopicQuery *instance = HelloWorldTopicQueryTypeSupport::
        create_data();
    if (instance == NULL) {
        throw std::runtime_error("create_data");
    }

    DDS_Duration_t send_period = DDS_Duration_t::from_seconds(arg.write_period);
    DDS_InstanceHandle_t instance_handle = DDS_HANDLE_NIL;
    DDS_ReturnCode_t retcode;

    /* For a data type that has a key, if the same instance is going to be
    written multiple times, initialize the key here
    and register the keyed instance prior to writing */
    /*
    instance_handle = HelloWorldTopicQuery_writer->register_instance(*instance);
    */

    /* Main loop */

    for (int count=0; (arg.count < 0) || (count < arg.count); ++count) {

        std::cout << "Writing HelloWorldTopicQuery, count " << count
            << std::endl;

        /* Modify the data to be sent here */
        if (arg.lower_instance_id >= 0) {
            instance->id = arg.upper_instance_id < 0
                ? count % (arg.lower_instance_id + 1)
                : count % (arg.upper_instance_id - arg.lower_instance_id);
        } else {
            instance->id = count;
        }
        RTI_SNPRINTF(instance->message, 20, "count: %d", count);
        retcode = HelloWorldTopicQuery_writer->write(
            *instance, instance_handle);
        if (retcode != DDS_RETCODE_OK) {
            std::cout<< "write error " << retcode << std::endl;
        }
        if (count >= arg.burst_size) {
            NDDSUtility::sleep(send_period);
        }
    }

    /*
    retcode = HelloWorldTopicQuery_writer->unregister_instance(
        *instance, instance_handle);
    if (retcode != DDS_RETCODE_OK) {
        std::cout << "unregister instance error " << retcode << std::endl;
    }
    */

    /* Delete data sample */
    retcode = HelloWorldTopicQueryTypeSupport::delete_data(instance);
    if (retcode != DDS_RETCODE_OK) {
        std::stringstream ss;
        ss << retcode;
        throw std::runtime_error("delete_data error " + ss.str());
    }

}

/*
 * Prints help on command line accepted by this application
 */
void HelloWorldTopicQuery_print_usage() {
    std::cout << "Usage: HelloWorldTopicQueryPublisher [options]" << std::endl;

    std::cout << "Where arguments are:" << std::endl;
    std::cout << "  -h | --help                 "
              << "Shows this page" << std::endl;
    std::cout << "  -d | --domain <domainID>    "
              << "Sets the DDS domain ID [default=0]" << std::endl;

    std::cout << "  -c <count>                  "
              << "Sets the number of samples to write [default=-1 (infinite)]"
              << std::endl;
    std::cout << "  -l <lower_instance_id>      "
              << "Sets the lower_instance_id [default=0]"<< std::endl;
    std::cout << "  -u <upper_instance_id>      "
              << "Sets the upper_instance_id [default=-1 (no upper limit)]"
              << std::endl;
    std::cout << "  -p <write_period>           "
              << "Sets the periodic rate at which the samples are "
              << "published [default=4s]"
              << std::endl;
    std::cout << "  -b <burst_size>             "
              << "Sets the initial number of samples published [default=0]"
              << std::endl;

    std::cout << std::endl;
}



int main(int argc, char *argv[])
{
    CommandLineArguments arg;

    /* Parse the optional arguments */
    for (int i = 1; i < argc; ++i) {
        if (!RTI_STRNCMP(argv[i], "-h", 2) ||
            !RTI_STRNCMP(argv[i], "--help", 6)) {
            HelloWorldTopicQuery_print_usage();
            return EXIT_SUCCESS;
        }
        if (!RTI_STRNCMP(argv[i], "-d", 2) ||
            !RTI_STRNCMP(argv[i], "--domain", 8)) {
            char *ptr;
            HelloWorldTopicQuery_ensure_one_more_argument(argc, i, "-d");
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
            HelloWorldTopicQuery_ensure_one_more_argument(argc, i, "-c");
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
        if (!RTI_STRNCMP(argv[i], "-l", 2)) {
            char *ptr;
            HelloWorldTopicQuery_ensure_one_more_argument(argc, i, "-l");
            arg.lower_instance_id = strtol(argv[++i], &ptr, 10);
            if (*ptr != '\0') {
                HelloWorldTopicQuery_print_usage();
                std::cerr << "! Value of -l argument is not a number:"
                          << argv[i] << std::endl;
                return EXIT_FAILURE;
            }
            if (arg.lower_instance_id < 0) {
                HelloWorldTopicQuery_print_usage();
                std::cerr << "! Invalid value for lower_instance_id argument: "
                          << arg.lower_instance_id << std::endl;
                return EXIT_FAILURE;
            }
            continue;
        }
        if (!RTI_STRNCMP(argv[i], "-u", 2)) {
            char *ptr;
            HelloWorldTopicQuery_ensure_one_more_argument(argc, i, "-u");
            arg.upper_instance_id = strtol(argv[++i], &ptr, 10);
            if (*ptr != '\0') {
                HelloWorldTopicQuery_print_usage();
                std::cerr << "! Value of -u argument is not a number:"
                          << argv[i] << std::endl;
                return EXIT_FAILURE;
            }
            if (arg.upper_instance_id < 0) {
                HelloWorldTopicQuery_print_usage();
                std::cerr << "! Invalid value for upper_instance_id argument: "
                          << arg.upper_instance_id << std::endl;
                return EXIT_FAILURE;
            }
            continue;
        }
        if (!RTI_STRNCMP(argv[i], "-p", 2)) {
            char *ptr;
            HelloWorldTopicQuery_ensure_one_more_argument(argc, i, "-p");
            arg.write_period = strtol(argv[++i], &ptr, 10);
            if (*ptr != '\0') {
                HelloWorldTopicQuery_print_usage();
                std::cerr << "! Value of -p argument is not a number:"
                          << argv[i] << std::endl;
                return EXIT_FAILURE;
            }
            if (arg.write_period < 0) {
                HelloWorldTopicQuery_print_usage();
                std::cerr << "! Invalid value for write_period argument: "
                          << arg.write_period << std::endl;
                return EXIT_FAILURE;
            }
            continue;
        }
        if (!RTI_STRNCMP(argv[i], "-b", 2)) {
            char *ptr;
            HelloWorldTopicQuery_ensure_one_more_argument(argc, i, "-b");
            arg.burst_size = strtol(argv[++i], &ptr, 10);
            if (*ptr != '\0') {
                HelloWorldTopicQuery_print_usage();
                std::cerr << "! Value of -b argument is not a number:"
                          << argv[i] << std::endl;
                return EXIT_FAILURE;
            }
            if (arg.burst_size < 0) {
                HelloWorldTopicQuery_print_usage();
                std::cerr << "! Invalid value for burst_size argument: "
                          << arg.burst_size << std::endl;
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
        HelloWorldTopicQueryPublisher helloWorldTopicQueryPublisher(arg);
        helloWorldTopicQueryPublisher.run();
    } catch (const std::exception& e) {
        std::cerr << "exception caught: " << e.what() << std::endl;
    }

    return 0;
}

