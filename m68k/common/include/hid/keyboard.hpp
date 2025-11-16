/****************************************************************************
**																			**
**																			**
**									m68k									**
**																			**
**	'm68k/hid/keyboard.hpp'							2025 written by int71	**
 ****************************************************************************/
#ifndef M68K_HID_KEYBOARD
#define M68K_HID_KEYBOARD

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

	class KEYBOARD;

	//
	//		class:KEYBOARD
	//

	class KEYBOARD{
	public:

		//
		//		const
		//

		class _IDKEY{
		public:
			//	00				01				02				03				04				05				06				07				08				09				0a				0b				0c				0d				0e				0f
			enum BODY:UINT8{
				Esc,					F1,				F2,				F3,				F4,				F5,				F6,				F7,				F8,				F9,				F10,			F11,			F12,			_0x0d,			_0x0e,			_0x0f,
				Zenkaku,				n1,				n2,				n3,				n4,				n5,				n6,				n7,				n8,				n9,				n0,				Minus,			Hat,			Yen,			BackSpace,		_0x1f,
				Tab,					Q,				W,				E,				R,				T,				Y,				U,				I,				O,				P,				At,				Bracket_L,		Enter,			_0x2e,			_0x2f,
				CapsLock,				A,				S,				D,				F,				G,				H,				J,				K,				L,				Semicolon,		Colon,			Bracket_R,		_0x3d,			_0x3e,			_0x3f,
				Shift_L,				Z,				X,				C,				V,				B,				N,				M,				Comma,			Period,			Slash,			BackSlash,		Shift_R,		Shift,			Ctrl,			_0x4f,
				Ctrl_L,					_0x51,			_0x52,			Muhenkan,		Space,			Henkan,			Hiragana,		_0x57,			_0x58,			_0x59,			Ctrl_R,			_0x5b,			_0x5c,			_0x5d,			_0x5e,			_0x5f,
				_0x60,					_0x61,			_0x62,			Insert,			Home,			PageUp,			Delete,			End,			PageDown,		Up,				Left,			Down,			Right,			NumLock,		_0x6e,			_0x6f,
				Slash_TK,				Asterisk_TK,	Minus_TK,		n7_TK,			n8_TK,			n9_TK,			Plus_TK,		n4_TK,			n5_TK,			n6_TK,			n1_TK,			n2_TK,			n3_TK,			Enter_TK,		n0_TK,			Period_TK
			};
		};
		using					IDKEY=_IDKEY::BODY;
		static constexpr UINT8	stcui8nKey=				0x80;
		static constexpr UINT8	stcui8nBank=			stcui8nKey>>4;
	};
}

#endif
