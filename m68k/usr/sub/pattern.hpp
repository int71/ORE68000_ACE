/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/pattern.hpp'								2025 written by int71	**
 ****************************************************************************/
#ifndef OREDIUS68K_SUB_SERVICE_PATTERN
#define OREDIUS68K_SUB_SERVICE_PATTERN

//
//		include
//

#include				"../common/rom_video.hpp"

//
//		namespace:m68k::i71::sub
//

namespace m68k::i71::sub{

	//
	//		class
	//

	//	PATTERN
	class PATTERN;

	//
	//		class:PATTERN
	//

	class PATTERN{
	public:

		//
		//		const
		//

		using					ROM_VIDEO=										common::ROM_VIDEO;
		using					IDPATTERN=										ROM_VIDEO::IDPATTERN;
		static constexpr AUTO&	stacui32iAddressS=								ROM_VIDEO::PATTERN::stacui32iAddressS;
		static constexpr AUTO&	stacui32nSize=									ROM_VIDEO::PATTERN::stacui32nSize;

		//
		//		body:PATTERN
		//

	public:
		static VOID				stNew(VOID)noexcept;
		static VOID				stDelete(VOID)noexcept;
		static _INLINE_ VOID	stWrite(CUINT16 patternchr_cui16iaddressdestination,const IDPATTERN cidpatternsource)noexcept{
			stWrite(
				patternchr_cui16iaddressdestination,
				OFWSIZE(stacui32nSize[cidpatternsource]),
				PCVOID(stacui32iAddressS[cidpatternsource])
			);
			return;
		}
		static VOID				stWrite(CUINT16 patternchr_cui16iaddressdestination,COFWSIZE cszndestination,const PCVOID cpcsource)noexcept;
	};
}

#endif
