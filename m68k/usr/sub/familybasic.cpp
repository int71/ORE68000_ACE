/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/familybasic.cpp'							2026 written by int71	**
 ****************************************************************************/

//
//		include
//

#include				"../common/map.hpp"
#include				"familybasic.hpp"

//
//		using
//

using namespace m68k::i71::sub;

//
//		class:FAMILYBASIC::ST
//

//	public

VOID					FAMILYBASIC::ST::Delete(VOID)noexcept{
	return;
}

//
//		class:FAMILYBASIC
//

//	public

VOID					FAMILYBASIC::stNew(
	const IDRESOLUTION		cidresolution,
	CVECTOR2& 				cv2nresolutionoverride,
	COFWBOOL				ceshow
)noexcept{
	stNew_SetResolution(cidresolution,cv2nresolutionoverride);
	stNew_SetPattern(PATTERN::IDPATTERN::SPRITE_SYSTEM,PATTERN::IDPATTERN::BG_SYSTEM);
	stNew_Common(cidresolution,ceshow);
	return;
}

VOID					FAMILYBASIC::stDelete(VOID)noexcept{
	st.Delete();
	return;
}

VOID					FAMILYBASIC::stShow(
	COFWBOOL				ceshow
)noexcept{
	using					IDREGISTERW=VIDEO_DRIVER::IDREGISTERW;
	using					IDLAYER=VIDEO_DRIVER::IDLAYER;

	if(ceshow){
		VIDEO_DRIVER::stWrite(
			IDREGISTERW::Composite1,
			(/*表示面7(最前)*/	IDLAYER::Text<<0xc)|
			(/*表示面6*/		IDLAYER::BG0<<0x8)|
			(/*表示面5*/		IDLAYER::SpritePriority0<<0x4)|
			(/*表示面4*/		IDLAYER::BG1<<0x0)
		);
		VIDEO_DRIVER::stWrite(
			IDREGISTERW::Composite0,
			(/*表示面3*/		IDLAYER::SpritePriority1<<0xc)|
			(/*表示面2*/		IDLAYER::BG2<<0x8)|
			(/*表示面1*/		IDLAYER::SpritePriority2<<0x4)|
			(/*表示面0(最奥)*/	IDLAYER::BG3<<0x0)
		);
	}else{
		VIDEO_DRIVER::stWrite(
			IDREGISTERW::Composite1,
			(/*表示面7(最前)*/	IDLAYER::None<<0xc)|
			(/*表示面6*/		IDLAYER::None<<0x8)|
			(/*表示面5*/		IDLAYER::None<<0x4)|
			(/*表示面4*/		IDLAYER::None<<0x0)
		);
		VIDEO_DRIVER::stWrite(
			IDREGISTERW::Composite0,
			(/*表示面3*/		IDLAYER::None<<0xc)|
			(/*表示面2*/		IDLAYER::None<<0x8)|
			(/*表示面1*/		IDLAYER::None<<0x4)|
			(/*表示面0(最奥)*/	IDLAYER::None<<0x0)
		);
	}
	return;
}

VOID					FAMILYBASIC::PALETTE_stWrite(
	CUINT8					cui8ipalette,
	CUINT8					cui8inescolor0,
	CUINT8					cui8inescolor1,
	CUINT8					cui8inescolor2
)noexcept{
	CUINT16					acui16ccolor[]={
		PALETTE_stacui16cColor[cui8inescolor0],
		PALETTE_stacui16cColor[cui8inescolor1],
		PALETTE_stacui16cColor[cui8inescolor2]
	};

	VIDEO_DRIVER::PALETTE_stWrite((cui8ipalette<<4)+1,acui16ccolor,3);
	return;
}

VOID					FAMILYBASIC::PALETTE_stWriteBack(
	CUINT8					cui8inescolor
)noexcept{
	CAUTO					cui16ccolor=PALETTE_stacui16cColor[cui8inescolor];

	VIDEO_DRIVER::PALETTE_stWrite(0,&cui16ccolor,1);
	return;
}

