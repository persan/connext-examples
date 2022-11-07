/****************************************************************************/
/*         (c) Copyright, Real-Time Innovations, All rights reserved.       */
/*                                                                          */
/*         Permission to modify and use for internal purposes granted.      */
/* This software is provided "as is", without warranty, express or implied. */
/*                                                                          */
/****************************************************************************/

#include "Primes.hpp" // generated support for the request and reply types
#include <rti/request/rtirequest.hpp> // full request-reply API
#include <rti/config/Logger.hpp> // Logger to configure logging verbosity
#include <cmath>

class PrimeNumberReplierExample {

private:
    dds::domain::DomainParticipant participant;

public:
    PrimeNumberReplierExample(int domain_id)
        : participant(domain_id)
    {
    }

private:

    void calculate_and_send_primes(
            rti::request::Replier<PrimeNumberRequest, PrimeNumberReply> replier,
            const rti::sub::LoanedSample<PrimeNumberRequest>& request)
    {
        int n = request.data().n();
        size_t primes_per_reply = static_cast<size_t>(
                request.data().primes_per_reply());

        PrimeNumberReply reply;
        reply.primes().reserve(primes_per_reply);
        reply.status() = PrimeNumberCalculationStatus::REPLY_IN_PROGRESS;

        // prime[i] indicates if i is a prime number
        // Initially, we assume all of them are prime
        std::vector<bool> prime(n+1, true);

        prime[0] = false;
        prime[1] = false;

        int m = (int) std::sqrt((float)n);

        for (int i = 2; i <= m; i++) {
            if (prime[i]) {
                for (int k = i*i; k <= n; k+=i) {
                    prime[k] = false;
                }

                // Add a new element
                reply.primes().push_back(i);

                if (reply.primes().size() == primes_per_reply) {
                    // Send a reply now
                    replier.send_reply(reply, request.info());
                    reply.primes().clear();
                }
            }
        }

        // Calculation is done. Send remaining prime numbers
        for (int i = m + 1; i <= n; i++) {
            if (prime[i]) {
                reply.primes().push_back(i);

                if (reply.primes().size() == primes_per_reply) {
                    // Send a reply now
                    replier.send_reply(reply, request.info());
                    reply.primes().clear();
                }
            }
        }

        // Send the last reply. Indicate that the calculation is complete and
        // send any prime number left in the sequence
        reply.status() = PrimeNumberCalculationStatus::REPLY_COMPLETED;
        replier.send_reply(reply, request.info());
    }

public:
    void run_example()
    {

        rti::request::ReplierParams replier_params(participant);

        auto qos_provider = dds::core::QosProvider::Default();
        replier_params.service_name("PrimeCalculator");
        replier_params.datawriter_qos(qos_provider.datawriter_qos(
                "RequestReplyExampleProfiles::ReplierExampleProfile"));
        replier_params.datareader_qos(qos_provider.datareader_qos(
                "RequestReplyExampleProfiles::ReplierExampleProfile"));

        rti::request::Replier<PrimeNumberRequest, PrimeNumberReply> replier(
                replier_params);

        // Receive requests and process them
        const auto MAX_WAIT = dds::core::Duration::from_secs(20);
        auto requests = replier.receive_requests(MAX_WAIT);
        while (requests.length() > 0) { // end the requester when no requests received in MAX_WAIT
            for (const auto& request : requests) {
                if (!request.info().valid()) {
                    continue;
                }

                // This constant is defined in Primes.idl
                if (request.data().n() <= 0 ||
                    request.data().primes_per_reply() <= 0 ||
                    request.data().primes_per_reply() > PRIME_SEQUENCE_MAX_LENGTH) {

                    std::cout << "Cannot process request" << std::endl;

                    // Send reply indicating error
                    PrimeNumberReply error_reply;
                    error_reply.status() = PrimeNumberCalculationStatus::REPLY_ERROR;
                    replier.send_reply(error_reply, request.info());

                } else {
                    std::cout << "Calculating prime numbers below "
                              << request.data().n() << "... " << std::endl;

                    calculate_and_send_primes(replier, request);

                    std::cout << "DONE" << std::endl;
                }
            }

            requests = replier.receive_requests(MAX_WAIT);
        }
    }
};

int replier_main(int domain_id)
{
    /* Uncomment this to turn on additional logging
        rti::config::Logger::instance().verbosity(
                rti::config::Verbosity::WARNING);
    */

    std::cout << "PrimeNumberReplier running (on domain " << domain_id << ")"
              << std::endl;

    try {
        PrimeNumberReplierExample(domain_id).run_example();
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

    if (argc > 1) {
        domain_id = atoi(argv[1]);
    }
    return replier_main(domain_id);

}
#endif

