// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME ExpEventDictionary

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "/afs/crc.nd.edu/group/nsl/rms/user/lmorale1/software/evt2root_sab/ExpEvent/include/eventData.h"
#include "/afs/crc.nd.edu/group/nsl/rms/user/lmorale1/software/evt2root_sab/ExpEvent/include/eventScaler.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_eventScaler(void *p = 0);
   static void *newArray_eventScaler(Long_t size, void *p);
   static void delete_eventScaler(void *p);
   static void deleteArray_eventScaler(void *p);
   static void destruct_eventScaler(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::eventScaler*)
   {
      ::eventScaler *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::eventScaler >(0);
      static ::ROOT::TGenericClassInfo 
         instance("eventScaler", ::eventScaler::Class_Version(), "eventScaler.h", 8,
                  typeid(::eventScaler), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::eventScaler::Dictionary, isa_proxy, 4,
                  sizeof(::eventScaler) );
      instance.SetNew(&new_eventScaler);
      instance.SetNewArray(&newArray_eventScaler);
      instance.SetDelete(&delete_eventScaler);
      instance.SetDeleteArray(&deleteArray_eventScaler);
      instance.SetDestructor(&destruct_eventScaler);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::eventScaler*)
   {
      return GenerateInitInstanceLocal((::eventScaler*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::eventScaler*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_eventData(void *p = 0);
   static void *newArray_eventData(Long_t size, void *p);
   static void delete_eventData(void *p);
   static void deleteArray_eventData(void *p);
   static void destruct_eventData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::eventData*)
   {
      ::eventData *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::eventData >(0);
      static ::ROOT::TGenericClassInfo 
         instance("eventData", ::eventData::Class_Version(), "eventData.h", 11,
                  typeid(::eventData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::eventData::Dictionary, isa_proxy, 4,
                  sizeof(::eventData) );
      instance.SetNew(&new_eventData);
      instance.SetNewArray(&newArray_eventData);
      instance.SetDelete(&delete_eventData);
      instance.SetDeleteArray(&deleteArray_eventData);
      instance.SetDestructor(&destruct_eventData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::eventData*)
   {
      return GenerateInitInstanceLocal((::eventData*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::eventData*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr eventScaler::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *eventScaler::Class_Name()
{
   return "eventScaler";
}

//______________________________________________________________________________
const char *eventScaler::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::eventScaler*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int eventScaler::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::eventScaler*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *eventScaler::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::eventScaler*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *eventScaler::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::eventScaler*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr eventData::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *eventData::Class_Name()
{
   return "eventData";
}

//______________________________________________________________________________
const char *eventData::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::eventData*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int eventData::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::eventData*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *eventData::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::eventData*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *eventData::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::eventData*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void eventScaler::Streamer(TBuffer &R__b)
{
   // Stream an object of class eventScaler.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(eventScaler::Class(),this);
   } else {
      R__b.WriteClassBuffer(eventScaler::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_eventScaler(void *p) {
      return  p ? new(p) ::eventScaler : new ::eventScaler;
   }
   static void *newArray_eventScaler(Long_t nElements, void *p) {
      return p ? new(p) ::eventScaler[nElements] : new ::eventScaler[nElements];
   }
   // Wrapper around operator delete
   static void delete_eventScaler(void *p) {
      delete ((::eventScaler*)p);
   }
   static void deleteArray_eventScaler(void *p) {
      delete [] ((::eventScaler*)p);
   }
   static void destruct_eventScaler(void *p) {
      typedef ::eventScaler current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::eventScaler

//______________________________________________________________________________
void eventData::Streamer(TBuffer &R__b)
{
   // Stream an object of class eventData.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(eventData::Class(),this);
   } else {
      R__b.WriteClassBuffer(eventData::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_eventData(void *p) {
      return  p ? new(p) ::eventData : new ::eventData;
   }
   static void *newArray_eventData(Long_t nElements, void *p) {
      return p ? new(p) ::eventData[nElements] : new ::eventData[nElements];
   }
   // Wrapper around operator delete
   static void delete_eventData(void *p) {
      delete ((::eventData*)p);
   }
   static void deleteArray_eventData(void *p) {
      delete [] ((::eventData*)p);
   }
   static void destruct_eventData(void *p) {
      typedef ::eventData current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::eventData

namespace {
  void TriggerDictionaryInitialization_ExpEventDictionary_Impl() {
    static const char* headers[] = {
"/afs/crc.nd.edu/group/nsl/rms/user/lmorale1/software/evt2root_sab/ExpEvent/include/eventData.h",
"/afs/crc.nd.edu/group/nsl/rms/user/lmorale1/software/evt2root_sab/ExpEvent/include/eventScaler.h",
0
    };
    static const char* includePaths[] = {
"/afs/crc.nd.edu/user/n/nsl/nuclear/x86_64_linux_el6/install/root_v6.06.06/include",
"/afs/crc.nd.edu/group/nsl/rms/user/lmorale1/software/evt2root_sab/ExpEvent/include",
"/afs/crc.nd.edu/group/nsl/rms/user/lmorale1/software/evt2root_sab/ExpEvent/include",
"/afs/crc.nd.edu/user/n/nsl/nuclear/x86_64_linux_el6/install/root_v6.06.06/include",
"/afs/crc.nd.edu/group/nsl/rms/user/lmorale1/software/evt2root_sab/exec/ExpEvent/src/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "ExpEventDictionary dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate("$clingAutoload$/afs/crc.nd.edu/group/nsl/rms/user/lmorale1/software/evt2root_sab/ExpEvent/include/eventScaler.h")))  eventScaler;
class __attribute__((annotate("$clingAutoload$/afs/crc.nd.edu/group/nsl/rms/user/lmorale1/software/evt2root_sab/ExpEvent/include/eventData.h")))  eventData;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "ExpEventDictionary dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "/afs/crc.nd.edu/group/nsl/rms/user/lmorale1/software/evt2root_sab/ExpEvent/include/eventData.h"
#include "/afs/crc.nd.edu/group/nsl/rms/user/lmorale1/software/evt2root_sab/ExpEvent/include/eventScaler.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"eventData", payloadCode, "@",
"eventScaler", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("ExpEventDictionary",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_ExpEventDictionary_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_ExpEventDictionary_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_ExpEventDictionary() {
  TriggerDictionaryInitialization_ExpEventDictionary_Impl();
}
