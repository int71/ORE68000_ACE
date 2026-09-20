/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/canvas_.cpp'								2026 written by int71	**
 ****************************************************************************/

//
//		include
//

#include				"canvas_.hpp"

//
//		using
//

using namespace m68k::i71::sub;

//
//		class:CANVAS
//

//	protected

template<COFWBOOL ceDestinationAlpha>
VOID					CANVAS_::RGBX_stFill(
	const PUINT8			cpui8cdestinationbase,
	CUINT32					cui32idestinationdotposition,
	CUINT32					cui32ddestinationdotoffsetend,
	CUINT16					cui16ndestinationhdotline,
	CUINT16					cui16ndestinationlinepitch,
	CUINT32					cui32ndestinationplanepitch,
	CUINT16					cui16ccolor,
	const IDBLEND			cidblend
)noexcept{
	switch(cidblend){
	case IDBLEND::Source:
		RGBX_stFill_Blend<ceDestinationAlpha,IDBLEND::Source>(cpui8cdestinationbase,cui32idestinationdotposition,cui32ddestinationdotoffsetend,cui16ndestinationhdotline,cui16ndestinationlinepitch,cui32ndestinationplanepitch,cui16ccolor);
		break;
	case IDBLEND::BackNega_Source:
		RGBX_stFill_Blend<ceDestinationAlpha,IDBLEND::BackNega_Source>(cpui8cdestinationbase,cui32idestinationdotposition,cui32ddestinationdotoffsetend,cui16ndestinationhdotline,cui16ndestinationlinepitch,cui32ndestinationplanepitch,cui16ccolor);
		break;
	case IDBLEND::BackNega_SourceAlpha:
		RGBX_stFill_Blend<ceDestinationAlpha,IDBLEND::BackNega_SourceAlpha>(cpui8cdestinationbase,cui32idestinationdotposition,cui32ddestinationdotoffsetend,cui16ndestinationhdotline,cui16ndestinationlinepitch,cui32ndestinationplanepitch,cui16ccolor);
		break;
	}
	return;
}

template<COFWBOOL ceDestinationAlpha>
VOID					CANVAS_::RGBX_stFillAlpha(
	const PUINT8			cpui8cdestinationbase,
	CUINT32					cui32idestinationdotposition,
	CUINT32					cui32ddestinationdotoffsetend,
	CUINT16					cui16ndestinationhdotline,
	CUINT16					cui16ndestinationlinepitch,
	CUINT32					cui32ndestinationplanepitch,
	CUINT16					cui16ccolor,
	const PCUINT8			cpcui8csourcea,
	CUINT32					cui32isourcedotposition,
	CUINT16					cui16nsourcelinepitch,
	const IDBLEND			cidblend
)noexcept{
	switch(cidblend){
	case IDBLEND::Source:
		RGBX_stFillAlpha_Blend<ceDestinationAlpha,IDBLEND::Source>(cpui8cdestinationbase,cui32idestinationdotposition,cui32ddestinationdotoffsetend,cui16ndestinationhdotline,cui16ndestinationlinepitch,cui32ndestinationplanepitch,cui16ccolor,cpcui8csourcea,cui32isourcedotposition,cui16nsourcelinepitch);
		break;
	case IDBLEND::BackNega_Source:
		RGBX_stFillAlpha_Blend<ceDestinationAlpha,IDBLEND::BackNega_Source>(cpui8cdestinationbase,cui32idestinationdotposition,cui32ddestinationdotoffsetend,cui16ndestinationhdotline,cui16ndestinationlinepitch,cui32ndestinationplanepitch,cui16ccolor,cpcui8csourcea,cui32isourcedotposition,cui16nsourcelinepitch);
		break;
	case IDBLEND::BackNega_SourceAlpha:
		RGBX_stFillAlpha_Blend<ceDestinationAlpha,IDBLEND::BackNega_SourceAlpha>(cpui8cdestinationbase,cui32idestinationdotposition,cui32ddestinationdotoffsetend,cui16ndestinationhdotline,cui16ndestinationlinepitch,cui32ndestinationplanepitch,cui16ccolor,cpcui8csourcea,cui32isourcedotposition,cui16nsourcelinepitch);
		break;
	}
	return;
}

template<COFWBOOL ceDestinationAlpha,COFWBOOL ceSourceAlpha>
VOID					CANVAS_::RGBX_stCopy(
	const PUINT8			cpui8cdestinationbase,
	CUINT32					cui32idestinationdotposition,
	CUINT32					cui32ddestinationdotoffsetend,
	CUINT16					cui16ndestinationhdotline,
	CUINT16					cui16ndestinationlinepitch,
	CUINT32					cui32ndestinationplanepitch,
	const PCUINT8			cpcui8csourcebase,
	CUINT32					cui32isourcedotposition,
	CUINT16					cui16nsourcelinepitch,
	CUINT32					cui32nsourceplanepitch,
	const IDBLEND			cidblend
)noexcept{
	switch(cidblend){
	case IDBLEND::Source:
		RGBX_stCopy_Blend<ceDestinationAlpha,ceSourceAlpha,IDBLEND::Source>(cpui8cdestinationbase,cui32idestinationdotposition,cui32ddestinationdotoffsetend,cui16ndestinationhdotline,cui16ndestinationlinepitch,cui32ndestinationplanepitch,cpcui8csourcebase,cui32isourcedotposition,cui16nsourcelinepitch,cui32nsourceplanepitch);
		break;
	case IDBLEND::BackNega_Source:
		RGBX_stCopy_Blend<ceDestinationAlpha,ceSourceAlpha,IDBLEND::BackNega_Source>(cpui8cdestinationbase,cui32idestinationdotposition,cui32ddestinationdotoffsetend,cui16ndestinationhdotline,cui16ndestinationlinepitch,cui32ndestinationplanepitch,cpcui8csourcebase,cui32isourcedotposition,cui16nsourcelinepitch,cui32nsourceplanepitch);
		break;
	case IDBLEND::BackNega_SourceAlpha:
		RGBX_stCopy_Blend<ceDestinationAlpha,ceSourceAlpha,IDBLEND::BackNega_SourceAlpha>(cpui8cdestinationbase,cui32idestinationdotposition,cui32ddestinationdotoffsetend,cui16ndestinationhdotline,cui16ndestinationlinepitch,cui32ndestinationplanepitch,cpcui8csourcebase,cui32isourcedotposition,cui16nsourcelinepitch,cui32nsourceplanepitch);
		break;
	}
	return;
}

template<COFWBOOL ceDestinationAlpha>
VOID					CANVAS_::RGBX_stCopyAlpha(
	const PUINT8			cpui8cdestinationbase,
	CUINT32					cui32idestinationdotposition,
	CUINT32					cui32ddestinationdotoffsetend,
	CUINT16					cui16ndestinationhdotline,
	CUINT16					cui16ndestinationlinepitch,
	CUINT32					cui32ndestinationplanepitch,
	const PCUINT8			cpcui8csourcebase,
	const PCUINT8			cpcui8csourcea,
	CUINT32					cui32isourcedotposition,
	CUINT16					cui16nsourcelinepitch,
	CUINT32					cui32nsourceplanepitch,
	const IDBLEND			cidblend
)noexcept{
	switch(cidblend){
	case IDBLEND::Source:
		RGBX_stCopyAlpha_Blend<ceDestinationAlpha,IDBLEND::Source>(cpui8cdestinationbase,cui32idestinationdotposition,cui32ddestinationdotoffsetend,cui16ndestinationhdotline,cui16ndestinationlinepitch,cui32ndestinationplanepitch,cpcui8csourcebase,cpcui8csourcea,cui32isourcedotposition,cui16nsourcelinepitch,cui32nsourceplanepitch);
		break;
	case IDBLEND::BackNega_Source:
		RGBX_stCopyAlpha_Blend<ceDestinationAlpha,IDBLEND::BackNega_Source>(cpui8cdestinationbase,cui32idestinationdotposition,cui32ddestinationdotoffsetend,cui16ndestinationhdotline,cui16ndestinationlinepitch,cui32ndestinationplanepitch,cpcui8csourcebase,cpcui8csourcea,cui32isourcedotposition,cui16nsourcelinepitch,cui32nsourceplanepitch);
		break;
	case IDBLEND::BackNega_SourceAlpha:
		RGBX_stCopyAlpha_Blend<ceDestinationAlpha,IDBLEND::BackNega_SourceAlpha>(cpui8cdestinationbase,cui32idestinationdotposition,cui32ddestinationdotoffsetend,cui16ndestinationhdotline,cui16ndestinationlinepitch,cui32ndestinationplanepitch,cpcui8csourcebase,cpcui8csourcea,cui32isourcedotposition,cui16nsourcelinepitch,cui32nsourceplanepitch);
		break;
	}
	return;
}

VOID					CANVAS_::A_stFill(
	const PUINT8			cpui8cdestination,
	CUINT32					cui32idestinationdotposition,
	CUINT32					cui32ddestinationdotoffsetend,
	CUINT16					cui16ndestinationhdotline,
	CUINT16					cui16ndestinationlinepitch,
	CUINT8					cui8ialpha
)noexcept{
	CAUTO					cui32ndestinationlinedotpitch=UINT32(cui16ndestinationlinepitch<<1);
	AUTO					ui32idestinationdotposition=cui32idestinationdotposition;
	AUTO					ui32csource=UINT32(cui8ialpha&0x000f);

	ui32csource|=ui32csource<<4;
	ui32csource|=ui32csource<<8;
	ui32csource|=ui32csource<<16;
	for(
		CAUTO					cui32idestination_end=ui32idestinationdotposition+cui32ddestinationdotoffsetend;
		ui32idestinationdotposition<cui32idestination_end;
		ui32idestinationdotposition+=cui32ndestinationlinedotpitch
	)A_stFill_Line(
		cpui8cdestination,
		ui32idestinationdotposition,
		cui16ndestinationhdotline,
		ui32csource
	);
	return;
}

VOID					CANVAS_::A_stCopy(
	const PUINT8			cpui8cdestination,
	CUINT32					cui32idestinationdotposition,
	CUINT32					cui32ddestinationdotoffsetend,
	CUINT16					cui16ndestinationhdotline,
	CUINT16					cui16ndestinationlinepitch,
	const PCUINT8			cpcui8csource,
	CUINT32					cui32isourcedotposition,
	CUINT16					cui16nsourcelinepitch
)noexcept{
	CAUTO					cui32ndestinationlinedotpitch=UINT32(cui16ndestinationlinepitch<<1);
	CAUTO					cui32nsourcelinedotpitch=UINT32(cui16nsourcelinepitch<<1);
	AUTO					ui32idestinationdotposition=cui32idestinationdotposition;
	AUTO					ui32isourcedotposition=cui32isourcedotposition;

	for(
		CAUTO					cui32idestination_end=ui32idestinationdotposition+cui32ddestinationdotoffsetend;
		ui32idestinationdotposition<cui32idestination_end;
		ui32idestinationdotposition+=cui32ndestinationlinedotpitch
	){
		A_stCopy_Line(
			cpui8cdestination,
			ui32idestinationdotposition,
			cui16ndestinationhdotline,
			cpcui8csource,
			ui32isourcedotposition
		);
		ui32isourcedotposition+=cui32nsourcelinedotpitch;
	}
	return;
}

//	private

template<CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::stMakePrevious_Offset(
	CUINT32					cui32idestinationdotposition,
	const PCUINT8			cpcui8csource,
	UINT32&					ui32csource_previous
)noexcept{
	//	参照ドット位置の差が2の倍数ですらないなら、ビットシフト必須。
	//	であれば、せめてもの抗いとして32bit単位にまとめる。
	//	そこでビットシフト用「旧値」たる「ui32csource?_previous」の準備をする。
	//	アライン、効率で洗ってみると、単純なルールにはならない模様なので地道に場合分け。
	if constexpr(cui8nOffsetDot<3){
		//	<cui8nOffsetDot:1>
		//		cui32idestination下位3bit:0
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|           |   |             32|
		//			|           |--X|D-D-D-D-D-D-D-D|
		//			|               |x D-D-D-D-D-D-D|d
		//		cui32idestination下位3bit:1
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			| 4R|  8|     16|             32|
		//			|R-R|B-B|W-W-W-W|D-D-D-D-D-D-D-D|
		//			|  R|r B|b W-W-W|w D-D-D-D-D-D-D|d
		//		cui32idestination下位3bit:2
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|   |  8|     16|             32|
		//			|--X|B-B|W-W-W-W|D-D-D-D-D-D-D-D|
		//			|   |x B|b W-W-W|w D-D-D-D-D-D-D|d
		//		cui32idestination下位3bit:3
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|   | 4R|     16|             32|
		//			|   |R-R|W-W-W-W|D-D-D-D-D-D-D-D|
		//			|   |  R|r W-W-W|w D-D-D-D-D-D-D|d
		//		cui32idestination下位3bit:4
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|   |   |     16|             32|
		//			|   |--X|W-W-W-W|D-D-D-D-D-D-D-D|
		//			|       |x W-W-W|w D-D-D-D-D-D-D|d
		//		cui32idestination下位3bit:5
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|       | 4R|  8|             32|
		//			|       |R-R|B-B|D-D-D-D-D-D-D-D|
		//			|       |  R|r B|b D-D-D-D-D-D-D|d
		//		cui32idestination下位3bit:6
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|       |   |  8|             32|
		//			|       |--X|B-B|D-D-D-D-D-D-D-D|
		//			|       |   |x B|w D-D-D-D-D-D-D|d
		//		cui32idestination下位3bit:7
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|           | 4R|             32|
		//			|           |R-R|D-D-D-D-D-D-D-D|
		//			|           |  R|r D-D-D-D-D-D-D|d
		if((cui32idestinationdotposition&1)==0){
			ui32csource_previous=UINT32(*(cpcui8csource-1));
		}
	}else if constexpr(cui8nOffsetDot<5){
		//	<cui8nOffsetDot:3>
		//		cui32idestination下位3bit:0
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|       |       |             32|
		//			|       |--X-X-X|D-D-D-D-D-D-D-D|
		//			|               |x x x D-D-D-D-D|d d d
		//		cui32idestination下位3bit:1
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|           |   | 4R|  8|     16|
		//			|           |X-X|R-R|B-B|W-W-W-W|
		//			|               |  x|x r|r b b W|w w w
		//		cui32idestination下位3bit:2
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|           |   |   |  8|     16|
		//			|           |--X|X-X|B-B|W-W-W-W|
		//			|               |   |x x|x b b W|w w w
		//		cui32idestination下位3bit:3
		//			|0-1 2-3 4-5 6-7|
		//			|   | 4R|     16|
		//			|X-X|R-R|W-W-W-W|
		//			|   |  x|x r r W|w w w
		//		cui32idestination下位3bit:4
		//			|0-1 2-3 4-5 6-7|
		//			|       |     16|
		//			|--X-X-X|W-W-W-W|
		//			|       |x x x W|w w w
		//		cui32idestination下位3bit:5
		//			|0-1 2-3 4-5 6-7|
		//			|   |   | 4R|  8|
		//			|   |X-X|R-R|B-B|
		//			|   |   |  x|x r|r b b
		//		cui32idestination下位3bit:6
		//			|0-1 2-3 4-5 6-7|
		//			|   |   |   |  8|
		//			|   |--X|X-X|B-B|
		//			|   |   |   |x x|x b b
		//		cui32idestination下位3bit:7
		//			|0-1 2-3 4-5 6-7|
		//			|       |   | 4R|
		//			|       |X-X|R-R|
		//			|       |   |  x|x x r
		switch(cui32idestinationdotposition&7){
		case 0:
			FALLTHROUGH;
		case 4:
			ui32csource_previous=UINT32(*PUINT16(cpcui8csource-2));
			break;
		case 1:
			FALLTHROUGH;
		case 3:
			FALLTHROUGH;
		case 5:
			FALLTHROUGH;
		case 7:
			ui32csource_previous=UINT32(*(cpcui8csource-1));
			break;
		case 2:
			FALLTHROUGH;
		case 6:
			ui32csource_previous=(UINT32(*(cpcui8csource-2))<<8)|UINT32(*(cpcui8csource-1));
			break;
		}
	}else if constexpr(cui8nOffsetDot<7){
		//	<cui8nOffsetDot:5>
		//		cui32idestination下位3bit:0
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|   |   |       |             32|
		//			|   |--X|X-X-X-X|D-D-D-D-D-D-D-D|
		//			|               |x x x x x D D D|d d d d d
		//		cui32idestination下位3bit:1
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|       |       | 4R|  8|     16|             32|
		//			|       |X-X-X-X|R-R|B-B|W-W-W-W|D-D-D-D-D-D-D-D|
		//			|               |  x|x x|x r r b|b w w w w D D D|d d d d d
		//		cui32idestination下位3bit:2
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|       |       |   |  8|     16|             32|
		//			|       |--X-X-X|X-X|B-B|W-W-W-W|D-D-D-D-D-D-D-D|
		//			|               |   |x x|x x x b|b w w w w D D D|d d d d d
		//		cui32idestination下位3bit:3
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|           |   |   | 4R|     16|             32|
		//			|           |X-X|X-X|R-R|W-W-W-W|D-D-D-D-D-D-D-D|
		//			|               |   |  x|x x x r|r w w w w D D D|d d d d d
		//		cui32idestination下位3bit:4
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|           |   |       |     16|             32|
		//			|           |--X|X-X-X-X|W-W-W-W|D-D-D-D-D-D-D-D|
		//			|               |       |x x x x|x w w w w D D D|d d d d d
		//		cui32idestination下位3bit:5
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|               |       | 4R|  8|             32|
		//			|               |X-X-X-X|R-R|B-B|D-D-D-D-D-D-D-D|
		//			|               |       |  x x x|x r r b b D D D|d d d d d
		//		cui32idestination下位3bit:6
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|               |       |   |  8|             32|
		//			|               |--X-X-X|X-X|B-B|D-D-D-D-D-D-D-D|
		//			|               |       |    x x|x x x b b D D D|d d d d d
		//		cui32idestination下位3bit:7
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|   |   |   | 4R|             32|
		//			|   |X-X|X-X|R-R|D-D-D-D-D-D-D-D|
		//			|   |   |      x|x x x r r D D D|d d d d d
		switch(cui32idestinationdotposition&7){
		case 0:
			FALLTHROUGH;
		case 4:
			ui32csource_previous=(UINT32(*(cpcui8csource-3))<<16)|UINT32(*PUINT16(cpcui8csource-2));
			break;
		case 1:
			FALLTHROUGH;
		case 5:
			ui32csource_previous=UINT32(*PUINT16(cpcui8csource-2));
			break;
		case 2:
			FALLTHROUGH;
		case 6:
			ui32csource_previous=(UINT32(*PUINT16(cpcui8csource-3))<<8)|UINT32(*(cpcui8csource-1));
			break;
		case 3:
			FALLTHROUGH;
		case 7:
			ui32csource_previous=(UINT32(*(cpcui8csource-2))<<8)|UINT32(*(cpcui8csource-1));
			break;
		}
	}else{
		//	<cui8nOffsetDot:7>
		//		cui32idestination下位3bit:0
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|               |             32|
		//			|--X-X-X-X-X-X-X|D-D-D-D-D-D-D-D|
		//			|               |x x x x x x x D|d d d d d d d
		//		cui32idestination下位3bit:1
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|   |   |       | 4R|  8|     16|             32|
		//			|   |X-X|X-X-X-X|R-R|B-B|W-W-W-W|D-D-D-D-D-D-D-D|
		//			|               |  x|x x|x x x r|r b b w w w w D|d d d d d d d
		//		cui32idestination下位3bit:2
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|   |   |       |   |  8|     16|             32|
		//			|   |--X|X-X-X-X|X-X|B-B|W-W-W-W|D-D-D-D-D-D-D-D|
		//			|               |   |x x|x x x x|x b b w w w w D|d d d d d d d
		//		cui32idestination下位3bit:3
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|       |       |   | 4R|     16|             32|
		//			|       |X-X-X-X|X-X|R-R|W-W-W-W|D-D-D-D-D-D-D-D|
		//			|               |   |  x|x x x x|x r r w w w w D|d d d d d d d
		//		cui32idestination下位3bit:4
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|       |       |       |     16|             32|
		//			|       |--X-X-X|X-X-X-X|W-W-W-W|D-D-D-D-D-D-D-D|
		//			|               |       |x x x x|x x x w w w w D|d d d d d d d
		//		cui32idestination下位3bit:5
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|           |   |       | 4R|  8|             32|
		//			|           |X-X|X-X-X-X|R-R|B-B|D-D-D-D-D-D-D-D|
		//			|               |       |  x x x|x x x r r b b D|d d d d d d d
		//		cui32idestination下位3bit:6
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|           |   |       |   |  8|             32|
		//			|           |--X|X-X-X-X|X-X|B-B|D-D-D-D-D-D-D-D|
		//			|               |       |    x x|x x x x x b b D|d d d d d d d
		//		cui32idestination下位3bit:7
		//			|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//			|       |   | 4R|             32|
		//			|X-X-X-X|X-X|R-R|D-D-D-D-D-D-D-D|
		//			|       |      x|x x x x x r r D|d d d d d d d
		switch(cui32idestinationdotposition&7){
		case 0:
			ui32csource_previous=*PUINT32(cpcui8csource-4);
			break;
		case 1:
			FALLTHROUGH;
		case 5:
			ui32csource_previous=(UINT32(*(cpcui8csource-3))<<16)|UINT32(*PUINT16(cpcui8csource-2));
			break;
		case 2:
			FALLTHROUGH;
		case 6:
			ui32csource_previous=(UINT32(*(cpcui8csource-4))<<24)|(UINT32(*PUINT16(cpcui8csource-3))<<8)|UINT32(*(cpcui8csource-1));
			break;
		case 3:
			FALLTHROUGH;
		case 7:
			ui32csource_previous=(UINT32(*PUINT16(cpcui8csource-3))<<8)|UINT32(*(cpcui8csource-1));
			break;
		case 4:
			ui32csource_previous=(UINT32(*PUINT16(cpcui8csource-4))<<16)|UINT32(*PUINT16(cpcui8csource-2));
			break;
		}
	}
	return;
}

