

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Primes.idl
using RTI Code Generator (rtiddsgen) version 4.0.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "Primes.hpp"
#include "PrimesPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

// ---- PrimeNumberRequest: 

PrimeNumberRequest::PrimeNumberRequest() :
    m_n_ (0) ,
    m_primes_per_reply_ (0)  {
}   

PrimeNumberRequest::PrimeNumberRequest (int32_t n,int32_t primes_per_reply):
    m_n_( n ),
    m_primes_per_reply_( primes_per_reply ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
PrimeNumberRequest::PrimeNumberRequest(PrimeNumberRequest&& other_) OMG_NOEXCEPT  :m_n_ (std::move(other_.m_n_))
,
m_primes_per_reply_ (std::move(other_.m_primes_per_reply_))
{
} 

PrimeNumberRequest& PrimeNumberRequest::operator=(PrimeNumberRequest&&  other_) OMG_NOEXCEPT {
    PrimeNumberRequest tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void PrimeNumberRequest::swap(PrimeNumberRequest& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_n_, other_.m_n_);
    swap(m_primes_per_reply_, other_.m_primes_per_reply_);
}  

bool PrimeNumberRequest::operator == (const PrimeNumberRequest& other_) const {
    if (m_n_ != other_.m_n_) {
        return false;
    }
    if (m_primes_per_reply_ != other_.m_primes_per_reply_) {
        return false;
    }
    return true;
}
bool PrimeNumberRequest::operator != (const PrimeNumberRequest& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const PrimeNumberRequest& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "n: " << sample.n()<<", ";
    o << "primes_per_reply: " << sample.primes_per_reply() ;
    o <<"]";
    return o;
}

std::ostream& operator << (std::ostream& o,const PrimeNumberCalculationStatus& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    switch(sample){
        case PrimeNumberCalculationStatus::REPLY_IN_PROGRESS:
        o << "PrimeNumberCalculationStatus::REPLY_IN_PROGRESS" << " ";
        break;
        case PrimeNumberCalculationStatus::REPLY_COMPLETED:
        o << "PrimeNumberCalculationStatus::REPLY_COMPLETED" << " ";
        break;
        case PrimeNumberCalculationStatus::REPLY_ERROR:
        o << "PrimeNumberCalculationStatus::REPLY_ERROR" << " ";
        break;
    }
    return o;
}

// ---- PrimeNumberReply: 

PrimeNumberReply::PrimeNumberReply() :
    m_status_(PrimeNumberCalculationStatus::REPLY_IN_PROGRESS)  {
}   

PrimeNumberReply::PrimeNumberReply (const ::rti::core::bounded_sequence< int32_t, (PRIME_SEQUENCE_MAX_LENGTH) >& primes,const PrimeNumberCalculationStatus& status):
    m_primes_( primes ),
    m_status_( status ) {
}

#ifdef RTI_CXX11_RVALUE_REFERENCES
#ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
PrimeNumberReply::PrimeNumberReply(PrimeNumberReply&& other_) OMG_NOEXCEPT  :m_primes_ (std::move(other_.m_primes_))
,
m_status_ (std::move(other_.m_status_))
{
} 

PrimeNumberReply& PrimeNumberReply::operator=(PrimeNumberReply&&  other_) OMG_NOEXCEPT {
    PrimeNumberReply tmp(std::move(other_));
    swap(tmp); 
    return *this;
}
#endif
#endif   

void PrimeNumberReply::swap(PrimeNumberReply& other_)  OMG_NOEXCEPT 
{
    using std::swap;
    swap(m_primes_, other_.m_primes_);
    swap(m_status_, other_.m_status_);
}  

bool PrimeNumberReply::operator == (const PrimeNumberReply& other_) const {
    if (m_primes_ != other_.m_primes_) {
        return false;
    }
    if (m_status_ != other_.m_status_) {
        return false;
    }
    return true;
}
bool PrimeNumberReply::operator != (const PrimeNumberReply& other_) const {
    return !this->operator ==(other_);
}

std::ostream& operator << (std::ostream& o,const PrimeNumberReply& sample)
{
    ::rti::util::StreamFlagSaver flag_saver (o);
    o <<"[";
    o << "primes: " << sample.primes()<<", ";
    o << "status: " << sample.status() ;
    o <<"]";
    return o;
}

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {
        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< PrimeNumberRequest > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member PrimeNumberRequest_g_tc_members[2]=
                {

                    {
                        (char *)"n",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"primes_per_reply",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode PrimeNumberRequest_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"PrimeNumberRequest", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        PrimeNumberRequest_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for PrimeNumberRequest*/

                if (is_initialized) {
                    return &PrimeNumberRequest_g_tc;
                }

                is_initialized = RTI_TRUE;

                PrimeNumberRequest_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                PrimeNumberRequest_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                PrimeNumberRequest_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

                /* Initialize the values for member annotations. */
                PrimeNumberRequest_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                PrimeNumberRequest_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
                PrimeNumberRequest_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                PrimeNumberRequest_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                PrimeNumberRequest_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                PrimeNumberRequest_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;
                PrimeNumberRequest_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
                PrimeNumberRequest_g_tc_members[1]._annotations._defaultValue._u.long_value = 0;
                PrimeNumberRequest_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_LONG;
                PrimeNumberRequest_g_tc_members[1]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
                PrimeNumberRequest_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
                PrimeNumberRequest_g_tc_members[1]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;

                PrimeNumberRequest_g_tc._data._sampleAccessInfo = sample_access_info();
                PrimeNumberRequest_g_tc._data._typePlugin = type_plugin_info();    

                return &PrimeNumberRequest_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                PrimeNumberRequest *sample;

                static RTIXCdrMemberAccessInfo PrimeNumberRequest_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo PrimeNumberRequest_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &PrimeNumberRequest_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    PrimeNumberRequest);
                if (sample == NULL) {
                    return NULL;
                }

                PrimeNumberRequest_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->n() - (char *)sample);

                PrimeNumberRequest_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->primes_per_reply() - (char *)sample);

                PrimeNumberRequest_g_sampleAccessInfo.memberAccessInfos = 
                PrimeNumberRequest_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(PrimeNumberRequest);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        PrimeNumberRequest_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        PrimeNumberRequest_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                PrimeNumberRequest_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                PrimeNumberRequest_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< PrimeNumberRequest >;

                PrimeNumberRequest_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &PrimeNumberRequest_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin PrimeNumberRequest_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &PrimeNumberRequest_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< PrimeNumberRequest >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< PrimeNumberRequest >::get())));
        }
        #ifndef NDDS_STANDALONE_TYPE
        const PrimeNumberCalculationStatus default_enumerator<PrimeNumberCalculationStatus>::value = PrimeNumberCalculationStatus::REPLY_IN_PROGRESS;
        template<>
        struct native_type_code< PrimeNumberCalculationStatus > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member PrimeNumberCalculationStatus_g_tc_members[3]=
                {

                    {
                        (char *)"REPLY_IN_PROGRESS",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(PrimeNumberCalculationStatus::REPLY_IN_PROGRESS), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"REPLY_COMPLETED",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(PrimeNumberCalculationStatus::REPLY_COMPLETED), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"REPLY_ERROR",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(PrimeNumberCalculationStatus::REPLY_ERROR), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode PrimeNumberCalculationStatus_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"PrimeNumberCalculationStatus", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        PrimeNumberCalculationStatus_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for PrimeNumberCalculationStatus*/

                if (is_initialized) {
                    return &PrimeNumberCalculationStatus_g_tc;
                }

                is_initialized = RTI_TRUE;

                PrimeNumberCalculationStatus_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                PrimeNumberCalculationStatus_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                PrimeNumberCalculationStatus_g_tc._data._annotations._defaultValue._u.long_value = 0;

                PrimeNumberCalculationStatus_g_tc._data._sampleAccessInfo = sample_access_info();
                PrimeNumberCalculationStatus_g_tc._data._typePlugin = type_plugin_info();    

                return &PrimeNumberCalculationStatus_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo PrimeNumberCalculationStatus_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo PrimeNumberCalculationStatus_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &PrimeNumberCalculationStatus_g_sampleAccessInfo;
                }

                PrimeNumberCalculationStatus_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                PrimeNumberCalculationStatus_g_sampleAccessInfo.memberAccessInfos = 
                PrimeNumberCalculationStatus_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(PrimeNumberCalculationStatus);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        PrimeNumberCalculationStatus_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        PrimeNumberCalculationStatus_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                PrimeNumberCalculationStatus_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                PrimeNumberCalculationStatus_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< PrimeNumberCalculationStatus >;

                PrimeNumberCalculationStatus_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &PrimeNumberCalculationStatus_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin PrimeNumberCalculationStatus_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &PrimeNumberCalculationStatus_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::EnumType& dynamic_type< PrimeNumberCalculationStatus >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< PrimeNumberCalculationStatus >::get())));
        }
        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< PrimeNumberReply > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode PrimeNumberReply_g_tc_primes_sequence;

                static DDS_TypeCode_Member PrimeNumberReply_g_tc_members[2]=
                {

                    {
                        (char *)"primes",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"status",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode PrimeNumberReply_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"PrimeNumberReply", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        PrimeNumberReply_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for PrimeNumberReply*/

                if (is_initialized) {
                    return &PrimeNumberReply_g_tc;
                }

                is_initialized = RTI_TRUE;

                PrimeNumberReply_g_tc_primes_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< int32_t, (PRIME_SEQUENCE_MAX_LENGTH) > >(((PRIME_SEQUENCE_MAX_LENGTH)));

                PrimeNumberReply_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                PrimeNumberReply_g_tc_primes_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
                PrimeNumberReply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& PrimeNumberReply_g_tc_primes_sequence;
                PrimeNumberReply_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< PrimeNumberCalculationStatus>::get().native();

                /* Initialize the values for member annotations. */
                PrimeNumberReply_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                PrimeNumberReply_g_tc_members[1]._annotations._defaultValue._u.enumerated_value = 0;

                PrimeNumberReply_g_tc._data._sampleAccessInfo = sample_access_info();
                PrimeNumberReply_g_tc._data._typePlugin = type_plugin_info();    

                return &PrimeNumberReply_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                PrimeNumberReply *sample;

                static RTIXCdrMemberAccessInfo PrimeNumberReply_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo PrimeNumberReply_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &PrimeNumberReply_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    PrimeNumberReply);
                if (sample == NULL) {
                    return NULL;
                }

                PrimeNumberReply_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->primes() - (char *)sample);

                PrimeNumberReply_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->status() - (char *)sample);

                PrimeNumberReply_g_sampleAccessInfo.memberAccessInfos = 
                PrimeNumberReply_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(PrimeNumberReply);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        PrimeNumberReply_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        PrimeNumberReply_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                PrimeNumberReply_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                PrimeNumberReply_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< PrimeNumberReply >;

                PrimeNumberReply_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &PrimeNumberReply_g_sampleAccessInfo;
            }
            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin PrimeNumberReply_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &PrimeNumberReply_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< PrimeNumberReply >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< PrimeNumberReply >::get())));
        }
    }
}