VOID					FAMILYBASIC::PALETTE_stWriteSet(
	CUINT8					cui8isetsprite,
	CUINT8					cui8isetbg
)noexcept{
	CAUTO&					acsetsprite=PALETTE_staacSetSprite[(cui8isetsprite<3)?cui8isetsprite:0];
	CAUTO&					acsetbg=PALETTE_staacSetBG[(cui8isetbg<2)?cui8isetbg:0];

	for(UINT8 ui8ipalette=0;ui8ipalette<4;++ui8ipalette){
		PALETTE_stWrite(PALETTE_stui8iBase_Sprite+	ui8ipalette,acsetsprite[ui8ipalette]);
		PALETTE_stWrite(PALETTE_stui8iBase_BG+		ui8ipalette,acsetbg[ui8ipalette]);
	}
	return;
}

VOID					FAMILYBASIC::PALETTE_stWriteSet2(
	CUINT8					cui8isetsprite0,
	CUINT8					cui8isetsprite1,
	CUINT8					cui8isetbg0,
	CUINT8					cui8isetbg1
)noexcept{
	CAUTO&					acsetsprite0=PALETTE_staacSetSprite[(cui8isetsprite0<3)?cui8isetsprite0:0];
	CAUTO&					acsetsprite1=PALETTE_staacSetSprite[(cui8isetsprite1<3)?cui8isetsprite1:0];
	CAUTO&					acsetbg0=PALETTE_staacSetBG[(cui8isetbg0<2)?cui8isetbg0:0];
	CAUTO&					acsetbg1=PALETTE_staacSetBG[(cui8isetbg1<2)?cui8isetbg1:0];

	for(UINT8 ui8ipalette=0;ui8ipalette<4;++ui8ipalette){
		PALETTE_stWrite(PALETTE_stui8iBase_Sprite+	ui8ipalette+0,acsetsprite0[ui8ipalette]);
		PALETTE_stWrite(PALETTE_stui8iBase_Sprite+	ui8ipalette+4,acsetsprite1[ui8ipalette]);
		PALETTE_stWrite(PALETTE_stui8iBase_BG+		ui8ipalette+0,acsetbg0[ui8ipalette]);
		PALETTE_stWrite(PALETTE_stui8iBase_BG+		ui8ipalette+4,acsetbg1[ui8ipalette]);
	}
	return;
}

VOID					FAMILYBASIC::SPRITE_stSetOffset(
	CVECTOR2&				cv2doffset
)noexcept{
	st.SPRITE_ui16dOffsetX=UINT16(cv2doffset.i16iX())&0x3ff;
	st.SPRITE_ui16dOffsetY=UINT16(cv2doffset.i16iY())&0x3ff;
	SPRITE_stApplyOffset();
	return;
}

VOID					FAMILYBASIC::SPRITE_stSetSize(
	const IDSIZE			cidsizex,
	const IDSIZE			cidsizey
)noexcept{
	CAUTO					cui8ix=UINT8(cidsizex),cui8iy=UINT8(cidsizey);

	st.SPRITE_ui16cCirculationX=stacui16cCirculation[cui8ix];
	st.SPRITE_ui16cCirculationY=stacui16cCirculation[cui8iy];
	st.SPRITE_v2nSize={staci16nSize[cui8ix],staci16nSize[cui8iy]};
	st.SPRITE_v2cMask=st.SPRITE_v2nSize-VECTOR2(1,1);
	SPRITE_stApplyOffset();
	return;
}

VOID					FAMILYBASIC::BG0_stSetOffset(
	CVECTOR2&				cv2doffset
)noexcept{
	st.BG0_ui16dOffsetX=UINT16(cv2doffset.i16iX())&0x3ff;
	st.BG0_ui16dOffsetY=UINT16(cv2doffset.i16iY())&0x3ff;
	BG0_stApplyOffset();
	return;
}

VOID					FAMILYBASIC::BG0_stSetSize(
	const IDSIZE			cidsizex,
	const IDSIZE			cidsizey
)noexcept{
	CAUTO					cui8ix=UINT8(cidsizex),cui8iy=UINT8(cidsizey);

	st.BG0_ui16cCirculationX=stacui16cCirculation[cui8ix];
	st.BG0_ui16cCirculationY=stacui16cCirculation[cui8iy];
	st.BG0_v2nSize={staci16nSize[cui8ix],staci16nSize[cui8iy]};
	st.BG0_v2cMask=st.BG0_v2nSize-VECTOR2(1,1);
	st.BG0_v2nSize8=st.BG0_v2nSize>>3;
	st.BG0_v2cMask8=st.BG0_v2nSize8-VECTOR2(1,1);
	BG0_stApplyOffset();
	return;
}

