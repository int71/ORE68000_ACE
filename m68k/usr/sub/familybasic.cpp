/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/familybasic.cpp'							2025 written by int71	**
 ****************************************************************************/

//
//		include
//

#include				"../common/map.hpp"
#include				"pattern.hpp"
#include				"familybasic.hpp"

//
//		using
//

using namespace m68k::i71::sub;

//
//		class:FAMILYBASIC
//

//	public

VOID					FAMILYBASIC::stNew(
	COFWBOOL				ceshow
)noexcept{
	VIDEO_DRIVER::stSetCRT256x212P();
	stShow(ceshow);
	PATTERN::stWrite(MAP::VRAM::PATTERNCHR_SPRITE_stcui16iAddress,PATTERN::IDPATTERN::SPRITE_SYSTEM);
	PATTERN::stWrite(MAP::VRAM::PATTERNCHR_BG0_stcui16iAddress,PATTERN::IDPATTERN::BG_SYSTEM);
	PATTERN::stWrite(MAP::VRAM::PATTERNCHR_BG1_stcui16iAddress,PATTERN::IDPATTERN::BG_SYSTEM);
	PATTERN::stWrite(MAP::VRAM::PATTERNCHR_BG2_stcui16iAddress,PATTERN::IDPATTERN::BG_SYSTEM);
	PATTERN::stWrite(MAP::VRAM::PATTERNCHR_BG3_stcui16iAddress,PATTERN::IDPATTERN::BG_SYSTEM);
	st.SPRITE_ui16dOffsetX=0;
	st.SPRITE_ui16dOffsetY=0;
	SPRITE_stSetSize(IDSIZE::n256);
	st.BG0_ui16dOffsetX=0;
	st.BG0_ui16dOffsetY=0;
	BG0_stSetSize(IDSIZE::n256);
	st.BG1_ui16dOffsetX=0;
	st.BG1_ui16dOffsetY=0;
	BG1_stSetSize(IDSIZE::n256);
	st.BG2_ui16dOffsetX=0;
	st.BG2_ui16dOffsetY=0;
	BG2_stSetSize(IDSIZE::n256);
	st.BG3_ui16dOffsetX=0;
	st.BG3_ui16dOffsetY=0;
	BG3_stSetSize(IDSIZE::n256);
	BG0_stFillAttribute({0,0},{128,128},0x8020);
	BG1_stFillAttribute({0,0},{128,128},0x8020);
	BG2_stFillAttribute({0,0},{128,128},0x8020);
	BG3_stFillAttribute({0,0},{128,128},0x8020);
	PALETTE_stWriteBack(0x3f);
	PALETTE_stWriteSet(0,1);
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
	return;
}

VOID					FAMILYBASIC::stDelete(VOID)noexcept{
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
		PALETTE_stWrite(ui8ipalette+ 0,acsetsprite[ui8ipalette]);
		PALETTE_stWrite(ui8ipalette+ 8,acsetbg[ui8ipalette]);
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
		PALETTE_stWrite(ui8ipalette+ 0,acsetsprite0[ui8ipalette]);
		PALETTE_stWrite(ui8ipalette+ 4,acsetsprite1[ui8ipalette]);
		PALETTE_stWrite(ui8ipalette+ 8,acsetbg0[ui8ipalette]);
		PALETTE_stWrite(ui8ipalette+12,acsetbg1[ui8ipalette]);
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
	st.SPRITE_ui16cCirculationX=stacui16cCirculation[UINT8(cidsizex)];
	st.SPRITE_ui16cCirculationY=stacui16cCirculation[UINT8(cidsizey)];
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
	st.BG0_ui16cCirculationX=stacui16cCirculation[UINT8(cidsizex)];
	st.BG0_ui16cCirculationY=stacui16cCirculation[UINT8(cidsizey)];
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
	st.BG1_ui16cCirculationX=stacui16cCirculation[UINT8(cidsizex)];
	st.BG1_ui16cCirculationY=stacui16cCirculation[UINT8(cidsizey)];
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
	st.BG2_ui16cCirculationX=stacui16cCirculation[UINT8(cidsizex)];
	st.BG2_ui16cCirculationY=stacui16cCirculation[UINT8(cidsizey)];
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
	st.BG3_ui16cCirculationX=stacui16cCirculation[UINT8(cidsizex)];
	st.BG3_ui16cCirculationY=stacui16cCirculation[UINT8(cidsizey)];
	BG3_stApplyOffset();
	return;
}

