/****************************************************************************
**																			**
**																			**
**									m68k									**
**																			**
**	'm68k/ofw/std/std.hpp'							2026 written by int71	**
 ****************************************************************************/
#ifndef M68K_OFW_STD_STD
#define M68K_OFW_STD_STD

//
//		include
//

#include				<base.hpp>

//
//		macro
//

#define _ALIGN1_		alignas(1)
#define _ALIGN2_		alignas(2)
#define _ALIGN4_		alignas(4)
#define _ALIGN8_		alignas(8)
#define _ALIGN16_		alignas(16)
#define _ALIGN32_		alignas(32)
#define _INLINE_		inline
#define _UNDISCARDABLE_	volatile
#define _VECTOR_		_UNDISCARDABLE_ __attribute__((section(".vector")))
#define _IO_			_UNDISCARDABLE_ __attribute__((section(".io")))
#define _ORDERED_(ID)	_UNDISCARDABLE_ __attribute__((section(".ordered." ID)))
#ifdef __clang__
#define _HANDLER_		__attribute__((interrupt(0)))
#else
#define _HANDLER_		__attribute__((interrupt))
#endif
#define _STD_			extern "C"
#define _NORETURN_		void __attribute__((noreturn))
#ifdef __clang__
#define _PADDING_BEGIN_	_Pragma("GCC diagnostic ignored \"-Wunused-private-field\"")
#define _PADDING_END_	_Pragma("GCC diagnostic warning \"-Wunused-private-field\"")
#define _PARTIALSWITCH_BEGIN_	_Pragma("GCC diagnostic ignored \"-Wswitch\"")
#define _PARTIALSWITCH_END_	_Pragma("GCC diagnostic warning \"-Wswitch\"")
#else
#define _PADDING_BEGIN_
#define _PADDING_END_
#define _PARTIALSWITCH_BEGIN_
#define _PARTIALSWITCH_END_
#endif
#define ASM				__asm__ _UNDISCARDABLE_
#define FALLTHROUGH		[[fallthrough]]
#define NEVER			__builtin_unreachable()
#define BARRIER			ASM("":::"memory")
#define ASSERT(cecondition,acustrerrormessage)	static_assert(cecondition,"[ASSERT]" acustrerrormessage)
#define SIZEOF(DECL)	OFWSIZE(sizeof(DECL))
#define OFFSETOF(CLASS,member)	_OFFSETOF::BODY(&CLASS::member)
#define ISCONSTEVAL		OFWBOOL(__builtin_is_constant_evaluated())

//
//		primitive
//

//	OFWSIZE
using					OFWSIZE=unsigned long;
using					COFWSIZE=const OFWSIZE;
using					POFWSIZE=OFWSIZE*;
using					PCOFWSIZE=COFWSIZE*;
//	PTRINT
using					PTRINT=DWORD;
using					CPTRINT=const PTRINT;
using					PPTRINT=PTRINT*;
using					PCPTRINT=CPTRINT*;
//	ENDIAN
enum class IDENDIAN:BYTE{
	Little,
	Big,
	Native=Big
};

//
//		class
//

//	OFFSETOF
namespace _OFFSETOF{
	template<class MCLASS,class CLASS>
	class BODY_Body{
	public:

		//
		//		class
		//

		union MEMBER;

		//
		//		class:MEMBER
		//

		union MEMBER{
			UINT8					aui8Body[SIZEOF(CLASS)];
			CLASS					xBody;
		};

		//
		//		body:private_OFFSETOF_Body
		//

	public:
		static MEMBER			stmmbrThis;
	public:
		static constexpr OFWSIZE	stszdGetOffset(MCLASS CLASS::*member)noexcept{
			for(OFWSIZE szdoffset=0;szdoffset<SIZEOF(CLASS);++szdoffset)if(
				PVOID(stmmbrThis.aui8Body+szdoffset)==&(stmmbrThis.xBody.*member)
			)return szdoffset;
			return SIZEOF(CLASS);
		}
	};
	template<class MCLASS,class CLASS>
	constexpr OFWSIZE		BODY(MCLASS CLASS::*member)noexcept{
		return BODY_Body<MCLASS,CLASS>::stszdGetOffset(member);
	}
}
//	INT16HL
union INT16HL;
using					CINT16HL=const INT16HL;
using					PINT16HL=INT16HL*;
using					PCINT16HL=CINT16HL*;
//	UINT16HL
union UINT16HL;
using					CUINT16HL=const UINT16HL;
using					PUINT16HL=UINT16HL*;
using					PCUINT16HL=CUINT16HL*;
//	INT32HL
union INT32HL;
using					CINT32HL=const INT32HL;
using					PINT32HL=INT32HL*;
using					PCINT32HL=CINT32HL*;
//	UINT32HL
union UINT32HL;
using					CUINT32HL=const UINT32HL;
using					PUINT32HL=UINT32HL*;
using					PCUINT32HL=CUINT32HL*;

