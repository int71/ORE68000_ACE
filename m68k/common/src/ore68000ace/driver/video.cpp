/****************************************************************************
**																			**
**																			**
**								ORE68000ACE									**
**																			**
**	'm68k/ore68000ace/driver/video.cpp'				2026 written by int71	**
 ****************************************************************************/

//
//		include
//

#include				<ore68000ace/driver/video.hpp>

//
//		using
//

using namespace m68k::ore68000ace::driver;

//
//		class:VIDEO
//

VOID					VIDEO::stNew(VOID)noexcept{
	stOff();
	//	TXT:		000000～07ffff
	//	SPR pttn.:	080000～087fff
	//	SPR attr.:	088000～0887ff
	//	BG0 pttn.:	0c0000～0c7fff
	//	BG1 pttn.:	0c8000～0cffff
	//	BG2 pttn.:	0d0000～0d7fff
	//	BG3 pttn.:	0d8000～0dffff
	//	BG0 attr.:	0e0000～0e7fff
	//	BG1 attr.:	0e8000～0effff
	//	BG2 attr.:	0f0000～0f7fff
	//	BG3 attr.:	0f8000～0fffff
	constexpr UINT32	cui32iaddress=0x800;
	constexpr UINT16	cui16value=UINT16(cui32iaddress>>11);
	stWrite(IDREGISTERW::TextAddress,UINT16(
		(/*TXT ADR*/((VRAM_TEXT_stcui32dDefaultOffset>>19)&1)<<15)|
		(/*パレット*/0x0<<8)|
		(/*複写値*/0xf<<4)|
		(/*複写マスク*/0xf<<0)
	));
	stWrite(IDREGISTERW::SpriteAddress,UINT16(
		(/*SPRITEアトリビュート単位アドレス*/((VRAM_ATTRIBUTE_SPRITE_stcui32dDefaultOffset>>11)&511)<<7)|
		(/*SPRITEパターン単位アドレス*/((VRAM_PATTERN_SPRITE_stcui32dDefaultOffset>>15)&31)<<0)
	));
	stWrite(IDREGISTERW::BG0Address,UINT16(
		(/*BG0アトリビュート単位アドレス*/((VRAM_ATTRIBUTE_BG0_stcui32dDefaultOffset>>15)&31)<<11)|
		(/*BG0パターン単位アドレス*/((VRAM_PATTERN_BG0_stcui32dDefaultOffset>>15)&31)<<0)
	));
	stWrite(IDREGISTERW::BG1Address,UINT16(
		(/*BG1アトリビュート単位アドレス*/((VRAM_ATTRIBUTE_BG1_stcui32dDefaultOffset>>15)&31)<<11)|
		(/*BG1パターン単位アドレス*/((VRAM_PATTERN_BG1_stcui32dDefaultOffset>>15)&31)<<0)
	));
	stWrite(IDREGISTERW::BG2Address,UINT16(
		(/*BG2アトリビュート単位アドレス*/((VRAM_ATTRIBUTE_BG2_stcui32dDefaultOffset>>15)&31)<<11)|
		(/*BG2パターン単位アドレス*/((VRAM_PATTERN_BG2_stcui32dDefaultOffset>>15)&31)<<0)
	));
	stWrite(IDREGISTERW::BG3Address,UINT16(
		(/*BG3アトリビュート単位アドレス*/((VRAM_ATTRIBUTE_BG3_stcui32dDefaultOffset>>15)&31)<<11)|
		(/*BG3パターン単位アドレス*/((VRAM_PATTERN_BG3_stcui32dDefaultOffset>>15)&31)<<0)
	));
	stWrite(IDREGISTERW::TextOffsetX,UINT16(
		(/*TEXT H拡大*/0<<14)|
		(/*TEXT H循環幅*/0<<12)|
		(/*TEXT Xオフセット*/0x000<<0)
	));
	stWrite(IDREGISTERW::TextOffsetY,UINT16(
		(/*TEXT V拡大*/0<<14)|
		(/*TEXT V循環幅*/0<<12)|
		(/*TEXT Yオフセット*/0x000<<0)
	));
	stWrite(IDREGISTERW::SpriteOffsetX,UINT16(
		(/*SPRITE H拡大*/0<<14)|
		(/*SPRITE H循環幅*/0<<12)|
		(/*SPRITE Xオフセット*/0x000<<0)
	));
	stWrite(IDREGISTERW::SpriteOffsetY,UINT16(
		(/*SPRITE V拡大*/0<<14)|
		(/*SPRITE V循環幅*/0<<12)|
		(/*SPRITE Yオフセット*/0x000<<0)
	));
	stWrite(IDREGISTERW::BG0OffsetX,UINT16(
		(/*BG0 H拡大*/0<<14)|
		(/*BG0 H循環幅*/0<<12)|
		(/*BG0 Xオフセット*/0x000<<0)
	));
	stWrite(IDREGISTERW::BG0OffsetY,UINT16(
		(/*BG0 V拡大*/0<<14)|
		(/*BG0 V循環幅*/0<<12)|
		(/*BG0 Yオフセット*/0x000<<0)
	));
	stWrite(IDREGISTERW::BG1OffsetX,UINT16(
		(/*BG1 H拡大*/0<<14)|
		(/*BG1 H循環幅*/0<<12)|
		(/*BG1 Xオフセット*/0x000<<0)
	));
	stWrite(IDREGISTERW::BG1OffsetY,UINT16(
		(/*BG1 V拡大*/0<<14)|
		(/*BG1 V循環幅*/0<<12)|
		(/*BG1 Yオフセット*/0x000<<0)
	));
	stWrite(IDREGISTERW::BG2OffsetX,UINT16(
		(/*BG2 H拡大*/0<<14)|
		(/*BG2 H循環幅*/0<<12)|
		(/*BG2 Xオフセット*/0x000<<0)
	));
	stWrite(IDREGISTERW::BG2OffsetY,UINT16(
		(/*BG2 V拡大*/0<<14)|
		(/*BG2 V循環幅*/0<<12)|
		(/*BG2 Yオフセット*/0x000<<0)
	));
	stWrite(IDREGISTERW::BG3OffsetX,UINT16(
		(/*BG3 H拡大*/0<<14)|
		(/*BG3 H循環幅*/0<<12)|
		(/*BG3 Xオフセット*/0x000<<0)
	));
	stWrite(IDREGISTERW::BG3OffsetY,UINT16(
		(/*BG3 V拡大*/0<<14)|
		(/*BG3 V循環幅*/0<<12)|
		(/*BG3 Yオフセット*/0x000<<0)
	));
	stWrite(IDREGISTERW::Interrupt,UINT16(
		(/*VI*/1<<15)|
		(/*HI*/0<<14)|
		(/*割り込み走査線番号*/0<<0)
	));
	return;
}