//	定数塗りつぶし(RGB*)

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend>
_INLINE_ VOID			CANVAS_::RGBX_stFill_Blend(
	const PUINT8			cpui8cdestinationbase,
	CUINT32					cui32idestinationdotposition,
	CUINT32					cui32ddestinationdotoffsetend,
	CUINT16					cui16ndestinationhdotline,
	CUINT16					cui16ndestinationlinepitch,
	CUINT32					cui32ndestinationplanepitch,
	CUINT16					cui16ccolor
)noexcept{
	CAUTO					cui32ndestinationlinedotpitch=UINT32(cui16ndestinationlinepitch<<1);
	AUTO					ui32idestinationdotposition=cui32idestinationdotposition;
	AUTO					ui32csourcer=UINT32(cui16ccolor&0x000f);
	AUTO					ui32csourceg=UINT32(cui16ccolor&0x00f0);
	AUTO					ui32csourceb=UINT32(cui16ccolor&0x0f00);
	AUTO					ui32csourcea=UINT32(cui16ccolor&0xf000);

	ui32csourcer|=ui32csourcer<<4;
	ui32csourcer|=ui32csourcer<<8;
	ui32csourcer|=ui32csourcer<<16;
	ui32csourceg|=ui32csourceg>>4;
	ui32csourceg|=ui32csourceg<<8;
	ui32csourceg|=ui32csourceg<<16;
	ui32csourceb|=ui32csourceb<<4;
	ui32csourceb|=ui32csourceb>>8;
	ui32csourceb|=ui32csourceb<<16;
	ui32csourcea|=ui32csourcea>>4;
	ui32csourcea|=ui32csourcea>>8;
	ui32csourcea|=ui32csourcea<<16;
	for(
		CAUTO					cui32idestination_end=ui32idestinationdotposition+cui32ddestinationdotoffsetend;
		ui32idestinationdotposition<cui32idestination_end;
		ui32idestinationdotposition+=cui32ndestinationlinedotpitch
	)RGBX_stFill_Blend_Line<ceDestinationAlpha,cidBlend>(
		cpui8cdestinationbase,
		ui32idestinationdotposition,
		cui16ndestinationhdotline,
		cui32ndestinationplanepitch,
		ui32csourcer,ui32csourceg,ui32csourceb,ui32csourcea
	);
	return;
}

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend>
_INLINE_ VOID			CANVAS_::RGBX_stFill_Blend_Line(
	const PUINT8			cpui8cdestinationbase,
	CUINT32					cui32idestinationdotposition,
	CUINT16					cui16ndestinationhdotline,
	CUINT32					cui32ndestinationplanepitch,
	CUINT32					cui32csourcer,
	CUINT32					cui32csourceg,
	CUINT32					cui32csourceb,
	CUINT32					cui32csourcea
)noexcept{
	if(cui16ndestinationhdotline){
		AUTO					pui8cdestination=cpui8cdestinationbase+(cui32idestinationdotposition>>1);
		//	PUINT8					cpui8cdestination_end
		//		コピー終了条件に使いますが、注意すべきは「右端数1ドット」を含まない事。
		//		含めてしまうと、「2、4、8ドットコピー可」と誤認されてしまう。
		//		「右端数1ドット」があるかどうかは「(cui32idestinationdotposition+cui32ndestinationhdotline)&1」で判定する。
		AUTO					cpui8cdestination_end=cpui8cdestinationbase+((cui32idestinationdotposition+UINT32(cui16ndestinationhdotline))>>1);
		CAUTO					cfp_fraction4l=[&](VOID)noexcept{
			//	終了位置に「端数1ドット」あるなら、残りを解消。
			//	1バイト未満で「pui8cdestination」には現れないので、
			//	「(cui32idestinationdotposition+cui32ndestinationhdotline)&1」で判定。
			//	ここまでで1ドット超過の端数は処理済みであるので、
			//	「pui8cdestination」のような進行状況変数を見る必要は無い。
			if((UINT8(cui32idestinationdotposition)+UINT8(cui16ndestinationhdotline))&1){
				RGBX_stFill_Blend_Line_Bit4L<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,UINT8(cui32csourcer),UINT8(cui32csourceg),UINT8(cui32csourceb),UINT8(cui32csourcea));
			}
			return;
		};
		CAUTO					cfp_fraction8=[&](VOID)noexcept{
			//	終了位置に「端数2～4ドット」あるなら、「2ドット(1バイト)」分解消。
			if(pui8cdestination+1<=cpui8cdestination_end){
				RGBX_stFill_Blend_Line_Bit8<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,UINT8(cui32csourcer),UINT8(cui32csourceg),UINT8(cui32csourceb),UINT8(cui32csourcea));
			}
			cfp_fraction4l();
			return;
		};
		CAUTO					cfp_fraction16=[&](VOID)noexcept{
			//	終了位置に「端数4～8ドット」あるなら、「4ドット(2バイト)」分解消。
			if(pui8cdestination+2<=cpui8cdestination_end){
				RGBX_stFill_Blend_Line_Bit16<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,UINT16(cui32csourcer),UINT16(cui32csourceg),UINT16(cui32csourceb),UINT16(cui32csourcea));
			}
			cfp_fraction8();
			return;
		};

		//	まずは「左端数1ドット」があるか判定するが、
		//	「pui8cdestination」には現れないので「cui32ndestinationdotposition」で判定する。
		//	これは更新前の処理初段であるから通用する方法。
		if(cui32idestinationdotposition&1){
			//	開始位置に「端数1ドット」があるので、それを解消する。
			RGBX_stFill_Blend_Line_Bit4R<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,UINT8(cui32csourcer),UINT8(cui32csourceg),UINT8(cui32csourceb),UINT8(cui32csourcea));
		}
		//	この時点で処理対象位置は2の倍数になっている。
		if(PTRINT(pui8cdestination)&1){
			//	開始位置に「端数2ドット(1バイト)」があるので、それを解消する。
			if(cpui8cdestination_end<pui8cdestination+1){
				cfp_fraction4l();
				return;
			}
			RGBX_stFill_Blend_Line_Bit8<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,UINT8(cui32csourcer),UINT8(cui32csourceg),UINT8(cui32csourceb),UINT8(cui32csourcea));
		}
		//	この時点で処理対象位置は4の倍数になっている。
		if(PTRINT(pui8cdestination)&2){
			//	開始位置に「端数4ドット(2バイト)」があるので、それを解消する。
			if(cpui8cdestination_end<pui8cdestination+2){
				cfp_fraction8();
				return;
			}
			RGBX_stFill_Blend_Line_Bit16<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,UINT16(cui32csourcer),UINT16(cui32csourceg),UINT16(cui32csourceb),UINT16(cui32csourcea));
		}
		//	この時点で処理対象位置は8の倍数になっている。
		if(pui8cdestination+4<=cpui8cdestination_end){
			CAUTO					cpui8cdestination_endm4=cpui8cdestination_end-4;

			while(pui8cdestination<=cpui8cdestination_endm4)RGBX_stFill_Blend_Line_Bit32<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32csourcer,cui32csourceg,cui32csourceb,cui32csourcea);
		}
		cfp_fraction16();
	}
	return;
}

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend>
_INLINE_ VOID			CANVAS_::RGBX_stFill_Blend_Line_Bit4L(
	PUINT8&					pui8cdestination,
	CUINT32					cui32ndestinationplanepitch,
	CUINT8					cui8csourcer,
	CUINT8					cui8csourceg,
	CUINT8					cui8csourceb,
	CUINT8					cui8csourcea
)noexcept{
	constexpr AUTO			cfp_blend_bit4lthis=stfp_blend_bit4lGetThis<cidBlend>();
	CAUTO					cpui8cdestinationr=pui8cdestination;
	CAUTO					cpui8cdestinationg=cpui8cdestinationr+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationb=cpui8cdestinationg+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationa=cpui8cdestinationb+cui32ndestinationplanepitch;
	AUTO&					ui8cdestinationr=*cpui8cdestinationr;
	AUTO&					ui8cdestinationg=*cpui8cdestinationg;
	AUTO&					ui8cdestinationb=*cpui8cdestinationb;

	cfp_blend_bit4lthis(ui8cdestinationr,cui8csourcer,cui8csourcea);
	cfp_blend_bit4lthis(ui8cdestinationg,cui8csourceg,cui8csourcea);
	cfp_blend_bit4lthis(ui8cdestinationb,cui8csourceb,cui8csourcea);
	if constexpr(ceDestinationAlpha){
		AUTO&					ui8cdestinationa=*cpui8cdestinationa;

		ui8cdestinationa=(ui8cdestinationa&0x0f)|(cui8csourcea&0xf0);
	}
	return;
}

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend>
_INLINE_ VOID			CANVAS_::RGBX_stFill_Blend_Line_Bit4R(
	PUINT8&					pui8cdestination,
	CUINT32					cui32ndestinationplanepitch,
	CUINT8					cui8csourcer,
	CUINT8					cui8csourceg,
	CUINT8					cui8csourceb,
	CUINT8					cui8csourcea
)noexcept{
	constexpr AUTO			cfp_blend_bit4rthis=stfp_blend_bit4rGetThis<cidBlend>();
	CAUTO					cpui8cdestinationr=pui8cdestination;
	CAUTO					cpui8cdestinationg=cpui8cdestinationr+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationb=cpui8cdestinationg+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationa=cpui8cdestinationb+cui32ndestinationplanepitch;
	AUTO&					ui8cdestinationr=*cpui8cdestinationr;
	AUTO&					ui8cdestinationg=*cpui8cdestinationg;
	AUTO&					ui8cdestinationb=*cpui8cdestinationb;

	cfp_blend_bit4rthis(ui8cdestinationr,cui8csourcer,cui8csourcea);
	cfp_blend_bit4rthis(ui8cdestinationg,cui8csourceg,cui8csourcea);
	cfp_blend_bit4rthis(ui8cdestinationb,cui8csourceb,cui8csourcea);
	if constexpr(ceDestinationAlpha){
		AUTO&					ui8cdestinationa=*cpui8cdestinationa;

		ui8cdestinationa=(ui8cdestinationa&0xf0)|(cui8csourcea&0x0f);
	}
	++pui8cdestination;
	return;
}

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend>
_INLINE_ VOID			CANVAS_::RGBX_stFill_Blend_Line_Bit8(
	PUINT8&					pui8cdestination,
	CUINT32					cui32ndestinationplanepitch,
	CUINT8					cui8csourcer,
	CUINT8					cui8csourceg,
	CUINT8					cui8csourceb,
	CUINT8					cui8csourcea
)noexcept{
	constexpr AUTO			cfp_blend_bit8this=stfp_blend_bit8GetThis<cidBlend>();
	CAUTO					cpui8cdestinationr=pui8cdestination;
	CAUTO					cpui8cdestinationg=cpui8cdestinationr+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationb=cpui8cdestinationg+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationa=cpui8cdestinationb+cui32ndestinationplanepitch;
	AUTO&					ui8cdestinationr=*cpui8cdestinationr;
	AUTO&					ui8cdestinationg=*cpui8cdestinationg;
	AUTO&					ui8cdestinationb=*cpui8cdestinationb;

	cfp_blend_bit8this(ui8cdestinationr,cui8csourcer,cui8csourcea);
	cfp_blend_bit8this(ui8cdestinationg,cui8csourceg,cui8csourcea);
	cfp_blend_bit8this(ui8cdestinationb,cui8csourceb,cui8csourcea);
	if constexpr(ceDestinationAlpha){
		AUTO&					ui8cdestinationa=*cpui8cdestinationa;

		ui8cdestinationa=cui8csourcea;
	}
	++pui8cdestination;
	return;
}

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend>
_INLINE_ VOID			CANVAS_::RGBX_stFill_Blend_Line_Bit16(
	PUINT8&					pui8cdestination,
	CUINT32					cui32ndestinationplanepitch,
	CUINT16					cui16csourcer,
	CUINT16					cui16csourceg,
	CUINT16					cui16csourceb,
	CUINT16					cui16csourcea
)noexcept{
	constexpr AUTO			cfp_blend_bit16this=stfp_blend_bit16GetThis<cidBlend>();
	CAUTO					cpui8cdestinationr=pui8cdestination;
	CAUTO					cpui8cdestinationg=cpui8cdestinationr+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationb=cpui8cdestinationg+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationa=cpui8cdestinationb+cui32ndestinationplanepitch;
	AUTO&					ui16cdestinationr=*PUINT16(cpui8cdestinationr);
	AUTO&					ui16cdestinationg=*PUINT16(cpui8cdestinationg);
	AUTO&					ui16cdestinationb=*PUINT16(cpui8cdestinationb);

	cfp_blend_bit16this(ui16cdestinationr,cui16csourcer,cui16csourcea);
	cfp_blend_bit16this(ui16cdestinationg,cui16csourceg,cui16csourcea);
	cfp_blend_bit16this(ui16cdestinationb,cui16csourceb,cui16csourcea);
	if constexpr(ceDestinationAlpha){
		AUTO&					ui16cdestinationa=*PUINT16(cpui8cdestinationa);

		ui16cdestinationa=cui16csourcea;
	}
	pui8cdestination+=2;
	return;
}

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend>
_INLINE_ VOID			CANVAS_::RGBX_stFill_Blend_Line_Bit32(
	PUINT8&					pui8cdestination,
	CUINT32					cui32ndestinationplanepitch,
	CUINT32					cui32csourcer,
	CUINT32					cui32csourceg,
	CUINT32					cui32csourceb,
	CUINT32					cui32csourcea
)noexcept{
	constexpr AUTO			cfp_blend_bit32this=stfp_blend32GetThis<cidBlend>();
	CAUTO					cpui8cdestinationr=pui8cdestination;
	CAUTO					cpui8cdestinationg=cpui8cdestinationr+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationb=cpui8cdestinationg+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationa=cpui8cdestinationb+cui32ndestinationplanepitch;
	AUTO&					ui32cdestinationr=*PUINT32(cpui8cdestinationr);
	AUTO&					ui32cdestinationg=*PUINT32(cpui8cdestinationg);
	AUTO&					ui32cdestinationb=*PUINT32(cpui8cdestinationb);

	cfp_blend_bit32this(ui32cdestinationr,cui32csourcer,cui32csourcea);
	cfp_blend_bit32this(ui32cdestinationg,cui32csourceg,cui32csourcea);
	cfp_blend_bit32this(ui32cdestinationb,cui32csourceb,cui32csourcea);
	if constexpr(ceDestinationAlpha){
		AUTO&					ui32cdestinationa=*PUINT32(cpui8cdestinationa);

		ui32cdestinationa=cui32csourcea;
	}
	pui8cdestination+=4;
	return;
}

