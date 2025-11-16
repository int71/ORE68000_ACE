/****************************************************************************
**																			**
**																			**
**								ORE68000ACE									**
**																			**
**	'm68k/ore68000ace/driver/sound.hpp'				2025 written by int71	**
 ****************************************************************************/
#ifndef M68K_ORE68000ACE_DRIVER_SOUND
#define M68K_ORE68000ACE_DRIVER_SOUND

//
//		include
//

#include				<sound/ym2151b.hpp>
#include				<ore68000ace/memory.hpp>

//
//		namespace:m68k::ore68000ace::driver
//

namespace m68k::ore68000ace::driver{

	//
	//		class
	//

	class SOUND;
	using					CSOUND=const SOUND;
	using					PSOUND=SOUND*;
	using					PCSOUND=CSOUND*;

	//
	//		class:SOUND
	//

	class SOUND{
	public:

		//
		//		class
		//

		using					DEVICE=											sound::YM2151B;

		//
		//		const
		//

		using					FM_IDREGISTERW=									DEVICE::FM_IDREGISTERW;
		using					FM_IDOPERATOR=									DEVICE::FM_IDOPERATOR;
		using					PCM_IDREGISTERW=								DEVICE::PCM_IDREGISTERW;
		using					PCM_IDINTERPOLATION=							DEVICE::PCM_IDINTERPOLATION;
		using					IDREGISTERR=									DEVICE::IDREGISTERR;
		class _IDFLOW{
		public:
			enum BODY:UINT8{
				Jump=					0,
				Call=					1,
				Return=					2,
				End=					3
			};
		};
		using					IDFLOW=_IDFLOW::BODY;
		class _IDEVENT{
		public:
			enum BODY:UINT8{
				KeyOn=					0x0,
				KeyOff=					0x1,
				KeyOnChange=			0x2,
				KeyOffChange=			0x3,
				Volume=					0x4,
				Pan=					0x5,
				Portamento=				0x8,
				Detune=					0x9,
				PitchModulationDepth=	0xa,
				ProgramChange=			0xc,
				Common=					0xf
			};
		};
		using					IDEVENT=_IDEVENT::BODY;
		class _IDEVENTCOMMON{
		public:
			enum BODY:UINT8{
				PitchModulationSpeed=	0x0,
				End=					0xf
			};
		};
		using					IDEVENTCOMMON=_IDEVENTCOMMON::BODY;
		class _IDCHANNEL{
		public:
			enum BODY:UINT8{
				FM0=					0x0,
				FM1=					0x1,
				FM2=					0x2,
				FM3=					0x3,
				FM4=					0x4,
				FM5=					0x5,
				FM6=					0x6,
				FM7=					0x7,
				PCM0=					0x8,
				PCM1=					0x9,
				PCM2=					0xa,
				PCM3=					0xb,
				PCM4=					0xc,
				PCM5=					0xd,
				PCM6=					0xe,
				PCM7=					0xf
			};
		};
		using					IDCHANNEL=_IDCHANNEL::BODY;
		static constexpr AUTO	DEVICE_stcui16nPort=							DEVICE_SOUND_stcui16nPort;
		static constexpr AUTO	DEVICE_FM_stcui16dSelectWOffset=				DEVICE_SOUND_FM_stcui16dSelectWOffset;
		static constexpr AUTO	DEVICE_PCM_stcui16dSelectWOffset=				DEVICE_SOUND_PCM_stcui16dSelectWOffset;
		static constexpr AUTO	DEVICE_stcui16dSelectROffset=					DEVICE_SOUND_stcui16dSelectROffset;
		static constexpr AUTO	DEVICE_stcui16dDataOffset=						DEVICE_SOUND_stcui16dDataOffset;
		static constexpr AUTO	FM_stcui8nChannel=								DEVICE::FM_stcui8nChannel;
		static constexpr AUTO	FM_stcui8nOperator=								DEVICE::FM_stcui8nOperator;
		static constexpr AUTO	PCM_stcui8nChannel=								DEVICE::PCM_stcui8nChannel;
		static constexpr AUTO	ROM_FM_stcui32iBankAddressS=					ROM_SOUND_stcui32iAddressS+0x000000;
		static constexpr AUTO	ROM_PCM_stcui32iBankAddressS=					ROM_SOUND_stcui32iAddressS+0x002000;
		static constexpr AUTO	ROM_PCM_stcui32iImageAddressS=					ROM_SOUND_stcui32iAddressS+0x002800;
		static constexpr UINT16	stcui16cChannelMaskFM0=							1<<IDCHANNEL::FM0;
		static constexpr UINT16	stcui16cChannelMaskFM1=							1<<IDCHANNEL::FM1;
		static constexpr UINT16	stcui16cChannelMaskFM2=							1<<IDCHANNEL::FM2;
		static constexpr UINT16	stcui16cChannelMaskFM3=							1<<IDCHANNEL::FM3;
		static constexpr UINT16	stcui16cChannelMaskFM4=							1<<IDCHANNEL::FM4;
		static constexpr UINT16	stcui16cChannelMaskFM5=							1<<IDCHANNEL::FM5;
		static constexpr UINT16	stcui16cChannelMaskFM6=							1<<IDCHANNEL::FM6;
		static constexpr UINT16	stcui16cChannelMaskFM7=							1<<IDCHANNEL::FM7;
		static constexpr UINT16	stcui16cChannelMaskPCM0=						1<<IDCHANNEL::PCM0;
		static constexpr UINT16	stcui16cChannelMaskPCM1=						1<<IDCHANNEL::PCM1;
		static constexpr UINT16	stcui16cChannelMaskPCM2=						1<<IDCHANNEL::PCM2;
		static constexpr UINT16	stcui16cChannelMaskPCM3=						1<<IDCHANNEL::PCM3;
		static constexpr UINT16	stcui16cChannelMaskPCM4=						1<<IDCHANNEL::PCM4;
		static constexpr UINT16	stcui16cChannelMaskPCM5=						1<<IDCHANNEL::PCM5;
		static constexpr UINT16	stcui16cChannelMaskPCM6=						1<<IDCHANNEL::PCM6;
		static constexpr UINT16	stcui16cChannelMaskPCM7=						1<<IDCHANNEL::PCM7;
		static constexpr UINT8	stcui8nStack=									4;
		static constexpr UINT8	stacui8iNote[]={
			0x00,0x01,0x02,0x04,0x05,0x06,0x08,0x09,0x0a,0x0c,0x0d,0x0e,
			0x10,0x11,0x12,0x14,0x15,0x16,0x18,0x19,0x1a,0x1c,0x1d,0x1e,
			0x20,0x21,0x22,0x24,0x25,0x26,0x28,0x29,0x2a,0x2c,0x2d,0x2e,
			0x30,0x31,0x32,0x34,0x35,0x36,0x38,0x39,0x3a,0x3c,0x3d,0x3e,
			0x40,0x41,0x42,0x44,0x45,0x46,0x48,0x49,0x4a,0x4c,0x4d,0x4e,
			0x50,0x51,0x52,0x54,0x55,0x56,0x58,0x59,0x5a,0x5c,0x5d,0x5e,
			0x60,0x61,0x62,0x64,0x65,0x66,0x68,0x69,0x6a,0x6c,0x6d,0x6e,
			0x70,0x71,0x72,0x74,0x75,0x76,0x78,0x79,0x7a,0x7c,0x7d,0x7e
		};
		static constexpr UINT8	stacui8nVolume[]={
			      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,
			  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
			  2,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,
			  4,  4,  4,  4,  5,  5,  5,  5,  5,  5,  6,  6,  6,  6,  6,  7,
			  7,  7,  7,  8,  8,  8,  8,  9,  9,  9,  9, 10, 10, 10, 11, 11,
			 11, 12, 12, 12, 13, 13, 14, 14, 15, 15, 16, 16, 17, 17, 18, 19,
			 19, 20, 21, 22, 23, 24, 25, 27, 28, 30, 32, 35, 38, 43, 51,127
		};

