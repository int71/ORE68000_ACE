/****************************************************************************
**																			**
**																			**
**								ORE68000ACE									**
**																			**
**	'm68k/ore68000ace/driver/sound.cpp'				2025 written by int71	**
 ****************************************************************************/

//
//		include
//

#include				<ore68000ace/driver/sound.hpp>

//
//		using
//

using namespace m68k::ore68000ace::driver;

//
//		class:SOUND::FM
//

//	public

VOID					SOUND::FM::stNew(VOID)noexcept{
	for(UINT8 ui8ichannel=0;ui8ichannel<stcui8nChannel;++ui8ichannel){
		st.achnThis[ui8ichannel].SetChannel(ui8ichannel);
		DEVICE_FM_stWrite(IDREGISTERW::Key,(0x0<<3)|ui8ichannel);
		DEVICE_FM_stWrite(IDREGISTERW::Ch0M1TotalLevel7+ui8ichannel,127);
		DEVICE_FM_stWrite(IDREGISTERW::Ch0M2TotalLevel7+ui8ichannel,127);
		DEVICE_FM_stWrite(IDREGISTERW::Ch0C1TotalLevel7+ui8ichannel,127);
		DEVICE_FM_stWrite(IDREGISTERW::Ch0C2TotalLevel7+ui8ichannel,127);
		DEVICE_FM_stWrite(IDREGISTERW::Ch0StereoLevelR7+ui8ichannel,127);
		DEVICE_FM_stWrite(IDREGISTERW::Ch0StereoLevelL7+ui8ichannel,127);
	}
	return;
}

VOID					SOUND::FM::stDelete(VOID)noexcept{
	return;
}

VOID					SOUND::FM::stProgress(VOID)noexcept{
	for(AUTO& chncurrent:st.achnThis)chncurrent.Progress();
	return;
}

//
//		class:SOUND::PCM::CHANNEL
//

//	private

VOID					SOUND::PCM::CHANNEL::Progress_VoiceWrite64(VOID)noexcept{
	AUTO					pui8destination=&MEMORYS::PCMM_stui8DelegateThis(UINT32(Voice.ui16iBufferAddress+Voice.ui16iBufferProgress));
	CAUTO					cpui8destination_end=pui8destination+64;

	if(VOICE_ui16nSourceBlock64Margin<Voice.ui16nSourceBlock64){
		AUTO					pcui8source=Voice.pcui8Source;

		while(pui8destination<cpui8destination_end){
			*pui8destination=*pcui8source;++pui8destination;++pcui8source;
			*pui8destination=*pcui8source;++pui8destination;++pcui8source;
			*pui8destination=*pcui8source;++pui8destination;++pcui8source;
			*pui8destination=*pcui8source;++pui8destination;++pcui8source;
			*pui8destination=*pcui8source;++pui8destination;++pcui8source;
			*pui8destination=*pcui8source;++pui8destination;++pcui8source;
			*pui8destination=*pcui8source;++pui8destination;++pcui8source;
			*pui8destination=*pcui8source;++pui8destination;++pcui8source;
		}
		Voice.pcui8Source=pcui8source;
		--Voice.ui16nSourceBlock64;
	}else if(Voice.ui16nSourceBlock64){
		while(pui8destination<cpui8destination_end){
			*pui8destination=0;++pui8destination;*pui8destination=0;++pui8destination;
			*pui8destination=0;++pui8destination;*pui8destination=0;++pui8destination;
			*pui8destination=0;++pui8destination;*pui8destination=0;++pui8destination;
			*pui8destination=0;++pui8destination;*pui8destination=0;++pui8destination;
			*pui8destination=0;++pui8destination;*pui8destination=0;++pui8destination;
			*pui8destination=0;++pui8destination;*pui8destination=0;++pui8destination;
			*pui8destination=0;++pui8destination;*pui8destination=0;++pui8destination;
			*pui8destination=0;++pui8destination;*pui8destination=0;++pui8destination;
		}
		--Voice.ui16nSourceBlock64;
	}
	Voice.ui16iBufferProgress=(Voice.ui16iBufferProgress+64)&0x01ff;
	return;
}

//
//		class:SOUND::PCM
//

//	public

