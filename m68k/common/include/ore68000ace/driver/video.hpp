/****************************************************************************
**																			**
**																			**
**								ORE68000ACE									**
**																			**
**	'm68k/ore68000ace/driver/video.hpp'				2026 written by int71	**
 ****************************************************************************/
#ifndef M68K_ORE68000ACE_DRIVER_VIDEO
#define M68K_ORE68000ACE_DRIVER_VIDEO

//
//		include
//

#include				<video/vi71b.hpp>
#include				<ore68000ace/memory.hpp>

//
//		namespace:m68k::ore68000ace::driver
//

namespace m68k::ore68000ace::driver{

	//
	//		class
	//

	class VIDEO;
	using					CVIDEO=const VIDEO;
	using					PVIDEO=VIDEO*;
	using					PCVIDEO=CVIDEO*;

	//
	//		class:VIDEO
	//

	//	VIDEO
	class VIDEO{
	public:

		//
		//		class
		//

		using					DEVICE=											video::VI71B;

		//
		//		const
		//

		using					IDDEVICEMODE=									DEVICE::IDDEVICEMODE;
		using					IDREGISTERW=									DEVICE::IDREGISTERW;
		using					IDREGISTERR=									DEVICE::IDREGISTERR;
		using					IDLAYER=										DEVICE::IDLAYER;
		using					IDVBCOMMAND=									DEVICE::IDVBCOMMAND;
		static constexpr AUTO	DEVICE_stcui16nPort=							DEVICE_VIDEO_stcui16nPort;
		static constexpr AUTO	DEVICE_stcui16dSelectOffset=					DEVICE_VIDEO_stcui16dSelectOffset;
		static constexpr AUTO	DEVICE_stcui16dRegisterOffset=					DEVICE_VIDEO_stcui16dRegisterOffset;
		static constexpr AUTO	DEVICE_stcui16dPaletteOffset=					DEVICE_VIDEO_stcui16dPaletteOffset;
		static constexpr AUTO	ATTRIBUTE_SPRITE_stcui8iHInvertBit=				DEVICE::ATTRIBUTE_SPRITE_stcui8iHInvertBit;
		static constexpr AUTO	ATTRIBUTE_SPRITE_stcui16cHInvertMask=			DEVICE::ATTRIBUTE_SPRITE_stcui16cHInvertMask;
		static constexpr AUTO	ATTRIBUTE_SPRITE_stcui8iVInvertBit=				DEVICE::ATTRIBUTE_SPRITE_stcui8iVInvertBit;
		static constexpr AUTO	ATTRIBUTE_SPRITE_stcui16cVInvertMask=			DEVICE::ATTRIBUTE_SPRITE_stcui16cVInvertMask;
		static constexpr AUTO	VRAM_PATTERNCHR_SPRITE_stcui16dDefaultOffset=	UINT16(VRAM_PATTERN_SPRITE_stcui32dDefaultOffset>>5);
		static constexpr AUTO	VRAM_PATTERNCHR_BG0_stcui16dDefaultOffset=		UINT16(VRAM_PATTERN_BG0_stcui32dDefaultOffset>>5);
		static constexpr AUTO	VRAM_PATTERNCHR_BG1_stcui16dDefaultOffset=		UINT16(VRAM_PATTERN_BG1_stcui32dDefaultOffset>>5);
		static constexpr AUTO	VRAM_PATTERNCHR_BG2_stcui16dDefaultOffset=		UINT16(VRAM_PATTERN_BG2_stcui32dDefaultOffset>>5);
		static constexpr AUTO	VRAM_PATTERNCHR_BG3_stcui16dDefaultOffset=		UINT16(VRAM_PATTERN_BG3_stcui32dDefaultOffset>>5);

		//
		//		class
		//

		//	ST
		class ST;
		using					CST=const ST;
		using					PST=ST*;
		using					PCST=CST*;

		//
		//		class:ST
		//

		//	ST
		class ST{
		public:
		};

		//
		//		body:VIDEO
		//