//	別アルファ画像使用定数塗りつぶし

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend>
_INLINE_ VOID			CANVAS_::RGBX_stFillAlpha_Blend(
	const PUINT8			cpui8cdestinationbase,
	CUINT32					cui32idestinationdotposition,
	CUINT32					cui32ddestinationdotoffsetend,
	CUINT16					cui16ndestinationhdotline,
	CUINT16					cui16ndestinationlinepitch,
	CUINT32					cui32ndestinationplanepitch,
	CUINT16					cui16ccolor,
	const PCUINT8			cpcui8csourcea,
	CUINT32					cui32isourcedotposition,
	CUINT16					cui16nsourcelinepitch
)noexcept{
	CAUTO					cui32ndestinationlinedotpitch=UINT32(cui16ndestinationlinepitch<<1);
	CAUTO					cui32nsourcelinedotpitch=UINT32(cui16nsourcelinepitch<<1);
	AUTO					ui32idestinationdotposition=cui32idestinationdotposition;
	AUTO					ui32isourcedotposition=cui32isourcedotposition;
	AUTO					ui32csourcer=UINT32(cui16ccolor&0x000f);
	AUTO					ui32csourceg=UINT32(cui16ccolor&0x00f0);
	AUTO					ui32csourceb=UINT32(cui16ccolor&0x0f00);

	ui32csourcer|=ui32csourcer<<4;
	ui32csourcer|=ui32csourcer<<8;
	ui32csourcer|=ui32csourcer<<16;
	ui32csourceg|=ui32csourceg>>4;
	ui32csourceg|=ui32csourceg<<8;
	ui32csourceg|=ui32csourceg<<16;
	ui32csourceb|=ui32csourceb<<4;
	ui32csourceb|=ui32csourceb>>8;
	ui32csourceb|=ui32csourceb<<16;
	for(
		CAUTO					cui32idestination_end=ui32idestinationdotposition+cui32ddestinationdotoffsetend;
		ui32idestinationdotposition<cui32idestination_end;
		ui32idestinationdotposition+=cui32ndestinationlinedotpitch
	)RGBX_stFillAlpha_Blend_Line<ceDestinationAlpha,cidBlend>(
		cpui8cdestinationbase,
		ui32idestinationdotposition,
		cui16ndestinationhdotline,
		cui32ndestinationplanepitch,
		ui32csourcer,ui32csourceg,ui32csourceb,
		cpcui8csourcea,
		ui32isourcedotposition
	);
	return;
}

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend>
_INLINE_ VOID			CANVAS_::RGBX_stFillAlpha_Blend_Line(
	const PUINT8			cpui8cdestinationbase,
	CUINT32					cui32idestinationdotposition,
	CUINT16					cui16ndestinationhdotline,
	CUINT32					cui32ndestinationplanepitch,
	CUINT32					cui32csourcer,
	CUINT32					cui32csourceg,
	CUINT32					cui32csourceb,
	const PCUINT8			cpcui8csourcea,
	CUINT32					cui32isourcedotposition
)noexcept{
	switch(UINT8(cui32idestinationdotposition-cui32isourcedotposition)&7){
	case 0:
		RGBX_stFillAlpha_Blend_Line_Offset<ceDestinationAlpha,cidBlend,0>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cui32csourcer,cui32csourceg,cui32csourceb,cpcui8csourcea,cui32isourcedotposition);
		break;
	case 1:
		RGBX_stFillAlpha_Blend_Line_Offset<ceDestinationAlpha,cidBlend,1>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cui32csourcer,cui32csourceg,cui32csourceb,cpcui8csourcea,cui32isourcedotposition);
		break;
	case 2:
		RGBX_stFillAlpha_Blend_Line_Offset<ceDestinationAlpha,cidBlend,2>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cui32csourcer,cui32csourceg,cui32csourceb,cpcui8csourcea,cui32isourcedotposition);
		break;
	case 3:
		RGBX_stFillAlpha_Blend_Line_Offset<ceDestinationAlpha,cidBlend,3>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cui32csourcer,cui32csourceg,cui32csourceb,cpcui8csourcea,cui32isourcedotposition);
		break;
	case 4:
		RGBX_stFillAlpha_Blend_Line_Offset<ceDestinationAlpha,cidBlend,4>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cui32csourcer,cui32csourceg,cui32csourceb,cpcui8csourcea,cui32isourcedotposition);
		break;
	case 5:
		RGBX_stFillAlpha_Blend_Line_Offset<ceDestinationAlpha,cidBlend,5>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cui32csourcer,cui32csourceg,cui32csourceb,cpcui8csourcea,cui32isourcedotposition);
		break;
	case 6:
		RGBX_stFillAlpha_Blend_Line_Offset<ceDestinationAlpha,cidBlend,6>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cui32csourcer,cui32csourceg,cui32csourceb,cpcui8csourcea,cui32isourcedotposition);
		break;
	case 7:
		RGBX_stFillAlpha_Blend_Line_Offset<ceDestinationAlpha,cidBlend,7>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cui32csourcer,cui32csourceg,cui32csourceb,cpcui8csourcea,cui32isourcedotposition);
		break;
	}
	return;
}

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend,CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::RGBX_stFillAlpha_Blend_Line_Offset(
	const PUINT8			cpui8cdestinationbase,
	CUINT32					cui32idestinationdotposition,
	CUINT16					cui16ndestinationhdotline,
	CUINT32					cui32ndestinationplanepitch,
	CUINT32					cui32csourcer,
	CUINT32					cui32csourceg,
	CUINT32					cui32csourceb,
	const PCUINT8			cpcui8csourcea,
	CUINT32					cui32isourcedotposition
)noexcept{
	if(cui16ndestinationhdotline){
		AUTO					pui8cdestination=cpui8cdestinationbase+(cui32idestinationdotposition>>1);
		//	PUINT8					cpui8cdestination_end
		//		コピー終了条件に使いますが、注意すべきは「右端数1ドット」を含まない事。
		//		含めてしまうと、「2、4、8ドットコピー可」と誤認されてしまう。
		//		「右端数1ドット」があるかどうかは「(cui32idestinationdotposition+cui32ndestinationhdotline)&1」で判定する。
		AUTO					cpui8cdestination_end=cpui8cdestinationbase+((cui32idestinationdotposition+UINT32(cui16ndestinationhdotline))>>1);
		CAUTO					cui32isourceposition=UINT32((cui32isourcedotposition+UINT32((cui8nOffsetDot&1)?cui8nOffsetDot:UINT8(0)))>>1);
		CAUTO					cpcui8csourcea_positioned=cpcui8csourcea+cui32isourceposition;
		CAUTO					cui32doffsetsourcea=UINT32(cpcui8csourcea_positioned-pui8cdestination);

		if constexpr((cui8nOffsetDot&1)==0){
			CAUTO					cfp_fraction4l=[&](VOID)noexcept{
				//	終了位置に「端数1ドット」あるなら、残りを解消。
				//	1バイト未満で「pui8cdestination」には現れないので、
				//	「(cui32idestinationdotposition+cui32ndestinationhdotline)&1」で判定。
				//	ここまでで1ドット超過の端数は処理済みであるので、
				//	「pui8cdestination」のような進行状況変数を見る必要は無い。
				if((UINT8(cui32idestinationdotposition)+UINT8(cui16ndestinationhdotline))&1){
					RGBX_stFillAlpha_Blend_Line_Offset_Bit4L<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,UINT8(cui32csourcer),UINT8(cui32csourceg),UINT8(cui32csourceb),cui32doffsetsourcea);
				}
				return;
			};
			CAUTO					cfp_fraction8=[&](VOID)noexcept{
				//	終了位置に「端数2～4ドット」あるなら、「2ドット(1バイト)」分解消。
				if(pui8cdestination+1<=cpui8cdestination_end){
					RGBX_stFillAlpha_Blend_Line_Offset_Bit8<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,UINT8(cui32csourcer),UINT8(cui32csourceg),UINT8(cui32csourceb),cui32doffsetsourcea);
				}
				cfp_fraction4l();
				return;
			};
			CAUTO					cfp_fraction16=[&](VOID)noexcept{
				//	終了位置に「端数4～8ドット」あるなら、「4ドット(2バイト)」分解消。
				if(pui8cdestination+2<=cpui8cdestination_end){
					RGBX_stFillAlpha_Blend_Line_Offset_Bit16<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,UINT16(cui32csourcer),UINT16(cui32csourceg),UINT16(cui32csourceb),cui32doffsetsourcea);
				}
				cfp_fraction8();
				return;
			};

			//	参照ドット位置の差は2の倍数なので、最悪でもバイト単位転送にはできる。
			//	「ビットシフトありの4バイト単位処理」と「ビットシフト無しの1バイト単位処理」のどちらが速いか定かでないが、
			//	一旦「ビットシフト無しの方が速い」とする。
			//	まずは「左端数1ドット」があるか判定するが、
			//	「pui8cdestination」には現れないので「cui32ndestinationdotposition」で判定する。
			//	これは更新前の処理初段であるから通用する方法。
			if(cui32idestinationdotposition&1){
				//	差は2の倍数なれど、開始位置に「端数1ドット」があるので、それを解消する。
				RGBX_stFillAlpha_Blend_Line_Offset_Bit4R<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,UINT8(cui32csourcer),UINT8(cui32csourceg),UINT8(cui32csourceb),cui32doffsetsourcea);
			}
			//	この時点で参照ドット位置の差、処理対象位置共に2の倍数になっている。
			if constexpr((cui8nOffsetDot&2)==0){
				//	参照ドット位置の差は4の倍数なので、最悪でもワード単位転送にはできる。
				if(PTRINT(pui8cdestination)&1){
					//	差は4の倍数なれど、開始位置に「端数2ドット(1バイト)」があるので、それを解消する。
					if(cpui8cdestination_end<pui8cdestination+1){
						cfp_fraction4l();
						return;
					}
					RGBX_stFillAlpha_Blend_Line_Offset_Bit8<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,UINT8(cui32csourcer),UINT8(cui32csourceg),UINT8(cui32csourceb),cui32doffsetsourcea);
				}
				//	この時点で参照ドット位置の差、処理対象位置共に4の倍数になっている。
				if constexpr((cui8nOffsetDot&4)==0){
					//	参照ドット位置の差は8の倍数なので、ダブルワード単位転送にできる。
					if(PTRINT(pui8cdestination)&2){
						//	差は8の倍数なれど、開始位置に「端数4ドット(2バイト)」があるので、それを解消する。
						if(cpui8cdestination_end<pui8cdestination+2){
							cfp_fraction8();
							return;
						}
						RGBX_stFillAlpha_Blend_Line_Offset_Bit16<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,UINT16(cui32csourcer),UINT16(cui32csourceg),UINT16(cui32csourceb),cui32doffsetsourcea);
					}
					//	この時点で参照ドット位置の差、処理対象位置共に8の倍数になっている。
					if(pui8cdestination+4<=cpui8cdestination_end){
						CAUTO					cpui8cdestination_endm4=cpui8cdestination_end-4;

						while(pui8cdestination<=cpui8cdestination_endm4)RGBX_stFillAlpha_Blend_Line_Offset_Bit32<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32csourcer,cui32csourceg,cui32csourceb,cui32doffsetsourcea);
					}
					cfp_fraction16();
				}else{
					//	差は4の倍数なれど8の倍数ではなかった。
					if(pui8cdestination+2<=cpui8cdestination_end){
						CAUTO					cpui8cdestination_endm2=cpui8cdestination_end-2;

						while(pui8cdestination<=cpui8cdestination_endm2)RGBX_stFillAlpha_Blend_Line_Offset_Bit16<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32csourcer,cui32csourceg,cui32csourceb,cui32doffsetsourcea);
					}
					cfp_fraction8();
				}
			}else{
				//	差は2の倍数なれど4の倍数ではなかった。
				if(pui8cdestination+1<=cpui8cdestination_end){
					CAUTO					cpui8cdestination_endm1=cpui8cdestination_end-1;

					while(pui8cdestination<=cpui8cdestination_endm1)RGBX_stFillAlpha_Blend_Line_Offset_Bit8<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32csourcer,cui32csourceg,cui32csourceb,cui32doffsetsourcea);
				}
				cfp_fraction4l();
			}
		}else{
			UINT32					ui32csourcea_previous=0x00000000;
			CAUTO					cfp_fraction4l=[&](VOID)noexcept{
				//	終了位置に「端数1ドット」あるなら、残りを解消。
				//	1バイト未満で「pui8cdestination」には現れないので、
				//	「(cui32idestinationdotposition+cui32ndestinationhdotline)&1」で判定。
				//	ここまでで1ドット超過の端数は処理済みであるので、
				//	「pui8cdestination」のような進行状況変数を見る必要は無い。
				if((UINT8(cui32idestinationdotposition)+UINT8(cui16ndestinationhdotline))&1){
					RGBX_stFillAlpha_Blend_Line_Offset_Bit4L<ceDestinationAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,UINT8(cui32csourcer),UINT8(cui32csourceg),UINT8(cui32csourceb),cui32doffsetsourcea,&ui32csourcea_previous);
				}
				return;
			};
			CAUTO					cfp_fraction8=[&](VOID)noexcept{
				//	終了位置に「端数2～4ドット」あるなら、「2ドット(1バイト)」分解消。
				if(pui8cdestination+1<=cpui8cdestination_end){
					RGBX_stFillAlpha_Blend_Line_Offset_Bit8<ceDestinationAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,UINT8(cui32csourcer),UINT8(cui32csourceg),UINT8(cui32csourceb),cui32doffsetsourcea,&ui32csourcea_previous);
				}
				cfp_fraction4l();
				return;
			};
			CAUTO					cfp_fraction16=[&](VOID)noexcept{
				//	終了位置に「端数4～8ドット」あるなら、「4ドット(2バイト)」分解消。
				if(pui8cdestination+2<=cpui8cdestination_end){
					RGBX_stFillAlpha_Blend_Line_Offset_Bit16<ceDestinationAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,UINT16(cui32csourcer),UINT16(cui32csourceg),UINT16(cui32csourceb),cui32doffsetsourcea,&ui32csourcea_previous);
				}
				cfp_fraction8();
				return;
			};

			stMakePrevious_Offset<cui8nOffsetDot>(cui32idestinationdotposition,cpcui8csourcea_positioned,ui32csourcea_previous);
			//	書き込み位置32bitアラインを目指し、「左側端数ドット」をコピーする。
			//	まずは「左端数1ドット」があるか判定するが、
			//	「pui8cdestination」には現れないので「cui32ndestinationdotposition」で判定する。
			//	これは更新前の処理初段であるから通用する方法。
			if(cui32idestinationdotposition&1){
				RGBX_stFillAlpha_Blend_Line_Offset_Bit4R<ceDestinationAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,UINT8(cui32csourcer),UINT8(cui32csourceg),UINT8(cui32csourceb),cui32doffsetsourcea,&ui32csourcea_previous);
			}
			if(PTRINT(pui8cdestination)&1){
				if(cpui8cdestination_end<pui8cdestination+1){
					cfp_fraction4l();
					return;
				}
				RGBX_stFillAlpha_Blend_Line_Offset_Bit8<ceDestinationAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,UINT8(cui32csourcer),UINT8(cui32csourceg),UINT8(cui32csourceb),cui32doffsetsourcea,&ui32csourcea_previous);
			}
			if(PTRINT(pui8cdestination)&2){
				if(cpui8cdestination_end<pui8cdestination+2){
					cfp_fraction8();
					return;
				}
				RGBX_stFillAlpha_Blend_Line_Offset_Bit16<ceDestinationAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,UINT16(cui32csourcer),UINT16(cui32csourceg),UINT16(cui32csourceb),cui32doffsetsourcea,&ui32csourcea_previous);
			}
			//	書き込み位置32bitアラインできたのでコピーループに入る。
			if(pui8cdestination+4<=cpui8cdestination_end){
				CAUTO					cpui8cdestination_endm4=cpui8cdestination_end-4;

				while(pui8cdestination<=cpui8cdestination_endm4)RGBX_stFillAlpha_Blend_Line_Offset_Bit32<ceDestinationAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,cui32csourcer,cui32csourceg,cui32csourceb,cui32doffsetsourcea,&ui32csourcea_previous);
			}
			//	32bitアラインコピー出来る分は全て片付けたので、「右側端数ドット」をコピーする。
			cfp_fraction16();
		}
	}
	return;
}

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend,CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::RGBX_stFillAlpha_Blend_Line_Offset_Bit4L(
	PUINT8&					pui8cdestination,
	CUINT32					cui32ndestinationplanepitch,
	CUINT8					cui8csourcer,
	CUINT8					cui8csourceg,
	CUINT8					cui8csourceb,
	CUINT32					cui32doffsetsourcea,
	const PUINT32			cpui32csourcea_previous
)noexcept{
	constexpr AUTO			cfp_blend_bit4lthis=stfp_blend_bit4lGetThis<cidBlend>();
	CAUTO					cpui8cdestinationr=pui8cdestination;
	CAUTO					cpui8cdestinationg=cpui8cdestinationr+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationb=cpui8cdestinationg+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationa=cpui8cdestinationb+cui32ndestinationplanepitch;
	AUTO&					ui8cdestinationr=*cpui8cdestinationr;
	AUTO&					ui8cdestinationg=*cpui8cdestinationg;
	AUTO&					ui8cdestinationb=*cpui8cdestinationb;

	if constexpr(cui8nOffsetDot==0){
		CAUTO					cpcui8csourcea=PCUINT8(pui8cdestination+cui32doffsetsourcea);
		CAUTO					cui8csourcea=*cpcui8csourcea;

		cfp_blend_bit4lthis(ui8cdestinationr,cui8csourcer,cui8csourcea);
		cfp_blend_bit4lthis(ui8cdestinationg,cui8csourceg,cui8csourcea);
		cfp_blend_bit4lthis(ui8cdestinationb,cui8csourceb,cui8csourcea);
		if constexpr(ceDestinationAlpha){
			AUTO&					ui8cdestinationa=*cpui8cdestinationa;

			ui8cdestinationa=(ui8cdestinationa&0x0f)|(cui8csourcea&0xf0);
		}
	}else{
		constexpr AUTO			cui8nshiftbitr=UINT8(cui8nOffsetDot<<2);
		constexpr AUTO			cui8nshiftbitr_previous=UINT8(cui8nshiftbitr-4);
		CAUTO					cui32csourcea_previous=*cpui32csourcea_previous;
		CAUTO					cui8csourcea_merged=UINT8((cui32csourcea_previous>>cui8nshiftbitr_previous)<<4);

		//	<cui8nOffsetDot:1>
		//		previous:--------------X
		//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//		|           |   | 4L|
		//		|           |--X|   |
		//		|               |x  |
		//		previous:---------------
		//	<cui8nOffsetDot:7>
		//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//		previous:--------------X
		//		|               | 4L|
		//		|X              |   |
		//		|               |x  |
		//		previous:---------------
		cfp_blend_bit4lthis(ui8cdestinationr,cui8csourcer,cui8csourcea_merged);
		cfp_blend_bit4lthis(ui8cdestinationg,cui8csourceg,cui8csourcea_merged);
		cfp_blend_bit4lthis(ui8cdestinationb,cui8csourceb,cui8csourcea_merged);
		if constexpr(ceDestinationAlpha){
			AUTO&					ui8cdestinationa=*cpui8cdestinationa;

			ui8cdestinationa=(ui8cdestinationa&0x0f)|(cui8csourcea_merged&0xf0);
		}
	}
	return;
}

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend,CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::RGBX_stFillAlpha_Blend_Line_Offset_Bit4R(
	PUINT8&					pui8cdestination,
	CUINT32					cui32ndestinationplanepitch,
	CUINT8					cui8csourcer,
	CUINT8					cui8csourceg,
	CUINT8					cui8csourceb,
	CUINT32					cui32doffsetsourcea,
	const PUINT32			cpui32csourcea_previous
)noexcept{
	constexpr AUTO			cfp_blend_bit4rthis=stfp_blend_bit4rGetThis<cidBlend>();
	CAUTO					cpui8cdestinationr=pui8cdestination;
	CAUTO					cpui8cdestinationg=cpui8cdestinationr+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationb=cpui8cdestinationg+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationa=cpui8cdestinationb+cui32ndestinationplanepitch;
	AUTO&					ui8cdestinationr=*cpui8cdestinationr;
	AUTO&					ui8cdestinationg=*cpui8cdestinationg;
	AUTO&					ui8cdestinationb=*cpui8cdestinationb;
	CAUTO					cpcui8csourcea=PCUINT8(pui8cdestination+cui32doffsetsourcea);
	CAUTO					cui8csourcea=*cpcui8csourcea;

	if constexpr(cui8nOffsetDot==0){
		cfp_blend_bit4rthis(ui8cdestinationr,cui8csourcer,cui8csourcea);
		cfp_blend_bit4rthis(ui8cdestinationg,cui8csourceg,cui8csourcea);
		cfp_blend_bit4rthis(ui8cdestinationb,cui8csourceb,cui8csourcea);
		if constexpr(ceDestinationAlpha){
			AUTO&					ui8cdestinationa=*cpui8cdestinationa;

			ui8cdestinationa=(ui8cdestinationa&0xf0)|(cui8csourcea&0x0f);
		}
	}else{
		constexpr AUTO			cui8nshiftbitr=UINT8(cui8nOffsetDot<<2);
		AUTO&					ui32csourcea_previous=*cpui32csourcea_previous;

		if constexpr(cui8nshiftbitr<8){
			CAUTO					cui8csourcea_merged=UINT8(cui8csourcea>>cui8nshiftbitr);

			//	<cui8nOffsetDot:1>
			//		previous:--------------X
			//		|0-1 2-3 4-5 6-7|
			//		| 4R|  8|     16|
			//		|R-R|B-B|W-W-W-W|
			//		|  R|r B|b W-W-W|w
			//		previous:--------------r
			cfp_blend_bit4rthis(ui8cdestinationr,cui8csourcer,cui8csourcea_merged);
			cfp_blend_bit4rthis(ui8cdestinationg,cui8csourceg,cui8csourcea_merged);
			cfp_blend_bit4rthis(ui8cdestinationb,cui8csourceb,cui8csourcea_merged);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui8cdestinationa=*cpui8cdestinationa;

				ui8cdestinationa=(ui8cdestinationa&0xf0)|(cui8csourcea_merged&0x0f);
			}
			ui32csourcea_previous=UINT32(cui8csourcea);
		}else{
			constexpr AUTO			cui8nshiftbitr_previous=UINT8(cui8nshiftbitr-8);
			CAUTO					cui8csourcea_merged=UINT8(ui32csourcea_previous>>cui8nshiftbitr_previous);

			//	<cui8nOffsetDot:7>
			//		previous:----X-X-X-X-X-X
			//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
			//		|   |   |       | 4R|  8|     16|
			//		|   |X-X|X-X-X-X|R-R|B-B|W-W-W-W|
			//		|               |  x|x x|x x x r|r b b w w w w
			//		previous:----X-X-X-X-r-r
			cfp_blend_bit4rthis(ui8cdestinationr,cui8csourcer,cui8csourcea_merged);
			cfp_blend_bit4rthis(ui8cdestinationg,cui8csourceg,cui8csourcea_merged);
			cfp_blend_bit4rthis(ui8cdestinationb,cui8csourceb,cui8csourcea_merged);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui8cdestinationa=*(cpui8cdestinationa);

				ui8cdestinationa=(ui8cdestinationa&0xf0)|(cui8csourcea_merged&0x0f);
			}
			ui32csourcea_previous=(ui32csourcea_previous<<8)|UINT32(cui8csourcea);
		}
	}
	++pui8cdestination;
	return;
}

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend,CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::RGBX_stFillAlpha_Blend_Line_Offset_Bit8(
	PUINT8&					pui8cdestination,
	CUINT32					cui32ndestinationplanepitch,
	CUINT8					cui8csourcer,
	CUINT8					cui8csourceg,
	CUINT8					cui8csourceb,
	CUINT32					cui32doffsetsourcea,
	const PUINT32			cpui32csourcea_previous
)noexcept{
	constexpr AUTO			cfp_blend_bit8this=stfp_blend_bit8GetThis<cidBlend>();
	CAUTO					cpui8cdestinationr=pui8cdestination;
	CAUTO					cpui8cdestinationg=cpui8cdestinationr+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationb=cpui8cdestinationg+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationa=cpui8cdestinationb+cui32ndestinationplanepitch;
	AUTO&					ui8cdestinationr=*cpui8cdestinationr;
	AUTO&					ui8cdestinationg=*cpui8cdestinationg;
	AUTO&					ui8cdestinationb=*cpui8cdestinationb;
	CAUTO					cpcui8csourcea=PCUINT8(pui8cdestination+cui32doffsetsourcea);
	CAUTO					cui8csourcea=*cpcui8csourcea;

	if constexpr(cui8nOffsetDot==0){
		cfp_blend_bit8this(ui8cdestinationr,cui8csourcer,cui8csourcea);
		cfp_blend_bit8this(ui8cdestinationg,cui8csourceg,cui8csourcea);
		cfp_blend_bit8this(ui8cdestinationb,cui8csourceb,cui8csourcea);
		if constexpr(ceDestinationAlpha){
			AUTO&					ui8cdestinationa=*cpui8cdestinationa;

			ui8cdestinationa=cui8csourcea;
		}
	}else{
		constexpr AUTO			cui8nshiftbitr=UINT8(cui8nOffsetDot<<2);
		AUTO&					ui32csourcea_previous=*cpui32csourcea_previous;

		if constexpr(cui8nshiftbitr<8){
			constexpr AUTO			cui8nshiftbitl_previous=UINT8(8-cui8nshiftbitr);
			CAUTO					cui8csourcea_merged=UINT8((cui8csourcea>>cui8nshiftbitr)|UINT8(ui32csourcea_previous<<cui8nshiftbitl_previous));

			//	<cui8nOffsetDot:1>
			//		previous:--------------X
			//		|0-1 2-3 4-5 6-7|
			//		|   |  8|     16|
			//		|--X|B-B|W-W-W-W|
			//		|   |x B|b W-W-W|w
			//		previous:--------------b
			cfp_blend_bit8this(ui8cdestinationr,cui8csourcer,cui8csourcea_merged);
			cfp_blend_bit8this(ui8cdestinationg,cui8csourceg,cui8csourcea_merged);
			cfp_blend_bit8this(ui8cdestinationb,cui8csourceb,cui8csourcea_merged);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui8cdestinationa=*cpui8cdestinationa;

				ui8cdestinationa=cui8csourcea_merged;
			}
			ui32csourcea_previous=UINT32(cui8csourcea);
		}else{
			constexpr AUTO			cui8nshiftbitr_previous=UINT8(cui8nshiftbitr-8);
			CAUTO					cui8csourcea_merged=UINT8(ui32csourcea_previous>>cui8nshiftbitr_previous);

			//	<cui8nOffsetDot:7>
			//		previous:--X-X-X-X-X-X-X
			//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
			//		|   |   |       |   |  8|     16|
			//		|   |--X|X-X-X-X|X-X|B-B|W-W-W-W|
			//		|               |   |x x|x x x x|x b b w w w w
			//		previous:--x-x-x-x-x-b-b
			cfp_blend_bit8this(ui8cdestinationr,cui8csourcer,cui8csourcea_merged);
			cfp_blend_bit8this(ui8cdestinationg,cui8csourceg,cui8csourcea_merged);
			cfp_blend_bit8this(ui8cdestinationb,cui8csourceb,cui8csourcea_merged);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui8cdestinationa=*(cpui8cdestinationa);

				ui8cdestinationa=cui8csourcea_merged;
			}
			ui32csourcea_previous=(ui32csourcea_previous<<8)|UINT32(cui8csourcea);
		}
	}
	++pui8cdestination;
	return;
}

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend,CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::RGBX_stFillAlpha_Blend_Line_Offset_Bit16(
	PUINT8&					pui8cdestination,
	CUINT32					cui32ndestinationplanepitch,
	CUINT16					cui16csourcer,
	CUINT16					cui16csourceg,
	CUINT16					cui16csourceb,
	CUINT32					cui32doffsetsourcea,
	const PUINT32			cpui32csourcea_previous
)noexcept{
	constexpr AUTO			cfp_blend_bit16this=stfp_blend_bit16GetThis<cidBlend>();
	CAUTO					cpui8cdestinationr=pui8cdestination;
	CAUTO					cpui8cdestinationg=cpui8cdestinationr+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationb=cpui8cdestinationg+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationa=cpui8cdestinationb+cui32ndestinationplanepitch;
	AUTO&					ui16cdestinationr=*PUINT16(cpui8cdestinationr);
	AUTO&					ui16cdestinationg=*PUINT16(cpui8cdestinationg);
	AUTO&					ui16cdestinationb=*PUINT16(cpui8cdestinationb);
	CAUTO					cpcui8csourcea=PCUINT8(pui8cdestination+cui32doffsetsourcea);
	CAUTO					cui16csourcea=*PCUINT16(cpcui8csourcea);

	if constexpr(cui8nOffsetDot==0){
		cfp_blend_bit16this(ui16cdestinationr,cui16csourcer,cui16csourcea);
		cfp_blend_bit16this(ui16cdestinationg,cui16csourceg,cui16csourcea);
		cfp_blend_bit16this(ui16cdestinationb,cui16csourceb,cui16csourcea);
		if constexpr(ceDestinationAlpha){
			AUTO&					ui16cdestinationa=*PUINT16(cpui8cdestinationa);

			ui16cdestinationa=cui16csourcea;
		}
	}else{
		constexpr AUTO			cui8nshiftbitr=UINT8(cui8nOffsetDot<<2);
		AUTO&					ui32csourcea_previous=*cpui32csourcea_previous;

		if constexpr(cui8nshiftbitr<16){
			constexpr AUTO			cui8nshiftbitl_previous=UINT8(16-cui8nshiftbitr);
			CAUTO					cui16csourcea_merged=UINT16((cui16csourcea>>cui8nshiftbitr)|UINT16(ui32csourcea_previous<<cui8nshiftbitl_previous));

			//	<cui8nOffsetDot:1>
			//		previous:--------------X
			//		|0-1 2-3 4-5 6-7|
			//		|   |   |     16|
			//		|   |--X|W-W-W-W|
			//		|       |x W-W-W|w
			//		previous:--------------w
			cfp_blend_bit16this(ui16cdestinationr,cui16csourcer,cui16csourcea_merged);
			cfp_blend_bit16this(ui16cdestinationg,cui16csourceg,cui16csourcea_merged);
			cfp_blend_bit16this(ui16cdestinationb,cui16csourceb,cui16csourcea_merged);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui16cdestinationa=*PUINT16(cpui8cdestinationa);

				ui16cdestinationa=cui16csourcea_merged;
			}
			ui32csourcea_previous=UINT32(cui16csourcea);
		}else{
			constexpr AUTO			cui8nshiftbitr_previous=UINT8(cui8nshiftbitr-16);
			CAUTO					cui16csourcea_merged=UINT16(ui32csourcea_previous>>cui8nshiftbitr_previous);

			//	<cui8nOffsetDot:7>
			//		previous:--X-X-X-X-X-X-X
			//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
			//		|       |       |       |     16|
			//		|       |--X-X-X|X-X-X-X|W-W-W-W|
			//		|               |       |x x x x|x x x w w w w
			//		previous:--x-x-x-w-w-w-w
			cfp_blend_bit16this(ui16cdestinationr,cui16csourcer,cui16csourcea_merged);
			cfp_blend_bit16this(ui16cdestinationg,cui16csourceg,cui16csourcea_merged);
			cfp_blend_bit16this(ui16cdestinationb,cui16csourceb,cui16csourcea_merged);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui16cdestinationa=*PUINT16(cpui8cdestinationa);

				ui16cdestinationa=cui16csourcea_merged;
			}
			ui32csourcea_previous=(ui32csourcea_previous<<16)|UINT32(cui16csourcea);
		}
	}
	pui8cdestination+=2;
	return;
}

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend,CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::RGBX_stFillAlpha_Blend_Line_Offset_Bit32(
	PUINT8&					pui8cdestination,
	CUINT32					cui32ndestinationplanepitch,
	CUINT32					cui32csourcer,
	CUINT32					cui32csourceg,
	CUINT32					cui32csourceb,
	CUINT32					cui32doffsetsourcea,
	const PUINT32			cpui32csourcea_previous
)noexcept{
	constexpr AUTO			cfp_blend_bit32this=stfp_blend32GetThis<cidBlend>();
	CAUTO					cpui8cdestinationr=pui8cdestination;
	CAUTO					cpui8cdestinationg=cpui8cdestinationr+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationb=cpui8cdestinationg+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationa=cpui8cdestinationb+cui32ndestinationplanepitch;
	AUTO&					ui32cdestinationr=*PUINT32(cpui8cdestinationr);
	AUTO&					ui32cdestinationg=*PUINT32(cpui8cdestinationg);
	AUTO&					ui32cdestinationb=*PUINT32(cpui8cdestinationb);
	CAUTO					cpcui8csourcea=PCUINT8(pui8cdestination+cui32doffsetsourcea);
	CAUTO					cui32csourcea=*PCUINT32(cpcui8csourcea);

	if constexpr(cui8nOffsetDot==0){
		cfp_blend_bit32this(ui32cdestinationr,cui32csourcer,cui32csourcea);
		cfp_blend_bit32this(ui32cdestinationg,cui32csourceg,cui32csourcea);
		cfp_blend_bit32this(ui32cdestinationb,cui32csourceb,cui32csourcea);
		if constexpr(ceDestinationAlpha){
			AUTO&					ui32cdestinationa=*PUINT32(cpui8cdestinationa);

			ui32cdestinationa=cui32csourcea;
		}
	}else{
		constexpr AUTO			cui8nshiftbitr=UINT8(cui8nOffsetDot<<2);
		constexpr AUTO			cui8nshiftbitl_previous=UINT8(32-cui8nshiftbitr);
		AUTO&					ui32csourcea_previous=*cpui32csourcea_previous;
		CAUTO					cui32csourcea_merged=UINT32((cui32csourcea>>cui8nshiftbitr)|(ui32csourcea_previous<<cui8nshiftbitl_previous));

		//	<cui8nOffsetDot:1>
		//		previous:--------------X
		//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//		|           |   |             32|
		//		|           |--X|D-D-D-D-D-D-D-D|
		//		|               |x D-D-D-D-D-D-D|d
		//		previous:--------------d
		//	<cui8nOffsetDot:7>
		//		previous:--X-X-X-X-X-X-X
		//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//		|               |             32|
		//		|--X-X-X-X-X-X-X|D-D-D-D-D-D-D-D|
		//		|               |x x x x x x x D|d d d d d d d
		//		previous:--d-d-d-d-d-d-d
		cfp_blend_bit32this(ui32cdestinationr,cui32csourcer,cui32csourcea_merged);
		cfp_blend_bit32this(ui32cdestinationg,cui32csourceg,cui32csourcea_merged);
		cfp_blend_bit32this(ui32cdestinationb,cui32csourceb,cui32csourcea_merged);
		if constexpr(ceDestinationAlpha){
			AUTO&					ui32cdestinationa=*PUINT32(cpui8cdestinationa);

			ui32cdestinationa=cui32csourcea_merged;
		}
		ui32csourcea_previous=cui32csourcea;
	}
	pui8cdestination+=4;
	return;
}

//	画像コピー(RGB*)

template<COFWBOOL ceDestinationAlpha,COFWBOOL ceSourceAlpha,const CANVAS_::IDBLEND cidBlend>
_INLINE_ VOID			CANVAS_::RGBX_stCopy_Blend(
	const PUINT8			cpui8cdestinationbase,
	CUINT32					cui32idestinationdotposition,
	CUINT32					cui32ddestinationdotoffsetend,
	CUINT16					cui16ndestinationhdotline,
	CUINT16					cui16ndestinationlinepitch,
	CUINT32					cui32ndestinationplanepitch,
	const PCUINT8			cpcui8csourcebase,
	CUINT32					cui32isourcedotposition,
	CUINT16					cui16nsourcelinepitch,
	CUINT32					cui32nsourceplanepitch
)noexcept{
	CAUTO					cui32ndestinationlinedotpitch=UINT32(cui16ndestinationlinepitch<<1);
	CAUTO					cui32nsourcelinedotpitch=UINT32(cui16nsourcelinepitch<<1);
	AUTO					ui32idestinationdotposition=cui32idestinationdotposition;
	AUTO					ui32isourcedotposition=cui32isourcedotposition;

	for(
		CAUTO					cui32idestination_end=ui32idestinationdotposition+cui32ddestinationdotoffsetend;
		ui32idestinationdotposition<cui32idestination_end;
		ui32idestinationdotposition+=cui32ndestinationlinedotpitch
	){
		RGBX_stCopy_Blend_Line<ceDestinationAlpha,ceSourceAlpha,cidBlend>(
			cpui8cdestinationbase,
			ui32idestinationdotposition,
			cui16ndestinationhdotline,
			cui32ndestinationplanepitch,
			cpcui8csourcebase,
			ui32isourcedotposition,
			cui32nsourceplanepitch
		);
		ui32isourcedotposition+=cui32nsourcelinedotpitch;
	}
	return;
}

template<COFWBOOL ceDestinationAlpha,COFWBOOL ceSourceAlpha,const CANVAS_::IDBLEND cidBlend>
_INLINE_ VOID			CANVAS_::RGBX_stCopy_Blend_Line(
	const PUINT8			cpui8cdestinationbase,
	CUINT32					cui32idestinationdotposition,
	CUINT16					cui16ndestinationhdotline,
	CUINT32					cui32ndestinationplanepitch,
	const PCUINT8			cpcui8csourcebase,
	CUINT32					cui32isourcedotposition,
	CUINT32					cui32nsourceplanepitch
)noexcept{
	switch(UINT8(cui32idestinationdotposition-cui32isourcedotposition)&7){
	case 0:
		RGBX_stCopy_Blend_Line_Offset<ceDestinationAlpha,ceSourceAlpha,cidBlend,0>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cpcui8csourcebase,cui32isourcedotposition,cui32nsourceplanepitch);
		break;
	case 1:
		RGBX_stCopy_Blend_Line_Offset<ceDestinationAlpha,ceSourceAlpha,cidBlend,1>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cpcui8csourcebase,cui32isourcedotposition,cui32nsourceplanepitch);
		break;
	case 2:
		RGBX_stCopy_Blend_Line_Offset<ceDestinationAlpha,ceSourceAlpha,cidBlend,2>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cpcui8csourcebase,cui32isourcedotposition,cui32nsourceplanepitch);
		break;
	case 3:
		RGBX_stCopy_Blend_Line_Offset<ceDestinationAlpha,ceSourceAlpha,cidBlend,3>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cpcui8csourcebase,cui32isourcedotposition,cui32nsourceplanepitch);
		break;
	case 4:
		RGBX_stCopy_Blend_Line_Offset<ceDestinationAlpha,ceSourceAlpha,cidBlend,4>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cpcui8csourcebase,cui32isourcedotposition,cui32nsourceplanepitch);
		break;
	case 5:
		RGBX_stCopy_Blend_Line_Offset<ceDestinationAlpha,ceSourceAlpha,cidBlend,5>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cpcui8csourcebase,cui32isourcedotposition,cui32nsourceplanepitch);
		break;
	case 6:
		RGBX_stCopy_Blend_Line_Offset<ceDestinationAlpha,ceSourceAlpha,cidBlend,6>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cpcui8csourcebase,cui32isourcedotposition,cui32nsourceplanepitch);
		break;
	case 7:
		RGBX_stCopy_Blend_Line_Offset<ceDestinationAlpha,ceSourceAlpha,cidBlend,7>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cpcui8csourcebase,cui32isourcedotposition,cui32nsourceplanepitch);
		break;
	}
	return;
}

