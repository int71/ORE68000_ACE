/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'common/rom_sound.hpp'							2025 written by int71	**
 ****************************************************************************/
#ifndef I71_COMMON_ROM_SOUND
#define I71_COMMON_ROM_SOUND

//
//		include
//

#include				"map.hpp"

//
//		namespace:m68k::i71::common
//

namespace m68k::i71::common{

	//
	//		class
	//

	class ROM_SOUND;

	//
	//		class:ROM_SOUND
	//

	class ROM_SOUND{
	public:

		//
		//		const
		//

		static constexpr AUTO	stcui32iAddressS=								ore68000ace::ROM_SOUND_stcui32iAddressS;

		//
		//		class
		//

		//	BANK
		class BANK;

		//
		//		class:BANK
		//

		class BANK{
		public:

			//
			//		const
			//

			static constexpr UINT32	FM_BGM_stcui32iAddressS=						stcui32iAddressS+0x000000;
			static constexpr UINT32	FM_SE_stcui32iAddressS=							stcui32iAddressS+0x001000;
			static constexpr UINT32	PCM_stcui32iAddressS=							stcui32iAddressS+0x002000;
			static constexpr UINT32	PCM_PCMM_stcui32iAddressS=						stcui32iAddressS+0x002800;
		};
	};
}
#endif
