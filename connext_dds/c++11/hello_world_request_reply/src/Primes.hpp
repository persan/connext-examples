

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Primes.idl
using RTI Code Generator (rtiddsgen) version 4.0.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef Primes_831781118_hpp
#define Primes_831781118_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/Optional.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/core/array.hpp"
#include "rti/core/BoundedSequence.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#include "rti/core/LongDouble.hpp"
#include "dds/core/External.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/topic/TopicTraits.hpp"

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

class NDDSUSERDllExport PrimeNumberRequest {
  public:
    PrimeNumberRequest();

    PrimeNumberRequest(int32_t n,int32_t primes_per_reply);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    PrimeNumberRequest (PrimeNumberRequest&&) = default;
    PrimeNumberRequest& operator=(PrimeNumberRequest&&) = default;
    PrimeNumberRequest& operator=(const PrimeNumberRequest&) = default;
    PrimeNumberRequest(const PrimeNumberRequest&) = default;
    #else
    PrimeNumberRequest(PrimeNumberRequest&& other_) OMG_NOEXCEPT;  
    PrimeNumberRequest& operator=(PrimeNumberRequest&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    int32_t& n() OMG_NOEXCEPT {
        return m_n_;
    }

    const int32_t& n() const OMG_NOEXCEPT {
        return m_n_;
    }

    void n(int32_t value) {
        m_n_ = value;
    }

    int32_t& primes_per_reply() OMG_NOEXCEPT {
        return m_primes_per_reply_;
    }

    const int32_t& primes_per_reply() const OMG_NOEXCEPT {
        return m_primes_per_reply_;
    }

    void primes_per_reply(int32_t value) {
        m_primes_per_reply_ = value;
    }

    bool operator == (const PrimeNumberRequest& other_) const;
    bool operator != (const PrimeNumberRequest& other_) const;

    void swap(PrimeNumberRequest& other_) OMG_NOEXCEPT ;

  private:

    int32_t m_n_;
    int32_t m_primes_per_reply_;

};

inline void swap(PrimeNumberRequest& a, PrimeNumberRequest& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const PrimeNumberRequest& sample);

static const int32_t PRIME_SEQUENCE_MAX_LENGTH = 1024L;
enum class PrimeNumberCalculationStatus {
    REPLY_IN_PROGRESS, 
    REPLY_COMPLETED, 
    REPLY_ERROR
};

NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const PrimeNumberCalculationStatus& sample);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
// On Windows, dll-export template instantiations of standard types used by
// other dll-exported types
template class NDDSUSERDllExport std::allocator< int32_t >;
template class NDDSUSERDllExport std::vector< int32_t >;
#endif
class NDDSUSERDllExport PrimeNumberReply {
  public:
    PrimeNumberReply();

    PrimeNumberReply(const ::rti::core::bounded_sequence< int32_t, (PRIME_SEQUENCE_MAX_LENGTH) >& primes,const PrimeNumberCalculationStatus& status);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    PrimeNumberReply (PrimeNumberReply&&) = default;
    PrimeNumberReply& operator=(PrimeNumberReply&&) = default;
    PrimeNumberReply& operator=(const PrimeNumberReply&) = default;
    PrimeNumberReply(const PrimeNumberReply&) = default;
    #else
    PrimeNumberReply(PrimeNumberReply&& other_) OMG_NOEXCEPT;  
    PrimeNumberReply& operator=(PrimeNumberReply&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    ::rti::core::bounded_sequence< int32_t, (PRIME_SEQUENCE_MAX_LENGTH) >& primes() OMG_NOEXCEPT {
        return m_primes_;
    }

    const ::rti::core::bounded_sequence< int32_t, (PRIME_SEQUENCE_MAX_LENGTH) >& primes() const OMG_NOEXCEPT {
        return m_primes_;
    }

    void primes(const ::rti::core::bounded_sequence< int32_t, (PRIME_SEQUENCE_MAX_LENGTH) >& value) {
        m_primes_ = value;
    }

    void primes(::rti::core::bounded_sequence< int32_t, (PRIME_SEQUENCE_MAX_LENGTH) >&& value) {
        m_primes_ = std::move(value);
    }
    PrimeNumberCalculationStatus& status() OMG_NOEXCEPT {
        return m_status_;
    }

    const PrimeNumberCalculationStatus& status() const OMG_NOEXCEPT {
        return m_status_;
    }

    void status(const PrimeNumberCalculationStatus& value) {
        m_status_ = value;
    }

    void status(PrimeNumberCalculationStatus&& value) {
        m_status_ = std::move(value);
    }

    bool operator == (const PrimeNumberReply& other_) const;
    bool operator != (const PrimeNumberReply& other_) const;

    void swap(PrimeNumberReply& other_) OMG_NOEXCEPT ;

  private:

    ::rti::core::bounded_sequence< int32_t, (PRIME_SEQUENCE_MAX_LENGTH) > m_primes_;
    PrimeNumberCalculationStatus m_status_;

};

inline void swap(PrimeNumberReply& a, PrimeNumberReply& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const PrimeNumberReply& sample);

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name< PrimeNumberRequest > {
            NDDSUSERDllExport static std::string value() {
                return "PrimeNumberRequest";
            }
        };

        template<>
        struct is_topic_type< PrimeNumberRequest > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< PrimeNumberRequest > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const PrimeNumberRequest& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(PrimeNumberRequest& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(PrimeNumberRequest& sample);

            NDDSUSERDllExport 
            static void allocate_sample(PrimeNumberRequest& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
        template<>
        struct topic_type_name< PrimeNumberReply > {
            NDDSUSERDllExport static std::string value() {
                return "PrimeNumberReply";
            }
        };

        template<>
        struct is_topic_type< PrimeNumberReply > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< PrimeNumberReply > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const PrimeNumberReply& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(PrimeNumberReply& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(PrimeNumberReply& sample);

            NDDSUSERDllExport 
            static void allocate_sample(PrimeNumberReply& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
    }
}

namespace rti { 
    namespace topic {
        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< PrimeNumberRequest > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< PrimeNumberRequest > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<PrimeNumberCalculationStatus>
        {
            static const PrimeNumberCalculationStatus value;
        };
        template<>
        struct dynamic_type< PrimeNumberCalculationStatus > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< PrimeNumberCalculationStatus > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< PrimeNumberReply > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< PrimeNumberReply > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;    };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // Primes_831781118_hpp

