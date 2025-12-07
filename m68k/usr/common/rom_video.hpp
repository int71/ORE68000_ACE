/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'common/rom_video.hpp'							2025 written by int71	**
 ****************************************************************************/
#ifndef I71_COMMON_ROM_VIDEO
#define I71_COMMON_ROM_VIDEO

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

	class ROM_VIDEO;

	//
	//		class:ROM_VIDEO
	//

	class ROM_VIDEO{
	public:

		//
		//		const
		//

		static constexpr AUTO	stcui32iAddressS=								ore68000ace::ROM_VIDEO_stcui32iAddressS;
		class _IDPATTERN{
		public:
			enum BODY:UINT16{
				SPRITE_SYSTEM,
				BG_SYSTEM
			};
		};
		using					IDPATTERN=_IDPATTERN::BODY;

		//
		//		class
		//

		//	PATTERNCHR
		class PATTERNCHR;
		//	PATTERN
		class PATTERN;

		//
		//		class:PATTERNCHR
		//

		class PATTERNCHR{
		public:

			//
			//		const
			//

			static constexpr UINT16	SPRITE_SYSTEM_stcui16nSize=						0x0100;
			static constexpr UINT16	BG_SYSTEM_stcui16nSize=							0x0100;
		};

		//
		//		class:PATTERN
		//

		class PATTERN{
		public:

			//
			//		const
			//

			static constexpr UINT32	stcui32iBaseAddressS=							stcui32iAddressS+0x000000;
			static constexpr UINT32	SPRITE_SYSTEM_stcui32iAddressS=					stcui32iBaseAddressS+0x000000;
			static constexpr UINT32	SPRITE_SYSTEM_stcui32nSize=						UINT32(PATTERNCHR::SPRITE_SYSTEM_stcui16nSize)<<5;
			static constexpr UINT32	BG_SYSTEM_stcui32iAddressS=						stcui32iBaseAddressS+0x002000;
			static constexpr UINT32	BG_SYSTEM_stcui32nSize=							UINT32(PATTERNCHR::BG_SYSTEM_stcui16nSize)<<5;
			static constexpr UINT32	stacui32iAddressS[]={
				SPRITE_SYSTEM_stcui32iAddressS,
				BG_SYSTEM_stcui32iAddressS
			};
			static constexpr UINT32	stacui32nSize[]={
				SPRITE_SYSTEM_stcui32nSize,
				BG_SYSTEM_stcui32nSize
			};
		};
	};
}
#endif
