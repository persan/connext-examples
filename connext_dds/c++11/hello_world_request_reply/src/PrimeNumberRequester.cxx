/****************************************************************************/
/*         (c) Copyright, Real-Time Innovations, All rights reserved.       */
/*                                                                          */
/*         Permission to modify and use for internal purposes granted.      */
/* This software is provided "as is", without warranty, express or implied. */
/*                                                                          */
/****************************************************************************/

#include "Primes.hpp" // generated support for the request and reply types
#include <rti/request/rtirequest.hpp> // full request-reply API
#include <rti/util/util.hpp> // for sleep()
#include <rti/config/Logger.hpp> // Logger to configure logging verbosity

class PrimeNumberRequesterExample {
private:
    dds::domain::DomainParticipant participant;

public:
    PrimeNumberRequesterExample(int domain_id)
        : participant(domain_id)
    {
    }

    void run_example(int n, int primes_per_reply)
    {
        // Create the requester with the participant, and a QoS profile
        // defined in USER_QOS_PROFILES.xml
        rti::request::RequesterParams requester_params(participant);
        auto qos_provider = dds::core::QosProvider::Default();
        requester_params.service_name("PrimeCalculator");
        requester_params.datawriter_qos(qos_provider.datawriter_qos(
                "RequestReplyExampleProfiles::RequesterExampleProfile"));
        requester_params.datareader_qos(qos_provider.datareader_qos(
                "RequestReplyExampleProfiles::RequesterExampleProfile"));

        rti::request::Requester<PrimeNumberRequest, PrimeNumberReply> requester(
            requester_params);

        while (rti::request::matched_replier_count(requester) == 0) {
            rti::util::sleep(dds::core::Duration::from_millisecs(100));
        }

        // Send the request
        auto request_id =
                requester.send_request(PrimeNumberRequest(n, primes_per_reply));

        // Receive replies
        const auto MAX_WAIT = dds::core::Duration::from_secs(20);

        bool in_progress = true;
        while(in_progress) {
            auto replies = requester.receive_replies(MAX_WAIT);

            // When receive_replies times out,
            // it returns an empty reply collection
            if (replies.length() == 0) {
                throw std::runtime_error("Timed out waiting for replies");
                return;
            }

            // Print the prime numbers we receive
            for (const auto& reply : replies) {
                if (!reply.info().valid()) {
                    continue;
                }

                for (auto prime : reply.data().primes()) {
                    std::cout << prime << " ";
                }

                if (reply.data().status() != PrimeNumberCalculationStatus::REPLY_IN_PROGRESS) {
                    in_progress = false;
                    if (reply.data().status() == PrimeNumberCalculationStatus::REPLY_ERROR) {
                        throw std::runtime_error("Error in replier");
                    } else { // reply->status == COMPLETED
                        std::cout << "DONE";
                    }
                }

                std::cout << std::endl;
            }
        }
    }

};

int requester_main(int n, int primes_per_reply, int domain_id)
{
    /* Uncomment this to turn on additional logging
        rti::config::Logger::instance().verbosity(
                rti::config::Verbosity::WARNING);
    */

    std::cout << "PrimeNumberRequester: Sending a request to calculate the "
              << "prime numbers <= " << n << " in sequences of "
              << primes_per_reply << " or less elements (on domain "
              << domain_id << ")" << std::endl;

    try {
        PrimeNumberRequesterExample(domain_id).run_example(n, primes_per_reply);
    } catch (const std::exception& ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
        return -1;
    }

    return 0;
}

#if !(defined(RTI_VXWORKS) && !defined(__RTP__)) && !defined(RTI_PSOS)
int main(int argc, char *argv[])
{
    int domain_id = 0;
    int n;
    int primes_per_reply = 5;

    if (argc < 2) {
        std::cout << "PrimeNumberRequester" << std::endl
                  << "Sends a request to calculate the prime numbers <= n"
                  << std::endl
                  << "Parameters: <n> [<primes_per_reply>=5] [<domain_id>=0]"
                  << std::endl;
        return -1;
    }

    n = atoi(argv[1]);

    if (argc > 2) {
        primes_per_reply = atoi(argv[2]);
    }

    if (argc > 3) {
        domain_id = atoi(argv[3]);
    }

    return requester_main(n, primes_per_reply, domain_id);
}
#endif

