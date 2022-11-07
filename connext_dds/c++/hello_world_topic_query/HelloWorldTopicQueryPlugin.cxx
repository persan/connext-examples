
/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorldTopicQuery.idl
using RTI Code Generator (rtiddsgen) version 4.0.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <string.h>

#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif

#ifndef osapi_type_h
#include "osapi/osapi_type.h"
#endif
#ifndef osapi_heap_h
#include "osapi/osapi_heap.h"
#endif

#ifndef osapi_utility_h
#include "osapi/osapi_utility.h"
#endif

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif

#ifndef cdr_type_object_h
#include "cdr/cdr_typeObject.h"
#endif

#ifndef cdr_encapsulation_h
#include "cdr/cdr_encapsulation.h"
#endif

#ifndef cdr_stream_h
#include "cdr/cdr_stream.h"
#endif

#include "xcdr/xcdr_interpreter.h"
#include "xcdr/xcdr_stream.h"

#ifndef cdr_log_h
#include "cdr/cdr_log.h"
#endif

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#include "dds_c/dds_c_typecode_impl.h"

#define RTI_CDR_CURRENT_SUBMODULE RTI_CDR_SUBMODULE_MASK_STREAM

#include <new>

#include "HelloWorldTopicQueryPlugin.h"

/* ----------------------------------------------------------------------------
*  Type HelloWorldTopicQuery
* -------------------------------------------------------------------------- */

/* -----------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------- */

HelloWorldTopicQuery*
HelloWorldTopicQueryPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params) 
{
    HelloWorldTopicQuery *sample = NULL;

    if (alloc_params == NULL) {
        return NULL;
    } else if(!alloc_params->allocate_memory) {
        RTICdrLog_exception(&RTI_CDR_LOG_TYPE_OBJECT_NOT_ASSIGNABLE_ss,
        "alloc_params->allocate_memory","false");
        return NULL;
    }

    sample = new (std::nothrow) HelloWorldTopicQuery();
    if (sample == NULL) {
        return NULL;
    }

    if (!HelloWorldTopicQuery_initialize_w_params(sample,alloc_params)) {
        struct DDS_TypeDeallocationParams_t deallocParams =
        DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
        deallocParams.delete_pointers = alloc_params->allocate_pointers;
        deallocParams.delete_optional_members = alloc_params->allocate_pointers;
        /* Coverity reports a possible uninit_use_in_call that will happen if the
        allocation fails. But if the allocation fails then sample == null and
        the method will return before reach this point.*/
        /* coverity[uninit_use_in_call : FALSE] */
        HelloWorldTopicQuery_finalize_w_params(sample, &deallocParams);
        delete  sample;
        sample=NULL;
    }
    return sample;
} 

HelloWorldTopicQuery *
HelloWorldTopicQueryPluginSupport_create_data_ex(RTIBool allocate_pointers) 
{
    HelloWorldTopicQuery *sample = NULL;

    sample = new (std::nothrow) HelloWorldTopicQuery();

    if(sample == NULL) {
        return NULL;
    }

    if (!HelloWorldTopicQuery_initialize_ex(sample,allocate_pointers, RTI_TRUE)) {
        /* Coverity reports a possible uninit_use_in_call that will happen if the
        new fails. But if new fails then sample == null and the method will
        return before reach this point. */
        /* coverity[uninit_use_in_call : FALSE] */
        HelloWorldTopicQuery_finalize_ex(sample, RTI_TRUE);
        delete  sample;
        sample=NULL;
    }

    return sample;
}

HelloWorldTopicQuery *
HelloWorldTopicQueryPluginSupport_create_data(void)
{
    return HelloWorldTopicQueryPluginSupport_create_data_ex(RTI_TRUE);
}

void 
HelloWorldTopicQueryPluginSupport_destroy_data_w_params(
    HelloWorldTopicQuery *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params) {
    HelloWorldTopicQuery_finalize_w_params(sample,dealloc_params);

    delete  sample;
}

void 
HelloWorldTopicQueryPluginSupport_destroy_data_ex(
    HelloWorldTopicQuery *sample,RTIBool deallocate_pointers) {
    HelloWorldTopicQuery_finalize_ex(sample,deallocate_pointers);

    delete  sample;
}