		//
		//		class
		//

		//	FM
		class FM;
		using					CFM=const FM;
		using					PFM=FM*;
		using					PCFM=CFM*;
		//	PCM
		class PCM;
		using					CPCM=const PCM;
		using					PPCM=PCM*;
		using					PCPCM=CPCM*;
		//	ST
		class ST;
		using					CST=const ST;
		using					PST=ST*;
		using					PCST=CST*;

		//
		//		class:FM
		//

		//	FM
		class FM{
		public:

			//
			//		const
			//

			using					IDREGISTERW=									FM_IDREGISTERW;
			using					IDOPERATOR=										FM_IDOPERATOR;
			static constexpr AUTO	stcui8nChannel=									FM_stcui8nChannel;
			static constexpr AUTO	stcui8nOperator=								FM_stcui8nOperator;
			static constexpr AUTO	stcui8cKeyDefault=								0x80;
			static constexpr AUTO	ROM_stcui32iBankAddress=						ROM_FM_stcui32iBankAddressS;

			//
			//		class
			//

			//	CHANNEL
			class CHANNEL;
			using					CCHANNEL=const CHANNEL;
			using					PCHANNEL=CHANNEL*;
			using					PCCHANNEL=CCHANNEL*;
			//	ST
			class ST;
			using					CST=const ST;
			using					PST=ST*;
			using					PCST=CST*;

			//
			//		class:CHANNEL
			//

