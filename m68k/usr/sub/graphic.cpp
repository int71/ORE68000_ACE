/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/graphic.cpp'								2026 written by int71	**
 ****************************************************************************/

//
//		include
//

#include				"os.hpp"
#include				"graphic.hpp"

//
//		using
//

using namespace m68k::i71::sub;

//
//		class:GRAPHIC
//

//	public

VOID					GRAPHIC::stNew(
	COFWBOOL				ceshow
)noexcept{
	st.eShow=TRUE;
	st.VBLANK_fp_callbackThis=NULL;
	//	表示周り
	stShow(FALSE);
	DRIVER::stSetCRT640x480P();
	//	アドレス割り当て
	DRIVER::stWrite(IDREGISTERW::TextAddress,
		0x00f0
	);	//	とりあえず複数プレーン同時書き込みだけは無効化
	DRIVER::stWrite(IDREGISTERW::SpriteAddress,UINT16(
		(/*SPRITEアトリビュート単位アドレス*/((VRAM_ATTRIBUTE_SPRITE_stcui32dOffset>>11)&511)<<7)|
		(/*SPRITEパターン単位アドレス*/((VRAM_PATTERN_SPRITE_stcui32dOffset>>15)&31)<<0)
	));
	DRIVER::stWrite(IDREGISTERW::BG0Address,UINT16(
		(/*BG0アトリビュート単位アドレス*/((VRAM_ATTRIBUTE_BG0_stcui32dOffset>>15)&31)<<11)|
		(/*BG0パターン単位アドレス*/((VRAM_PATTERN_BG01_stcui32dOffset>>15)&31)<<0)
	));
	DRIVER::stWrite(IDREGISTERW::BG1Address,UINT16(
		(/*BG0アトリビュート単位アドレス*/((VRAM_ATTRIBUTE_BG1_stcui32dOffset>>15)&31)<<11)|
		(/*BG0パターン単位アドレス*/((VRAM_PATTERN_BG01_stcui32dOffset>>15)&31)<<0)
	));
	DRIVER::stWrite(IDREGISTERW::BG2Address,UINT16(
		(/*BG0アトリビュート単位アドレス*/((VRAM_ATTRIBUTE_BG2_stcui32dOffset>>15)&31)<<11)|
		(/*BG0パターン単位アドレス*/((VRAM_PATTERN_BG23_stcui32dOffset>>15)&31)<<0)
	));
	DRIVER::stWrite(IDREGISTERW::BG3Address,UINT16(
		(/*BG0アトリビュート単位アドレス*/((VRAM_ATTRIBUTE_BG3_stcui32dOffset>>15)&31)<<11)|
		(/*BG0パターン単位アドレス*/((VRAM_PATTERN_BG23_stcui32dOffset>>15)&31)<<0)
	));
	//	表示設定
	DRIVER::stWrite(IDREGISTERW::TextOffsetX,
		0
	);
	DRIVER::stWrite(IDREGISTERW::TextOffsetY,
		0
	);
	DRIVER::stWrite(IDREGISTERW::SpriteOffsetX,UINT16(
		(/*SPRITE H拡大*/0<<14)|
		(/*SPRITE H循環幅*/0<<12)|
		(/*SPRITE Xオフセット*/0x000<<0)
	));
	DRIVER::stWrite(IDREGISTERW::SpriteOffsetY,UINT16(
		(/*SPRITE V拡大*/0<<14)|
		(/*SPRITE V循環幅*/0<<12)|
		(/*SPRITE Yオフセット*/0x000<<0)
	));
	DRIVER::stWrite(IDREGISTERW::BG0OffsetX,UINT16(
		(/*BG0 H拡大*/0<<14)|
		(/*BG0 H循環幅*/0<<12)|
		(/*BG0 Xオフセット*/0x000<<0)
	));
	DRIVER::stWrite(IDREGISTERW::BG0OffsetY,UINT16(
		(/*BG0 V拡大*/0<<14)|
		(/*BG0 V循環幅*/0<<12)|
		(/*BG0 Yオフセット*/0x000<<0)
	));
	DRIVER::stWrite(IDREGISTERW::BG1OffsetX,UINT16(
		(/*BG0 H拡大*/0<<14)|
		(/*BG0 H循環幅*/0<<12)|
		(/*BG0 Xオフセット*/0x000<<0)
	));
	DRIVER::stWrite(IDREGISTERW::BG1OffsetY,UINT16(
		(/*BG0 V拡大*/0<<14)|
		(/*BG0 V循環幅*/0<<12)|
		(/*BG0 Yオフセット*/0x000<<0)
	));
	DRIVER::stWrite(IDREGISTERW::BG2OffsetX,UINT16(
		(/*BG0 H拡大*/0<<14)|
		(/*BG0 H循環幅*/0<<12)|
		(/*BG0 Xオフセット*/0x000<<0)
	));
	DRIVER::stWrite(IDREGISTERW::BG2OffsetY,UINT16(
		(/*BG0 V拡大*/0<<14)|
		(/*BG0 V循環幅*/0<<12)|
		(/*BG0 Yオフセット*/0x000<<0)
	));
	DRIVER::stWrite(IDREGISTERW::BG3OffsetX,UINT16(
		(/*BG0 H拡大*/0<<14)|
		(/*BG0 H循環幅*/0<<12)|
		(/*BG0 Xオフセット*/0x000<<0)
	));
	DRIVER::stWrite(IDREGISTERW::BG3OffsetY,UINT16(
		(/*BG0 V拡大*/0<<14)|
		(/*BG0 V循環幅*/0<<12)|
		(/*BG0 Yオフセット*/0x000<<0)
	));
	//	割り込み設定
	OS::INT_stSetCallback(
		[](const OS::IDCALLBACK cidcallback,const PVOID cpobject)noexcept{
			switch(cidcallback){
			case OS::IDCALLBACK::VBlank:
				if(st.eShow)DRIVER::stWrite(IDREGISTERW::TextAddress,0x11f0);
				else DRIVER::stWrite(IDREGISTERW::TextAddress,0x00f0);
				if(st.VBLANK_fp_callbackThis)st.VBLANK_fp_callbackThis(st.VBLANK_pObject);
				break;
			case OS::IDCALLBACK::HBlank:
				if(st.eShow)DRIVER::stWrite(IDREGISTERW::TextAddress,0x91f0);
				break;
			}
			return;
		},
		NULL
	);
	OS::INT_stSetHBlank(254);
	if(ceshow)stShow(TRUE);
	return;
}