//	private

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
	AUTO					pui16destination=
		&MEMORY::VRAM_stui16DelegateThis(cui32doffset)+
		(cv2iposition.i16iY()<<7)+
		cv2iposition.i16iX();
	AUTO					pui16destination_line_end=pui16destination+cv2nsize.i16nWidth();

	for(
		CAUTO					cpui16destination_end=pui16destination+(cv2nsize.i16nHeight()<<7);
		pui16destination<cpui16destination_end;
		pui16destination+=128,pui16destination_line_end+=128
	)for(
		AUTO					pui16destination_line=pui16destination;
		pui16destination_line<pui16destination_line_end;
		++pui16destination_line
	)*pui16destination_line=cui16cattribute;
	return;
}

VOID					FAMILYBASIC::BG_stWriteAttribute(
	CUINT32					cui32doffset,
	CVECTOR2&				cv2iposition,
	const PCUINT16			cpcui16cattribute,
	CUINT16					cui16nattribute
)noexcept{
	AUTO					pui16destination=
		&MEMORY::VRAM_stui16DelegateThis(cui32doffset)+
		(cv2iposition.i16iY()<<7)+
		cv2iposition.i16iX();
	CAUTO					cpui16attribute_end=
		pui16destination+
		cui16nattribute;

	for(AUTO pcui16cattribute=cpcui16cattribute;pui16destination<cpui16attribute_end;++pui16destination){
		*pui16destination=*pcui16cattribute;
		++pcui16cattribute;
	}
	return;
}

VOID					FAMILYBASIC::BG_stPrint(
	CUINT32					cui32doffset,
	CVECTOR2&				cv2iposition,
	const PCUSTR			cpcustrstring,
	CUINT8					cui8ibgpalette
)noexcept{
	CAUTO					cui16cbase=UINT16(UINT16(cui8ibgpalette+8)<<12);
	AUTO					pui16destination_base=
		&MEMORY::VRAM_stui16DelegateThis(cui32doffset)+
		(cv2iposition.i16iY()<<7)+
		cv2iposition.i16iX();
	AUTO					pui16destination=pui16destination_base;

	for(AUTO pcustrsource=cpcustrstring;*pcustrsource;++pcustrsource){
		if(*pcustrsource!='\n'){
			*pui16destination=cui16cbase|UINT16(UINT8(*pcustrsource));
			++pui16destination;
		}else{
			pui16destination_base+=128;
			pui16destination=pui16destination_base;
		}
	}
	return;
}

VOID					FAMILYBASIC::BG_stCopyAttribute(
	CUINT32					cui32doffset,
	CVECTOR2&				cv2iposition,
	CVECTOR2&				cv2nsize,
	const PCUINT16			cpcui16cattribute
)noexcept{
	AUTO					pui16destination=
		&MEMORY::VRAM_stui16DelegateThis(cui32doffset)+
		(cv2iposition.i16iY()<<7)+
		cv2iposition.i16iX();
	AUTO					pui16destination_line_end=pui16destination+cv2nsize.i16nWidth();
	AUTO					pcui16cattribute=cpcui16cattribute;

	for(
		CAUTO					cpui16destination_end=pui16destination+(cv2nsize.i16nHeight()<<7);
		pui16destination<cpui16destination_end;
		pui16destination+=128,pui16destination_line_end+=128
	)for(
		AUTO					pui16destination_line=pui16destination;
		pui16destination_line<pui16destination_line_end;
		++pui16destination_line,++pcui16cattribute
	)*pui16destination_line=*pcui16cattribute;
	return;
}
