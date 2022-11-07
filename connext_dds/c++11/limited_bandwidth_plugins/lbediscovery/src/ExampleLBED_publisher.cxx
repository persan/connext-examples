/**
 * @file ExampleLBED_publisher.cxx
 *
 * @brief Publication example of type ExampleLBED.
 * @details This file is a modified version of the code generated by the
 * rtiddsgen command:
 *
 *      > rtiddsgen -platform universal -create examplefiles \
 *              -language C++11 -exampleTemplate advanced ExampleLBED.idl
 *
 * @note Even though we generated this file using platform universal, we don't
 * support LBED for all of our platforms. We modified this file to remove
 * the platform-specific code for those architectures on which we don't
 * support the Limited Bandwidth Endpoint Discovery Plugin.
 * We also removed the generated DataWriter listener, as it was not used
 * in the example.
 * @see the README.txt file in the lbediscovery directory for further
 * information about how to compile and run this example.
 */

#include <iostream>

#include <dds/pub/ddspub.hpp>
#include <rti/util/util.hpp>      // for sleep()
#include <rti/config/Logger.hpp>  // for logging
#include "application.hpp"  // for command line parsing and ctrl-c
#include "ExampleLBED.hpp"

void run_publisher_application(unsigned int domain_id, unsigned int sample_count)
{
    // Start communicating in a domain, usually one participant per application
    // Load QoS profile from USER_QOS_PROFILES.xml file
    dds::domain::DomainParticipant participant(
        domain_id,
        dds::core::QosProvider::Default().participant_qos(
            "ExampleLBED_Library::ExampleLBED_Publisher_Profile"));

    // Create a Topic with a name and a datatype
    dds::topic::Topic<ExampleLBED> topic(
        participant,
        "Example ExampleLBED",
        dds::core::QosProvider::Default().topic_qos(
            "ExampleLBED_Library::ExampleLBED_Publisher_Profile"));

    // Create a Publisher
    dds::pub::Publisher publisher(
        participant,
        dds::core::QosProvider::Default().publisher_qos(
            "ExampleLBED_Library::ExampleLBED_Publisher_Profile"));

    // Create a DataWriter, loading QoS profile from USER_QOS_PROFILES.xml.
    dds::pub::DataWriter<ExampleLBED> writer(
        publisher,
        topic,
        dds::core::QosProvider::Default().datawriter_qos(
            "ExampleLBED_Library::ExampleLBED_Publisher_Profile"));

    ExampleLBED data;
    for (unsigned int samples_written = 0;
    !application::shutdown_requested && samples_written < sample_count;
    samples_written++) {
        // Modify the data to be written here
        data.data(static_cast<int32_t>(samples_written));

        std::cout << "Writing ExampleLBED, count " << samples_written << std::endl;

        writer.write(data);

        // Send every 1 second
        rti::util::sleep(dds::core::Duration(1));
    }
}

int main(int argc, char *argv[])
{

    using namespace application;

    // Parse arguments and handle control-C
    auto arguments = parse_arguments(argc, argv);
    if (arguments.parse_result == ParseReturn::exit) {
        return EXIT_SUCCESS;
    } else if (arguments.parse_result == ParseReturn::failure) {
        return EXIT_FAILURE;
    }
    setup_signal_handlers();

    // Sets Connext verbosity to help debugging
    rti::config::Logger::instance().verbosity(arguments.verbosity);

    try {
        run_publisher_application(arguments.domain_id, arguments.sample_count);
    } catch (const std::exception& ex) {
        // This will catch DDS exceptions
        std::cerr << "Exception in run_publisher_application(): " << ex.what()
        << std::endl;
        return EXIT_FAILURE;
    }

    // Releases the memory used by the participant factory.  Optional at
    // application exit
    dds::domain::DomainParticipant::finalize_participant_factory();

    return EXIT_SUCCESS;
}