VOID					FAMILYBASIC::BG1_stSetOffset(
	CVECTOR2&				cv2iposition
)noexcept{
	st.BG1_ui16dOffsetX=UINT16(cv2iposition.i16iX())&0x3ff;
	st.BG1_ui16dOffsetY=UINT16(cv2iposition.i16iY())&0x3ff;
	BG1_stApplyOffset();
	return;
}

VOID					FAMILYBASIC::BG1_stSetSize(
	const IDSIZE			cidsizex,
	const IDSIZE			cidsizey
)noexcept{
	CAUTO					cui8ix=UINT8(cidsizex),cui8iy=UINT8(cidsizey);

	st.BG1_ui16cCirculationX=stacui16cCirculation[cui8ix];
	st.BG1_ui16cCirculationY=stacui16cCirculation[cui8iy];
	st.BG1_v2nSize={staci16nSize[cui8ix],staci16nSize[cui8iy]};
	st.BG1_v2cMask=st.BG1_v2nSize-VECTOR2(1,1);
	st.BG1_v2nSize8=st.BG1_v2nSize>>3;
	st.BG1_v2cMask8=st.BG1_v2nSize8-VECTOR2(1,1);
	BG1_stApplyOffset();
	return;
}

VOID					FAMILYBASIC::BG2_stSetOffset(
	CVECTOR2&				cv2iposition
)noexcept{
	st.BG2_ui16dOffsetX=UINT16(cv2iposition.i16iX())&0x3ff;
	st.BG2_ui16dOffsetY=UINT16(cv2iposition.i16iY())&0x3ff;
	BG2_stApplyOffset();
	return;
}

VOID					FAMILYBASIC::BG2_stSetSize(
	const IDSIZE			cidsizex,
	const IDSIZE			cidsizey
)noexcept{
	CAUTO					cui8ix=UINT8(cidsizex),cui8iy=UINT8(cidsizey);

	st.BG2_ui16cCirculationX=stacui16cCirculation[cui8ix];
	st.BG2_ui16cCirculationY=stacui16cCirculation[cui8iy];
	st.BG2_v2nSize={staci16nSize[cui8ix],staci16nSize[cui8iy]};
	st.BG2_v2cMask=st.BG2_v2nSize-VECTOR2(1,1);
	st.BG2_v2nSize8=st.BG2_v2nSize>>3;
	st.BG2_v2cMask8=st.BG2_v2nSize8-VECTOR2(1,1);
	BG2_stApplyOffset();
	return;
}

VOID					FAMILYBASIC::BG3_stSetOffset(
	CVECTOR2&				cv2iposition
)noexcept{
	st.BG3_ui16dOffsetX=UINT16(cv2iposition.i16iX())&0x3ff;
	st.BG3_ui16dOffsetY=UINT16(cv2iposition.i16iY())&0x3ff;
	BG3_stApplyOffset();
	return;
}

VOID					FAMILYBASIC::BG3_stSetSize(
	const IDSIZE			cidsizex,
	const IDSIZE			cidsizey
)noexcept{
	CAUTO					cui8ix=UINT8(cidsizex),cui8iy=UINT8(cidsizey);

	st.BG3_ui16cCirculationX=stacui16cCirculation[cui8ix];
	st.BG3_ui16cCirculationY=stacui16cCirculation[cui8iy];
	st.BG3_v2nSize={staci16nSize[cui8ix],staci16nSize[cui8iy]};
	st.BG3_v2cMask=st.BG3_v2nSize-VECTOR2(1,1);
	st.BG3_v2nSize8=st.BG3_v2nSize>>3;
	st.BG3_v2cMask8=st.BG3_v2nSize8-VECTOR2(1,1);
	BG3_stApplyOffset();
	return;
}

//	protected

VOID					FAMILYBASIC::stNew_SetResolution(
	const IDRESOLUTION		cidresolution,
	CVECTOR2&				cv2nresolutionoverride
)noexcept{
	stShow(FALSE);
	switch(cidresolution){
	case IDRESOLUTION::n256x212:
		if(cv2nresolutionoverride==VECTOR2::stv2ImmediateZero())VIDEO_DRIVER::stSetCRT256x212P();
		else VIDEO_DRIVER::stSetCRT256x212P(
			256-cv2nresolutionoverride.i16nWidth(),
			212-cv2nresolutionoverride.i16nHeight()
		);
		break;
	case IDRESOLUTION::n320x240:
		if(cv2nresolutionoverride==VECTOR2::stv2ImmediateZero())VIDEO_DRIVER::stSetCRT320x240P();
		else VIDEO_DRIVER::stSetCRT320x240P(
			320-cv2nresolutionoverride.i16nWidth(),
			240-cv2nresolutionoverride.i16nHeight()
		);
		break;
	case IDRESOLUTION::n640x480:
		if(cv2nresolutionoverride==VECTOR2::stv2ImmediateZero())VIDEO_DRIVER::stSetCRT640x480P();
		else VIDEO_DRIVER::stSetCRT640x480P(
			640-cv2nresolutionoverride.i16nWidth(),
			480-cv2nresolutionoverride.i16nHeight()
		);
		break;
	}
	return;
}