template<COFWBOOL ceDestinationAlpha,COFWBOOL ceSourceAlpha,const CANVAS_::IDBLEND cidBlend,CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::RGBX_stCopy_Blend_Line_Offset(
	const PUINT8			cpui8cdestinationbase,
	CUINT32					cui32idestinationdotposition,
	CUINT16					cui16ndestinationhdotline,
	CUINT32					cui32ndestinationplanepitch,
	const PCUINT8			cpcui8csourcebase,
	CUINT32					cui32isourcedotposition,
	CUINT32					cui32nsourceplanepitch
)noexcept{
	if(cui16ndestinationhdotline){
		AUTO					pui8cdestination=cpui8cdestinationbase+(cui32idestinationdotposition>>1);
		//	PUINT8					cpui8cdestination_end
		//		コピー終了条件に使いますが、注意すべきは「右端数1ドット」を含まない事。
		//		含めてしまうと、「2、4、8ドットコピー可」と誤認されてしまう。
		//		「右端数1ドット」があるかどうかは「(cui32idestinationdotposition+cui32ndestinationhdotline)&1」で判定する。
		AUTO					cpui8cdestination_end=cpui8cdestinationbase+((cui32idestinationdotposition+UINT32(cui16ndestinationhdotline))>>1);
		CAUTO					cui32isourceposition=UINT32((cui32isourcedotposition+UINT32((cui8nOffsetDot&1)?cui8nOffsetDot:UINT8(0)))>>1);
		CAUTO					cpcui8csourcebase_positioned=cpcui8csourcebase+cui32isourceposition;
		CAUTO					cui32doffsetsourcebase=UINT32(cpcui8csourcebase_positioned-pui8cdestination);

		if constexpr((cui8nOffsetDot&1)==0){
			CAUTO					cfp_fraction4l=[&](VOID)noexcept{
				//	終了位置に「端数1ドット」あるなら、残りを解消。
				//	1バイト未満で「pui8cdestination」には現れないので、
				//	「(cui32idestinationdotposition+cui32ndestinationhdotline)&1」で判定。
				//	ここまでで1ドット超過の端数は処理済みであるので、
				//	「pui8cdestination」のような進行状況変数を見る必要は無い。
				if((UINT8(cui32idestinationdotposition)+UINT8(cui16ndestinationhdotline))&1){
					RGBX_stCopy_Blend_Line_Offset_Bit4L<ceDestinationAlpha,ceSourceAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32nsourceplanepitch);
				}
				return;
			};
			CAUTO					cfp_fraction8=[&](VOID)noexcept{
				//	終了位置に「端数2～4ドット」あるなら、「2ドット(1バイト)」分解消。
				if(pui8cdestination+1<=cpui8cdestination_end){
					RGBX_stCopy_Blend_Line_Offset_Bit8<ceDestinationAlpha,ceSourceAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32nsourceplanepitch);
				}
				cfp_fraction4l();
				return;
			};
			CAUTO					cfp_fraction16=[&](VOID)noexcept{
				//	終了位置に「端数4～8ドット」あるなら、「4ドット(2バイト)」分解消。
				if(pui8cdestination+2<=cpui8cdestination_end){
					RGBX_stCopy_Blend_Line_Offset_Bit16<ceDestinationAlpha,ceSourceAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32nsourceplanepitch);
				}
				cfp_fraction8();
				return;
			};

			//	参照ドット位置の差は2の倍数なので、最悪でもバイト単位転送にはできる。
			//	「ビットシフトありの4バイト単位処理」と「ビットシフト無しの1バイト単位処理」のどちらが速いか定かでないが、
			//	一旦「ビットシフト無しの方が速い」とする。
			//	まずは「左端数1ドット」があるか判定するが、
			//	「pui8cdestination」には現れないので「cui32ndestinationdotposition」で判定する。
			//	これは更新前の処理初段であるから通用する方法。
			if(cui32idestinationdotposition&1){
				//	差は2の倍数なれど、開始位置に「端数1ドット」があるので、それを解消する。
				RGBX_stCopy_Blend_Line_Offset_Bit4R<ceDestinationAlpha,ceSourceAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32nsourceplanepitch);
			}
			//	この時点で参照ドット位置の差、処理対象位置共に2の倍数になっている。
			if constexpr((cui8nOffsetDot&2)==0){
				//	参照ドット位置の差は4の倍数なので、最悪でもワード単位転送にはできる。
				if(PTRINT(pui8cdestination)&1){
					//	差は4の倍数なれど、開始位置に「端数2ドット(1バイト)」があるので、それを解消する。
					if(cpui8cdestination_end<pui8cdestination+1){
						cfp_fraction4l();
						return;
					}
					RGBX_stCopy_Blend_Line_Offset_Bit8<ceDestinationAlpha,ceSourceAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32nsourceplanepitch);
				}
				//	この時点で参照ドット位置の差、処理対象位置共に4の倍数になっている。
				if constexpr((cui8nOffsetDot&4)==0){
					//	参照ドット位置の差は8の倍数なので、ダブルワード単位転送にできる。
					if(PTRINT(pui8cdestination)&2){
						//	差は8の倍数なれど、開始位置に「端数4ドット(2バイト)」があるので、それを解消する。
						if(cpui8cdestination_end<pui8cdestination+2){
							cfp_fraction8();
							return;
						}
						RGBX_stCopy_Blend_Line_Offset_Bit16<ceDestinationAlpha,ceSourceAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32nsourceplanepitch);
					}
					//	この時点で参照ドット位置の差、処理対象位置共に8の倍数になっている。
					if(pui8cdestination+4<=cpui8cdestination_end){
						CAUTO					cpui8cdestination_endm4=cpui8cdestination_end-4;

						while(pui8cdestination<=cpui8cdestination_endm4)RGBX_stCopy_Blend_Line_Offset_Bit32<ceDestinationAlpha,ceSourceAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32nsourceplanepitch);
					}
					cfp_fraction16();
				}else{
					//	差は4の倍数なれど8の倍数ではなかった。
					if(pui8cdestination+2<=cpui8cdestination_end){
						CAUTO					cpui8cdestination_endm2=cpui8cdestination_end-2;

						while(pui8cdestination<=cpui8cdestination_endm2)RGBX_stCopy_Blend_Line_Offset_Bit16<ceDestinationAlpha,ceSourceAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32nsourceplanepitch);
					}
					cfp_fraction8();
				}
			}else{
				//	差は2の倍数なれど4の倍数ではなかった。
				if(pui8cdestination+1<=cpui8cdestination_end){
					CAUTO					cpui8cdestination_endm1=cpui8cdestination_end-1;

					while(pui8cdestination<=cpui8cdestination_endm1)RGBX_stCopy_Blend_Line_Offset_Bit8<ceDestinationAlpha,ceSourceAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32nsourceplanepitch);
				}
				cfp_fraction4l();
			}
		}else{
			UINT32					ui32csourcer_previous=0x00000000;
			UINT32					ui32csourceg_previous=0x00000000;
			UINT32					ui32csourceb_previous=0x00000000;
			UINT32					ui32csourcea_previous=0x00000000;
			CAUTO					cfp_fraction4l=[&](VOID)noexcept{
				//	終了位置に「端数1ドット」あるなら、残りを解消。
				//	1バイト未満で「pui8cdestination」には現れないので、
				//	「(cui32idestinationdotposition+cui32ndestinationhdotline)&1」で判定。
				//	ここまでで1ドット超過の端数は処理済みであるので、
				//	「pui8cdestination」のような進行状況変数を見る必要は無い。
				if((UINT8(cui32idestinationdotposition)+UINT8(cui16ndestinationhdotline))&1){
					RGBX_stCopy_Blend_Line_Offset_Bit4L<ceDestinationAlpha,ceSourceAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32nsourceplanepitch,&ui32csourcer_previous,&ui32csourceg_previous,&ui32csourceb_previous,&ui32csourcea_previous);
				}
				return;
			};
			CAUTO					cfp_fraction8=[&](VOID)noexcept{
				if(pui8cdestination+1<=cpui8cdestination_end){
					RGBX_stCopy_Blend_Line_Offset_Bit8<ceDestinationAlpha,ceSourceAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32nsourceplanepitch,&ui32csourcer_previous,&ui32csourceg_previous,&ui32csourceb_previous,&ui32csourcea_previous);
				}
				cfp_fraction4l();
				return;
			};
			CAUTO					cfp_fraction16=[&](VOID)noexcept{
				if(pui8cdestination+2<=cpui8cdestination_end){
					RGBX_stCopy_Blend_Line_Offset_Bit16<ceDestinationAlpha,ceSourceAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32nsourceplanepitch,&ui32csourcer_previous,&ui32csourceg_previous,&ui32csourceb_previous,&ui32csourcea_previous);
				}
				cfp_fraction8();
				return;
			};

			{
				CAUTO					cpcui8csourcer_positioned=cpcui8csourcebase_positioned;
				CAUTO					cpcui8csourceg_positioned=cpcui8csourcer_positioned+cui32nsourceplanepitch;
				CAUTO					cpcui8csourceb_positioned=cpcui8csourceg_positioned+cui32nsourceplanepitch;
				CAUTO					cpcui8csourcea_positioned=cpcui8csourceb_positioned+cui32nsourceplanepitch;

				stMakePrevious_Offset<cui8nOffsetDot>(cui32idestinationdotposition,cpcui8csourcer_positioned,ui32csourcer_previous);
				stMakePrevious_Offset<cui8nOffsetDot>(cui32idestinationdotposition,cpcui8csourceg_positioned,ui32csourceg_previous);
				stMakePrevious_Offset<cui8nOffsetDot>(cui32idestinationdotposition,cpcui8csourceb_positioned,ui32csourceb_previous);
				if constexpr(ceSourceAlpha)stMakePrevious_Offset<cui8nOffsetDot>(cui32idestinationdotposition,cpcui8csourcea_positioned,ui32csourcea_previous);
			}
			//	書き込み位置32bitアラインを目指し、「左側端数ドット」をコピーする。
			//	まずは「左端数1ドット」があるか判定するが、
			//	「pui8cdestination」には現れないので「cui32ndestinationdotposition」で判定する。
			//	これは更新前の処理初段であるから通用する方法。
			if(cui32idestinationdotposition&1){
				RGBX_stCopy_Blend_Line_Offset_Bit4R<ceDestinationAlpha,ceSourceAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32nsourceplanepitch,&ui32csourcer_previous,&ui32csourceg_previous,&ui32csourceb_previous,&ui32csourcea_previous);
			}
			if(PTRINT(pui8cdestination)&1){
				if(cpui8cdestination_end<pui8cdestination+1){
					cfp_fraction4l();
					return;
				}
				RGBX_stCopy_Blend_Line_Offset_Bit8<ceDestinationAlpha,ceSourceAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32nsourceplanepitch,&ui32csourcer_previous,&ui32csourceg_previous,&ui32csourceb_previous,&ui32csourcea_previous);
			}
			if(PTRINT(pui8cdestination)&2){
				if(cpui8cdestination_end<pui8cdestination+2){
					cfp_fraction8();
					return;
				}
				RGBX_stCopy_Blend_Line_Offset_Bit16<ceDestinationAlpha,ceSourceAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32nsourceplanepitch,&ui32csourcer_previous,&ui32csourceg_previous,&ui32csourceb_previous,&ui32csourcea_previous);
			}
			//	書き込み位置32bitアラインできたのでコピーループに入る。
			if(pui8cdestination+4<=cpui8cdestination_end){
				CAUTO					cpui8cdestination_endm4=cpui8cdestination_end-4;

				while(pui8cdestination<=cpui8cdestination_endm4)RGBX_stCopy_Blend_Line_Offset_Bit32<ceDestinationAlpha,ceSourceAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32nsourceplanepitch,&ui32csourcer_previous,&ui32csourceg_previous,&ui32csourceb_previous,&ui32csourcea_previous);
			}
			//	32bitアラインコピー出来る分は全て片付けたので、「右側端数ドット」をコピーする。
			cfp_fraction16();
		}
	}
	return;
}

template<COFWBOOL ceDestinationAlpha,COFWBOOL ceSourceAlpha,const CANVAS_::IDBLEND cidBlend,CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::RGBX_stCopy_Blend_Line_Offset_Bit4L(
	PUINT8&					pui8cdestination,
	CUINT32					cui32ndestinationplanepitch,
	CUINT32					cui32doffsetsourcebase,
	CUINT32					cui32nsourceplanepitch,
	const PUINT32			cpui32csourcer_previous,
	const PUINT32			cpui32csourceg_previous,
	const PUINT32			cpui32csourceb_previous,
	const PUINT32			cpui32csourcea_previous
)noexcept{
	constexpr AUTO			cfp_blend_bit4lthis=stfp_blend_bit4lGetThis<cidBlend>();
	CAUTO					cpui8cdestinationr=pui8cdestination;
	CAUTO					cpui8cdestinationg=cpui8cdestinationr+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationb=cpui8cdestinationg+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationa=cpui8cdestinationb+cui32ndestinationplanepitch;
	AUTO&					ui8cdestinationr=*cpui8cdestinationr;
	AUTO&					ui8cdestinationg=*cpui8cdestinationg;
	AUTO&					ui8cdestinationb=*cpui8cdestinationb;

	if constexpr(cui8nOffsetDot==0){
		CAUTO					cpcui8csourcer=PCUINT8(pui8cdestination+cui32doffsetsourcebase);
		CAUTO					cpcui8csourceg=cpcui8csourcer+cui32nsourceplanepitch;
		CAUTO					cpcui8csourceb=cpcui8csourceg+cui32nsourceplanepitch;
		CAUTO					cpcui8csourcea=cpcui8csourceb+cui32nsourceplanepitch;
		CAUTO					cui8csourcer=*cpcui8csourcer;
		CAUTO					cui8csourceg=*cpcui8csourceg;
		CAUTO					cui8csourceb=*cpcui8csourceb;

		if constexpr(ceSourceAlpha){
			CAUTO					cui8csourcea=*cpcui8csourcea;

			cfp_blend_bit4lthis(ui8cdestinationr,cui8csourcer,cui8csourcea);
			cfp_blend_bit4lthis(ui8cdestinationg,cui8csourceg,cui8csourcea);
			cfp_blend_bit4lthis(ui8cdestinationb,cui8csourceb,cui8csourcea);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui8cdestinationa=*cpui8cdestinationa;

				ui8cdestinationa=(ui8cdestinationa&0x0f)|(cui8csourcea&0xf0);
			}
		}else{
			constexpr AUTO			cui8csourcea=UINT8(0xf0);

			cfp_blend_bit4lthis(ui8cdestinationr,cui8csourcer,cui8csourcea);
			cfp_blend_bit4lthis(ui8cdestinationg,cui8csourceg,cui8csourcea);
			cfp_blend_bit4lthis(ui8cdestinationb,cui8csourceb,cui8csourcea);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui8cdestinationa=*cpui8cdestinationa;

				ui8cdestinationa=(ui8cdestinationa&0x0f)|cui8csourcea;
			}
		}
	}else{
		constexpr AUTO			cui8nshiftbitr=UINT8(cui8nOffsetDot<<2);
		constexpr AUTO			cui8nshiftbitr_previous=UINT8(cui8nshiftbitr-4);
		CAUTO					cui32csourcer_previous=*cpui32csourcer_previous;
		CAUTO					cui32csourceg_previous=*cpui32csourceg_previous;
		CAUTO					cui32csourceb_previous=*cpui32csourceb_previous;
		CAUTO					cui8csourcer_merged=UINT8((cui32csourcer_previous>>cui8nshiftbitr_previous)<<4);
		CAUTO					cui8csourceg_merged=UINT8((cui32csourceg_previous>>cui8nshiftbitr_previous)<<4);
		CAUTO					cui8csourceb_merged=UINT8((cui32csourceb_previous>>cui8nshiftbitr_previous)<<4);

		//	<cui8nOffsetDot:1>
		//		previous:--------------X
		//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//		|           |   | 4L|
		//		|           |--X|   |
		//		|               |x  |
		//		previous:---------------
		//	<cui8nOffsetDot:7>
		//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//		previous:--------------X
		//		|               | 4L|
		//		|X              |   |
		//		|               |x  |
		//		previous:---------------
		if constexpr(ceSourceAlpha){
			CAUTO					cui32csourcea_previous=*cpui32csourcea_previous;
			CAUTO					cui8csourcea_merged=UINT8((cui32csourcea_previous>>cui8nshiftbitr_previous)<<4);

			cfp_blend_bit4lthis(ui8cdestinationr,cui8csourcer_merged,cui8csourcea_merged);
			cfp_blend_bit4lthis(ui8cdestinationg,cui8csourceg_merged,cui8csourcea_merged);
			cfp_blend_bit4lthis(ui8cdestinationb,cui8csourceb_merged,cui8csourcea_merged);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui8cdestinationa=*cpui8cdestinationa;

				ui8cdestinationa=(ui8cdestinationa&0x0f)|(cui8csourcea_merged&0xf0);
			}
		}else{
			constexpr AUTO			cui8csourcea_merged=UINT8(0xf0);

			cfp_blend_bit4lthis(ui8cdestinationr,cui8csourcer_merged,cui8csourcea_merged);
			cfp_blend_bit4lthis(ui8cdestinationg,cui8csourceg_merged,cui8csourcea_merged);
			cfp_blend_bit4lthis(ui8cdestinationb,cui8csourceb_merged,cui8csourcea_merged);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui8cdestinationa=*cpui8cdestinationa;

				ui8cdestinationa=(ui8cdestinationa&0x0f)|cui8csourcea_merged;
			}
		}
	}
	return;
}

template<COFWBOOL ceDestinationAlpha,COFWBOOL ceSourceAlpha,const CANVAS_::IDBLEND cidBlend,CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::RGBX_stCopy_Blend_Line_Offset_Bit4R(
	PUINT8&					pui8cdestination,
	CUINT32					cui32ndestinationplanepitch,
	CUINT32					cui32doffsetsourcebase,
	CUINT32					cui32nsourceplanepitch,
	const PUINT32			cpui32csourcer_previous,
	const PUINT32			cpui32csourceg_previous,
	const PUINT32			cpui32csourceb_previous,
	const PUINT32			cpui32csourcea_previous
)noexcept{
	constexpr AUTO			cfp_blend_bit4rthis=stfp_blend_bit4rGetThis<cidBlend>();
	CAUTO					cpui8cdestinationr=pui8cdestination;
	CAUTO					cpui8cdestinationg=cpui8cdestinationr+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationb=cpui8cdestinationg+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationa=cpui8cdestinationb+cui32ndestinationplanepitch;
	AUTO&					ui8cdestinationr=*cpui8cdestinationr;
	AUTO&					ui8cdestinationg=*cpui8cdestinationg;
	AUTO&					ui8cdestinationb=*cpui8cdestinationb;
	CAUTO					cpcui8csourcer=PCUINT8(pui8cdestination+cui32doffsetsourcebase);
	CAUTO					cpcui8csourceg=cpcui8csourcer+cui32nsourceplanepitch;
	CAUTO					cpcui8csourceb=cpcui8csourceg+cui32nsourceplanepitch;
	CAUTO					cpcui8csourcea=cpcui8csourceb+cui32nsourceplanepitch;
	CAUTO					cui8csourcer=*cpcui8csourcer;
	CAUTO					cui8csourceg=*cpcui8csourceg;
	CAUTO					cui8csourceb=*cpcui8csourceb;

	if constexpr(cui8nOffsetDot==0){
		if constexpr(ceSourceAlpha){
			CAUTO					cui8csourcea=*cpcui8csourcea;

			cfp_blend_bit4rthis(ui8cdestinationr,cui8csourcer,cui8csourcea);
			cfp_blend_bit4rthis(ui8cdestinationg,cui8csourceg,cui8csourcea);
			cfp_blend_bit4rthis(ui8cdestinationb,cui8csourceb,cui8csourcea);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui8cdestinationa=*cpui8cdestinationa;

				ui8cdestinationa=(ui8cdestinationa&0xf0)|(cui8csourcea&0x0f);
			}
		}else{
			constexpr AUTO			cui8csourcea=UINT8(0x0f);

			cfp_blend_bit4rthis(ui8cdestinationr,cui8csourcer,cui8csourcea);
			cfp_blend_bit4rthis(ui8cdestinationg,cui8csourceg,cui8csourcea);
			cfp_blend_bit4rthis(ui8cdestinationb,cui8csourceb,cui8csourcea);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui8cdestinationa=*cpui8cdestinationa;

				ui8cdestinationa=(ui8cdestinationa&0xf0)|cui8csourcea;
			}
		}
	}else{
		constexpr AUTO			cui8nshiftbitr=UINT8(cui8nOffsetDot<<2);
		AUTO&					ui32csourcer_previous=*cpui32csourcer_previous;
		AUTO&					ui32csourceg_previous=*cpui32csourceg_previous;
		AUTO&					ui32csourceb_previous=*cpui32csourceb_previous;

		if constexpr(cui8nshiftbitr<8){
			CAUTO					cui8csourcer_merged=UINT8(cui8csourcer>>cui8nshiftbitr);
			CAUTO					cui8csourceg_merged=UINT8(cui8csourceg>>cui8nshiftbitr);
			CAUTO					cui8csourceb_merged=UINT8(cui8csourceb>>cui8nshiftbitr);

			//	<cui8nOffsetDot:1>
			//		previous:--------------X
			//		|0-1 2-3 4-5 6-7|
			//		| 4R|  8|     16|
			//		|R-R|B-B|W-W-W-W|
			//		|  R|r B|b W-W-W|w
			//		previous:--------------r
			if constexpr(ceSourceAlpha){
				CAUTO					cui8csourcea=*cpcui8csourcea;
				AUTO&					ui32csourcea_previous=*cpui32csourcea_previous;
				CAUTO					cui8csourcea_merged=UINT8(cui8csourcea>>cui8nshiftbitr);

				cfp_blend_bit4rthis(ui8cdestinationr,cui8csourcer_merged,cui8csourcea_merged);
				cfp_blend_bit4rthis(ui8cdestinationg,cui8csourceg_merged,cui8csourcea_merged);
				cfp_blend_bit4rthis(ui8cdestinationb,cui8csourceb_merged,cui8csourcea_merged);
				ui32csourcea_previous=UINT32(cui8csourcea);
				if constexpr(ceDestinationAlpha){
					AUTO&					ui8cdestinationa=*cpui8cdestinationa;

					ui8cdestinationa=(ui8cdestinationa&0xf0)|(cui8csourcea_merged&0x0f);
				}
			}else{
				constexpr AUTO			cui8csourcea_merged=UINT8(0x0f);

				cfp_blend_bit4rthis(ui8cdestinationr,cui8csourcer_merged,cui8csourcea_merged);
				cfp_blend_bit4rthis(ui8cdestinationg,cui8csourceg_merged,cui8csourcea_merged);
				cfp_blend_bit4rthis(ui8cdestinationb,cui8csourceb_merged,cui8csourcea_merged);
				if constexpr(ceDestinationAlpha){
					AUTO&					ui8cdestinationa=*cpui8cdestinationa;

					ui8cdestinationa=(ui8cdestinationa&0xf0)|cui8csourcea_merged;
				}
			}
			ui32csourcer_previous=UINT32(cui8csourcer);
			ui32csourceg_previous=UINT32(cui8csourceg);
			ui32csourceb_previous=UINT32(cui8csourceb);
		}else{
			constexpr AUTO			cui8nshiftbitr_previous=UINT8(cui8nshiftbitr-8);
			CAUTO					cui8csourcer_merged=UINT8(ui32csourcer_previous>>cui8nshiftbitr_previous);
			CAUTO					cui8csourceg_merged=UINT8(ui32csourceg_previous>>cui8nshiftbitr_previous);
			CAUTO					cui8csourceb_merged=UINT8(ui32csourceb_previous>>cui8nshiftbitr_previous);

			//	<cui8nOffsetDot:7>
			//		previous:----X-X-X-X-X-X
			//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
			//		|   |   |       | 4R|  8|     16|
			//		|   |X-X|X-X-X-X|R-R|B-B|W-W-W-W|
			//		|               |  x|x x|x x x r|r b b w w w w
			//		previous:----X-X-X-X-r-r
			if constexpr(ceSourceAlpha){
				CAUTO					cui8csourcea=*cpcui8csourcea;
				AUTO&					ui32csourcea_previous=*cpui32csourcea_previous;
				CAUTO					cui8csourcea_merged=UINT8(ui32csourcea_previous>>cui8nshiftbitr_previous);

				cfp_blend_bit4rthis(ui8cdestinationr,cui8csourcer_merged,cui8csourcea_merged);
				cfp_blend_bit4rthis(ui8cdestinationg,cui8csourceg_merged,cui8csourcea_merged);
				cfp_blend_bit4rthis(ui8cdestinationb,cui8csourceb_merged,cui8csourcea_merged);
				ui32csourcea_previous=(ui32csourcea_previous<<8)|UINT32(cui8csourcea);
				if constexpr(ceDestinationAlpha){
					AUTO&					ui8cdestinationa=*(cpui8cdestinationa);

					ui8cdestinationa=(ui8cdestinationa&0xf0)|(cui8csourcea_merged&0x0f);
				}
			}else{
				constexpr AUTO			cui8csourcea_merged=UINT8(0x0f);

				cfp_blend_bit4rthis(ui8cdestinationr,cui8csourcer_merged,cui8csourcea_merged);
				cfp_blend_bit4rthis(ui8cdestinationg,cui8csourceg_merged,cui8csourcea_merged);
				cfp_blend_bit4rthis(ui8cdestinationb,cui8csourceb_merged,cui8csourcea_merged);
				if constexpr(ceDestinationAlpha){
					AUTO&					ui8cdestinationa=*cpui8cdestinationa;

					ui8cdestinationa=(ui8cdestinationa&0xf0)|cui8csourcea_merged;
				}
			}
			ui32csourcer_previous=(ui32csourcer_previous<<8)|UINT32(cui8csourcer);
			ui32csourceg_previous=(ui32csourceg_previous<<8)|UINT32(cui8csourceg);
			ui32csourceb_previous=(ui32csourceb_previous<<8)|UINT32(cui8csourceb);
		}
	}
	++pui8cdestination;
	return;
}

template<COFWBOOL ceDestinationAlpha,COFWBOOL ceSourceAlpha,const CANVAS_::IDBLEND cidBlend,CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::RGBX_stCopy_Blend_Line_Offset_Bit8(
	PUINT8&					pui8cdestination,
	CUINT32					cui32ndestinationplanepitch,
	CUINT32					cui32doffsetsourcebase,
	CUINT32					cui32nsourceplanepitch,
	const PUINT32			cpui32csourcer_previous,
	const PUINT32			cpui32csourceg_previous,
	const PUINT32			cpui32csourceb_previous,
	const PUINT32			cpui32csourcea_previous
)noexcept{
	constexpr AUTO			cfp_blend_bit8this=stfp_blend_bit8GetThis<cidBlend>();
	CAUTO					cpui8cdestinationr=pui8cdestination;
	CAUTO					cpui8cdestinationg=cpui8cdestinationr+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationb=cpui8cdestinationg+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationa=cpui8cdestinationb+cui32ndestinationplanepitch;
	AUTO&					ui8cdestinationr=*cpui8cdestinationr;
	AUTO&					ui8cdestinationg=*cpui8cdestinationg;
	AUTO&					ui8cdestinationb=*cpui8cdestinationb;
	CAUTO					cpcui8csourcer=PCUINT8(pui8cdestination+cui32doffsetsourcebase);
	CAUTO					cpcui8csourceg=cpcui8csourcer+cui32nsourceplanepitch;
	CAUTO					cpcui8csourceb=cpcui8csourceg+cui32nsourceplanepitch;
	CAUTO					cpcui8csourcea=cpcui8csourceb+cui32nsourceplanepitch;
	CAUTO					cui8csourcer=*cpcui8csourcer;
	CAUTO					cui8csourceg=*cpcui8csourceg;
	CAUTO					cui8csourceb=*cpcui8csourceb;

	if constexpr(cui8nOffsetDot==0){
		if constexpr(ceSourceAlpha){
			CAUTO					cui8csourcea=*cpcui8csourcea;

			cfp_blend_bit8this(ui8cdestinationr,cui8csourcer,cui8csourcea);
			cfp_blend_bit8this(ui8cdestinationg,cui8csourceg,cui8csourcea);
			cfp_blend_bit8this(ui8cdestinationb,cui8csourceb,cui8csourcea);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui8cdestinationa=*cpui8cdestinationa;

				ui8cdestinationa=cui8csourcea;
			}
		}else{
			constexpr AUTO			cui8csourcea=UINT8(0xff);

			cfp_blend_bit8this(ui8cdestinationr,cui8csourcer,cui8csourcea);
			cfp_blend_bit8this(ui8cdestinationg,cui8csourceg,cui8csourcea);
			cfp_blend_bit8this(ui8cdestinationb,cui8csourceb,cui8csourcea);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui8cdestinationa=*cpui8cdestinationa;

				ui8cdestinationa=cui8csourcea;
			}
		}
	}else{
		constexpr AUTO			cui8nshiftbitr=UINT8(cui8nOffsetDot<<2);
		AUTO&					ui32csourcer_previous=*cpui32csourcer_previous;
		AUTO&					ui32csourceg_previous=*cpui32csourceg_previous;
		AUTO&					ui32csourceb_previous=*cpui32csourceb_previous;

		if constexpr(cui8nshiftbitr<8){
			constexpr AUTO			cui8nshiftbitl_previous=UINT8(8-cui8nshiftbitr);
			CAUTO					cui8csourcer_merged=UINT8((cui8csourcer>>cui8nshiftbitr)|UINT8(ui32csourcer_previous<<cui8nshiftbitl_previous));
			CAUTO					cui8csourceg_merged=UINT8((cui8csourceg>>cui8nshiftbitr)|UINT8(ui32csourceg_previous<<cui8nshiftbitl_previous));
			CAUTO					cui8csourceb_merged=UINT8((cui8csourceb>>cui8nshiftbitr)|UINT8(ui32csourceb_previous<<cui8nshiftbitl_previous));

			//	<cui8nOffsetDot:1>
			//		previous:--------------X
			//		|0-1 2-3 4-5 6-7|
			//		|   |  8|     16|
			//		|--X|B-B|W-W-W-W|
			//		|   |x B|b W-W-W|w
			//		previous:--------------b
			if constexpr(ceSourceAlpha){
				CAUTO					cui8csourcea=*cpcui8csourcea;
				AUTO&					ui32csourcea_previous=*cpui32csourcea_previous;
				CAUTO					cui8csourcea_merged=UINT8((cui8csourcea>>cui8nshiftbitr)|UINT8(ui32csourcea_previous<<cui8nshiftbitl_previous));

				cfp_blend_bit8this(ui8cdestinationr,cui8csourcer_merged,cui8csourcea_merged);
				cfp_blend_bit8this(ui8cdestinationg,cui8csourceg_merged,cui8csourcea_merged);
				cfp_blend_bit8this(ui8cdestinationb,cui8csourceb_merged,cui8csourcea_merged);
				ui32csourcea_previous=UINT32(cui8csourcea);
				if constexpr(ceDestinationAlpha){
					AUTO&					ui8cdestinationa=*cpui8cdestinationa;

					ui8cdestinationa=cui8csourcea_merged;
				}
			}else{
				constexpr AUTO			cui8csourcea_merged=UINT8(0xff);

				cfp_blend_bit8this(ui8cdestinationr,cui8csourcer_merged,cui8csourcea_merged);
				cfp_blend_bit8this(ui8cdestinationg,cui8csourceg_merged,cui8csourcea_merged);
				cfp_blend_bit8this(ui8cdestinationb,cui8csourceb_merged,cui8csourcea_merged);
				if constexpr(ceDestinationAlpha){
					AUTO&					ui8cdestinationa=*cpui8cdestinationa;

					ui8cdestinationa=cui8csourcea_merged;
				}
			}
			ui32csourcer_previous=UINT32(cui8csourcer);
			ui32csourceg_previous=UINT32(cui8csourceg);
			ui32csourceb_previous=UINT32(cui8csourceb);
		}else{
			constexpr AUTO			cui8nshiftbitr_previous=UINT8(cui8nshiftbitr-8);
			CAUTO					cui8csourcer_merged=UINT8(ui32csourcer_previous>>cui8nshiftbitr_previous);
			CAUTO					cui8csourceg_merged=UINT8(ui32csourceg_previous>>cui8nshiftbitr_previous);
			CAUTO					cui8csourceb_merged=UINT8(ui32csourceb_previous>>cui8nshiftbitr_previous);

			//	<cui8nOffsetDot:7>
			//		previous:--X-X-X-X-X-X-X
			//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
			//		|   |   |       |   |  8|     16|
			//		|   |--X|X-X-X-X|X-X|B-B|W-W-W-W|
			//		|               |   |x x|x x x x|x b b w w w w
			//		previous:--x-x-x-x-x-b-b
			if constexpr(ceSourceAlpha){
				CAUTO					cui8csourcea=*cpcui8csourcea;
				AUTO&					ui32csourcea_previous=*cpui32csourcea_previous;
				CAUTO					cui8csourcea_merged=UINT8(ui32csourcea_previous>>cui8nshiftbitr_previous);

				cfp_blend_bit8this(ui8cdestinationr,cui8csourcer_merged,cui8csourcea_merged);
				cfp_blend_bit8this(ui8cdestinationg,cui8csourceg_merged,cui8csourcea_merged);
				cfp_blend_bit8this(ui8cdestinationb,cui8csourceb_merged,cui8csourcea_merged);
				ui32csourcea_previous=(ui32csourcea_previous<<8)|UINT32(cui8csourcea);
				if constexpr(ceDestinationAlpha){
					AUTO&					ui8cdestinationa=*cpui8cdestinationa;

					ui8cdestinationa=cui8csourcea_merged;
				}
			}else{
				constexpr AUTO			cui8csourcea_merged=UINT8(0xff);

				cfp_blend_bit8this(ui8cdestinationr,cui8csourcer_merged,cui8csourcea_merged);
				cfp_blend_bit8this(ui8cdestinationg,cui8csourceg_merged,cui8csourcea_merged);
				cfp_blend_bit8this(ui8cdestinationb,cui8csourceb_merged,cui8csourcea_merged);
				if constexpr(ceDestinationAlpha){
					AUTO&					ui8cdestinationa=*cpui8cdestinationa;

					ui8cdestinationa=cui8csourcea_merged;
				}
			}
			ui32csourcer_previous=(ui32csourcer_previous<<8)|UINT32(cui8csourcer);
			ui32csourceg_previous=(ui32csourceg_previous<<8)|UINT32(cui8csourceg);
			ui32csourceb_previous=(ui32csourceb_previous<<8)|UINT32(cui8csourceb);
		}
	}
	++pui8cdestination;
	return;
}

