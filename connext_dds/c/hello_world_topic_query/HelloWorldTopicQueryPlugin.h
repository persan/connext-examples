

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorldTopicQuery.idl
using RTI Code Generator (rtiddsgen) version 4.0.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef HelloWorldTopicQueryPlugin_1885117055_h
#define HelloWorldTopicQueryPlugin_1885117055_h

#include "HelloWorldTopicQuery.h"

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

#ifdef __cplusplus
extern "C" {
    #endif

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct HelloWorldTopicQuery
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct HelloWorldTopicQuery)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * HelloWorldTopicQuery must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct HelloWorldTopicQuery.
    */
    typedef  struct HelloWorldTopicQuery HelloWorldTopicQueryKeyHolder;

    #define HelloWorldTopicQueryPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 

    #define HelloWorldTopicQueryPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define HelloWorldTopicQueryPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define HelloWorldTopicQueryPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define HelloWorldTopicQueryPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define HelloWorldTopicQueryPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define HelloWorldTopicQueryPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern HelloWorldTopicQuery*
    HelloWorldTopicQueryPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern HelloWorldTopicQuery*
    HelloWorldTopicQueryPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern HelloWorldTopicQuery*
    HelloWorldTopicQueryPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    HelloWorldTopicQueryPluginSupport_copy_data(
        HelloWorldTopicQuery *out,
        const HelloWorldTopicQuery *in);

    NDDSUSERDllExport extern void 
    HelloWorldTopicQueryPluginSupport_destroy_data_w_params(
        HelloWorldTopicQuery *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    HelloWorldTopicQueryPluginSupport_destroy_data_ex(
        HelloWorldTopicQuery *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    HelloWorldTopicQueryPluginSupport_destroy_data(
        HelloWorldTopicQuery *sample);

    NDDSUSERDllExport extern void 
    HelloWorldTopicQueryPluginSupport_print_data(
        const HelloWorldTopicQuery *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern HelloWorldTopicQuery*
    HelloWorldTopicQueryPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern HelloWorldTopicQuery*
    HelloWorldTopicQueryPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    HelloWorldTopicQueryPluginSupport_destroy_key_ex(
        HelloWorldTopicQueryKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    HelloWorldTopicQueryPluginSupport_destroy_key(
        HelloWorldTopicQueryKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    HelloWorldTopicQueryPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    HelloWorldTopicQueryPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    HelloWorldTopicQueryPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    HelloWorldTopicQueryPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    HelloWorldTopicQueryPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        HelloWorldTopicQuery *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    HelloWorldTopicQueryPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        HelloWorldTopicQuery *out,
        const HelloWorldTopicQuery *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    HelloWorldTopicQueryPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const HelloWorldTopicQuery *sample); 

    NDDSUSERDllExport extern RTIBool
    HelloWorldTopicQueryPlugin_serialize_to_cdr_buffer_ex(
        char *buffer,
        unsigned int *length,
        const HelloWorldTopicQuery *sample,
        DDS_DataRepresentationId_t representation);

    NDDSUSERDllExport extern RTIBool
    HelloWorldTopicQueryPlugin_deserialize_from_cdr_buffer(
        HelloWorldTopicQuery *sample,
        const char * buffer,
        unsigned int length);    
    #if !defined (NDDS_STANDALONE_TYPE)
    NDDSUSERDllExport extern DDS_ReturnCode_t
    HelloWorldTopicQueryPlugin_data_to_string(
        const HelloWorldTopicQuery *sample,
        char *str,
        DDS_UnsignedLong *str_size, 
        const struct DDS_PrintFormatProperty *property);    
    #endif

    NDDSUSERDllExport extern unsigned int 
    HelloWorldTopicQueryPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    HelloWorldTopicQueryPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    HelloWorldTopicQueryPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    HelloWorldTopicQueryPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    HelloWorldTopicQueryPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        HelloWorldTopicQuery ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    HelloWorldTopicQueryPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        HelloWorldTopicQueryKeyHolder *key, 
        const HelloWorldTopicQuery *instance);

    NDDSUSERDllExport extern RTIBool 
    HelloWorldTopicQueryPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        HelloWorldTopicQuery *instance, 
        const HelloWorldTopicQueryKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    HelloWorldTopicQueryPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    NDDSUSERDllExport extern
    struct RTIXCdrInterpreterPrograms * HelloWorldTopicQueryPlugin_get_programs(void);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    HelloWorldTopicQueryPlugin_new(void);

    NDDSUSERDllExport extern void
    HelloWorldTopicQueryPlugin_delete(struct PRESTypePlugin *);

    #ifdef __cplusplus
}
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* HelloWorldTopicQueryPlugin_1885117055_h */

