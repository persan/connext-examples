

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorldTopicQuery.idl 
using RTI Code Generator (rtiddsgen) version 4.0.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
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

#include "HelloWorldTopicQuery.h"

#ifndef NDDS_STANDALONE_TYPE
#include "HelloWorldTopicQueryPlugin.h"
#endif

/* ========================================================================= */
const char *HelloWorldTopicQueryTYPENAME = "HelloWorldTopicQuery";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode * HelloWorldTopicQuery_get_typecode(void)
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode HelloWorldTopicQuery_g_tc_message_string = DDS_INITIALIZE_STRING_TYPECODE((255L));

    static DDS_TypeCode_Member HelloWorldTopicQuery_g_tc_members[2]=
    {

        {
            (char *)"id",/* Member name */
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
            RTI_CDR_KEY_MEMBER , /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"message",/* Member name */
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

    static DDS_TypeCode HelloWorldTopicQuery_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"HelloWorldTopicQuery", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            HelloWorldTopicQuery_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for HelloWorldTopicQuery*/

    if (is_initialized) {
        return &HelloWorldTopicQuery_g_tc;
    }

    is_initialized = RTI_TRUE;

    HelloWorldTopicQuery_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    HelloWorldTopicQuery_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;
    HelloWorldTopicQuery_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&HelloWorldTopicQuery_g_tc_message_string;

    /* Initialize the values for member annotations. */
    HelloWorldTopicQuery_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONG;
    HelloWorldTopicQuery_g_tc_members[0]._annotations._defaultValue._u.long_value = 0;
    HelloWorldTopicQuery_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONG;
    HelloWorldTopicQuery_g_tc_members[0]._annotations._minValue._u.long_value = RTIXCdrLong_MIN;
    HelloWorldTopicQuery_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONG;
    HelloWorldTopicQuery_g_tc_members[0]._annotations._maxValue._u.long_value = RTIXCdrLong_MAX;
    HelloWorldTopicQuery_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    HelloWorldTopicQuery_g_tc_members[1]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    HelloWorldTopicQuery_g_tc._data._sampleAccessInfo =
    HelloWorldTopicQuery_get_sample_access_info();
    HelloWorldTopicQuery_g_tc._data._typePlugin =
    HelloWorldTopicQuery_get_type_plugin_info();    

    return &HelloWorldTopicQuery_g_tc;
}

RTIXCdrSampleAccessInfo *HelloWorldTopicQuery_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo HelloWorldTopicQuery_g_memberAccessInfos[2] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo HelloWorldTopicQuery_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &HelloWorldTopicQuery_g_sampleAccessInfo;
    }

    HelloWorldTopicQuery_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((HelloWorldTopicQuery *)NULL)->id);

    HelloWorldTopicQuery_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((HelloWorldTopicQuery *)NULL)->message);

    HelloWorldTopicQuery_g_sampleAccessInfo.memberAccessInfos = 
    HelloWorldTopicQuery_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(HelloWorldTopicQuery);

        if (candidateTypeSize > RTIXCdrLong_MAX) {
            HelloWorldTopicQuery_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrLong_MAX;
        } else {
            HelloWorldTopicQuery_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    HelloWorldTopicQuery_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_C ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &HelloWorldTopicQuery_g_sampleAccessInfo;
}
RTIXCdrTypePlugin *HelloWorldTopicQuery_get_type_plugin_info()
{
    static RTIXCdrTypePlugin HelloWorldTopicQuery_g_typePlugin = 
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
        HelloWorldTopicQuery_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        HelloWorldTopicQuery_finalize_w_return,
        NULL,
        NULL
    };

    return &HelloWorldTopicQuery_g_typePlugin;
}
#endif

RTIBool HelloWorldTopicQuery_initialize(
    HelloWorldTopicQuery* sample)
{
    return HelloWorldTopicQuery_initialize_ex(
        sample, 
        RTI_TRUE, 
        RTI_TRUE);
}
RTIBool HelloWorldTopicQuery_initialize_w_params(
    HelloWorldTopicQuery *sample,
    const struct DDS_TypeAllocationParams_t *allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->id = 0;

    if (allocParams->allocate_memory) {
        sample->message = DDS_String_alloc((255L));
        if (sample->message != NULL) {
            RTIOsapiUtility_unusedReturnValue(
                RTICdrType_copyStringEx(
                    &sample->message,
                    "",
                    (255L),
                    RTI_FALSE),
                    RTIBool);
        }
        if (sample->message == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->message != NULL) {
            RTIOsapiUtility_unusedReturnValue(
                RTICdrType_copyStringEx(
                    &sample->message,
                    "",
                    (255L),
                    RTI_FALSE),
                    RTIBool);
            if (sample->message == NULL) {
                return RTI_FALSE;
            }
        }
    }

    return RTI_TRUE;
}
RTIBool HelloWorldTopicQuery_initialize_ex(
    HelloWorldTopicQuery *sample,
    RTIBool allocatePointers, 
    RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return HelloWorldTopicQuery_initialize_w_params(
        sample,
        &allocParams);
}

RTIBool HelloWorldTopicQuery_finalize_w_return(
    HelloWorldTopicQuery* sample)
{
    HelloWorldTopicQuery_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void HelloWorldTopicQuery_finalize(
    HelloWorldTopicQuery* sample)
{

    HelloWorldTopicQuery_finalize_ex(sample,RTI_TRUE);
}

void HelloWorldTopicQuery_finalize_ex(
    HelloWorldTopicQuery* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    HelloWorldTopicQuery_finalize_w_params(
        sample,&deallocParams);
}

void HelloWorldTopicQuery_finalize_w_params(
    HelloWorldTopicQuery* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    if (sample->message != NULL) {
        DDS_String_free(sample->message);
        sample->message=NULL;

    }
}

void HelloWorldTopicQuery_finalize_optional_members(
    HelloWorldTopicQuery* sample, RTIBool deletePointers)
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

RTIBool HelloWorldTopicQuery_copy(
    HelloWorldTopicQuery* dst,
    const HelloWorldTopicQuery* src)
{

    if (dst == NULL || src == NULL) {
        return RTI_FALSE;
    }

    if (!RTICdrType_copyLong (
        &dst->id, 
        &src->id)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyStringEx (
        &dst->message
        ,
        src->message, 
        (255L) + 1,
        RTI_FALSE)){
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'HelloWorldTopicQuery' sequence class.
*/
#define T HelloWorldTopicQuery
#define TSeq HelloWorldTopicQuerySeq

#define T_initialize_w_params HelloWorldTopicQuery_initialize_w_params

#define T_finalize_w_params   HelloWorldTopicQuery_finalize_w_params
#define T_copy       HelloWorldTopicQuery_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