template<COFWBOOL ceDestinationAlpha,COFWBOOL ceSourceAlpha,const CANVAS_::IDBLEND cidBlend,CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::RGBX_stCopy_Blend_Line_Offset_Bit16(
	PUINT8&					pui8cdestination,
	CUINT32					cui32ndestinationplanepitch,
	CUINT32					cui32doffsetsourcebase,
	CUINT32					cui32nsourceplanepitch,
	const PUINT32			cpui32csourcer_previous,
	const PUINT32			cpui32csourceg_previous,
	const PUINT32			cpui32csourceb_previous,
	const PUINT32			cpui32csourcea_previous
)noexcept{
	constexpr AUTO			cfp_blend_bit16this=stfp_blend_bit16GetThis<cidBlend>();
	CAUTO					cpui8cdestinationr=pui8cdestination;
	CAUTO					cpui8cdestinationg=cpui8cdestinationr+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationb=cpui8cdestinationg+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationa=cpui8cdestinationb+cui32ndestinationplanepitch;
	AUTO&					ui16cdestinationr=*PUINT16(cpui8cdestinationr);
	AUTO&					ui16cdestinationg=*PUINT16(cpui8cdestinationg);
	AUTO&					ui16cdestinationb=*PUINT16(cpui8cdestinationb);
	CAUTO					cpcui8csourcer=PCUINT8(pui8cdestination+cui32doffsetsourcebase);
	CAUTO					cpcui8csourceg=cpcui8csourcer+cui32nsourceplanepitch;
	CAUTO					cpcui8csourceb=cpcui8csourceg+cui32nsourceplanepitch;
	CAUTO					cpcui8csourcea=cpcui8csourceb+cui32nsourceplanepitch;
	CAUTO					cui16csourcer=*PCUINT16(cpcui8csourcer);
	CAUTO					cui16csourceg=*PCUINT16(cpcui8csourceg);
	CAUTO					cui16csourceb=*PCUINT16(cpcui8csourceb);

	if constexpr(cui8nOffsetDot==0){
		if constexpr(ceSourceAlpha){
			CAUTO					cui16csourcea=*PCUINT16(cpcui8csourcea);

			cfp_blend_bit16this(ui16cdestinationr,cui16csourcer,cui16csourcea);
			cfp_blend_bit16this(ui16cdestinationg,cui16csourceg,cui16csourcea);
			cfp_blend_bit16this(ui16cdestinationb,cui16csourceb,cui16csourcea);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui16cdestinationa=*PUINT16(cpui8cdestinationa);

				ui16cdestinationa=cui16csourcea;
			}
		}else{
			constexpr AUTO			cui16csourcea=UINT16(0xffff);

			cfp_blend_bit16this(ui16cdestinationr,cui16csourcer,cui16csourcea);
			cfp_blend_bit16this(ui16cdestinationg,cui16csourceg,cui16csourcea);
			cfp_blend_bit16this(ui16cdestinationb,cui16csourceb,cui16csourcea);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui16cdestinationa=*PUINT16(cpui8cdestinationa);

				ui16cdestinationa=cui16csourcea;
			}
		}
	}else{
		constexpr AUTO			cui8nshiftbitr=UINT8(cui8nOffsetDot<<2);
		AUTO&					ui32csourcer_previous=*cpui32csourcer_previous;
		AUTO&					ui32csourceg_previous=*cpui32csourceg_previous;
		AUTO&					ui32csourceb_previous=*cpui32csourceb_previous;

		if constexpr(cui8nshiftbitr<16){
			constexpr AUTO			cui8nshiftbitl_previous=UINT8(16-cui8nshiftbitr);
			CAUTO					cui16csourcer_merged=UINT16((cui16csourcer>>cui8nshiftbitr)|UINT16(ui32csourcer_previous<<cui8nshiftbitl_previous));
			CAUTO					cui16csourceg_merged=UINT16((cui16csourceg>>cui8nshiftbitr)|UINT16(ui32csourceg_previous<<cui8nshiftbitl_previous));
			CAUTO					cui16csourceb_merged=UINT16((cui16csourceb>>cui8nshiftbitr)|UINT16(ui32csourceb_previous<<cui8nshiftbitl_previous));

			//	<cui8nOffsetDot:1>
			//		previous:--------------X
			//		|0-1 2-3 4-5 6-7|
			//		|   |   |     16|
			//		|   |--X|W-W-W-W|
			//		|       |x W-W-W|w
			//		previous:--------------w
			if constexpr(ceSourceAlpha){
				CAUTO					cui16csourcea=*PCUINT16(cpcui8csourcea);
				AUTO&					ui32csourcea_previous=*cpui32csourcea_previous;
				CAUTO					cui16csourcea_merged=UINT16((cui16csourcea>>cui8nshiftbitr)|UINT16(ui32csourcea_previous<<cui8nshiftbitl_previous));

				cfp_blend_bit16this(ui16cdestinationr,cui16csourcer_merged,cui16csourcea_merged);
				cfp_blend_bit16this(ui16cdestinationg,cui16csourceg_merged,cui16csourcea_merged);
				cfp_blend_bit16this(ui16cdestinationb,cui16csourceb_merged,cui16csourcea_merged);
				ui32csourcea_previous=UINT32(cui16csourcea);
				if constexpr(ceDestinationAlpha){
					AUTO&					ui16cdestinationa=*PUINT16(cpui8cdestinationa);

					ui16cdestinationa=cui16csourcea_merged;
				}
			}else{
				constexpr AUTO			cui16csourcea_merged=UINT16(0xffff);

				cfp_blend_bit16this(ui16cdestinationr,cui16csourcer_merged,cui16csourcea_merged);
				cfp_blend_bit16this(ui16cdestinationg,cui16csourceg_merged,cui16csourcea_merged);
				cfp_blend_bit16this(ui16cdestinationb,cui16csourceb_merged,cui16csourcea_merged);
				if constexpr(ceDestinationAlpha){
					AUTO&					ui16cdestinationa=*PUINT16(cpui8cdestinationa);

					ui16cdestinationa=cui16csourcea_merged;
				}
			}
			ui32csourcer_previous=UINT32(cui16csourcer);
			ui32csourceg_previous=UINT32(cui16csourceg);
			ui32csourceb_previous=UINT32(cui16csourceb);
		}else{
			constexpr AUTO			cui8nshiftbitr_previous=UINT8(cui8nshiftbitr-16);
			CAUTO					cui16csourcer_merged=UINT16(ui32csourcer_previous>>cui8nshiftbitr_previous);
			CAUTO					cui16csourceg_merged=UINT16(ui32csourceg_previous>>cui8nshiftbitr_previous);
			CAUTO					cui16csourceb_merged=UINT16(ui32csourceb_previous>>cui8nshiftbitr_previous);

			//	<cui8nOffsetDot:7>
			//		previous:--X-X-X-X-X-X-X
			//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
			//		|       |       |       |     16|
			//		|       |--X-X-X|X-X-X-X|W-W-W-W|
			//		|               |       |x x x x|x x x w w w w
			//		previous:--x-x-x-w-w-w-w
			if constexpr(ceSourceAlpha){
				CAUTO					cui16csourcea=*PCUINT16(cpcui8csourcea);
				AUTO&					ui32csourcea_previous=*cpui32csourcea_previous;
				CAUTO					cui16csourcea_merged=UINT16(ui32csourcea_previous>>cui8nshiftbitr_previous);

				cfp_blend_bit16this(ui16cdestinationr,cui16csourcer_merged,cui16csourcea_merged);
				cfp_blend_bit16this(ui16cdestinationg,cui16csourceg_merged,cui16csourcea_merged);
				cfp_blend_bit16this(ui16cdestinationb,cui16csourceb_merged,cui16csourcea_merged);
				ui32csourcea_previous=(ui32csourcea_previous<<16)|UINT32(cui16csourcea);
				if constexpr(ceDestinationAlpha){
					AUTO&					ui16cdestinationa=*PUINT16(cpui8cdestinationa);

					ui16cdestinationa=cui16csourcea_merged;
				}
			}else{
				constexpr AUTO			cui16csourcea_merged=UINT16(0xffff);

				cfp_blend_bit16this(ui16cdestinationr,cui16csourcer_merged,cui16csourcea_merged);
				cfp_blend_bit16this(ui16cdestinationg,cui16csourceg_merged,cui16csourcea_merged);
				cfp_blend_bit16this(ui16cdestinationb,cui16csourceb_merged,cui16csourcea_merged);
				if constexpr(ceDestinationAlpha){
					AUTO&					ui16cdestinationa=*PUINT16(cpui8cdestinationa);

					ui16cdestinationa=cui16csourcea_merged;
				}
			}
			ui32csourcer_previous=(ui32csourcer_previous<<16)|UINT32(cui16csourcer);
			ui32csourceg_previous=(ui32csourceg_previous<<16)|UINT32(cui16csourceg);
			ui32csourceb_previous=(ui32csourceb_previous<<16)|UINT32(cui16csourceb);
		}
	}
	pui8cdestination+=2;
	return;
}

template<COFWBOOL ceDestinationAlpha,COFWBOOL ceSourceAlpha,const CANVAS_::IDBLEND cidBlend,CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::RGBX_stCopy_Blend_Line_Offset_Bit32(
	PUINT8&					pui8cdestination,
	CUINT32					cui32ndestinationplanepitch,
	CUINT32					cui32doffsetsourcebase,
	CUINT32					cui32nsourceplanepitch,
	const PUINT32			cpui32csourcer_previous,
	const PUINT32			cpui32csourceg_previous,
	const PUINT32			cpui32csourceb_previous,
	const PUINT32			cpui32csourcea_previous
)noexcept{
	constexpr AUTO			cfp_blend_bit32this=stfp_blend32GetThis<cidBlend>();
	CAUTO					cpui8cdestinationr=pui8cdestination;
	CAUTO					cpui8cdestinationg=cpui8cdestinationr+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationb=cpui8cdestinationg+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationa=cpui8cdestinationb+cui32ndestinationplanepitch;
	AUTO&					ui32cdestinationr=*PUINT32(cpui8cdestinationr);
	AUTO&					ui32cdestinationg=*PUINT32(cpui8cdestinationg);
	AUTO&					ui32cdestinationb=*PUINT32(cpui8cdestinationb);
	CAUTO					cpcui8csourcer=PCUINT8(pui8cdestination+cui32doffsetsourcebase);
	CAUTO					cpcui8csourceg=cpcui8csourcer+cui32nsourceplanepitch;
	CAUTO					cpcui8csourceb=cpcui8csourceg+cui32nsourceplanepitch;
	CAUTO					cpcui8csourcea=cpcui8csourceb+cui32nsourceplanepitch;
	CAUTO					cui32csourcer=*PCUINT32(cpcui8csourcer);
	CAUTO					cui32csourceg=*PCUINT32(cpcui8csourceg);
	CAUTO					cui32csourceb=*PCUINT32(cpcui8csourceb);

	if constexpr(cui8nOffsetDot==0){
		if constexpr(ceSourceAlpha){
			CAUTO					cui32csourcea=*PCUINT32(cpcui8csourcea);

			cfp_blend_bit32this(ui32cdestinationr,cui32csourcer,cui32csourcea);
			cfp_blend_bit32this(ui32cdestinationg,cui32csourceg,cui32csourcea);
			cfp_blend_bit32this(ui32cdestinationb,cui32csourceb,cui32csourcea);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui32cdestinationa=*PUINT32(cpui8cdestinationa);

				ui32cdestinationa=cui32csourcea;
			}
		}else{
			constexpr AUTO			cui32csourcea=UINT32(0xffffffff);

			cfp_blend_bit32this(ui32cdestinationr,cui32csourcer,cui32csourcea);
			cfp_blend_bit32this(ui32cdestinationg,cui32csourceg,cui32csourcea);
			cfp_blend_bit32this(ui32cdestinationb,cui32csourceb,cui32csourcea);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui32cdestinationa=*PUINT32(cpui8cdestinationa);

				ui32cdestinationa=cui32csourcea;
			}
		}
	}else{
		constexpr AUTO			cui8nshiftbitr=UINT8(cui8nOffsetDot<<2);
		constexpr AUTO			cui8nshiftbitl_previous=UINT8(32-cui8nshiftbitr);
		AUTO&					ui32csourcer_previous=*cpui32csourcer_previous;
		AUTO&					ui32csourceg_previous=*cpui32csourceg_previous;
		AUTO&					ui32csourceb_previous=*cpui32csourceb_previous;
		CAUTO					cui32csourcer_merged=UINT32((cui32csourcer>>cui8nshiftbitr)|(ui32csourcer_previous<<cui8nshiftbitl_previous));
		CAUTO					cui32csourceg_merged=UINT32((cui32csourceg>>cui8nshiftbitr)|(ui32csourceg_previous<<cui8nshiftbitl_previous));
		CAUTO					cui32csourceb_merged=UINT32((cui32csourceb>>cui8nshiftbitr)|(ui32csourceb_previous<<cui8nshiftbitl_previous));

		//	<cui8nOffsetDot:1>
		//		previous:--------------X
		//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//		|           |   |             32|
		//		|           |--X|D-D-D-D-D-D-D-D|
		//		|               |x D-D-D-D-D-D-D|d
		//		previous:--------------d
		//	<cui8nOffsetDot:7>
		//		previous:--X-X-X-X-X-X-X
		//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//		|               |             32|
		//		|--X-X-X-X-X-X-X|D-D-D-D-D-D-D-D|
		//		|               |x x x x x x x D|d d d d d d d
		//		previous:--d-d-d-d-d-d-d
		if constexpr(ceSourceAlpha){
			CAUTO					cui32csourcea=*PCUINT32(cpcui8csourcea);
			AUTO&					ui32csourcea_previous=*cpui32csourcea_previous;
			CAUTO					cui32csourcea_merged=UINT32((cui32csourcea>>cui8nshiftbitr)|(ui32csourcea_previous<<cui8nshiftbitl_previous));

			cfp_blend_bit32this(ui32cdestinationr,cui32csourcer_merged,cui32csourcea_merged);
			cfp_blend_bit32this(ui32cdestinationg,cui32csourceg_merged,cui32csourcea_merged);
			cfp_blend_bit32this(ui32cdestinationb,cui32csourceb_merged,cui32csourcea_merged);
			ui32csourcea_previous=cui32csourcea;
			if constexpr(ceDestinationAlpha){
				AUTO&					ui32cdestinationa=*PUINT32(cpui8cdestinationa);

				ui32cdestinationa=cui32csourcea_merged;
			}
		}else{
			constexpr AUTO			cui32csourcea_merged=UINT32(0xffffffff);

			cfp_blend_bit32this(ui32cdestinationr,cui32csourcer_merged,cui32csourcea_merged);
			cfp_blend_bit32this(ui32cdestinationg,cui32csourceg_merged,cui32csourcea_merged);
			cfp_blend_bit32this(ui32cdestinationb,cui32csourceb_merged,cui32csourcea_merged);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui32cdestinationa=*PUINT32(cpui8cdestinationa);

				ui32cdestinationa=cui32csourcea_merged;
			}
		}
		ui32csourcer_previous=cui32csourcer;
		ui32csourceg_previous=cui32csourceg;
		ui32csourceb_previous=cui32csourceb;
	}
	pui8cdestination+=4;
	return;
}

