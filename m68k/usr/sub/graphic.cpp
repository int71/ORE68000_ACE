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

#include				"../common/map.hpp"
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

VOID					GRAPHIC::stDrawRect(
	CUINT16					cui16ccolor,
	CSHAPE&					cshpshape
)noexcept{
	stProcess<
		[](CVECTOR2& cv2isource,CUINT16 cui16ccolorback,const PVOID cpobject)noexcept{
			return *PCUINT16(cpobject);
		}
	>(cshpshape,PVOID(&cui16ccolor));
	return;
}

VOID					GRAPHIC::stCopy(
	BITMAP&					bmpsource,
	CVECTOR2&				cv2iposition
)noexcept{
	stProcess<
		[](CVECTOR2& cv2isource,CUINT16 cui16ccolorback,const PVOID cpobject)noexcept{
			AUTO&				bmpsource=*PBITMAP(cpobject);

			return bmpsource.ui16cGetColor(cv2isource);
		}
	>({cv2iposition,bmpsource.v2nGetSize()},PVOID(&bmpsource));
	return;
}

VOID					GRAPHIC::stCopyRect(
	BITMAP&					bmpsource,
	CSHAPE&					cshpsource,
	CVECTOR2&				cv2iposition
)noexcept{
	class LOCAL{
	public:
		PBITMAP					pbmpSource;
		VECTOR2					v2dOffset;
	};
	LOCAL					xobject={
		&bmpsource,
		cshpsource.v2iPosition
	};

	stProcess<
		[](CVECTOR2& cv2isource,CUINT16 cui16ccolorback,const PVOID cpobject)noexcept{
			CAUTO&				cxobject=*(const LOCAL*)(cpobject);
			AUTO&				bmpsource=*cxobject.pbmpSource;

			return bmpsource.ui16cGetColor(cv2isource+cxobject.v2dOffset);
		}
	>({cv2iposition,cshpsource.v2nSize},PVOID(&xobject));
	return;
}

//	private

template<const GRAPHIC::IDPART cidPart>
_INLINE_ PUINT8			GRAPHIC::stpui8cGetDestination(
	CVECTOR2&				cv2iposition
)noexcept{
	constexpr AUTO			cui32doffset=(cidPart==IDPART::Upper)?UINT32(
		0x000000
	):UINT32(
		0x080000				//	バンク#1オフセット
		-(256<<9)				//	Y座標「-256」オフセット
	);

	return PUINT8(
		+MAP::VRAM::stcui32iAddressS+cui32doffset
		+(UINT32(cv2iposition.i16iY())<<9)
		+(cv2iposition.i16iX()>>1)
	);
}

template<const GRAPHIC::FP_BRUSH cfp_brushThis>
_INLINE_ VOID			GRAPHIC::stProcess(
	CSHAPE&					cshpshape,
	const PVOID				cpobject
)noexcept{
	stProcessPart<cfp_brushThis,IDPART::Upper>(cshpshape,cpobject);
	stProcessPart<cfp_brushThis,IDPART::Lower>(cshpshape,cpobject);
	return;
}

template<const GRAPHIC::FP_BRUSH cfp_brushThis,const GRAPHIC::IDPART cidPart>
VOID					GRAPHIC::stProcessPart(
	CSHAPE&					cshpshape,
	const PVOID				cpobject
)noexcept{
	CAUTO					cshppart=cshpshape.shpMakePart<cidPart>();

	stProcessFraction<cfp_brushThis,cidPart, 4,IDSIDE::Left>(cshpshape.v2iPosition,cshppart,cpobject);
	stProcessFraction<cfp_brushThis,cidPart, 8,IDSIDE::Left>(cshpshape.v2iPosition,cshppart,cpobject);
	stProcessFraction<cfp_brushThis,cidPart,16,IDSIDE::Left>(cshpshape.v2iPosition,cshppart,cpobject);
	stProcessUnit<cfp_brushThis,cidPart,32>(cshpshape.v2iPosition,cshppart,cpobject);
	stProcessFraction<cfp_brushThis,cidPart,16,IDSIDE::Right>(cshpshape.v2iPosition,cshppart,cpobject);
	stProcessFraction<cfp_brushThis,cidPart, 8,IDSIDE::Right>(cshpshape.v2iPosition,cshppart,cpobject);
	stProcessFraction<cfp_brushThis,cidPart, 4,IDSIDE::Right>(cshpshape.v2iPosition,cshppart,cpobject);
	return;
}

