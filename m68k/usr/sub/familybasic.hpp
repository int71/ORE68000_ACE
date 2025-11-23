/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/familybasic.hpp'							2025 written by int71	**
 ****************************************************************************/
#ifndef I71_SUB_FAMILYBASIC
#define I71_SUB_FAMILYBASIC

//
//		include
//

#include				<hid/keyboard.hpp>
#include				<hid/joystick.hpp>
#include				"vector2.hpp"
#include				"os.hpp"

//
//		namespace:m68k::i71::sub
//

namespace m68k::i71::sub{

	//
	//		class
	//

	//	FAMILYBASIC
	class FAMILYBASIC;

	//
	//		class:FAMILYBASIC
	//

	class FAMILYBASIC{
	public:

		//
		//		const
		//

		using					IDKEY=m68k::hid::KEYBOARD::IDKEY;
		using					IDBUTTON=m68k::hid::JOYSTICK::IDBUTTON;

		//
		//		body:FAMILYBASIC
		//

	public:
		static VOID				stNew(VOID)noexcept;
		static VOID				stDelete(VOID)noexcept;
		static VOID				stSetPalette(CUINT8 cui8ipalette,CUINT8 cui8inescolor0,CUINT8 cui8inescolor1,CUINT8 cui8inescolor2,CUINT8 cui8inescolor3)noexcept;
		static _INLINE_ VOID	stWriteSpritePattern8(CUINT8 cui8ipattern,CUINT32 cui32cpattern0,CUINT32 cui32cpattern1,CUINT32 cui32cpattern2,CUINT32 cui32cpattern3,CUINT32 cui32cpattern4,CUINT32 cui32cpattern5,CUINT32 cui32cpattern6,CUINT32 cui32cpattern7)noexcept{
			CAUTO					cui32doffset=MAP::VRAM::PATTERN_SPRITE_stcui32dOffset+(UINT32(cui8ipattern)<<5);

			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x00)=cui32cpattern0;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x04)=cui32cpattern1;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x08)=cui32cpattern2;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x0c)=cui32cpattern3;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x10)=cui32cpattern4;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x14)=cui32cpattern5;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x18)=cui32cpattern6;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x1c)=cui32cpattern7;
			return;
		}
		static _INLINE_ VOID	stWriteSpritePattern16(CUINT8 cui8ipattern,CUINT32 cui32cpattern0l,CUINT32 cui32cpattern0r,CUINT32 cui32cpattern1l,CUINT32 cui32cpattern1r,CUINT32 cui32cpattern2l,CUINT32 cui32cpattern2r,CUINT32 cui32cpattern3l,CUINT32 cui32cpattern3r,CUINT32 cui32cpattern4l,CUINT32 cui32cpattern4r,CUINT32 cui32cpattern5l,CUINT32 cui32cpattern5r,CUINT32 cui32cpattern6l,CUINT32 cui32cpattern6r,CUINT32 cui32cpattern7l,CUINT32 cui32cpattern7r,CUINT32 cui32cpattern8l,CUINT32 cui32cpattern8r,CUINT32 cui32cpattern9l,CUINT32 cui32cpattern9r,CUINT32 cui32cpatternal,CUINT32 cui32cpatternar,CUINT32 cui32cpatternbl,CUINT32 cui32cpatternbr,CUINT32 cui32cpatterncl,CUINT32 cui32cpatterncr,CUINT32 cui32cpatterndl,CUINT32 cui32cpatterndr,CUINT32 cui32cpatternel,CUINT32 cui32cpatterner,CUINT32 cui32cpatternfl,CUINT32 cui32cpatternfr)noexcept{
			stWriteSpritePattern8(cui8ipattern+0,cui32cpattern0l,cui32cpattern1l,cui32cpattern2l,cui32cpattern3l,cui32cpattern4l,cui32cpattern5l,cui32cpattern6l,cui32cpattern7l);
			stWriteSpritePattern8(cui8ipattern+1,cui32cpattern8l,cui32cpattern9l,cui32cpatternal,cui32cpatternbl,cui32cpatterncl,cui32cpatterndl,cui32cpatternel,cui32cpatternfl);
			stWriteSpritePattern8(cui8ipattern+2,cui32cpattern0r,cui32cpattern1r,cui32cpattern2r,cui32cpattern3r,cui32cpattern4r,cui32cpattern5r,cui32cpattern6r,cui32cpattern7r);
			stWriteSpritePattern8(cui8ipattern+3,cui32cpattern8r,cui32cpattern9r,cui32cpatternar,cui32cpatternbr,cui32cpatterncr,cui32cpatterndr,cui32cpatterner,cui32cpatternfr);
			return;
		}
		static _INLINE_ VOID	stWriteSprite(CUINT8 cui8isprite,CUINT16 cui16cattribute0,CUINT16 cui16cattribute1,CUINT16 cui16cattribute2,CUINT16 cui16cattribute3)noexcept{
			CAUTO					cui32doffset=MAP::VRAM::ATTRIBUTE_SPRITE_stcui32dOffset+(UINT32(cui8isprite)<<3);

			MEMORY::VRAM_stui16DelegateThis(cui32doffset+0x00)=cui16cattribute0;
			MEMORY::VRAM_stui16DelegateThis(cui32doffset+0x02)=cui16cattribute1;
			MEMORY::VRAM_stui16DelegateThis(cui32doffset+0x04)=cui16cattribute2;
			MEMORY::VRAM_stui16DelegateThis(cui32doffset+0x06)=cui16cattribute3;
			return;
		}
		static _INLINE_ VOID	stWriteBGPattern(CUINT8 cui8ipattern,CUINT32 cui32cpattern0,CUINT32 cui32cpattern1,CUINT32 cui32cpattern2,CUINT32 cui32cpattern3,CUINT32 cui32cpattern4,CUINT32 cui32cpattern5,CUINT32 cui32cpattern6,CUINT32 cui32cpattern7)noexcept{
			CAUTO					cui32doffset=MAP::VRAM::PATTERN_BG1_stcui32dOffset+(UINT32(cui8ipattern)<<5);

			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x00)=cui32cpattern0;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x04)=cui32cpattern1;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x08)=cui32cpattern2;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x0c)=cui32cpattern3;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x10)=cui32cpattern4;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x14)=cui32cpattern5;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x18)=cui32cpattern6;
			MEMORY::VRAM_stui32DelegateThis(cui32doffset+0x1c)=cui32cpattern7;
			return;
		}
		static VOID				stWriteBG(CVECTOR2& cv2iposition,const PCUINT16 cpcui16csource,CUINT16 cui16nsource)noexcept;
		static VOID				stWriteBG(CVECTOR2& cv2iposition,CUINT8 cui8ipalette,const PCUSTR cpcustrsource)noexcept;
		static OFWBOOL			steIsKeyDown(const IDKEY cidkey)noexcept{
			return OS::DEVICE_KEYBOARD_stui16Read(cidkey>>4)&(1<<(cidkey&0xf));
		}
		static UINT8			stui8cReadJoystick(CUINT8 cui8ibank)noexcept{
			return OS::DEVICE_JOYSTICK_stui8Read(cui8ibank);
		}
	};
}

#endif
