

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Primes.idl 
using RTI Code Generator (rtiddsgen) version 4.0.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#ifndef dds_c_log_impl_h              
#include "dds_c/dds_c_log_impl.h"                                
#endif 

#ifndef dds_c_log_infrastructure_h
#include "dds_c/dds_c_infrastructure_impl.h"       
#endif 

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#else
#include "ndds_standalone_type.h"
#endif

#include "Primes.h"

#ifndef NDDS_STANDALONE_TYPE
#include "PrimesPlugin.h"
#endif

#include <new>

/* ========================================================================= */
const char *PrimeNumberRequestTYPENAME = "PrimeNumberRequest";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode * PrimeNumberRequest_get_typecode(void)
{
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

    PrimeNumberRequest_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long_w_new;
    PrimeNumberRequest_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long_w_new;

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

    PrimeNumberRequest_g_tc._data._sampleAccessInfo =
    PrimeNumberRequest_get_sample_access_info();
    PrimeNumberRequest_g_tc._data._typePlugin =
    PrimeNumberRequest_get_type_plugin_info();    

    return &PrimeNumberRequest_g_tc;
}

#define TSeq PrimeNumberRequestSeq
#define T PrimeNumberRequest
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *PrimeNumberRequest_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo PrimeNumberRequest_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(PrimeNumberRequestSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        PrimeNumberRequestSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &PrimeNumberRequest_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *PrimeNumberRequest_get_sample_access_info()
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
    (RTIXCdrUnsignedLong) ((char *)&sample->n - (char *)sample);

    PrimeNumberRequest_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->primes_per_reply - (char *)sample);

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
    PrimeNumberRequest_get_member_value_pointer;

    PrimeNumberRequest_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &PrimeNumberRequest_g_sampleAccessInfo;
}
RTIXCdrTypePlugin *PrimeNumberRequest_get_type_plugin_info()
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
        (RTIXCdrTypePluginInitializeSampleFunction) 
        PrimeNumberRequest_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        PrimeNumberRequest_finalize_w_return,
        NULL,
        NULL
    };

    return &PrimeNumberRequest_g_typePlugin;
}
#endif

RTIBool PrimeNumberRequest_initialize(
    PrimeNumberRequest* sample)
{
    return PrimeNumberRequest_initialize_ex(
        sample, 
        RTI_TRUE, 
        RTI_TRUE);
}
RTIBool PrimeNumberRequest_initialize_w_params(
    PrimeNumberRequest *sample,
    const struct DDS_TypeAllocationParams_t *allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->n = 0;

    sample->primes_per_reply = 0;

    return RTI_TRUE;
}
RTIBool PrimeNumberRequest_initialize_ex(
    PrimeNumberRequest *sample,
    RTIBool allocatePointers, 
    RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return PrimeNumberRequest_initialize_w_params(
        sample,
        &allocParams);
}

RTIBool PrimeNumberRequest_finalize_w_return(
    PrimeNumberRequest* sample)
{
    PrimeNumberRequest_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void PrimeNumberRequest_finalize(
    PrimeNumberRequest* sample)
{

    PrimeNumberRequest_finalize_ex(sample,RTI_TRUE);
}

void PrimeNumberRequest_finalize_ex(
    PrimeNumberRequest* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    PrimeNumberRequest_finalize_w_params(
        sample,&deallocParams);
}

void PrimeNumberRequest_finalize_w_params(
    PrimeNumberRequest* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void PrimeNumberRequest_finalize_optional_members(
    PrimeNumberRequest* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool PrimeNumberRequest_copy(
    PrimeNumberRequest* dst,
    const PrimeNumberRequest* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!RTICdrType_copyLong (
            &dst->n, 
            &src->n)) { 
            return RTI_FALSE;
        }
        if (!RTICdrType_copyLong (
            &dst->primes_per_reply, 
            &src->primes_per_reply)) { 
            return RTI_FALSE;
        }

        return RTI_TRUE;
    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'PrimeNumberRequest' sequence class.
*/
#define T PrimeNumberRequest
#define TSeq PrimeNumberRequestSeq

#define T_initialize_w_params PrimeNumberRequest_initialize_w_params

#define T_finalize_w_params   PrimeNumberRequest_finalize_w_params
#define T_copy       PrimeNumberRequest_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

/* ========================================================================= */
const char *PrimeNumberCalculationStatusTYPENAME = "PrimeNumberCalculationStatus";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode * PrimeNumberCalculationStatus_get_typecode(void)
{
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
            REPLY_IN_PROGRESS, 
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
            REPLY_COMPLETED, 
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
            REPLY_ERROR, 
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

    PrimeNumberCalculationStatus_g_tc._data._sampleAccessInfo =
    PrimeNumberCalculationStatus_get_sample_access_info();
    PrimeNumberCalculationStatus_g_tc._data._typePlugin =
    PrimeNumberCalculationStatus_get_type_plugin_info();    

    return &PrimeNumberCalculationStatus_g_tc;
}

#define TSeq PrimeNumberCalculationStatusSeq
#define T PrimeNumberCalculationStatus
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *PrimeNumberCalculationStatus_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo PrimeNumberCalculationStatus_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(PrimeNumberCalculationStatusSeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        PrimeNumberCalculationStatusSeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &PrimeNumberCalculationStatus_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *PrimeNumberCalculationStatus_get_sample_access_info()
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
    PrimeNumberCalculationStatus_get_member_value_pointer;

    PrimeNumberCalculationStatus_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &PrimeNumberCalculationStatus_g_sampleAccessInfo;
}
RTIXCdrTypePlugin *PrimeNumberCalculationStatus_get_type_plugin_info()
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
        (RTIXCdrTypePluginInitializeSampleFunction) 
        PrimeNumberCalculationStatus_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        PrimeNumberCalculationStatus_finalize_w_return,
        NULL,
        NULL
    };

    return &PrimeNumberCalculationStatus_g_typePlugin;
}
#endif

RTIBool PrimeNumberCalculationStatus_initialize(
    PrimeNumberCalculationStatus* sample)
{

    *sample = REPLY_IN_PROGRESS;
    return RTI_TRUE;
}
RTIBool PrimeNumberCalculationStatus_initialize_w_params(
    PrimeNumberCalculationStatus *sample,
    const struct DDS_TypeAllocationParams_t *allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }
    *sample = REPLY_IN_PROGRESS;
    return RTI_TRUE;
}
RTIBool PrimeNumberCalculationStatus_initialize_ex(
    PrimeNumberCalculationStatus *sample,
    RTIBool allocatePointers, 
    RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return PrimeNumberCalculationStatus_initialize_w_params(
        sample,
        &allocParams);
}

