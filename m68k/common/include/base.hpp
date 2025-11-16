/****************************************************************************
**																			**
**																			**
**									m68k									**
**																			**
**	'm68k/base.hpp'									2025 written by int71	**
 ****************************************************************************/
#ifndef M68K_BASE
#define M68K_BASE

//
//		primitive
//

#ifndef AUTO
#define AUTO			auto
#define CAUTO			const auto
constexpr AUTO			NULL=nullptr;
//	VOID
using					VOID=void;
using					CVOID=const VOID;
using					PVOID=VOID*;
using					PCVOID=CVOID*;
//	OFWBOOL
using					OFWBOOL=bool;
using					COFWBOOL=const OFWBOOL;
using					POFWBOOL=OFWBOOL*;
using					PCOFWBOOL=COFWBOOL*;
constexpr AUTO			FALSE=OFWBOOL(false);
constexpr AUTO			TRUE=OFWBOOL(true);
//	INT8
using					INT8=char;
using					CINT8=const INT8;
using					PINT8=INT8*;
using					PCINT8=CINT8*;
//	UINT8
using					UINT8=unsigned char;
using					CUINT8=const UINT8;
using					PUINT8=UINT8*;
using					PCUINT8=CUINT8*;
//	INT16
using					INT16=short;
using					CINT16=const INT16;
using					PINT16=INT16*;
using					PCINT16=CINT16*;
//	UINT16
using					UINT16=unsigned short;
using					CUINT16=const UINT16;
using					PUINT16=UINT16*;
using					PCUINT16=CUINT16*;
//	INT32
using					INT32=long;
using					CINT32=const INT32;
using					PINT32=INT32*;
using					PCINT32=CINT32*;
//	UINT32
using					UINT32=unsigned long;
using					CUINT32=const UINT32;
using					PUINT32=UINT32*;
using					PCUINT32=CUINT32*;
//	INT
using					INT=int;
using					CINT=const INT;
using					PCINT=CINT*;
//	UINT
using					UINT=unsigned int;
using					CUINT=const UINT;
using					PUINT=UINT*;
using					PCUINT=CUINT*;
//	BYTE
using					BYTE=UINT8;
using					CBYTE=const BYTE;
using					PBYTE=BYTE*;
using					PCBYTE=CBYTE*;
//	WORD
using					WORD=UINT16;
using					CWORD=const WORD;
using					PWORD=WORD*;
using					PCWORD=CWORD*;
//	DWORD
using					DWORD=UINT32;
using					CDWORD=const DWORD;
using					PDWORD=DWORD*;
using					PCDWORD=CDWORD*;
//	SJIS
using					SJIS=char;
using					CSJIS=const SJIS;
using					PSJIS=SJIS*;
using					PCSJIS=CSJIS*;
//	USTR
using					USTR=SJIS;
using					CUSTR=const USTR;
using					PUSTR=USTR*;
using					PCUSTR=CUSTR*;
#endif

#endif