//
//		std
//

_STD_ PVOID 			memset(const PVOID cpdestination,CINT cisource,COFWSIZE cszndestination)noexcept;
_STD_ PVOID 			memcpy(const PVOID cpdestination,const PCVOID cpcsource,COFWSIZE csznsource)noexcept;
_STD_ PVOID 			memmove(const PVOID cpdestination,const PCVOID cpcsource,COFWSIZE csznsource)noexcept;

//
//		class:INT16HL
//

union INT16HL{
public:
	INT16					i16HL;
	class{
	public:
		INT8					i8H;
		INT8					i8L;
	};
public:
	_INLINE_ /*VOID*/		INT16HL(VOID)noexcept{}
	constexpr /*VOID*/		INT16HL(CINT16 ci16hl)noexcept:
		i16HL(ci16hl)
	{}
	constexpr /*VOID*/		INT16HL(CINT8 ci8h,CINT8 ci8l)noexcept:
		i8H(ci8h),
		i8L(ci8l)
	{}
};

//
//		class:UINT16HL
//

union UINT16HL{
public:
	UINT16					ui16HL;
	class{
	public:
		UINT8					ui8H;
		UINT8					ui8L;
	};
public:
	_INLINE_ /*VOID*/		UINT16HL(VOID)noexcept{}
	constexpr /*VOID*/		UINT16HL(CUINT16 cui16hl)noexcept:
		ui16HL(cui16hl)
	{}
	constexpr /*VOID*/		UINT16HL(CUINT8 cui8h,CUINT8 cui8l)noexcept:
		ui8H(cui8h),
		ui8L(cui8l)
	{}
};

//
//		class:INT32HL
//

union INT32HL{
public:
	INT32					i32HL;
	class{
	public:
		INT16					i16H;
		INT16					i16L;
	};
public:
	_INLINE_ /*VOID*/		INT32HL(VOID)noexcept{}
	constexpr /*VOID*/		INT32HL(CINT32 ci32hl)noexcept:
		i32HL(ci32hl)
	{}
	constexpr /*VOID*/		INT32HL(CINT16 ci16h,CINT16 ci16l)noexcept:
		i16H(ci16h),
		i16L(ci16l)
	{}
};

//
//		class:UINT32HL
//

union UINT32HL{
public:
	UINT32					ui32HL;
	class{
	public:
		UINT16					ui16H;
		UINT16					ui16L;
	};
public:
	_INLINE_ /*VOID*/		UINT32HL(VOID)noexcept{}
	constexpr /*VOID*/		UINT32HL(CUINT32 cui32hl)noexcept:
		ui32HL(cui32hl)
	{}
	constexpr /*VOID*/		UINT32HL(CUINT16 cui16h,CUINT16 cui16l)noexcept:
		ui16H(cui16h),
		ui16L(cui16l)
	{}
};

//
//		namespace:m68k
//

namespace m68k::ofw{

	//
	//		helper
	//

	//
	//		helper:STD
	//

