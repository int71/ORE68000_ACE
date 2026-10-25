/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/familybasic.hpp'							2026 written by int71	**
 ****************************************************************************/
#ifndef I71_SUB_FAMILYBASIC
#define I71_SUB_FAMILYBASIC

//
//		include
//

#include				<hid/keyboard.hpp>
#include				<hid/joystick.hpp>
#include				"vector2.hpp"
#include				"pattern.hpp"
#include				"os.hpp"
#include				"canvasbg.hpp"

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

		using					KEYBOARD_IDKEY=m68k::hid::KEYBOARD::IDKEY;
		using					JOYSTICK_IDBUTTON=								m68k::hid::JOYSTICK::IDBUTTON;
		static constexpr AUTO	JOYSTICK_stcui8nBank=							m68k::hid::JOYSTICK::stcui8nBank;
		static constexpr AUTO	JOYSTICK_stcui8cMaskButtonRight=				m68k::hid::JOYSTICK::stcui8cMaskButtonRight;
		static constexpr AUTO	JOYSTICK_stcui8cMaskButtonLeft=					m68k::hid::JOYSTICK::stcui8cMaskButtonLeft;
		static constexpr AUTO	JOYSTICK_stcui8cMaskButtonDown=					m68k::hid::JOYSTICK::stcui8cMaskButtonDown;
		static constexpr AUTO	JOYSTICK_stcui8cMaskButtonUp=					m68k::hid::JOYSTICK::stcui8cMaskButtonUp;
		static constexpr AUTO	JOYSTICK_stcui8cMaskButtonA=					m68k::hid::JOYSTICK::stcui8cMaskButtonA;
		static constexpr AUTO	JOYSTICK_stcui8cMaskButtonB=					m68k::hid::JOYSTICK::stcui8cMaskButtonB;
		enum class IDRESOLUTION{
			n256x212,
			n320x240,
			n640x480
		};
		class _IDSIZE{
		public:
			enum BODY:UINT8{
				n256=					0x00,
				n512=					0x01,
				n1024=					0x02
			};
		};
		using					IDSIZE=_IDSIZE::BODY;
		static constexpr UINT16	stacui16cCirculation[]={
			0x2000,
			0x1000,
			0x0000
		};
		static constexpr INT16	staci16nSize[]={
			0x0100,
			0x0200,
			0x0400
		};
		static constexpr UINT8	PALETTE_stui8iBase_Sprite=						0x0;
		static constexpr UINT8	PALETTE_stui8iBase_BG=							0x8;
		static constexpr UINT16	PALETTE_stacui16cColor[]={
			common::ui16cGetColor(0x616161),common::ui16cGetColor(0x000088),common::ui16cGetColor(0x1f0d99),common::ui16cGetColor(0x371379),common::ui16cGetColor(0x561260),common::ui16cGetColor(0x5d0010),common::ui16cGetColor(0x520e00),common::ui16cGetColor(0x3a2308),
			common::ui16cGetColor(0x21350c),common::ui16cGetColor(0x0d410e),common::ui16cGetColor(0x174417),common::ui16cGetColor(0x003a1f),common::ui16cGetColor(0x002f57),common::ui16cGetColor(0x000000),common::ui16cGetColor(0x000000),common::ui16cGetColor(0x000000),
			common::ui16cGetColor(0xaaaaaa),common::ui16cGetColor(0x0d4dc4),common::ui16cGetColor(0x4b24de),common::ui16cGetColor(0x6912cf),common::ui16cGetColor(0x9014ad),common::ui16cGetColor(0x9d1c48),common::ui16cGetColor(0x923404),common::ui16cGetColor(0x735005),
			common::ui16cGetColor(0x5d6913),common::ui16cGetColor(0x167a11),common::ui16cGetColor(0x138008),common::ui16cGetColor(0x127649),common::ui16cGetColor(0x1c6691),common::ui16cGetColor(0x000000),common::ui16cGetColor(0x000000),common::ui16cGetColor(0x000000),
			common::ui16cGetColor(0xfcfcfc),common::ui16cGetColor(0x639afc),common::ui16cGetColor(0x8a7efc),common::ui16cGetColor(0xb06afc),common::ui16cGetColor(0xdd6df2),common::ui16cGetColor(0xe771ab),common::ui16cGetColor(0xe38658),common::ui16cGetColor(0xcc9e22),
			common::ui16cGetColor(0xa8b100),common::ui16cGetColor(0x72c100),common::ui16cGetColor(0x5acd4e),common::ui16cGetColor(0x34c28e),common::ui16cGetColor(0x4fbece),common::ui16cGetColor(0x424242),common::ui16cGetColor(0x000000),common::ui16cGetColor(0x000000),
			common::ui16cGetColor(0xfcfcfc),common::ui16cGetColor(0xbed4fc),common::ui16cGetColor(0xcacafc),common::ui16cGetColor(0xd9c4fc),common::ui16cGetColor(0xecc1fc),common::ui16cGetColor(0xfac3e7),common::ui16cGetColor(0xf7cec3),common::ui16cGetColor(0xe2cda7),
			common::ui16cGetColor(0xdadb9c),common::ui16cGetColor(0xc8e39e),common::ui16cGetColor(0xbfe5b8),common::ui16cGetColor(0xb2ebc8),common::ui16cGetColor(0xb7e5eb),common::ui16cGetColor(0xacacac),common::ui16cGetColor(0x000000),common::ui16cGetColor(0x000000)
		};
		static constexpr UINT8	PALETTE_staacSetSprite[][4][3]={
			{
				{0x36,0x16,0x02},
				{0x27,0x30,0x19},
				{0x35,0x25,0x17},
				{0x30,0x27,0x16}
			},{
				{0x30,0x16,0x01},
				{0x10,0x00,0x01},
				{0x30,0x29,0x09},
				{0x30,0x16,0x07}
			},{
				{0x30,0x26,0x12},
				{0x30,0x15,0x12},
				{0x30,0x12,0x16},
				{0x30,0x26,0x19}
			}
		};
		static constexpr UINT8	PALETTE_staacSetBG[][4][3]={
			{
				{0x2c,0x15,0x07},
				{0x27,0x21,0x12},
				{0x29,0x36,0x17},
				{0x30,0x26,0x07}
			},{
				{0x30,0x21,0x02},
				{0x30,0x27,0x18},
				{0x30,0x27,0x16},
				{0x29,0x36,0x17}
			}
		};

		//
		//		class
		//

		//	CANVASBG_DEVICE
		using					CANVASBG_DEVICE=CANVASBG_SIZED_<{128,128}>;
		using					CCANVASBG_DEVICE=const CANVASBG_DEVICE;
		using					PCANVASBG_DEVICE=CANVASBG_DEVICE*;
		using					PCCANVASBG_DEVICE=CCANVASBG_DEVICE*;
		//	ST
		class ST;
		using					CST=const ST;
		using					PST=ST*;
		using					PCST=CST*;

		//
		//		class:ST
		//

		class ST{
		public:
			UINT16					SPRITE_ui16dOffsetX,SPRITE_ui16dOffsetY,SPRITE_ui16cCirculationX,SPRITE_ui16cCirculationY;
			VECTOR2					SPRITE_v2nSize,SPRITE_v2cMask;
			UINT16					BG0_ui16dOffsetX,BG0_ui16dOffsetY,BG0_ui16cCirculationX,BG0_ui16cCirculationY;
			VECTOR2					BG0_v2nSize,BG0_v2cMask,BG0_v2nSize8,BG0_v2cMask8;
			UINT16					BG1_ui16dOffsetX,BG1_ui16dOffsetY,BG1_ui16cCirculationX,BG1_ui16cCirculationY;
			VECTOR2					BG1_v2nSize,BG1_v2cMask,BG1_v2nSize8,BG1_v2cMask8;
			UINT16					BG2_ui16dOffsetX,BG2_ui16dOffsetY,BG2_ui16cCirculationX,BG2_ui16cCirculationY;
			VECTOR2					BG2_v2nSize,BG2_v2cMask,BG2_v2nSize8,BG2_v2cMask8;
			UINT16					BG3_ui16dOffsetX,BG3_ui16dOffsetY,BG3_ui16cCirculationX,BG3_ui16cCirculationY;
			VECTOR2					BG3_v2nSize,BG3_v2cMask,BG3_v2nSize8,BG3_v2cMask8;
		public:
			constexpr /*VOID*/		ST(VOID)noexcept{}
			VOID					Delete(VOID)noexcept;
		};

		//
		//		body:FAMILYBASIC
		//

	private:
		static inline ST		st;
	public:
		static VOID				stNew(const IDRESOLUTION cidresolution=IDRESOLUTION::n256x212,CVECTOR2& cv2nresolutionoverride=VECTOR2::stv2ImmediateZero(),COFWBOOL ceshow=TRUE)noexcept;
		static VOID				stDelete(VOID)noexcept;
		static VOID				stShow(COFWBOOL ceshow)noexcept;
		static _INLINE_ UINT16	stui16GetRandom(VOID)noexcept{
			return OS::LFSR_stui16Read();
		}
		template<CUINT8 cui8nRange>
		static UINT8			stui8GetRandom(VOID)noexcept{
			return UINT8(((stui16GetRandom()&0xff)*UINT16(cui8nRange))>>8);
		}
		static VOID				PALETTE_stWrite(CUINT8 cui8ipalette,CUINT8 cui8inescolor0,CUINT8 cui8inescolor1,CUINT8 cui8inescolor2)noexcept;
		static _INLINE_ VOID	PALETTE_stWrite(CUINT8 cui8ipalette,CUINT8 (&acui8inescolor)[3])noexcept{
			PALETTE_stWrite(cui8ipalette,acui8inescolor[0],acui8inescolor[1],acui8inescolor[2]);
			return;
		}
		static VOID				PALETTE_stWriteBack(CUINT8 cui8inescolor)noexcept;
		static VOID				PALETTE_stWriteSet(CUINT8 cui8isetsprite,CUINT8 setcui8ibg)noexcept;
		static VOID				PALETTE_stWriteSet2(CUINT8 cui8isetsprite0,CUINT8 cui8isetsprite1,CUINT8 cui8isetbg0,CUINT8 cui8isetbg1)noexcept;
		static VOID				SPRITE_stSetOffset(CVECTOR2& cv2doffset)noexcept;
		static _INLINE_ VOID	SPRITE_stSetSize(const IDSIZE cidsize)noexcept{
			SPRITE_stSetSize(cidsize,cidsize);
			return;
		}
		static VOID				SPRITE_stSetSize(const IDSIZE cidsizex,const IDSIZE cidsizey)noexcept;
		static _INLINE_ CVECTOR2&	SPRITE_stv2nGetSize(VOID)noexcept{
			return st.SPRITE_v2nSize;
		}
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
		static VOID				BG0_stSetOffset(CVECTOR2& cv2doffset)noexcept;
		static _INLINE_ VOID	BG0_stSetSize(const IDSIZE cidsize)noexcept{
			BG0_stSetSize(cidsize,cidsize);
			return;
		}
		static VOID				BG0_stSetSize(const IDSIZE cidsizex,const IDSIZE cidsizey)noexcept;
		static _INLINE_ CVECTOR2&	BG0_stv2nGetSize(VOID)noexcept{
			return st.BG0_v2nSize;
		}
		static _INLINE_ CVECTOR2&	BG0_stv2nGetSize8(VOID)noexcept{
			return st.BG0_v2nSize8;
		}
		static _INLINE_ VOID	BG0_stFillAttribute(CVECTOR2& cv2iposition,CVECTOR2& cv2nsize,CUINT16 cui16cattribute)noexcept{
			BG_stFillAttribute(MAP::VRAM::ATTRIBUTE_BG0_stcui32dOffset,cv2iposition,cv2nsize,cui16cattribute);
			return;
		}
		static _INLINE_ VOID	BG0_stFill(CVECTOR2& cv2iposition,CVECTOR2& cv2nsize,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG0_stFillAttribute(
				cv2iposition,
				cv2nsize,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG0_stWriteAttribute(CVECTOR2& cv2iposition,CUINT16 cui16cattribute)noexcept{
			BG_stWriteAttribute(MAP::VRAM::ATTRIBUTE_BG0_stcui32dOffset,cv2iposition,cui16cattribute);
			return;
		}
		static _INLINE_ VOID	BG0_stWrite(CVECTOR2& cv2iposition,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG0_stWriteAttribute(
				cv2iposition,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG0_stPrint(CVECTOR2& cv2iposition,const PCUSTR cpcustrstring,CUINT8 cui8ibgpalette)noexcept{
			BG_stPrint(MAP::VRAM::ATTRIBUTE_BG0_stcui32dOffset,cv2iposition,cpcustrstring,cui8ibgpalette);
			return;
		}
		template<CVECTOR2 SCLASS_cv2nSize>
		static _INLINE_ VOID	BG0_stCopy(const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CVECTOR2& cv2iposition)noexcept{
			using					SCLASS=CANVASBG_SIZED_<SCLASS_cv2nSize>;

			BG0_stCopyRect(ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition);
			return;
		}
		template<CVECTOR2 SCLASS_cv2nSize>
		static _INLINE_ VOID	BG0_stCopyRect(const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CANVASBG_::CSHAPE& cshpsource,CVECTOR2& cv2iposition)noexcept{
			BG_stCopyRect(MAP::VRAM::ATTRIBUTE_BG0_stcui32dOffset,ccvssource,cshpsource,cv2iposition);
			return;
		}
		static _INLINE_ UINT16	BG0_stui16cReadAttribute(CVECTOR2& cv2iposition)noexcept{
			return BG_stui16cReadAttribute(MAP::VRAM::ATTRIBUTE_BG0_stcui32dOffset,cv2iposition);
		}
		static VOID				BG1_stSetOffset(CVECTOR2& cv2doffset)noexcept;
		static _INLINE_ VOID	BG1_stSetSize(const IDSIZE cidsize)noexcept{
			BG1_stSetSize(cidsize,cidsize);
			return;
		}
		static VOID				BG1_stSetSize(const IDSIZE cidsizex,const IDSIZE cidsizey)noexcept;
		static _INLINE_ CVECTOR2&	BG1_stv2nGetSize(VOID)noexcept{
			return st.BG1_v2nSize;
		}
		static _INLINE_ CVECTOR2&	BG1_stv2nGetSize8(VOID)noexcept{
			return st.BG1_v2nSize8;
		}
		static _INLINE_ VOID	BG1_stFillAttribute(CVECTOR2& cv2iposition,CVECTOR2& cv2nsize,CUINT16 cui16cattribute)noexcept{
			BG_stFillAttribute(MAP::VRAM::ATTRIBUTE_BG1_stcui32dOffset,cv2iposition,cv2nsize,cui16cattribute);
			return;
		}
		static _INLINE_ VOID	BG1_stFill(CVECTOR2& cv2iposition,CVECTOR2& cv2ndestination,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG1_stFillAttribute(
				cv2iposition,
				cv2ndestination,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG1_stWriteAttribute(CVECTOR2& cv2iposition,CUINT16 cui16cattribute)noexcept{
			BG_stWriteAttribute(MAP::VRAM::ATTRIBUTE_BG1_stcui32dOffset,cv2iposition,cui16cattribute);
			return;
		}
		static _INLINE_ VOID	BG1_stWrite(CVECTOR2& cv2iposition,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG1_stWriteAttribute(
				cv2iposition,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG1_stPrint(CVECTOR2& cv2iposition,const PCUSTR cpcustrstring,CUINT8 cui8ipalette)noexcept{
			BG_stPrint(MAP::VRAM::ATTRIBUTE_BG1_stcui32dOffset,cv2iposition,cpcustrstring,cui8ipalette);
			return;
		}
		template<CVECTOR2 SCLASS_cv2nSize>
		static _INLINE_ VOID	BG1_stCopy(const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CVECTOR2& cv2iposition)noexcept{
			using					SCLASS=CANVASBG_SIZED_<SCLASS_cv2nSize>;

			BG1_stCopyRect(ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition);
			return;
		}
		template<CVECTOR2 SCLASS_cv2nSize>
		static _INLINE_ VOID	BG1_stCopyRect(const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CANVASBG_::CSHAPE& cshpsource,CVECTOR2& cv2iposition)noexcept{
			BG_stCopyRect(MAP::VRAM::ATTRIBUTE_BG1_stcui32dOffset,ccvssource,cshpsource,cv2iposition);
			return;
		}
		static _INLINE_ UINT16	BG1_stui16cReadAttribute(CVECTOR2& cv2iposition)noexcept{
			return BG_stui16cReadAttribute(MAP::VRAM::ATTRIBUTE_BG1_stcui32dOffset,cv2iposition);
		}
		static VOID				BG2_stSetOffset(CVECTOR2& cv2doffset)noexcept;
		static _INLINE_ VOID	BG2_stSetSize(const IDSIZE cidsize)noexcept{
			BG2_stSetSize(cidsize,cidsize);
			return;
		}
		static VOID				BG2_stSetSize(const IDSIZE cidsizex,const IDSIZE cidsizey)noexcept;
		static _INLINE_ CVECTOR2&	BG2_stv2nGetSize(VOID)noexcept{
			return st.BG2_v2nSize;
		}
		static _INLINE_ CVECTOR2&	BG2_stv2nGetSize8(VOID)noexcept{
			return st.BG2_v2nSize8;
		}
		static _INLINE_ VOID	BG2_stFillAttribute(CVECTOR2& cv2iposition,CVECTOR2& cv2nsize,CUINT16 cui16cattribute)noexcept{
			BG_stFillAttribute(MAP::VRAM::ATTRIBUTE_BG2_stcui32dOffset,cv2iposition,cv2nsize,cui16cattribute);
			return;
		}
		static _INLINE_ VOID	BG2_stFill(CVECTOR2& cv2iposition,CVECTOR2& cv2ndestination,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG2_stFillAttribute(
				cv2iposition,
				cv2ndestination,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG2_stWriteAttribute(CVECTOR2& cv2iposition,CUINT16 cui16cattribute)noexcept{
			BG_stWriteAttribute(MAP::VRAM::ATTRIBUTE_BG2_stcui32dOffset,cv2iposition,cui16cattribute);
			return;
		}
		static _INLINE_ VOID	BG2_stWrite(CVECTOR2& cv2iposition,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG2_stWriteAttribute(
				cv2iposition,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG2_stPrint(CVECTOR2& cv2iposition,const PCUSTR cpcustrstring,CUINT8 cui8ipalette)noexcept{
			BG_stPrint(MAP::VRAM::ATTRIBUTE_BG2_stcui32dOffset,cv2iposition,cpcustrstring,cui8ipalette);
			return;
		}
		template<CVECTOR2 SCLASS_cv2nSize>
		static _INLINE_ VOID	BG2_stCopy(const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CVECTOR2& cv2iposition)noexcept{
			using					SCLASS=CANVASBG_SIZED_<SCLASS_cv2nSize>;

			BG2_stCopyRect(ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition);
			return;
		}
		template<CVECTOR2 SCLASS_cv2nSize>
		static _INLINE_ VOID	BG2_stCopyRect(const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CANVASBG_::CSHAPE& cshpsource,CVECTOR2& cv2iposition)noexcept{
			BG_stCopyRect(MAP::VRAM::ATTRIBUTE_BG2_stcui32dOffset,ccvssource,cshpsource,cv2iposition);
			return;
		}
		static _INLINE_ UINT16	BG2_stui16cReadAttribute(CVECTOR2& cv2iposition)noexcept{
			return BG_stui16cReadAttribute(MAP::VRAM::ATTRIBUTE_BG2_stcui32dOffset,cv2iposition);
		}
		static VOID				BG3_stSetOffset(CVECTOR2& cv2doffset)noexcept;
		static _INLINE_ VOID	BG3_stSetSize(const IDSIZE cidsize)noexcept{
			BG3_stSetSize(cidsize,cidsize);
			return;
		}
		static VOID				BG3_stSetSize(const IDSIZE cidsizex,const IDSIZE cidsizey)noexcept;
		static _INLINE_ CVECTOR2&	BG3_stv2nGetSize(VOID)noexcept{
			return st.BG3_v2nSize;
		}
		static _INLINE_ CVECTOR2&	BG3_stv2nGetSize8(VOID)noexcept{
			return st.BG3_v2nSize8;
		}
		static _INLINE_ VOID	BG3_stFillAttribute(CVECTOR2& cv2iposition,CVECTOR2& cv2nsize,CUINT16 cui16cattribute)noexcept{
			BG_stFillAttribute(MAP::VRAM::ATTRIBUTE_BG3_stcui32dOffset,cv2iposition,cv2nsize,cui16cattribute);
			return;
		}
		static _INLINE_ VOID	BG3_stFill(CVECTOR2& cv2iposition,CVECTOR2& cv2ndestination,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG3_stFillAttribute(
				cv2iposition,
				cv2ndestination,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG3_stWriteAttribute(CVECTOR2& cv2iposition,CUINT16 cui16cattribute)noexcept{
			BG_stWriteAttribute(MAP::VRAM::ATTRIBUTE_BG3_stcui32dOffset,cv2iposition,cui16cattribute);
			return;
		}
		static _INLINE_ VOID	BG3_stWrite(CVECTOR2& cv2iposition,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG3_stWriteAttribute(
				cv2iposition,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG3_stPrint(CVECTOR2& cv2iposition,const PCUSTR cpcustrstring,CUINT8 cui8ipalette)noexcept{
			BG_stPrint(MAP::VRAM::ATTRIBUTE_BG3_stcui32dOffset,cv2iposition,cpcustrstring,cui8ipalette);
			return;
		}
		template<CVECTOR2 SCLASS_cv2nSize>
		static _INLINE_ VOID	BG3_stCopy(const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CVECTOR2& cv2iposition)noexcept{
			using					SCLASS=CANVASBG_SIZED_<SCLASS_cv2nSize>;

			BG3_stCopyRect(ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition);
			return;
		}
		template<CVECTOR2 SCLASS_cv2nSize>
		static _INLINE_ VOID	BG3_stCopyRect(const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CANVASBG_::CSHAPE& cshpsource,CVECTOR2& cv2iposition)noexcept{
			BG_stCopyRect(MAP::VRAM::ATTRIBUTE_BG3_stcui32dOffset,ccvssource,cshpsource,cv2iposition);
			return;
		}
		static _INLINE_ UINT16	BG3_stui16cReadAttribute(CVECTOR2& cv2iposition)noexcept{
			return BG_stui16cReadAttribute(MAP::VRAM::ATTRIBUTE_BG3_stcui32dOffset,cv2iposition);
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
		static OFWBOOL			KEY_steIsDown(const KEYBOARD_IDKEY cidkey)noexcept{
			return OS::DEVICE_KEYBOARD_stui16Read(cidkey>>4)&(1<<(cidkey&0xf));
		}
		static UINT8			CONTROLLER_stui8cRead(CUINT8 cui8ibank)noexcept{
			return OS::DEVICE_JOYSTICK_stui8Read(cui8ibank);
		}
	protected:
		static VOID				stNew_SetResolution(const IDRESOLUTION cidresolution,CVECTOR2& cv2nresolutionoverride)noexcept;
		static VOID				stNew_SetPattern(const PATTERN::IDPATTERN cidpatternsprite,const PATTERN::IDPATTERN cidpatternbg)noexcept;
		static VOID				stNew_Common(const IDRESOLUTION cidresolution,COFWBOOL ceshow)noexcept;
		static _INLINE_ VECTOR2	SPRITE_stv2iMakeOffset_R(CVECTOR2& cv2doffset)noexcept{
			return {
				cv2doffset.i16iY(),
				INT16(
					(cv2doffset.i16iX()&(~st.SPRITE_v2cMask.i16nHeight()))|
					((-cv2doffset.i16iX())&st.SPRITE_v2cMask.i16nHeight())
				)
			};
		}
		static _INLINE_ VECTOR2	BG0_stv2iMakeOffset_R(CVECTOR2& cv2doffset)noexcept{
			return {
				cv2doffset.i16iY(),
				INT16(
					(cv2doffset.i16iX()&(~st.BG0_v2cMask.i16nHeight()))|
					((-cv2doffset.i16iX())&st.BG0_v2cMask.i16nHeight())
				)
			};
		}
		static _INLINE_ VECTOR2	BG1_stv2iMakeOffset_R(CVECTOR2& cv2doffset)noexcept{
			return {
				cv2doffset.i16iY(),
				INT16(
					(cv2doffset.i16iX()&(~st.BG1_v2cMask.i16nHeight()))|
					((-cv2doffset.i16iX())&st.BG1_v2cMask.i16nHeight())
				)
			};
		}
		static _INLINE_ VECTOR2	BG2_stv2iMakeOffset_R(CVECTOR2& cv2doffset)noexcept{
			return {
				cv2doffset.i16iY(),
				INT16(
					(cv2doffset.i16iX()&(~st.BG2_v2cMask.i16nHeight()))|
					((-cv2doffset.i16iX())&st.BG2_v2cMask.i16nHeight())
				)
			};
		}
		static _INLINE_ VECTOR2	BG3_stv2iMakeOffset_R(CVECTOR2& cv2doffset)noexcept{
			return {
				cv2doffset.i16iY(),
				INT16(
					(cv2doffset.i16iX()&(~st.BG3_v2cMask.i16nHeight()))|
					((-cv2doffset.i16iX())&st.BG3_v2cMask.i16nHeight())
				)
			};
		}
		static constexpr VECTOR2	stv2nMakeSize_R(CVECTOR2& cv2nsize)noexcept{
			return {
				cv2nsize.i16nHeight(),
				cv2nsize.i16nWidth()
			};
		}
		static VOID				SPRITE_stApplyOffset(VOID)noexcept;
		static VOID				BG0_stApplyOffset(VOID)noexcept;
		static VOID				BG1_stApplyOffset(VOID)noexcept;
		static VOID				BG2_stApplyOffset(VOID)noexcept;
		static VOID				BG3_stApplyOffset(VOID)noexcept;
		static VOID				BG_stFillAttribute(CUINT32 cui32doffset,CVECTOR2& cv2iposition,CVECTOR2& cv2nsize,CUINT16 cui16cattribute)noexcept;
		static _INLINE_ VOID	BG_stWriteAttribute(CUINT32 cui32doffset,CVECTOR2& cv2iposition,CUINT16 cui16cattribute)noexcept{
			CAUTO					cpui16cdestination=(
				&MEMORY::VRAM_stui16DelegateThis(cui32doffset)+
				(cv2iposition.i16iY()<<7)+
				cv2iposition.i16iX()
			);

			*cpui16cdestination=cui16cattribute;
			return;
		}
		static VOID				BG_stPrint(CUINT32 cui32doffset,CVECTOR2& cv2iposition,const PCUSTR cpcustrstring,CUINT8 cui8ibgpalette)noexcept;
		static VOID				BG_stPrint_R_Body(CUINT32 cui32doffset,CVECTOR2& cv2iposition,const PCUSTR cpcustrstring,CUINT8 cui8ibgpalette,CVECTOR2& cv2ntrim)noexcept;
		template<CVECTOR2 SCLASS_cv2nSize>
		static _INLINE_ VOID	BG_stCopyRect(CUINT32 cui32doffset,const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CANVASBG_::CSHAPE& cshpsource,CVECTOR2& cv2iposition)noexcept{
			using					SCLASS=CANVASBG_SIZED_<SCLASS_cv2nSize>;
			AUTO					shpsource=cshpsource;
			AUTO					v2iposition=cv2iposition;

			SCLASS::stTrimSending(shpsource,v2iposition);
			CANVASBG_DEVICE::stTrimReceiving(shpsource,v2iposition);
			BG_stCopyRect_Body(
				cui32doffset+UINT32(CANVASBG_DEVICE::stui16iGetPosition(v2iposition)),
				ccvssource.pcui16cGetThis()+SCLASS::stui16iGetPosition(shpsource.v2iPosition),
				SCLASS::stcui16nPitch,
				shpsource.v2nSize
			);
			return;
		}
		static VOID				BG_stCopyRect_Body(CUINT32 cui32doffset,const PCUINT16 cpcui16csource,CUINT16 cui16nsourcepitch,CVECTOR2& cv2nsource)noexcept;
		static VOID				BG_stCopyRect_R_Body(CUINT32 cui32doffset,const PCUINT16 cpcui16csource,CUINT16 cui16nsourcepitch,CVECTOR2& cv2nsource)noexcept;
		static _INLINE_ UINT16	BG_stui16cReadAttribute(CUINT32 cui32doffset,CVECTOR2& cv2iposition)noexcept{
			CAUTO					cpcui16source=(
				&MEMORY::VRAM_stcui16GetThis(cui32doffset)+
				(cv2iposition.i16iY()<<7)+
				cv2iposition.i16iX()
			);

			return *cpcui16source;
		}
	};

	//
	//		class
	//

	//	FAMILYBASIC_R
	template<const FAMILYBASIC::IDRESOLUTION cidResolution,CVECTOR2 cv2nResolutionOverride=VECTOR2::stv2ImmediateZero()>
	class FAMILYBASIC_R;

	//
	//		class:FAMILYBASIC_R
	//

	template<const FAMILYBASIC::IDRESOLUTION cidResolution,CVECTOR2 cv2nResolutionOverride>
	class FAMILYBASIC_R:public FAMILYBASIC{
	public:

		//
		//		const
		//

		static constexpr VECTOR2	stcv2nScreen=(cv2nResolutionOverride==VECTOR2::stv2ImmediateZero())?(
			(cidResolution==IDRESOLUTION::n256x212)?VECTOR2(
				212,256
			):(
				(cidResolution==IDRESOLUTION::n320x240)?VECTOR2(
					240,320
				):VECTOR2(
					480,640
				)
			)
		):(
			stv2nMakeSize_R(cv2nResolutionOverride)
		);
		static constexpr AUTO	stcv2nScreen_M8=stcv2nScreen-VECTOR2(8,8);
		static constexpr AUTO	stcv2nScreen_M16=stcv2nScreen-VECTOR2(16,16);
		static constexpr AUTO	stcv2nBG=stcv2nScreen>>3;
		static constexpr AUTO	stcv2nBG_M1=stcv2nBG-VECTOR2(1,1);

		//
		//		class
		//

		//	SUPER
		using					SUPER=FAMILYBASIC;

		//
		//		body:FAMILYBASIC_R
		//

	public:
		static VOID				stNew(COFWBOOL ceshow=TRUE)noexcept{
			stNew_SetResolution(cidResolution,cv2nResolutionOverride);
			stNew_SetPattern(PATTERN::IDPATTERN::SPRITE_SYSTEM_R,PATTERN::IDPATTERN::BG_SYSTEM_R);
			stNew_Common(cidResolution,ceshow);
			return;
		}
		static VOID				SPRITE_stSetOffset(CVECTOR2& cv2doffset)noexcept{
			SUPER::SPRITE_stSetOffset(SPRITE_stv2iMakeOffset_R(cv2doffset));
			return;
		}
		static _INLINE_ VOID	SPRITE_stSetSize(const IDSIZE cidsize)noexcept{
			SPRITE_stSetSize(cidsize,cidsize);
			return;
		}
		static _INLINE_ VOID	SPRITE_stSetSize(const IDSIZE cidsizex,const IDSIZE cidsizey)noexcept{
			SUPER::SPRITE_stSetSize(cidsizey,cidsizex);
			return;
		}
		static _INLINE_ VOID	SPRITE_stWrite8(CUINT8 cui8isprite,CVECTOR2& cv2iposition,CUINT8 cui8ipattern,CUINT8 cui8ispritepalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE,CUINT8 cui8ipriority=1)noexcept{
			SUPER::SPRITE_stWrite8(
				cui8isprite,			//	cui8isprite
				SPRITE_stv2iMakePosition8(cv2iposition),	//	cv2iposition
				cui8ipattern,			//	cui8ipattern
				cui8ispritepalette,		//	cui8ispritepalette
				ceinvertv,				//	ceinverth
				ceinverth,				//	ceinvertv
				cui8ipriority			//	cui8ipriority
			);
			return;
		}
		static _INLINE_ VOID	SPRITE_stWrite16(CUINT8 cui8isprite,CVECTOR2& cv2iposition,CUINT8 cui8ipattern,CUINT8 cui8ispritepalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE,CUINT8 cui8ipriority=1)noexcept{
			SUPER::SPRITE_stWrite16(
				cui8isprite,			//	cui8isprite
				SPRITE_stv2iMakePosition16(cv2iposition),	//	cv2iposition
				cui8ipattern,			//	cui8ipattern
				cui8ispritepalette,		//	cui8ispritepalette
				ceinvertv,				//	ceinverth
				ceinverth,				//	ceinvertv
				cui8ipriority			//	cui8ipriority
			);
			return;
		}
		static VOID				BG0_stSetOffset(CVECTOR2& cv2doffset)noexcept{
			SUPER::BG0_stSetOffset(BG0_stv2iMakeOffset_R(cv2doffset));
			return;
		}
		static _INLINE_ VOID	BG0_stSetSize(const IDSIZE cidsize)noexcept{
			BG0_stSetSize(cidsize,cidsize);
			return;
		}
		static _INLINE_ VOID	BG0_stSetSize(const IDSIZE cidsizex,const IDSIZE cidsizey)noexcept{
			SUPER::BG0_stSetSize(cidsizey,cidsizex);
			return;
		}
		static _INLINE_ VOID	BG0_stFillAttribute(CVECTOR2& cv2iposition,CVECTOR2& cv2nsize,CUINT16 cui16cattribute)noexcept{
			BG_stFillAttribute(MAP::VRAM::ATTRIBUTE_BG0_stcui32dOffset,cv2iposition,cv2nsize,cui16cattribute,BG0_stv2nGetSize8());
			return;
		}
		static _INLINE_ VOID	BG0_stFill(CVECTOR2& cv2iposition,CVECTOR2& cv2nsize,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG0_stFillAttribute(
				cv2iposition,
				cv2nsize,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG0_stWriteAttribute(CVECTOR2& cv2iposition,CUINT16 cui16cattribute)noexcept{
			BG_stWriteAttribute(MAP::VRAM::ATTRIBUTE_BG0_stcui32dOffset,cv2iposition,cui16cattribute,BG0_stv2nGetSize8());
			return;
		}
		static _INLINE_ VOID	BG0_stWrite(CVECTOR2& cv2iposition,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG0_stWriteAttribute(
				cv2iposition,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG0_stPrint(CVECTOR2& cv2iposition,const PCUSTR cpcustrstring,CUINT8 cui8ibgpalette)noexcept{
			BG_stPrint(MAP::VRAM::ATTRIBUTE_BG0_stcui32dOffset,cv2iposition,cpcustrstring,cui8ibgpalette,BG0_stv2nGetSize8());
			return;
		}
		template<CVECTOR2 SCLASS_cv2nSize>
		static _INLINE_ VOID	BG0_stCopy(const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CVECTOR2& cv2iposition)noexcept{
			using					SCLASS=CANVASBG_SIZED_<SCLASS_cv2nSize>;

			BG0_stCopyRect(ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition);
			return;
		}
		template<CVECTOR2 SCLASS_cv2nSize>
		static _INLINE_ VOID	BG0_stCopyRect(const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CANVASBG_::CSHAPE& cshpsource,CVECTOR2& cv2iposition)noexcept{
			BG_stCopyRect(MAP::VRAM::ATTRIBUTE_BG0_stcui32dOffset,ccvssource,cshpsource,cv2iposition,BG0_stv2nGetSize8());
			return;
		}
		static _INLINE_ UINT16	BG0_stui16cReadAttribute(CVECTOR2& cv2iposition)noexcept{
			return BG_stui16cReadAttribute(MAP::VRAM::ATTRIBUTE_BG0_stcui32dOffset,cv2iposition,BG0_stv2nGetSize8());
		}
		static VOID				BG1_stSetOffset(CVECTOR2& cv2doffset)noexcept{
			SUPER::BG1_stSetOffset(BG1_stv2iMakeOffset_R(cv2doffset));
			return;
		}
		static _INLINE_ VOID	BG1_stSetSize(const IDSIZE cidsize)noexcept{
			BG1_stSetSize(cidsize,cidsize);
			return;
		}
		static _INLINE_ VOID	BG1_stSetSize(const IDSIZE cidsizex,const IDSIZE cidsizey)noexcept{
			SUPER::BG1_stSetSize(cidsizey,cidsizex);
			return;
		}
		static _INLINE_ VOID	BG1_stFillAttribute(CVECTOR2& cv2iposition,CVECTOR2& cv2nsize,CUINT16 cui16cattribute)noexcept{
			BG_stFillAttribute(MAP::VRAM::ATTRIBUTE_BG1_stcui32dOffset,cv2iposition,cv2nsize,cui16cattribute,BG1_stv2nGetSize8());
			return;
		}
		static _INLINE_ VOID	BG1_stFill(CVECTOR2& cv2iposition,CVECTOR2& cv2ndestination,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG1_stFillAttribute(
				cv2iposition,
				cv2ndestination,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG1_stWriteAttribute(CVECTOR2& cv2iposition,CUINT16 cui16cattribute)noexcept{
			BG_stWriteAttribute(MAP::VRAM::ATTRIBUTE_BG1_stcui32dOffset,cv2iposition,cui16cattribute,BG1_stv2nGetSize8());
			return;
		}
		static _INLINE_ VOID	BG1_stWrite(CVECTOR2& cv2iposition,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG1_stWriteAttribute(
				cv2iposition,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG1_stPrint(CVECTOR2& cv2iposition,const PCUSTR cpcustrstring,CUINT8 cui8ipalette)noexcept{
			BG_stPrint(MAP::VRAM::ATTRIBUTE_BG1_stcui32dOffset,cv2iposition,cpcustrstring,cui8ipalette,BG1_stv2nGetSize8());
			return;
		}
		template<CVECTOR2 SCLASS_cv2nSize>
		static _INLINE_ VOID	BG1_stCopy(const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CVECTOR2& cv2iposition)noexcept{
			using					SCLASS=CANVASBG_SIZED_<SCLASS_cv2nSize>;

			BG1_stCopyRect(ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition);
			return;
		}
		template<CVECTOR2 SCLASS_cv2nSize>
		static _INLINE_ VOID	BG1_stCopyRect(const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CANVASBG_::CSHAPE& cshpsource,CVECTOR2& cv2iposition)noexcept{
			BG_stCopyRect(MAP::VRAM::ATTRIBUTE_BG1_stcui32dOffset,ccvssource,cshpsource,cv2iposition,BG1_stv2nGetSize8());
			return;
		}
		static _INLINE_ UINT16	BG1_stui16cReadAttribute(CVECTOR2& cv2iposition)noexcept{
			return BG_stui16cReadAttribute(MAP::VRAM::ATTRIBUTE_BG1_stcui32dOffset,cv2iposition,BG1_stv2nGetSize8());
		}
		static VOID				BG2_stSetOffset(CVECTOR2& cv2doffset)noexcept{
			SUPER::BG2_stSetOffset(BG2_stv2iMakeOffset_R(cv2doffset));
			return;
		}
		static _INLINE_ VOID	BG2_stSetSize(const IDSIZE cidsize)noexcept{
			BG2_stSetSize(cidsize,cidsize);
			return;
		}
		static _INLINE_ VOID	BG2_stSetSize(const IDSIZE cidsizex,const IDSIZE cidsizey)noexcept{
			SUPER::BG2_stSetSize(cidsizey,cidsizex);
			return;
		}
		static _INLINE_ VOID	BG2_stFillAttribute(CVECTOR2& cv2iposition,CVECTOR2& cv2nsize,CUINT16 cui16cattribute)noexcept{
			BG_stFillAttribute(MAP::VRAM::ATTRIBUTE_BG2_stcui32dOffset,cv2iposition,cv2nsize,cui16cattribute,BG2_stv2nGetSize8());
			return;
		}
		static _INLINE_ VOID	BG2_stFill(CVECTOR2& cv2iposition,CVECTOR2& cv2ndestination,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG2_stFillAttribute(
				cv2iposition,
				cv2ndestination,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG2_stWriteAttribute(CVECTOR2& cv2iposition,CUINT16 cui16cattribute)noexcept{
			BG_stWriteAttribute(MAP::VRAM::ATTRIBUTE_BG2_stcui32dOffset,cv2iposition,cui16cattribute,BG2_stv2nGetSize8());
			return;
		}
		static _INLINE_ VOID	BG2_stWrite(CVECTOR2& cv2iposition,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG2_stWriteAttribute(
				cv2iposition,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG2_stPrint(CVECTOR2& cv2iposition,const PCUSTR cpcustrstring,CUINT8 cui8ipalette)noexcept{
			BG_stPrint(MAP::VRAM::ATTRIBUTE_BG2_stcui32dOffset,cv2iposition,cpcustrstring,cui8ipalette,BG2_stv2nGetSize8());
			return;
		}
		template<CVECTOR2 SCLASS_cv2nSize>
		static _INLINE_ VOID	BG2_stCopy(const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CVECTOR2& cv2iposition)noexcept{
			using					SCLASS=CANVASBG_SIZED_<SCLASS_cv2nSize>;

			BG2_stCopyRect(ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition);
			return;
		}
		template<CVECTOR2 SCLASS_cv2nSize>
		static _INLINE_ VOID	BG2_stCopyRect(const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CANVASBG_::CSHAPE& cshpsource,CVECTOR2& cv2iposition)noexcept{
			BG_stCopyRect(MAP::VRAM::ATTRIBUTE_BG2_stcui32dOffset,ccvssource,cshpsource,cv2iposition,BG2_stv2nGetSize8());
			return;
		}
		static _INLINE_ UINT16	BG2_stui16cReadAttribute(CVECTOR2& cv2iposition)noexcept{
			return BG_stui16cReadAttribute(MAP::VRAM::ATTRIBUTE_BG2_stcui32dOffset,cv2iposition,BG2_stv2nGetSize8());
		}
		static VOID				BG3_stSetOffset(CVECTOR2& cv2doffset)noexcept{
			SUPER::BG3_stSetOffset(BG3_stv2iMakeOffset_R(cv2doffset));
			return;
		}
		static _INLINE_ VOID	BG3_stSetSize(const IDSIZE cidsize)noexcept{
			BG3_stSetSize(cidsize,cidsize);
			return;
		}
		static _INLINE_ VOID	BG3_stSetSize(const IDSIZE cidsizex,const IDSIZE cidsizey)noexcept{
			SUPER::BG3_stSetSize(cidsizey,cidsizex);
			return;
		}
		static _INLINE_ VOID	BG3_stFillAttribute(CVECTOR2& cv2iposition,CVECTOR2& cv2nsize,CUINT16 cui16cattribute)noexcept{
			BG_stFillAttribute(MAP::VRAM::ATTRIBUTE_BG3_stcui32dOffset,cv2iposition,cv2nsize,cui16cattribute,BG3_stv2nGetSize8());
			return;
		}
		static _INLINE_ VOID	BG3_stFill(CVECTOR2& cv2iposition,CVECTOR2& cv2ndestination,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG3_stFillAttribute(
				cv2iposition,
				cv2ndestination,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG3_stWriteAttribute(CVECTOR2& cv2iposition,CUINT16 cui16cattribute)noexcept{
			BG_stWriteAttribute(MAP::VRAM::ATTRIBUTE_BG3_stcui32dOffset,cv2iposition,cui16cattribute,BG3_stv2nGetSize8());
			return;
		}
		static _INLINE_ VOID	BG3_stWrite(CVECTOR2& cv2iposition,CUINT8 cui8ipattern,CUINT8 cui8ibgpalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE)noexcept{
			BG3_stWriteAttribute(
				cv2iposition,
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ibgpalette+8)<<12)
			);
			return;
		}
		static _INLINE_ VOID	BG3_stPrint(CVECTOR2& cv2iposition,const PCUSTR cpcustrstring,CUINT8 cui8ipalette)noexcept{
			BG_stPrint(MAP::VRAM::ATTRIBUTE_BG3_stcui32dOffset,cv2iposition,cpcustrstring,cui8ipalette,BG3_stv2nGetSize8());
			return;
		}
		template<CVECTOR2 SCLASS_cv2nSize>
		static _INLINE_ VOID	BG3_stCopy(const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CVECTOR2& cv2iposition)noexcept{
			using					SCLASS=CANVASBG_SIZED_<SCLASS_cv2nSize>;

			BG3_stCopyRect(ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition);
			return;
		}
		template<CVECTOR2 SCLASS_cv2nSize>
		static _INLINE_ VOID	BG3_stCopyRect(const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CANVASBG_::CSHAPE& cshpsource,CVECTOR2& cv2iposition)noexcept{
			BG_stCopyRect(MAP::VRAM::ATTRIBUTE_BG3_stcui32dOffset,ccvssource,cshpsource,cv2iposition,BG3_stv2nGetSize8());
			return;
		}
		static _INLINE_ UINT16	BG3_stui16cReadAttribute(CVECTOR2& cv2iposition)noexcept{
			return BG_stui16cReadAttribute(MAP::VRAM::ATTRIBUTE_BG3_stcui32dOffset,cv2iposition,BG3_stv2nGetSize8());
		}
	private:
		static VOID				stTrimReceiving(CANVASBG_::SHAPE& shpsource,VECTOR2& v2iposition,CVECTOR2& cv2ntrim)noexcept{
			CANVASBG_::stTrimReceiving(shpsource,v2iposition,stv2nMakeSize_R(cv2ntrim));
			return;
		}
		static _INLINE_ VECTOR2	SPRITE_stv2iMakePosition8(CVECTOR2& cv2iposition)noexcept{
			return {
				cv2iposition.i16iY(),
				INT16(stcv2nScreen_M8.i16nWidth()-cv2iposition.i16iX())
			};
		}
		static _INLINE_ VECTOR2	SPRITE_stv2iMakePosition16(CVECTOR2& cv2iposition)noexcept{
			return {
				cv2iposition.i16iY(),
				INT16(stcv2nScreen_M16.i16nWidth()-cv2iposition.i16iX())
			};
		}
		static _INLINE_ VECTOR2	BG_stv2iMakePosition(CVECTOR2& cv2iposition,CVECTOR2& cv2ntrim)noexcept{
			CAUTO					ci16ix_r=INT16(stcv2nBG_M1.i16nWidth()-cv2iposition.i16iX());

			return {
				cv2iposition.i16iY(),
				(0<=ci16ix_r)?ci16ix_r:INT16(cv2ntrim.i16nHeight()+ci16ix_r)
			};
		}
		static _INLINE_ VOID	BG_stFillAttribute(CUINT32 cui32doffset,CVECTOR2& cv2iposition,CVECTOR2& cv2nsize,CUINT16 cui16cattribute,CVECTOR2& cv2ntrim)noexcept{
			CAUTO					ci16ndestinationx_rest=INT16(stcv2nBG.i16nWidth()-cv2iposition.i16iX());
			CAUTO					ci16ndestinationx_over=INT16(cv2nsize.i16nWidth()-ci16ndestinationx_rest);

			if(
				(ci16ndestinationx_rest<=0)||
				(ci16ndestinationx_over<=0)
			){
				BG_stFillAttribute_Body(
					cui32doffset,
					cv2iposition,
					cv2nsize,
					cui16cattribute,
					cv2ntrim
				);
			}else{
				BG_stFillAttribute_Body(
					cui32doffset,
					cv2iposition,
					{
						ci16ndestinationx_rest,
						cv2nsize.i16nHeight()
					},
					cui16cattribute,
					cv2ntrim
				);
				BG_stFillAttribute_Body(
					cui32doffset,
					{
						stcv2nBG.i16nWidth(),
						cv2iposition.i16iY()
					},
					{
						ci16ndestinationx_over,
						cv2nsize.i16nHeight()
					},
					cui16cattribute,
					cv2ntrim
				);
			}
			return;
		}
		static _INLINE_ VOID	BG_stFillAttribute_Body(CUINT32 cui32doffset,CVECTOR2& cv2iposition,CVECTOR2& cv2nsize,CUINT16 cui16cattribute,CVECTOR2& cv2ntrim)noexcept{
			CAUTO					cv2iposition_r0=BG_stv2iMakePosition(cv2iposition,cv2ntrim);
			CAUTO					cv2nsize_r=stv2nMakeSize_R(cv2nsize);
			CAUTO					cv2iposition_r1=VECTOR2(
				cv2iposition_r0.i16iX(),
				INT16(cv2iposition_r0.i16iY()-cv2nsize_r.i16nHeight()+1)
			);

			SUPER::BG_stFillAttribute(
				cui32doffset,			//	cui32doffset
				cv2iposition_r1,		//	cv2iposition
				cv2nsize_r,				//	cv2nsize
				cui16cattribute			//	cui16cattribute
			);
			return;
		}
		static _INLINE_ VOID	BG_stWriteAttribute(CUINT32 cui32doffset,CVECTOR2& cv2iposition,CUINT16 cui16cattribute,CVECTOR2& cv2ntrim)noexcept{
			SUPER::BG_stWriteAttribute(
				cui32doffset,			//	cui32doffset
				BG_stv2iMakePosition(cv2iposition,cv2ntrim),	//	cv2iposition
				cui16cattribute			//	cui16cattribute
			);
			return;
		}
		static _INLINE_ VOID	BG_stPrint(CUINT32 cui32doffset,CVECTOR2& cv2iposition,const PCUSTR cpcustrstring,CUINT8 cui8ibgpalette,CVECTOR2& cv2ntrim)noexcept{
			CAUTO					cv2iposition_r=BG_stv2iMakePosition(cv2iposition,cv2ntrim);

			SUPER::BG_stPrint_R_Body(
				cui32doffset,
				cv2iposition_r,
				cpcustrstring,
				cui8ibgpalette,
				cv2ntrim
			);
			return;
		}
		template<CVECTOR2 SCLASS_cv2nSize>
		static VOID				BG_stCopyRect(CUINT32 cui32doffset,const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CANVASBG_::CSHAPE& cshpsource,CVECTOR2& cv2iposition,CVECTOR2& cv2ntrim)noexcept{
			using					SCLASS=CANVASBG_SIZED_<SCLASS_cv2nSize>;
			AUTO					shpsource=cshpsource;
			AUTO					v2iposition=cv2iposition;

			SCLASS::stTrimSending(shpsource,v2iposition);
			stTrimReceiving(shpsource,v2iposition,cv2ntrim);
			{
				CAUTO					cv2iposition_r=BG_stv2iMakePosition(v2iposition,cv2ntrim);
				CAUTO					cui32doffset_r=UINT32(cui32doffset+UINT32(CANVASBG_DEVICE::stui16iGetPosition(cv2iposition_r)));
				CAUTO					cpcui16csource0=PCUINT16(PCUINT8(ccvssource.pcui16cGetThis())+SCLASS::stui16iGetPosition(shpsource.v2iPosition));
				CAUTO					ci16idestinationy_end=INT16(v2iposition.i16iX()+shpsource.v2nSize.i16nWidth());
				CAUTO					ci16ndestinationy_over=INT16(ci16idestinationy_end-stcv2nBG.i16nWidth());

				if(
					(stcv2nBG.i16nWidth()<=v2iposition.i16iX())||
					(ci16ndestinationy_over<=0)
				){
					SUPER::BG_stCopyRect_R_Body(
						cui32doffset_r,
						cpcui16csource0,
						SCLASS::stcui16nPitch,
						shpsource.v2nSize
					);
				}else{
					CAUTO					ci16nsource0width=INT16(shpsource.v2nSize.i16nWidth()-ci16ndestinationy_over);

					SUPER::BG_stCopyRect_R_Body(
						cui32doffset_r,
						cpcui16csource0,
						SCLASS::stcui16nPitch,
						{
							ci16nsource0width,
							shpsource.v2nSize.i16nHeight()
						}
					);
					SUPER::BG_stCopyRect_R_Body(
						cui32doffset+UINT32(CANVASBG_DEVICE::stui16iGetPosition(
							{
								cv2iposition_r.i16iX(),
								INT16(ci16idestinationy_end-1)
							}
						)),
						cpcui16csource0+ci16nsource0width,
						SCLASS::stcui16nPitch,
						{
							ci16ndestinationy_over,
							shpsource.v2nSize.i16nHeight()
						}
					);
				}
			}
			return;
		}
		static _INLINE_ UINT16	BG_stui16cReadAttribute(CUINT32 cui32doffset,CVECTOR2& cv2iposition,CVECTOR2& cv2ntrim)noexcept{
			return SUPER::BG_stui16cReadAttribute(cui32doffset,BG_stv2iMakePosition(cv2iposition,cv2ntrim));
		}
	};
}

#endif