void 
HelloWorldTopicQueryPluginSupport_destroy_data(
    HelloWorldTopicQuery *sample) {

    HelloWorldTopicQueryPluginSupport_destroy_data_ex(sample,RTI_TRUE);

}

RTIBool 
HelloWorldTopicQueryPluginSupport_copy_data(
    HelloWorldTopicQuery *dst,
    const HelloWorldTopicQuery *src)
{
    return HelloWorldTopicQuery_copy(dst,(const HelloWorldTopicQuery*) src);
}

void 
HelloWorldTopicQueryPluginSupport_print_data(
    const HelloWorldTopicQuery *sample,
    const char *desc,
    unsigned int indent_level)
{

    RTICdrType_printIndent(indent_level);

    if (desc != NULL) {
        RTILogParamString_printPlain("%s:\n", desc);
    } else {
        RTILogParamString_printPlain("\n");
    }

    if (sample == NULL) {
        RTILogParamString_printPlain("NULL\n");
        return;
    }

    RTICdrType_printLong(
        &sample->id, "id", indent_level + 1);    

    if (sample->message==NULL) {
        RTICdrType_printString(
            NULL,"message", indent_level + 1);
    } else {
        RTICdrType_printString(
            sample->message,"message", indent_level + 1);    
    }

}

HelloWorldTopicQuery *
HelloWorldTopicQueryPluginSupport_create_key_ex(RTIBool allocate_pointers){
    HelloWorldTopicQuery *key = NULL;

    key = new (std::nothrow) HelloWorldTopicQueryKeyHolder();

    HelloWorldTopicQuery_initialize_ex(key,allocate_pointers, RTI_TRUE);

    return key;
}

HelloWorldTopicQuery *
HelloWorldTopicQueryPluginSupport_create_key(void)
{
    return  HelloWorldTopicQueryPluginSupport_create_key_ex(RTI_TRUE);
}

void 
HelloWorldTopicQueryPluginSupport_destroy_key_ex(
    HelloWorldTopicQueryKeyHolder *key,RTIBool deallocate_pointers)
{
    HelloWorldTopicQuery_finalize_ex(key,deallocate_pointers);

    delete  key;
}

void 
HelloWorldTopicQueryPluginSupport_destroy_key(
    HelloWorldTopicQueryKeyHolder *key) {

    HelloWorldTopicQueryPluginSupport_destroy_key_ex(key,RTI_TRUE);

}

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

PRESTypePluginParticipantData 
HelloWorldTopicQueryPlugin_on_participant_attached(
    void *registration_data,
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration,
    void *container_plugin_context,
    RTICdrTypeCode *type_code)
{
    struct RTIXCdrInterpreterPrograms *programs = NULL;
    struct RTIXCdrInterpreterProgramsGenProperty programProperty =
    RTIXCdrInterpreterProgramsGenProperty_INITIALIZER;
    struct PRESTypePluginDefaultParticipantData *pd = NULL;

    if (registration_data) {} /* To avoid warnings */
    if (participant_info) {} /* To avoid warnings */
    if (top_level_registration) {} /* To avoid warnings */
    if (container_plugin_context) {} /* To avoid warnings */
    if (type_code) {} /* To avoid warnings */

    pd = (struct PRESTypePluginDefaultParticipantData *)
    PRESTypePluginDefaultParticipantData_new(participant_info);

    programProperty.generateV1Encapsulation = RTI_XCDR_TRUE;
    programProperty.generateV2Encapsulation = RTI_XCDR_TRUE;
    programProperty.resolveAlias = RTI_XCDR_TRUE;
    programProperty.inlineStruct = RTI_XCDR_TRUE;
    programProperty.optimizeEnum = RTI_XCDR_TRUE;
    programProperty.unboundedSize = RTIXCdrLong_MAX;

    programs = DDS_TypeCodeFactory_assert_programs_in_global_list(
        DDS_TypeCodeFactory_get_instance(),
        HelloWorldTopicQuery_get_typecode(),
        &programProperty,
        RTI_XCDR_PROGRAM_MASK_TYPEPLUGIN);
    if (programs == NULL) {
        PRESTypePluginDefaultParticipantData_delete(
            (PRESTypePluginParticipantData) pd);
        return NULL;
    }

    pd->programs = programs;
    return (PRESTypePluginParticipantData)pd;
}

