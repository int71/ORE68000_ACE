/****************************************************************************
**																			**
**																			**
**									m68k									**
**																			**
**	'm68k/hid/joystick.hpp'							2026 written by int71	**
 ****************************************************************************/
#ifndef M68K_HID_JOYSTICK
#define M68K_HID_JOYSTICK

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

	class JOYSTICK;

	//
	//		class:JOYSTICK
	//

	class JOYSTICK{
	public:

		//
		//		const
		//

		class _IDBUTTON{
		public:
			enum BODY:UINT8{
				Right=					0,
				Left=					1,
				Down=					2,
				Up=						3,
				A=						4,
				B=						5
			};
		};
		using					IDBUTTON=_IDBUTTON::BODY;
		static constexpr UINT8	stcui8nBank=			2;
		static constexpr UINT8	stcui8cMaskButtonRight=	1<<IDBUTTON::Right;
		static constexpr UINT8	stcui8cMaskButtonLeft=	1<<IDBUTTON::Left;
		static constexpr UINT8	stcui8cMaskButtonDown=	1<<IDBUTTON::Down;
		static constexpr UINT8	stcui8cMaskButtonUp=	1<<IDBUTTON::Up;
		static constexpr UINT8	stcui8cMaskButtonA=		1<<IDBUTTON::A;
		static constexpr UINT8	stcui8cMaskButtonB=		1<<IDBUTTON::B;
	};
}

#endif