VOID					FAMILYBASIC::stNew_SetPattern(
	const PATTERN::IDPATTERN	cidpatternsprite,
	const PATTERN::IDPATTERN	cidpatternbg
)noexcept{
	PATTERN::stWrite(MAP::VRAM::PATTERNCHR_SPRITE_stcui16iAddress,cidpatternsprite);
	PATTERN::stWrite(MAP::VRAM::PATTERNCHR_BG0_stcui16iAddress,cidpatternbg);
	PATTERN::stWrite(MAP::VRAM::PATTERNCHR_BG1_stcui16iAddress,cidpatternbg);
	PATTERN::stWrite(MAP::VRAM::PATTERNCHR_BG2_stcui16iAddress,cidpatternbg);
	PATTERN::stWrite(MAP::VRAM::PATTERNCHR_BG3_stcui16iAddress,cidpatternbg);
	BG0_stFillAttribute({0,0},{128,128},0x8020);
	BG1_stFillAttribute({0,0},{128,128},0x8020);
	BG2_stFillAttribute({0,0},{128,128},0x8020);
	BG3_stFillAttribute({0,0},{128,128},0x8020);
	PALETTE_stWriteBack(0x3f);
	PALETTE_stWriteSet(0,1);
	return;
}

VOID					FAMILYBASIC::stNew_Common(
	const IDRESOLUTION		cidresolution,
	COFWBOOL				ceshow
)noexcept{
	st.SPRITE_ui16dOffsetX=0;
	st.SPRITE_ui16dOffsetY=0;
	{
		CAUTO					cidsize=(cidresolution==IDRESOLUTION::n256x212)?(
			IDSIZE::n256
		):(
			(cidresolution==IDRESOLUTION::n320x240)?(
				IDSIZE::n512
			):(
				IDSIZE::n1024
			)
		);

		SPRITE_stSetSize(cidsize);
		st.BG0_ui16dOffsetX=0;
		st.BG0_ui16dOffsetY=0;
		BG0_stSetSize(cidsize);
		st.BG1_ui16dOffsetX=0;
		st.BG1_ui16dOffsetY=0;
		BG1_stSetSize(cidsize);
		st.BG2_ui16dOffsetX=0;
		st.BG2_ui16dOffsetY=0;
		BG2_stSetSize(cidsize);
		st.BG3_ui16dOffsetX=0;
		st.BG3_ui16dOffsetY=0;
		BG3_stSetSize(cidsize);
	}
	OS::BGM_stSetMask(
		SOUND_DRIVER::stcui16cChannelMaskPCM0|
		SOUND_DRIVER::stcui16cChannelMaskPCM1|
		SOUND_DRIVER::stcui16cChannelMaskPCM2
	);
	OS::SE0_stSetMask(
		SOUND_DRIVER::stcui16cChannelMaskPCM3
	);
	OS::SE1_stSetMask(
		SOUND_DRIVER::stcui16cChannelMaskPCM4|
		SOUND_DRIVER::stcui16cChannelMaskFM7
	);
	if(ceshow)stShow(TRUE);
	return;
}

VOID					FAMILYBASIC::SPRITE_stApplyOffset(VOID)noexcept{
	using					IDREGISTERW=VIDEO_DRIVER::IDREGISTERW;

	VIDEO_DRIVER::stWrite(IDREGISTERW::SpriteOffsetX,st.SPRITE_ui16dOffsetX|st.SPRITE_ui16cCirculationX);
	VIDEO_DRIVER::stWrite(IDREGISTERW::SpriteOffsetY,st.SPRITE_ui16dOffsetY|st.SPRITE_ui16cCirculationY);
	return;
}

