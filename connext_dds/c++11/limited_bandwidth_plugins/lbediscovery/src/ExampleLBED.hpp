

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ExampleLBED.idl
using RTI Code Generator (rtiddsgen) version 4.0.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef ExampleLBED_1681160520_hpp
#define ExampleLBED_1681160520_hpp

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

class NDDSUSERDllExport ExampleLBED {
  public:
    ExampleLBED();

    explicit ExampleLBED(int32_t data);

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    ExampleLBED (ExampleLBED&&) = default;
    ExampleLBED& operator=(ExampleLBED&&) = default;
    ExampleLBED& operator=(const ExampleLBED&) = default;
    ExampleLBED(const ExampleLBED&) = default;
    #else
    ExampleLBED(ExampleLBED&& other_) OMG_NOEXCEPT;  
    ExampleLBED& operator=(ExampleLBED&&  other_) OMG_NOEXCEPT;
    #endif
    #endif 

    int32_t& data() OMG_NOEXCEPT {
        return m_data_;
    }

    const int32_t& data() const OMG_NOEXCEPT {
        return m_data_;
    }

    void data(int32_t value) {
        m_data_ = value;
    }

    bool operator == (const ExampleLBED& other_) const;
    bool operator != (const ExampleLBED& other_) const;

    void swap(ExampleLBED& other_) OMG_NOEXCEPT ;

  private:

    int32_t m_data_;

};

inline void swap(ExampleLBED& a, ExampleLBED& b)  OMG_NOEXCEPT 
{
    a.swap(b);
}

NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ExampleLBED& sample);

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name< ExampleLBED > {
            NDDSUSERDllExport static std::string value() {
                return "ExampleLBED";
            }
        };

        template<>
        struct is_topic_type< ExampleLBED > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< ExampleLBED > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const ExampleLBED& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(ExampleLBED& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(ExampleLBED& sample);

            NDDSUSERDllExport 
            static void allocate_sample(ExampleLBED& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };
    }
}

namespace rti { 
    namespace topic {
        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< ExampleLBED > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< ExampleLBED > {
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

#endif // ExampleLBED_1681160520_hpp