VOID					SOUND::PCM::stNew(VOID)noexcept{
	for(UINT8 ui8ichannel=0;ui8ichannel<stcui8nChannel;++ui8ichannel){
		st.achnThis[ui8ichannel].SetChannel(ui8ichannel);
		DEVICE_PCM_stWrite(IDREGISTERW::Key,(0x0<<3)|ui8ichannel);
		DEVICE_PCM_stWrite(IDREGISTERW::Ch0TotalLevel7+ui8ichannel,127);
		DEVICE_PCM_stWrite(IDREGISTERW::Ch0StereoLevelR7+ui8ichannel,127);
		DEVICE_PCM_stWrite(IDREGISTERW::Ch0StereoLevelL7+ui8ichannel,127);
	}
	PCMM_stWrite(0,PCVOID(ROM_PCM_stcui32iImageAddressS),0xff00);
	return;
}

VOID					SOUND::PCM::stDelete(VOID)noexcept{
	return;
}

VOID					SOUND::PCM::stProgress(VOID)noexcept{
	for(AUTO& chncurrent:st.achnThis)chncurrent.Progress();
	return;
}

VOID					SOUND::PCM::PCMM_stWrite(
	CUINT16					cui16idestination,
	const PCVOID			cpsource,
	CUINT16					cui16nsource
)noexcept{
	AUTO					pbdestination=&MEMORYS::PCMM_stui8DelegateThis(UINT32(cui16idestination));
	AUTO					pcbsource=PCBYTE(cpsource);
	CAUTO					cpcbsource_end=pcbsource+UINT32((cui16nsource-1)&0xffff)+1;

	while(pcbsource<cpcbsource_end){
		*pbdestination=*pcbsource;
		++pbdestination;
		++pcbsource;
	}
	return;
}

//
//		class:SOUND
//

VOID					SOUND::stNew(VOID)noexcept{
	DEVICE_FM_stWrite(FM_IDREGISTERW::NoiseDivRatio5,(0<<7)| 0);
	DEVICE_FM_stWrite(FM_IDREGISTERW::LFODepth7,(1<<7)|127);
	DEVICE_FM_stWrite(FM_IDREGISTERW::LFOShape2,2);
	stSetPitchModulationSpeed(0);
	FM::stNew();
	PCM::stNew();
	return;
}

VOID					SOUND::stDelete(VOID)noexcept{
	PCM::stDelete();
	FM::stDelete();
	return;
}

VOID					SOUND::New(
	CUINT16					cui16cchannelmask
)noexcept{
	ui16cChannelMask=cui16cchannelmask;
	ui8iVoiceChannel=(ui16cChannelMask&stcui16cChannelMaskPCM0)?0:(
		(ui16cChannelMask&stcui16cChannelMaskPCM1)?1:(
			(ui16cChannelMask&stcui16cChannelMaskPCM2)?2:(
				(ui16cChannelMask&stcui16cChannelMaskPCM3)?3:(
					(ui16cChannelMask&stcui16cChannelMaskPCM4)?4:(
						(ui16cChannelMask&stcui16cChannelMaskPCM5)?5:(
							(ui16cChannelMask&stcui16cChannelMaskPCM6)?6:(
								(ui16cChannelMask&stcui16cChannelMaskPCM7)?7:0xff
							)
						)
					)
				)
			)
		)
	);
	ROM_pcui8Cursor=NULL;
	return;
}

VOID					SOUND::Delete(VOID)noexcept{
	return;
}

