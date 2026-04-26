/****************************************************************************
**																			**
**																			**
**									m68k									**
**																			**
**	'm68k/video/vi71.hpp'							2026 written by int71	**
 ****************************************************************************/
#ifndef M68K_VIDEO_VI71
#define M68K_VIDEO_VI71

//
//		include
//

#include				<base.hpp>

//
//		namespace:m68k::video
//

namespace m68k::video{

	//
	//		class
	//

	class VI71;

	//
	//		class:VI71
	//

	class VI71{
	public:

		//
		//		const
		//

		class _IDREGISTER{
		public:
			enum BODY:UINT8{
				RWCRTHBlank=			0x00,
				RWCRTHVisible=			0x01,
				RWCRTVBlank=			0x02,
				RWCRTVVisible=			0x03,
				RWComposite0=			0x04,
				RWComposite1=			0x05,
				RWTextAddress=			0x08,
				RWBG0Address=			0x09,
				RWBG1Address=			0x0a,
				RWSpriteAddress=		0x0b,
				RWTextOffsetX=			0x10,
				RWTextOffsetY=			0x11,
				RWBG0OffsetX=			0x12,
				RWBG0OffsetY=			0x13,
				RWBG1OffsetX=			0x14,
				RWBG1OffsetY=			0x15,
				RWSpriteOffsetX=		0x16,
				RWSpriteOffsetY=		0x17,
				RWInterrupt=			0x1e,
				RScanLine=				0x1f
			};
		};
		using					IDREGISTER=_IDREGISTER::BODY;
		static constexpr UINT8	stcui8nRegister=		0x20;
		static constexpr UINT16	stcui16nPort=			0x000c;
		static constexpr UINT16	stcui16dSelectOffset=	0x0000;
		static constexpr UINT16	stcui16dWriteOffset=	0x0002;
		static constexpr UINT16	stcui16dReadOffset=		0x0004;
		static constexpr UINT16	stcui16dPaletteSelectOffset=0x0008;
		static constexpr UINT16	stcui16dPaletteWriteOffset=0x000a;
		static constexpr UINT16	stcui16dPaletteReadOffset=0x000c;
	}
}

#endif