_INLINE_ UINT16			GRAPHIC::stui16cGetColorBack0(
	const PCUINT16			cpcui16csource
)noexcept{
	return UINT16(
		(UINT16(cpcui16csource[0x000000]&0xf0)>>4)|
		(UINT16(cpcui16csource[0x020000]&0xf0)<<0)|
		(UINT16(cpcui16csource[0x040000]&0xf0)<<4)
	);
}

_INLINE_ UINT16			GRAPHIC::stui16cGetColorBack1(
	const PCUINT16			cpcui16csource
)noexcept{
	return UINT16(
		(UINT16(cpcui16csource[0x000000]&0x0f)<<0)|
		(UINT16(cpcui16csource[0x020000]&0x0f)<<4)|
		(UINT16(cpcui16csource[0x040000]&0x0f)<<8)
	);
}

template<const GRAPHIC::FP_BRUSH cfp_brushThis,const GRAPHIC::IDPART cidPart,CUINT8 cui8nAlignBit>
VOID					GRAPHIC::stProcessUnit(
	CVECTOR2&				cv2iorigin,
	CSHAPE&					cshppart,
	const PVOID				cpobject
)noexcept{
	if(
		CAUTO					cshpunit=cshppart.shpMakeUnit<cui8nAlignBit>();
		cshpunit.v2nSize.i16nWidth()
	){
		AUTO					pui8cdestination=stpui8cGetDestination<cidPart>(cshpunit.v2iPosition);
		CAUTO					cui32nhrange=UINT32(UINT32(cshpunit.v2nSize.i16nWidth())>>1);
		CAUTO					cui32nvrange=UINT32(UINT32(cshpunit.v2nSize.i16nHeight())<<9);
		AUTO					pui8cdestination_hend=pui8cdestination+cui32nhrange;
		AUTO					cpui8cdestination_vend=pui8cdestination+cui32nvrange;
		CAUTO					cui32nhnext=UINT32(0x00200-cui32nhrange);
		AUTO					v2doffset=cshpunit.v2iPosition-cv2iorigin;
		CAUTO					ci16doffsetorigin=v2doffset.i16iX();

		for(;pui8cdestination<cpui8cdestination_vend;pui8cdestination+=cui32nhnext){
			while(pui8cdestination<pui8cdestination_hend){
				CAUTO					cui16ccolor0=cfp_brushThis(v2doffset,stui16cGetColorBack0(PCUINT16(pui8cdestination+0)),cpobject);

				++v2doffset.i16iX();
				{
					CAUTO					cui16ccolor1=cfp_brushThis(v2doffset,stui16cGetColorBack1(PCUINT16(pui8cdestination+0)),cpobject);
					CAUTO					cui8ir=UINT8((UINT8((cui16ccolor0>>0)&0xf)<<4)|((cui16ccolor1>>0)&0xf));
					CAUTO					cui8ig=UINT8((UINT8((cui16ccolor0>>4)&0xf)<<4)|((cui16ccolor1>>4)&0xf));
					CAUTO					cui8ib=UINT8((UINT8((cui16ccolor0>>8)&0xf)<<4)|((cui16ccolor1>>8)&0xf));

					++v2doffset.i16iX();
					if constexpr(cui8nAlignBit==8){
						pui8cdestination[0x000000]=cui8ir;
						pui8cdestination[0x020000]=cui8ig;
						pui8cdestination[0x040000]=cui8ib;
						++pui8cdestination;
					}else{
						CAUTO					cui16ccolor2=cfp_brushThis(v2doffset,stui16cGetColorBack0(PCUINT16(pui8cdestination+1)),cpobject);

						++v2doffset.i16iX();
						{
							CAUTO					cui16ccolor3=cfp_brushThis(v2doffset,stui16cGetColorBack1(PCUINT16(pui8cdestination+1)),cpobject);
							CAUTO					cui16ir=(UINT16(cui8ir)<<8)|(((cui16ccolor2>>0)&0xf)<<4)|((cui16ccolor3>>0)&0xf);
							CAUTO					cui16ig=(UINT16(cui8ig)<<8)|(((cui16ccolor2>>4)&0xf)<<4)|((cui16ccolor3>>4)&0xf);
							CAUTO					cui16ib=(UINT16(cui8ib)<<8)|(((cui16ccolor2>>8)&0xf)<<4)|((cui16ccolor3>>8)&0xf);

							++v2doffset.i16iX();
							if constexpr(cui8nAlignBit==16){
								*PUINT16(pui8cdestination+0x000000)=cui16ir;
								*PUINT16(pui8cdestination+0x020000)=cui16ig;
								*PUINT16(pui8cdestination+0x040000)=cui16ib;
								pui8cdestination+=2;
							}else{
								CAUTO					cui16ccolor4=cfp_brushThis(v2doffset,stui16cGetColorBack0(PCUINT16(pui8cdestination+2)),cpobject);

								++v2doffset.i16iX();
								{
									CAUTO					cui16ccolor5=cfp_brushThis(v2doffset,stui16cGetColorBack1(PCUINT16(pui8cdestination+2)),cpobject);

									++v2doffset.i16iX();
									{
										CAUTO					cui16ccolor6=cfp_brushThis(v2doffset,stui16cGetColorBack0(PCUINT16(pui8cdestination+3)),cpobject);

										++v2doffset.i16iX();
										{
											CAUTO					cui16ccolor7=cfp_brushThis(v2doffset,stui16cGetColorBack1(PCUINT16(pui8cdestination+3)),cpobject);
											CAUTO					cui32ir=(UINT32(cui16ir)<<16)|(((cui16ccolor4>>0)&0xf)<<12)|(((cui16ccolor5>>0)&0xf)<<8)|(((cui16ccolor6>>0)&0xf)<<4)|((cui16ccolor7>>0)&0xf);
											CAUTO					cui32ig=(UINT32(cui16ig)<<16)|(((cui16ccolor4>>4)&0xf)<<12)|(((cui16ccolor5>>4)&0xf)<<8)|(((cui16ccolor6>>4)&0xf)<<4)|((cui16ccolor7>>4)&0xf);
											CAUTO					cui32ib=(UINT32(cui16ib)<<16)|(((cui16ccolor4>>8)&0xf)<<12)|(((cui16ccolor5>>8)&0xf)<<8)|(((cui16ccolor6>>8)&0xf)<<4)|((cui16ccolor7>>8)&0xf);

											++v2doffset.i16iX();
											if constexpr(cui8nAlignBit==32){
												*PUINT32(pui8cdestination+0x000000)=cui32ir;
												*PUINT32(pui8cdestination+0x020000)=cui32ig;
												*PUINT32(pui8cdestination+0x040000)=cui32ib;
												pui8cdestination+=4;
											}
										}
									}
								}
							}
						}
					}
				}
			}
			pui8cdestination_hend+=0x00200;
			v2doffset.i16iX()=ci16doffsetorigin;
			++v2doffset.i16iY();
		}
	}
	return;
}