RTIBool PrimeNumberCalculationStatus_finalize_w_return(
    PrimeNumberCalculationStatus* sample)
{
    if (sample) {} /* To avoid warnings */

    return RTI_TRUE;
}

void PrimeNumberCalculationStatus_finalize(
    PrimeNumberCalculationStatus* sample)
{

    if (sample==NULL) {
        return;
    }
}

void PrimeNumberCalculationStatus_finalize_ex(
    PrimeNumberCalculationStatus* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    PrimeNumberCalculationStatus_finalize_w_params(
        sample,&deallocParams);
}

void PrimeNumberCalculationStatus_finalize_w_params(
    PrimeNumberCalculationStatus* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void PrimeNumberCalculationStatus_finalize_optional_members(
    PrimeNumberCalculationStatus* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool PrimeNumberCalculationStatus_copy(
    PrimeNumberCalculationStatus* dst,
    const PrimeNumberCalculationStatus* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        return RTICdrType_copyEnum((RTICdrEnum *)dst, (RTICdrEnum *)src);

    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'PrimeNumberCalculationStatus' sequence class.
*/
#define T PrimeNumberCalculationStatus
#define TSeq PrimeNumberCalculationStatusSeq

#define T_initialize_w_params PrimeNumberCalculationStatus_initialize_w_params

#define T_finalize_w_params   PrimeNumberCalculationStatus_finalize_w_params
#define T_copy       PrimeNumberCalculationStatus_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

/* ========================================================================= */
const char *PrimeNumberReplyTYPENAME = "PrimeNumberReply";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode * PrimeNumberReply_get_typecode(void)
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode PrimeNumberReply_g_tc_primes_sequence = DDS_INITIALIZE_SEQUENCE_TYPECODE(((PRIME_SEQUENCE_MAX_LENGTH)),NULL);

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

    PrimeNumberReply_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    PrimeNumberReply_g_tc_primes_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long_w_new;
    PrimeNumberReply_g_tc_primes_sequence._data._sampleAccessInfo = &DDS_g_sai_long_seq;
    PrimeNumberReply_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)& PrimeNumberReply_g_tc_primes_sequence;
    PrimeNumberReply_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)PrimeNumberCalculationStatus_get_typecode();

    /* Initialize the values for member annotations. */
    PrimeNumberReply_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
    PrimeNumberReply_g_tc_members[1]._annotations._defaultValue._u.enumerated_value = 0;

    PrimeNumberReply_g_tc._data._sampleAccessInfo =
    PrimeNumberReply_get_sample_access_info();
    PrimeNumberReply_g_tc._data._typePlugin =
    PrimeNumberReply_get_type_plugin_info();    

    return &PrimeNumberReply_g_tc;
}

#define TSeq PrimeNumberReplySeq
#define T PrimeNumberReply
#include "dds_cpp/generic/dds_cpp_data_TInterpreterSupport.gen"
#undef T
#undef TSeq