VOID					GRAPHIC::stDelete(VOID)noexcept{
	return;
}

VOID					GRAPHIC::stShow(
	COFWBOOL				ceshow
)noexcept{
	if(st.eShow!=ceshow){
		st.eShow=ceshow;
		if(st.eShow){
			DRIVER::stWrite(IDREGISTERW::Composite1,
				(/*表示面7(最前)*/	IDLAYER::BG0<<0xc)|
				(/*表示面6*/		IDLAYER::SpritePriority0<<0x8)|
				(/*表示面5*/		IDLAYER::BG1<<0x4)|
				(/*表示面4*/		IDLAYER::SpritePriority1<<0x0)
			);
			DRIVER::stWrite(IDREGISTERW::Composite0,
				(/*表示面3*/		IDLAYER::BG2<<0xc)|
				(/*表示面2*/		IDLAYER::SpritePriority2<<0x8)|
				(/*表示面1*/		IDLAYER::BG3<<0x4)|
				(/*表示面0(最奥)*/	IDLAYER::None<<0x0)
			);
		}else{
			DRIVER::stWrite(IDREGISTERW::Composite1,
				(/*表示面7(最前)*/	IDLAYER::None<<0xc)|
				(/*表示面6*/		IDLAYER::None<<0x8)|
				(/*表示面5*/		IDLAYER::None<<0x4)|
				(/*表示面4*/		IDLAYER::None<<0x0)
			);
			DRIVER::stWrite(IDREGISTERW::Composite0,
				(/*表示面3*/		IDLAYER::None<<0xc)|
				(/*表示面2*/		IDLAYER::None<<0x8)|
				(/*表示面1*/		IDLAYER::None<<0x4)|
				(/*表示面0(最奥)*/	IDLAYER::None<<0x0)
			);
		}
	}
	return;
}
