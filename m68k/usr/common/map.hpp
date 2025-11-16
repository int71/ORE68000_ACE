/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'common/map.hpp'								2025 written by int71	**
 ****************************************************************************/
#ifndef I71_COMMON_MAP
#define I71_COMMON_MAP

//
//		include
//

#include				<hid/keyboard.hpp>
#include				<hid/joystick.hpp>
#include				<ore68000ace/driver/video.hpp>
#include				<ore68000ace/driver/sound.hpp>

//
//		namespace:m68k::i71::common
//

namespace m68k::i71::common{

	//
	//		class
	//

	//	MAP
	class MAP;

	//
	//		class:MAP
	//

	class MAP{
	public:

		//
		//		class
		//

		//	COM
		class COM;
		//	VRAM
		class VRAM;
		//	PCMRAM
		class PCMRAM;
		//	DEVICE
		class DEVICE;
		//	VIDEO
		class VIDEO;
		//	SOUND
		class SOUND;
		//	KEYBOARD
		class KEYBOARD;
		//	JOYSTICK
		class JOYSTICK;

		//
		//		class:COM
		//

		class COM{
		public:

			//
			//		const
			//

			static constexpr AUTO	stcui32iAddressM=								ore68000ace::COM_stcui32iAddressM;
			static constexpr AUTO	stcui32iAddressS=								ore68000ace::COM_stcui32iAddressS;
			static constexpr AUTO	stcui32nSize=									ore68000ace::COM_stcui32nSize;
		};

		//
		//		class:VRAM
		//

		class VRAM{
		public:

			//
			//		const
			//

			static constexpr AUTO	stcui32iAddressS=								ore68000ace::VRAM_stcui32iAddressS;
			static constexpr AUTO	stcui32nSize=									ore68000ace::VRAM_stcui32nSize;
			static constexpr AUTO	TEXT_stcui32dOffset=							ore68000ace::VRAM_TEXT_stcui32dDefaultOffset;
			static constexpr AUTO	PATTERN_SPRITE_stcui32dOffset=					ore68000ace::VRAM_PATTERN_SPRITE_stcui32dDefaultOffset;
			static constexpr AUTO	PATTERN_BG0_stcui32dOffset=						ore68000ace::VRAM_PATTERN_BG0_stcui32dDefaultOffset;
			static constexpr AUTO	PATTERN_BG1_stcui32dOffset=						ore68000ace::VRAM_PATTERN_BG1_stcui32dDefaultOffset;
			static constexpr AUTO	PATTERN_BG2_stcui32dOffset=						ore68000ace::VRAM_PATTERN_BG2_stcui32dDefaultOffset;
			static constexpr AUTO	PATTERN_BG3_stcui32dOffset=						ore68000ace::VRAM_PATTERN_BG3_stcui32dDefaultOffset;
			static constexpr AUTO	ATTRIBUTE_SPRITE_stcui32dOffset=				ore68000ace::VRAM_ATTRIBUTE_SPRITE_stcui32dDefaultOffset;
			static constexpr AUTO	ATTRIBUTE_BG0_stcui32dOffset=					ore68000ace::VRAM_ATTRIBUTE_BG0_stcui32dDefaultOffset;
			static constexpr AUTO	ATTRIBUTE_BG1_stcui32dOffset=					ore68000ace::VRAM_ATTRIBUTE_BG1_stcui32dDefaultOffset;
			static constexpr AUTO	ATTRIBUTE_BG2_stcui32dOffset=					ore68000ace::VRAM_ATTRIBUTE_BG2_stcui32dDefaultOffset;
			static constexpr AUTO	ATTRIBUTE_BG3_stcui32dOffset=					ore68000ace::VRAM_ATTRIBUTE_BG3_stcui32dDefaultOffset;
		};

		//
		//		class:PCMRAM
		//

		class PCMRAM{
		public:

			//
			//		const
			//