	private:
		static inline ST		st;
	public:
		static VOID				stNew(VOID)noexcept;
		static VOID				stDelete(VOID)noexcept;
		static VOID				stOff(VOID)noexcept;
		static VOID				stSetCRT640x480P(VOID)noexcept;
		static VOID				stSetCRT320x240P(VOID)noexcept;
		static VOID				stSetCRT320x240I(VOID)noexcept;
		static VOID				stSetCRT256x192P(VOID)noexcept;
		static VOID				stSetCRT256x192I(VOID)noexcept;
		static VOID				stSetCRT256x212P(VOID)noexcept;
		static VOID				stSetCRT256x212I(VOID)noexcept;
		static _INLINE_ VOID	stWrite(const IDREGISTERW cidregister,CUINT16 cui16value)noexcept{
			DEVICE_stui16Delegate(DEVICE_stcui16dSelectOffset)=(UINT16(IDDEVICEMODE::RegisterW)<<8)|UINT16(cidregister);
			DEVICE_stui16Delegate(DEVICE_stcui16dRegisterOffset)=cui16value;
			return;
		}
		static _INLINE_ UINT16	stui16Read(const IDREGISTERR cidregister)noexcept{
			DEVICE_stui16Delegate(DEVICE_stcui16dSelectOffset)=(UINT16(IDDEVICEMODE::RegisterR)<<8)|UINT16(cidregister);
			return DEVICE_stcui16GetThis(DEVICE_stcui16dRegisterOffset);
		}
		constexpr UINT16		ui16cGetColor(CBYTE cbired,CBYTE cbigreen,CBYTE cbiblue)noexcept{
			return DEVICE::stui16cGetColor(cbired,cbigreen,cbiblue);
		}
		constexpr UINT16		ui16cGetColor(CDWORD cdwvalue)noexcept{
			return DEVICE::stui16cGetColor(cdwvalue);
		}
		static _INLINE_ VOID	PALETTE_stSetWrite(CUINT8 cui8iaddress)noexcept{
			DEVICE_stui16Delegate(DEVICE_stcui16dSelectOffset)=(UINT16(IDDEVICEMODE::Palette)<<8)|UINT16(cui8iaddress);
			return;
		}
		static _INLINE_ VOID	PALETTE_stWrite(CUINT16 cui16ccolor)noexcept{
			DEVICE_stui16Delegate(DEVICE_stcui16dPaletteOffset)=cui16ccolor;
			return;
		}
		static VOID				PALETTE_stWrite(CUINT8 cui8iaddress,const PCUINT16 cpcui16ccolor,CUINT8 cui8nsize)noexcept;
		static VOID				VRAM_TEXT_stWrite(CUINT16 cui16ix,CUINT16 cui16iy,const PCUSTR cpcustrsource,CUINT8 cui8ccolor)noexcept;
		static _INLINE_ VOID	VRAM_SPRITE_stWrite(CUINT8 cui8ithis,CUINT16 cui16ix,CUINT16 cui16iy,CUINT16 cui16ipattern,CUINT8 cui8ipalette,CUINT8 cui8nwidth,CUINT8 cui8nheight,COFWBOOL cehinvert,COFWBOOL cevinvert,CUINT8 cui8ipriority)noexcept{
			CAUTO					cui32iaddress=VRAM_ATTRIBUTE_SPRITE_stcui32dDefaultOffset+(UINT32(cui8ithis)<<3);

			MEMORYS::VRAM_stui16DelegateThis(cui32iaddress+0x0)=cui16ix;
			MEMORYS::VRAM_stui16DelegateThis(cui32iaddress+0x2)=cui16iy;
			MEMORYS::VRAM_stui16DelegateThis(cui32iaddress+0x4)=(UINT16(cui8ipalette)<<0xc)|(cevinvert?ATTRIBUTE_SPRITE_stcui16cVInvertMask:0)|(cehinvert?ATTRIBUTE_SPRITE_stcui16cHInvertMask:0)|cui16ipattern;
			MEMORYS::VRAM_stui16DelegateThis(cui32iaddress+0x6)=(UINT16(cui8nheight)<<0xe)|(UINT16(cui8nwidth)<<0xc)|(UINT16(cui8ipriority)<<0x8);
			return;
		}
	private:
		static _INLINE_ _UNDISCARDABLE_ UINT16&	DEVICE_stui16Delegate(CUINT16 cui16iaddress)noexcept{
			return MEMORYS::DEVICE_stui16DelegateThis(DEVICE_VIDEO_stcui16dOffsetS+cui16iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_ CUINT16&	DEVICE_stcui16GetThis(CUINT16 cui16iaddress)noexcept{
			return MEMORYS::DEVICE_stcui16GetThis(DEVICE_VIDEO_stcui16dOffsetS+cui16iaddress);
		}
	};
}

#endif
