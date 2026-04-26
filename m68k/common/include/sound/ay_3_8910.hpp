/****************************************************************************
**																			**
**																			**
**									m68k									**
**																			**
**	'm68k/sound/ay_3_8910.hpp'						2026 written by int71	**
 ****************************************************************************/
#ifndef M68K_SOUND_AY_3_8910
#define M68K_SOUND_AY_3_8910

//
//		include
//

#include				<base.hpp>

//
//		namespace:m68k::sound
//

namespace m68k::sound{

	//
	//		class
	//

	class AY_3_8910;

	//
	//		class:AY_3_8910
	//

	class AY_3_8910{
	public:

		//
		//		const
		//

		class _IDREGISTER{
		public:
			enum BODY:UINT8{
				Ch0DivRatioL=			0x00,
				Ch0DivRatioH4=			0x01,
				Ch1DivRatioL=			0x02,
				Ch1DivRatioH4=			0x03,
				Ch2DivRatioL=			0x04,
				Ch2DivRatioH4=			0x05,
				NoiseDivRatio5=			0x06,
				Enable=					0x07,
				Ch0Volume4=				0x08,
				Ch1Volume4=				0x09,
				Ch2Volume4=				0x0a,
				EnvDivRatioL=			0x0b,
				EnvDivRatioH=			0x0c,
				EnvShape4=				0x0d,
				IO0=					0x0e,
				IO1=					0x0f
			};
		};
		using					IDREGISTER=_IDREGISTER::BODY;
		static constexpr UINT8	stcui8nRegister=		0x10;
		static constexpr UINT16	stcui16nPort=			0x0003;
		static constexpr UINT16	stcui16dSelectOffset=	0x0000;
		static constexpr UINT16	stcui16dWriteOffset=	0x0001;
		static constexpr UINT16	stcui16dReadOffset=		0x0002;
	};
}

#endif