void 
HelloWorldTopicQueryPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data)
{  		
    if (participant_data != NULL) {
        struct PRESTypePluginDefaultParticipantData *pd = 
        (struct PRESTypePluginDefaultParticipantData *)participant_data;

        if (pd->programs != NULL) {
            DDS_TypeCodeFactory_remove_programs_from_global_list(
                DDS_TypeCodeFactory_get_instance(),
                pd->programs);
            pd->programs = NULL;
        }
        PRESTypePluginDefaultParticipantData_delete(participant_data);
    }
}

PRESTypePluginEndpointData
HelloWorldTopicQueryPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *containerPluginContext)
{
    PRESTypePluginEndpointData epd = NULL;
    unsigned int serializedSampleMaxSize = 0;

    unsigned int serializedKeyMaxSize = 0;
    unsigned int serializedKeyMaxSizeV2 = 0;

    if (top_level_registration) {} /* To avoid warnings */
    if (containerPluginContext) {} /* To avoid warnings */

    if (participant_data == NULL) {
        return NULL;
    } 

    epd = PRESTypePluginDefaultEndpointData_new(
        participant_data,
        endpoint_info,
        (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
        HelloWorldTopicQueryPluginSupport_create_data,
        (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
        HelloWorldTopicQueryPluginSupport_destroy_data,
        (PRESTypePluginDefaultEndpointDataCreateKeyFunction)
        HelloWorldTopicQueryPluginSupport_create_key ,            (PRESTypePluginDefaultEndpointDataDestroyKeyFunction)
        HelloWorldTopicQueryPluginSupport_destroy_key);

    if (epd == NULL) {
        return NULL;
    } 

    serializedKeyMaxSize =  HelloWorldTopicQueryPlugin_get_serialized_key_max_size(
        epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
    serializedKeyMaxSizeV2 =  HelloWorldTopicQueryPlugin_get_serialized_key_max_size_for_keyhash(
        epd,
        RTI_CDR_ENCAPSULATION_ID_CDR2_BE,
        0);

    if(!PRESTypePluginDefaultEndpointData_createMD5StreamWithInfo(
        epd,
        endpoint_info,
        serializedKeyMaxSize,
        serializedKeyMaxSizeV2))  
    {
        PRESTypePluginDefaultEndpointData_delete(epd);
        return NULL;
    }

    if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
        serializedSampleMaxSize = HelloWorldTopicQueryPlugin_get_serialized_sample_max_size(
            epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
        PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, serializedSampleMaxSize);

        if (PRESTypePluginDefaultEndpointData_createWriterPool(
            epd,
            endpoint_info,
            (PRESTypePluginGetSerializedSampleMaxSizeFunction)
            HelloWorldTopicQueryPlugin_get_serialized_sample_max_size, epd,
            (PRESTypePluginGetSerializedSampleSizeFunction)
            PRESTypePlugin_interpretedGetSerializedSampleSize,
            epd) == RTI_FALSE) {
            PRESTypePluginDefaultEndpointData_delete(epd);
            return NULL;
        }
    }

    return epd;    
}

void 
HelloWorldTopicQueryPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data)
{
    PRESTypePluginDefaultEndpointData_delete(endpoint_data);
}

void    
HelloWorldTopicQueryPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    HelloWorldTopicQuery *sample,
    void *handle)
{
    HelloWorldTopicQuery_finalize_optional_members(sample, RTI_TRUE);

    PRESTypePluginDefaultEndpointData_returnSample(
        endpoint_data, sample, handle);
}

void HelloWorldTopicQueryPlugin_finalize_optional_members(
    PRESTypePluginEndpointData endpoint_data,
    HelloWorldTopicQuery* sample,
    RTIBool deletePointers)
{
    RTIOsapiUtility_unusedParameter(endpoint_data);
    HelloWorldTopicQuery_finalize_optional_members(
        sample, deletePointers);
}

RTIBool 
HelloWorldTopicQueryPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    HelloWorldTopicQuery *dst,
    const HelloWorldTopicQuery *src)
{
    if (endpoint_data) {} /* To avoid warnings */
    return HelloWorldTopicQueryPluginSupport_copy_data(dst,src);
}

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */
unsigned int 
HelloWorldTopicQueryPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

