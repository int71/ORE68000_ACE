/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/base.hpp'									2025 written by int71	**
 ****************************************************************************/
#ifndef I71_SUB_BASE
#define I71_SUB_BASE

//
//		include
//

#include				"../common/base_.hpp"
#include				"serial.hpp"

//
//		namespace:m68k::i71::sub
//

namespace m68k::i71::sub{

	//
	//		const
	//

	static constexpr AUTO	RAM_stcui32iAddress=							ore68000ace::RAM_stcui32iAddressS;
	static constexpr AUTO	RAM_stcui32nSize=								ore68000ace::RAM_stcui32nSizeS;

	//
	//		class
	//

	//	MEMORY
	using					MEMORY=											common::MEMORYS;
	//	MAP
	using					MAP=											common::MAP;
	//	VIDEO_DEVICE
	using					VIDEO_DEVICE=									common::VIDEO_DEVICE;
	//	VIDEO_DRIVER
	using					VIDEO_DRIVER=									common::VIDEO_DRIVER;
	//	SOUND_DEVICE
	using					SOUND_DEVICE=									common::SOUND_DEVICE;
	//	SOUND_DRIVER
	using					SOUND_DRIVER=									common::SOUND_DRIVER;
	//	KEYBOARD_DEVICE
	using					KEYBOARD_DEVICE=								common::KEYBOARD_DEVICE;
	//	JOYSTICK_DEVICE
	using					JOYSTICK_DEVICE=								common::JOYSTICK_DEVICE;
	//	BASE
	using					BASE=											common::BASE_;
	//	DEBUG
	class DEBUG;

	//
	//		class:DEBUG
	//

#ifdef I71_DEBUG
	class DEBUG{
	public:
		static _INLINE_ VOID	stNew(VOID)noexcept{
			SERIAL::stNew();
			return;
		}
		static _INLINE_ VOID	stDelete(VOID)noexcept{
			SERIAL::stDelete();
			return;
		}
		static _INLINE_ VOID	stWrite(const PCUSTR cpcustrsource)noexcept{
			SERIAL::stWrite(cpcustrsource);
			return;
		}
		static _INLINE_ VOID	stWrite(CINT8 ci8source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWrite(ci8source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWrite(CUINT8 cui8source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWrite(cui8source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWrite(CINT16 ci16source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWrite(ci16source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWrite(CUINT16 cui16source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWrite(cui16source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWrite(CINT32 ci32source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWrite(ci32source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWrite(CUINT32 cui32source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWrite(cui32source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWriteHex(CINT8 ci8source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWriteHex(ci8source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWriteHex(CUINT8 cui8source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWriteHex(cui8source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWriteHex(CINT16 ci16source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWriteHex(ci16source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWriteHex(CUINT16 cui16source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWriteHex(cui16source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWriteHex(CINT32 ci32source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWriteHex(ci32source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWriteHex(CUINT32 cui32source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWriteHex(cui32source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWriteLine(const PCUSTR cpcustrsource)noexcept{
			SERIAL::stWriteLine(cpcustrsource);
			return;
		}
		static _INLINE_ VOID	stWriteLine(CINT8 ci8source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWriteLine(ci8source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWriteLine(CUINT8 cui8source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWriteLine(cui8source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWriteLine(CINT16 ci16source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWriteLine(ci16source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWriteLine(CUINT16 cui16source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWriteLine(cui16source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWriteLine(CINT32 ci32source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWriteLine(ci32source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWriteLine(CUINT32 cui32source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWriteLine(cui32source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWriteHexLine(CINT8 ci8source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWriteHexLine(ci8source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWriteHexLine(CUINT8 cui8source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWriteHexLine(cui8source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWriteHexLine(CINT16 ci16source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWriteHexLine(ci16source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWriteHexLine(CUINT16 cui16source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWriteHexLine(cui16source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWriteHexLine(CINT32 ci32source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWriteHexLine(ci32source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWriteHexLine(CUINT32 cui32source,CUINT8 cui8ndigitminimum=0)noexcept{
			SERIAL::stWriteHexLine(cui32source,cui8ndigitminimum);
			return;
		}
		static _INLINE_ VOID	stWriteHex(const PCUINT8 cpcui8source,CUINT16 cui16nsource)noexcept{
			SERIAL::stWriteHex(cpcui8source,cui16nsource);
			return;
		}
		static _INLINE_ VOID	stWriteHex(const PCUINT16 cpcui16source,CUINT16 cui16nsource)noexcept{
			SERIAL::stWriteHex(cpcui16source,cui16nsource);
			return;
		}
		static _INLINE_ VOID	stWriteHex(const PCUINT32 cpcui32source,CUINT16 cui16nsource)noexcept{
			SERIAL::stWriteHex(cpcui32source,cui16nsource);
			return;
		}
	};
#else
	class DEBUG{
	public:
		static constexpr VOID	stNew(VOID)noexcept{
			return;
		}
		static constexpr VOID	stDelete(VOID)noexcept{
			return;
		}
		static constexpr VOID	stWrite(const PCUSTR cpcustrsource)noexcept{
			return;
		}
		static constexpr VOID	stWrite(CINT8 ci8source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWrite(CUINT8 cui8source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWrite(CINT16 ci16source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWrite(CUINT16 cui16source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWrite(CINT32 ci32source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWrite(CUINT32 cui32source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWriteHex(CINT8 ci8source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWriteHex(CUINT8 cui8source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWriteHex(CINT16 ci16source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWriteHex(CUINT16 cui16source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWriteHex(CINT32 ci32source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWriteHex(CUINT32 cui32source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWriteLine(const PCUSTR cpcustrsource)noexcept{
			return;
		}
		static constexpr VOID	stWriteLine(CINT8 ci8source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWriteLine(CUINT8 cui8source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWriteLine(CINT16 ci16source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWriteLine(CUINT16 cui16source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWriteLine(CINT32 ci32source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWriteLine(CUINT32 cui32source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWriteHexLine(CINT8 ci8source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWriteHexLine(CUINT8 cui8source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWriteHexLine(CINT16 ci16source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWriteHexLine(CUINT16 cui16source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWriteHexLine(CINT32 ci32source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWriteHexLine(CUINT32 cui32source,CUINT8 cui8ndigitminimum=0)noexcept{
			return;
		}
		static constexpr VOID	stWriteHex(const PCUINT8 cpcui8source,CUINT16 cui16nsource)noexcept{
			return;
		}
		static constexpr VOID	stWriteHex(const PCUINT16 cpcui16source,CUINT16 cui16nsource)noexcept{
			return;
		}
		static constexpr VOID	stWriteHex(const PCUINT32 cpcui32source,CUINT16 cui16nsource)noexcept{
			return;
		}
	};
#endif
}

#endif
