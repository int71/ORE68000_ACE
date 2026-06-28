/****************************************************************************
**																			**
**																			**
**								ORE68000ACE									**
**																			**
**	'm68k/ore68000ace/map.hpp'						2026 written by int71	**
 ****************************************************************************/
#ifndef M68K_ORE68000ACE_MAP
#define M68K_ORE68000ACE_MAP

//
//		include
//

#include				"../video/vi71b.hpp"
#include				"../sound/ym2151b.hpp"
#include				"../misc/collider.hpp"

//
//		namespace:m68k::ore68000ace
//

namespace m68k::ore68000ace{

	//
	//		primitive
	//

	//	PERIOD
	using					PERIOD=INT32;
	using					CPERIOD=const PERIOD;
	using					PPERIOD=PERIOD*;
	using					PCPERIOD=CPERIOD*;
	//	UPERIOD
	using					UPERIOD=UINT32;
	using					CUPERIOD=const UPERIOD;
	using					PUPERIOD=UPERIOD*;
	using					PCUPERIOD=CUPERIOD*;

	//
	//		const
	//

	//	<MAIN>
	//	ROM			000000-7f0000	CODE
	//				7fe000-7ff000	ATAN
	//				7ff000-7ff400	TRIG(三角関数)
	//	RAM			800000-a00000
	//	COLLIDER	fc0000-fc0200	コライダパラメータメモリ
	//	COM			fe0000-ff0000	M/Sコミュニケーション用非対称アクセスメモリ
	//	I/O			ff8000-
	//	<SUB>
	//	ROM			000000-400000	CODE
	//				400000-700000	VIDEO(画像系)
	//				700000-7c0000	SOUND(音系)
	//				7c0000-7e0000	FONT
	//				7fe000-7ff000	ATAN
	//				7ff000-7ff400	TRIG(三角関数)
	//	RAM			800000-a00000
	//	PCMRAM		bf0000-c00000	YM2151B波形メモリ
	//	VRAM		c00000-d00000
	//	COLLIDER	fc0000-fc0200	コライダパラメータメモリ
	//	COM			fe0000-ff0000	M/Sコミュニケーション用非対称アクセスメモリ
	//	I/O			ff8000-
	static constexpr UPERIOD	stcuprdnCPUFrequencyHzM=					16'000'000;
	static constexpr UPERIOD	stcuprdnCPUFrequencyHzS=					16'000'000;
	static constexpr UINT32	ROM_stcui32iAddressM=							0x000000;
	static constexpr UINT32	ROM_stcui32iAddressS=							0x000000;
	static constexpr UINT32	ROM_stcui32nSizeM=								0x800000;
	static constexpr UINT32	ROM_stcui32nSizeS=								0x800000;
	static constexpr UINT32	ROM_M68K_stcui32dOffsetM=						0x000000;
	static constexpr UINT32	ROM_M68K_stcui32dOffsetS=						0x000000;
	static constexpr UINT32	ROM_M68K_stcui32iAddressM=						ROM_stcui32iAddressM+ROM_M68K_stcui32dOffsetM;
	static constexpr UINT32	ROM_M68K_stcui32iAddressS=						ROM_stcui32iAddressS+ROM_M68K_stcui32dOffsetS;
	static constexpr UINT32	ROM_M68K_stcui32nSizeM=							0x7f0000;
	static constexpr UINT32	ROM_M68K_stcui32nSizeS=							0x400000;
	static constexpr UINT32	ROM_VECTOR_stcui32dOffsetM=						ROM_M68K_stcui32dOffsetM;
	static constexpr UINT32	ROM_VECTOR_stcui32dOffsetS=						ROM_M68K_stcui32dOffsetS;
	static constexpr UINT32	ROM_VECTOR_stcui32iAddressM=					ROM_stcui32iAddressM+ROM_VECTOR_stcui32dOffsetM;
	static constexpr UINT32	ROM_VECTOR_stcui32iAddressS=					ROM_stcui32iAddressS+ROM_VECTOR_stcui32dOffsetS;
	static constexpr UINT32	ROM_VECTOR_stcui32nSizeM=						0x000400;
	static constexpr UINT32	ROM_VECTOR_stcui32nSizeS=						0x000400;
	static constexpr UINT32	ROM_CODE_stcui32dOffsetM=						ROM_VECTOR_stcui32dOffsetM+ROM_VECTOR_stcui32nSizeM;
	static constexpr UINT32	ROM_CODE_stcui32dOffsetS=						ROM_VECTOR_stcui32dOffsetS+ROM_VECTOR_stcui32nSizeS;
	static constexpr UINT32	ROM_CODE_stcui32iAddressM=						ROM_stcui32iAddressM+ROM_CODE_stcui32dOffsetM;
	static constexpr UINT32	ROM_CODE_stcui32iAddressS=						ROM_stcui32iAddressS+ROM_CODE_stcui32dOffsetS;
	static constexpr UINT32	ROM_CODE_stcui32nSizeM=							ROM_M68K_stcui32nSizeM-ROM_CODE_stcui32iAddressM;
	static constexpr UINT32	ROM_CODE_stcui32nSizeS=							ROM_M68K_stcui32nSizeS-ROM_CODE_stcui32iAddressS;
	static constexpr UINT32	ROM_VIDEO_stcui32dOffsetS=						0x400000;
	static constexpr UINT32	ROM_VIDEO_stcui32iAddressS=						ROM_stcui32iAddressS+ROM_VIDEO_stcui32dOffsetS;
	static constexpr UINT32	ROM_VIDEO_stcui32nSize=							0x300000;
	static constexpr UINT32	ROM_SOUND_stcui32dOffsetS=						0x700000;
	static constexpr UINT32	ROM_SOUND_stcui32iAddressS=						ROM_stcui32iAddressS+ROM_SOUND_stcui32dOffsetS;
	static constexpr UINT32	ROM_SOUND_stcui32nSize=							0x0c0000;
	static constexpr UINT32	ROM_FONT_stcui32dOffsetS=						0x7c0000;
	static constexpr UINT32	ROM_FONT_stcui32iAddressS=						ROM_stcui32iAddressS+ROM_FONT_stcui32dOffsetS;
	static constexpr UINT32	ROM_FONT_stcui32nSize=							0x020000;
	static constexpr UINT8	ATAN_stcui8nTableBit=							6;
	static constexpr UINT16	ATAN_stcui16nTableSide=							1<<ATAN_stcui8nTableBit;
	static constexpr UINT32	ROM_ATAN_stcui32dOffsetM=						0x7fe000;
	static constexpr UINT32	ROM_ATAN_stcui32dOffsetS=						0x7fe000;
	static constexpr UINT32	ROM_ATAN_stcui32iAddressM=						ROM_stcui32iAddressM+ROM_ATAN_stcui32dOffsetM;
	static constexpr UINT32	ROM_ATAN_stcui32iAddressS=						ROM_stcui32iAddressS+ROM_ATAN_stcui32dOffsetS;
	static constexpr UINT32	ROM_ATAN_stcui32nSize=							ATAN_stcui16nTableSide*ATAN_stcui16nTableSide;
	static constexpr UINT16	TRIG_stcui16nAngle=								256;
	static constexpr UINT8	TRIG_stcui8nWidthBit=							14;
	static constexpr INT16	TRIG_stci16nWidth=								1<<TRIG_stcui8nWidthBit;
	static constexpr UINT32	ROM_TRIG_stcui32dOffsetM=						0x7ff000;
	static constexpr UINT32	ROM_TRIG_stcui32dOffsetS=						0x7ff000;
	static constexpr UINT32	ROM_TRIG_stcui32iAddressM=						ROM_stcui32iAddressM+ROM_TRIG_stcui32dOffsetM;
	static constexpr UINT32	ROM_TRIG_stcui32iAddressS=						ROM_stcui32iAddressS+ROM_TRIG_stcui32dOffsetS;
	static constexpr UINT32	ROM_TRIG_stcui32nSize=							TRIG_stcui16nAngle*2*2;
	static constexpr UINT32	RAM_stcui32iAddressM=							0x800000;
	static constexpr UINT32	RAM_stcui32iAddressS=							0x800000;
	static constexpr UINT32	RAM_stcui32nSizeM=								0x200000;
	static constexpr UINT32	RAM_stcui32nSizeS=								0x200000;
	static constexpr UINT32	PCMRAM_stcui32iAddressS=						0xbf0000;
	static constexpr AUTO	PCMRAM_stcui32nSize=							sound::YM2151B::PCMRAM_stcui32nSize;
	static constexpr UINT32	VRAM_stcui32iAddressS=							0xc00000;
	static constexpr AUTO	VRAM_stcui32nSize=								video::VI71B::VRAM_stcui32nSize;
	static constexpr UINT32	VRAM_TEXT_stcui32dDefaultOffset=				0x000000;
	static constexpr UINT32	VRAM_PATTERN_SPRITE_stcui32dDefaultOffset=		0x080000;
	static constexpr UINT32	VRAM_PATTERN_BG0_stcui32dDefaultOffset=			0x0c0000;
	static constexpr UINT32	VRAM_PATTERN_BG1_stcui32dDefaultOffset=			0x0c8000;
	static constexpr UINT32	VRAM_PATTERN_BG2_stcui32dDefaultOffset=			0x0d0000;
	static constexpr UINT32	VRAM_PATTERN_BG3_stcui32dDefaultOffset=			0x0d8000;
	static constexpr UINT32	VRAM_ATTRIBUTE_SPRITE_stcui32dDefaultOffset=	0x088000;
	static constexpr UINT32	VRAM_ATTRIBUTE_BG0_stcui32dDefaultOffset=		0x0e0000;
	static constexpr UINT32	VRAM_ATTRIBUTE_BG1_stcui32dDefaultOffset=		0x0e8000;
	static constexpr UINT32	VRAM_ATTRIBUTE_BG2_stcui32dDefaultOffset=		0x0f0000;
	static constexpr UINT32	VRAM_ATTRIBUTE_BG3_stcui32dDefaultOffset=		0x0f8000;
	static constexpr UINT32	COLLIDERRAM_stcui32iAddressM=					0xfc0000;
	static constexpr UINT32	COLLIDERRAM_stcui32iAddressS=					0xfc0000;
	static constexpr AUTO	COLLIDERRAM_stcui32nSize=						misc::COLLIDER::COLLIDERRAM_stcui32nSize;
	static constexpr UINT32	COM_stcui32iAddressM=							0xfe0000;
	static constexpr UINT32	COM_stcui32iAddressS=							0xfe0000;
	static constexpr UINT32	COM_stcui32nSize=								0x010000;
	static constexpr UINT32	DEVICE_stcui32iAddress=							-0x008000;
	static constexpr UINT32	DEVICE_stcui32nSize=							0x008000;
	static constexpr UINT16	DEVICE_INTERRUPTER_stcui16dOffsetM=				0x0000;
	static constexpr UINT16	DEVICE_INTERRUPTER_stcui16dOffsetS=				0x0000;
	static constexpr UINT16	DEVICE_INTERRUPTER_stcui16nPort=				0x0001;
	static constexpr UINT16	DEVICE_INTERRUPTER_stcui16dDataOffset=			0x0000;
	static constexpr UINT16	DEVICE_COM_stcui16dOffsetM=						0x0002;
	static constexpr UINT16	DEVICE_COM_stcui16dOffsetS=						0x0002;
	static constexpr UINT16	DEVICE_COM_stcui16nPort=						0x0001;
	static constexpr UINT16	DEVICE_COM_stcui16dDataOffset=					0x0000;
	static constexpr UINT16	DEVICE_VIDEO_stcui16dOffsetS=					0x0010;
	static constexpr UINT16	DEVICE_VIDEO_stcui16nPort=						0x0008;
	static constexpr UINT16	DEVICE_VIDEO_stcui16dSelectOffset=				0x0000;
	static constexpr UINT16	DEVICE_VIDEO_stcui16dRegisterOffset=			0x0002;
	static constexpr UINT16	DEVICE_VIDEO_stcui16dPaletteOffset=				0x0004;
#ifndef M68K_ORE68000ACE_YM2151B_FREQUENCY
#define M68K_ORE68000ACE_YM2151B_FREQUENCY	3'580'000
#endif
	static constexpr UPERIOD	SOUND_stcuprdnFrequencyHz=					M68K_ORE68000ACE_YM2151B_FREQUENCY;
#if M68K_ORE68000ACE_YM2151B_FREQUENCY==3'580'000
	static constexpr INT16	SOUND_stci16dToneAdjust=						-256/*offset of 0:C#*/;
#elif M68K_ORE68000ACE_YM2151B_FREQUENCY==4'000'000
	static constexpr INT16	SOUND_stci16dToneAdjust=						-256/*offset of 0:C#*/-492/*offset of 4MHz*/;
#else
	static constexpr INT16	SOUND_stci16dToneAdjust=						-256/*offset of 0:C#*/;
#endif
	static constexpr UINT16	DEVICE_SOUND_stcui16dOffsetS=					0x0020;
	static constexpr UINT16	DEVICE_SOUND_stcui16nPort=						0x0004;
	static constexpr UINT16	DEVICE_SOUND_FM_stcui16dSelectWOffset=			0x0000;
	static constexpr UINT16	DEVICE_SOUND_PCM_stcui16dSelectWOffset=			0x0001;
	static constexpr UINT16	DEVICE_SOUND_stcui16dSelectROffset=				0x0002;
	static constexpr UINT16	DEVICE_SOUND_stcui16dDataOffset=				0x0003;
	static constexpr UPERIOD	KEYBOARD_stcuprdnFrequencyHz=				1'000;
	static constexpr UINT16	DEVICE_KEYBOARD_stcui16dOffsetS=				0x0030;
	static constexpr UINT16	DEVICE_KEYBOARD_stcui16nPort=					0x0004;
	static constexpr UINT16	DEVICE_KEYBOARD_stcui16dSelectOffset=			0x0000;
	static constexpr UINT16	DEVICE_KEYBOARD_stcui16dDataOffset=				0x0002;
	static constexpr UPERIOD	JOYSTICK_stcuprdnFrequencyHz=				1'000;
	static constexpr UINT16	DEVICE_JOYSTICK_stcui16dOffsetS=				0x0038;
	static constexpr UINT16	DEVICE_JOYSTICK_stcui16nPort=					0x0002;
	static constexpr UINT16	DEVICE_JOYSTICK_stcui16dSelectOffset=			0x0000;
	static constexpr UINT16	DEVICE_JOYSTICK_stcui16dDataOffset=				0x0001;
	static constexpr UINT16	DEVICE_HPC_stcui16dOffsetM=						0x0040;
	static constexpr UINT16	DEVICE_HPC_stcui16dOffsetS=						0x0040;
	static constexpr UINT16	DEVICE_HPC_stcui16nPort=						0x0002;
	static constexpr UINT16	DEVICE_HPC_stcui16dDataOffset=					0x0000;
	static constexpr UINT16	DEVICE_LFSR_stcui16dOffsetM=					0x0044;
	static constexpr UINT16	DEVICE_LFSR_stcui16dOffsetS=					0x0044;
	static constexpr UINT16	DEVICE_LFSR_stcui16nPort=						0x0002;
	static constexpr UINT16	DEVICE_LFSR_stcui16dDataOffset=					0x0000;
	static constexpr UINT16	DEVICE_COLLIDER_stcui16dOffsetM=				0x0048;
	static constexpr UINT16	DEVICE_COLLIDER_stcui16dOffsetS=				0x0048;
	static constexpr UINT16	DEVICE_COLLIDER_stcui16nPort=					0x0008;
	static constexpr UINT16	DEVICE_COLLIDER_stcui16dSelectWOffset=			0x0000;
	static constexpr UINT16	DEVICE_COLLIDER_stcui16dSelectROffset=			0x0002;
	static constexpr UINT16	DEVICE_COLLIDER_stcui16dDataOffset=				0x0006;
	static constexpr UINT16	DEVICE_SERIAL_stcui16dOffsetM=					0x0100;
	static constexpr UINT16	DEVICE_SERIAL_stcui16dOffsetS=					0x0100;
	static constexpr UINT16	DEVICE_SERIAL_stcui16nPort=						0x0001;
	static constexpr UINT16	DEVICE_SERIAL_stcui16dDataOffset=				0x0000;
}

#endif