namespace dds { 
    namespace topic {
        void topic_type_support< PrimeNumberRequest >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                PrimeNumberRequestPlugin_new,
                PrimeNumberRequestPlugin_delete);
        }

        std::vector<char>& topic_type_support< PrimeNumberRequest >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const PrimeNumberRequest& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = PrimeNumberRequestPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = PrimeNumberRequestPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< PrimeNumberRequest >::from_cdr_buffer(PrimeNumberRequest& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = PrimeNumberRequestPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create PrimeNumberRequest from cdr buffer");
        }

        void topic_type_support< PrimeNumberRequest >::reset_sample(PrimeNumberRequest& sample) 
        {
            sample.n(0);
            sample.primes_per_reply(0);
        }

        void topic_type_support< PrimeNumberRequest >::allocate_sample(PrimeNumberRequest& sample, int, int) 
        {
            RTIOsapiUtility_unusedParameter(sample);
        }
        void topic_type_support< PrimeNumberReply >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                PrimeNumberReplyPlugin_new,
                PrimeNumberReplyPlugin_delete);
        }

        std::vector<char>& topic_type_support< PrimeNumberReply >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const PrimeNumberReply& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = PrimeNumberReplyPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = PrimeNumberReplyPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< PrimeNumberReply >::from_cdr_buffer(PrimeNumberReply& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = PrimeNumberReplyPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create PrimeNumberReply from cdr buffer");
        }

        void topic_type_support< PrimeNumberReply >::reset_sample(PrimeNumberReply& sample) 
        {
            ::rti::topic::reset_sample(sample.primes());
            sample.status(PrimeNumberCalculationStatus::REPLY_IN_PROGRESS);
        }

        void topic_type_support< PrimeNumberReply >::allocate_sample(PrimeNumberReply& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.primes(),  (PRIME_SEQUENCE_MAX_LENGTH), -1);
            ::rti::topic::allocate_sample(sample.status(),  -1, -1);
        }
    }
}  