	//	STD
	//		クラス初期化操作は不要で、各種機能は直接呼び出せます。
	class STD{
	public:
		//	OFWBOOL					steGetLSB(const CLASS& cxsource)
		//		整数型「cxsource」のLSB(最下位ビット)を「OFWBOOL」で返します。
		template<class CLASS>
		static constexpr OFWBOOL	steGetLSB(const CLASS& cxsource)noexcept{
			return OFWBOOL(cxsource&CLASS(1));
		}
		//	OFWBOOL					steGetMSB(const CLASS& cxsource)
		//		整数型「cxsource」のMSB(最上位ビット)を「OFWBOOL」で返します。
		//		符号付き型であれば「TRUE」時にマイナス、という事です。
		template<class CLASS>
		static constexpr OFWBOOL	steGetMSB(const CLASS& cxsource)noexcept{
			return OFWBOOL(cxsource&(CLASS(CLASS(1)<<((SIZEOF(CLASS)<<3)-1))));
		}
		//	OFWSIZE					stszGetMinimumLargerPower2(COFWSIZE csznsource)
		//		「csznsource」以上である、最小の2の累乗値を返します。
		static constexpr OFWSIZE	stszGetMinimumLargerPower2(COFWSIZE csznsource)noexcept{
			return OFWSIZE(stdwGetMinimumLargerPower2(DWORD(csznsource)));
		}
		//	DWORD					stdwGetMinimumLargerPower2(CDWORD cdwnsource)
		//		「cdwnsource」以上である、最小の2の累乗値を返します。
		static constexpr DWORD	stdwGetMinimumLargerPower2(CDWORD cdwnsource)noexcept{
			AUTO					dwnsource=cdwnsource;

			--dwnsource;
			dwnsource|=(dwnsource>>1);
			dwnsource|=(dwnsource>>2);
			dwnsource|=(dwnsource>>4);
			dwnsource|=(dwnsource>>8);
			dwnsource|=(dwnsource>>16);
			return dwnsource+1;
		}
		//	OFWSIZE					stszGetMaximumSmallerPower2(COFWSIZE csznsource)
		//		「csznsource」以下である、最大の2の累乗値を返します。
		static constexpr OFWSIZE	stszGetMaximumSmallerPower2(COFWSIZE csznsource)noexcept{
			return OFWSIZE(stdwGetMaximumSmallerPower2(DWORD(csznsource)));
		}
		//	DWORD					stdwGetMaximumSmallerPower2(CDWORD cdwnsource)
		//		「cdwnsource」以下である、最大の2の累乗値を返します。
		static constexpr DWORD	stdwGetMaximumSmallerPower2(CDWORD cdwnsource)noexcept{
			AUTO					dwnsource=cdwnsource>>1;

			dwnsource|=(dwnsource>>1);
			dwnsource|=(dwnsource>>2);
			dwnsource|=(dwnsource>>4);
			dwnsource|=(dwnsource>>8);
			dwnsource|=(dwnsource>>16);
			return cdwnsource&(~dwnsource);
		}
		//	WORD					stwSwitchEndian(CWORD cwsource)
		//		「cwsource」のバイトオーダ反転値を返します。
		static constexpr WORD	stwSwitchEndian(CWORD cwsource)noexcept{
			return
				+((cwsource<< 8)&0xff00)
				+((cwsource>> 8)&0x00ff);
		}
		//	WORD					stwSwitchEndianL(CWORD cwsource)
		//		プロセッサネイティブのエンディアンがリトル時は「cwsource」そのままの値を、
		//		ビッグ時は「cwsource」のバイトオーダ反転値を返します。
		static constexpr WORD	stwSwitchEndianL(CWORD cwsource)noexcept{
			if constexpr(IDENDIAN::Native==IDENDIAN::Little)return cwsource;
			else return stwSwitchEndian(cwsource);
		}
		//	WORD					stwSwitchEndianB(CWORD cwsource)
		//		プロセッサネイティブのエンディアンがリトル時は「cwsource」のバイトオーダ反転値を、
		//		ビッグ時は「cwsource」そのままの値を返します。
		static constexpr WORD	stwSwitchEndianB(CWORD cwsource)noexcept{
			if constexpr(IDENDIAN::Native==IDENDIAN::Little)return stwSwitchEndian(cwsource);
			else return cwsource;
		}
		//	DWORD					stdwSwitchEndian(CDWORD cdwsource)
		//		「cdwsource」のバイトオーダ反転値を返します。
		static constexpr DWORD	stdwSwitchEndian(CDWORD cdwsource)noexcept{
			return
				+((cdwsource<<24)&0xff000000)
				+((cdwsource<< 8)&0x00ff0000)
				+((cdwsource>> 8)&0x0000ff00)
				+((cdwsource>>24)&0x000000ff);
		}
		//	DWORD					stdwSwitchEndianL(CDWORD cdwsource)
		//		プロセッサネイティブのエンディアンがリトル時は「cdwsource」そのままの値を、
		//		ビッグ時は「cdwsource」のバイトオーダ反転値を返します。
		static constexpr DWORD	stdwSwitchEndianL(CDWORD cdwsource)noexcept{
			if constexpr(IDENDIAN::Native==IDENDIAN::Little)return cdwsource;
			else return stdwSwitchEndian(cdwsource);
		}
		//	DWORD					stdwSwitchEndianB(CDWORD cdwsource)
		//		プロセッサネイティブのエンディアンがリトル時は「cdwsource」のバイトオーダ反転値を、
		//		ビッグ時は「cdwsource」そのままの値を返します。
		static constexpr DWORD	stdwSwitchEndianB(CDWORD cdwsource)noexcept{
			if constexpr(IDENDIAN::Native==IDENDIAN::Little)return stdwSwitchEndian(cdwsource);
			else return cdwsource;
		}
		//	CLASS					stxSwitchEndian(const CLASS& cxsource)
		//		「cxsource」のバイトオーダ反転値を返します。
		template<class CLASS>
		static constexpr CLASS	stxSwitchEndian(const CLASS& cxsource)noexcept{
			if constexpr(SIZEOF(CLASS)==2){
				return CLASS(stwSwitchEndian(WORD(cxsource)));
			}else if constexpr(SIZEOF(CLASS)==4){
				return CLASS(stdwSwitchEndian(DWORD(cxsource)));
			}else{
				return cxsource;
			}
		}
		//	CLASS					stxSwitchEndianL(const CLASS& cxsource)
		//		プロセッサネイティブのエンディアンがリトル時は「cxsource」そのままの値を、
		//		ビッグ時は「cxsource」のバイトオーダ反転値を返します。
		template<class CLASS>
		static constexpr CLASS	stxSwitchEndianL(const CLASS& cxsource)noexcept{
			if constexpr(SIZEOF(CLASS)==2){
				return CLASS(stwSwitchEndianL(WORD(cxsource)));
			}else if constexpr(SIZEOF(CLASS)==4){
				return CLASS(stdwSwitchEndianL(DWORD(cxsource)));
			}else{
				return cxsource;
			}
		}
		//	CLASS					stxSwitchEndianB(const CLASS& cxsource)
		//		プロセッサネイティブのエンディアンがリトル時は「cxsource」のバイトオーダ反転値を、
		//		ビッグ時は「cxsource」そのままの値を返します。
		template<class CLASS>
		static constexpr CLASS	stxSwitchEndianB(const CLASS& cxsource)noexcept{
			if constexpr(SIZEOF(CLASS)==2){
				return CLASS(stwSwitchEndianB(WORD(cxsource)));
			}else if constexpr(SIZEOF(CLASS)==4){
				return CLASS(stdwSwitchEndianB(DWORD(cxsource)));
			}else{
				return cxsource;
			}
		}
		//	BYTE					stbReverseBit(CBYTE cbsource)
		//		「cbsource」のビット並び順を反転します。
		static constexpr BYTE	stbReverseBit(CBYTE cbsource)noexcept{
			return
				((cbsource&0x01)<<7)|
				((cbsource&0x02)<<5)|
				((cbsource&0x04)<<3)|
				((cbsource&0x08)<<1)|
				((cbsource&0x10)>>1)|
				((cbsource&0x20)>>3)|
				((cbsource&0x40)>>5)|
				((cbsource&0x80)>>7);
		}
		//	WORD					stwReverseBit(CWORD cwsource)
		//		「cwsource」のビット並び順を反転します。
		static constexpr WORD	stwReverseBit(CWORD cwsource)noexcept{
			return
				((cwsource&0x0001)<<15)|
				((cwsource&0x0002)<<13)|
				((cwsource&0x0004)<<11)|
				((cwsource&0x0008)<< 9)|
				((cwsource&0x0010)<< 7)|
				((cwsource&0x0020)<< 5)|
				((cwsource&0x0040)<< 3)|
				((cwsource&0x0080)<< 1)|
				((cwsource&0x0100)>> 1)|
				((cwsource&0x0200)>> 3)|
				((cwsource&0x0400)>> 5)|
				((cwsource&0x0800)>> 7)|
				((cwsource&0x1000)>> 9)|
				((cwsource&0x2000)>>11)|
				((cwsource&0x4000)>>13)|
				((cwsource&0x8000)>>15);
		}
		//	DWORD					stdwReverseBit(CDWORD cdwsource)
		//		「cdwsource」のビット並び順を反転します。
		static constexpr DWORD	stdwReverseBit(CDWORD cdwsource)noexcept{
			return
				((cdwsource&0x00000001)<<31)|
				((cdwsource&0x00000002)<<29)|
				((cdwsource&0x00000004)<<27)|
				((cdwsource&0x00000008)<<25)|
				((cdwsource&0x00000010)<<23)|
				((cdwsource&0x00000020)<<21)|
				((cdwsource&0x00000040)<<19)|
				((cdwsource&0x00000080)<<17)|
				((cdwsource&0x00000100)<<15)|
				((cdwsource&0x00000200)<<13)|
				((cdwsource&0x00000400)<<11)|
				((cdwsource&0x00000800)<< 9)|
				((cdwsource&0x00001000)<< 7)|
				((cdwsource&0x00002000)<< 5)|
				((cdwsource&0x00004000)<< 3)|
				((cdwsource&0x00008000)<< 1)|
				((cdwsource&0x00010000)>> 1)|
				((cdwsource&0x00020000)>> 3)|
				((cdwsource&0x00040000)>> 5)|
				((cdwsource&0x00080000)>> 7)|
				((cdwsource&0x00100000)>> 9)|
				((cdwsource&0x00200000)>>11)|
				((cdwsource&0x00400000)>>13)|
				((cdwsource&0x00800000)>>15)|
				((cdwsource&0x01000000)>>17)|
				((cdwsource&0x02000000)>>19)|
				((cdwsource&0x04000000)>>21)|
				((cdwsource&0x08000000)>>23)|
				((cdwsource&0x10000000)>>25)|
				((cdwsource&0x20000000)>>27)|
				((cdwsource&0x40000000)>>29)|
				((cdwsource&0x80000000)>>31);
		}
		//	CLASS					stxReverseBit(const CLASS& cxsource)
		//		「cxsource」のビット並び順を反転します。
		template<class CLASS>
		static constexpr CLASS	stxReverseBit(const CLASS& cxsource)noexcept{
			if constexpr(SIZEOF(CLASS)==1){
				return CLASS(stbReverseBit(BYTE(cxsource)));
			}else if constexpr(SIZEOF(CLASS)==2){
				return CLASS(stwReverseBit(WORD(cxsource)));
			}else{
				return CLASS(stdwReverseBit(DWORD(cxsource)));
			}
		}
		//	CLASS					stxGetMinimum<CLASS>(VOID)
		//		整数型「CLASS」で表現しうる最小値を返します。
		template<class CLASS>
		static constexpr CLASS	stxGetMinimum(VOID)noexcept{
			if(CLASS(-1)<CLASS(0))return CLASS(OFWSIZE(1)<<(SIZEOF(CLASS)*8-1));
			return CLASS(0);
		}
		//	CLASS					stxGetMaximum<CLASS>(VOID)
		//		整数型「CLASS」で表現しうる最大値を返します。
		template<class CLASS>
		static constexpr CLASS	stxGetMaximum(VOID)noexcept{
			if(CLASS(-1)<CLASS(0))return ~CLASS(OFWSIZE(1)<<(SIZEOF(CLASS)*8-1));
			return ~CLASS(0);
		}
		//	AUTO					stxGetMinimum(const DCLASS& cxdestination,const SCLASS& cxsource)
		//		「cxdestination」と「cxsource」のうち小さい値を返します。
		template<class DCLASS,class SCLASS>
		static constexpr AUTO	stxGetMinimum(const DCLASS& cxdestination,const SCLASS& cxsource)noexcept{
			if constexpr(SIZEOF(DCLASS)<SIZEOF(SCLASS)){
				if(cxdestination<cxsource)return cxdestination;
				return DCLASS(cxsource);
			}else{
				if(cxdestination<cxsource)return SCLASS(cxdestination);
				return cxsource;
			}
		}
		//	AUTO					stxGetMaximum(const DCLASS& cxdestination,const SCLASS& cxsource)
		//		「cxdestination」と「cxsource」のうち大きい値を返します。
		template<class DCLASS,class SCLASS>
		static constexpr AUTO	stxGetMaximum(const DCLASS& cxdestination,const SCLASS& cxsource)noexcept{
			if constexpr(SIZEOF(DCLASS)<SIZEOF(SCLASS)){
				if(cxdestination<cxsource)return cxsource;
				return SCLASS(cxdestination);
			}else{
				if(cxdestination<cxsource)return DCLASS(cxsource);
				return cxdestination;
			}
		}
		//	CLASS					stxClamp(const CLASS& cxdestination,const CLASS& cxminimum,const CLASS& cxmaximum)
		//		「cxdestination」を最小「cxminimum」、最大「cxmaximum」に丸めて返します。
		template<class CLASS>
		static constexpr CLASS	stxClamp(const CLASS& cxdestination,const CLASS& cxminimum,const CLASS& cxmaximum)noexcept{
			if(cxdestination<cxminimum)return cxminimum;
			if(cxmaximum<cxdestination)return cxmaximum;
			return cxdestination;
		}
		//	DCLASS					stxAddSaturated(const DCLASS& cxdestination,const SCLASS& cxsource)
		//		「cxdestination」と「cxsource」の加算値を返します。
		//		オーバーフローする場合は、本来の加算結果に一番近い、
		//		「DCLASS」で表現できる最大値、もしくは最小値を返します。
		template<class DCLASS,class SCLASS>
		static constexpr DCLASS	stxAddSaturated(const DCLASS& cxdestination,const SCLASS& cxsource)noexcept{
			if(cxsource<0){
				if(cxdestination<DCLASS(cxdestination+DCLASS(cxsource)))return stxGetMinimum<DCLASS>();
			}else{
				if(DCLASS(cxdestination+DCLASS(cxsource))<cxdestination)return stxGetMaximum<DCLASS>();
			}
			return cxdestination+DCLASS(cxsource);
		}
		//	DCLASS					stxSubtractSaturated(const DCLASS& cxdestination,const SCLASS& cxsource)
		//		「cxdestination」と「cxsource」の減算値を返します。
		//		オーバーフローする場合は、本来の減算結果に一番近い、
		//		「DCLASS」で表現できる最小値、もしくは最大値を返します。
		template<class DCLASS,class SCLASS>
		static constexpr DCLASS	stxSubtractSaturated(const DCLASS& cxdestination,const SCLASS& cxsource)noexcept{
			if(cxsource<0){
				if(DCLASS(cxdestination-DCLASS(cxsource))<cxdestination)return stxGetMaximum<DCLASS>();
			}else{
				if(cxdestination<DCLASS(cxdestination-DCLASS(cxsource)))return stxGetMinimum<DCLASS>();
			}
			return cxdestination-DCLASS(cxsource);
		}
		//	SCLASS					stxGetAbs(const SCLASS cxsource)
		//		「cxsource」の絶対値を返します。
		//		「SCLASS」が符号付き整数型で「cxsource」が負の最小値である場合は、
		//		未定義値(「0」もしくは変換されない値)が返されます。
		template<class SCLASS>
		static constexpr SCLASS	stxGetAbs(const SCLASS cxsource)noexcept{
			if(SCLASS(0)<=cxsource)return cxsource;
			return -cxsource;
		}
		//	SCLASS					stxNegateAbs(const SCLASS cxsource)
		//		「cxsource」の絶対値の負値を返します。
		//		「stxGetAbs」とは異なり、未定義値が返される事はありません。
		template<class SCLASS>
		static constexpr SCLASS	stxNegateAbs(const SCLASS cxsource)noexcept{
			if(cxsource<SCLASS(0))return cxsource;
			return -cxsource;
		}
		//	DCLASS					stxGetDifference(const DCLASS cxdestination,const SCLASS cxsource)
		//		差を返します。
		//		オーバーフロー判定は行わないので、アプリケーション側で判定する必要があります。
		template<class DCLASS,class SCLASS>
		static constexpr DCLASS	stxGetDifference(const DCLASS cxdestination,const SCLASS cxsource)noexcept{
			if(cxdestination<cxsource)return DCLASS(cxsource)-cxdestination;
			else return cxdestination-DCLASS(cxsource);
		}
		//	DCLASS					stxSaturate(const SCLASS& cxsource)
		//		「cxsource」を整数型「DCLASS」で表現しうる最小、最大値に丸めて、「DCLASS」型に変換します。
		template<class DCLASS,class SCLASS>
		static constexpr DCLASS	stxSaturate(const SCLASS& cxsource)noexcept{
			constexpr AUTO			cxminimum=STD::stxGetMinimum<DCLASS>();
			constexpr AUTO			cxmaximum=STD::stxGetMaximum<DCLASS>();

			if(cxsource<cxminimum)return cxminimum;
			if(cxmaximum<cxsource)return cxmaximum;
			return DCLASS(cxsource);
		}
		static UINT16			stui16cRead(PCUSTR& pcustrsource)noexcept;
		static _INLINE_ VOID	stFill(const PVOID cpdestination,COFWSIZE cszndestination,CUINT8 cui8source)noexcept{
			memset(cpdestination,cui8source,cszndestination);
			return;
		}
		static VOID				stFill(const PUINT16 cpui16destination,COFWSIZE cszndestination,CUINT16 cui16source)noexcept;
		static VOID				stFill(const PUINT32 cpui32destination,COFWSIZE cszndestination,CUINT32 cui32source)noexcept;
		static _INLINE_ VOID	stCopy(const PVOID cpdestination,const PCVOID cpcsource,COFWSIZE csznsource)noexcept{
			memcpy(cpdestination,cpcsource,csznsource);
			return;
		}
		static VOID				stCopy(const PUSTR cpustrdestination,COFWSIZE cszndestination,const PCUSTR cpcustrsource)noexcept;
		static constexpr INT32	sti32Multiply(CINT16 ci16source0,CINT16 ci16source1)noexcept{
			if(ISCONSTEVAL){
				return INT32(ci16source0)*INT32(ci16source1);
			}else{
				INT32					i32return;

				ASM(
					R"(
						MULS.W					%1,%0
					)":
					"=d"(i32return):
					"n?d?m"(ci16source1),"0"(ci16source0)
				);
				return i32return;
			}
		}
		static constexpr UINT32	stui32Multiply(CUINT16 cui16source0,CUINT16 cui16source1)noexcept{
			if(ISCONSTEVAL){
				return UINT32(cui16source0)*UINT32(cui16source1);
			}else{
				UINT32					ui32return;

				ASM(
					R"(
						MULU.W					%1,%0
					)":
					"=d"(ui32return):
					"n?d?m"(cui16source1),"0"(cui16source0)
				);
				return ui32return;
			}
		}
		static constexpr INT32HL	sti32hlDivide(CINT32 ci32source0,CINT16 ci16source1)noexcept{
			if(ISCONSTEVAL){
				return {
					INT16(ci32source0%INT32(ci16source1)),
					INT16(ci32source0/INT32(ci16source1))
				};
			}else{
				AUTO					i32hlreturn=INT32HL(ci32source0);

				i32hlreturn.i32HL=ci32source0;
				ASM(
					R"(
						DIVS.W					%1,%0
					)":
					"+d"(i32hlreturn.i32HL):
					"n?d?m"(ci16source1)
				);
				return i32hlreturn;
			}
		}
		static constexpr UINT32HL	stui32hlDivide(CUINT32 cui32source0,CUINT16 cui16source1)noexcept{
			if(ISCONSTEVAL){
				return {
					UINT16(cui32source0%UINT32(cui16source1)),
					UINT16(cui32source0/UINT32(cui16source1))
				};
			}else{
				AUTO					ui32hlreturn=UINT32HL(cui32source0);

				ui32hlreturn.ui32HL=cui32source0;
				ASM(
					R"(
						DIVU.W					%1,%0
					)":
					"+d"(ui32hlreturn.ui32HL):
					"n?d?m"(cui16source1)
				);
				return ui32hlreturn;
			}
		}
		static constexpr INT16	sti16GetQuotient(CINT32HL& ci32hlsource)noexcept{
			return ci32hlsource.i16L;
		}
		static constexpr INT16	sti16GetRemainder(CINT32HL& ci32hlsource)noexcept{
			return ci32hlsource.i16H;
		}
		static constexpr UINT16	stui16GetQuotient(CUINT32HL& cui32hlsource)noexcept{
			return cui32hlsource.ui16L;
		}
		static constexpr UINT16	stui16GetRemainder(CUINT32HL& cui32hlsource)noexcept{
			return cui32hlsource.ui16H;
		}
	};

	//
	//		custom
	//

	constexpr OFWBOOL		eXOR(COFWBOOL cesource0,COFWBOOL cesource1)noexcept{
		return (cesource0&&(!cesource1))||((!cesource0)&&cesource1);
	}
}

//
//		using
//

using namespace m68k::ofw;

#endif