VOID					VIDEO::stDelete(VOID)noexcept{
	return;
}

VOID					VIDEO::stOff(VOID)noexcept{
	VIDEO::stWrite(IDREGISTERW::Composite1,UINT16(
		(/*表示面7(最前)*/	0xf<<0xc)|
		(/*表示面6*/		0xf<<0x8)|
		(/*表示面5*/		0xf<<0x4)|
		(/*表示面4*/		0xf<<0x0)
	));
	VIDEO::stWrite(IDREGISTERW::Composite0,UINT16(
		(/*表示面3*/		0xf<<0xc)|
		(/*表示面2*/		0xf<<0x8)|
		(/*表示面1*/		0xf<<0x4)|
		(/*表示面0(最奥)*/	0xf<<0x0)
	));
	PALETTE_stSetWrite(0x00);
	PALETTE_stWrite(0x000);
	return;
}

VOID					VIDEO::stSetCRT640x480P(VOID)noexcept{
	stWrite(IDREGISTERW::CRTHBlank,UINT16(
		(/*CLK*/1<<0xf)|
		(/*CLK分周*/3<<0xd)|
		(/*水平帰線区間*/160<<0x2)|
		(/*.5*/0<<0x1)|
		(/*.25*/0<<0x0)
	));
	stWrite(IDREGISTERW::CRTHVisible,UINT16(
		(/*水平表示区間*/640<<0x2)
	));
	stWrite(IDREGISTERW::CRTVBlank,UINT16(
		(/*EO*/0<<0xf)|
		(/*IL*/0<<0xe)|
		(/*VL 2X*/0<<0xd)|
		(/*垂直帰線区間*/45<<0x2)|
		(/*.5*/0<<0x1)|
		(/*.25*/0<<0x0)
	));
	stWrite(IDREGISTERW::CRTVVisible,UINT16(
		(/*RST*/1<<0xf)|
		(/*垂直表示区間*/480<<0x2)
	));
	return;
}