//	別アルファ画像使用画像コピー

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend>
_INLINE_ VOID			CANVAS_::RGBX_stCopyAlpha_Blend(
	const PUINT8			cpui8cdestinationbase,
	CUINT32					cui32idestinationdotposition,
	CUINT32					cui32ddestinationdotoffsetend,
	CUINT16					cui16ndestinationhdotline,
	CUINT16					cui16ndestinationlinepitch,
	CUINT32					cui32ndestinationplanepitch,
	const PCUINT8			cpcui8csourcebase,
	const PCUINT8			cpcui8csourcea,
	CUINT32					cui32isourcedotposition,
	CUINT16					cui16nsourcelinepitch,
	CUINT32					cui32nsourceplanepitch
)noexcept{
	CAUTO					cui32ndestinationlinedotpitch=UINT32(cui16ndestinationlinepitch<<1);
	CAUTO					cui32nsourcelinedotpitch=UINT32(cui16nsourcelinepitch<<1);
	AUTO					ui32idestinationdotposition=cui32idestinationdotposition;
	AUTO					ui32isourcedotposition=cui32isourcedotposition;

	for(
		CAUTO					cui32idestination_end=ui32idestinationdotposition+cui32ddestinationdotoffsetend;
		ui32idestinationdotposition<cui32idestination_end;
		ui32idestinationdotposition+=cui32ndestinationlinedotpitch
	){
		RGBX_stCopyAlpha_Blend_Line<ceDestinationAlpha,cidBlend>(
			cpui8cdestinationbase,
			ui32idestinationdotposition,
			cui16ndestinationhdotline,
			cui32ndestinationplanepitch,
			cpcui8csourcebase,
			cpcui8csourcea,
			ui32isourcedotposition,
			cui32nsourceplanepitch
		);
		ui32isourcedotposition+=cui32nsourcelinedotpitch;
	}
	return;
}

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend>
_INLINE_ VOID			CANVAS_::RGBX_stCopyAlpha_Blend_Line(
	const PUINT8			cpui8cdestinationbase,
	CUINT32					cui32idestinationdotposition,
	CUINT16					cui16ndestinationhdotline,
	CUINT32					cui32ndestinationplanepitch,
	const PCUINT8			cpcui8csourcebase,
	const PCUINT8			cpcui8csourcea,
	CUINT32					cui32isourcedotposition,
	CUINT32					cui32nsourceplanepitch
)noexcept{
	switch(UINT8(cui32idestinationdotposition-cui32isourcedotposition)&7){
	case 0:
		RGBX_stCopyAlpha_Blend_Line_Offset<ceDestinationAlpha,cidBlend,0>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cpcui8csourcebase,cpcui8csourcea,cui32isourcedotposition,cui32nsourceplanepitch);
		break;
	case 1:
		RGBX_stCopyAlpha_Blend_Line_Offset<ceDestinationAlpha,cidBlend,1>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cpcui8csourcebase,cpcui8csourcea,cui32isourcedotposition,cui32nsourceplanepitch);
		break;
	case 2:
		RGBX_stCopyAlpha_Blend_Line_Offset<ceDestinationAlpha,cidBlend,2>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cpcui8csourcebase,cpcui8csourcea,cui32isourcedotposition,cui32nsourceplanepitch);
		break;
	case 3:
		RGBX_stCopyAlpha_Blend_Line_Offset<ceDestinationAlpha,cidBlend,3>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cpcui8csourcebase,cpcui8csourcea,cui32isourcedotposition,cui32nsourceplanepitch);
		break;
	case 4:
		RGBX_stCopyAlpha_Blend_Line_Offset<ceDestinationAlpha,cidBlend,4>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cpcui8csourcebase,cpcui8csourcea,cui32isourcedotposition,cui32nsourceplanepitch);
		break;
	case 5:
		RGBX_stCopyAlpha_Blend_Line_Offset<ceDestinationAlpha,cidBlend,5>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cpcui8csourcebase,cpcui8csourcea,cui32isourcedotposition,cui32nsourceplanepitch);
		break;
	case 6:
		RGBX_stCopyAlpha_Blend_Line_Offset<ceDestinationAlpha,cidBlend,6>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cpcui8csourcebase,cpcui8csourcea,cui32isourcedotposition,cui32nsourceplanepitch);
		break;
	case 7:
		RGBX_stCopyAlpha_Blend_Line_Offset<ceDestinationAlpha,cidBlend,7>(cpui8cdestinationbase,cui32idestinationdotposition,cui16ndestinationhdotline,cui32ndestinationplanepitch,cpcui8csourcebase,cpcui8csourcea,cui32isourcedotposition,cui32nsourceplanepitch);
		break;
	}
	return;
}

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend,CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::RGBX_stCopyAlpha_Blend_Line_Offset(
	const PUINT8			cpui8cdestinationbase,
	CUINT32					cui32idestinationdotposition,
	CUINT16					cui16ndestinationhdotline,
	CUINT32					cui32ndestinationplanepitch,
	const PCUINT8			cpcui8csourcebase,
	const PCUINT8			cpcui8csourcea,
	CUINT32					cui32isourcedotposition,
	CUINT32					cui32nsourceplanepitch
)noexcept{
	if(cui16ndestinationhdotline){
		AUTO					pui8cdestination=cpui8cdestinationbase+(cui32idestinationdotposition>>1);
		//	PUINT8					cpui8cdestination_end
		//		コピー終了条件に使いますが、注意すべきは「右端数1ドット」を含まない事。
		//		含めてしまうと、「2、4、8ドットコピー可」と誤認されてしまう。
		//		「右端数1ドット」があるかどうかは「(cui32idestinationdotposition+cui32ndestinationhdotline)&1」で判定する。
		AUTO					cpui8cdestination_end=cpui8cdestinationbase+((cui32idestinationdotposition+UINT32(cui16ndestinationhdotline))>>1);
		CAUTO					cui32isourceposition=UINT32((cui32isourcedotposition+UINT32((cui8nOffsetDot&1)?cui8nOffsetDot:UINT8(0)))>>1);
		CAUTO					cpcui8csourcebase_positioned=cpcui8csourcebase+cui32isourceposition;
		CAUTO					cui32doffsetsourcebase=UINT32(cpcui8csourcebase_positioned-pui8cdestination);
		CAUTO					cpcui8csourcea_positioned=cpcui8csourcea+cui32isourceposition;
		CAUTO					cui32doffsetsourcea=UINT32(cpcui8csourcea_positioned-pui8cdestination);

		if constexpr((cui8nOffsetDot&1)==0){
			CAUTO					cfp_fraction4l=[&](VOID)noexcept{
				//	終了位置に「端数1ドット」あるなら、残りを解消。
				//	1バイト未満で「pui8cdestination」には現れないので、
				//	「(cui32idestinationdotposition+cui32ndestinationhdotline)&1」で判定。
				//	ここまでで1ドット超過の端数は処理済みであるので、
				//	「pui8cdestination」のような進行状況変数を見る必要は無い。
				if((UINT8(cui32idestinationdotposition)+UINT8(cui16ndestinationhdotline))&1){
					RGBX_stCopyAlpha_Blend_Line_Offset_Bit4L<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32doffsetsourcea,cui32nsourceplanepitch);
				}
				return;
			};
			CAUTO					cfp_fraction8=[&](VOID)noexcept{
				//	終了位置に「端数2～4ドット」あるなら、「2ドット(1バイト)」分解消。
				if(pui8cdestination+1<=cpui8cdestination_end){
					RGBX_stCopyAlpha_Blend_Line_Offset_Bit8<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32doffsetsourcea,cui32nsourceplanepitch);
				}
				cfp_fraction4l();
				return;
			};
			CAUTO					cfp_fraction16=[&](VOID)noexcept{
				//	終了位置に「端数4～8ドット」あるなら、「4ドット(2バイト)」分解消。
				if(pui8cdestination+2<=cpui8cdestination_end){
					RGBX_stCopyAlpha_Blend_Line_Offset_Bit16<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32doffsetsourcea,cui32nsourceplanepitch);
				}
				cfp_fraction8();
				return;
			};

			//	参照ドット位置の差は2の倍数なので、最悪でもバイト単位転送にはできる。
			//	「ビットシフトありの4バイト単位処理」と「ビットシフト無しの1バイト単位処理」のどちらが速いか定かでないが、
			//	一旦「ビットシフト無しの方が速い」とする。
			//	まずは「左端数1ドット」があるか判定するが、
			//	「pui8cdestination」には現れないので「cui32ndestinationdotposition」で判定する。
			//	これは更新前の処理初段であるから通用する方法。
			if(cui32idestinationdotposition&1){
				//	差は2の倍数なれど、開始位置に「端数1ドット」があるので、それを解消する。
				RGBX_stCopyAlpha_Blend_Line_Offset_Bit4R<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32doffsetsourcea,cui32nsourceplanepitch);
			}
			//	この時点で参照ドット位置の差、処理対象位置共に2の倍数になっている。
			if constexpr((cui8nOffsetDot&2)==0){
				//	参照ドット位置の差は4の倍数なので、最悪でもワード単位転送にはできる。
				if(PTRINT(pui8cdestination)&1){
					//	差は4の倍数なれど、開始位置に「端数2ドット(1バイト)」があるので、それを解消する。
					if(cpui8cdestination_end<pui8cdestination+1){
						cfp_fraction4l();
						return;
					}
					RGBX_stCopyAlpha_Blend_Line_Offset_Bit8<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32doffsetsourcea,cui32nsourceplanepitch);
				}
				//	この時点で参照ドット位置の差、処理対象位置共に4の倍数になっている。
				if constexpr((cui8nOffsetDot&4)==0){
					//	参照ドット位置の差は8の倍数なので、ダブルワード単位転送にできる。
					if(PTRINT(pui8cdestination)&2){
						//	差は8の倍数なれど、開始位置に「端数4ドット(2バイト)」があるので、それを解消する。
						if(cpui8cdestination_end<pui8cdestination+2){
							cfp_fraction8();
							return;
						}
						RGBX_stCopyAlpha_Blend_Line_Offset_Bit16<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32doffsetsourcea,cui32nsourceplanepitch);
					}
					//	この時点で参照ドット位置の差、処理対象位置共に8の倍数になっている。
					if(pui8cdestination+4<=cpui8cdestination_end){
						CAUTO					cpui8cdestination_endm4=cpui8cdestination_end-4;

						while(pui8cdestination<=cpui8cdestination_endm4)RGBX_stCopyAlpha_Blend_Line_Offset_Bit32<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32doffsetsourcea,cui32nsourceplanepitch);
					}
					cfp_fraction16();
				}else{
					//	差は4の倍数なれど8の倍数ではなかった。
					if(pui8cdestination+2<=cpui8cdestination_end){
						CAUTO					cpui8cdestination_endm2=cpui8cdestination_end-2;

						while(pui8cdestination<=cpui8cdestination_endm2)RGBX_stCopyAlpha_Blend_Line_Offset_Bit16<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32doffsetsourcea,cui32nsourceplanepitch);
					}
					cfp_fraction8();
				}
			}else{
				//	差は2の倍数なれど4の倍数ではなかった。
				if(pui8cdestination+1<=cpui8cdestination_end){
					CAUTO					cpui8cdestination_endm1=cpui8cdestination_end-1;

					while(pui8cdestination<=cpui8cdestination_endm1)RGBX_stCopyAlpha_Blend_Line_Offset_Bit8<ceDestinationAlpha,cidBlend>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32doffsetsourcea,cui32nsourceplanepitch);
				}
				cfp_fraction4l();
			}
		}else{
			UINT32					ui32csourcer_previous=0x00000000;
			UINT32					ui32csourceg_previous=0x00000000;
			UINT32					ui32csourceb_previous=0x00000000;
			UINT32					ui32csourcea_previous=0x00000000;
			CAUTO					cfp_fraction4l=[&](VOID)noexcept{
				//	終了位置に「端数1ドット」あるなら、残りを解消。
				//	1バイト未満で「pui8cdestination」には現れないので、
				//	「(cui32idestinationdotposition+cui32ndestinationhdotline)&1」で判定。
				//	ここまでで1ドット超過の端数は処理済みであるので、
				//	「pui8cdestination」のような進行状況変数を見る必要は無い。
				if((UINT8(cui32idestinationdotposition)+UINT8(cui16ndestinationhdotline))&1){
					RGBX_stCopyAlpha_Blend_Line_Offset_Bit4L<ceDestinationAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32doffsetsourcea,cui32nsourceplanepitch,&ui32csourcer_previous,&ui32csourceg_previous,&ui32csourceb_previous,&ui32csourcea_previous);
				}
				return;
			};
			CAUTO					cfp_fraction8=[&](VOID)noexcept{
				if(pui8cdestination+1<=cpui8cdestination_end){
					RGBX_stCopyAlpha_Blend_Line_Offset_Bit8<ceDestinationAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32doffsetsourcea,cui32nsourceplanepitch,&ui32csourcer_previous,&ui32csourceg_previous,&ui32csourceb_previous,&ui32csourcea_previous);
				}
				cfp_fraction4l();
				return;
			};
			CAUTO					cfp_fraction16=[&](VOID)noexcept{
				if(pui8cdestination+2<=cpui8cdestination_end){
					RGBX_stCopyAlpha_Blend_Line_Offset_Bit16<ceDestinationAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32doffsetsourcea,cui32nsourceplanepitch,&ui32csourcer_previous,&ui32csourceg_previous,&ui32csourceb_previous,&ui32csourcea_previous);
				}
				cfp_fraction8();
				return;
			};

			{
				CAUTO					cpcui8csourcer_positioned=cpcui8csourcebase_positioned;
				CAUTO					cpcui8csourceg_positioned=cpcui8csourcer_positioned+cui32nsourceplanepitch;
				CAUTO					cpcui8csourceb_positioned=cpcui8csourceg_positioned+cui32nsourceplanepitch;

				stMakePrevious_Offset<cui8nOffsetDot>(cui32idestinationdotposition,cpcui8csourcer_positioned,ui32csourcer_previous);
				stMakePrevious_Offset<cui8nOffsetDot>(cui32idestinationdotposition,cpcui8csourceg_positioned,ui32csourceg_previous);
				stMakePrevious_Offset<cui8nOffsetDot>(cui32idestinationdotposition,cpcui8csourceb_positioned,ui32csourceb_previous);
				stMakePrevious_Offset<cui8nOffsetDot>(cui32idestinationdotposition,cpcui8csourcea_positioned,ui32csourcea_previous);
			}
			//	書き込み位置32bitアラインを目指し、「左側端数ドット」をコピーする。
			//	まずは「左端数1ドット」があるか判定するが、
			//	「pui8cdestination」には現れないので「cui32ndestinationdotposition」で判定する。
			//	これは更新前の処理初段であるから通用する方法。
			if(cui32idestinationdotposition&1){
				RGBX_stCopyAlpha_Blend_Line_Offset_Bit4R<ceDestinationAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32doffsetsourcea,cui32nsourceplanepitch,&ui32csourcer_previous,&ui32csourceg_previous,&ui32csourceb_previous,&ui32csourcea_previous);
			}
			if(PTRINT(pui8cdestination)&1){
				if(cpui8cdestination_end<pui8cdestination+1){
					cfp_fraction4l();
					return;
				}
				RGBX_stCopyAlpha_Blend_Line_Offset_Bit8<ceDestinationAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32doffsetsourcea,cui32nsourceplanepitch,&ui32csourcer_previous,&ui32csourceg_previous,&ui32csourceb_previous,&ui32csourcea_previous);
			}
			if(PTRINT(pui8cdestination)&2){
				if(cpui8cdestination_end<pui8cdestination+2){
					cfp_fraction8();
					return;
				}
				RGBX_stCopyAlpha_Blend_Line_Offset_Bit16<ceDestinationAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32doffsetsourcea,cui32nsourceplanepitch,&ui32csourcer_previous,&ui32csourceg_previous,&ui32csourceb_previous,&ui32csourcea_previous);
			}
			//	書き込み位置32bitアラインできたのでコピーループに入る。
			if(pui8cdestination+4<=cpui8cdestination_end){
				CAUTO					cpui8cdestination_endm4=cpui8cdestination_end-4;

				while(pui8cdestination<=cpui8cdestination_endm4)RGBX_stCopyAlpha_Blend_Line_Offset_Bit32<ceDestinationAlpha,cidBlend,cui8nOffsetDot>(pui8cdestination,cui32ndestinationplanepitch,cui32doffsetsourcebase,cui32doffsetsourcea,cui32nsourceplanepitch,&ui32csourcer_previous,&ui32csourceg_previous,&ui32csourceb_previous,&ui32csourcea_previous);
			}
			//	32bitアラインコピー出来る分は全て片付けたので、「右側端数ドット」をコピーする。
			cfp_fraction16();
		}
	}
	return;
}

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend,CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::RGBX_stCopyAlpha_Blend_Line_Offset_Bit4L(
	PUINT8&					pui8cdestination,
	CUINT32					cui32ndestinationplanepitch,
	CUINT32					cui32doffsetsourcebase,
	CUINT32					cui32doffsetsourcea,
	CUINT32					cui32nsourceplanepitch,
	const PUINT32			cpui32csourcer_previous,
	const PUINT32			cpui32csourceg_previous,
	const PUINT32			cpui32csourceb_previous,
	const PUINT32			cpui32csourcea_previous
)noexcept{
	constexpr AUTO			cfp_blend_bit4lthis=stfp_blend_bit4lGetThis<cidBlend>();
	CAUTO					cpui8cdestinationr=pui8cdestination;
	CAUTO					cpui8cdestinationg=cpui8cdestinationr+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationb=cpui8cdestinationg+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationa=cpui8cdestinationb+cui32ndestinationplanepitch;
	AUTO&					ui8cdestinationr=*cpui8cdestinationr;
	AUTO&					ui8cdestinationg=*cpui8cdestinationg;
	AUTO&					ui8cdestinationb=*cpui8cdestinationb;

	if constexpr(cui8nOffsetDot==0){
		CAUTO					cpcui8csourcer=PCUINT8(pui8cdestination+cui32doffsetsourcebase);
		CAUTO					cpcui8csourceg=cpcui8csourcer+cui32nsourceplanepitch;
		CAUTO					cpcui8csourceb=cpcui8csourceg+cui32nsourceplanepitch;
		CAUTO					cpcui8csourcea=PCUINT8(pui8cdestination+cui32doffsetsourcea);
		CAUTO					cui8csourcer=*cpcui8csourcer;
		CAUTO					cui8csourceg=*cpcui8csourceg;
		CAUTO					cui8csourceb=*cpcui8csourceb;
		CAUTO					cui8csourcea=*cpcui8csourcea;

		cfp_blend_bit4lthis(ui8cdestinationr,cui8csourcer,cui8csourcea);
		cfp_blend_bit4lthis(ui8cdestinationg,cui8csourceg,cui8csourcea);
		cfp_blend_bit4lthis(ui8cdestinationb,cui8csourceb,cui8csourcea);
		if constexpr(ceDestinationAlpha){
			AUTO&					ui8cdestinationa=*cpui8cdestinationa;

			ui8cdestinationa=(ui8cdestinationa&0x0f)|(cui8csourcea&0xf0);
		}
	}else{
		constexpr AUTO			cui8nshiftbitr=UINT8(cui8nOffsetDot<<2);
		constexpr AUTO			cui8nshiftbitr_previous=UINT8(cui8nshiftbitr-4);
		CAUTO					cui32csourcer_previous=*cpui32csourcer_previous;
		CAUTO					cui32csourceg_previous=*cpui32csourceg_previous;
		CAUTO					cui32csourceb_previous=*cpui32csourceb_previous;
		CAUTO					cui32csourcea_previous=*cpui32csourcea_previous;
		CAUTO					cui8csourcer_merged=UINT8((cui32csourcer_previous>>cui8nshiftbitr_previous)<<4);
		CAUTO					cui8csourceg_merged=UINT8((cui32csourceg_previous>>cui8nshiftbitr_previous)<<4);
		CAUTO					cui8csourceb_merged=UINT8((cui32csourceb_previous>>cui8nshiftbitr_previous)<<4);
		CAUTO					cui8csourcea_merged=UINT8((cui32csourcea_previous>>cui8nshiftbitr_previous)<<4);

		//	<cui8nOffsetDot:1>
		//		previous:--------------X
		//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//		|           |   | 4L|
		//		|           |--X|   |
		//		|               |x  |
		//		previous:---------------
		//	<cui8nOffsetDot:7>
		//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//		previous:--------------X
		//		|               | 4L|
		//		|X              |   |
		//		|               |x  |
		//		previous:---------------
		cfp_blend_bit4lthis(ui8cdestinationr,cui8csourcer_merged,cui8csourcea_merged);
		cfp_blend_bit4lthis(ui8cdestinationg,cui8csourceg_merged,cui8csourcea_merged);
		cfp_blend_bit4lthis(ui8cdestinationb,cui8csourceb_merged,cui8csourcea_merged);
		if constexpr(ceDestinationAlpha){
			AUTO&					ui8cdestinationa=*cpui8cdestinationa;

			ui8cdestinationa=(ui8cdestinationa&0x0f)|(cui8csourcea_merged&0xf0);
		}
	}
	return;
}

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend,CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::RGBX_stCopyAlpha_Blend_Line_Offset_Bit4R(
	PUINT8&					pui8cdestination,
	CUINT32					cui32ndestinationplanepitch,
	CUINT32					cui32doffsetsourcebase,
	CUINT32					cui32doffsetsourcea,
	CUINT32					cui32nsourceplanepitch,
	const PUINT32			cpui32csourcer_previous,
	const PUINT32			cpui32csourceg_previous,
	const PUINT32			cpui32csourceb_previous,
	const PUINT32			cpui32csourcea_previous
)noexcept{
	constexpr AUTO			cfp_blend_bit4rthis=stfp_blend_bit4rGetThis<cidBlend>();
	CAUTO					cpui8cdestinationr=pui8cdestination;
	CAUTO					cpui8cdestinationg=cpui8cdestinationr+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationb=cpui8cdestinationg+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationa=cpui8cdestinationb+cui32ndestinationplanepitch;
	AUTO&					ui8cdestinationr=*cpui8cdestinationr;
	AUTO&					ui8cdestinationg=*cpui8cdestinationg;
	AUTO&					ui8cdestinationb=*cpui8cdestinationb;
	CAUTO					cpcui8csourcer=PCUINT8(pui8cdestination+cui32doffsetsourcebase);
	CAUTO					cpcui8csourceg=cpcui8csourcer+cui32nsourceplanepitch;
	CAUTO					cpcui8csourceb=cpcui8csourceg+cui32nsourceplanepitch;
	CAUTO					cpcui8csourcea=PCUINT8(pui8cdestination+cui32doffsetsourcea);
	CAUTO					cui8csourcer=*cpcui8csourcer;
	CAUTO					cui8csourceg=*cpcui8csourceg;
	CAUTO					cui8csourceb=*cpcui8csourceb;
	CAUTO					cui8csourcea=*cpcui8csourcea;

	if constexpr(cui8nOffsetDot==0){
		cfp_blend_bit4rthis(ui8cdestinationr,cui8csourcer,cui8csourcea);
		cfp_blend_bit4rthis(ui8cdestinationg,cui8csourceg,cui8csourcea);
		cfp_blend_bit4rthis(ui8cdestinationb,cui8csourceb,cui8csourcea);
		if constexpr(ceDestinationAlpha){
			AUTO&					ui8cdestinationa=*cpui8cdestinationa;

			ui8cdestinationa=(ui8cdestinationa&0xf0)|(cui8csourcea&0x0f);
		}
	}else{
		constexpr AUTO			cui8nshiftbitr=UINT8(cui8nOffsetDot<<2);
		AUTO&					ui32csourcer_previous=*cpui32csourcer_previous;
		AUTO&					ui32csourceg_previous=*cpui32csourceg_previous;
		AUTO&					ui32csourceb_previous=*cpui32csourceb_previous;
		AUTO&					ui32csourcea_previous=*cpui32csourcea_previous;

		if constexpr(cui8nshiftbitr<8){
			CAUTO					cui8csourcer_merged=UINT8(cui8csourcer>>cui8nshiftbitr);
			CAUTO					cui8csourceg_merged=UINT8(cui8csourceg>>cui8nshiftbitr);
			CAUTO					cui8csourceb_merged=UINT8(cui8csourceb>>cui8nshiftbitr);
			CAUTO					cui8csourcea_merged=UINT8(cui8csourcea>>cui8nshiftbitr);

			//	<cui8nOffsetDot:1>
			//		previous:--------------X
			//		|0-1 2-3 4-5 6-7|
			//		| 4R|  8|     16|
			//		|R-R|B-B|W-W-W-W|
			//		|  R|r B|b W-W-W|w
			//		previous:--------------r
			cfp_blend_bit4rthis(ui8cdestinationr,cui8csourcer_merged,cui8csourcea_merged);
			cfp_blend_bit4rthis(ui8cdestinationg,cui8csourceg_merged,cui8csourcea_merged);
			cfp_blend_bit4rthis(ui8cdestinationb,cui8csourceb_merged,cui8csourcea_merged);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui8cdestinationa=*cpui8cdestinationa;

				ui8cdestinationa=(ui8cdestinationa&0xf0)|(cui8csourcea_merged&0x0f);
			}
			ui32csourcer_previous=UINT32(cui8csourcer);
			ui32csourceg_previous=UINT32(cui8csourceg);
			ui32csourceb_previous=UINT32(cui8csourceb);
			ui32csourcea_previous=UINT32(cui8csourcea);
		}else{
			constexpr AUTO			cui8nshiftbitr_previous=UINT8(cui8nshiftbitr-8);
			CAUTO					cui8csourcer_merged=UINT8(ui32csourcer_previous>>cui8nshiftbitr_previous);
			CAUTO					cui8csourceg_merged=UINT8(ui32csourceg_previous>>cui8nshiftbitr_previous);
			CAUTO					cui8csourceb_merged=UINT8(ui32csourceb_previous>>cui8nshiftbitr_previous);
			CAUTO					cui8csourcea_merged=UINT8(ui32csourcea_previous>>cui8nshiftbitr_previous);

			//	<cui8nOffsetDot:7>
			//		previous:----X-X-X-X-X-X
			//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
			//		|   |   |       | 4R|  8|     16|
			//		|   |X-X|X-X-X-X|R-R|B-B|W-W-W-W|
			//		|               |  x|x x|x x x r|r b b w w w w
			//		previous:----X-X-X-X-r-r
			cfp_blend_bit4rthis(ui8cdestinationr,cui8csourcer_merged,cui8csourcea_merged);
			cfp_blend_bit4rthis(ui8cdestinationg,cui8csourceg_merged,cui8csourcea_merged);
			cfp_blend_bit4rthis(ui8cdestinationb,cui8csourceb_merged,cui8csourcea_merged);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui8cdestinationa=*(cpui8cdestinationa);

				ui8cdestinationa=(ui8cdestinationa&0xf0)|(cui8csourcea_merged&0x0f);
			}
			ui32csourcer_previous=(ui32csourcer_previous<<8)|UINT32(cui8csourcer);
			ui32csourceg_previous=(ui32csourceg_previous<<8)|UINT32(cui8csourceg);
			ui32csourceb_previous=(ui32csourceb_previous<<8)|UINT32(cui8csourceb);
			ui32csourcea_previous=(ui32csourcea_previous<<8)|UINT32(cui8csourcea);
		}
	}
	++pui8cdestination;
	return;
}

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend,CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::RGBX_stCopyAlpha_Blend_Line_Offset_Bit8(
	PUINT8&					pui8cdestination,
	CUINT32					cui32ndestinationplanepitch,
	CUINT32					cui32doffsetsourcebase,
	CUINT32					cui32doffsetsourcea,
	CUINT32					cui32nsourceplanepitch,
	const PUINT32			cpui32csourcer_previous,
	const PUINT32			cpui32csourceg_previous,
	const PUINT32			cpui32csourceb_previous,
	const PUINT32			cpui32csourcea_previous
)noexcept{
	constexpr AUTO			cfp_blend_bit8this=stfp_blend_bit8GetThis<cidBlend>();
	CAUTO					cpui8cdestinationr=pui8cdestination;
	CAUTO					cpui8cdestinationg=cpui8cdestinationr+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationb=cpui8cdestinationg+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationa=cpui8cdestinationb+cui32ndestinationplanepitch;
	AUTO&					ui8cdestinationr=*cpui8cdestinationr;
	AUTO&					ui8cdestinationg=*cpui8cdestinationg;
	AUTO&					ui8cdestinationb=*cpui8cdestinationb;
	CAUTO					cpcui8csourcer=PCUINT8(pui8cdestination+cui32doffsetsourcebase);
	CAUTO					cpcui8csourceg=cpcui8csourcer+cui32nsourceplanepitch;
	CAUTO					cpcui8csourceb=cpcui8csourceg+cui32nsourceplanepitch;
	CAUTO					cpcui8csourcea=PCUINT8(pui8cdestination+cui32doffsetsourcea);
	CAUTO					cui8csourcer=*cpcui8csourcer;
	CAUTO					cui8csourceg=*cpcui8csourceg;
	CAUTO					cui8csourceb=*cpcui8csourceb;
	CAUTO					cui8csourcea=*cpcui8csourcea;

	if constexpr(cui8nOffsetDot==0){
		cfp_blend_bit8this(ui8cdestinationr,cui8csourcer,cui8csourcea);
		cfp_blend_bit8this(ui8cdestinationg,cui8csourceg,cui8csourcea);
		cfp_blend_bit8this(ui8cdestinationb,cui8csourceb,cui8csourcea);
		if constexpr(ceDestinationAlpha){
			AUTO&					ui8cdestinationa=*cpui8cdestinationa;

			ui8cdestinationa=cui8csourcea;
		}
	}else{
		constexpr AUTO			cui8nshiftbitr=UINT8(cui8nOffsetDot<<2);
		AUTO&					ui32csourcer_previous=*cpui32csourcer_previous;
		AUTO&					ui32csourceg_previous=*cpui32csourceg_previous;
		AUTO&					ui32csourceb_previous=*cpui32csourceb_previous;
		AUTO&					ui32csourcea_previous=*cpui32csourcea_previous;

		if constexpr(cui8nshiftbitr<8){
			constexpr AUTO			cui8nshiftbitl_previous=UINT8(8-cui8nshiftbitr);
			CAUTO					cui8csourcer_merged=UINT8((cui8csourcer>>cui8nshiftbitr)|UINT8(ui32csourcer_previous<<cui8nshiftbitl_previous));
			CAUTO					cui8csourceg_merged=UINT8((cui8csourceg>>cui8nshiftbitr)|UINT8(ui32csourceg_previous<<cui8nshiftbitl_previous));
			CAUTO					cui8csourceb_merged=UINT8((cui8csourceb>>cui8nshiftbitr)|UINT8(ui32csourceb_previous<<cui8nshiftbitl_previous));
			CAUTO					cui8csourcea_merged=UINT8((cui8csourcea>>cui8nshiftbitr)|UINT8(ui32csourcea_previous<<cui8nshiftbitl_previous));

			//	<cui8nOffsetDot:1>
			//		previous:--------------X
			//		|0-1 2-3 4-5 6-7|
			//		|   |  8|     16|
			//		|--X|B-B|W-W-W-W|
			//		|   |x B|b W-W-W|w
			//		previous:--------------b
			cfp_blend_bit8this(ui8cdestinationr,cui8csourcer_merged,cui8csourcea_merged);
			cfp_blend_bit8this(ui8cdestinationg,cui8csourceg_merged,cui8csourcea_merged);
			cfp_blend_bit8this(ui8cdestinationb,cui8csourceb_merged,cui8csourcea_merged);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui8cdestinationa=*cpui8cdestinationa;

				ui8cdestinationa=cui8csourcea_merged;
			}
			ui32csourcer_previous=UINT32(cui8csourcer);
			ui32csourceg_previous=UINT32(cui8csourceg);
			ui32csourceb_previous=UINT32(cui8csourceb);
			ui32csourcea_previous=UINT32(cui8csourcea);
		}else{
			constexpr AUTO			cui8nshiftbitr_previous=UINT8(cui8nshiftbitr-8);
			CAUTO					cui8csourcer_merged=UINT8(ui32csourcer_previous>>cui8nshiftbitr_previous);
			CAUTO					cui8csourceg_merged=UINT8(ui32csourceg_previous>>cui8nshiftbitr_previous);
			CAUTO					cui8csourceb_merged=UINT8(ui32csourceb_previous>>cui8nshiftbitr_previous);
			CAUTO					cui8csourcea_merged=UINT8(ui32csourcea_previous>>cui8nshiftbitr_previous);

			//	<cui8nOffsetDot:7>
			//		previous:--X-X-X-X-X-X-X
			//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
			//		|   |   |       |   |  8|     16|
			//		|   |--X|X-X-X-X|X-X|B-B|W-W-W-W|
			//		|               |   |x x|x x x x|x b b w w w w
			//		previous:--x-x-x-x-x-b-b
			cfp_blend_bit8this(ui8cdestinationr,cui8csourcer_merged,cui8csourcea_merged);
			cfp_blend_bit8this(ui8cdestinationg,cui8csourceg_merged,cui8csourcea_merged);
			cfp_blend_bit8this(ui8cdestinationb,cui8csourceb_merged,cui8csourcea_merged);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui8cdestinationa=*(cpui8cdestinationa);

				ui8cdestinationa=cui8csourcea_merged;
			}
			ui32csourcer_previous=(ui32csourcer_previous<<8)|UINT32(cui8csourcer);
			ui32csourceg_previous=(ui32csourceg_previous<<8)|UINT32(cui8csourceg);
			ui32csourceb_previous=(ui32csourceb_previous<<8)|UINT32(cui8csourceb);
			ui32csourcea_previous=(ui32csourcea_previous<<8)|UINT32(cui8csourcea);
		}
	}
	++pui8cdestination;
	return;
}

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend,CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::RGBX_stCopyAlpha_Blend_Line_Offset_Bit16(
	PUINT8&					pui8cdestination,
	CUINT32					cui32ndestinationplanepitch,
	CUINT32					cui32doffsetsourcebase,
	CUINT32					cui32doffsetsourcea,
	CUINT32					cui32nsourceplanepitch,
	const PUINT32			cpui32csourcer_previous,
	const PUINT32			cpui32csourceg_previous,
	const PUINT32			cpui32csourceb_previous,
	const PUINT32			cpui32csourcea_previous
)noexcept{
	constexpr AUTO			cfp_blend_bit16this=stfp_blend_bit16GetThis<cidBlend>();
	CAUTO					cpui8cdestinationr=pui8cdestination;
	CAUTO					cpui8cdestinationg=cpui8cdestinationr+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationb=cpui8cdestinationg+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationa=cpui8cdestinationb+cui32ndestinationplanepitch;
	AUTO&					ui16cdestinationr=*PUINT16(cpui8cdestinationr);
	AUTO&					ui16cdestinationg=*PUINT16(cpui8cdestinationg);
	AUTO&					ui16cdestinationb=*PUINT16(cpui8cdestinationb);
	CAUTO					cpcui8csourcer=PCUINT8(pui8cdestination+cui32doffsetsourcebase);
	CAUTO					cpcui8csourceg=cpcui8csourcer+cui32nsourceplanepitch;
	CAUTO					cpcui8csourceb=cpcui8csourceg+cui32nsourceplanepitch;
	CAUTO					cpcui8csourcea=PCUINT8(pui8cdestination+cui32doffsetsourcea);
	CAUTO					cui16csourcer=*PCUINT16(cpcui8csourcer);
	CAUTO					cui16csourceg=*PCUINT16(cpcui8csourceg);
	CAUTO					cui16csourceb=*PCUINT16(cpcui8csourceb);
	CAUTO					cui16csourcea=*PCUINT16(cpcui8csourcea);

	if constexpr(cui8nOffsetDot==0){
		cfp_blend_bit16this(ui16cdestinationr,cui16csourcer,cui16csourcea);
		cfp_blend_bit16this(ui16cdestinationg,cui16csourceg,cui16csourcea);
		cfp_blend_bit16this(ui16cdestinationb,cui16csourceb,cui16csourcea);
		if constexpr(ceDestinationAlpha){
			AUTO&					ui16cdestinationa=*PUINT16(cpui8cdestinationa);

			ui16cdestinationa=cui16csourcea;
		}
	}else{
		constexpr AUTO			cui8nshiftbitr=UINT8(cui8nOffsetDot<<2);
		AUTO&					ui32csourcer_previous=*cpui32csourcer_previous;
		AUTO&					ui32csourceg_previous=*cpui32csourceg_previous;
		AUTO&					ui32csourceb_previous=*cpui32csourceb_previous;
		AUTO&					ui32csourcea_previous=*cpui32csourcea_previous;

		if constexpr(cui8nshiftbitr<16){
			constexpr AUTO			cui8nshiftbitl_previous=UINT8(16-cui8nshiftbitr);
			CAUTO					cui16csourcer_merged=UINT16((cui16csourcer>>cui8nshiftbitr)|UINT16(ui32csourcer_previous<<cui8nshiftbitl_previous));
			CAUTO					cui16csourceg_merged=UINT16((cui16csourceg>>cui8nshiftbitr)|UINT16(ui32csourceg_previous<<cui8nshiftbitl_previous));
			CAUTO					cui16csourceb_merged=UINT16((cui16csourceb>>cui8nshiftbitr)|UINT16(ui32csourceb_previous<<cui8nshiftbitl_previous));
			CAUTO					cui16csourcea_merged=UINT16((cui16csourcea>>cui8nshiftbitr)|UINT16(ui32csourcea_previous<<cui8nshiftbitl_previous));

			//	<cui8nOffsetDot:1>
			//		previous:--------------X
			//		|0-1 2-3 4-5 6-7|
			//		|   |   |     16|
			//		|   |--X|W-W-W-W|
			//		|       |x W-W-W|w
			//		previous:--------------w
			cfp_blend_bit16this(ui16cdestinationr,cui16csourcer_merged,cui16csourcea_merged);
			cfp_blend_bit16this(ui16cdestinationg,cui16csourceg_merged,cui16csourcea_merged);
			cfp_blend_bit16this(ui16cdestinationb,cui16csourceb_merged,cui16csourcea_merged);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui16cdestinationa=*PUINT16(cpui8cdestinationa);

				ui16cdestinationa=cui16csourcea_merged;
			}
			ui32csourcer_previous=UINT32(cui16csourcer);
			ui32csourceg_previous=UINT32(cui16csourceg);
			ui32csourceb_previous=UINT32(cui16csourceb);
			ui32csourcea_previous=UINT32(cui16csourcea);
		}else{
			constexpr AUTO			cui8nshiftbitr_previous=UINT8(cui8nshiftbitr-16);
			CAUTO					cui16csourcer_merged=UINT16(ui32csourcer_previous>>cui8nshiftbitr_previous);
			CAUTO					cui16csourceg_merged=UINT16(ui32csourceg_previous>>cui8nshiftbitr_previous);
			CAUTO					cui16csourceb_merged=UINT16(ui32csourceb_previous>>cui8nshiftbitr_previous);
			CAUTO					cui16csourcea_merged=UINT16(ui32csourcea_previous>>cui8nshiftbitr_previous);

			//	<cui8nOffsetDot:7>
			//		previous:--X-X-X-X-X-X-X
			//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
			//		|       |       |       |     16|
			//		|       |--X-X-X|X-X-X-X|W-W-W-W|
			//		|               |       |x x x x|x x x w w w w
			//		previous:--x-x-x-w-w-w-w
			cfp_blend_bit16this(ui16cdestinationr,cui16csourcer_merged,cui16csourcea_merged);
			cfp_blend_bit16this(ui16cdestinationg,cui16csourceg_merged,cui16csourcea_merged);
			cfp_blend_bit16this(ui16cdestinationb,cui16csourceb_merged,cui16csourcea_merged);
			if constexpr(ceDestinationAlpha){
				AUTO&					ui16cdestinationa=*PUINT16(cpui8cdestinationa);

				ui16cdestinationa=cui16csourcea_merged;
			}
			ui32csourcer_previous=(ui32csourcer_previous<<16)|UINT32(cui16csourcer);
			ui32csourceg_previous=(ui32csourceg_previous<<16)|UINT32(cui16csourceg);
			ui32csourceb_previous=(ui32csourceb_previous<<16)|UINT32(cui16csourceb);
			ui32csourcea_previous=(ui32csourcea_previous<<16)|UINT32(cui16csourcea);
		}
	}
	pui8cdestination+=2;
	return;
}

