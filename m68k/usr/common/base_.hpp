/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'common/base_.hpp'								2025 written by int71	**
 ****************************************************************************/
#ifndef I71_COMMON_BASE_
#define I71_COMMON_BASE_

//
//		include
//

#include				"map.hpp"

//
//		macro
//

#define					I71_DEBUG

//
//		namespace:m68k::i71::common
//

namespace m68k::i71::common{

	//
	//		class
	//

	//	MEMORYM
	using					MEMORYM=										ore68000ace::MEMORYM;
	//	MEMORYS
	using					MEMORYS=										ore68000ace::MEMORYS;
	//	VIDEO_DEVICE
	using					VIDEO_DEVICE=									MAP::VIDEO::DEVICE;
	//	VIDEO_DRIVER
	using					VIDEO_DRIVER=									MAP::VIDEO::DRIVER;
	//	SOUND_DEVICE
	using					SOUND_DEVICE=									MAP::SOUND::DEVICE;
	//	SOUND_DRIVER
	using					SOUND_DRIVER=									MAP::SOUND::DRIVER;
	//	KEYBOARD_DEVICE
	using					KEYBOARD_DEVICE=								MAP::KEYBOARD::DEVICE;
	//	JOYSTICK_DEVICE
	using					JOYSTICK_DEVICE=								MAP::JOYSTICK::DEVICE;
	//	BASE_
	class BASE_;

	//
	//		class:BASE_
	//

	class BASE_{
	public:

		//
		//		class:ST
		//

		class ST{
		public:
		public:
			VOID					Delete(VOID)noexcept;
		};

		//
		//		body:BASE_
		//

	private:
		static inline ST		st;
	public:
		static VOID				stNew(VOID)noexcept;
		static VOID				stDelete(VOID)noexcept;
	};

	//
	//		custom
	//

	constexpr UINT16		ui16cGetColor(CBYTE cbired,CBYTE cbigreen,CBYTE cbiblue)noexcept{
		return VIDEO_DEVICE::stui16cGetColor(cbired,cbigreen,cbiblue);
	}
	constexpr UINT16		ui16cGetColor(CDWORD cdwvalue)noexcept{
		return VIDEO_DEVICE::stui16cGetColor(cdwvalue);
	}
}

#endif