VOID					VIDEO::stSetCRT320x240P(VOID)noexcept{
	stWrite(IDREGISTERW::CRTHBlank,UINT16(
		(/*CLK*/1<<0xf)|
		(/*CLK分周*/1<<0xd)|
		(/*水平帰線区間*/80<<0x2)|
		(/*.5*/0<<0x1)|
		(/*.25*/0<<0x0)
	));
	stWrite(IDREGISTERW::CRTHVisible,UINT16(
		(/*水平表示区間*/320<<0x2)
	));
	stWrite(IDREGISTERW::CRTVBlank,UINT16(
		(/*EO*/1<<0xf)|
		(/*IL*/0<<0xe)|
		(/*VL 2X*/1<<0xd)|
		(/*垂直帰線区間*/45<<0x2)|
		(/*.5*/0<<0x1)|
		(/*.25*/0<<0x0)
	));
	stWrite(IDREGISTERW::CRTVVisible,UINT16(
		(/*RST*/1<<0xf)|
		(/*垂直表示区間*/480<<0x2)
	));
	return;
}

VOID					VIDEO::stSetCRT320x240I(VOID)noexcept{
	stWrite(IDREGISTERW::CRTHBlank,UINT16(
		(/*CLK*/1<<0xf)|
		(/*CLK分周*/1<<0xd)|
		(/*水平帰線区間*/80<<0x2)|
		(/*.5*/0<<0x1)|
		(/*.25*/0<<0x0)
	));
	stWrite(IDREGISTERW::CRTHVisible,UINT16(
		(/*水平表示区間*/320<<0x2)
	));
	stWrite(IDREGISTERW::CRTVBlank,UINT16(
		(/*EO*/1<<0xf)|
		(/*IL*/1<<0xe)|
		(/*VL 2X*/1<<0xd)|
		(/*垂直帰線区間*/45<<0x2)|
		(/*.5*/0<<0x1)|
		(/*.25*/0<<0x0)
	));
	stWrite(IDREGISTERW::CRTVVisible,UINT16(
		(/*RST*/1<<0xf)|
		(/*垂直表示区間*/480<<0x2)
	));
	return;
}

VOID					VIDEO::stSetCRT256x192P(VOID)noexcept{
	stWrite(IDREGISTERW::CRTHBlank,UINT16(
		(/*CLK*/0<<0xf)|
		(/*CLK分周*/1<<0xd)|
		(/*水平帰線区間*/85<<0x2)|
		(/*.5*/0<<0x1)|
		(/*.25*/1<<0x0)
	));
	stWrite(IDREGISTERW::CRTHVisible,UINT16(
		(/*水平表示区間*/256<<0x2)
	));
	stWrite(IDREGISTERW::CRTVBlank,UINT16(
		(/*EO*/1<<0xf)|
		(/*IL*/0<<0xe)|
		(/*VL 2X*/1<<0xd)|
		(/*垂直帰線区間*/141<<0x2)|
		(/*.5*/0<<0x1)|
		(/*.25*/0<<0x0)
	));
	stWrite(IDREGISTERW::CRTVVisible,UINT16(
		(/*RST*/1<<0xf)|
		(/*垂直表示区間*/384<<0x2)
	));
	return;
}

VOID					VIDEO::stSetCRT256x192I(VOID)noexcept{
	stWrite(IDREGISTERW::CRTHBlank,UINT16(
		(/*CLK*/0<<0xf)|
		(/*CLK分周*/1<<0xd)|
		(/*水平帰線区間*/85<<0x2)|
		(/*.5*/0<<0x1)|
		(/*.25*/1<<0x0)
	));
	stWrite(IDREGISTERW::CRTHVisible,UINT16(
		(/*水平表示区間*/256<<0x2)
	));
	stWrite(IDREGISTERW::CRTVBlank,UINT16(
		(/*EO*/1<<0xf)|
		(/*IL*/1<<0xe)|
		(/*VL 2X*/1<<0xd)|
		(/*垂直帰線区間*/141<<0x2)|
		(/*.5*/0<<0x1)|
		(/*.25*/0<<0x0)
	));
	stWrite(IDREGISTERW::CRTVVisible,UINT16(
		(/*RST*/1<<0xf)|
		(/*垂直表示区間*/384<<0x2)
	));
	return;
}

VOID					VIDEO::stSetCRT256x212P(VOID)noexcept{
	stWrite(IDREGISTERW::CRTHBlank,UINT16(
		(/*CLK*/0<<0xf)|
		(/*CLK分周*/1<<0xd)|
		(/*水平帰線区間*/85<<0x2)|
		(/*.5*/0<<0x1)|
		(/*.25*/1<<0x0)
	));
	stWrite(IDREGISTERW::CRTHVisible,UINT16(
		(/*水平表示区間*/256<<0x2)
	));
	stWrite(IDREGISTERW::CRTVBlank,UINT16(
		(/*EO*/1<<0xf)|
		(/*IL*/0<<0xe)|
		(/*VL 2X*/1<<0xd)|
		(/*垂直帰線区間*/101<<0x2)|
		(/*.5*/0<<0x1)|
		(/*.25*/0<<0x0)
	));
	stWrite(IDREGISTERW::CRTVVisible,UINT16(
		(/*RST*/1<<0xf)|
		(/*垂直表示区間*/424<<0x2)
	));
	return;
}