			class CHANNEL{
			private:
				UINT8					ui8iChannel;
				UINT8					ui8nMasterVolume;
				UINT8					ui8nChannelVolume;
				UINT8					ui8nChannelVolumeL;
				UINT8					ui8nChannelVolumeR;
				INT16					i16iTone;
				INT16					i16iTonePrevious;
				INT16					i16dPortamento;
				INT16					i16dDetune;
				UINT8					ARG_ui8nMasterVolume;
				UINT8					ARG_ui8nChannelVolume;
				INT8					ARG_i8iPan;
				UINT8					ARG_ui8nPitchModulationDepth;
				UINT8					ARG_ui8iProgram;
				OFWBOOL					eSetVolume:1;
				OFWBOOL					eKeyOn:1;
			public:
				constexpr /*VOID*/		CHANNEL(VOID)noexcept:
					ui8iChannel(0),
					ui8nMasterVolume(0x00),
					ui8nChannelVolume(0x7f),
					ui8nChannelVolumeL(4),
					ui8nChannelVolumeR(4),
					i16iTone(0),
					i16iTonePrevious(0),
					i16dPortamento(0),
					ARG_ui8nMasterVolume(255),
					ARG_ui8nChannelVolume(0),
					ARG_i8iPan(0),
					ARG_ui8nPitchModulationDepth(0),
					ARG_ui8iProgram(255),
					eSetVolume(TRUE),
					eKeyOn(FALSE)
				{}
				constexpr VOID			SetChannel(CUINT8 cui8ichannel)noexcept{
					ui8iChannel=cui8ichannel;
					return;
				}
				_INLINE_ VOID			KeyOn(CUINT8 cui8inote)noexcept{
					i16iTone=INT16(cui8inote)<<8;
					i16dPortamento=0;
					eKeyOn=TRUE;
					return;
				}
				_INLINE_ VOID			KeyOff(VOID)noexcept{
					DEVICE_FM_stWrite(IDREGISTERW::Key,stcui8cKeyDefault|(0x0<<3)|ui8iChannel);
					i16dPortamento=0;
					return;
				}
				_INLINE_ VOID			KeyOnChange(CUINT8 cui8inote)noexcept{
					i16iTone=INT16(cui8inote)<<8;
					i16dPortamento=0;
					return;
				}
				_INLINE_ VOID			KeyOffChange(CUINT8 cui8inote)noexcept{
					DEVICE_FM_stWrite(IDREGISTERW::Key,stcui8cKeyDefault|(0x0<<3)|ui8iChannel);
					i16iTone=INT16(cui8inote)<<8;
					i16dPortamento=0;
					return;
				}
				_INLINE_ VOID			SetMasterVolume(CUINT8 cui8nmastervolume)noexcept{
					if(cui8nmastervolume!=ARG_ui8nMasterVolume){
						ui8nMasterVolume=UINT8(127-(cui8nmastervolume>>1));
						eSetVolume=TRUE;
						ARG_ui8nMasterVolume=cui8nmastervolume;
					}
					return;
				}
				_INLINE_ VOID			SetChannelVolume(CUINT8 cui8nchannelvolume)noexcept{
					if(cui8nchannelvolume!=ARG_ui8nChannelVolume){
						ui8nChannelVolume=UINT8(127-(cui8nchannelvolume>>1));
						eSetVolume=TRUE;
						ARG_ui8nChannelVolume=cui8nchannelvolume;
					}
					return;
				}
				_INLINE_ VOID			SetPan(CINT8 ci8ipan)noexcept{
					if(ci8ipan!=ARG_i8iPan){
						CAUTO					cui8ipan=UINT8((ci8ipan>>1)+0x40);

						ui8nChannelVolumeL=stacui8nVolume[cui8ipan-1];
						ui8nChannelVolumeR=stacui8nVolume[127-cui8ipan];
						eSetVolume=TRUE;
						ARG_i8iPan=ci8ipan;
					}
					return;
				}
				_INLINE_ VOID			SetPortamento(CINT16 ci16dportamento)noexcept{
					i16dPortamento=ci16dportamento;
					return;
				}
				_INLINE_ VOID			SetDetune(CUINT16 ci16ddetune)noexcept{
					if(ci16ddetune!=i16dDetune){
						i16iTonePrevious=0;
						i16dDetune=ci16ddetune;
					}
					return;
				}
				_INLINE_ VOID			SetPitchModulationDepth(CUINT8 cui8npitchmodulationdepth)noexcept{
					if(cui8npitchmodulationdepth!=ARG_ui8nPitchModulationDepth){
						DEVICE_FM_stWrite(IDREGISTERW::Ch0PMS3AMS2+ui8iChannel,(cui8npitchmodulationdepth>>1)&0x70);
						ARG_ui8nPitchModulationDepth=cui8npitchmodulationdepth;
					}
					return;
				}
				_INLINE_ VOID			ProgramChange(CUINT8 cui8iprogram)noexcept{
					if(cui8iprogram!=ARG_ui8iProgram){
						CAUTO					cpcui8program=PCUINT8(ROM_stcui32iBankAddress+(UINT16(cui8iprogram)<<5));

						DEVICE_FM_stWrite(IDREGISTERW::Ch0Feedback3Connect3+ui8iChannel,			cpcui8program[0x00]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0M1DetuneFine3Multiply4+ui8iChannel,		cpcui8program[0x08]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0M2DetuneFine3Multiply4+ui8iChannel,		cpcui8program[0x09]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0C1DetuneFine3Multiply4+ui8iChannel,		cpcui8program[0x0a]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0C2DetuneFine3Multiply4+ui8iChannel,		cpcui8program[0x0b]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0M1TotalLevel7+ui8iChannel,				cpcui8program[0x0c]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0M2TotalLevel7+ui8iChannel,				cpcui8program[0x0d]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0C1TotalLevel7+ui8iChannel,				cpcui8program[0x0e]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0C2TotalLevel7+ui8iChannel,				cpcui8program[0x0f]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0M1KeyScale2AttackRate5+ui8iChannel,		cpcui8program[0x10]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0M2KeyScale2AttackRate5+ui8iChannel,		cpcui8program[0x11]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0C1KeyScale2AttackRate5+ui8iChannel,		cpcui8program[0x12]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0C2KeyScale2AttackRate5+ui8iChannel,		cpcui8program[0x13]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0M1AME1Decay1Rate5+ui8iChannel,			cpcui8program[0x14]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0M2AME1Decay1Rate5+ui8iChannel,			cpcui8program[0x15]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0C1AME1Decay1Rate5+ui8iChannel,			cpcui8program[0x16]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0C2AME1Decay1Rate5+ui8iChannel,			cpcui8program[0x17]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0M1DetuneRough2Decay2Rate5+ui8iChannel,	cpcui8program[0x18]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0M2DetuneRough2Decay2Rate5+ui8iChannel,	cpcui8program[0x19]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0C1DetuneRough2Decay2Rate5+ui8iChannel,	cpcui8program[0x1a]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0C2DetuneRough2Decay2Rate5+ui8iChannel,	cpcui8program[0x1b]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0M1DecayLevel4ReleaseRate4+ui8iChannel,	cpcui8program[0x1c]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0M2DecayLevel4ReleaseRate4+ui8iChannel,	cpcui8program[0x1d]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0C1DecayLevel4ReleaseRate4+ui8iChannel,	cpcui8program[0x1e]);
						DEVICE_FM_stWrite(IDREGISTERW::Ch0C2DecayLevel4ReleaseRate4+ui8iChannel,	cpcui8program[0x1f]);
						ARG_ui8iProgram=cui8iprogram;
					}
					return;
				}
				_INLINE_ VOID			Progress(VOID)noexcept{
					{
						CAUTO					ci16doffset=i16dDetune+SOUND_stci16dToneAdjust;

						i16iTone=STD::stxFit(i16iTone+i16dPortamento,-ci16doffset,0x5fff-ci16doffset);
						if(i16iTone!=i16iTonePrevious){
							CAUTO					ci16itone=i16iTone+ci16doffset;
							CAUTO					cui16itone_real=UINT16((UINT16(stacui8iNote[ci16itone>>8])<<8)|UINT16(ci16itone&0xfc));

							DEVICE_FM_stWrite(IDREGISTERW::Ch0NoteFine6+ui8iChannel,		UINT8(cui16itone_real&0xff));
							DEVICE_FM_stWrite(IDREGISTERW::Ch0Note7+ui8iChannel,			UINT8(cui16itone_real>>8));
							i16iTonePrevious=i16iTone;
						}
					}
					if(eSetVolume){
						CAUTO					cui8nvolume=STD::stxGetMinimum(ui8nChannelVolume+ui8nMasterVolume,UINT8(127));

						DEVICE_FM_stWrite(IDREGISTERW::Ch0StereoLevelR7+ui8iChannel,	STD::stxGetMinimum(cui8nvolume+ui8nChannelVolumeR,127));
						DEVICE_FM_stWrite(IDREGISTERW::Ch0StereoLevelL7+ui8iChannel,	STD::stxGetMinimum(cui8nvolume+ui8nChannelVolumeL,127));
						eSetVolume=FALSE;
					}
					if(eKeyOn){
						DEVICE_FM_stWrite(IDREGISTERW::Key,stcui8cKeyDefault|(0xf<<3)|ui8iChannel);
						eKeyOn=FALSE;
					}
					return;
				}
			};