			static constexpr AUTO	stcui32iAddressS=								ore68000ace::PCMRAM_stcui32iAddressS;
			static constexpr AUTO	stcui32nSize=									ore68000ace::PCMRAM_stcui32nSize;
		};

		//
		//		class:DEVICE
		//

		class DEVICE{
		public:

			//
			//		const
			//

			static constexpr AUTO	stcui32iAddress=								ore68000ace::DEVICE_stcui32iAddress;
			static constexpr AUTO	stcui32nSize=									ore68000ace::DEVICE_stcui32nSize;
			static constexpr AUTO	INTERRUPTER_stcui16dOffsetM=					ore68000ace::DEVICE_INTERRUPTER_stcui16dOffsetM;
			static constexpr AUTO	INTERRUPTER_stcui16dOffsetS=					ore68000ace::DEVICE_INTERRUPTER_stcui16dOffsetS;
			static constexpr AUTO	INTERRUPTER_stcui16nPort=						ore68000ace::DEVICE_INTERRUPTER_stcui16nPort;
			static constexpr AUTO	INTERRUPTER_stcui16dDataOffset=					ore68000ace::DEVICE_INTERRUPTER_stcui16dDataOffset;
			static constexpr AUTO	COM_stcui16dOffsetM=							ore68000ace::DEVICE_COM_stcui16dOffsetM;
			static constexpr AUTO	COM_stcui16dOffsetS=							ore68000ace::DEVICE_COM_stcui16dOffsetS;
			static constexpr AUTO	COM_stcui16nPort=								ore68000ace::DEVICE_COM_stcui16nPort;
			static constexpr AUTO	COM_stcui16dDataOffset=							ore68000ace::DEVICE_COM_stcui16dDataOffset;
			static constexpr AUTO	VIDEO_stcui16dOffsetS=							ore68000ace::DEVICE_VIDEO_stcui16dOffsetS;
			static constexpr AUTO	VIDEO_stcui16nPort=								ore68000ace::DEVICE_VIDEO_stcui16nPort;
			static constexpr AUTO	VIDEO_stcui16dSelectOffset=						ore68000ace::DEVICE_VIDEO_stcui16dSelectOffset;
			static constexpr AUTO	VIDEO_stcui16dRegisterOffset=					ore68000ace::DEVICE_VIDEO_stcui16dRegisterOffset;
			static constexpr AUTO	VIDEO_stcui16dPaletteOffset=					ore68000ace::DEVICE_VIDEO_stcui16dPaletteOffset;
			static constexpr AUTO	SOUND_stcui16dOffsetS=							ore68000ace::DEVICE_SOUND_stcui16dOffsetS;
			static constexpr AUTO	SOUND_stcui16nPort=								ore68000ace::DEVICE_SOUND_stcui16nPort;
			static constexpr AUTO	SOUND_FM_stcui16dSelectWOffset=					ore68000ace::DEVICE_SOUND_FM_stcui16dSelectWOffset;
			static constexpr AUTO	SOUND_PCM_stcui16dSelectWOffset=				ore68000ace::DEVICE_SOUND_PCM_stcui16dSelectWOffset;
			static constexpr AUTO	SOUND_stcui16dSelectROffset=					ore68000ace::DEVICE_SOUND_stcui16dSelectROffset;
			static constexpr AUTO	SOUND_stcui16dDataOffset=						ore68000ace::DEVICE_SOUND_stcui16dDataOffset;
			static constexpr AUTO	KEYBOARD_stcui16dOffsetS=						ore68000ace::DEVICE_KEYBOARD_stcui16dOffsetS;
			static constexpr AUTO	KEYBOARD_stcui16nPort=							ore68000ace::DEVICE_KEYBOARD_stcui16nPort;
			static constexpr AUTO	KEYBOARD_stcui16dSelectOffset=					ore68000ace::DEVICE_KEYBOARD_stcui16dSelectOffset;
			static constexpr AUTO	KEYBOARD_stcui16dDataOffset=					ore68000ace::DEVICE_KEYBOARD_stcui16dDataOffset;
			static constexpr AUTO	JOYSTICK_stcui16dOffsetS=						ore68000ace::DEVICE_JOYSTICK_stcui16dOffsetS;
			static constexpr AUTO	JOYSTICK_stcui16nPort=							ore68000ace::DEVICE_JOYSTICK_stcui16nPort;
			static constexpr AUTO	JOYSTICK_stcui16dSelectOffset=					ore68000ace::DEVICE_JOYSTICK_stcui16dSelectOffset;
			static constexpr AUTO	JOYSTICK_stcui16dDataOffset=					ore68000ace::DEVICE_JOYSTICK_stcui16dDataOffset;
			static constexpr AUTO	HPC_stcui16dOffsetM=							ore68000ace::DEVICE_HPC_stcui16dOffsetM;
			static constexpr AUTO	HPC_stcui16dOffsetS=							ore68000ace::DEVICE_HPC_stcui16dOffsetS;
			static constexpr AUTO	HPC_stcui16nPort=								ore68000ace::DEVICE_HPC_stcui16nPort;
			static constexpr AUTO	HPC_stcui16dDataOffset=							ore68000ace::DEVICE_HPC_stcui16dDataOffset;
			static constexpr AUTO	LFSR_stcui16dOffsetM=							ore68000ace::DEVICE_LFSR_stcui16dOffsetM;
			static constexpr AUTO	LFSR_stcui16dOffsetS=							ore68000ace::DEVICE_LFSR_stcui16dOffsetS;
			static constexpr AUTO	LFSR_stcui16nPort=								ore68000ace::DEVICE_LFSR_stcui16nPort;
			static constexpr AUTO	LFSR_stcui16dDataOffset=						ore68000ace::DEVICE_LFSR_stcui16dDataOffset;
			static constexpr AUTO	SERIAL_stcui16dOffsetM=							ore68000ace::DEVICE_SERIAL_stcui16dOffsetM;
			static constexpr AUTO	SERIAL_stcui16dOffsetS=							ore68000ace::DEVICE_SERIAL_stcui16dOffsetS;
			static constexpr AUTO	SERIAL_stcui16nPort=							ore68000ace::DEVICE_SERIAL_stcui16nPort;
			static constexpr AUTO	SERIAL_stcui16dDataOffset=						ore68000ace::DEVICE_SERIAL_stcui16dDataOffset;
		};