RTIBool
HelloWorldTopicQueryPlugin_serialize_to_cdr_buffer_ex(
    char *buffer,
    unsigned int *length,
    const HelloWorldTopicQuery *sample,
    DDS_DataRepresentationId_t representation)
{
    RTIEncapsulationId encapsulationId = RTI_CDR_ENCAPSULATION_ID_INVALID;
    struct RTICdrStream stream;
    struct PRESTypePluginDefaultEndpointData epd;
    RTIBool result;
    struct PRESTypePluginDefaultParticipantData pd;
    struct RTIXCdrTypePluginProgramContext defaultProgramContext =
    RTIXCdrTypePluginProgramContext_INTIALIZER;
    struct PRESTypePlugin plugin;

    if (length == NULL) {
        return RTI_FALSE;
    }

    RTIOsapiMemory_zero(&epd, sizeof(struct PRESTypePluginDefaultEndpointData));
    epd.programContext = defaultProgramContext;
    epd._participantData = &pd;
    epd.typePlugin = &plugin;
    epd.programContext.endpointPluginData = &epd;
    plugin.typeCode = (struct RTICdrTypeCode *)
    HelloWorldTopicQuery_get_typecode();
    pd.programs = HelloWorldTopicQueryPlugin_get_programs();
    if (pd.programs == NULL) {
        return RTI_FALSE;
    }

    encapsulationId = DDS_TypeCode_get_native_encapsulation(
        (DDS_TypeCode *) plugin.typeCode,
        representation);    
    if (encapsulationId == RTI_CDR_ENCAPSULATION_ID_INVALID) {
        return RTI_FALSE;
    }

    epd._maxSizeSerializedSample =
    HelloWorldTopicQueryPlugin_get_serialized_sample_max_size(
        (PRESTypePluginEndpointData)&epd, 
        RTI_TRUE, 
        encapsulationId,
        0);

    if (buffer == NULL) {
        *length = 
        PRESTypePlugin_interpretedGetSerializedSampleSize(
            (PRESTypePluginEndpointData)&epd,
            RTI_TRUE,
            encapsulationId,
            0,
            sample);

        if (*length == 0) {
            return RTI_FALSE;
        }

        return RTI_TRUE;
    }    

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, *length);

    result = PRESTypePlugin_interpretedSerialize(
        (PRESTypePluginEndpointData)&epd,
        sample,
        &stream,
        RTI_TRUE,
        encapsulationId,
        RTI_TRUE,
        NULL);

    *length = (unsigned int) RTICdrStream_getCurrentPositionOffset(&stream);
    return result;
}

RTIBool
HelloWorldTopicQueryPlugin_serialize_to_cdr_buffer(
    char *buffer,
    unsigned int *length,
    const HelloWorldTopicQuery *sample)
{
    return HelloWorldTopicQueryPlugin_serialize_to_cdr_buffer_ex(
        buffer,
        length,
        sample,
        DDS_AUTO_DATA_REPRESENTATION);
}

RTIBool
HelloWorldTopicQueryPlugin_deserialize_from_cdr_buffer(
    HelloWorldTopicQuery *sample,
    const char * buffer,
    unsigned int length)
{
    struct RTICdrStream stream;
    struct PRESTypePluginDefaultEndpointData epd;
    struct RTIXCdrTypePluginProgramContext defaultProgramContext =
    RTIXCdrTypePluginProgramContext_INTIALIZER;
    struct PRESTypePluginDefaultParticipantData pd;
    struct PRESTypePlugin plugin;

    epd.programContext = defaultProgramContext;
    epd._participantData = &pd;
    epd.typePlugin = &plugin;
    epd.programContext.endpointPluginData = &epd;
    plugin.typeCode = (struct RTICdrTypeCode *)
    HelloWorldTopicQuery_get_typecode();
    pd.programs = HelloWorldTopicQueryPlugin_get_programs();
    if (pd.programs == NULL) {
        return RTI_FALSE;
    }

    epd._assignabilityProperty.acceptUnknownEnumValue = RTI_XCDR_TRUE;
    epd._assignabilityProperty.acceptUnknownUnionDiscriminator = RTI_XCDR_TRUE;

    RTICdrStream_init(&stream);
    RTICdrStream_set(&stream, (char *)buffer, length);

    HelloWorldTopicQuery_finalize_optional_members(sample, RTI_TRUE);
    return PRESTypePlugin_interpretedDeserialize( 
        (PRESTypePluginEndpointData)&epd, sample,
        &stream, RTI_TRUE, RTI_TRUE, 
        NULL);
}

