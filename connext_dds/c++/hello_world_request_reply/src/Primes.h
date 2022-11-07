

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from Primes.idl
using RTI Code Generator (rtiddsgen) version 4.0.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef Primes_831781118_h
#define Primes_831781118_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_cpp_h
#include "ndds/ndds_cpp.h"
#endif
#include "rti/xcdr/Interpreter.hpp"
#else
#include "ndds_standalone_type.h"
#endif

extern "C" {

    extern const char *PrimeNumberRequestTYPENAME;

}

struct PrimeNumberRequestSeq;
#ifndef NDDS_STANDALONE_TYPE
class PrimeNumberRequestTypeSupport;
class PrimeNumberRequestDataWriter;
class PrimeNumberRequestDataReader;
#endif
class PrimeNumberRequest 
{
  public:
    typedef struct PrimeNumberRequestSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef PrimeNumberRequestTypeSupport TypeSupport;
    typedef PrimeNumberRequestDataWriter DataWriter;
    typedef PrimeNumberRequestDataReader DataReader;
    #endif

    DDS_Long   n ;
    DDS_Long   primes_per_reply ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode * PrimeNumberRequest_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *PrimeNumberRequest_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *PrimeNumberRequest_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *PrimeNumberRequest_get_sample_seq_access_info(void);
#endif

DDS_SEQUENCE(PrimeNumberRequestSeq, PrimeNumberRequest);

NDDSUSERDllExport
RTIBool PrimeNumberRequest_initialize(
    PrimeNumberRequest* self);

NDDSUSERDllExport
RTIBool PrimeNumberRequest_initialize_ex(
    PrimeNumberRequest* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool PrimeNumberRequest_initialize_w_params(
    PrimeNumberRequest* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool PrimeNumberRequest_finalize_w_return(
    PrimeNumberRequest* self);

NDDSUSERDllExport
void PrimeNumberRequest_finalize(
    PrimeNumberRequest* self);

NDDSUSERDllExport
void PrimeNumberRequest_finalize_ex(
    PrimeNumberRequest* self,RTIBool deletePointers);

NDDSUSERDllExport
void PrimeNumberRequest_finalize_w_params(
    PrimeNumberRequest* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void PrimeNumberRequest_finalize_optional_members(
    PrimeNumberRequest* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool PrimeNumberRequest_copy(
    PrimeNumberRequest* dst,
    const PrimeNumberRequest* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

static const DDS_Long PRIME_SEQUENCE_MAX_LENGTH= 1024L;
typedef enum PrimeNumberCalculationStatus
{
    REPLY_IN_PROGRESS , 
    REPLY_COMPLETED , 
    REPLY_ERROR 
} PrimeNumberCalculationStatus;
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode * PrimeNumberCalculationStatus_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *PrimeNumberCalculationStatus_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *PrimeNumberCalculationStatus_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *PrimeNumberCalculationStatus_get_sample_seq_access_info(void);
#endif

DDS_SEQUENCE(PrimeNumberCalculationStatusSeq, PrimeNumberCalculationStatus);

NDDSUSERDllExport
RTIBool PrimeNumberCalculationStatus_initialize(
    PrimeNumberCalculationStatus* self);

NDDSUSERDllExport
RTIBool PrimeNumberCalculationStatus_initialize_ex(
    PrimeNumberCalculationStatus* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool PrimeNumberCalculationStatus_initialize_w_params(
    PrimeNumberCalculationStatus* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool PrimeNumberCalculationStatus_finalize_w_return(
    PrimeNumberCalculationStatus* self);

NDDSUSERDllExport
void PrimeNumberCalculationStatus_finalize(
    PrimeNumberCalculationStatus* self);

NDDSUSERDllExport
void PrimeNumberCalculationStatus_finalize_ex(
    PrimeNumberCalculationStatus* self,RTIBool deletePointers);

NDDSUSERDllExport
void PrimeNumberCalculationStatus_finalize_w_params(
    PrimeNumberCalculationStatus* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void PrimeNumberCalculationStatus_finalize_optional_members(
    PrimeNumberCalculationStatus* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool PrimeNumberCalculationStatus_copy(
    PrimeNumberCalculationStatus* dst,
    const PrimeNumberCalculationStatus* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

extern "C" {

    extern const char *PrimeNumberReplyTYPENAME;

}

struct PrimeNumberReplySeq;
#ifndef NDDS_STANDALONE_TYPE
class PrimeNumberReplyTypeSupport;
class PrimeNumberReplyDataWriter;
class PrimeNumberReplyDataReader;
#endif
class PrimeNumberReply 
{
  public:
    typedef struct PrimeNumberReplySeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef PrimeNumberReplyTypeSupport TypeSupport;
    typedef PrimeNumberReplyDataWriter DataWriter;
    typedef PrimeNumberReplyDataReader DataReader;
    #endif

    DDS_LongSeq  primes ;
    PrimeNumberCalculationStatus   status ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode * PrimeNumberReply_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *PrimeNumberReply_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *PrimeNumberReply_get_sample_access_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *PrimeNumberReply_get_sample_seq_access_info(void);
#endif

DDS_SEQUENCE(PrimeNumberReplySeq, PrimeNumberReply);

NDDSUSERDllExport
RTIBool PrimeNumberReply_initialize(
    PrimeNumberReply* self);

NDDSUSERDllExport
RTIBool PrimeNumberReply_initialize_ex(
    PrimeNumberReply* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool PrimeNumberReply_initialize_w_params(
    PrimeNumberReply* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool PrimeNumberReply_finalize_w_return(
    PrimeNumberReply* self);

NDDSUSERDllExport
void PrimeNumberReply_finalize(
    PrimeNumberReply* self);

NDDSUSERDllExport
void PrimeNumberReply_finalize_ex(
    PrimeNumberReply* self,RTIBool deletePointers);

NDDSUSERDllExport
void PrimeNumberReply_finalize_w_params(
    PrimeNumberReply* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void PrimeNumberReply_finalize_optional_members(
    PrimeNumberReply* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool PrimeNumberReply_copy(
    PrimeNumberReply* dst,
    const PrimeNumberReply* src);

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
        struct type_code<PrimeNumberRequest> {
            static const RTIXCdrTypeCode * get();
        };

        template <>
        struct type_code<PrimeNumberReply> {
            static const RTIXCdrTypeCode * get();
        };

    } 
}

#endif

#endif /* Primes */

