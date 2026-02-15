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

VOID					FAMILYBASIC::stNew(VOID)noexcept{
	using					IDREGISTERW=VIDEO_DRIVER::IDREGISTERW;
	using					IDLAYER=VIDEO_DRIVER::IDLAYER;

	VIDEO_DRIVER::stSetCRT256x212P();
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

VOID					FAMILYBASIC::PALETTE_stWrite(
	CUINT8					cui8ipalette,
	CUINT8					cui8inescolor0,
	CUINT8					cui8inescolor1,
	CUINT8					cui8inescolor2,
	CUINT8					cui8inescolor3
)noexcept{
	static constexpr UINT16	stacui16ccolornes[]={
		common::ui16cGetColor(0x616161),common::ui16cGetColor(0x000088),common::ui16cGetColor(0x1f0d99),common::ui16cGetColor(0x371379),common::ui16cGetColor(0x561260),common::ui16cGetColor(0x5d0010),common::ui16cGetColor(0x520e00),common::ui16cGetColor(0x3a2308),
		common::ui16cGetColor(0x21350c),common::ui16cGetColor(0x0d410e),common::ui16cGetColor(0x174417),common::ui16cGetColor(0x003a1f),common::ui16cGetColor(0x002f57),common::ui16cGetColor(0x000000),common::ui16cGetColor(0x000000),common::ui16cGetColor(0x000000),
		common::ui16cGetColor(0xaaaaaa),common::ui16cGetColor(0x0d4dc4),common::ui16cGetColor(0x4b24de),common::ui16cGetColor(0x6912cf),common::ui16cGetColor(0x9014ad),common::ui16cGetColor(0x9d1c48),common::ui16cGetColor(0x923404),common::ui16cGetColor(0x735005),
		common::ui16cGetColor(0x5d6913),common::ui16cGetColor(0x167a11),common::ui16cGetColor(0x138008),common::ui16cGetColor(0x127649),common::ui16cGetColor(0x1c6691),common::ui16cGetColor(0x000000),common::ui16cGetColor(0x000000),common::ui16cGetColor(0x000000),
		common::ui16cGetColor(0xfcfcfc),common::ui16cGetColor(0x639afc),common::ui16cGetColor(0x8a7efc),common::ui16cGetColor(0xb06afc),common::ui16cGetColor(0xdd6df2),common::ui16cGetColor(0xe771ab),common::ui16cGetColor(0xe38658),common::ui16cGetColor(0xcc9e22),
		common::ui16cGetColor(0xa8b100),common::ui16cGetColor(0x72c100),common::ui16cGetColor(0x5acd4e),common::ui16cGetColor(0x34c28e),common::ui16cGetColor(0x4fbece),common::ui16cGetColor(0x424242),common::ui16cGetColor(0x000000),common::ui16cGetColor(0x000000),
		common::ui16cGetColor(0xfcfcfc),common::ui16cGetColor(0xbed4fc),common::ui16cGetColor(0xcacafc),common::ui16cGetColor(0xd9c4fc),common::ui16cGetColor(0xecc1fc),common::ui16cGetColor(0xfac3e7),common::ui16cGetColor(0xf7cec3),common::ui16cGetColor(0xe2cda7),
		common::ui16cGetColor(0xdadb9c),common::ui16cGetColor(0xc8e39e),common::ui16cGetColor(0xbfe5b8),common::ui16cGetColor(0xb2ebc8),common::ui16cGetColor(0xb7e5eb),common::ui16cGetColor(0xacacac),common::ui16cGetColor(0x000000),common::ui16cGetColor(0x000000)
	};
	CUINT16					acui16ccolor[]={
		stacui16ccolornes[cui8inescolor0],
		stacui16ccolornes[cui8inescolor1],
		stacui16ccolornes[cui8inescolor2],
		stacui16ccolornes[cui8inescolor3]
	};

	VIDEO_DRIVER::PALETTE_stWrite(cui8ipalette<<4,acui16ccolor,4);
	return;
}

VOID					FAMILYBASIC::PALETTE_stWriteSet(
	CUINT8					cui8ispriteset,
	CUINT8					cui8ibgset
)noexcept{
	static constexpr UINT8	staacspriteset[][4][4]={
		{
			{0x3f,0x36,0x16,0x02},
			{0x3f,0x27,0x30,0x19},
			{0x3f,0x35,0x25,0x17},
			{0x3f,0x30,0x27,0x16}
		},{
			{0x3f,0x30,0x16,0x01},
			{0x3f,0x10,0x00,0x01},
			{0x3f,0x30,0x29,0x09},
			{0x3f,0x30,0x16,0x07}
		},{
			{0x3f,0x30,0x26,0x12},
			{0x3f,0x30,0x15,0x12},
			{0x3f,0x30,0x12,0x16},
			{0x3f,0x30,0x26,0x19}
		}
	};
	static constexpr UINT8	staacbg[][4][4]={
		{
			{0x3f,0x2c,0x15,0x07},
			{0x3f,0x27,0x21,0x12},
			{0x3f,0x29,0x36,0x17},
			{0x3f,0x30,0x26,0x07}
		},{
			{0x3f,0x30,0x21,0x02},
			{0x3f,0x30,0x27,0x18},
			{0x3f,0x30,0x27,0x16},
			{0x3f,0x29,0x36,0x17}
		}
	};
	CAUTO&					acsprite=staacspriteset[(cui8ispriteset<3)?cui8ispriteset:0];
	CAUTO&					acbg=staacbg[(cui8ibgset<2)?cui8ibgset:0];

	for(UINT8 ui8ipalette=0;ui8ipalette<4;++ui8ipalette){
		PALETTE_stWrite(ui8ipalette+0,acsprite[ui8ipalette]);
		PALETTE_stWrite(ui8ipalette+8,acbg[ui8ipalette]);
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