#if !defined(NDDS_STANDALONE_TYPE)
DDS_ReturnCode_t
HelloWorldTopicQueryPlugin_data_to_string(
    const HelloWorldTopicQuery *sample,
    char *_str,
    DDS_UnsignedLong *str_size, 
    const struct DDS_PrintFormatProperty *property)
{
    DDS_DynamicData *data = NULL;
    char *buffer = NULL;
    unsigned int length = 0;
    struct DDS_PrintFormat printFormat;
    DDS_ReturnCode_t retCode = DDS_RETCODE_ERROR;

    if (sample == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }

    if (str_size == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }

    if (property == NULL) {
        return DDS_RETCODE_BAD_PARAMETER;
    }
    if (!HelloWorldTopicQueryPlugin_serialize_to_cdr_buffer(
        NULL, 
        &length, 
        sample)) {
        return DDS_RETCODE_ERROR;
    }

    RTIOsapiHeap_allocateBuffer(&buffer, length, RTI_OSAPI_ALIGNMENT_DEFAULT);
    if (buffer == NULL) {
        return DDS_RETCODE_ERROR;
    }

    if (!HelloWorldTopicQueryPlugin_serialize_to_cdr_buffer(
        buffer, 
        &length, 
        sample)) {
        RTIOsapiHeap_freeBuffer(buffer);
        return DDS_RETCODE_ERROR;
    }
    data = DDS_DynamicData_new(
        HelloWorldTopicQuery_get_typecode(), 
        &DDS_DYNAMIC_DATA_PROPERTY_DEFAULT);
    if (data == NULL) {
        RTIOsapiHeap_freeBuffer(buffer);
        return DDS_RETCODE_ERROR;
    }

    retCode = DDS_DynamicData_from_cdr_buffer(data, buffer, length);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    retCode = DDS_PrintFormatProperty_to_print_format(
        property, 
        &printFormat);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    retCode = DDS_DynamicDataFormatter_to_string_w_format(
        data, 
        _str,
        str_size, 
        &printFormat);
    if (retCode != DDS_RETCODE_OK) {
        RTIOsapiHeap_freeBuffer(buffer);
        DDS_DynamicData_delete(data);
        return retCode;
    }

    RTIOsapiHeap_freeBuffer(buffer);
    DDS_DynamicData_delete(data);
    return DDS_RETCODE_OK;
}
#endif

unsigned int 
HelloWorldTopicQueryPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;

    size = PRESTypePlugin_interpretedGetSerializedSampleMaxSize(
        endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */

PRESTypePluginKeyKind 
HelloWorldTopicQueryPlugin_get_key_kind(void)
{
    return PRES_TYPEPLUGIN_USER_KEY;
}

RTIBool HelloWorldTopicQueryPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    HelloWorldTopicQuery **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos)
{
    RTIBool result;
    if (drop_sample) {} /* To avoid warnings */
    result= PRESTypePlugin_interpretedDeserializeKey(
        endpoint_data, (sample != NULL)?*sample:NULL, stream,
        deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
    return result;    

}

unsigned int
HelloWorldTopicQueryPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;
    size = PRESTypePlugin_interpretedGetSerializedKeyMaxSize(
        endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);
    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

unsigned int
HelloWorldTopicQueryPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment)
{
    unsigned int size;
    RTIBool overflow = RTI_FALSE;
    size = PRESTypePlugin_interpretedGetSerializedKeyMaxSizeForKeyhash(
        endpoint_data,
        &overflow,
        encapsulation_id,
        current_alignment);
    if (overflow) {
        size = RTI_CDR_MAX_SERIALIZED_SIZE;
    }

    return size;
}