template<COFWBOOL ceDestinationAlpha,const CANVAS_::IDBLEND cidBlend,CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::RGBX_stCopyAlpha_Blend_Line_Offset_Bit32(
	PUINT8&					pui8cdestination,
	CUINT32					cui32ndestinationplanepitch,
	CUINT32					cui32doffsetsourcebase,
	CUINT32					cui32doffsetsourcea,
	CUINT32					cui32nsourceplanepitch,
	const PUINT32			cpui32csourcer_previous,
	const PUINT32			cpui32csourceg_previous,
	const PUINT32			cpui32csourceb_previous,
	const PUINT32			cpui32csourcea_previous
)noexcept{
	constexpr AUTO			cfp_blend_bit32this=stfp_blend32GetThis<cidBlend>();
	CAUTO					cpui8cdestinationr=pui8cdestination;
	CAUTO					cpui8cdestinationg=cpui8cdestinationr+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationb=cpui8cdestinationg+cui32ndestinationplanepitch;
	CAUTO					cpui8cdestinationa=cpui8cdestinationb+cui32ndestinationplanepitch;
	AUTO&					ui32cdestinationr=*PUINT32(cpui8cdestinationr);
	AUTO&					ui32cdestinationg=*PUINT32(cpui8cdestinationg);
	AUTO&					ui32cdestinationb=*PUINT32(cpui8cdestinationb);
	CAUTO					cpcui8csourcer=PCUINT8(pui8cdestination+cui32doffsetsourcebase);
	CAUTO					cpcui8csourceg=cpcui8csourcer+cui32nsourceplanepitch;
	CAUTO					cpcui8csourceb=cpcui8csourceg+cui32nsourceplanepitch;
	CAUTO					cpcui8csourcea=PCUINT8(pui8cdestination+cui32doffsetsourcea);
	CAUTO					cui32csourcer=*PCUINT32(cpcui8csourcer);
	CAUTO					cui32csourceg=*PCUINT32(cpcui8csourceg);
	CAUTO					cui32csourceb=*PCUINT32(cpcui8csourceb);
	CAUTO					cui32csourcea=*PCUINT32(cpcui8csourcea);

	if constexpr(cui8nOffsetDot==0){
		cfp_blend_bit32this(ui32cdestinationr,cui32csourcer,cui32csourcea);
		cfp_blend_bit32this(ui32cdestinationg,cui32csourceg,cui32csourcea);
		cfp_blend_bit32this(ui32cdestinationb,cui32csourceb,cui32csourcea);
		if constexpr(ceDestinationAlpha){
			AUTO&					ui32cdestinationa=*PUINT32(cpui8cdestinationa);

			ui32cdestinationa=cui32csourcea;
		}
	}else{
		constexpr AUTO			cui8nshiftbitr=UINT8(cui8nOffsetDot<<2);
		constexpr AUTO			cui8nshiftbitl_previous=UINT8(32-cui8nshiftbitr);
		AUTO&					ui32csourcer_previous=*cpui32csourcer_previous;
		AUTO&					ui32csourceg_previous=*cpui32csourceg_previous;
		AUTO&					ui32csourceb_previous=*cpui32csourceb_previous;
		AUTO&					ui32csourcea_previous=*cpui32csourcea_previous;
		CAUTO					cui32csourcer_merged=UINT32((cui32csourcer>>cui8nshiftbitr)|(ui32csourcer_previous<<cui8nshiftbitl_previous));
		CAUTO					cui32csourceg_merged=UINT32((cui32csourceg>>cui8nshiftbitr)|(ui32csourceg_previous<<cui8nshiftbitl_previous));
		CAUTO					cui32csourceb_merged=UINT32((cui32csourceb>>cui8nshiftbitr)|(ui32csourceb_previous<<cui8nshiftbitl_previous));
		CAUTO					cui32csourcea_merged=UINT32((cui32csourcea>>cui8nshiftbitr)|(ui32csourcea_previous<<cui8nshiftbitl_previous));

		//	<cui8nOffsetDot:1>
		//		previous:--------------X
		//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//		|           |   |             32|
		//		|           |--X|D-D-D-D-D-D-D-D|
		//		|               |x D-D-D-D-D-D-D|d
		//		previous:--------------d
		//	<cui8nOffsetDot:7>
		//		previous:--X-X-X-X-X-X-X
		//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//		|               |             32|
		//		|--X-X-X-X-X-X-X|D-D-D-D-D-D-D-D|
		//		|               |x x x x x x x D|d d d d d d d
		//		previous:--d-d-d-d-d-d-d
		cfp_blend_bit32this(ui32cdestinationr,cui32csourcer_merged,cui32csourcea_merged);
		cfp_blend_bit32this(ui32cdestinationg,cui32csourceg_merged,cui32csourcea_merged);
		cfp_blend_bit32this(ui32cdestinationb,cui32csourceb_merged,cui32csourcea_merged);
		if constexpr(ceDestinationAlpha){
			AUTO&					ui32cdestinationa=*PUINT32(cpui8cdestinationa);

			ui32cdestinationa=cui32csourcea_merged;
		}
		ui32csourcer_previous=cui32csourcer;
		ui32csourceg_previous=cui32csourceg;
		ui32csourceb_previous=cui32csourceb;
		ui32csourcea_previous=cui32csourcea;
	}
	pui8cdestination+=4;
	return;
}

//	定数塗りつぶし(A)

_INLINE_ VOID			CANVAS_::A_stFill_Line(
	const PUINT8			cpui8cdestination,
	CUINT32					cui32idestinationdotposition,
	CUINT16					cui16ndestinationhdotline,
	CUINT32					cui32csource
)noexcept{
	if(cui16ndestinationhdotline){
		AUTO					pui8cdestination=cpui8cdestination+(cui32idestinationdotposition>>1);
		//	PUINT8					cpui8cdestination_end
		//		コピー終了条件に使いますが、注意すべきは「右端数1ドット」を含まない事。
		//		含めてしまうと、「2、4、8ドットコピー可」と誤認されてしまう。
		//		「右端数1ドット」があるかどうかは「(cui32idestinationdotposition+cui32ndestinationhdotline)&1」で判定する。
		AUTO					cpui8cdestination_end=cpui8cdestination+((cui32idestinationdotposition+UINT32(cui16ndestinationhdotline))>>1);
		CAUTO					cfp_fraction4l=[&](VOID)noexcept{
			//	終了位置に「端数1ドット」あるなら、残りを解消。
			//	1バイト未満で「pui8cdestination」には現れないので、
			//	「(cui32idestinationdotposition+cui32ndestinationhdotline)&1」で判定。
			//	ここまでで1ドット超過の端数は処理済みであるので、
			//	「pui8cdestination」のような進行状況変数を見る必要は無い。
			if((UINT8(cui32idestinationdotposition)+UINT8(cui16ndestinationhdotline))&1){
				A_stFill_Line_Bit4L(pui8cdestination,UINT8(cui32csource));
			}
			return;
		};
		CAUTO					cfp_fraction8=[&](VOID)noexcept{
			//	終了位置に「端数2～4ドット」あるなら、「2ドット(1バイト)」分解消。
			if(pui8cdestination+1<=cpui8cdestination_end){
				A_stFill_Line_Bit8(pui8cdestination,UINT8(cui32csource));
			}
			cfp_fraction4l();
			return;
		};
		CAUTO					cfp_fraction16=[&](VOID)noexcept{
			//	終了位置に「端数4～8ドット」あるなら、「4ドット(2バイト)」分解消。
			if(pui8cdestination+2<=cpui8cdestination_end){
				A_stFill_Line_Bit16(pui8cdestination,UINT16(cui32csource));
			}
			cfp_fraction8();
			return;
		};

		//	まずは「左端数1ドット」があるか判定するが、
		//	「pui8cdestination」には現れないので「cui32ndestinationdotposition」で判定する。
		//	これは更新前の処理初段であるから通用する方法。
		if(cui32idestinationdotposition&1){
			//	開始位置に「端数1ドット」があるので、それを解消する。
			A_stFill_Line_Bit4R(pui8cdestination,UINT8(cui32csource));
		}
		//	この時点で処理対象位置は2の倍数になっている。
		if(PTRINT(pui8cdestination)&1){
			//	開始位置に「端数2ドット(1バイト)」があるので、それを解消する。
			if(cpui8cdestination_end<pui8cdestination+1){
				cfp_fraction4l();
				return;
			}
			A_stFill_Line_Bit8(pui8cdestination,UINT8(cui32csource));
		}
		//	この時点で処理対象位置は4の倍数になっている。
		if(PTRINT(pui8cdestination)&2){
			//	開始位置に「端数4ドット(2バイト)」があるので、それを解消する。
			if(cpui8cdestination_end<pui8cdestination+2){
				cfp_fraction8();
				return;
			}
			A_stFill_Line_Bit16(pui8cdestination,UINT16(cui32csource));
		}
		//	この時点で処理対象位置は8の倍数になっている。
		if(pui8cdestination+4<=cpui8cdestination_end){
			CAUTO					cpui8cdestination_endm4=cpui8cdestination_end-4;

			while(pui8cdestination<=cpui8cdestination_endm4)A_stFill_Line_Bit32(pui8cdestination,cui32csource);
		}
		cfp_fraction16();
	}
	return;
}

_INLINE_ VOID			CANVAS_::A_stFill_Line_Bit4L(
	PUINT8&					pui8cdestination,
	CUINT8					cui8csource
)noexcept{
	AUTO&					ui8cdestination=*pui8cdestination;

	ui8cdestination=(ui8cdestination&0x0f)|(cui8csource&0xf0);
	return;
}

_INLINE_ VOID			CANVAS_::A_stFill_Line_Bit4R(
	PUINT8&					pui8cdestination,
	CUINT8					cui8csource
)noexcept{
	AUTO&					ui8cdestination=*pui8cdestination;

	ui8cdestination=(ui8cdestination&0xf0)|(cui8csource&0x0f);
	++pui8cdestination;
	return;
}

_INLINE_ VOID			CANVAS_::A_stFill_Line_Bit8(
	PUINT8&					pui8cdestination,
	CUINT8					cui8csource
)noexcept{
	AUTO&					ui8cdestination=*pui8cdestination;

	ui8cdestination=cui8csource;
	++pui8cdestination;
	return;
}

_INLINE_ VOID			CANVAS_::A_stFill_Line_Bit16(
	PUINT8&					pui8cdestination,
	CUINT16					cui16csource
)noexcept{
	AUTO&					ui16cdestination=*PUINT16(pui8cdestination);

	ui16cdestination=cui16csource;
	pui8cdestination+=2;
	return;
}

_INLINE_ VOID			CANVAS_::A_stFill_Line_Bit32(
	PUINT8&					pui8cdestination,
	CUINT32					cui32csource
)noexcept{
	AUTO&					ui32cdestination=*PUINT32(pui8cdestination);

	ui32cdestination=cui32csource;
	pui8cdestination+=4;
	return;
}

//	画像コピー(A)

_INLINE_ VOID			CANVAS_::A_stCopy_Line(
	const PUINT8			cpui8cdestination,
	CUINT32					cui32idestinationdotposition,
	CUINT16					cui16ndestinationhdotline,
	const PCUINT8			cpcui8csource,
	CUINT32					cui32isourcedotposition
)noexcept{
	switch(UINT8(cui32idestinationdotposition-cui32isourcedotposition)&7){
	case 0:
		A_stCopy_Line_Offset<0>(cpui8cdestination,cui32idestinationdotposition,cui16ndestinationhdotline,cpcui8csource,cui32isourcedotposition);
		break;
	case 1:
		A_stCopy_Line_Offset<1>(cpui8cdestination,cui32idestinationdotposition,cui16ndestinationhdotline,cpcui8csource,cui32isourcedotposition);
		break;
	case 2:
		A_stCopy_Line_Offset<2>(cpui8cdestination,cui32idestinationdotposition,cui16ndestinationhdotline,cpcui8csource,cui32isourcedotposition);
		break;
	case 3:
		A_stCopy_Line_Offset<3>(cpui8cdestination,cui32idestinationdotposition,cui16ndestinationhdotline,cpcui8csource,cui32isourcedotposition);
		break;
	case 4:
		A_stCopy_Line_Offset<4>(cpui8cdestination,cui32idestinationdotposition,cui16ndestinationhdotline,cpcui8csource,cui32isourcedotposition);
		break;
	case 5:
		A_stCopy_Line_Offset<5>(cpui8cdestination,cui32idestinationdotposition,cui16ndestinationhdotline,cpcui8csource,cui32isourcedotposition);
		break;
	case 6:
		A_stCopy_Line_Offset<6>(cpui8cdestination,cui32idestinationdotposition,cui16ndestinationhdotline,cpcui8csource,cui32isourcedotposition);
		break;
	case 7:
		A_stCopy_Line_Offset<7>(cpui8cdestination,cui32idestinationdotposition,cui16ndestinationhdotline,cpcui8csource,cui32isourcedotposition);
		break;
	}
	return;
}

template<CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::A_stCopy_Line_Offset(
	const PUINT8			cpui8cdestination,
	CUINT32					cui32idestinationdotposition,
	CUINT16					cui16ndestinationhdotline,
	const PCUINT8			cpcui8csource,
	CUINT32					cui32isourcedotposition
)noexcept{
	if(cui16ndestinationhdotline){
		AUTO					pui8cdestination=cpui8cdestination+(cui32idestinationdotposition>>1);
		//	PUINT8					cpui8cdestination_end
		//		コピー終了条件に使いますが、注意すべきは「右端数1ドット」を含まない事。
		//		含めてしまうと、「2、4、8ドットコピー可」と誤認されてしまう。
		//		「右端数1ドット」があるかどうかは「(cui32idestinationdotposition+cui32ndestinationhdotline)&1」で判定する。
		AUTO					cpui8cdestination_end=cpui8cdestination+((cui32idestinationdotposition+UINT32(cui16ndestinationhdotline))>>1);
		CAUTO					cui32isourceposition=UINT32((cui32isourcedotposition+UINT32((cui8nOffsetDot&1)?cui8nOffsetDot:UINT8(0)))>>1);
		CAUTO					cpcui8csource_positioned=cpcui8csource+cui32isourceposition;
		CAUTO					cui32doffsetsource=UINT32(cpcui8csource_positioned-pui8cdestination);

		if constexpr((cui8nOffsetDot&1)==0){
			CAUTO					cfp_fraction4l=[&](VOID)noexcept{
				//	終了位置に「端数1ドット」あるなら、残りを解消。
				//	1バイト未満で「pui8cdestination」には現れないので、
				//	「(cui32idestinationdotposition+cui32ndestinationhdotline)&1」で判定。
				//	ここまでで1ドット超過の端数は処理済みであるので、
				//	「pui8cdestination」のような進行状況変数を見る必要は無い。
				if((UINT8(cui32idestinationdotposition)+UINT8(cui16ndestinationhdotline))&1){
					A_stCopy_Line_Offset_Bit4L(pui8cdestination,cui32doffsetsource);
				}
				return;
			};
			CAUTO					cfp_fraction8=[&](VOID)noexcept{
				//	終了位置に「端数2～4ドット」あるなら、「2ドット(1バイト)」分解消。
				if(pui8cdestination+1<=cpui8cdestination_end){
					A_stCopy_Line_Offset_Bit8(pui8cdestination,cui32doffsetsource);
				}
				cfp_fraction4l();
				return;
			};
			CAUTO					cfp_fraction16=[&](VOID)noexcept{
				//	終了位置に「端数4～8ドット」あるなら、「4ドット(2バイト)」分解消。
				if(pui8cdestination+2<=cpui8cdestination_end){
					A_stCopy_Line_Offset_Bit16(pui8cdestination,cui32doffsetsource);
				}
				cfp_fraction8();
				return;
			};

			//	参照ドット位置の差は2の倍数なので、最悪でもバイト単位転送にはできる。
			//	「ビットシフトありの4バイト単位処理」と「ビットシフト無しの1バイト単位処理」のどちらが速いか定かでないが、
			//	一旦「ビットシフト無しの方が速い」とする。
			//	まずは「左端数1ドット」があるか判定するが、
			//	「pui8cdestination」には現れないので「cui32ndestinationdotposition」で判定する。
			//	これは更新前の処理初段であるから通用する方法。
			if(cui32idestinationdotposition&1){
				//	差は2の倍数なれど、開始位置に「端数1ドット」があるので、それを解消する。
				A_stCopy_Line_Offset_Bit4R(pui8cdestination,cui32doffsetsource);
			}
			//	この時点で参照ドット位置の差、処理対象位置共に2の倍数になっている。
			if constexpr((cui8nOffsetDot&2)==0){
				//	参照ドット位置の差は4の倍数なので、最悪でもワード単位転送にはできる。
				if(PTRINT(pui8cdestination)&1){
					//	差は4の倍数なれど、開始位置に「端数2ドット(1バイト)」があるので、それを解消する。
					if(cpui8cdestination_end<pui8cdestination+1){
						cfp_fraction4l();
						return;
					}
					A_stCopy_Line_Offset_Bit8(pui8cdestination,cui32doffsetsource);
				}
				//	この時点で参照ドット位置の差、処理対象位置共に4の倍数になっている。
				if constexpr((cui8nOffsetDot&4)==0){
					//	参照ドット位置の差は8の倍数なので、ダブルワード単位転送にできる。
					if(PTRINT(pui8cdestination)&2){
						//	差は8の倍数なれど、開始位置に「端数4ドット(2バイト)」があるので、それを解消する。
						if(cpui8cdestination_end<pui8cdestination+2){
							cfp_fraction8();
							return;
						}
						A_stCopy_Line_Offset_Bit16(pui8cdestination,cui32doffsetsource);
					}
					//	この時点で参照ドット位置の差、処理対象位置共に8の倍数になっている。
					if(pui8cdestination+4<=cpui8cdestination_end){
						CAUTO					cpui8cdestination_endm4=cpui8cdestination_end-4;

						while(pui8cdestination<=cpui8cdestination_endm4)A_stCopy_Line_Offset_Bit32(pui8cdestination,cui32doffsetsource);
					}
					cfp_fraction16();
				}else{
					//	差は4の倍数なれど8の倍数ではなかった。
					if(pui8cdestination+2<=cpui8cdestination_end){
						CAUTO					cpui8cdestination_endm2=cpui8cdestination_end-2;

						while(pui8cdestination<=cpui8cdestination_endm2)A_stCopy_Line_Offset_Bit16(pui8cdestination,cui32doffsetsource);
					}
					cfp_fraction8();
				}
			}else{
				//	差は2の倍数なれど4の倍数ではなかった。
				if(pui8cdestination+1<=cpui8cdestination_end){
					CAUTO					cpui8cdestination_endm1=cpui8cdestination_end-1;

					while(pui8cdestination<=cpui8cdestination_endm1)A_stCopy_Line_Offset_Bit8(pui8cdestination,cui32doffsetsource);
				}
				cfp_fraction4l();
			}
		}else{
			UINT32					ui32csource_previous=0x00000000;
			CAUTO					cfp_fraction4l=[&](VOID)noexcept{
				//	終了位置に「端数1ドット」あるなら、残りを解消。
				//	1バイト未満で「pui8cdestination」には現れないので、
				//	「(cui32idestinationdotposition+cui32ndestinationhdotline)&1」で判定。
				//	ここまでで1ドット超過の端数は処理済みであるので、
				//	「pui8cdestination」のような進行状況変数を見る必要は無い。
				if((UINT8(cui32idestinationdotposition)+UINT8(cui16ndestinationhdotline))&1){
					A_stCopy_Line_Offset_Bit4L<cui8nOffsetDot>(pui8cdestination,cui32doffsetsource,&ui32csource_previous);
				}
				return;
			};
			CAUTO					cfp_fraction8=[&](VOID)noexcept{
				if(pui8cdestination+1<=cpui8cdestination_end){
					A_stCopy_Line_Offset_Bit8<cui8nOffsetDot>(pui8cdestination,cui32doffsetsource,&ui32csource_previous);
				}
				cfp_fraction4l();
				return;
			};
			CAUTO					cfp_fraction16=[&](VOID)noexcept{
				if(pui8cdestination+2<=cpui8cdestination_end){
					A_stCopy_Line_Offset_Bit16<cui8nOffsetDot>(pui8cdestination,cui32doffsetsource,&ui32csource_previous);
				}
				cfp_fraction8();
				return;
			};

			stMakePrevious_Offset<cui8nOffsetDot>(cui32idestinationdotposition,cpcui8csource_positioned,ui32csource_previous);
			//	書き込み位置32bitアラインを目指し、「左側端数ドット」をコピーする。
			//	まずは「左端数1ドット」があるか判定するが、
			//	「pui8cdestination」には現れないので「cui32ndestinationdotposition」で判定する。
			//	これは更新前の処理初段であるから通用する方法。
			if(cui32idestinationdotposition&1){
				A_stCopy_Line_Offset_Bit4R<cui8nOffsetDot>(pui8cdestination,cui32doffsetsource,&ui32csource_previous);
			}
			if(PTRINT(pui8cdestination)&1){
				if(cpui8cdestination_end<pui8cdestination+1){
					cfp_fraction4l();
					return;
				}
				A_stCopy_Line_Offset_Bit8<cui8nOffsetDot>(pui8cdestination,cui32doffsetsource,&ui32csource_previous);
			}
			if(PTRINT(pui8cdestination)&2){
				if(cpui8cdestination_end<pui8cdestination+2){
					cfp_fraction8();
					return;
				}
				A_stCopy_Line_Offset_Bit16<cui8nOffsetDot>(pui8cdestination,cui32doffsetsource,&ui32csource_previous);
			}
			//	書き込み位置32bitアラインできたのでコピーループに入る。
			if(pui8cdestination+4<=cpui8cdestination_end){
				CAUTO					cpui8cdestination_endm4=cpui8cdestination_end-4;

				while(pui8cdestination<=cpui8cdestination_endm4)A_stCopy_Line_Offset_Bit32<cui8nOffsetDot>(pui8cdestination,cui32doffsetsource,&ui32csource_previous);
			}
			//	32bitアラインコピー出来る分は全て片付けたので、「右側端数ドット」をコピーする。
			cfp_fraction16();
		}
	}
	return;
}

