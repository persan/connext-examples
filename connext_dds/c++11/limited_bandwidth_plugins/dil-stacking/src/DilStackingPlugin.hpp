

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from DilStacking.idl
using RTI Code Generator (rtiddsgen) version 4.0.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef DilStackingPlugin_586274562_h
#define DilStackingPlugin_586274562_h

#include "DilStacking.hpp"

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

#define DilStackingPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

#define DilStackingPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define DilStackingPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

#define DilStackingPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define DilStackingPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern DilStacking*
DilStackingPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern DilStacking*
DilStackingPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern DilStacking*
DilStackingPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
DilStackingPluginSupport_copy_data(
    DilStacking *out,
    const DilStacking *in);

NDDSUSERDllExport extern void 
DilStackingPluginSupport_destroy_data_w_params(
    DilStacking *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
DilStackingPluginSupport_destroy_data_ex(
    DilStacking *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
DilStackingPluginSupport_destroy_data(
    DilStacking *sample);

NDDSUSERDllExport extern void 
DilStackingPluginSupport_print_data(
    const DilStacking *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
DilStackingPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
DilStackingPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
DilStackingPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
DilStackingPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
DilStackingPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    DilStacking *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
DilStackingPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    DilStacking *out,
    const DilStacking *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool
DilStackingPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const DilStacking *sample,
    ::dds::core::policy::DataRepresentationId representation
    = ::dds::core::policy::DataRepresentation::xcdr()); 

NDDSUSERDllExport extern RTIBool 
DilStackingPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    DilStacking **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
DilStackingPlugin_deserialize_from_cdr_buffer(
    DilStacking *sample,
    const char * buffer,
    unsigned int length);    

NDDSUSERDllExport extern unsigned int 
DilStackingPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
DilStackingPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
DilStackingPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
DilStackingPlugin_get_serialized_key_max_size_for_keyhash(
    PRESTypePluginEndpointData endpoint_data,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
DilStackingPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    DilStacking ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
DilStackingPlugin_new(void);

NDDSUSERDllExport extern void
DilStackingPlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* DilStackingPlugin_586274562_h */