VOID					SOUND::Play(
	_UNDISCARDABLE_ CUINT8* const	cpcui8source
)noexcept{
	ROM_pcui8Cursor=cpcui8source;
	if(ROM_pcui8Cursor){
		ui32nWait=1;
		ppcui8Stack=apcui8Stack+stcui8nStack;
	}else{
		SetMasterVolume(0);
		if(ui16cChannelMask&stcui16cChannelMaskFM0)FM::stchnDelegate(0).KeyOff();
		if(ui16cChannelMask&stcui16cChannelMaskFM1)FM::stchnDelegate(1).KeyOff();
		if(ui16cChannelMask&stcui16cChannelMaskFM2)FM::stchnDelegate(2).KeyOff();
		if(ui16cChannelMask&stcui16cChannelMaskFM3)FM::stchnDelegate(3).KeyOff();
		if(ui16cChannelMask&stcui16cChannelMaskFM4)FM::stchnDelegate(4).KeyOff();
		if(ui16cChannelMask&stcui16cChannelMaskFM5)FM::stchnDelegate(5).KeyOff();
		if(ui16cChannelMask&stcui16cChannelMaskFM6)FM::stchnDelegate(6).KeyOff();
		if(ui16cChannelMask&stcui16cChannelMaskFM7)FM::stchnDelegate(7).KeyOff();
		if(ui16cChannelMask&stcui16cChannelMaskPCM0)PCM::stchnDelegate(0).KeyOff();
		if(ui16cChannelMask&stcui16cChannelMaskPCM1)PCM::stchnDelegate(1).KeyOff();
		if(ui16cChannelMask&stcui16cChannelMaskPCM2)PCM::stchnDelegate(2).KeyOff();
		if(ui16cChannelMask&stcui16cChannelMaskPCM3)PCM::stchnDelegate(3).KeyOff();
		if(ui16cChannelMask&stcui16cChannelMaskPCM4)PCM::stchnDelegate(4).KeyOff();
		if(ui16cChannelMask&stcui16cChannelMaskPCM5)PCM::stchnDelegate(5).KeyOff();
		if(ui16cChannelMask&stcui16cChannelMaskPCM6)PCM::stchnDelegate(6).KeyOff();
		if(ui16cChannelMask&stcui16cChannelMaskPCM7)PCM::stchnDelegate(7).KeyOff();
	}
	return;
}

VOID					SOUND::SetMasterVolume(
	CUINT8					cui8nvolume
)noexcept{
	if(ui16cChannelMask&stcui16cChannelMaskFM0)FM::stchnDelegate(0).SetMasterVolume(cui8nvolume);
	if(ui16cChannelMask&stcui16cChannelMaskFM1)FM::stchnDelegate(1).SetMasterVolume(cui8nvolume);
	if(ui16cChannelMask&stcui16cChannelMaskFM2)FM::stchnDelegate(2).SetMasterVolume(cui8nvolume);
	if(ui16cChannelMask&stcui16cChannelMaskFM3)FM::stchnDelegate(3).SetMasterVolume(cui8nvolume);
	if(ui16cChannelMask&stcui16cChannelMaskFM4)FM::stchnDelegate(4).SetMasterVolume(cui8nvolume);
	if(ui16cChannelMask&stcui16cChannelMaskFM5)FM::stchnDelegate(5).SetMasterVolume(cui8nvolume);
	if(ui16cChannelMask&stcui16cChannelMaskFM6)FM::stchnDelegate(6).SetMasterVolume(cui8nvolume);
	if(ui16cChannelMask&stcui16cChannelMaskFM7)FM::stchnDelegate(7).SetMasterVolume(cui8nvolume);
	if(ui16cChannelMask&stcui16cChannelMaskPCM0)PCM::stchnDelegate(0).SetMasterVolume(cui8nvolume);
	if(ui16cChannelMask&stcui16cChannelMaskPCM1)PCM::stchnDelegate(1).SetMasterVolume(cui8nvolume);
	if(ui16cChannelMask&stcui16cChannelMaskPCM2)PCM::stchnDelegate(2).SetMasterVolume(cui8nvolume);
	if(ui16cChannelMask&stcui16cChannelMaskPCM3)PCM::stchnDelegate(3).SetMasterVolume(cui8nvolume);
	if(ui16cChannelMask&stcui16cChannelMaskPCM4)PCM::stchnDelegate(4).SetMasterVolume(cui8nvolume);
	if(ui16cChannelMask&stcui16cChannelMaskPCM5)PCM::stchnDelegate(5).SetMasterVolume(cui8nvolume);
	if(ui16cChannelMask&stcui16cChannelMaskPCM6)PCM::stchnDelegate(6).SetMasterVolume(cui8nvolume);
	if(ui16cChannelMask&stcui16cChannelMaskPCM7)PCM::stchnDelegate(7).SetMasterVolume(cui8nvolume);
	return;
}

