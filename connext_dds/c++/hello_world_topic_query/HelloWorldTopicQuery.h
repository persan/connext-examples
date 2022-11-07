

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from HelloWorldTopicQuery.idl
using RTI Code Generator (rtiddsgen) version 4.0.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef HelloWorldTopicQuery_1885117055_h
#define HelloWorldTopicQuery_1885117055_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#include "rti/xcdr/Interpreter.hpp"
#else
#include "ndds_standalone_type.h"
#endif

extern "C" {

    extern const char *HelloWorldTopicQueryTYPENAME;

}

struct HelloWorldTopicQuerySeq;
#ifndef NDDS_STANDALONE_TYPE
class HelloWorldTopicQueryTypeSupport;
class HelloWorldTopicQueryDataWriter;
class HelloWorldTopicQueryDataReader;
#endif
class HelloWorldTopicQuery 
{
  public:
    typedef struct HelloWorldTopicQuerySeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef HelloWorldTopicQueryTypeSupport TypeSupport;
    typedef HelloWorldTopicQueryDataWriter DataWriter;
    typedef HelloWorldTopicQueryDataReader DataReader;
    #endif

    DDS_Long   id ;
    DDS_Char *   message ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode * HelloWorldTopicQuery_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *HelloWorldTopicQuery_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *HelloWorldTopicQuery_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *HelloWorldTopicQuery_get_sample_seq_access_info(void);
#endif

DDS_SEQUENCE(HelloWorldTopicQuerySeq, HelloWorldTopicQuery);

NDDSUSERDllExport
RTIBool HelloWorldTopicQuery_initialize(
    HelloWorldTopicQuery* self);

NDDSUSERDllExport
RTIBool HelloWorldTopicQuery_initialize_ex(
    HelloWorldTopicQuery* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool HelloWorldTopicQuery_initialize_w_params(
    HelloWorldTopicQuery* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool HelloWorldTopicQuery_finalize_w_return(
    HelloWorldTopicQuery* self);

NDDSUSERDllExport
void HelloWorldTopicQuery_finalize(
    HelloWorldTopicQuery* self);

NDDSUSERDllExport
void HelloWorldTopicQuery_finalize_ex(
    HelloWorldTopicQuery* self,RTIBool deletePointers);

NDDSUSERDllExport
void HelloWorldTopicQuery_finalize_w_params(
    HelloWorldTopicQuery* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void HelloWorldTopicQuery_finalize_optional_members(
    HelloWorldTopicQuery* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool HelloWorldTopicQuery_copy(
    HelloWorldTopicQuery* dst,
    const HelloWorldTopicQuery* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#ifndef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace xcdr {
        template <>
        struct type_code<HelloWorldTopicQuery> {
            static const RTIXCdrTypeCode * get();
        };

    } 
}

#endif

#endif /* HelloWorldTopicQuery */

