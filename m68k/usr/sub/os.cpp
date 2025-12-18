/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/os.cpp'									2025 written by int71	**
 ****************************************************************************/

//
//		include
//

#include				"os.hpp"
#include				"interrupter.hpp"
#include				"pattern.hpp"

//
//		using
//

using namespace m68k::i71::sub;

//
//		user
//

VOID					USER_New(VOID)noexcept;
VOID					USER_Delete(VOID)noexcept;
VOID					USER_Main(VOID)noexcept;

//
//		class:OS::ST
//

//	public

VOID					OS::ST::Delete(VOID)noexcept{
	return;
}

//
//		class:OS
//

//	public

VOID					OS::stNew(VOID)noexcept{
	static _VECTOR_ CUINT32	stacui32iexception[]={
		RAM_stcui32iStackInitialAddress,	//	0x00:InitialSSP
		UINT32(_main),			//	0x01:InitialPC
		0x000000,				//	0x02:BusError
		0x000000,				//	0x03:AddressError
		0x000000,				//	0x04:IllegalInstruction
		0x000000,				//	0x05:DivisionByZero
		0x000000,				//	0x06:CHK
		0x000000,				//	0x07:TRAPV
		0x000000,				//	0x08:PrivilegeViolation
		0x000000,				//	0x09:Trace
		0x000000,				//	0x0a:ALINE
		0x000000,				//	0x0b:FLINE
		0x000000,				//	0x0c:
		0x000000,				//	0x0d:
		0x000000,				//	0x0e:
		0x000000,				//	0x0f:INTUninitialised
		0x000000,				//	0x10:
		0x000000,				//	0x11:
		0x000000,				//	0x12:
		0x000000,				//	0x13:
		0x000000,				//	0x14:
		0x000000,				//	0x15:
		0x000000,				//	0x16:
		0x000000,				//	0x17:
		0x000000,				//	0x18:SpuriousInterrupt
		UINT32(stINT1),			//	0x19:INT1
		UINT32(stINT2),			//	0x1a:INT2
		UINT32(stINT3),			//	0x1b:INT3
		UINT32(stINT4),			//	0x1c:INT4
		UINT32(stINT5),			//	0x1d:INT5
		UINT32(stINT6),			//	0x1e:INT6
		UINT32(stINT7),			//	0x1f:INT7
		0x000000,				//	0x20:TRAP00
		0x000000,				//	0x21:TRAP01
		0x000000,				//	0x22:TRAP02
		0x000000,				//	0x23:TRAP03
		0x000000,				//	0x24:TRAP04
		0x000000,				//	0x25:TRAP05
		0x000000,				//	0x26:TRAP06
		0x000000,				//	0x27:TRAP07
		0x000000,				//	0x28:TRAP08
		0x000000,				//	0x29:TRAP09
		0x000000,				//	0x2a:TRAP10
		0x000000,				//	0x2b:TRAP11
		0x000000,				//	0x2c:TRAP12
		0x000000,				//	0x2d:TRAP13
		0x000000,				//	0x2e:TRAP14
		0x000000,				//	0x2f:TRAP15
		0x000000,				//	0x30:
		0x000000,				//	0x31:
		0x000000,				//	0x32:
		0x000000,				//	0x33:
		0x000000,				//	0x34:
		0x000000,				//	0x35:
		0x000000,				//	0x36:
		0x000000,				//	0x37:
		0x000000,				//	0x38:
		0x000000,				//	0x39:
		0x000000,				//	0x3a:
		0x000000,				//	0x3b:
		0x000000,				//	0x3c:
		0x000000,				//	0x3d:
		0x000000,				//	0x3e:
		0x000000,				//	0x3f:
		0x000000				//	0x40:INTUserBase
	};

	OFW::stDisableInterrupt();
	BASE::stNew();
	VIDEO_DRIVER::stNew();
	SOUND_DRIVER::stNew();
	st.BGM_drvThis.New(
		SOUND_DRIVER::stcui16cChannelMaskFM0|
		SOUND_DRIVER::stcui16cChannelMaskFM1|
		SOUND_DRIVER::stcui16cChannelMaskFM2|
		SOUND_DRIVER::stcui16cChannelMaskFM3|
		SOUND_DRIVER::stcui16cChannelMaskFM4|
		SOUND_DRIVER::stcui16cChannelMaskFM5|
		SOUND_DRIVER::stcui16cChannelMaskPCM0|
		SOUND_DRIVER::stcui16cChannelMaskPCM1|
		SOUND_DRIVER::stcui16cChannelMaskPCM2|
		SOUND_DRIVER::stcui16cChannelMaskPCM3|
		SOUND_DRIVER::stcui16cChannelMaskPCM4|
		SOUND_DRIVER::stcui16cChannelMaskPCM5|
		SOUND_DRIVER::stcui16cChannelMaskPCM6
	);
	st.SE0_drvThis.New(
		SOUND_DRIVER::stcui16cChannelMaskFM6
	);
	st.SE1_drvThis.New(
		SOUND_DRIVER::stcui16cChannelMaskFM7
	);
	st.VOICE_drvThis.New(
		SOUND_DRIVER::stcui16cChannelMaskPCM7
	);
	st.SE0_drvThis.SetMasterVolume(255);
	st.SE1_drvThis.SetMasterVolume(255);
	st.VOICE_drvThis.SetMasterVolume(255);
	DEBUG::stNew();
	INTERRUPTER::stNew();
	PATTERN::stNew();
	LFSR_stSetSeed(0);
	OFW::stEnableInterrupt();
	return;
}

VOID					OS::stDelete(VOID)noexcept{
	OFW::stDisableInterrupt();
	st.Delete();
	PATTERN::stDelete();
	INTERRUPTER::stDelete();
	DEBUG::stDelete();
	SOUND_DRIVER::stDelete();
	VIDEO_DRIVER::stDelete();
	BASE::stDelete();
	return;
}

VOID					OS::stMain(VOID)noexcept{
	USER_New();
	while(TRUE){
		st.eVBlank=FALSE;
		while(!st.eVBlank);
		USER_Main();
		st.BGM_drvThis.Progress();
		st.SE0_drvThis.Progress();
		st.SE1_drvThis.Progress();
		SOUND_DRIVER::stProgress();
	}
	USER_Delete();
	return;
}

//	private

_HANDLER_ VOID			OS::stINT1(VOID)noexcept{
	st.eVBlank=TRUE;
//	INTERRUPTER::stRaiseS2M(1);
	return;
}

_HANDLER_ VOID			OS::stINT2(VOID)noexcept{
	return;
}

_HANDLER_ VOID			OS::stINT3(VOID)noexcept{
	return;
}

_HANDLER_ VOID			OS::stINT4(VOID)noexcept{
	return;
}

_HANDLER_ VOID			OS::stINT5(VOID)noexcept{
	return;
}

_HANDLER_ VOID			OS::stINT6(VOID)noexcept{
	return;
}

_HANDLER_ VOID			OS::stINT7(VOID)noexcept{
	return;
}