VOID					SOUND::PlayVoice(
	_UNDISCARDABLE_ CUINT8* const	cpcui8source,
	CUINT16					cui16nsourceblock,
	CUINT8					cui8ibufferblockaddress
)noexcept{
	if(ui8iVoiceChannel<8)PCM::stchnDelegate(ui8iVoiceChannel).PlayVoice(cpcui8source,cui16nsourceblock,cui8ibufferblockaddress);
	return;
}

VOID					SOUND::Progress(VOID)noexcept{
	if(ROM_pcui8Cursor){
		--ui32nWait;
		if(ui32nWait==0){
			OFWBOOL					eprogress=TRUE;

			while((ui32nWait=ROM_ui32ReadVU())==0)switch(
				CAUTO					cui8cflowtype=ROM_ui8Read();
				IDFLOW(cui8cflowtype>>6)
			){
			case IDFLOW::Jump:
				ROM_pcui8Cursor+=ROM_ui32dGetCursorOffset(cui8cflowtype);
				break;
			case IDFLOW::Call:
				--ppcui8Stack;
				*ppcui8Stack=ROM_pcui8Cursor;
				ROM_pcui8Cursor+=ROM_ui32dGetCursorOffset(cui8cflowtype);
				break;
			case IDFLOW::Return:
				ROM_pcui8Cursor=*ppcui8Stack;
				++ppcui8Stack;
				break;
			case IDFLOW::End:
				ROM_pcui8Cursor=NULL;
				return;
			}
			while(eprogress){
				CAUTO					cui8cevent=ROM_ui8Read();
				CAUTO					cidevent=IDEVENT((cui8cevent>>4)&0xf);
				CAUTO					cidchannel=IDCHANNEL(cui8cevent&0xf);

				switch(cidevent){
				case IDEVENT::KeyOn:
					switch(cidchannel){
					case IDCHANNEL::FM0:FALLTHROUGH;
					case IDCHANNEL::FM1:FALLTHROUGH;
					case IDCHANNEL::FM2:FALLTHROUGH;
					case IDCHANNEL::FM3:FALLTHROUGH;
					case IDCHANNEL::FM4:FALLTHROUGH;
					case IDCHANNEL::FM5:FALLTHROUGH;
					case IDCHANNEL::FM6:FALLTHROUGH;
					case IDCHANNEL::FM7:
						FM::stchnDelegate(UINT8(cidchannel-IDCHANNEL::FM0)).KeyOn(ROM_ui8Read());
						break;
					case IDCHANNEL::PCM0:FALLTHROUGH;
					case IDCHANNEL::PCM1:FALLTHROUGH;
					case IDCHANNEL::PCM2:FALLTHROUGH;
					case IDCHANNEL::PCM3:FALLTHROUGH;
					case IDCHANNEL::PCM4:FALLTHROUGH;
					case IDCHANNEL::PCM5:FALLTHROUGH;
					case IDCHANNEL::PCM6:FALLTHROUGH;
					case IDCHANNEL::PCM7:
						PCM::stchnDelegate(UINT8(cidchannel-IDCHANNEL::PCM0)).KeyOn(ROM_ui8Read());
						break;
					}
					break;
				case IDEVENT::KeyOff:
					switch(cidchannel){
					case IDCHANNEL::FM0:FALLTHROUGH;
					case IDCHANNEL::FM1:FALLTHROUGH;
					case IDCHANNEL::FM2:FALLTHROUGH;
					case IDCHANNEL::FM3:FALLTHROUGH;
					case IDCHANNEL::FM4:FALLTHROUGH;
					case IDCHANNEL::FM5:FALLTHROUGH;
					case IDCHANNEL::FM6:FALLTHROUGH;
					case IDCHANNEL::FM7:
						FM::stchnDelegate(UINT8(cidchannel-IDCHANNEL::FM0)).KeyOff();
						break;
					case IDCHANNEL::PCM0:FALLTHROUGH;
					case IDCHANNEL::PCM1:FALLTHROUGH;
					case IDCHANNEL::PCM2:FALLTHROUGH;
					case IDCHANNEL::PCM3:FALLTHROUGH;
					case IDCHANNEL::PCM4:FALLTHROUGH;
					case IDCHANNEL::PCM5:FALLTHROUGH;
					case IDCHANNEL::PCM6:FALLTHROUGH;
					case IDCHANNEL::PCM7:
						PCM::stchnDelegate(UINT8(cidchannel-IDCHANNEL::PCM0)).KeyOff();
						break;
					}
					break;
				case IDEVENT::KeyOnChange:
					switch(cidchannel){
					case IDCHANNEL::FM0:FALLTHROUGH;
					case IDCHANNEL::FM1:FALLTHROUGH;
					case IDCHANNEL::FM2:FALLTHROUGH;
					case IDCHANNEL::FM3:FALLTHROUGH;
					case IDCHANNEL::FM4:FALLTHROUGH;
					case IDCHANNEL::FM5:FALLTHROUGH;
					case IDCHANNEL::FM6:FALLTHROUGH;
					case IDCHANNEL::FM7:
						FM::stchnDelegate(UINT8(cidchannel-IDCHANNEL::FM0)).KeyOnChange(ROM_ui8Read());
						break;
					case IDCHANNEL::PCM0:FALLTHROUGH;
					case IDCHANNEL::PCM1:FALLTHROUGH;
					case IDCHANNEL::PCM2:FALLTHROUGH;
					case IDCHANNEL::PCM3:FALLTHROUGH;
					case IDCHANNEL::PCM4:FALLTHROUGH;
					case IDCHANNEL::PCM5:FALLTHROUGH;
					case IDCHANNEL::PCM6:FALLTHROUGH;
					case IDCHANNEL::PCM7:
						PCM::stchnDelegate(UINT8(cidchannel-IDCHANNEL::PCM0)).KeyOnChange(ROM_ui8Read());
						break;
					}
					break;
				case IDEVENT::KeyOffChange:
					switch(cidchannel){
					case IDCHANNEL::FM0:FALLTHROUGH;
					case IDCHANNEL::FM1:FALLTHROUGH;
					case IDCHANNEL::FM2:FALLTHROUGH;
					case IDCHANNEL::FM3:FALLTHROUGH;
					case IDCHANNEL::FM4:FALLTHROUGH;
					case IDCHANNEL::FM5:FALLTHROUGH;
					case IDCHANNEL::FM6:FALLTHROUGH;
					case IDCHANNEL::FM7:
						FM::stchnDelegate(UINT8(cidchannel-IDCHANNEL::FM0)).KeyOffChange(ROM_ui8Read());
						break;
					case IDCHANNEL::PCM0:FALLTHROUGH;
					case IDCHANNEL::PCM1:FALLTHROUGH;
					case IDCHANNEL::PCM2:FALLTHROUGH;
					case IDCHANNEL::PCM3:FALLTHROUGH;
					case IDCHANNEL::PCM4:FALLTHROUGH;
					case IDCHANNEL::PCM5:FALLTHROUGH;
					case IDCHANNEL::PCM6:FALLTHROUGH;
					case IDCHANNEL::PCM7:
						PCM::stchnDelegate(UINT8(cidchannel-IDCHANNEL::PCM0)).KeyOffChange(ROM_ui8Read());
						break;
					}
					break;
				case IDEVENT::Volume:
					switch(cidchannel){
					case IDCHANNEL::FM0:FALLTHROUGH;
					case IDCHANNEL::FM1:FALLTHROUGH;
					case IDCHANNEL::FM2:FALLTHROUGH;
					case IDCHANNEL::FM3:FALLTHROUGH;
					case IDCHANNEL::FM4:FALLTHROUGH;
					case IDCHANNEL::FM5:FALLTHROUGH;
					case IDCHANNEL::FM6:FALLTHROUGH;
					case IDCHANNEL::FM7:
						FM::stchnDelegate(UINT8(cidchannel-IDCHANNEL::FM0)).SetChannelVolume(ROM_ui8Read());
						break;
					case IDCHANNEL::PCM0:FALLTHROUGH;
					case IDCHANNEL::PCM1:FALLTHROUGH;
					case IDCHANNEL::PCM2:FALLTHROUGH;
					case IDCHANNEL::PCM3:FALLTHROUGH;
					case IDCHANNEL::PCM4:FALLTHROUGH;
					case IDCHANNEL::PCM5:FALLTHROUGH;
					case IDCHANNEL::PCM6:FALLTHROUGH;
					case IDCHANNEL::PCM7:
						PCM::stchnDelegate(UINT8(cidchannel-IDCHANNEL::PCM0)).SetChannelVolume(ROM_ui8Read());
						break;
					}
					break;
				case IDEVENT::Pan:
					switch(cidchannel){
					case IDCHANNEL::FM0:FALLTHROUGH;
					case IDCHANNEL::FM1:FALLTHROUGH;
					case IDCHANNEL::FM2:FALLTHROUGH;
					case IDCHANNEL::FM3:FALLTHROUGH;
					case IDCHANNEL::FM4:FALLTHROUGH;
					case IDCHANNEL::FM5:FALLTHROUGH;
					case IDCHANNEL::FM6:FALLTHROUGH;
					case IDCHANNEL::FM7:
						FM::stchnDelegate(UINT8(cidchannel-IDCHANNEL::FM0)).SetPan(INT8(ROM_ui8Read()));
						break;
					case IDCHANNEL::PCM0:FALLTHROUGH;
					case IDCHANNEL::PCM1:FALLTHROUGH;
					case IDCHANNEL::PCM2:FALLTHROUGH;
					case IDCHANNEL::PCM3:FALLTHROUGH;
					case IDCHANNEL::PCM4:FALLTHROUGH;
					case IDCHANNEL::PCM5:FALLTHROUGH;
					case IDCHANNEL::PCM6:FALLTHROUGH;
					case IDCHANNEL::PCM7:
						PCM::stchnDelegate(UINT8(cidchannel-IDCHANNEL::PCM0)).SetPan(INT8(ROM_ui8Read()));
						break;
					}
					break;
				case IDEVENT::Portamento:
					switch(cidchannel){
					case IDCHANNEL::FM0:FALLTHROUGH;
					case IDCHANNEL::FM1:FALLTHROUGH;
					case IDCHANNEL::FM2:FALLTHROUGH;
					case IDCHANNEL::FM3:FALLTHROUGH;
					case IDCHANNEL::FM4:FALLTHROUGH;
					case IDCHANNEL::FM5:FALLTHROUGH;
					case IDCHANNEL::FM6:FALLTHROUGH;
					case IDCHANNEL::FM7:
						FM::stchnDelegate(UINT8(cidchannel-IDCHANNEL::FM0)).SetPortamento(ROM_ui16Read());
						break;
					case IDCHANNEL::PCM0:FALLTHROUGH;
					case IDCHANNEL::PCM1:FALLTHROUGH;
					case IDCHANNEL::PCM2:FALLTHROUGH;
					case IDCHANNEL::PCM3:FALLTHROUGH;
					case IDCHANNEL::PCM4:FALLTHROUGH;
					case IDCHANNEL::PCM5:FALLTHROUGH;
					case IDCHANNEL::PCM6:FALLTHROUGH;
					case IDCHANNEL::PCM7:
						PCM::stchnDelegate(UINT8(cidchannel-IDCHANNEL::PCM0)).SetPortamento(ROM_ui16Read());
						break;
					}
					break;
				case IDEVENT::Detune:
					switch(cidchannel){
					case IDCHANNEL::FM0:FALLTHROUGH;
					case IDCHANNEL::FM1:FALLTHROUGH;
					case IDCHANNEL::FM2:FALLTHROUGH;
					case IDCHANNEL::FM3:FALLTHROUGH;
					case IDCHANNEL::FM4:FALLTHROUGH;
					case IDCHANNEL::FM5:FALLTHROUGH;
					case IDCHANNEL::FM6:FALLTHROUGH;
					case IDCHANNEL::FM7:
						FM::stchnDelegate(UINT8(cidchannel-IDCHANNEL::FM0)).SetDetune(ROM_ui16Read());
						break;
					case IDCHANNEL::PCM0:FALLTHROUGH;
					case IDCHANNEL::PCM1:FALLTHROUGH;
					case IDCHANNEL::PCM2:FALLTHROUGH;
					case IDCHANNEL::PCM3:FALLTHROUGH;
					case IDCHANNEL::PCM4:FALLTHROUGH;
					case IDCHANNEL::PCM5:FALLTHROUGH;
					case IDCHANNEL::PCM6:FALLTHROUGH;
					case IDCHANNEL::PCM7:
						PCM::stchnDelegate(UINT8(cidchannel-IDCHANNEL::PCM0)).SetDetune(ROM_ui16Read());
						break;
					}
					break;
				case IDEVENT::PitchModulationDepth:
					switch(cidchannel){
					case IDCHANNEL::FM0:FALLTHROUGH;
					case IDCHANNEL::FM1:FALLTHROUGH;
					case IDCHANNEL::FM2:FALLTHROUGH;
					case IDCHANNEL::FM3:FALLTHROUGH;
					case IDCHANNEL::FM4:FALLTHROUGH;
					case IDCHANNEL::FM5:FALLTHROUGH;
					case IDCHANNEL::FM6:FALLTHROUGH;
					case IDCHANNEL::FM7:
						FM::stchnDelegate(UINT8(cidchannel-IDCHANNEL::FM0)).SetPitchModulationDepth(ROM_ui8Read());
						break;
					case IDCHANNEL::PCM0:FALLTHROUGH;
					case IDCHANNEL::PCM1:FALLTHROUGH;
					case IDCHANNEL::PCM2:FALLTHROUGH;
					case IDCHANNEL::PCM3:FALLTHROUGH;
					case IDCHANNEL::PCM4:FALLTHROUGH;
					case IDCHANNEL::PCM5:FALLTHROUGH;
					case IDCHANNEL::PCM6:FALLTHROUGH;
					case IDCHANNEL::PCM7:
						PCM::stchnDelegate(UINT8(cidchannel-IDCHANNEL::PCM0)).SetPitchModulationDepth(ROM_ui8Read());
						break;
					}
					break;
				case IDEVENT::ProgramChange:
					switch(cidchannel){
					case IDCHANNEL::FM0:FALLTHROUGH;
					case IDCHANNEL::FM1:FALLTHROUGH;
					case IDCHANNEL::FM2:FALLTHROUGH;
					case IDCHANNEL::FM3:FALLTHROUGH;
					case IDCHANNEL::FM4:FALLTHROUGH;
					case IDCHANNEL::FM5:FALLTHROUGH;
					case IDCHANNEL::FM6:FALLTHROUGH;
					case IDCHANNEL::FM7:
						FM::stchnDelegate(UINT8(cidchannel-IDCHANNEL::FM0)).ProgramChange(ROM_ui8Read());
						break;
					case IDCHANNEL::PCM0:FALLTHROUGH;
					case IDCHANNEL::PCM1:FALLTHROUGH;
					case IDCHANNEL::PCM2:FALLTHROUGH;
					case IDCHANNEL::PCM3:FALLTHROUGH;
					case IDCHANNEL::PCM4:FALLTHROUGH;
					case IDCHANNEL::PCM5:FALLTHROUGH;
					case IDCHANNEL::PCM6:FALLTHROUGH;
					case IDCHANNEL::PCM7:
						PCM::stchnDelegate(UINT8(cidchannel-IDCHANNEL::PCM0)).ProgramChange(ROM_ui8Read());
						break;
					}
					break;
				case IDEVENT::Common:
					switch(IDEVENTCOMMON(cidchannel)){
					case IDEVENTCOMMON::PitchModulationSpeed:
						stSetPitchModulationSpeed(ROM_ui8Read());
						break;
					case IDEVENTCOMMON::End:
						eprogress=FALSE;
						break;
					}
					break;
				}
			}
		}
	}
	return;
}

//	private

UINT32					SOUND::ROM_ui32ReadVU(VOID)noexcept{
	UINT32					ui32return=0;

	while(TRUE){
		CAUTO					cui8current=ROM_ui8Read();

		ui32return=(ui32return<<7)|(cui8current&0x7f);
		if((cui8current&0x80)==0)break;
	}
	return ui32return;
}

UINT32					SOUND::ROM_ui32dGetCursorOffset(
	CUINT8					cui8cflowtype
)noexcept{
	CAUTO					cui8m=ROM_ui8Read();
	CAUTO					cui8l=ROM_ui8Read();
	CAUTO					cui32dcursoroffset=UINT32(
		(UINT32(cui8cflowtype)<<16)|
		(UINT32(cui8m)<< 8)|
		(UINT32(cui8l)<< 0)
	);
	return (cui32dcursoroffset&0x00200000)?(cui32dcursoroffset|0xffe00000):(cui32dcursoroffset&0x001fffff);
}