template<const GRAPHIC::FP_BRUSH cfp_brushThis,const GRAPHIC::IDPART cidPart,CUINT8 cui8nAlignBit,const GRAPHIC::IDSIDE cidSide>
VOID					GRAPHIC::stProcessFraction(
	CVECTOR2&				cv2iorigin,
	CSHAPE&					cshppart,
	const PVOID				cpobject
)noexcept{
	if(
		CAUTO					cshpfraction=cshppart.shpMakeFraction<cui8nAlignBit,cidSide>();
		cshpfraction.v2nSize.i16nWidth()
	){
		AUTO					pui8cdestination=stpui8cGetDestination<cidPart>(cshpfraction.v2iPosition);
		CAUTO					cui32nrange=UINT32(UINT32(cshpfraction.v2nSize.i16nHeight())<<9);
		AUTO					cpui8cdestination_end=pui8cdestination+cui32nrange;
		CAUTO					cui32nnext=UINT32(0x20000-cui32nrange);
		AUTO					v2doffset=cshpfraction.v2iPosition-cv2iorigin;

		for(;pui8cdestination<cpui8cdestination_end;pui8cdestination+=0x200){
			if constexpr(cui8nAlignBit==4){
				if constexpr(cidSide==IDSIDE::Left){
					CAUTO					cui16ccolor0=cfp_brushThis(v2doffset,stui16cGetColorBack1(PCUINT16(pui8cdestination+0)),cpobject);
					CAUTO					cui4ir=UINT8((cui16ccolor0>>0)&0xf);
					CAUTO					cui4ig=UINT8((cui16ccolor0>>4)&0xf);
					CAUTO					cui4ib=UINT8((cui16ccolor0>>8)&0xf);

					pui8cdestination[0x000000]=(pui8cdestination[0x000000]&0xf0)|cui4ir;
					pui8cdestination[0x020000]=(pui8cdestination[0x020000]&0xf0)|cui4ig;
					pui8cdestination[0x040000]=(pui8cdestination[0x040000]&0xf0)|cui4ib;
				}else{
					CAUTO					cui16ccolor0=cfp_brushThis(v2doffset,stui16cGetColorBack0(PCUINT16(pui8cdestination+0)),cpobject);
					CAUTO					cui4ir=UINT8((cui16ccolor0>>0)&0xf);
					CAUTO					cui4ig=UINT8((cui16ccolor0>>4)&0xf);
					CAUTO					cui4ib=UINT8((cui16ccolor0>>8)&0xf);

					pui8cdestination[0x000000]=(pui8cdestination[0x000000]&0x0f)|(cui4ir<<4);
					pui8cdestination[0x020000]=(pui8cdestination[0x020000]&0x0f)|(cui4ig<<4);
					pui8cdestination[0x040000]=(pui8cdestination[0x040000]&0x0f)|(cui4ib<<4);
				}
			}else{
				CAUTO					cui16ccolor0=cfp_brushThis(v2doffset,stui16cGetColorBack0(PCUINT16(pui8cdestination+0)),cpobject);
				CAUTO					cui4ir=UINT8((cui16ccolor0>>0)&0xf);
				CAUTO					cui4ig=UINT8((cui16ccolor0>>4)&0xf);
				CAUTO					cui4ib=UINT8((cui16ccolor0>>8)&0xf);
				CAUTO					cui16ccolor1=cfp_brushThis({INT16(v2doffset.i16iX()+1),v2doffset.i16iY()},stui16cGetColorBack1(PCUINT16(pui8cdestination+0)),cpobject);
				CAUTO					cui8ir=UINT8((cui4ir<<4)|((cui16ccolor1>>0)&0xf));
				CAUTO					cui8ig=UINT8((cui4ig<<4)|((cui16ccolor1>>4)&0xf));
				CAUTO					cui8ib=UINT8((cui4ib<<4)|((cui16ccolor1>>8)&0xf));

				if constexpr(cui8nAlignBit==8){
					pui8cdestination[0x000000]=cui8ir;
					pui8cdestination[0x020000]=cui8ig;
					pui8cdestination[0x040000]=cui8ib;
				}else{
					CAUTO					cui16ccolor2=cfp_brushThis({INT16(v2doffset.i16iX()+2),v2doffset.i16iY()},stui16cGetColorBack0(PCUINT16(pui8cdestination+1)),cpobject);
					CAUTO					cui16ccolor3=cfp_brushThis({INT16(v2doffset.i16iX()+3),v2doffset.i16iY()},stui16cGetColorBack1(PCUINT16(pui8cdestination+1)),cpobject);
					CAUTO					cui16ir=(UINT16(cui8ir)<<8)|(((cui16ccolor2>>0)&0xf)<<4)|((cui16ccolor3>>0)&0xf);
					CAUTO					cui16ig=(UINT16(cui8ig)<<8)|(((cui16ccolor2>>4)&0xf)<<4)|((cui16ccolor3>>4)&0xf);
					CAUTO					cui16ib=(UINT16(cui8ib)<<8)|(((cui16ccolor2>>8)&0xf)<<4)|((cui16ccolor3>>8)&0xf);

					if constexpr(cui8nAlignBit==16){
						*PUINT16(pui8cdestination+0x000000)=cui16ir;
						*PUINT16(pui8cdestination+0x020000)=cui16ig;
						*PUINT16(pui8cdestination+0x040000)=cui16ib;
					}
				}
			}
			++v2doffset.i16iY();
		}
	}
	return;
}
