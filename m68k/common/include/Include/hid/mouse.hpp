/****************************************************************************
**																			**
**																			**
**									m68k									**
**																			**
**	'm68k/hid/mouse.hpp'							2026 written by int71	**
 ****************************************************************************/
#ifndef M68K_HID_MOUSE
#define M68K_HID_MOUSE

//
//		include
//

#include				"../base.hpp"

//
//		namespace:m68k::hid
//

namespace m68k::hid{

	//
	//		class
	//

	class MOUSE;

	//
	//		class:MOUSE
	//

	class MOUSE{
	public:

		//
		//		const
		//

		class _IDBUTTON{
		public:
			enum BODY:UINT8{
				Left=					0,
				Right=					1
			};
		};
		using					IDBUTTON=_IDBUTTON::BODY;
		static constexpr UINT8	stcui8nBank=			3;
		static constexpr UINT8	stcui8cMaskButtonLeft=	1<<IDBUTTON::Left;
		static constexpr UINT8	stcui8cMaskButtonRight=	1<<IDBUTTON::Right;
	};
}

#endif