template<CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::A_stCopy_Line_Offset_Bit4L(
	PUINT8&					pui8cdestination,
	CUINT32					cui32doffsetsource,
	const PUINT32			cpui32csource_previous
)noexcept{
	AUTO&					ui8cdestination=*pui8cdestination;

	if constexpr(cui8nOffsetDot==0){
		CAUTO					cpcui8csource=PCUINT8(pui8cdestination+cui32doffsetsource);
		CAUTO					cui8csource=*cpcui8csource;

		ui8cdestination=(ui8cdestination&0x0f)|(cui8csource&0xf0);
	}else{
		constexpr AUTO			cui8nshiftbitr=UINT8(cui8nOffsetDot<<2);
		constexpr AUTO			cui8nshiftbitr_previous=UINT8(cui8nshiftbitr-4);
		CAUTO					cui32csource_previous=*cpui32csource_previous;
		CAUTO					cui8csource_merged=UINT8((cui32csource_previous>>cui8nshiftbitr_previous)<<4);

		//	<cui8nOffsetDot:1>
		//		previous:--------------X
		//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//		|           |   | 4L|
		//		|           |--X|   |
		//		|               |x  |
		//		previous:---------------
		//	<cui8nOffsetDot:7>
		//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//		previous:--------------X
		//		|               | 4L|
		//		|X              |   |
		//		|               |x  |
		//		previous:---------------
		ui8cdestination=(ui8cdestination&0x0f)|(cui8csource_merged&0xf0);
	}
	return;
}

template<CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::A_stCopy_Line_Offset_Bit4R(
	PUINT8&					pui8cdestination,
	CUINT32					cui32doffsetsourcebase,
	const PUINT32			cpui32csource_previous
)noexcept{
	AUTO&					ui8cdestination=*pui8cdestination;
	CAUTO					cpcui8csource=PCUINT8(pui8cdestination+cui32doffsetsourcebase);
	CAUTO					cui8csource=*cpcui8csource;

	if constexpr(cui8nOffsetDot==0){
		ui8cdestination=(ui8cdestination&0xf0)|(cui8csource&0x0f);
	}else{
		constexpr AUTO			cui8nshiftbitr=UINT8(cui8nOffsetDot<<2);
		AUTO&					ui32csource_previous=*cpui32csource_previous;

		if constexpr(cui8nshiftbitr<8){
			CAUTO					cui8csource_merged=UINT8(cui8csource>>cui8nshiftbitr);

			//	<cui8nOffsetDot:1>
			//		previous:--------------X
			//		|0-1 2-3 4-5 6-7|
			//		| 4R|  8|     16|
			//		|R-R|B-B|W-W-W-W|
			//		|  R|r B|b W-W-W|w
			//		previous:--------------r
			ui8cdestination=(ui8cdestination&0xf0)|(cui8csource_merged&0x0f);
			ui32csource_previous=UINT32(cui8csource);
		}else{
			constexpr AUTO			cui8nshiftbitr_previous=UINT8(cui8nshiftbitr-8);
			CAUTO					cui8csource_merged=UINT8(ui32csource_previous>>cui8nshiftbitr_previous);

			//	<cui8nOffsetDot:7>
			//		previous:----X-X-X-X-X-X
			//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
			//		|   |   |       | 4R|  8|     16|
			//		|   |X-X|X-X-X-X|R-R|B-B|W-W-W-W|
			//		|               |  x|x x|x x x r|r b b w w w w
			//		previous:----X-X-X-X-r-r
			ui8cdestination=(ui8cdestination&0xf0)|(cui8csource_merged&0x0f);
			ui32csource_previous=(ui32csource_previous<<8)|UINT32(cui8csource);
		}
	}
	++pui8cdestination;
	return;
}

template<CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::A_stCopy_Line_Offset_Bit8(
	PUINT8&					pui8cdestination,
	CUINT32					cui32doffsetsource,
	const PUINT32			cpui32csource_previous
)noexcept{
	AUTO&					ui8cdestination=*pui8cdestination;
	CAUTO					cpcui8csource=PCUINT8(pui8cdestination+cui32doffsetsource);
	CAUTO					cui8csource=*cpcui8csource;

	if constexpr(cui8nOffsetDot==0){
		ui8cdestination=cui8csource;
	}else{
		constexpr AUTO			cui8nshiftbitr=UINT8(cui8nOffsetDot<<2);
		AUTO&					ui32csource_previous=*cpui32csource_previous;

		if constexpr(cui8nshiftbitr<8){
			constexpr AUTO			cui8nshiftbitl_previous=UINT8(8-cui8nshiftbitr);
			CAUTO					cui8csource_merged=UINT8((cui8csource>>cui8nshiftbitr)|UINT8(ui32csource_previous<<cui8nshiftbitl_previous));

			//	<cui8nOffsetDot:1>
			//		previous:--------------X
			//		|0-1 2-3 4-5 6-7|
			//		|   |  8|     16|
			//		|--X|B-B|W-W-W-W|
			//		|   |x B|b W-W-W|w
			//		previous:--------------b
			ui8cdestination=cui8csource_merged;
			ui32csource_previous=UINT32(cui8csource);
		}else{
			constexpr AUTO			cui8nshiftbitr_previous=UINT8(cui8nshiftbitr-8);
			CAUTO					cui8csource_merged=UINT8(ui32csource_previous>>cui8nshiftbitr_previous);

			//	<cui8nOffsetDot:7>
			//		previous:--X-X-X-X-X-X-X
			//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
			//		|   |   |       |   |  8|     16|
			//		|   |--X|X-X-X-X|X-X|B-B|W-W-W-W|
			//		|               |   |x x|x x x x|x b b w w w w
			//		previous:--x-x-x-x-x-b-b
			ui8cdestination=cui8csource_merged;
			ui32csource_previous=(ui32csource_previous<<8)|UINT32(cui8csource);
		}
	}
	++pui8cdestination;
	return;
}

template<CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::A_stCopy_Line_Offset_Bit16(
	PUINT8&					pui8cdestination,
	CUINT32					cui32doffsetsource,
	const PUINT32			cpui32csource_previous
)noexcept{
	AUTO&					ui16cdestination=*PUINT16(pui8cdestination);
	CAUTO					cpcui8csource=PCUINT8(pui8cdestination+cui32doffsetsource);
	CAUTO					cui16csource=*PCUINT16(cpcui8csource);

	if constexpr(cui8nOffsetDot==0){
		ui16cdestination=cui16csource;
	}else{
		constexpr AUTO			cui8nshiftbitr=UINT8(cui8nOffsetDot<<2);
		AUTO&					ui32csource_previous=*cpui32csource_previous;

		if constexpr(cui8nshiftbitr<16){
			constexpr AUTO			cui8nshiftbitl_previous=UINT8(16-cui8nshiftbitr);
			CAUTO					cui16csource_merged=UINT16((cui16csource>>cui8nshiftbitr)|UINT16(ui32csource_previous<<cui8nshiftbitl_previous));

			//	<cui8nOffsetDot:1>
			//		previous:--------------X
			//		|0-1 2-3 4-5 6-7|
			//		|   |   |     16|
			//		|   |--X|W-W-W-W|
			//		|       |x W-W-W|w
			//		previous:--------------w
			ui16cdestination=cui16csource_merged;
			ui32csource_previous=UINT32(cui16csource);
		}else{
			constexpr AUTO			cui8nshiftbitr_previous=UINT8(cui8nshiftbitr-16);
			CAUTO					cui16csource_merged=UINT16(ui32csource_previous>>cui8nshiftbitr_previous);

			//	<cui8nOffsetDot:7>
			//		previous:--X-X-X-X-X-X-X
			//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
			//		|       |       |       |     16|
			//		|       |--X-X-X|X-X-X-X|W-W-W-W|
			//		|               |       |x x x x|x x x w w w w
			//		previous:--x-x-x-w-w-w-w
			ui16cdestination=cui16csource_merged;
			ui32csource_previous=(ui32csource_previous<<16)|UINT32(cui16csource);
		}
	}
	pui8cdestination+=2;
	return;
}

template<CUINT8 cui8nOffsetDot>
_INLINE_ VOID			CANVAS_::A_stCopy_Line_Offset_Bit32(
	PUINT8&					pui8cdestination,
	CUINT32					cui32doffsetsource,
	const PUINT32			cpui32csource_previous
)noexcept{
	AUTO&					ui32cdestination=*PUINT32(pui8cdestination);
	CAUTO					cpcui8csource=PCUINT8(pui8cdestination+cui32doffsetsource);
	CAUTO					cui32csource=*PCUINT32(cpcui8csource);

	if constexpr(cui8nOffsetDot==0){
		ui32cdestination=cui32csource;
	}else{
		constexpr AUTO			cui8nshiftbitr=UINT8(cui8nOffsetDot<<2);
		constexpr AUTO			cui8nshiftbitl_previous=UINT8(32-cui8nshiftbitr);
		AUTO&					ui32csource_previous=*cpui32csource_previous;
		CAUTO					cui32csource_merged=UINT32((cui32csource>>cui8nshiftbitr)|(ui32csource_previous<<cui8nshiftbitl_previous));

		//	<cui8nOffsetDot:1>
		//		previous:--------------X
		//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//		|           |   |             32|
		//		|           |--X|D-D-D-D-D-D-D-D|
		//		|               |x D-D-D-D-D-D-D|d
		//		previous:--------------d
		//	<cui8nOffsetDot:7>
		//		previous:--X-X-X-X-X-X-X
		//		|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|0-1 2-3 4-5 6-7|
		//		|               |             32|
		//		|--X-X-X-X-X-X-X|D-D-D-D-D-D-D-D|
		//		|               |x x x x x x x D|d d d d d d d
		//		previous:--d-d-d-d-d-d-d
		ui32cdestination=cui32csource_merged;
		ui32csource_previous=cui32csource;
	}
	pui8cdestination+=4;
	return;
}

//	ブレンド関数

template<const CANVAS_::IDBLEND cidBlend>
constexpr CANVAS_::FP_BLEND_BIT4L	CANVAS_::stfp_blend_bit4lGetThis(VOID)noexcept{
	switch(cidBlend){
	case IDBLEND::Source:
		return [](UINT8& ui8cdestination,CUINT8 cui8csource,CUINT8 cui8calpha)noexcept{
			ui8cdestination=(ui8cdestination&0x0f)|(cui8csource&0xf0);
			return;
		};
	case IDBLEND::BackNega_Source:
		return [](UINT8& ui8cdestination,CUINT8 cui8csource,CUINT8 cui8calpha)noexcept{
			ui8cdestination=(ui8cdestination&0x0f)|stui8cBackNega_Source_Bit4L(ui8cdestination,cui8csource,cui8calpha);
			return;
		};
	case IDBLEND::BackNega_SourceAlpha:
		return [](UINT8& ui8cdestination,CUINT8 cui8csource,CUINT8 cui8calpha)noexcept{
			ui8cdestination=(ui8cdestination&0x0f)|stui8cBackNega_SourceAlpha_Bit4L(ui8cdestination,cui8csource,cui8calpha);
			return;
		};
	}
	NEVER;
}

template<const CANVAS_::IDBLEND cidBlend>
constexpr CANVAS_::FP_BLEND_BIT4R	CANVAS_::stfp_blend_bit4rGetThis(VOID)noexcept{
	switch(cidBlend){
	case IDBLEND::Source:
		return [](UINT8& ui8cdestination,CUINT8 cui8csource,CUINT8 cui8calpha)noexcept{
			ui8cdestination=(ui8cdestination&0xf0)|(cui8csource&0x0f);
			return;
		};
	case IDBLEND::BackNega_Source:
		return [](UINT8& ui8cdestination,CUINT8 cui8csource,CUINT8 cui8calpha)noexcept{
			ui8cdestination=(ui8cdestination&0xf0)|stui8cBackNega_Source_Bit4R(ui8cdestination,cui8csource,cui8calpha);
			return;
		};
	case IDBLEND::BackNega_SourceAlpha:
		return [](UINT8& ui8cdestination,CUINT8 cui8csource,CUINT8 cui8calpha)noexcept{
			ui8cdestination=(ui8cdestination&0xf0)|stui8cBackNega_SourceAlpha_Bit4R(ui8cdestination,cui8csource,cui8calpha);
			return;
		};
	}
	NEVER;
}

template<const CANVAS_::IDBLEND cidBlend>
constexpr CANVAS_::FP_BLEND_BIT8	CANVAS_::stfp_blend_bit8GetThis(VOID)noexcept{
	switch(cidBlend){
	case IDBLEND::Source:
		return [](UINT8& ui8cdestination,CUINT8 cui8csource,CUINT8 cui8calpha)noexcept{
			ui8cdestination=cui8csource;
			return;
		};
	case IDBLEND::BackNega_Source:
		return [](UINT8& ui8cdestination,CUINT8 cui8csource,CUINT8 cui8calpha)noexcept{
			ui8cdestination=stui8cBackNega_Source_Bit8(ui8cdestination,cui8csource,cui8calpha);
			return;
		};
	case IDBLEND::BackNega_SourceAlpha:
		return [](UINT8& ui8cdestination,CUINT8 cui8csource,CUINT8 cui8calpha)noexcept{
			ui8cdestination=stui8cBackNega_SourceAlpha_Bit8(ui8cdestination,cui8csource,cui8calpha);
			return;
		};
	}
	NEVER;
}

template<const CANVAS_::IDBLEND cidBlend>
constexpr CANVAS_::FP_BLEND_BIT16	CANVAS_::stfp_blend_bit16GetThis(VOID)noexcept{
	switch(cidBlend){
	case IDBLEND::Source:
		return [](UINT16& ui16cdestination,CUINT16 cui16csource,CUINT16 cui16calpha)noexcept{
			ui16cdestination=cui16csource;
			return;
		};
	case IDBLEND::BackNega_Source:
		return [](UINT16& ui16cdestination,CUINT16 cui16csource,CUINT16 cui16calpha)noexcept{
			ui16cdestination=stui16cBackNega_Source_Bit16(ui16cdestination,cui16csource,cui16calpha);
			return;
		};
	case IDBLEND::BackNega_SourceAlpha:
		return [](UINT16& ui16cdestination,CUINT16 cui16csource,CUINT16 cui16calpha)noexcept{
			ui16cdestination=stui16cBackNega_SourceAlpha_Bit16(ui16cdestination,cui16csource,cui16calpha);
			return;
		};
	}
	NEVER;
}

template<const CANVAS_::IDBLEND cidBlend>
constexpr CANVAS_::FP_BLEND_BIT32	CANVAS_::stfp_blend32GetThis(VOID)noexcept{
	switch(cidBlend){
	case IDBLEND::Source:
		return [](UINT32& ui32cdestination,CUINT32 cui32csource,CUINT32 cui32calpha)noexcept{
			ui32cdestination=cui32csource;
			return;
		};
	case IDBLEND::BackNega_Source:
		return [](UINT32& ui32cdestination,CUINT32 cui32csource,CUINT32 cui32calpha)noexcept{
			ui32cdestination=stui32cBackNega_Source_Bit32(ui32cdestination,cui32csource,cui32calpha);
			return;
		};
	case IDBLEND::BackNega_SourceAlpha:
		return [](UINT32& ui32cdestination,CUINT32 cui32csource,CUINT32 cui32calpha)noexcept{
			ui32cdestination=stui32cBackNega_SourceAlpha_Bit32(ui32cdestination,cui32csource,cui32calpha);
			return;
		};
	}
	NEVER;
}

constexpr UINT8			CANVAS_::stui8cBackNega_Source_Bit4L(
	CUINT8					cui8cdestination,
	CUINT8					cui8csource,
	CUINT8					cui8calpha
)noexcept{
	return (stacui8cBlend[
		(UINT16(cui8cdestination&0xf0)<<4)|UINT16(cui8csource&0xf0)|(UINT16(cui8calpha&0xf0)>>4)
	]<<4)&0xf0;
}

constexpr UINT8			CANVAS_::stui8cBackNega_SourceAlpha_Bit4L(
	CUINT8					cui8cdestination,
	CUINT8					cui8csource,
	CUINT8					cui8calpha
)noexcept{
	return stacui8cBlend[
		(UINT16(cui8cdestination&0xf0)<<4)|UINT16(cui8csource&0xf0)|(UINT16(cui8calpha&0xf0)>>4)
	]&0xf0;
}

constexpr UINT8			CANVAS_::stui8cBackNega_Source_Bit4R(
	CUINT8					cui8cdestination,
	CUINT8					cui8csource,
	CUINT8					cui8calpha
)noexcept{
	return stacui8cBlend[
		(UINT16(cui8cdestination&0x0f)<<8)|(UINT16(cui8csource&0x0f)<<4)|UINT16(cui8calpha&0x0f)
	]&0x0f;
}

constexpr UINT8			CANVAS_::stui8cBackNega_SourceAlpha_Bit4R(
	CUINT8					cui8cdestination,
	CUINT8					cui8csource,
	CUINT8					cui8calpha
)noexcept{
	return (stacui8cBlend[
		(UINT16(cui8cdestination&0x0f)<<8)|(UINT16(cui8csource&0x0f)<<4)|UINT16(cui8calpha&0x0f)
	]>>4)&0x0f;
}

constexpr UINT8			CANVAS_::stui8cBackNega_Source_Bit8(
	CUINT8					cui8cdestination,
	CUINT8					cui8csource,
	CUINT8					cui8calpha
)noexcept{
	return stui8cBackNega_Source_Bit4L(
		cui8cdestination,cui8csource,cui8calpha
	)|stui8cBackNega_Source_Bit4R(
		cui8cdestination,cui8csource,cui8calpha
	);
}

constexpr UINT8			CANVAS_::stui8cBackNega_SourceAlpha_Bit8(
	CUINT8					cui8cdestination,
	CUINT8					cui8csource,
	CUINT8					cui8calpha
)noexcept{
	return stui8cBackNega_SourceAlpha_Bit4L(
		cui8cdestination,cui8csource,cui8calpha
	)|stui8cBackNega_SourceAlpha_Bit4R(
		cui8cdestination,cui8csource,cui8calpha
	);
}

constexpr UINT16		CANVAS_::stui16cBackNega_Source_Bit16(
	CUINT16					cui16cdestination,
	CUINT16					cui16csource,
	CUINT16					cui16calpha
)noexcept{
	return (UINT16(stui8cBackNega_Source_Bit8(
		UINT8(cui16cdestination>>8),UINT8(cui16csource>>8),UINT8(cui16calpha>>8)
	))<<8)|UINT16(stui8cBackNega_Source_Bit8(
		UINT8(cui16cdestination),UINT8(cui16csource),UINT8(cui16calpha)
	));
}

constexpr UINT16		CANVAS_::stui16cBackNega_SourceAlpha_Bit16(
	CUINT16					cui16cdestination,
	CUINT16					cui16csource,
	CUINT16					cui16calpha
)noexcept{
	return (UINT16(stui8cBackNega_SourceAlpha_Bit8(
		UINT8(cui16cdestination>>8),UINT8(cui16csource>>8),UINT8(cui16calpha>>8)
	))<<8)|UINT16(stui8cBackNega_SourceAlpha_Bit8(
		UINT8(cui16cdestination),UINT8(cui16csource),UINT8(cui16calpha)
	));
}

constexpr UINT32		CANVAS_::stui32cBackNega_Source_Bit32(
	CUINT32					cui32cdestination,
	CUINT32					cui32csource,
	CUINT32					cui32calpha
)noexcept{
	return (UINT32(stui16cBackNega_Source_Bit16(
		UINT16(cui32cdestination>>16),UINT16(cui32csource>>16),UINT16(cui32calpha>>16)
	))<<16)|UINT32(stui16cBackNega_Source_Bit16(
		UINT16(cui32cdestination),UINT16(cui32csource),UINT16(cui32calpha)
	));
}

constexpr UINT32		CANVAS_::stui32cBackNega_SourceAlpha_Bit32(
	CUINT32					cui32cdestination,
	CUINT32					cui32csource,
	CUINT32					cui32calpha
)noexcept{
	return (UINT32(stui16cBackNega_SourceAlpha_Bit16(
		UINT16(cui32cdestination>>16),UINT16(cui32csource>>16),UINT16(cui32calpha>>16)
	))<<16)|UINT32(stui16cBackNega_SourceAlpha_Bit16(
		UINT16(cui32cdestination),UINT16(cui32csource),UINT16(cui32calpha)
	));
}

//	instancing

template VOID			CANVAS_::RGBX_stFill<FALSE>(const PUINT8 cpui8cdestinationbase,CUINT32 cui32idestinationdotposition,CUINT32 cui32ddestinationdotoffsetend,CUINT16 cui16ndestinationhdotline,CUINT16 cui16ndestinationlinepitch,CUINT32 cui32ndestinationplanepitch,CUINT16 cui16ccolorsource,const IDBLEND cidblend)noexcept;
template VOID			CANVAS_::RGBX_stFill<TRUE>(const PUINT8 cpui8cdestinationbase,CUINT32 cui32idestinationdotposition,CUINT32 cui32ddestinationdotoffsetend,CUINT16 cui16ndestinationhdotline,CUINT16 cui16ndestinationlinepitch,CUINT32 cui32ndestinationplanepitch,CUINT16 cui16ccolorsource,const IDBLEND cidblend)noexcept;
template VOID			CANVAS_::RGBX_stFillAlpha<FALSE>(const PUINT8 cpui8cdestinationbase,CUINT32 cui32idestinationdotposition,CUINT32 cui32ddestinationdotoffsetend,CUINT16 cui16ndestinationhdotline,CUINT16 cui16ndestinationlinepitch,CUINT32 cui32ndestinationplanepitch,CUINT16 cui16ccolorsource,const PCUINT8 cpcui8csourcea,CUINT32 cui32isourcedotposition,CUINT16 cui16nsourcelinepitch,const IDBLEND cidblend)noexcept;
template VOID			CANVAS_::RGBX_stFillAlpha<TRUE>(const PUINT8 cpui8cdestinationbase,CUINT32 cui32idestinationdotposition,CUINT32 cui32ddestinationdotoffsetend,CUINT16 cui16ndestinationhdotline,CUINT16 cui16ndestinationlinepitch,CUINT32 cui32ndestinationplanepitch,CUINT16 cui16ccolorsource,const PCUINT8 cpcui8csourcea,CUINT32 cui32isourcedotposition,CUINT16 cui16nsourcelinepitch,const IDBLEND cidblend)noexcept;
template VOID			CANVAS_::RGBX_stCopy<FALSE,FALSE>(const PUINT8 cpui8cdestinationbase,CUINT32 cui32idestinationdotposition,CUINT32 cui32ddestinationdotoffsetend,CUINT16 cui16ndestinationhdotline,CUINT16 cui16ndestinationlinepitch,CUINT32 cui32ndestinationplanepitch,const PCUINT8 cpcui8csourcebase,CUINT32 cui32isourcedotposition,CUINT16 cui16nsourcelinepitch,CUINT32 cui32nsourceplanepitch,const IDBLEND cidblend)noexcept;
template VOID			CANVAS_::RGBX_stCopy<FALSE,TRUE>(const PUINT8 cpui8cdestinationbase,CUINT32 cui32idestinationdotposition,CUINT32 cui32ddestinationdotoffsetend,CUINT16 cui16ndestinationhdotline,CUINT16 cui16ndestinationlinepitch,CUINT32 cui32ndestinationplanepitch,const PCUINT8 cpcui8csourcebase,CUINT32 cui32isourcedotposition,CUINT16 cui16nsourcelinepitch,CUINT32 cui32nsourceplanepitch,const IDBLEND cidblend)noexcept;
template VOID			CANVAS_::RGBX_stCopy<TRUE,FALSE>(const PUINT8 cpui8cdestinationbase,CUINT32 cui32idestinationdotposition,CUINT32 cui32ddestinationdotoffsetend,CUINT16 cui16ndestinationhdotline,CUINT16 cui16ndestinationlinepitch,CUINT32 cui32ndestinationplanepitch,const PCUINT8 cpcui8csourcebase,CUINT32 cui32isourcedotposition,CUINT16 cui16nsourcelinepitch,CUINT32 cui32nsourceplanepitch,const IDBLEND cidblend)noexcept;
template VOID			CANVAS_::RGBX_stCopy<TRUE,TRUE>(const PUINT8 cpui8cdestinationbase,CUINT32 cui32idestinationdotposition,CUINT32 cui32ddestinationdotoffsetend,CUINT16 cui16ndestinationhdotline,CUINT16 cui16ndestinationlinepitch,CUINT32 cui32ndestinationplanepitch,const PCUINT8 cpcui8csourcebase,CUINT32 cui32isourcedotposition,CUINT16 cui16nsourcelinepitch,CUINT32 cui32nsourceplanepitch,const IDBLEND cidblend)noexcept;
template VOID			CANVAS_::RGBX_stCopyAlpha<FALSE>(const PUINT8 cpui8cdestinationbase,CUINT32 cui32idestinationdotposition,CUINT32 cui32ddestinationdotoffsetend,CUINT16 cui16ndestinationhdotline,CUINT16 cui16ndestinationlinepitch,CUINT32 cui32ndestinationplanepitch,const PCUINT8 cpcui8csourcebase,const PCUINT8 cpcui8csourcea,CUINT32 cui32isourcedotposition,CUINT16 cui16nsourcelinepitch,CUINT32 cui32nsourceplanepitch,const IDBLEND cidblend)noexcept;
template VOID			CANVAS_::RGBX_stCopyAlpha<TRUE>(const PUINT8 cpui8cdestinationbase,CUINT32 cui32idestinationdotposition,CUINT32 cui32ddestinationdotoffsetend,CUINT16 cui16ndestinationhdotline,CUINT16 cui16ndestinationlinepitch,CUINT32 cui32ndestinationplanepitch,const PCUINT8 cpcui8csourcebase,const PCUINT8 cpcui8csourcea,CUINT32 cui32isourcedotposition,CUINT16 cui16nsourcelinepitch,CUINT32 cui32nsourceplanepitch,const IDBLEND cidblend)noexcept;
