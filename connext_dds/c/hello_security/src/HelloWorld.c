

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorld.idl 
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

#include "HelloWorld.h"

#ifndef NDDS_STANDALONE_TYPE
#include "HelloWorldPlugin.h"
#endif

/* ========================================================================= */
const char *HelloWorldTYPENAME = "HelloWorld";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode * HelloWorld_get_typecode(void)
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode HelloWorld_g_tc_msg_string = DDS_INITIALIZE_STRING_TYPECODE((128L));

    static DDS_TypeCode_Member HelloWorld_g_tc_members[1]=
    {

        {
            (char *)"msg",/* Member name */
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
        }
    };

    static DDS_TypeCode HelloWorld_g_tc =
    {{
            DDS_TK_STRUCT, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"HelloWorld", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            1, /* Number of members */
            HelloWorld_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for HelloWorld*/

    if (is_initialized) {
        return &HelloWorld_g_tc;
    }

    is_initialized = RTI_TRUE;

    HelloWorld_g_tc._data._annotations._allowedDataRepresentationMask = 5;

    HelloWorld_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&HelloWorld_g_tc_msg_string;

    /* Initialize the values for member annotations. */
    HelloWorld_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
    HelloWorld_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

    HelloWorld_g_tc._data._sampleAccessInfo =
    HelloWorld_get_sample_access_info();
    HelloWorld_g_tc._data._typePlugin =
    HelloWorld_get_type_plugin_info();    

    return &HelloWorld_g_tc;
}

RTIXCdrSampleAccessInfo *HelloWorld_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo HelloWorld_g_memberAccessInfos[1] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo HelloWorld_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &HelloWorld_g_sampleAccessInfo;
    }

    HelloWorld_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) RTIXCdrUtility_pointerToULongLong(&((HelloWorld *)NULL)->msg);

    HelloWorld_g_sampleAccessInfo.memberAccessInfos = 
    HelloWorld_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(HelloWorld);

        if (candidateTypeSize > RTIXCdrLong_MAX) {
            HelloWorld_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrLong_MAX;
        } else {
            HelloWorld_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    HelloWorld_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_C ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &HelloWorld_g_sampleAccessInfo;
}
RTIXCdrTypePlugin *HelloWorld_get_type_plugin_info()
{
    static RTIXCdrTypePlugin HelloWorld_g_typePlugin = 
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
        HelloWorld_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        HelloWorld_finalize_w_return,
        NULL,
        NULL
    };

    return &HelloWorld_g_typePlugin;
}
#endif

RTIBool HelloWorld_initialize(
    HelloWorld* sample)
{
    return HelloWorld_initialize_ex(
        sample, 
        RTI_TRUE, 
        RTI_TRUE);
}
RTIBool HelloWorld_initialize_w_params(
    HelloWorld *sample,
    const struct DDS_TypeAllocationParams_t *allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (allocParams->allocate_memory) {
        sample->msg = DDS_String_alloc((128L));
        if (sample->msg != NULL) {
            RTIOsapiUtility_unusedReturnValue(
                RTICdrType_copyStringEx(
                    &sample->msg,
                    "",
                    (128L),
                    RTI_FALSE),
                    RTIBool);
        }
        if (sample->msg == NULL) {
            return RTI_FALSE;
        }
    } else {
        if (sample->msg != NULL) {
            RTIOsapiUtility_unusedReturnValue(
                RTICdrType_copyStringEx(
                    &sample->msg,
                    "",
                    (128L),
                    RTI_FALSE),
                    RTIBool);
            if (sample->msg == NULL) {
                return RTI_FALSE;
            }
        }
    }

    return RTI_TRUE;
}
RTIBool HelloWorld_initialize_ex(
    HelloWorld *sample,
    RTIBool allocatePointers, 
    RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return HelloWorld_initialize_w_params(
        sample,
        &allocParams);
}

RTIBool HelloWorld_finalize_w_return(
    HelloWorld* sample)
{
    HelloWorld_finalize_ex(sample, RTI_TRUE);

    return RTI_TRUE;
}

void HelloWorld_finalize(
    HelloWorld* sample)
{

    HelloWorld_finalize_ex(sample,RTI_TRUE);
}

void HelloWorld_finalize_ex(
    HelloWorld* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    HelloWorld_finalize_w_params(
        sample,&deallocParams);
}

void HelloWorld_finalize_w_params(
    HelloWorld* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    if (sample->msg != NULL) {
        DDS_String_free(sample->msg);
        sample->msg=NULL;

    }
}

void HelloWorld_finalize_optional_members(
    HelloWorld* sample, RTIBool deletePointers)
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

RTIBool HelloWorld_copy(
    HelloWorld* dst,
    const HelloWorld* src)
{

    if (dst == NULL || src == NULL) {
        return RTI_FALSE;
    }

    if (!RTICdrType_copyStringEx (
        &dst->msg
        ,
        src->msg, 
        (128L) + 1,
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
* Configure and implement 'HelloWorld' sequence class.
*/
#define T HelloWorld
#define TSeq HelloWorldSeq

#define T_initialize_w_params HelloWorld_initialize_w_params

#define T_finalize_w_params   HelloWorld_finalize_w_params
#define T_copy       HelloWorld_copy

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