		//
		//		class:VIDEO
		//

		class VIDEO{
		public:

			//
			//		class
			//

			//	DEVICE
			using					DEVICE=											video::VI71B;
			//	DRIVER
			using					DRIVER=											ore68000ace::driver::VIDEO;
			using					CDRIVER=const DRIVER;
			using					PDRIVER=DRIVER*;
			using					PCDRIVER=CDRIVER*;
		};

		//
		//		class:SOUND
		//

		class SOUND{
		public:

			//
			//		class
			//

			//	DEVICE
			using					DEVICE=											sound::YM2151B;
			//	DRIVER
			using					DRIVER=											ore68000ace::driver::SOUND;
			using					CDRIVER=const DRIVER;
			using					PDRIVER=DRIVER*;
			using					PCDRIVER=CDRIVER*;
		};

		//
		//		class:KEYBOARD
		//

		class KEYBOARD{
		public:

			//
			//		class
			//

			using					DEVICE=											hid::KEYBOARD;

			//
			//		const
			//

			using					IDKEY=											DEVICE::IDKEY;
			static constexpr AUTO	stcui8nKey=										DEVICE::stcui8nKey;
			static constexpr AUTO	stcui8nBank=									DEVICE::stcui8nBank;
		};

		//
		//		class:JOYSTICK
		//

		class JOYSTICK{
		public:

			//
			//		class
			//

			using					DEVICE=											hid::JOYSTICK;

			//
			//		const
			//

			using					IDBUTTON=										DEVICE::IDBUTTON;
			static constexpr AUTO	stcui8nBank=									DEVICE::stcui8nBank;
		};
	};
}
#endif