RTIXCdrSampleAccessInfo *PrimeNumberReply_get_sample_seq_access_info()
{
    static RTIXCdrSampleAccessInfo PrimeNumberReply_g_seqSampleAccessInfo = {
        RTI_XCDR_TYPE_BINDING_CPP, \
        {sizeof(PrimeNumberReplySeq),0,0,0}, \
        RTI_XCDR_FALSE, \
        DDS_Sequence_get_member_value_pointer, \
        PrimeNumberReplySeq_set_member_element_count, \
        NULL, \
        NULL, \
        NULL \
    };

    return &PrimeNumberReply_g_seqSampleAccessInfo;
}

RTIXCdrSampleAccessInfo *PrimeNumberReply_get_sample_access_info()
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
    (RTIXCdrUnsignedLong) ((char *)&sample->primes - (char *)sample);

    PrimeNumberReply_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->status - (char *)sample);

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
    PrimeNumberReply_get_member_value_pointer;

    PrimeNumberReply_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &PrimeNumberReply_g_sampleAccessInfo;
}
RTIXCdrTypePlugin *PrimeNumberReply_get_type_plugin_info()
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
        (RTIXCdrTypePluginInitializeSampleFunction) 
        PrimeNumberReply_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        PrimeNumberReply_finalize_w_return,
        NULL,
        NULL
    };

    return &PrimeNumberReply_g_typePlugin;
}
#endif

RTIBool PrimeNumberReply_initialize(
    PrimeNumberReply* sample)
{
    return PrimeNumberReply_initialize_ex(
        sample, 
        RTI_TRUE, 
        RTI_TRUE);
}
RTIBool PrimeNumberReply_initialize_w_params(
    PrimeNumberReply *sample,
    const struct DDS_TypeAllocationParams_t *allocParams)
{
    void* buffer = NULL;
    if (buffer) {} /* To avoid warnings */

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory) {
        if(!DDS_LongSeq_initialize(&sample->primes  )){
            return RTI_FALSE;
        }
        if(!DDS_LongSeq_set_absolute_maximum(&sample->primes , ((PRIME_SEQUENCE_MAX_LENGTH)))){
            return RTI_FALSE;
        }
        if (!DDS_LongSeq_set_maximum(
            &sample->primes
            ,
            ((PRIME_SEQUENCE_MAX_LENGTH)))) {
            return RTI_FALSE;
        }
    } else { 
        if(!DDS_LongSeq_set_length(&sample->primes, 0)){
            return RTI_FALSE;
        }    
    }
    sample->status = REPLY_IN_PROGRESS;
    return RTI_TRUE;
}
RTIBool PrimeNumberReply_initialize_ex(
    PrimeNumberReply *sample,
    RTIBool allocatePointers, 
    RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return PrimeNumberReply_initialize_w_params(
        sample,
        &allocParams);
}

RTIBool PrimeNumberReply_finalize_w_return(
    PrimeNumberReply* sample)
{
    PrimeNumberReply_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void PrimeNumberReply_finalize(
    PrimeNumberReply* sample)
{

    PrimeNumberReply_finalize_ex(sample,RTI_TRUE);
}

void PrimeNumberReply_finalize_ex(
    PrimeNumberReply* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    PrimeNumberReply_finalize_w_params(
        sample,&deallocParams);
}

void PrimeNumberReply_finalize_w_params(
    PrimeNumberReply* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    if(!DDS_LongSeq_finalize(&sample->primes)){
        return;
    }

    PrimeNumberCalculationStatus_finalize_w_params(&sample->status,deallocParams);

}

void PrimeNumberReply_finalize_optional_members(
    PrimeNumberReply* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool PrimeNumberReply_copy(
    PrimeNumberReply* dst,
    const PrimeNumberReply* src)
{
    try {

        if (dst == NULL || src == NULL) {
            return RTI_FALSE;
        }

        if (!DDS_LongSeq_copy(
            &dst->primes ,
            &src->primes )) {
            return RTI_FALSE;
        }
        if (!PrimeNumberCalculationStatus_copy(
            &dst->status,
            (const PrimeNumberCalculationStatus*)&src->status)) {
            return RTI_FALSE;
        } 

        return RTI_TRUE;
    } catch (const std::bad_alloc&) {
        return RTI_FALSE;
    }
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'PrimeNumberReply' sequence class.
*/
#define T PrimeNumberReply
#define TSeq PrimeNumberReplySeq

#define T_initialize_w_params PrimeNumberReply_initialize_w_params

#define T_finalize_w_params   PrimeNumberReply_finalize_w_params
#define T_copy       PrimeNumberReply_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#include "dds_cpp/generic/dds_cpp_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#include "dds_cpp_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

#ifndef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace xcdr {
        const RTIXCdrTypeCode * type_code<PrimeNumberRequest>::get() 
        {
            return (const RTIXCdrTypeCode *) PrimeNumberRequest_get_typecode();
        }

        const RTIXCdrTypeCode * type_code<PrimeNumberReply>::get() 
        {
            return (const RTIXCdrTypeCode *) PrimeNumberReply_get_typecode();
        }

    } 
}
#endif
