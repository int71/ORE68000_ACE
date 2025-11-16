/****************************************************************************
**																			**
**																			**
**								ORE68000ACE									**
**																			**
**	'm68k/ore68000ace/memory.hpp'					2025 written by int71	**
 ****************************************************************************/
#ifndef M68K_ORE68000ACE_MEMORY
#define M68K_ORE68000ACE_MEMORY

//
//		include
//

#include				<ofw/ofw.hpp>
#include				<ore68000ace/map.hpp>

//
//		namespace:m68k::ore68000ace
//

namespace m68k::ore68000ace{

	//
	//		class
	//

	class MEMORYM;
	class MEMORYS;

	//
	//		class:MEMORYM
	//

	//	MEMORYM
	//		クラス初期化操作は不要で、各種機能は直接呼び出せます。
	class MEMORYM{
	public:
		static _INLINE_ CUINT8&	ROM_ATAN_stcui8GetThis(CUINT8 cui8ix,CUINT8 cui8iy)noexcept{
			return *PCUINT8(ROM_ATAN_stcui32iAddressM+(UINT16(cui8iy)<<ATAN_stcui8nTableBit)+UINT16(cui8ix));
		}
		static _INLINE_ CINT16&	ROM_SIN_stci16GetThis(CUINT8 cui8iangle)noexcept{
			return *PCINT16(ROM_TRIG_stcui32iAddressM+(UINT16(cui8iangle)<<2)+0);
		}
		static _INLINE_ CINT16&	ROM_COS_stci16GetThis(CUINT8 cui8iangle)noexcept{
			return *PCINT16(ROM_TRIG_stcui32iAddressM+(UINT16(cui8iangle)<<2)+2);
		}
		static _INLINE_ _UNDISCARDABLE_	UINT32&	COM_stui32DelegateThis(CUINT32 cui32iaddress)noexcept{
			return *PUINT32(COM_stcui32iAddressM+cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_	CUINT32&	COM_stcui32GetThis(CUINT32 cui32iaddress)noexcept{
			return *PCUINT32(COM_stcui32iAddressM+cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_	UINT16&	COM_stui16DelegateThis(CUINT32 cui32iaddress)noexcept{
			return *PUINT16(COM_stcui32iAddressM+cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_	CUINT16&	COM_stcui16GetThis(CUINT32 cui32iaddress)noexcept{
			return *PCUINT16(COM_stcui32iAddressM+cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_	UINT8&	COM_stui8DelegateThis(CUINT32 cui32iaddress)noexcept{
			return *PUINT8(COM_stcui32iAddressM+cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_	CUINT8&	COM_stcui8GetThis(CUINT32 cui32iaddress)noexcept{
			return *PCUINT8(COM_stcui32iAddressM+cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_ UINT16&	DEVICE_stui16DelegateThis(CUINT16 cui16iaddress)noexcept{
			return *PUINT16(DEVICE_stcui32iAddress+cui16iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_ CUINT16&	DEVICE_stcui16GetThis(CUINT16 cui16iaddress)noexcept{
			return *PCUINT16(DEVICE_stcui32iAddress+cui16iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_ UINT8&	DEVICE_stui8DelegateThis(CUINT16 cui16iaddress)noexcept{
			return *PUINT8(DEVICE_stcui32iAddress+cui16iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_ CUINT8&	DEVICE_stcui8GetThis(CUINT16 cui16iaddress)noexcept{
			return *PCUINT8(DEVICE_stcui32iAddress+cui16iaddress);
		}
	};

	//
	//		class:MEMORYS
	//

	//	MEMORYS
	//		クラス初期化操作は不要で、各種機能は直接呼び出せます。
	class MEMORYS{
	public:
		static _INLINE_ CUINT16&	ROM_FONT_stcui16GetThis(CUINT32 cui32iaddress)noexcept{
			return *PCUINT16(ROM_FONT_stcui32iAddressS+cui32iaddress);
		}
		static _INLINE_ CUINT8&	ROM_FONT_stcui8GetThis(CUINT32 cui32iaddress)noexcept{
			return *PCUINT8(ROM_FONT_stcui32iAddressS+cui32iaddress);
		}
		static _INLINE_ CUINT8&	ROM_ATAN_stcui8GetThis(CUINT8 cui8ix,CUINT8 cui8iy)noexcept{
			return *PCUINT8(ROM_ATAN_stcui32iAddressS+(UINT16(cui8iy)<<ATAN_stcui8nTableBit)+UINT16(cui8ix));
		}
		static _INLINE_ CINT16&	ROM_SIN_stci16GetThis(CUINT8 cui8iangle)noexcept{
			return *PCINT16(ROM_TRIG_stcui32iAddressS+(UINT16(cui8iangle)<<2)+0);
		}
		static _INLINE_ CINT16&	ROM_COS_stci16GetThis(CUINT8 cui8iangle)noexcept{
			return *PCINT16(ROM_TRIG_stcui32iAddressS+(UINT16(cui8iangle)<<2)+2);
		}
		static _INLINE_ _UNDISCARDABLE_	UINT8&	PCMM_stui8DelegateThis(CUINT32 cui32iaddress)noexcept{
			return *PUINT8(PCMRAM_stcui32iAddressS+cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_	CUINT8&	PCMM_stcui8GetThis(CUINT32 cui32iaddress)noexcept{
			return *PCUINT8(PCMRAM_stcui32iAddressS+cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_	UINT32&	VRAM_stui32DelegateThis(CUINT32 cui32iaddress)noexcept{
			return *PUINT32(VRAM_stcui32iAddressS+cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_	CUINT32&	VRAM_stcui32GetThis(CUINT32 cui32iaddress)noexcept{
			return *PCUINT32(VRAM_stcui32iAddressS+cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_	UINT16&	VRAM_stui16DelegateThis(CUINT32 cui32iaddress)noexcept{
			return *PUINT16(VRAM_stcui32iAddressS+cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_	CUINT16&	VRAM_stcui16GetThis(CUINT32 cui32iaddress)noexcept{
			return *PCUINT16(VRAM_stcui32iAddressS+cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_	UINT8&	VRAM_stui8DelegateThis(CUINT32 cui32iaddress)noexcept{
			return *PUINT8(VRAM_stcui32iAddressS+cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_	CUINT8&	VRAM_stcui8GetThis(CUINT32 cui32iaddress)noexcept{
			return *PCUINT8(VRAM_stcui32iAddressS+cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_	UINT32&	COM_stui32DelegateThis(CUINT32 cui32iaddress)noexcept{
			return *PUINT32(COM_stcui32iAddressS+cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_	CUINT32&	COM_stcui32GetThis(CUINT32 cui32iaddress)noexcept{
			return *PCUINT32(COM_stcui32iAddressS+cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_	UINT16&	COM_stui16DelegateThis(CUINT32 cui32iaddress)noexcept{
			return *PUINT16(COM_stcui32iAddressS+cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_	CUINT16&	COM_stcui16GetThis(CUINT32 cui32iaddress)noexcept{
			return *PCUINT16(COM_stcui32iAddressS+cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_	UINT8&	COM_stui8DelegateThis(CUINT32 cui32iaddress)noexcept{
			return *PUINT8(COM_stcui32iAddressS+cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_	CUINT8&	COM_stcui8GetThis(CUINT32 cui32iaddress)noexcept{
			return *PCUINT8(COM_stcui32iAddressS+cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_ UINT16&	DEVICE_stui16DelegateThis(CUINT16 cui16iaddress)noexcept{
			return *PUINT16(DEVICE_stcui32iAddress+cui16iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_ CUINT16&	DEVICE_stcui16GetThis(CUINT16 cui16iaddress)noexcept{
			return *PCUINT16(DEVICE_stcui32iAddress+cui16iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_ UINT8&	DEVICE_stui8DelegateThis(CUINT16 cui16iaddress)noexcept{
			return *PUINT8(DEVICE_stcui32iAddress+cui16iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_ CUINT8&	DEVICE_stcui8GetThis(CUINT16 cui16iaddress)noexcept{
			return *PCUINT8(DEVICE_stcui32iAddress+cui16iaddress);
		}
	};
}

#endif