RTIBool 
HelloWorldTopicQueryPlugin_instance_to_key(
    PRESTypePluginEndpointData endpoint_data,
    HelloWorldTopicQueryKeyHolder *dst, 
    const HelloWorldTopicQuery *src)
{
    if (endpoint_data) {} /* To avoid warnings */   

    if (!RTICdrType_copyLong (
        &dst->id, 
        &src->id)) { 
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

RTIBool 
HelloWorldTopicQueryPlugin_key_to_instance(
    PRESTypePluginEndpointData endpoint_data,
    HelloWorldTopicQuery *dst, const
    HelloWorldTopicQueryKeyHolder *src)
{
    if (endpoint_data) {} /* To avoid warnings */   
    if (!RTICdrType_copyLong (
        &dst->id, 
        &src->id)) { 
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

RTIBool 
HelloWorldTopicQueryPlugin_serialized_sample_to_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    DDS_KeyHash_t *keyhash,
    RTIBool deserialize_encapsulation,
    void *endpoint_plugin_qos) 
{   
    HelloWorldTopicQuery * sample = NULL;
    sample = (HelloWorldTopicQuery *)
    PRESTypePluginDefaultEndpointData_getTempSample(endpoint_data);
    if (sample == NULL) {
        return RTI_FALSE;
    }

    if (!PRESTypePlugin_interpretedSerializedSampleToKey(
        endpoint_data,
        sample,
        stream, 
        deserialize_encapsulation, 
        RTI_TRUE,
        endpoint_plugin_qos)) {
        return RTI_FALSE;
    }
    if (!PRESTypePlugin_interpretedInstanceToKeyHash(
        endpoint_data, 
        keyhash, 
        sample,
        RTICdrStream_getEncapsulationKind(stream))) {
        return RTI_FALSE;
    }
    return RTI_TRUE;
}

struct RTIXCdrInterpreterPrograms * HelloWorldTopicQueryPlugin_get_programs(void)
{
    return ::rti::xcdr::get_cdr_serialization_programs<
    HelloWorldTopicQuery, 
    true, true, true>();
}

/* ------------------------------------------------------------------------
* Plug-in Installation Methods
* ------------------------------------------------------------------------ */
struct PRESTypePlugin *HelloWorldTopicQueryPlugin_new(void) 
{ 
    struct PRESTypePlugin *plugin = NULL;
    const struct PRESTypePluginVersion PLUGIN_VERSION = 
    PRES_TYPE_PLUGIN_VERSION_2_0;

    RTIOsapiHeap_allocateStructure(
        &plugin, struct PRESTypePlugin);

    if (plugin == NULL) {
        return NULL;
    }

    plugin->version = PLUGIN_VERSION;

    /* set up parent's function pointers */
    plugin->onParticipantAttached =
    (PRESTypePluginOnParticipantAttachedCallback)
    HelloWorldTopicQueryPlugin_on_participant_attached;
    plugin->onParticipantDetached =
    (PRESTypePluginOnParticipantDetachedCallback)
    HelloWorldTopicQueryPlugin_on_participant_detached;
    plugin->onEndpointAttached =
    (PRESTypePluginOnEndpointAttachedCallback)
    HelloWorldTopicQueryPlugin_on_endpoint_attached;
    plugin->onEndpointDetached =
    (PRESTypePluginOnEndpointDetachedCallback)
    HelloWorldTopicQueryPlugin_on_endpoint_detached;

    plugin->copySampleFnc =
    (PRESTypePluginCopySampleFunction)
    HelloWorldTopicQueryPlugin_copy_sample;
    plugin->createSampleFnc =
    (PRESTypePluginCreateSampleFunction)
    HelloWorldTopicQueryPlugin_create_sample;
    plugin->destroySampleFnc =
    (PRESTypePluginDestroySampleFunction)
    HelloWorldTopicQueryPlugin_destroy_sample;
    plugin->finalizeOptionalMembersFnc =
    (PRESTypePluginFinalizeOptionalMembersFunction)
    HelloWorldTopicQueryPlugin_finalize_optional_members;

    plugin->serializeFnc = 
    (PRESTypePluginSerializeFunction) PRESTypePlugin_interpretedSerialize;
    plugin->deserializeFnc =
    (PRESTypePluginDeserializeFunction) PRESTypePlugin_interpretedDeserializeWithAlloc;
    plugin->getSerializedSampleMaxSizeFnc =
    (PRESTypePluginGetSerializedSampleMaxSizeFunction)
    HelloWorldTopicQueryPlugin_get_serialized_sample_max_size;
    plugin->getSerializedSampleMinSizeFnc =
    (PRESTypePluginGetSerializedSampleMinSizeFunction)
    PRESTypePlugin_interpretedGetSerializedSampleMinSize;
    plugin->getDeserializedSampleMaxSizeFnc = NULL; 
    plugin->getSampleFnc =
    (PRESTypePluginGetSampleFunction)
    HelloWorldTopicQueryPlugin_get_sample;
    plugin->returnSampleFnc =
    (PRESTypePluginReturnSampleFunction)
    HelloWorldTopicQueryPlugin_return_sample;
    plugin->getKeyKindFnc =
    (PRESTypePluginGetKeyKindFunction)
    HelloWorldTopicQueryPlugin_get_key_kind;

    plugin->getSerializedKeyMaxSizeFnc =   
    (PRESTypePluginGetSerializedKeyMaxSizeFunction)
    HelloWorldTopicQueryPlugin_get_serialized_key_max_size;
    plugin->serializeKeyFnc =
    (PRESTypePluginSerializeKeyFunction)
    PRESTypePlugin_interpretedSerializeKey;
    plugin->deserializeKeyFnc =
    (PRESTypePluginDeserializeKeyFunction)
    HelloWorldTopicQueryPlugin_deserialize_key;
    plugin->deserializeKeySampleFnc =
    (PRESTypePluginDeserializeKeySampleFunction)
    PRESTypePlugin_interpretedDeserializeKey;

    plugin-> instanceToKeyHashFnc = 
    (PRESTypePluginInstanceToKeyHashFunction)
    PRESTypePlugin_interpretedInstanceToKeyHash;
    plugin->serializedSampleToKeyHashFnc = 
    (PRESTypePluginSerializedSampleToKeyHashFunction)
    HelloWorldTopicQueryPlugin_serialized_sample_to_keyhash;

    plugin->getKeyFnc =
    (PRESTypePluginGetKeyFunction)
    HelloWorldTopicQueryPlugin_get_key;
    plugin->returnKeyFnc =
    (PRESTypePluginReturnKeyFunction)
    HelloWorldTopicQueryPlugin_return_key;

    plugin->instanceToKeyFnc =
    (PRESTypePluginInstanceToKeyFunction)
    HelloWorldTopicQueryPlugin_instance_to_key;
    plugin->keyToInstanceFnc =
    (PRESTypePluginKeyToInstanceFunction)
    HelloWorldTopicQueryPlugin_key_to_instance;
    plugin->serializedKeyToKeyHashFnc = NULL; /* Not supported yet */
    #ifdef NDDS_STANDALONE_TYPE
    plugin->typeCode = NULL; 
    #else
    plugin->typeCode =  (struct RTICdrTypeCode *)HelloWorldTopicQuery_get_typecode();
    #endif
    plugin->languageKind = PRES_TYPEPLUGIN_CPP_LANG;

    /* Serialized buffer */
    plugin->getBuffer = 
    (PRESTypePluginGetBufferFunction)
    HelloWorldTopicQueryPlugin_get_buffer;
    plugin->returnBuffer = 
    (PRESTypePluginReturnBufferFunction)
    HelloWorldTopicQueryPlugin_return_buffer;
    plugin->getBufferWithParams = NULL;
    plugin->returnBufferWithParams = NULL;  
    plugin->getSerializedSampleSizeFnc =
    (PRESTypePluginGetSerializedSampleSizeFunction)
    PRESTypePlugin_interpretedGetSerializedSampleSize;

    plugin->getWriterLoanedSampleFnc = NULL; 
    plugin->returnWriterLoanedSampleFnc = NULL;
    plugin->returnWriterLoanedSampleFromCookieFnc = NULL;
    plugin->validateWriterLoanedSampleFnc = NULL;
    plugin->setWriterLoanedSampleSerializedStateFnc = NULL;

    plugin->endpointTypeName = HelloWorldTopicQueryTYPENAME;
    plugin->isMetpType = RTI_FALSE;
    return plugin;
}

void
HelloWorldTopicQueryPlugin_delete(struct PRESTypePlugin *plugin)
{
    RTIOsapiHeap_freeStructure(plugin);
} 
#undef RTI_CDR_CURRENT_SUBMODULE 
