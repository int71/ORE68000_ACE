/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/os.hpp'									2025 written by int71	**
 ****************************************************************************/
#ifndef I71_SUB_OS
#define I71_SUB_OS

//
//		include
//

#include				"base.hpp"

//
//		namespace:m68k::i71::sub
//

namespace m68k::i71::sub{

	//
	//		class
	//

	//	OS
	class OS;

	//
	//		class:OS
	//

	class OS{
	public:

		//
		//		const
		//

		static constexpr AUTO	RAM_stcui32iStackInitialAddress=				RAM_stcui32iAddress+RAM_stcui32nSize;

		//
		//		class
		//

		//	ST
		class ST;
		using					CST=const ST;
		using					PST=ST*;
		using					PCST=CST*;

		//
		//		class:ST
		//

		class ST{
		public:
			_UNDISCARDABLE_ OFWBOOL	eVBlank;
			SOUND_DRIVER			BGM_drvThis;
			SOUND_DRIVER			SE0_drvThis;
			SOUND_DRIVER			SE1_drvThis;
			SOUND_DRIVER			VOICE_drvThis;
			UINT16					BGM_ui16nVolumeFadeMain;
			UINT16					BGM_ui16nVolumeFadeSpeedMain;
		public:
			VOID					Delete(VOID)noexcept;
		};

		//
		//		body:OS
		//

	private:
		static inline ST		st;
	public:
		static VOID				stNew(VOID)noexcept;
		static VOID				stDelete(VOID)noexcept;
		static VOID				stMain(VOID)noexcept;
		static _INLINE_ VOID	BGM_stSetMask(CUINT16 cui16cchannelmask)noexcept{
			st.BGM_drvThis.Delete();
			st.BGM_drvThis.New(cui16cchannelmask);
			return;
		}
		static _INLINE_ VOID	BGM_stPlay(_UNDISCARDABLE_ CUINT8* const cpcui8csource)noexcept{
			st.BGM_drvThis.Play(cpcui8csource);
			BGM_stSetMasterVolume(255);
			return;
		}
		static _INLINE_ VOID	BGM_stSetMasterVolume(CUINT8 cui8nvolume)noexcept{
			st.BGM_drvThis.SetMasterVolume(cui8nvolume);
			st.BGM_ui16nVolumeFadeSpeedMain=0;
			return;
		}
		static _INLINE_ VOID	BGM_stSetMasterVolumeFade(CUINT8 cui8nvolumefade,CUINT8 cui8nvolumefadespeed)noexcept{
			st.BGM_ui16nVolumeFadeMain=UINT16(cui8nvolumefade)<<8;
			st.BGM_ui16nVolumeFadeSpeedMain=UINT16(cui8nvolumefadespeed)<<4;
			return;
		}
		static _INLINE_ VOID	SE0_stSetMask(CUINT16 cui16cchannelmask)noexcept{
			st.SE0_drvThis.Delete();
			st.SE0_drvThis.New(cui16cchannelmask);
			return;
		}
		static _INLINE_ VOID	SE0_stPlay(_UNDISCARDABLE_ CUINT8* const cpcui8csource)noexcept{
			st.SE0_drvThis.PlayDynamic(cpcui8csource);
			return;
		}
		static _INLINE_ VOID	SE1_stSetMask(CUINT16 cui16cchannelmask)noexcept{
			st.SE1_drvThis.Delete();
			st.SE1_drvThis.New(cui16cchannelmask);
			return;
		}
		static _INLINE_ VOID	SE1_stPlay(_UNDISCARDABLE_ CUINT8* const cpcui8csource)noexcept{
			st.SE1_drvThis.PlayDynamic(cpcui8csource);
			return;
		}
		static _INLINE_ VOID	VOICE_stPlay(_UNDISCARDABLE_ CUINT8* const cpcui8csource,CUINT16 cui16nblock)noexcept{
			st.VOICE_drvThis.PlayVoice(cpcui8csource,cui16nblock);
			return;
		}
		static _INLINE_ VOID	HPC_stReset(VOID)noexcept{
			DEVICE_HPC_stui16Delegate()=0;
			return;
		}
		static _INLINE_ UINT32	HPC_stui32Read(VOID)noexcept{
			CAUTO					cui16iupper=DEVICE_HPC_stui16Delegate();

			return (UINT32(cui16iupper)<<16)|UINT32(DEVICE_HPC_stui16Delegate());
		}
		static _INLINE_ VOID	LFSR_stSetSeed(CUINT32 cui32cseed)noexcept{
			DEVICE_LFSR_stui16Delegate()=0x0000|((cui32cseed>>24)&0xff);
			DEVICE_LFSR_stui16Delegate()=0x0100|((cui32cseed>>16)&0xff);
			DEVICE_LFSR_stui16Delegate()=0x0200|((cui32cseed>> 8)&0xff);
			DEVICE_LFSR_stui16Delegate()=0x0300|((cui32cseed>> 0)&0xff);
			return;
		}
		static _INLINE_ UINT16	LFSR_stui16Read(VOID)noexcept{
			return DEVICE_LFSR_stui16Delegate();
		}
		static _INLINE_ UINT16	DEVICE_KEYBOARD_stui16Read(CUINT8 cui8ibank)noexcept{
			DEVICE_KEYBOARD_stui16Delegate(MAP::DEVICE::KEYBOARD_stcui16dSelectOffset)=UINT16(cui8ibank);
			return DEVICE_KEYBOARD_stui16Delegate(MAP::DEVICE::KEYBOARD_stcui16dDataOffset);
		}
		static _INLINE_ UINT8	DEVICE_JOYSTICK_stui8Read(CUINT8 cui8ibank)noexcept{
			DEVICE_JOYSTICK_stui8Delegate(MAP::DEVICE::JOYSTICK_stcui16dSelectOffset)=cui8ibank;
			return DEVICE_JOYSTICK_stui8Delegate(MAP::DEVICE::JOYSTICK_stcui16dDataOffset);
		}
	private:
		static _HANDLER_ VOID	stINT1(VOID)noexcept;
		static _HANDLER_ VOID	stINT2(VOID)noexcept;
		static _HANDLER_ VOID	stINT3(VOID)noexcept;
		static _HANDLER_ VOID	stINT4(VOID)noexcept;
		static _HANDLER_ VOID	stINT5(VOID)noexcept;
		static _HANDLER_ VOID	stINT6(VOID)noexcept;
		static _HANDLER_ VOID	stINT7(VOID)noexcept;
		static _INLINE_ _UNDISCARDABLE_ UINT16&	DEVICE_HPC_stui16Delegate(VOID)noexcept{
			return MEMORY::DEVICE_stui16DelegateThis(MAP::DEVICE::HPC_stcui16dOffsetS);
		}
		static _INLINE_ _UNDISCARDABLE_ UINT16&	DEVICE_LFSR_stui16Delegate(VOID)noexcept{
			return MEMORY::DEVICE_stui16DelegateThis(MAP::DEVICE::LFSR_stcui16dOffsetS);
		}
		static _INLINE_ _UNDISCARDABLE_ UINT16&	DEVICE_KEYBOARD_stui16Delegate(CUINT16 cui16iaddress)noexcept{
			return MEMORY::DEVICE_stui16DelegateThis(MAP::DEVICE::KEYBOARD_stcui16dOffsetS+cui16iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_ UINT8&	DEVICE_JOYSTICK_stui8Delegate(CUINT16 cui16iaddress)noexcept{
			return MEMORY::DEVICE_stui8DelegateThis(MAP::DEVICE::JOYSTICK_stcui16dOffsetS+cui16iaddress);
		}
	};
}

#endif
