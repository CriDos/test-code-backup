

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0361 */
/* at Tue Jun 14 14:22:45 2011
 */
/* Compiler settings for .\Simple4.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IMathe,0xA413CA85,0xAF88,0x40A8,0x9C,0x29,0x5A,0x5A,0xD4,0x67,0x01,0x4A);


MIDL_DEFINE_GUID(IID, IID_IStr,0xA413CA86,0xAF88,0x40A8,0x9C,0x29,0x5A,0x5A,0xD4,0x67,0x01,0x4A);


MIDL_DEFINE_GUID(IID, IID_IMathe2,0xA413CA87,0xAF88,0x40A8,0x9C,0x29,0x5A,0x5A,0xD4,0x67,0x01,0x4A);


MIDL_DEFINE_GUID(IID, LIBID_Simple4Lib,0x97A1EA92,0xD241,0x4189,0x8B,0xBB,0x38,0xD9,0x5E,0x79,0xEA,0x8E);


MIDL_DEFINE_GUID(CLSID, CLSID_Mathe,0x0D8C856B,0x00CF,0x4F84,0xBC,0xC3,0xB8,0x55,0x56,0x2D,0x87,0x72);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

