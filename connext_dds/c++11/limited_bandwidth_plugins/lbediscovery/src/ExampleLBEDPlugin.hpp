

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from ExampleLBED.idl
using RTI Code Generator (rtiddsgen) version 4.0.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef ExampleLBEDPlugin_1681160520_h
#define ExampleLBEDPlugin_1681160520_h

#include "ExampleLBED.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#define ExampleLBEDPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define ExampleLBEDPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define ExampleLBEDPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define ExampleLBEDPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define ExampleLBEDPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern ExampleLBED*
ExampleLBEDPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern ExampleLBED*
ExampleLBEDPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern ExampleLBED*
ExampleLBEDPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
ExampleLBEDPluginSupport_copy_data(
    ExampleLBED *out,
    const ExampleLBED *in);

NDDSUSERDllExport extern void 
ExampleLBEDPluginSupport_destroy_data_w_params(
    ExampleLBED *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
ExampleLBEDPluginSupport_destroy_data_ex(
    ExampleLBED *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
ExampleLBEDPluginSupport_destroy_data(
    ExampleLBED *sample);

NDDSUSERDllExport extern void 
ExampleLBEDPluginSupport_print_data(
    const ExampleLBED *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
ExampleLBEDPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
ExampleLBEDPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
ExampleLBEDPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
ExampleLBEDPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
ExampleLBEDPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    ExampleLBED *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
ExampleLBEDPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    ExampleLBED *out,
    const ExampleLBED *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
ExampleLBEDPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const ExampleLBED *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
ExampleLBEDPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    ExampleLBED **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
ExampleLBEDPlugin_deserialize_from_cdr_buffer(
    ExampleLBED *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
ExampleLBEDPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
ExampleLBEDPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
ExampleLBEDPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
ExampleLBEDPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
ExampleLBEDPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    ExampleLBED ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
ExampleLBEDPlugin_new(void);

NDDSUSERDllExport extern void
ExampleLBEDPlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* ExampleLBEDPlugin_1681160520_h */

