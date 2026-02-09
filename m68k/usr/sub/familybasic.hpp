/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/familybasic.hpp'							2025 written by int71	**
 ****************************************************************************/
#ifndef I71_SUB_FAMILYBASIC
#define I71_SUB_FAMILYBASIC

//
//		include
//

#include				<hid/keyboard.hpp>
#include				<hid/joystick.hpp>
#include				"vector2.hpp"
#include				"os.hpp"

//
//		macro
//

#define __O68K_MAKESEQUENCE(cpsustrsource)	{0xff}

//
//		namespace:m68k::i71::sub
//

namespace m68k::i71::sub{

	//
	//		class
	//

	//	FAMILYBASIC
	class FAMILYBASIC;

	//
	//		class:FAMILYBASIC
	//

	class FAMILYBASIC{
	public:

		//
		//		const
		//

		using					IDKEY=m68k::hid::KEYBOARD::IDKEY;
		using					IDBUTTON=m68k::hid::JOYSTICK::IDBUTTON;
		static constexpr AUTO	stcui8nBank=			m68k::hid::JOYSTICK::stcui8nBank;
		static constexpr AUTO	stcui8cMaskButtonRight=	m68k::hid::JOYSTICK::stcui8cMaskButtonRight;
		static constexpr AUTO	stcui8cMaskButtonLeft=	m68k::hid::JOYSTICK::stcui8cMaskButtonLeft;
		static constexpr AUTO	stcui8cMaskButtonDown=	m68k::hid::JOYSTICK::stcui8cMaskButtonDown;
		static constexpr AUTO	stcui8cMaskButtonUp=	m68k::hid::JOYSTICK::stcui8cMaskButtonUp;
		static constexpr AUTO	stcui8cMaskButtonA=		m68k::hid::JOYSTICK::stcui8cMaskButtonA;
		static constexpr AUTO	stcui8cMaskButtonB=		m68k::hid::JOYSTICK::stcui8cMaskButtonB;
		class _IDSIZE{
		public:
			enum BODY:UINT8{
				n256=					0x00,
				n512=					0x01,
				n1024=					0x02
			};
		};
		using					IDSIZE=_IDSIZE::BODY;

		//
		//		body:FAMILYBASIC
		//