VOID					VIDEO::stSetCRT256x212I(VOID)noexcept{
	stWrite(IDREGISTERW::CRTHBlank,UINT16(
		(/*CLK*/0<<0xf)|
		(/*CLK分周*/1<<0xd)|
		(/*水平帰線区間*/85<<0x2)|
		(/*.5*/0<<0x1)|
		(/*.25*/1<<0x0)
	));
	stWrite(IDREGISTERW::CRTHVisible,UINT16(
		(/*水平表示区間*/256<<0x2)
	));
	stWrite(IDREGISTERW::CRTVBlank,UINT16(
		(/*EO*/1<<0xf)|
		(/*IL*/1<<0xe)|
		(/*VL 2X*/1<<0xd)|
		(/*垂直帰線区間*/101<<0x2)|
		(/*.5*/0<<0x1)|
		(/*.25*/0<<0x0)
	));
	stWrite(IDREGISTERW::CRTVVisible,UINT16(
		(/*RST*/1<<0xf)|
		(/*垂直表示区間*/424<<0x2)
	));
	return;
}

VOID					VIDEO::PALETTE_stWrite(
	CUINT8					cui8iaddress,
	const PCUINT16			cpcui16ccolor,
	CUINT8					cui8nsize
)noexcept{
	CAUTO					cpcui16ccolor_end=cpcui16ccolor+UINT8(cui8nsize-1)+1;

	PALETTE_stSetWrite(cui8iaddress);
	for(AUTO pcui16ccolor=cpcui16ccolor;pcui16ccolor<cpcui16ccolor_end;++pcui16ccolor)PALETTE_stWrite(*pcui16ccolor);
	return;
}

VOID				 	VIDEO::VRAM_TEXT_stWrite(
	CUINT16					cui16ix,
	CUINT16					cui16iy,
	const PCUSTR			cpcustrsource,
	CUINT8					cui8ccolor
)noexcept{
	AUTO					ui16iy=cui16iy;
	AUTO					pui8destinaion_pattern=&MEMORYS::VRAM_stui8DelegateThis(0)+OFWSIZE(cui16ix)+(OFWSIZE(ui16iy)<<11);
	AUTO					pcustrsource=cpcustrsource;
	UINT16					ui16source;

	stWrite(IDREGISTERW::TextAddress,UINT16(
		((/*TXT ADR*/VRAM_TEXT_stcui32dDefaultOffset>>19)<<0xf)|
		(/*パレット*/0x0<<0x8)|
		(/*プレーン値*/UINT16(cui8ccolor)<<0x4)|
		(/*プレーンマスク*/0xf<<0x0)
	));
	while((ui16source=STD::stui16cRead(pcustrsource)))if(
		(ui16source==UINT16('\r'))||
		(ui16source==UINT16('\n'))
	){
		++ui16iy;
		pui8destinaion_pattern=&MEMORYS::VRAM_stui8DelegateThis(0)+OFWSIZE(cui16ix)+(OFWSIZE(ui16iy)<<11);
	}else{
		CAUTO					cpcui8source=&MEMORYS::ROM_FONT_stcui8GetThis(0)+(OFWSIZE(
			(ui16source<0x007f)?((ui16source&0x003f)|(UINT16(UINT16(0x000e)+(ui16source>>6))<<6)):(
				(ui16source<0x00e0)?((ui16source-0x00a0)|UINT16(0x000b)<<6):(
					(ui16source<0x8500)?((ui16source&0x003f)|UINT16((ui16source>>8)*3+((ui16source>>6)&0x03)-0x0184)<<6):(
						((ui16source&0x003f)|UINT16((ui16source>>8)*3+((ui16source>>6)&0x03)-0x018a)<<6)
					)
				)
			)
		)<<5);

		if(ui16source<0x0100){
			for(UINT16 i=0;i<16;++i){
				CAUTO					cpui8dst=pui8destinaion_pattern+(i<<7);
				CAUTO					cui8src=cpcui8source[i<<1];

				cpui8dst[0]=cui8src;
			}
			++pui8destinaion_pattern;
		}else{
			for(UINT16 i=0;i<16;++i){
				CAUTO					cpui8dst=pui8destinaion_pattern+(i<<7);
				CAUTO					cui16src=PCUINT16(cpcui8source)[i];

				cpui8dst[0]=UINT8(cui16src>>8);
				cpui8dst[1]=UINT8(cui16src&0xff);
			}
			pui8destinaion_pattern+=2;
		}
	}
	return;
}