VOID					FAMILYBASIC::BG0_stApplyOffset(VOID)noexcept{
	using					IDREGISTERW=VIDEO_DRIVER::IDREGISTERW;

	VIDEO_DRIVER::stWrite(IDREGISTERW::BG0OffsetX,st.BG0_ui16dOffsetX|st.BG0_ui16cCirculationX);
	VIDEO_DRIVER::stWrite(IDREGISTERW::BG0OffsetY,st.BG0_ui16dOffsetY|st.BG0_ui16cCirculationY);
	return;
}

VOID					FAMILYBASIC::BG1_stApplyOffset(VOID)noexcept{
	using					IDREGISTERW=VIDEO_DRIVER::IDREGISTERW;

	VIDEO_DRIVER::stWrite(IDREGISTERW::BG1OffsetX,st.BG1_ui16dOffsetX|st.BG1_ui16cCirculationX);
	VIDEO_DRIVER::stWrite(IDREGISTERW::BG1OffsetY,st.BG1_ui16dOffsetY|st.BG1_ui16cCirculationY);
	return;
}

VOID					FAMILYBASIC::BG2_stApplyOffset(VOID)noexcept{
	using					IDREGISTERW=VIDEO_DRIVER::IDREGISTERW;

	VIDEO_DRIVER::stWrite(IDREGISTERW::BG2OffsetX,st.BG2_ui16dOffsetX|st.BG2_ui16cCirculationX);
	VIDEO_DRIVER::stWrite(IDREGISTERW::BG2OffsetY,st.BG2_ui16dOffsetY|st.BG2_ui16cCirculationY);
	return;
}

VOID					FAMILYBASIC::BG3_stApplyOffset(VOID)noexcept{
	using					IDREGISTERW=VIDEO_DRIVER::IDREGISTERW;

	VIDEO_DRIVER::stWrite(IDREGISTERW::BG3OffsetX,st.BG3_ui16dOffsetX|st.BG3_ui16cCirculationX);
	VIDEO_DRIVER::stWrite(IDREGISTERW::BG3OffsetY,st.BG3_ui16dOffsetY|st.BG3_ui16cCirculationY);
	return;
}

VOID					FAMILYBASIC::BG_stFillAttribute(
	CUINT32					cui32doffset,
	CVECTOR2&				cv2iposition,
	CVECTOR2&				cv2nsize,
	CUINT16					cui16cattribute
)noexcept{
	AUTO					pui16cdestination=(
		&MEMORY::VRAM_stui16DelegateThis(cui32doffset)+
		(cv2iposition.i16iY()<<7)+
		cv2iposition.i16iX()
	);
	AUTO					pui16cdestination_line_end=pui16cdestination+cv2nsize.i16nWidth();

	for(
		CAUTO					cpui16cdestination_end=pui16cdestination+(cv2nsize.i16nHeight()<<7);
		pui16cdestination<cpui16cdestination_end;
		pui16cdestination+=128,pui16cdestination_line_end+=128
	)for(
		AUTO					pui16cdestination_line=pui16cdestination;
		pui16cdestination_line<pui16cdestination_line_end;
		++pui16cdestination_line
	)*pui16cdestination_line=cui16cattribute;
	return;
}

VOID					FAMILYBASIC::BG_stPrint(
	CUINT32					cui32doffset,
	CVECTOR2&				cv2iposition,
	const PCUSTR			cpcustrstring,
	CUINT8					cui8ibgpalette
)noexcept{
	CAUTO					cui16cbase=UINT16(UINT16(cui8ibgpalette+8)<<12);
	AUTO					pui16cdestination_base=(
		&MEMORY::VRAM_stui16DelegateThis(cui32doffset)+
		(cv2iposition.i16iY()<<7)+
		cv2iposition.i16iX()
	);
	AUTO					pui16cdestination=pui16cdestination_base;

	for(AUTO pcustrsource=cpcustrstring;*pcustrsource;++pcustrsource){
		if(*pcustrsource!='\n'){
			*pui16cdestination=cui16cbase|UINT16(UINT8(*pcustrsource));
			++pui16cdestination;
		}else{
			pui16cdestination_base+=128;
			pui16cdestination=pui16cdestination_base;
		}
	}
	return;
}

