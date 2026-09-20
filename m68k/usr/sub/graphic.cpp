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
	using					IDREGISTERW=VIDEO_DRIVER::IDREGISTERW;

	stShow(FALSE);
	VIDEO_DRIVER::stSetCRT640x480P();
	VIDEO_DRIVER::stWrite(IDREGISTERW::TextOffsetX,0);
	VIDEO_DRIVER::stWrite(IDREGISTERW::TextOffsetY,0);
	//	とりあえず複数プレーン同時書き込みだけは無効化
	VIDEO_DRIVER::stWrite(IDREGISTERW::TextAddress,0x00f0);
	OS::INT_stSetCallback(
		[](const OS::IDCALLBACK cidcallback,const PVOID cpobject)noexcept{
			if(st.eShow){
				switch(cidcallback){
				case OS::IDCALLBACK::VBlank:
					VIDEO_DRIVER::stWrite(IDREGISTERW::TextAddress,0x11f0);
					break;
				case OS::IDCALLBACK::HBlank:
					VIDEO_DRIVER::stWrite(IDREGISTERW::TextAddress,0x91f0);
					break;
				}
			}else{
				VIDEO_DRIVER::stWrite(IDREGISTERW::TextAddress,0x00f0);
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
	using					IDREGISTERW=VIDEO_DRIVER::IDREGISTERW;
	using					IDLAYER=VIDEO_DRIVER::IDLAYER;

	if(st.eShow!=ceshow){
		st.eShow=ceshow;
		if(st.eShow){
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
	}
	return;
}