	public:
		static VOID				stNew(VOID)noexcept;
		static VOID				stDelete(VOID)noexcept;
		static _INLINE_ UINT16	stui16GetRandom(VOID)noexcept{
			return OS::LFSR_stui16Read();
		}
		static VOID				PALETTE_stWrite(CUINT8 cui8ipalette,CUINT8 cui8inescolor0,CUINT8 cui8inescolor1,CUINT8 cui8inescolor2,CUINT8 cui8inescolor3)noexcept;
		static _INLINE_ VOID	PALETTE_stWrite(CUINT8 cui8ipalette,CUINT8 (&acui8inescolor)[4])noexcept{
			PALETTE_stWrite(cui8ipalette,acui8inescolor[0],acui8inescolor[1],acui8inescolor[2],acui8inescolor[3]);
			return;
		}
		static VOID				PALETTE_stWriteSet(CUINT8 cui8ispriteset,CUINT8 cui8ibgset)noexcept;
		static VOID				SPRITE_stSetSize(const IDSIZE cidsize)noexcept;
		static _INLINE_ VOID	SPRITE_stWritePattern8(CUINT8 cui8ipattern,CUINT32 cui32cpattern0,CUINT32 cui32cpattern1,CUINT32 cui32cpattern2,CUINT32 cui32cpattern3,CUINT32 cui32cpattern4,CUINT32 cui32cpattern5,CUINT32 cui32cpattern6,CUINT32 cui32cpattern7)noexcept{
			CAUTO					cui32doffset=MAP::VRAM::PATTERN_SPRITE_stcui32dOffset+(UINT32(cui8ipattern)<<5);

			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x00)=cui32cpattern0;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x04)=cui32cpattern1;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x08)=cui32cpattern2;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x0c)=cui32cpattern3;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x10)=cui32cpattern4;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x14)=cui32cpattern5;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x18)=cui32cpattern6;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x1c)=cui32cpattern7;
			return;
		}
		static _INLINE_ VOID	SPRITE_stWritePattern16(CUINT8 cui8ipattern,CUINT32 cui32cpattern0l,CUINT32 cui32cpattern0r,CUINT32 cui32cpattern1l,CUINT32 cui32cpattern1r,CUINT32 cui32cpattern2l,CUINT32 cui32cpattern2r,CUINT32 cui32cpattern3l,CUINT32 cui32cpattern3r,CUINT32 cui32cpattern4l,CUINT32 cui32cpattern4r,CUINT32 cui32cpattern5l,CUINT32 cui32cpattern5r,CUINT32 cui32cpattern6l,CUINT32 cui32cpattern6r,CUINT32 cui32cpattern7l,CUINT32 cui32cpattern7r,CUINT32 cui32cpattern8l,CUINT32 cui32cpattern8r,CUINT32 cui32cpattern9l,CUINT32 cui32cpattern9r,CUINT32 cui32cpatternal,CUINT32 cui32cpatternar,CUINT32 cui32cpatternbl,CUINT32 cui32cpatternbr,CUINT32 cui32cpatterncl,CUINT32 cui32cpatterncr,CUINT32 cui32cpatterndl,CUINT32 cui32cpatterndr,CUINT32 cui32cpatternel,CUINT32 cui32cpatterner,CUINT32 cui32cpatternfl,CUINT32 cui32cpatternfr)noexcept{
			SPRITE_stWritePattern8(cui8ipattern+0,cui32cpattern0l,cui32cpattern1l,cui32cpattern2l,cui32cpattern3l,cui32cpattern4l,cui32cpattern5l,cui32cpattern6l,cui32cpattern7l);
			SPRITE_stWritePattern8(cui8ipattern+1,cui32cpattern8l,cui32cpattern9l,cui32cpatternal,cui32cpatternbl,cui32cpatterncl,cui32cpatterndl,cui32cpatternel,cui32cpatternfl);
			SPRITE_stWritePattern8(cui8ipattern+2,cui32cpattern0r,cui32cpattern1r,cui32cpattern2r,cui32cpattern3r,cui32cpattern4r,cui32cpattern5r,cui32cpattern6r,cui32cpattern7r);
			SPRITE_stWritePattern8(cui8ipattern+3,cui32cpattern8r,cui32cpattern9r,cui32cpatternar,cui32cpatternbr,cui32cpatterncr,cui32cpatterndr,cui32cpatterner,cui32cpatternfr);
			return;
		}
		static _INLINE_ VOID	SPRITE_stWriteAttribute(CUINT8 cui8isprite,CUINT16 cui16cattribute0,CUINT16 cui16cattribute1,CUINT16 cui16cattribute2,CUINT16 cui16cattribute3)noexcept{
			CAUTO					cui32doffset=MAP::VRAM::ATTRIBUTE_SPRITE_stcui32dOffset+(UINT32(cui8isprite)<<3);

			MEMORY::VRAM_stui16DelegateThis(cui32doffset+0x00)=cui16cattribute0;
			MEMORY::VRAM_stui16DelegateThis(cui32doffset+0x02)=cui16cattribute1;
			MEMORY::VRAM_stui16DelegateThis(cui32doffset+0x04)=cui16cattribute2;
			MEMORY::VRAM_stui16DelegateThis(cui32doffset+0x06)=cui16cattribute3;
			return;
		}
		static _INLINE_ VOID	SPRITE_stWrite8(CUINT8 cui8isprite,CVECTOR2& cv2iposition,CUINT8 cui8ipattern,CUINT8 cui8ispritepalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE,CUINT8 cui8ipriority=1)noexcept{
			SPRITE_stWriteAttribute(
				cui8isprite,
				UINT16(cv2iposition.i16iX()),
				UINT16(cv2iposition.i16iY()),
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ispritepalette)<<12),
				0x0000|(UINT16(cui8ipriority)<<8)
			);
			return;
		}
		static _INLINE_ VOID	SPRITE_stWrite16(CUINT8 cui8isprite,CVECTOR2& cv2iposition,CUINT8 cui8ipattern,CUINT8 cui8ispritepalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE,CUINT8 cui8ipriority=1)noexcept{
			SPRITE_stWriteAttribute(
				cui8isprite,
				UINT16(cv2iposition.i16iX()),
				UINT16(cv2iposition.i16iY()),
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ispritepalette)<<12),
				0x5000|(UINT16(cui8ipriority)<<8)
			);
			return;
		}
		static _INLINE_ VOID	SPRITE_stErase(CUINT8 cui8isprite)noexcept{
			CAUTO					cui32doffset=MAP::VRAM::ATTRIBUTE_SPRITE_stcui32dOffset+(UINT32(cui8isprite)<<3);

			MEMORY::VRAM_stui16DelegateThis(cui32doffset+0x06)=0x0000;
			return;
		}
		static _INLINE_ VOID	BG_stWritePattern(CUINT8 cui8ipattern,CUINT32 cui32cpattern0,CUINT32 cui32cpattern1,CUINT32 cui32cpattern2,CUINT32 cui32cpattern3,CUINT32 cui32cpattern4,CUINT32 cui32cpattern5,CUINT32 cui32cpattern6,CUINT32 cui32cpattern7)noexcept{
			CAUTO					cui32doffset=MAP::VRAM::PATTERN_BG1_stcui32dOffset+(UINT32(cui8ipattern)<<5);

			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x00)=cui32cpattern0;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x04)=cui32cpattern1;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x08)=cui32cpattern2;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x0c)=cui32cpattern3;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x10)=cui32cpattern4;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x14)=cui32cpattern5;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x18)=cui32cpattern6;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x1c)=cui32cpattern7;
			return;
		}
		static VOID				BG0_stSetSize(const IDSIZE cidsize)noexcept;
		static _INLINE_ VOID	BG0_stFillAttribute(CVECTOR2& cv2idestination,CVECTOR2& cv2ndestination,CUINT16 cui16cattribute)noexcept{
			BG_stFillAttribute(MAP::VRAM::ATTRIBUTE_BG0_stcui32dOffset,cv2idestination,cv2ndestination,cui16cattribute);
			return;
		}
		static _INLINE_ VOID	BG0_stFill(CVECTOR2& cv2idestination,CVECTOR2& cv2ndestination,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG0_stFillAttribute(
				cv2idestination,
				cv2ndestination,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG0_stWriteAttribute(CVECTOR2& cv2idestination,CUINT16 cui16cattribute)noexcept{
			BG_stWriteAttribute(MAP::VRAM::ATTRIBUTE_BG0_stcui32dOffset,cv2idestination,cui16cattribute);
			return;
		}
		static _INLINE_ VOID	BG0_stWriteAttribute(CVECTOR2& cv2idestination,const PCUINT16 cpcui16cattribute,CUINT16 cui16nattribute)noexcept{
			BG_stWriteAttribute(MAP::VRAM::ATTRIBUTE_BG0_stcui32dOffset,cv2idestination,cpcui16cattribute,cui16nattribute);
			return;
		}
		static _INLINE_ VOID	BG0_stWrite(CVECTOR2& cv2idestination,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG0_stWriteAttribute(
				cv2idestination,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG0_stPrint(CVECTOR2& cv2idestination,const PCUSTR cpcustrstring,CUINT8 cui8ibgpalette)noexcept{
			BG_stPrint(MAP::VRAM::ATTRIBUTE_BG0_stcui32dOffset,cv2idestination,cpcustrstring,cui8ibgpalette);
			return;
		}
		static VOID				BG1_stSetSize(const IDSIZE cidsize)noexcept;
		static _INLINE_ VOID	BG1_stFillAttribute(CVECTOR2& cv2idestination,CVECTOR2& cv2ndestination,CUINT16 cui16cattribute)noexcept{
			BG_stFillAttribute(MAP::VRAM::ATTRIBUTE_BG1_stcui32dOffset,cv2idestination,cv2ndestination,cui16cattribute);
			return;
		}
		static _INLINE_ VOID	BG1_stFill(CVECTOR2& cv2idestination,CVECTOR2& cv2ndestination,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG1_stFillAttribute(
				cv2idestination,
				cv2ndestination,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG1_stWriteAttribute(CVECTOR2& cv2idestination,CUINT16 cui16cattribute)noexcept{
			BG_stWriteAttribute(MAP::VRAM::ATTRIBUTE_BG1_stcui32dOffset,cv2idestination,cui16cattribute);
			return;
		}
		static _INLINE_ VOID	BG1_stWriteAttribute(CVECTOR2& cv2idestination,const PCUINT16 cpcui16cattribute,CUINT16 cui16nattribute)noexcept{
			BG_stWriteAttribute(MAP::VRAM::ATTRIBUTE_BG1_stcui32dOffset,cv2idestination,cpcui16cattribute,cui16nattribute);
			return;
		}
		static _INLINE_ VOID	BG1_stWrite(CVECTOR2& cv2idestination,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG1_stWriteAttribute(
				cv2idestination,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG1_stPrint(CVECTOR2& cv2idestination,const PCUSTR cpcustrstring,CUINT8 cui8ipalette)noexcept{
			BG_stPrint(MAP::VRAM::ATTRIBUTE_BG1_stcui32dOffset,cv2idestination,cpcustrstring,cui8ipalette);
			return;
		}
		static VOID				BG2_stSetSize(const IDSIZE cidsize)noexcept;
		static _INLINE_ VOID	BG2_stFillAttribute(CVECTOR2& cv2idestination,CVECTOR2& cv2ndestination,CUINT16 cui16cattribute)noexcept{
			BG_stFillAttribute(MAP::VRAM::ATTRIBUTE_BG2_stcui32dOffset,cv2idestination,cv2ndestination,cui16cattribute);
			return;
		}
		static _INLINE_ VOID	BG2_stFill(CVECTOR2& cv2idestination,CVECTOR2& cv2ndestination,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG2_stFillAttribute(
				cv2idestination,
				cv2ndestination,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG2_stWriteAttribute(CVECTOR2& cv2idestination,CUINT16 cui16cattribute)noexcept{
			BG_stWriteAttribute(MAP::VRAM::ATTRIBUTE_BG2_stcui32dOffset,cv2idestination,cui16cattribute);
			return;
		}
		static _INLINE_ VOID	BG2_stWriteAttribute(CVECTOR2& cv2idestination,const PCUINT16 cpcui16cattribute,CUINT16 cui16nattribute)noexcept{
			BG_stWriteAttribute(MAP::VRAM::ATTRIBUTE_BG2_stcui32dOffset,cv2idestination,cpcui16cattribute,cui16nattribute);
			return;
		}
		static _INLINE_ VOID	BG2_stWrite(CVECTOR2& cv2idestination,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG2_stWriteAttribute(
				cv2idestination,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG2_stPrint(CVECTOR2& cv2idestination,const PCUSTR cpcustrstring,CUINT8 cui8ipalette)noexcept{
			BG_stPrint(MAP::VRAM::ATTRIBUTE_BG2_stcui32dOffset,cv2idestination,cpcustrstring,cui8ipalette);
			return;
		}
		static VOID				BG3_stSetSize(const IDSIZE cidsize)noexcept;
		static _INLINE_ VOID	BG3_stFillAttribute(CVECTOR2& cv2idestination,CVECTOR2& cv2ndestination,CUINT16 cui16cattribute)noexcept{
			BG_stFillAttribute(MAP::VRAM::ATTRIBUTE_BG3_stcui32dOffset,cv2idestination,cv2ndestination,cui16cattribute);
			return;
		}
		static _INLINE_ VOID	BG3_stFill(CVECTOR2& cv2idestination,CVECTOR2& cv2ndestination,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG3_stFillAttribute(
				cv2idestination,
				cv2ndestination,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG3_stWriteAttribute(CVECTOR2& cv2idestination,CUINT16 cui16cattribute)noexcept{
			BG_stWriteAttribute(MAP::VRAM::ATTRIBUTE_BG3_stcui32dOffset,cv2idestination,cui16cattribute);
			return;
		}
		static _INLINE_ VOID	BG3_stWriteAttribute(CVECTOR2& cv2idestination,const PCUINT16 cpcui16cattribute,CUINT16 cui16nattribute)noexcept{
			BG_stWriteAttribute(MAP::VRAM::ATTRIBUTE_BG3_stcui32dOffset,cv2idestination,cpcui16cattribute,cui16nattribute);
			return;
		}
		static _INLINE_ VOID	BG3_stWrite(CVECTOR2& cv2idestination,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG3_stWriteAttribute(
				cv2idestination,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG3_stPrint(CVECTOR2& cv2idestination,const PCUSTR cpcustrstring,CUINT8 cui8ipalette)noexcept{
			BG_stPrint(MAP::VRAM::ATTRIBUTE_BG3_stcui32dOffset,cv2idestination,cpcustrstring,cui8ipalette);
			return;
		}
		static _INLINE_ VOID	BGM_stPlay(_UNDISCARDABLE_ CUINT8* const cpcui8csequence)noexcept{
			OS::BGM_stPlay(cpcui8csequence);
			return;
		}
		static _INLINE_ VOID	BGM_stSetMasterVolume(CUINT8 cui8nvolume)noexcept{
			OS::BGM_stSetMasterVolume(cui8nvolume);
			return;
		}
		static _INLINE_ VOID	BGM_stSetMasterVolumeFade(CUINT8 cui8nvolumefade,CUINT8 cui8nvolumefadespeed)noexcept{
			OS::BGM_stSetMasterVolumeFade(cui8nvolumefade,cui8nvolumefadespeed);
			return;
		}
		static _INLINE_ VOID	SE0_stPlay(_UNDISCARDABLE_ CUINT8* const cpcui8csequence)noexcept{
			OS::SE0_stPlay(cpcui8csequence);
			return;
		}
		static _INLINE_ VOID	SE1_stPlay(_UNDISCARDABLE_ CUINT8* const cpcui8csequence)noexcept{
			OS::SE1_stPlay(cpcui8csequence);
			return;
		}
		static OFWBOOL			KEY_steIsDown(const IDKEY cidkey)noexcept{
			return OS::DEVICE_KEYBOARD_stui16Read(cidkey>>4)&(1<<(cidkey&0xf));
		}
		static UINT8			CONTROLLER_stui8cRead(CUINT8 cui8ibank)noexcept{
			return OS::DEVICE_JOYSTICK_stui8Read(cui8ibank);
		}
	private:
		static VOID				BG_stFillAttribute(CUINT32 cui32doffset,CVECTOR2& cv2idestination,CVECTOR2& cv2ndestination,CUINT16 cui16cattribute)noexcept;
		static _INLINE_ VOID	BG_stWriteAttribute(CUINT32 cui32doffset,CVECTOR2& cv2idestination,CUINT16 cui16cattribute)noexcept{
			CAUTO					cpui16destination=
				&MEMORY::VRAM_stui16DelegateThis(cui32doffset)+
				(cv2idestination.i16iY()<<7)+
				cv2idestination.i16iX();

			*cpui16destination=cui16cattribute;
			return;
		}
		static VOID				BG_stWriteAttribute(CUINT32 cui32doffset,CVECTOR2& cv2idestination,const PCUINT16 cpcui16cattribute,CUINT16 cui16nattribute)noexcept;
		static VOID				BG_stPrint(CUINT32 cui32doffset,CVECTOR2& cv2idestination,const PCUSTR cpcustrstring,CUINT8 cui8ibgpalette)noexcept;
	};
}

#endif
