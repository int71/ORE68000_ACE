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
	stFillBG0({0,0},{128,128},0x8020);
	stFillBG1({0,0},{128,128},0x8020);
	stFillBG2({0,0},{128,128},0x8020);
	stFillBG3({0,0},{128,128},0x8020);
	OS::BGM_stSetMask(
		SOUND_DRIVER::stcui16cChannelMaskPCM0|
		SOUND_DRIVER::stcui16cChannelMaskPCM1|
		SOUND_DRIVER::stcui16cChannelMaskPCM2
	);
	OS::SE0_stSetMask(
		SOUND_DRIVER::stcui16cChannelMaskPCM3
	);
	OS::SE1_stSetMask(
		SOUND_DRIVER::stcui16cChannelMaskPCM4
	);
	return;
}

VOID					FAMILYBASIC::stDelete(VOID)noexcept{
	return;
}

VOID					FAMILYBASIC::stSetPalette(
	CUINT8					cui8ipalette,
	CUINT8					cui8inescolor0,
	CUINT8					cui8inescolor1,
	CUINT8					cui8inescolor2,
	CUINT8					cui8inescolor3
)noexcept{
	static constexpr UINT16	stacui16ccolornes[]={
		common::ui16cGetColor(0x696969),common::ui16cGetColor(0x00148f),common::ui16cGetColor(0x1e029b),common::ui16cGetColor(0x3f008a),common::ui16cGetColor(0x600060),common::ui16cGetColor(0x660017),common::ui16cGetColor(0x570d00),common::ui16cGetColor(0x451b00),common::ui16cGetColor(0x243400),common::ui16cGetColor(0x004200),common::ui16cGetColor(0x004500),common::ui16cGetColor(0x003c1f),common::ui16cGetColor(0x00315c),common::ui16cGetColor(0x000000),common::ui16cGetColor(0x000000),common::ui16cGetColor(0x000000),
		common::ui16cGetColor(0xafafaf),common::ui16cGetColor(0x0f51dd),common::ui16cGetColor(0x442ff3),common::ui16cGetColor(0x7220e2),common::ui16cGetColor(0xa319b3),common::ui16cGetColor(0xae1c51),common::ui16cGetColor(0xa43400),common::ui16cGetColor(0x884d00),common::ui16cGetColor(0x676d00),common::ui16cGetColor(0x208000),common::ui16cGetColor(0x008b00),common::ui16cGetColor(0x007f42),common::ui16cGetColor(0x006c97),common::ui16cGetColor(0x010101),common::ui16cGetColor(0x000000),common::ui16cGetColor(0x000000),
		common::ui16cGetColor(0xffffff),common::ui16cGetColor(0x65aaff),common::ui16cGetColor(0x8c96ff),common::ui16cGetColor(0xb983ff),common::ui16cGetColor(0xdd6fff),common::ui16cGetColor(0xea6fbd),common::ui16cGetColor(0xeb8466),common::ui16cGetColor(0xdca21f),common::ui16cGetColor(0xbab403),common::ui16cGetColor(0x7ecb07),common::ui16cGetColor(0x54d33e),common::ui16cGetColor(0x3cd284),common::ui16cGetColor(0x3ec7cc),common::ui16cGetColor(0x4b4b4b),common::ui16cGetColor(0x000000),common::ui16cGetColor(0x000000),
		common::ui16cGetColor(0xffffff),common::ui16cGetColor(0xbde2ff),common::ui16cGetColor(0xcecfff),common::ui16cGetColor(0xe6c2ff),common::ui16cGetColor(0xf6bcff),common::ui16cGetColor(0xf9c2ed),common::ui16cGetColor(0xfacfc6),common::ui16cGetColor(0xf8deac),common::ui16cGetColor(0xeee9a1),common::ui16cGetColor(0xd0f59f),common::ui16cGetColor(0xbbf5af),common::ui16cGetColor(0xb3f5cd),common::ui16cGetColor(0xb9edf0),common::ui16cGetColor(0xb9b9b9),common::ui16cGetColor(0x000000),common::ui16cGetColor(0x000000)
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

//	private

VOID					FAMILYBASIC::stFillBG(
	CUINT32					cui32doffset,
	CVECTOR2&				cv2idestination,
	CVECTOR2&				cv2ndestination,
	CUINT16					cui16nsource
)noexcept{
	AUTO					pui16destination=
		&MEMORY::VRAM_stui16DelegateThis(cui32doffset)+
		(cv2idestination.i16iY()<<7)+
		cv2idestination.i16iX();
	CAUTO					cpui16destination_end=
		pui16destination+
		(cv2ndestination.i16nHeight()<<7);
	AUTO					pui16destination_line_end=pui16destination+cv2ndestination.i16nWidth();

	for(
		;
		pui16destination<cpui16destination_end;
		pui16destination+=128,pui16destination_line_end+=128
	)for(
		AUTO					pui16destination_line=pui16destination;
		pui16destination_line<pui16destination_line_end;
		++pui16destination_line
	)*pui16destination_line=cui16nsource;
	return;
}

VOID					FAMILYBASIC::stWriteBG(
	CUINT32					cui32doffset,
	CVECTOR2&				cv2idestination,
	const PCUINT16			cpcui16csource,
	CUINT16					cui16nsource
)noexcept{
	AUTO					pui16destination=
		&MEMORY::VRAM_stui16DelegateThis(cui32doffset)+
		(cv2idestination.i16iY()<<7)+
		cv2idestination.i16iX();
	CAUTO					cpui16attribute_end=
		pui16destination+
		cui16nsource;

	for(AUTO pcui16csource=cpcui16csource;pui16destination<cpui16attribute_end;++pui16destination){
		*pui16destination=*pcui16csource;
		++pcui16csource;
	}
	return;
}

VOID					FAMILYBASIC::stWriteBG(
	CUINT32					cui32doffset,
	CVECTOR2&				cv2idestination,
	CUINT8					cui8ipalette,
	const PCUSTR			cpcustrsource
)noexcept{
	CAUTO					cui16cbase=UINT16(UINT16(cui8ipalette)<<12);
	AUTO					pui16destination_base=
		&MEMORY::VRAM_stui16DelegateThis(cui32doffset)+
		(cv2idestination.i16iY()<<7)+
		cv2idestination.i16iX();
	AUTO					pui16destination=pui16destination_base;

	for(AUTO pcustrsource=cpcustrsource;*pcustrsource;++pcustrsource){
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