VOID					FAMILYBASIC::BG_stPrint_R_Body(
	CUINT32					cui32doffset,
	CVECTOR2&				cv2iposition,
	const PCUSTR			cpcustrstring,
	CUINT8					cui8ibgpalette,
	CVECTOR2&				cv2ntrim
)noexcept{
	CAUTO					cui16cbase=UINT16(UINT16(cui8ibgpalette+8)<<12);
	CAUTO					cui16cmask=UINT16((cv2ntrim.i16nHeight()<<8)-1);
	AUTO					ui16idestination_base=UINT16((cv2iposition.i16iY()<<8)+(cv2iposition.i16iX()<<1));
	CAUTO					cpui8cdestination_base=PUINT8(&MEMORY::VRAM_stui16DelegateThis(cui32doffset));
	AUTO					ui16idestination=ui16idestination_base;

	for(AUTO pcustrsource=cpcustrstring;*pcustrsource;++pcustrsource){
		if(*pcustrsource!='\n'){
			*PUINT16(cpui8cdestination_base+ui16idestination)=cui16cbase|UINT16(UINT8(*pcustrsource));
			ui16idestination=(ui16idestination-256)&cui16cmask;
		}else{
			--ui16idestination_base;
			ui16idestination=ui16idestination_base;
		}
	}
	return;
}

VOID					FAMILYBASIC::BG_stCopyRect_Body(
	CUINT32					cui32doffset,
	const PCUINT16			cpcui16csource,
	CUINT16					cui16nsourcepitch,
	CVECTOR2&				cv2nsource
)noexcept{
	CAUTO					cui16ddestinationoffsetend=UINT16(cv2nsource.i16nHeight()<<8);
	CAUTO					cui16ndestinationh=UINT16(cv2nsource.i16nWidth()<<1);
	constexpr AUTO			cui16ndestinationpitch=UINT16(256);
	CAUTO					cui16ndestinationnext=UINT16(cui16ndestinationpitch-cui16ndestinationh);
	CAUTO					cui16nsourcenext=UINT16(cui16nsourcepitch-cui16ndestinationh);
	AUTO					pui8cdestination=PUINT8(&MEMORY::VRAM_stui16DelegateThis(cui32doffset));
	AUTO					pcui8csource=PCUINT8(cpcui16csource);

	for(
		CAUTO					cpui8cdestination_end=pui8cdestination+cui16ddestinationoffsetend;
		pui8cdestination<cpui8cdestination_end;
		pui8cdestination+=cui16ndestinationnext,pcui8csource+=cui16nsourcenext
	){
		for(
			CAUTO					cpui8cdestinationhline_end=pui8cdestination+cui16ndestinationh;
			pui8cdestination<cpui8cdestinationhline_end;
			pui8cdestination+=SIZEOF(UINT16),pcui8csource+=SIZEOF(UINT16)
		)*PUINT16(pui8cdestination)=*PCUINT16(pcui8csource);
	}
	return;
}

VOID					FAMILYBASIC::BG_stCopyRect_R_Body(
	CUINT32					cui32doffset,
	const PCUINT16			cpcui16csource,
	CUINT16					cui16nsourcepitch,
	CVECTOR2&				cv2nsource
)noexcept{
	CAUTO					cui16ddestinationoffsetend=UINT16(cv2nsource.i16nHeight()<<1);
	CAUTO					cui16ndestinationh=UINT16(cv2nsource.i16nWidth()<<1);
	CAUTO					cui16ndestinationv=UINT16(cv2nsource.i16nWidth()<<8);
	constexpr AUTO			cui16ndestinationpitch=UINT16(256);
	CAUTO					cui16ndestinationnext=UINT16(SIZEOF(UINT16)+cui16ndestinationv);
	CAUTO					cui16nsourcenext=UINT16(cui16nsourcepitch-cui16ndestinationh);
	AUTO					pui8cdestination=PUINT8(&MEMORY::VRAM_stui16DelegateThis(cui32doffset));
	AUTO					pcui8csource=PCUINT8(cpcui16csource);

	for(
		CAUTO					cpui8cdestination_end=pui8cdestination+cui16ddestinationoffsetend;
		pui8cdestination<cpui8cdestination_end;
		pui8cdestination+=cui16ndestinationnext,pcui8csource+=cui16nsourcenext
	){
		for(
			CAUTO					cpui8cdestinationvline_end=pui8cdestination-cui16ndestinationv;
			cpui8cdestinationvline_end<pui8cdestination;
			pui8cdestination-=cui16ndestinationpitch,pcui8csource+=SIZEOF(UINT16)
		)*PUINT16(pui8cdestination)=*PCUINT16(pcui8csource);
	}
	return;
}
