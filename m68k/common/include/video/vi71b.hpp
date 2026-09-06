/****************************************************************************
**																			**
**																			**
**									m68k									**
**																			**
**	'm68k/video/vi71b.hpp'							2026 written by int71	**
 ****************************************************************************/
#ifndef M68K_VIDEO_VI71B
#define M68K_VIDEO_VI71B

//
//		include
//

#include				"../base.hpp"

//
//		namespace:m68k::video
//

namespace m68k::video{

	//
	//		class
	//

	class VI71B;

	//
	//		class:VI71B
	//

	class VI71B{
	public:

		//
		//		const
		//

		class _IDDEVICEMODE{
		public:
			enum BODY:UINT8{
				RegisterW=				0x00,
				RegisterR=				0x01,
				Palette=				0x02
			};
		};
		using					IDDEVICEMODE=_IDDEVICEMODE::BODY;
		class _IDREGISTERW{
		public:
			enum BODY:UINT8{
				CRTHBlank=				0x00,
				CRTHVisible=			0x01,
				CRTVBlank=				0x02,
				CRTVVisible=			0x03,
				Composite0=				0x04,
				Composite1=				0x05,
				TextAddress=			0x08,
				SpriteAddress=			0x09,
				BG0Address=				0x0c,
				BG1Address=				0x0d,
				BG2Address=				0x0e,
				BG3Address=				0x0f,
				TextOffsetX=			0x10,
				TextOffsetY=			0x11,
				SpriteOffsetX=			0x12,
				SpriteOffsetY=			0x13,
				BG0OffsetX=				0x18,
				BG0OffsetY=				0x19,
				BG1OffsetX=				0x1a,
				BG1OffsetY=				0x1b,
				BG2OffsetX=				0x1c,
				BG2OffsetY=				0x1d,
				BG3OffsetX=				0x1e,
				BG3OffsetY=				0x1f,
				Interrupt=				0x20,
				VBCommand=				0x28,
				VBCommandValue=			0x29,
				VBCommandWidth=			0x2a,
				VBCommandHeight=		0x2b,
				VBCommandDX=			0x2c,
				VBCommandDY=			0x2d,
				VBCommandSX=			0x2e,
				VBCommandSY=			0x2f
			};
		};
		using					IDREGISTERW=_IDREGISTERW::BODY;
		class _IDREGISTERR{
		public:
			enum BODY:UINT8{
				Status=					0x00,
				VBCommandStatus=		0x01
			};
		};
		using					IDREGISTERR=_IDREGISTERR::BODY;
		class _IDLAYER{
		public:
			enum BODY:UINT8{
				Text=					0x00,
				SpritePriority0=		0x01,
				SpritePriority1=		0x02,
				SpritePriority2=		0x03,
				BG0=					0x04,
				BG1=					0x05,
				BG2=					0x06,
				BG3=					0x07,
				Reserved0=				0x08,
				Reserved1=				0x09,
				Reserved2=				0x0a,
				Reserved3=				0x0b,
				Reserved4=				0x0c,
				Reserved5=				0x0d,
				Reserved6=				0x0e,
				None=					0x0f
			};
		};
		using					IDLAYER=_IDLAYER::BODY;
		class _IDVBCOMMAND{
		public:
			enum BODY:UINT8{
				None=					0x00,
				FillM=					0x10,
				CopyM2M=				0x20,
				CopyM2P=				0x28
			};
		};
		using					IDVBCOMMAND=_IDVBCOMMAND::BODY;
		class _IDCRTMODE{
		public:
			enum BODY:UINT8{
				Typical640x480P=		0,
				Typical320x240P=		1,
				Typical320x240I=		2,
				Typical256x192P=		3,
				Typical256x192I=		4
			};
		};
		using					IDCRTMODE=_IDCRTMODE::BODY;
		static constexpr UINT8	stcui8nRegisterW=								0x30;
		static constexpr UINT8	stcui8nRegisterR=								0x02;
		static constexpr UINT32	VRAM_stcui32nSize=								0x100000;
		static constexpr UINT16	PALETTE_stcui16nSize=							256;
		static constexpr UINT16	SPRITE_stcui16nNumber=							256;
		static constexpr UINT8	REGISTERW_Interrupt_stcui8iScanLineInterruptNumberBit=	0x0;
		static constexpr UINT16	REGISTERW_Interrupt_stcui16cScanLineInterruptNumberMask=	0x3ff<<REGISTERW_Interrupt_stcui8iScanLineInterruptNumberBit;
		static constexpr UINT8	REGISTERW_Interrupt_stcui8iHBlankInterruptEnableBit=	0xe;
		static constexpr UINT16	REGISTERW_Interrupt_stcui16cHBlankInterruptEnableMask=	1<<REGISTERW_Interrupt_stcui8iHBlankInterruptEnableBit;
		static constexpr UINT8	REGISTERW_Interrupt_stcui8iVBlankInterruptEnableBit=	0xf;
		static constexpr UINT16	REGISTERW_Interrupt_stcui16cVBlankInterruptEnableMask=	1<<REGISTERW_Interrupt_stcui8iVBlankInterruptEnableBit;
		static constexpr UINT8	REGISTERW_VBCommand_stcui8iCommandBit=			0x0;
		static constexpr UINT16	REGISTERW_VBCommand_stcui16cCommandMask=		0xff<<REGISTERW_VBCommand_stcui8iCommandBit;
		static constexpr UINT8	REGISTERW_VBCommand_stcui8iPitchShiftBit=		0x8;
		static constexpr UINT16	REGISTERW_VBCommand_stcui16cPitchShiftMask=		0xf<<REGISTERW_VBCommand_stcui8iPitchShiftBit;
		static constexpr UINT8	REGISTERR_Status_stcui8iScanLineNumberBit=		0x0;
		static constexpr UINT16	REGISTERR_Status_stcui16cScanLineNumberMask=	0x3ff<<REGISTERR_Status_stcui8iScanLineNumberBit;
		static constexpr UINT8	REGISTERR_Status_stcui8iHBlankInterruptedBit=	0xe;
		static constexpr UINT16	REGISTERR_Status_stcui16cHBlankInterruptedMask=	1<<REGISTERR_Status_stcui8iHBlankInterruptedBit;
		static constexpr UINT8	REGISTERR_Status_stcui8iVBlankBit=				0xf;
		static constexpr UINT16	REGISTERR_Status_stcui16cVBlankMask=			1<<REGISTERR_Status_stcui8iVBlankBit;
		static constexpr UINT8	ATTRIBUTE_SPRITE_stcui8iHInvertBit=				0xa;
		static constexpr UINT16	ATTRIBUTE_SPRITE_stcui16cHInvertMask=			1<<ATTRIBUTE_SPRITE_stcui8iHInvertBit;
		static constexpr UINT8	ATTRIBUTE_SPRITE_stcui8iVInvertBit=				0xb;
		static constexpr UINT16	ATTRIBUTE_SPRITE_stcui16cVInvertMask=			1<<ATTRIBUTE_SPRITE_stcui8iVInvertBit;
	public:
		static constexpr UINT16	stui16cGetColor(CUINT8 cui8ired,CUINT8 cui8igreen,CUINT8 cui8iblue)noexcept{
			return (
				UINT16(((cui8ired<0xe8)?(cui8ired+8)>>4:0xf)<<0)|
				UINT16(((cui8igreen<0xe8)?(cui8igreen+8)>>4:0xf)<<4)|
				UINT16(((cui8iblue<0xe8)?(cui8iblue+8)>>4:0xf)<<8)
			);
		}
		static constexpr UINT16	stui16cGetColor(CUINT32 cui32cvalue)noexcept{
			return stui16cGetColor(
				UINT8((cui32cvalue>>16)&0xff),
				UINT8((cui32cvalue>> 8)&0xff),
				UINT8((cui32cvalue>> 0)&0xff)
			);
		}
	};

	//
	//		custom
	//

	template<class SCLASS>
	constexpr VI71B::IDREGISTERW	operator +(const VI71B::IDREGISTERW cidregister,const SCLASS& cxdoffset)noexcept{
		return VI71B::IDREGISTERW(UINT8(cidregister)+cxdoffset);
	}
	template<class SCLASS>
	constexpr VI71B::IDREGISTERR	operator +(const VI71B::IDREGISTERR cidregister,const SCLASS& cxdoffset)noexcept{
		return VI71B::IDREGISTERR(UINT8(cidregister)+cxdoffset);
	}
}

#endif