			//
			//		class:ST
			//

			//	ST
			class ST{
			public:
				CHANNEL					achnThis[stcui8nChannel];
			};

			//
			//		body:FM
			//

		private:
			static inline ST		st;
		public:
			static VOID				stNew(VOID)noexcept;
			static VOID				stDelete(VOID)noexcept;
			static _INLINE_ CHANNEL&	stchnDelegate(CUINT8 cui8ichannel)noexcept{
				return st.achnThis[cui8ichannel];
			}
			static VOID				stProgress(VOID)noexcept;
		};

		//	PCM
		class PCM{
		public:

			//
			//		const
			//

			using					IDREGISTERW=									PCM_IDREGISTERW;
			static constexpr AUTO	ROM_stcui32iBankAddress=						ROM_PCM_stcui32iBankAddressS;
			static constexpr AUTO	ROM_stcui32iImageAddress=						ROM_PCM_stcui32iImageAddressS;
			static constexpr AUTO	stcui8nChannel=									PCM_stcui8nChannel;
			//	<音声再生モード要件>
			//	「1001/60000(秒)」で「256(サンプル)」という事は「256*60000/1001=15,344.66(サンプル/秒)」。
			//	「Deceleration=6」指定時、つまり「2^6=64倍」遅くし、「YM2151B」基本ルールたる「4096サンプル/周期」で周波数を求めると。
			//
			//		15344.66*64/4096=239.76(Hz)
			//		440*(2^((12*OCT+NOTE(C#:0～C:11)-(12*4+8))/12))=239.76
			//		2^((12*OCT+NOTE(C#:0～C:11)-(12*4+8))/12)=239.76/440
			//		(12*OCT+NOTE(C#:0～C:11)-(12*4+8))/12=log2(239.76/440)=-0.8759
			//		12*OCT+NOTE(C#:0～C:11)-(12*4+8)=-0.8759*12=-10.5110
			//		12*OCT+NOTE(C#:0～C:11)=-10.5110+(12*4+8)=45.4890
			//		OCT=3 NOTE=9.4890
			//
			//	次に「1/60(秒)」で「256(サンプル)」、「256*60=15,360(サンプル/秒)」時。
			//
			//		15360*64/4096=240(Hz)
			//		440*(2^((12*OCT+NOTE(C#:0～C:11)-(12*4+8))/12))=240
			//		2^((12*OCT+NOTE(C#:0～C:11)-(12*4+8))/12)=240/440
			//		(12*OCT+NOTE(C#:0～C:11)-(12*4+8))/12=log2(240/440)=-0.8745
			//		12*OCT+NOTE(C#:0～C:11)-(12*4+8)=-0.8745*12=-10.4936
			//		12*OCT+NOTE(C#:0～C:11)=-10.4936+(12*4+8)=45.5064
			//		OCT=3 NOTE=9.5064
			static constexpr UINT8	VOICE_stcui8cKeyDefault=						0x00;
			static constexpr UINT16	VOICE_stcui16iTone=								0x3c58-1;
			static constexpr UINT16	VOICE_ui16nSourceBlock64Margin=					5;
			static constexpr UINT8	PCMM_VOICE_stcui8nBlockSize=					2;
			static constexpr UINT32	PCMM_VOICE_stcui32nSize=						UINT32(PCMM_VOICE_stcui8nBlockSize)<<8;

			//
			//		class
			//

			//	CHANNEL
			class CHANNEL;
			using					CCHANNEL=const CHANNEL;
			using					PCHANNEL=CHANNEL*;
			using					PCCHANNEL=CCHANNEL*;
			//	ST
			class ST;
			using					CST=const ST;
			using					PST=ST*;
			using					PCST=CST*;

			//
			//		class:CHANNEL
			//

			class CHANNEL{
			private:
				UINT8					ui8iChannel;
				UINT8					ui8nMasterVolume;
				UINT8					ui8nChannelVolume;
				UINT8					ui8nChannelVolumeL;
				UINT8					ui8nChannelVolumeR;
				union{
					struct{
						INT16					i16iTone;
						INT16					i16iTonePrevious;
						INT16					i16iToneAdjust;
						INT16					i16dPortamento;
						INT16					i16dDetune;
						UINT8					ui8cKey;
					}Normal;
					struct{
						PCUINT8					pcui8Source;
						UINT16					ui16nSourceBlock64;
						UINT16					ui16iBufferAddress;
						UINT16					ui16iBufferProgress;
					}Voice;
				};
				UINT8					ARG_ui8nMasterVolume;
				UINT8					ARG_ui8nChannelVolume;
				INT8					ARG_i8iPan;
				UINT8					ARG_ui8nPitchModulationDepth;
				UINT8					ARG_ui8iProgram;
				OFWBOOL					eVoiceMode:1;
				OFWBOOL					eSetVolume:1;
				OFWBOOL					eKeyOn:1;
			public:
				constexpr /*VOID*/		CHANNEL(VOID)noexcept:
					ui8iChannel(0),
					ui8nMasterVolume(0x00),
					ui8nChannelVolume(0x7f),
					ui8nChannelVolumeL(4),
					ui8nChannelVolumeR(4),
					Normal(
						0,						//	ui8cKey
						0,						//	i16iTone
						0,						//	i16iTonePrevious
						SOUND_stci16dToneAdjust,	//	i16iToneAdjust
						0						//	i16dPortamento
					),
					ARG_ui8nMasterVolume(255),
					ARG_ui8nChannelVolume(0),
					ARG_i8iPan(0),
					ARG_ui8nPitchModulationDepth(0),
					ARG_ui8iProgram(255),
					eVoiceMode(FALSE),
					eSetVolume(TRUE),
					eKeyOn(FALSE)
				{}
				constexpr VOID			SetChannel(CUINT8 cui8ichannel)noexcept{
					ui8iChannel=cui8ichannel;
					return;
				}
				_INLINE_ VOID			KeyOn(CUINT8 cui8inote)noexcept{
					Normal.i16iTone=(INT16(cui8inote)<<8);
					Normal.i16dPortamento=0;
					eKeyOn=TRUE;
					return;
				}
				_INLINE_ VOID			KeyOff(VOID)noexcept{
					DEVICE_PCM_stWrite(IDREGISTERW::Key,Normal.ui8cKey|(0x0<<3)|ui8iChannel);
					Normal.i16dPortamento=0;
					return;
				}
				_INLINE_ VOID			KeyOnChange(CUINT8 cui8inote)noexcept{
					Normal.i16iTone=(INT16(cui8inote)<<8);
					Normal.i16dPortamento=0;
					return;
				}
				_INLINE_ VOID			KeyOffChange(CUINT8 cui8inote)noexcept{
					DEVICE_PCM_stWrite(IDREGISTERW::Key,Normal.ui8cKey|(0x0<<3)|ui8iChannel);
					Normal.i16iTone=(INT16(cui8inote)<<8);
					Normal.i16dPortamento=0;
					return;
				}
				_INLINE_ VOID			SetMasterVolume(CUINT8 cui8nmastervolume)noexcept{
					if(cui8nmastervolume!=ARG_ui8nMasterVolume){
						ui8nMasterVolume=UINT8(127-(cui8nmastervolume>>1));
						eSetVolume=TRUE;
						ARG_ui8nMasterVolume=cui8nmastervolume;
					}
					return;
				}
				_INLINE_ VOID			SetChannelVolume(CUINT8 cui8nchannelvolume)noexcept{
					if(cui8nchannelvolume!=ARG_ui8nChannelVolume){
						ui8nChannelVolume=UINT8(127-(cui8nchannelvolume>>1));
						eSetVolume=TRUE;
						ARG_ui8nChannelVolume=cui8nchannelvolume;
					}
					return;
				}
				_INLINE_ VOID			SetPan(CINT8 ci8ipan)noexcept{
					if(ci8ipan!=ARG_i8iPan){
						CAUTO					cui8ipan=UINT8((ci8ipan>>1)+0x40);

						ui8nChannelVolumeL=stacui8nVolume[cui8ipan-1];
						ui8nChannelVolumeR=stacui8nVolume[127-cui8ipan];
						eSetVolume=TRUE;
						ARG_i8iPan=ci8ipan;
					}
					return;
				}
				_INLINE_ VOID			SetPortamento(CINT16 ci16dportamento)noexcept{
					Normal.i16dPortamento=ci16dportamento;
					return;
				}
				_INLINE_ VOID			SetDetune(CUINT16 ci16ddetune)noexcept{
					if(ci16ddetune!=Normal.i16dDetune){
						Normal.i16iTonePrevious=0;
						Normal.i16dDetune=ci16ddetune;
					}
					return;
				}
				_INLINE_ VOID			SetPitchModulationDepth(CUINT8 cui8npitchmodulationdepth)noexcept{
					if(cui8npitchmodulationdepth!=ARG_ui8nPitchModulationDepth){
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0PMS3AMS2+ui8iChannel,(cui8npitchmodulationdepth>>1)&0x70);
						ARG_ui8nPitchModulationDepth=cui8npitchmodulationdepth;
					}
					return;
				}
				_INLINE_ VOID			ProgramChange(CUINT8 cui8iprogram)noexcept{
					if(cui8iprogram!=ARG_ui8iProgram){
						CAUTO					cpcui8program=PCUINT8(ROM_stcui32iBankAddress+(UINT16(cui8iprogram)<<4));

						DEVICE_PCM_stWrite(IDREGISTERW::Ch0Interpolation2Deceleration4+ui8iChannel,	cpcui8program[0x00]);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0DetuneFine3Multiply4+ui8iChannel,		cpcui8program[0x01]);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0TotalLevel7+ui8iChannel,					cpcui8program[0x02]);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0KeyScale2AttackRate5+ui8iChannel,		cpcui8program[0x03]);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0Decay1Rate5+ui8iChannel,					cpcui8program[0x04]);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0DetuneRough2Decay2Rate5+ui8iChannel,		cpcui8program[0x05]);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0DecayLevel4ReleaseRate4+ui8iChannel,		cpcui8program[0x06]);
						Normal.ui8cKey=cpcui8program[0x07];
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0SampleStartFine8+ui8iChannel,			cpcui8program[0x09]);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0SampleStart8+ui8iChannel,				cpcui8program[0x08]);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0SampleLengthFine8+ui8iChannel,			cpcui8program[0x0b]);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0SampleLength8+ui8iChannel,				cpcui8program[0x0a]);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0SampleLoopLengthFine8+ui8iChannel,		cpcui8program[0x0d]);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0SampleLoopLength8+ui8iChannel,			cpcui8program[0x0c]);
						Normal.i16iToneAdjust=SOUND_stci16dToneAdjust+INT16((UINT16(cpcui8program[0x0e])<<8)|UINT16(cpcui8program[0x0f]));
						ARG_ui8iProgram=cui8iprogram;
					}
					return;
				}
				_INLINE_ VOID			PlayVoice(const PCUINT8 cpcui8source,CUINT16 cui16nsourceblock,CUINT8 cui8ibufferblockaddress)noexcept{
					//	「Progress_VoiceWrite64」のオーバーラン無音書き込みをアテに、
					//	「Voice.ui16nSourceBlock64」には波形データより大き目の値を設定しておき、
					//	しっかり最後まで再生できるようにしておく。
					Voice={
						cpcui8source,			//	pcui8Source
						UINT16((cui16nsourceblock<<2)+VOICE_ui16nSourceBlock64Margin),	//	ui16nSourceBlock64
						UINT16(UINT16(cui8ibufferblockaddress)<<8),	//	ui16iBufferAddress
						0						//	ui16iBufferProgress
					};
					//	とりあえず無音開始状態に
					DEVICE_PCM_stWrite(IDREGISTERW::Ch0TotalLevel7+ui8iChannel,					0x7f);
					if(!eVoiceMode){
						//	もし音声再生初回ならパラメータ初期化
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0Interpolation2Deceleration4+ui8iChannel,	0x16);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0NoteFine6+ui8iChannel,					UINT8(VOICE_stcui16iTone&0xff));
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0Note7+ui8iChannel,						UINT8(VOICE_stcui16iTone>>8));
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0PMS3AMS2+ui8iChannel,					0x8c);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0DetuneFine3Multiply4+ui8iChannel,		0x01);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0SampleLengthFine8+ui8iChannel,			0x00);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0SampleLength8+ui8iChannel,				PCMM_VOICE_stcui8nBlockSize);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0KeyScale2AttackRate5+ui8iChannel,		0x1f);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0SampleLoopLengthFine8+ui8iChannel,		0x00);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0SampleLoopLength8+ui8iChannel,			PCMM_VOICE_stcui8nBlockSize);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0Decay1Rate5+ui8iChannel,					0x00);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0DetuneRough2Decay2Rate5+ui8iChannel,		0x00);
						DEVICE_PCM_stWrite(IDREGISTERW::Ch0DecayLevel4ReleaseRate4+ui8iChannel,		0x0f);
						SetChannelVolume(255);
						SetPan(0);
						eVoiceMode=TRUE;
					}
					eKeyOn=TRUE;
					return;
				}
				_INLINE_ VOID			StopVoice(VOID)noexcept{
					if(eVoiceMode){
						DEVICE_PCM_stWrite(IDREGISTERW::Key,VOICE_stcui8cKeyDefault|(0x0<<3)|ui8iChannel);
						Normal.i16iTone=(((12*3+9)<<8)|0x7c)-SOUND_stci16dToneAdjust;
						Normal.i16iToneAdjust=SOUND_stci16dToneAdjust;
						Normal.i16dPortamento=0;
						Normal.i16dDetune=0;
						Normal.ui8cKey=VOICE_stcui8cKeyDefault;
						eVoiceMode=FALSE;
						eKeyOn=FALSE;
					}
					return;
				}
				_INLINE_ VOID			Progress(VOID)noexcept{
					if(eVoiceMode){
						if(Voice.ui16nSourceBlock64){
							if(eKeyOn){
								DEVICE_PCM_stWrite(IDREGISTERW::Ch0SampleStartFine8+ui8iChannel,			UINT8(Voice.ui16iBufferAddress&0xff));
								DEVICE_PCM_stWrite(IDREGISTERW::Ch0SampleStart8+ui8iChannel,				UINT8(Voice.ui16iBufferAddress>>8));
								Progress_VoiceWrite64();
								Progress_VoiceWrite64();
								Progress_VoiceWrite64();
								Progress_VoiceWrite64();
								DEVICE_PCM_stWrite(IDREGISTERW::Key,VOICE_stcui8cKeyDefault|(0x1<<3)|ui8iChannel);
								DEVICE_PCM_stWrite(IDREGISTERW::Ch0TotalLevel7+ui8iChannel,					0x00);
								eKeyOn=FALSE;
							}else{
								UINT16					ui16icurrent;

								//	誤差補正のため波形メモリに書き込みながら再生位置の取得を行う
								//	読み取りはFIFOバッファが利かないので間を空ける
								DEVICE_stSelectRead(IDREGISTERR::PCM_Ch0SampleCurrent8+ui8iChannel);
								Progress_VoiceWrite64();
								ui16icurrent=UINT16(DEVICE_stui8Read())<<8;
								DEVICE_stSelectRead(IDREGISTERR::PCM_Ch0SampleCurrentFine8+ui8iChannel);
								Progress_VoiceWrite64();
								ui16icurrent|=UINT16(DEVICE_stui8Read());
								Progress_VoiceWrite64();
								//	とりあえず192バイトまでは書き込んでおく。
								//	この後の再生マージンチェックにより書き込みサイズは192～320バイトで変動。
								//	これにより1フレーム当たりの書き込みサイズが256バイトの倍数でない場合が出るが、
								//	「Progress_VoiceWrite64」はオーバーランしても無音書き込みを行うので問題無い。
								//	多少フレームレートが暴れようが誤差は吸収できよう。
								if(
									CAUTO					cui16nmargin=(
										Voice.ui16iBufferProgress-(ui16icurrent-Voice.ui16iBufferAddress)
									)&0x1ff;
									cui16nmargin<256
								){
									//	普通にマージンが256バイト未満だったので通常通り256バイト書き込み
									Progress_VoiceWrite64();
									if(cui16nmargin<192){
										//	書き込み遅延的な事があったようなのでさらに64バイト書き込み
										Progress_VoiceWrite64();
									}
								}
							}
							if(eSetVolume){
								CAUTO					cui8nvolume=STD::stxGetMinimum(ui8nChannelVolume+ui8nMasterVolume,UINT8(127));

								DEVICE_PCM_stWrite(IDREGISTERW::Ch0StereoLevelR7+ui8iChannel,	STD::stxGetMinimum(cui8nvolume+ui8nChannelVolumeR,127));
								DEVICE_PCM_stWrite(IDREGISTERW::Ch0StereoLevelL7+ui8iChannel,	STD::stxGetMinimum(cui8nvolume+ui8nChannelVolumeL,127));
								eSetVolume=FALSE;
							}
						}else if(Voice.pcui8Source){
							//	ここまでで無音再生まで完了しているはずなのでキーオフを実施
							DEVICE_PCM_stWrite(IDREGISTERW::Key,VOICE_stcui8cKeyDefault|(0x0<<3)|ui8iChannel);
							Voice.pcui8Source=NULL;
						}
					}else{
						{
							CAUTO					ci16doffset=Normal.i16dDetune+Normal.i16iToneAdjust;

							Normal.i16iTone=STD::stxFit(Normal.i16iTone+Normal.i16dPortamento,-ci16doffset,0x5fff-ci16doffset);
							if(Normal.i16iTone!=Normal.i16iTonePrevious){
								CAUTO					ci16itone=Normal.i16iTone+ci16doffset;
								CAUTO					cui16itone_real=UINT16((UINT16(stacui8iNote[ci16itone>>8])<<8)|UINT16(ci16itone&0xfc));

								DEVICE_PCM_stWrite(IDREGISTERW::Ch0NoteFine6+ui8iChannel,		UINT8(cui16itone_real&0xff));
								DEVICE_PCM_stWrite(IDREGISTERW::Ch0Note7+ui8iChannel,			UINT8(cui16itone_real>>8));
								Normal.i16iTonePrevious=Normal.i16iTone;
							}
						}
						if(eSetVolume){
							CAUTO					cui8nvolume=STD::stxGetMinimum(ui8nChannelVolume+ui8nMasterVolume,UINT8(127));

							DEVICE_PCM_stWrite(IDREGISTERW::Ch0StereoLevelR7+ui8iChannel,	STD::stxGetMinimum(cui8nvolume+ui8nChannelVolumeR,127));
							DEVICE_PCM_stWrite(IDREGISTERW::Ch0StereoLevelL7+ui8iChannel,	STD::stxGetMinimum(cui8nvolume+ui8nChannelVolumeL,127));
							eSetVolume=FALSE;
						}
						if(eKeyOn){
							DEVICE_PCM_stWrite(IDREGISTERW::Key,Normal.ui8cKey|(0x1<<3)|ui8iChannel);
							eKeyOn=FALSE;
						}
					}
					return;
				}
			private:
				VOID					Progress_VoiceWrite64(VOID)noexcept;
			};

			//
			//		class:ST
			//

			//	ST
			class ST{
			public:
				CHANNEL					achnThis[stcui8nChannel];
			};

			//
			//		body:PCM
			//

		private:
			static inline ST		st;
		public:
			static VOID				stNew(VOID)noexcept;
			static VOID				stDelete(VOID)noexcept;
			static _INLINE_ CHANNEL&	stchnDelegate(CUINT8 cui8ichannel)noexcept{
				return st.achnThis[cui8ichannel];
			}
			static VOID				stProgress(VOID)noexcept;
			static VOID				PCMM_stWrite(CUINT16 cui16idestination,const PCVOID cpsource,CUINT16 cui16nsource)noexcept;
		};

		//
		//		class:ST
		//

		//	ST
		class ST{
		public:
		};

		//
		//		body:SOUND
		//

	private:
		static inline ST		st;
		UINT16					ui16cChannelMask;
		UINT8					ui8iVoiceChannel;
		PCUINT8					ROM_pcui8Cursor;
		UINT32					ui32nWait;
		PCUINT8					apcui8Stack[stcui8nStack];
		PCUINT8*				ppcui8Stack;
	public:
		static VOID				stNew(VOID)noexcept;
		static VOID				stDelete(VOID)noexcept;
		static _INLINE_ VOID	stProgress(VOID)noexcept{
			FM::stProgress();
			PCM::stProgress();
			return;
		}
		VOID					New(CUINT16 cui16cchannelmask)noexcept;
		VOID					Delete(VOID)noexcept;
		VOID					Play(const PCUINT8 cpcui8source)noexcept;
		_INLINE_ VOID			PlayDynamic(const PCUINT8 cpcui8source)noexcept{
			if((ROM_pcui8Cursor==NULL)||(cpcui8source<ROM_pcui8Cursor))Play(cpcui8source);
			return;
		}
		VOID					SetMasterVolume(CUINT8 cui8nvolume)noexcept;
		VOID					PlayVoice(const PCUINT8 cpcui8source,CUINT16 cui16nsourceblock,CUINT8 cui8ibufferblockaddress=0xfe)noexcept;
		VOID					Progress(VOID)noexcept;
	private:
		static _INLINE_ VOID	stSetPitchModulationSpeed(CUINT8 cui8npitchmodulationspeed)noexcept{
			DEVICE_FM_stWrite(DEVICE::FM_IDREGISTERW::LFOFrequency,cui8npitchmodulationspeed);
			return;
		}
		_INLINE_ UINT16			ROM_ui16Read(VOID)noexcept{
			CAUTO					cui8h=ROM_ui8Read();
			CAUTO					cui8l=ROM_ui8Read();
			return UINT16((UINT16(cui8h)<<8)|UINT16(cui8l));
		}
		_INLINE_ UINT8			ROM_ui8Read(VOID)noexcept{
			CAUTO					cui8return=*ROM_pcui8Cursor;

			++ROM_pcui8Cursor;
			return cui8return;
		}
		UINT32					ROM_ui32ReadVU(VOID)noexcept;
		UINT32					ROM_ui32dGetCursorOffset(CUINT8 cui8cflowtype)noexcept;
		static _INLINE_ VOID	DEVICE_FM_stWrite(const FM_IDREGISTERW cidregister,CUINT8 cui8value)noexcept{
			DEVICE_stui8Delegate(DEVICE_SOUND_FM_stcui16dSelectWOffset)=UINT8(cidregister);
			DEVICE_stui8Delegate(DEVICE_SOUND_stcui16dDataOffset)=cui8value;
			return;
		}
		static _INLINE_ VOID	DEVICE_PCM_stWrite(const PCM_IDREGISTERW cidregister,CUINT8 cui8value)noexcept{
			DEVICE_stui8Delegate(DEVICE_SOUND_PCM_stcui16dSelectWOffset)=UINT8(cidregister);
			DEVICE_stui8Delegate(DEVICE_SOUND_stcui16dDataOffset)=cui8value;
			return;
		}
		static _INLINE_ VOID	DEVICE_stSelectRead(const IDREGISTERR cidregister)noexcept{
			DEVICE_stui8Delegate(DEVICE_SOUND_stcui16dSelectROffset)=UINT8(cidregister);
			return;
		}
		static _INLINE_ UINT8	DEVICE_stui8Read(VOID)noexcept{
			return DEVICE_stcui8GetThis(DEVICE_stcui16dDataOffset);
		}
		static _INLINE_ _UNDISCARDABLE_ UINT8&	DEVICE_stui8Delegate(CUINT16 cui16iaddress)noexcept{
			return MEMORYS::DEVICE_stui8DelegateThis(DEVICE_SOUND_stcui16dOffsetS+cui16iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_ CUINT8&	DEVICE_stcui8GetThis(CUINT16 cui16iaddress)noexcept{
			return MEMORYS::DEVICE_stcui8GetThis(DEVICE_SOUND_stcui16dOffsetS+cui16iaddress);
		}
	};
}

#endif
