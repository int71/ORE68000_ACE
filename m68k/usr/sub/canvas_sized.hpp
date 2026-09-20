/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/canvas_sized.hpp'							2026 written by int71	**
 ****************************************************************************/
#ifndef I71_SUB_CANVAS
#define I71_SUB_CANVAS

//
//		include
//

#include				"canvas_.hpp"

//
//		namespace:m68k::i71::sub
//

namespace m68k::i71::sub{

	//
	//		class
	//

	//	CANVAS_SIZED_
	template<CUINT16 cui16nWidth,CUINT16 cui16nHeight>
	class CANVAS_SIZED_;
	//	CANVAS_RGB_
	template<CUINT16 cui16nWidth,CUINT16 cui16nHeight>
	class CANVAS_RGB_;
	//	CANVAS_RGBA_
	template<CUINT16 cui16nWidth,CUINT16 cui16nHeight>
	class CANVAS_RGBA_;
	//	CANVAS_A_
	template<CUINT16 cui16nWidth,CUINT16 cui16nHeight>
	class CANVAS_A_;
	//	CANVAS_RGB_ROM
	template<CUINT16 cui16nWidth,CUINT16 cui16nHeight>
	class CANVAS_RGB_ROM;
	//	CANVAS_RGBA_ROM
	template<CUINT16 cui16nWidth,CUINT16 cui16nHeight>
	class CANVAS_RGBA_ROM;
	//	CANVAS_A_ROM
	template<CUINT16 cui16nWidth,CUINT16 cui16nHeight>
	class CANVAS_A_ROM;
	//	CANVAS_RGB_RAM
	template<CUINT16 cui16nWidth,CUINT16 cui16nHeight>
	class CANVAS_RGB_RAM;
	//	CANVAS_RGBA_RAM
	template<CUINT16 cui16nWidth,CUINT16 cui16nHeight>
	class CANVAS_RGBA_RAM;
	//	CANVAS_A_RAM
	template<CUINT16 cui16nWidth,CUINT16 cui16nHeight>
	class CANVAS_A_RAM;

	//
	//		class:CANVAS_SIZED_
	//

	template<CUINT16 cui16nWidth,CUINT16 cui16nHeight>
	class CANVAS_SIZED_:public CANVAS_{
	public:

		//
		//		const
		//

		static constexpr AUTO	stcv2nSize=VECTOR2(INT16(cui16nWidth),INT16(cui16nHeight));
		static constexpr AUTO	stcui16nLinePitch=UINT16((cui16nWidth+1)>>1);
		static constexpr AUTO	stcui32nPlanePitch=UINT32(UINT32(cui16nHeight)*UINT32(stcui16nLinePitch));
		static constexpr AUTO	stcui16nLineDotPitch=UINT16(stcui16nLinePitch<<1);

		//
		//		class
		//

		//	SUPER
		using					SUPER=CANVAS_;
		//	CANVAS_SIZED_
		using					CCANVAS_SIZED_=const CANVAS_SIZED_;
		using					PCANVAS_SIZED_=CANVAS_SIZED_*;
		using					PCCANVAS_SIZED_=CCANVAS_SIZED_*;

		//
		//		body:CANVAS_SIZED_
		//

	public:
		static constexpr UINT32	stui32iGetDotPosition(CVECTOR2& cv2iposition)noexcept{
			return UINT32(
				sti32dGetDotOffset(cv2iposition.i16iY())+
				INT32(cv2iposition.i16iX())
			);
		}
		static constexpr INT32	sti32dGetDotOffset(CINT16 ci16dyoffset)noexcept{
			return INT32(ci16dyoffset)*INT32(stcui16nLineDotPitch);
		}
		static VOID				stTrim(SHAPE& shpshape)noexcept{
			//	‰¡•ûŒü
			if(shpshape.v2iPosition.i16iX()<0){
				shpshape.v2nSize.i16nWidth()+=shpshape.v2iPosition.i16iX();
				shpshape.v2iPosition.i16iX()=0;
			}
			shpshape.v2nSize.i16nWidth()=STD::stxGetMaximum(shpshape.v2nSize.i16nWidth(),0);
			if(stcv2nSize.i16nWidth()<shpshape.v2iPosition.i16iX()+shpshape.v2nSize.i16nWidth()){
				if(shpshape.v2iPosition.i16iX()<stcv2nSize.i16nWidth())shpshape.v2nSize.i16nWidth()=stcv2nSize.i16nWidth()-shpshape.v2iPosition.i16iX();
				else{
					shpshape.v2iPosition.i16iX()=stcv2nSize.i16nWidth();
					shpshape.v2nSize.i16nWidth()=0;
				}
			}
			//	c•ûŒü
			if(shpshape.v2iPosition.i16iY()<0){
				shpshape.v2nSize.i16nHeight()+=shpshape.v2iPosition.i16iY();
				shpshape.v2iPosition.i16iY()=0;
			}
			shpshape.v2nSize.i16nHeight()=STD::stxGetMaximum(shpshape.v2nSize.i16nHeight(),0);
			if(stcv2nSize.i16nHeight()<shpshape.v2iPosition.i16iY()+shpshape.v2nSize.i16nHeight()){
				if(shpshape.v2iPosition.i16iY()<stcv2nSize.i16nHeight())shpshape.v2nSize.i16nHeight()=stcv2nSize.i16nHeight()-shpshape.v2iPosition.i16iY();
				else{
					shpshape.v2iPosition.i16iY()=stcv2nSize.i16nHeight();
					shpshape.v2nSize.i16nHeight()=0;
				}
			}
			return;
		}
		static VOID				stTrimSending(SHAPE& shpthis,VECTOR2& v2iposition)noexcept{
			if(shpthis.v2iPosition.i16iX()<0){
				shpthis.v2nSize.i16nWidth()+=shpthis.v2iPosition.i16iX();
				v2iposition.i16iX()-=shpthis.v2iPosition.i16iX();
				shpthis.v2iPosition.i16iX()=0;
			}
			if(shpthis.v2iPosition.i16iY()<0){
				shpthis.v2nSize.i16nHeight()+=shpthis.v2iPosition.i16iY();
				v2iposition.i16iY()-=shpthis.v2iPosition.i16iY();
				shpthis.v2iPosition.i16iY()=0;
			}
			shpthis.v2nSize=shpthis.v2nSize.v2GetMinimum(stcv2nSize-shpthis.v2iPosition).v2GetMaximum(VECTOR2::stv2ImmediateZero());
			return;
		}
		static VOID				stTrimReceiving(SHAPE& shpsource,VECTOR2& v2iposition)noexcept{
			//	‰¡•ûŒü
			if(shpsource.v2iPosition.i16iX()<0){
				shpsource.v2nSize.i16nWidth()+=shpsource.v2iPosition.i16iX();
				v2iposition.i16iX()-=shpsource.v2iPosition.i16iX();
				shpsource.v2iPosition.i16iX()=0;
			}
			if(v2iposition.i16iX()<0){
				shpsource.v2iPosition.i16iX()-=v2iposition.i16iX();
				shpsource.v2nSize.i16nWidth()+=v2iposition.i16iX();
				v2iposition.i16iX()=0;
			}
			shpsource.v2nSize.i16nWidth()=STD::stxGetMaximum(shpsource.v2nSize.i16nWidth(),0);
			if(stcv2nSize.i16nWidth()<v2iposition.i16iX()+shpsource.v2nSize.i16nWidth()){
				if(v2iposition.i16iX()<stcv2nSize.i16nWidth())shpsource.v2nSize.i16nWidth()=stcv2nSize.i16nWidth()-v2iposition.i16iX();
				else{
					v2iposition.i16iX()=stcv2nSize.i16nWidth();
					shpsource.v2nSize.i16nWidth()=0;
				}
			}
			//	c•ûŒü
			if(shpsource.v2iPosition.i16iY()<0){
				shpsource.v2nSize.i16nHeight()+=shpsource.v2iPosition.i16iY();
				v2iposition.i16iY()-=shpsource.v2iPosition.i16iY();
				shpsource.v2iPosition.i16iY()=0;
			}
			if(v2iposition.i16iY()<0){
				shpsource.v2iPosition.i16iY()-=v2iposition.i16iY();
				shpsource.v2nSize.i16nHeight()+=v2iposition.i16iY();
				v2iposition.i16iY()=0;
			}
			shpsource.v2nSize.i16nHeight()=STD::stxGetMaximum(shpsource.v2nSize.i16nHeight(),0);
			if(stcv2nSize.i16nHeight()<v2iposition.i16iY()+shpsource.v2nSize.i16nHeight()){
				if(v2iposition.i16iY()<stcv2nSize.i16nHeight())shpsource.v2nSize.i16nHeight()=stcv2nSize.i16nHeight()-v2iposition.i16iY();
				else{
					v2iposition.i16iY()=stcv2nSize.i16nHeight();
					shpsource.v2nSize.i16nHeight()=0;
				}
			}
			return;
		}
	protected:
		template<COFWBOOL ceDestinationAlpha>
		static _INLINE_ VOID	RGBX_stFill(const PUINT8 cpui8cdestinationbase,CUINT16 cui16ccolor,CSHAPE& cshpshape,const IDBLEND cidblend)noexcept{
			AUTO					shpshape=cshpshape;

			stTrim(shpshape);
			SUPER_RGBX_stFill<ceDestinationAlpha>(cpui8cdestinationbase,cui16ccolor,shpshape,cidblend);
			return;
		}
		template<COFWBOOL ceDestinationAlpha,CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				RGBX_stFillAlpha(const PUINT8 cpui8cdestinationbase,CUINT16 cui16ccolor,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
			using					SCLASS=CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;
			AUTO					shpsource=cshpsource;
			AUTO					v2iposition=cv2iposition;

			ccvssourcea.stTrimSending(shpsource,v2iposition);
			stTrimReceiving(shpsource,v2iposition);
			SUPER_RGBX_stFillAlpha<ceDestinationAlpha>(
				cpui8cdestinationbase,
				cui16ccolor,
				ccvssourcea.pcui8cGetThis(),
				SCLASS::stui32iGetDotPosition(shpsource.v2iPosition),
				SCLASS::stcui16nLinePitch,
				shpsource,
				v2iposition,
				cidblend
			);
			return;
		}
		template<COFWBOOL ceDestinationAlpha,CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static _INLINE_ VOID	RGBX_stCopy(const PUINT8 cpui8cdestinationbase,const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
			using					SCLASS=CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;
			AUTO					shpsource=cshpsource;
			AUTO					v2iposition=cv2iposition;

			ccvssource.stTrimSending(shpsource,v2iposition);
			stTrimReceiving(shpsource,v2iposition);
			SUPER_RGBX_stCopy<ceDestinationAlpha,FALSE>(
				cpui8cdestinationbase,
				ccvssource.pcui8cGetThis(),
				SCLASS::stui32iGetDotPosition(shpsource.v2iPosition),
				SCLASS::stcui16nLinePitch,
				SCLASS::stcui32nPlanePitch,
				shpsource,
				v2iposition,
				cidblend
			);
			return;
		}
		template<COFWBOOL ceDestinationAlpha,CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static _INLINE_ VOID	RGBX_stCopy(const PUINT8 cpui8cdestinationbase,const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
			using					SCLASS=CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;
			AUTO					shpsource=cshpsource;
			AUTO					v2iposition=cv2iposition;

			ccvssource.stTrimSending(shpsource,v2iposition);
			stTrimReceiving(shpsource,v2iposition);
			SUPER_RGBX_stCopy<ceDestinationAlpha,TRUE>(
				cpui8cdestinationbase,
				ccvssource.pcui8cGetThis(),
				SCLASS::stui32iGetDotPosition(shpsource.v2iPosition),
				SCLASS::stcui16nLinePitch,
				SCLASS::stcui32nPlanePitch,
				shpsource,
				v2iposition,
				cidblend
			);
			return;
		}
		template<COFWBOOL ceDestinationAlpha,CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				RGBX_stCopyAlpha(const PUINT8 cpui8cdestinationbase,const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
			using					SCLASS=CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;
			AUTO					shpsource=cshpsource;
			AUTO					v2iposition=cv2iposition;

			ccvssource.stTrimSending(shpsource,v2iposition);
			stTrimReceiving(shpsource,v2iposition);
			SUPER_RGBX_stCopyAlpha<ceDestinationAlpha>(
				cpui8cdestinationbase,
				ccvssource.pcui8cGetThis(),
				ccvssourcea.pcui8cGetThis(),
				SCLASS::stui32iGetDotPosition(shpsource.v2iPosition),
				SCLASS::stcui16nLinePitch,
				SCLASS::stcui32nPlanePitch,
				shpsource,
				v2iposition,
				cidblend
			);
			return;
		}
		static _INLINE_ VOID	A_stFill(const PUINT8 cpui8cdestination,CUINT8 cui8ialpha,CSHAPE& cshpshape)noexcept{
			AUTO					shpshape=cshpshape;

			stTrim(shpshape);
			SUPER_A_stFill(cpui8cdestination,cui8ialpha,shpshape);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static _INLINE_ VOID	A_stCopy(const PUINT8 cpui8cdestination,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition)noexcept{
			using					SCLASS=CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;
			AUTO					shpsource=cshpsource;
			AUTO					v2iposition=cv2iposition;

			ccvssource.stTrimSending(shpsource,v2iposition);
			stTrimReceiving(shpsource,v2iposition);
			SUPER_A_stCopy(
				cpui8cdestination,
				ccvssource.pcui8cGetThis(),
				SCLASS::stui32iGetDotPosition(shpsource.v2iPosition),
				SCLASS::stcui16nLinePitch,
				shpsource,
				v2iposition
			);
			return;
		}
	private:
		template<COFWBOOL ceDestinationAlpha>
		static _INLINE_ VOID	SUPER_RGBX_stFill(const PUINT8 cpui8cdestinationbase,CUINT16 cui16ccolor,CSHAPE& cshpshape,const IDBLEND cidblend)noexcept{
			SUPER::RGBX_stFill<ceDestinationAlpha>(
				cpui8cdestinationbase,
				stui32iGetDotPosition(cshpshape.v2iPosition),
				UINT32(sti32dGetDotOffset(cshpshape.v2nSize.i16nHeight())),
				UINT16(cshpshape.v2nSize.i16nWidth()),
				stcui16nLinePitch,
				stcui32nPlanePitch,
				cui16ccolor,
				cidblend
			);
			return;
		}
		template<COFWBOOL ceDestinationAlpha>
		static VOID				SUPER_RGBX_stFillAlpha(const PUINT8 cpui8cdestinationbase,CUINT16 cui16ccolor,const PCUINT8 cpcui8csourcea,CUINT32 cui32isourcedotposition,CUINT16 cui16nsourcelinepitch,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
			SUPER::RGBX_stFillAlpha<ceDestinationAlpha>(
				cpui8cdestinationbase,
				stui32iGetDotPosition(cv2iposition),
				UINT32(sti32dGetDotOffset(cshpsource.v2nSize.i16nHeight())),
				UINT16(cshpsource.v2nSize.i16nWidth()),
				stcui16nLinePitch,
				stcui32nPlanePitch,
				cui16ccolor,
				cpcui8csourcea,
				cui32isourcedotposition,
				cui16nsourcelinepitch,
				cidblend
			);
			return;
		}
		template<COFWBOOL ceDestinationAlpha,COFWBOOL ceSourceAlpha>
		static _INLINE_ VOID	SUPER_RGBX_stCopy(const PUINT8 cpui8cdestinationbase,const PCUINT8 cpcui8csourcebase,CUINT32 cui32isourcedotposition,CUINT16 cui16nsourcelinepitch,CUINT32 cui32nsourceplanepitch,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
			SUPER::RGBX_stCopy<ceDestinationAlpha,ceSourceAlpha>(
				cpui8cdestinationbase,
				stui32iGetDotPosition(cv2iposition),
				UINT32(sti32dGetDotOffset(cshpsource.v2nSize.i16nHeight())),
				UINT16(cshpsource.v2nSize.i16nWidth()),
				stcui16nLinePitch,
				stcui32nPlanePitch,
				cpcui8csourcebase,
				cui32isourcedotposition,
				cui16nsourcelinepitch,
				cui32nsourceplanepitch,
				cidblend
			);
			return;
		}
		template<COFWBOOL ceDestinationAlpha>
		static _INLINE_ VOID	SUPER_RGBX_stCopyAlpha(const PUINT8 cpui8cdestinationbase,const PCUINT8 cpcui8csourcebase,const PCUINT8 cpcui8csourcea,CUINT32 cui32isourcedotposition,CUINT16 cui16nsourcelinepitch,CUINT32 cui32nsourceplanepitch,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
			SUPER::RGBX_stCopyAlpha<ceDestinationAlpha>(
				cpui8cdestinationbase,
				stui32iGetDotPosition(cv2iposition),
				UINT32(sti32dGetDotOffset(cshpsource.v2nSize.i16nHeight())),
				UINT16(cshpsource.v2nSize.i16nWidth()),
				stcui16nLinePitch,
				stcui32nPlanePitch,
				cpcui8csourcebase,
				cpcui8csourcea,
				cui32isourcedotposition,
				cui16nsourcelinepitch,
				cui32nsourceplanepitch,
				cidblend
			);
			return;
		}
		static _INLINE_ VOID	SUPER_A_stFill(const PUINT8 cpui8cdestination,CUINT8 cui8ialpha,CSHAPE& cshpshape)noexcept{
			SUPER::A_stFill(
				cpui8cdestination,
				stui32iGetDotPosition(cshpshape.v2iPosition),
				UINT32(sti32dGetDotOffset(cshpshape.v2nSize.i16nHeight())),
				UINT16(cshpshape.v2nSize.i16nWidth()),
				stcui16nLinePitch,
				cui8ialpha
			);
			return;
		}
		static _INLINE_ VOID	SUPER_A_stCopy(const PUINT8 cpui8cdestination,const PCUINT8 cpcui8csource,CUINT32 cui32isourcedotposition,CUINT16 cui16nsourcelinepitch,CSHAPE& cshpsource,CVECTOR2& cv2iposition)noexcept{
			SUPER::A_stCopy(
				cpui8cdestination,
				stui32iGetDotPosition(cv2iposition),
				UINT32(sti32dGetDotOffset(cshpsource.v2nSize.i16nHeight())),
				UINT16(cshpsource.v2nSize.i16nWidth()),
				stcui16nLinePitch,
				cpcui8csource,
				cui32isourcedotposition,
				cui16nsourcelinepitch
			);
			return;
		}
	};

	//
	//		class:CANVAS_RGB_
	//

	template<CUINT16 cui16nWidth,CUINT16 cui16nHeight>
	class CANVAS_RGB_:public CANVAS_SIZED_<cui16nWidth,cui16nHeight>{
	public:

		//
		//		const
		//

		//	IDBLEND
		using					IDBLEND=CANVAS_::IDBLEND;

		//
		//		class
		//

		//	SUPER
		using					SUPER=CANVAS_SIZED_<cui16nWidth,cui16nHeight>;
		//	CANVAS_RGB_
		using					CCANVAS_RGB_=const CANVAS_RGB_;
		using					PCANVAS_RGB_=CANVAS_RGB_*;
		using					PCCANVAS_RGB_=CCANVAS_RGB_*;
		//	SHAPE
		using					SHAPE=CANVAS_::SHAPE;
		using					CSHAPE=CANVAS_::CSHAPE;
		using					PSHAPE=CANVAS_::PSHAPE;
		using					PCSHAPE=CANVAS_::PCSHAPE;

		//
		//		body:CANVAS_RGB_
		//

	protected:
		static VOID				stFill(const PUINT8 cpui8cdestinationbase,CUINT16 cui16ccolor,CSHAPE& cshpshape,const IDBLEND cidblend)noexcept{
			SUPER::template RGBX_stFill<FALSE>(cpui8cdestinationbase,cui16ccolor,cshpshape,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stFillAlpha(const PUINT8 cpui8cdestinationbase,CUINT16 cui16ccolor,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
			SUPER::template RGBX_stFillAlpha<FALSE>(cpui8cdestinationbase,cui16ccolor,ccvssourcea,cshpsource,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopy(const PUINT8 cpui8cdestinationbase,const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
			SUPER::template RGBX_stCopy<FALSE>(cpui8cdestinationbase,ccvssource,cshpsource,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopy(const PUINT8 cpui8cdestinationbase,const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
			SUPER::template RGBX_stCopy<FALSE>(cpui8cdestinationbase,ccvssource,cshpsource,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopyAlpha(const PUINT8 cpui8cdestinationbase,const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
			SUPER::template RGBX_stCopyAlpha<FALSE>(cpui8cdestinationbase,ccvssource,ccvssourcea,cshpsource,cv2iposition,cidblend);
			return;
		}
	};

	//
	//		class:CANVAS_RGBA_
	//

	template<CUINT16 cui16nWidth,CUINT16 cui16nHeight>
	class CANVAS_RGBA_:public CANVAS_SIZED_<cui16nWidth,cui16nHeight>{
	public:

		//
		//		const
		//

		//	IDBLEND
		using					IDBLEND=CANVAS_::IDBLEND;

		//
		//		class
		//

		//	SUPER
		using					SUPER=CANVAS_SIZED_<cui16nWidth,cui16nHeight>;
		//	CANVAS_RGBA_
		using					CCANVAS_RGBA_=const CANVAS_RGBA_;
		using					PCANVAS_RGBA_=CANVAS_RGBA_*;
		using					PCCANVAS_RGBA_=CCANVAS_RGBA_*;
		//	SHAPE
		using					SHAPE=CANVAS_::SHAPE;
		using					CSHAPE=CANVAS_::CSHAPE;
		using					PSHAPE=CANVAS_::PSHAPE;
		using					PCSHAPE=CANVAS_::PCSHAPE;

		//
		//		body:CANVAS_RGBA_
		//

	protected:
		static VOID				stFill(const PUINT8 cpui8cdestinationbase,CUINT16 cui16ccolor,CSHAPE& cshpshape,const IDBLEND cidblend)noexcept{
			SUPER::template RGBX_stFill<TRUE>(cpui8cdestinationbase,cui16ccolor,cshpshape,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stFillAlpha(const PUINT8 cpui8cdestinationbase,CUINT16 cui16ccolor,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
			SUPER::template RGBX_stFillAlpha<TRUE>(cpui8cdestinationbase,cui16ccolor,ccvssourcea,cshpsource,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopy(const PUINT8 cpui8cdestinationbase,const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
			SUPER::template RGBX_stCopy<TRUE>(cpui8cdestinationbase,ccvssource,cshpsource,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopy(const PUINT8 cpui8cdestinationbase,const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
			SUPER::template RGBX_stCopy<TRUE>(cpui8cdestinationbase,ccvssource,cshpsource,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopyAlpha(const PUINT8 cpui8cdestinationbase,const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
			SUPER::template RGBX_stCopyAlpha<TRUE>(cpui8cdestinationbase,ccvssource,ccvssourcea,cshpsource,cv2iposition,cidblend);
			return;
		}
	};

	//
	//		class:CANVAS_A_
	//

	template<CUINT16 cui16nWidth,CUINT16 cui16nHeight>
	class CANVAS_A_:public CANVAS_SIZED_<cui16nWidth,cui16nHeight>{
	public:

		//
		//		const
		//

		//	IDBLEND
		using					IDBLEND=CANVAS_::IDBLEND;

		//
		//		class
		//

		//	SUPER
		using					SUPER=CANVAS_SIZED_<cui16nWidth,cui16nHeight>;
		//	CANVAS_A_
		using					CCANVAS_A_=const CANVAS_A_;
		using					PCANVAS_A_=CANVAS_A_*;
		using					PCCANVAS_A_=CCANVAS_A_*;
		//	SHAPE
		using					SHAPE=CANVAS_::SHAPE;
		using					CSHAPE=CANVAS_::CSHAPE;
		using					PSHAPE=CANVAS_::PSHAPE;
		using					PCSHAPE=CANVAS_::PCSHAPE;

		//
		//		body:CANVAS_A_
		//

	protected:
		static _INLINE_ VOID	stFill(const PUINT8 cpui8cdestination,CUINT8 cui8ialpha,CSHAPE& cshpshape)noexcept{
			SUPER::A_stFill(cpui8cdestination,cui8ialpha,cshpshape);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static _INLINE_ VOID	stCopy(const PUINT8 cpui8cdestination,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition)noexcept{
			SUPER::template A_stCopy(cpui8cdestination,ccvssource,cshpsource,cv2iposition);
			return;
		}
	};

	//
	//		class:CANVAS_RGB_ROM
	//

	template<CUINT16 cui16nWidth,CUINT16 cui16nHeight>
	class CANVAS_RGB_ROM:public CANVAS_RGB_<cui16nWidth,cui16nHeight>{
	public:

		//
		//		const
		//

		//	IDBLEND
		using					IDBLEND=CANVAS_::IDBLEND;

		//
		//		class
		//

		//	SUPER
		using					SUPER=CANVAS_RGB_<cui16nWidth,cui16nHeight>;
		//	CANVAS_RGB_ROM
		using					CCANVAS_RGB_ROM=const CANVAS_RGB_ROM;
		using					PCANVAS_RGB_ROM=CANVAS_RGB_ROM*;
		using					PCCANVAS_RGB_ROM=CCANVAS_RGB_ROM*;
		//	SHAPE
		using					SHAPE=CANVAS_::SHAPE;
		using					CSHAPE=CANVAS_::CSHAPE;
		using					PSHAPE=CANVAS_::PSHAPE;
		using					PCSHAPE=CANVAS_::PCSHAPE;

		//
		//		body:CANVAS_RGB_ROM
		//

	private:
	public:
		constexpr /*VOID*/		CANVAS_RGB_ROM(const PCUINT16 cpcui16csource)noexcept{
			SUPER::pcui8cThis=PCUINT8(cpcui16csource);
		}
	};

	//
	//		class:CANVAS_RGBA_ROM
	//

	template<CUINT16 cui16nWidth,CUINT16 cui16nHeight>
	class CANVAS_RGBA_ROM:public CANVAS_RGBA_<cui16nWidth,cui16nHeight>{
	public:

		//
		//		const
		//

		//	IDBLEND
		using					IDBLEND=CANVAS_::IDBLEND;

		//
		//		class
		//

		//	SUPER
		using					SUPER=CANVAS_RGBA_<cui16nWidth,cui16nHeight>;
		//	CANVAS_RGBA_ROM
		using					CCANVAS_RGBA_ROM=const CANVAS_RGBA_ROM;
		using					PCANVAS_RGBA_ROM=CANVAS_RGBA_ROM*;
		using					PCCANVAS_RGBA_ROM=CCANVAS_RGBA_ROM*;
		//	SHAPE
		using					SHAPE=CANVAS_::SHAPE;
		using					CSHAPE=CANVAS_::CSHAPE;
		using					PSHAPE=CANVAS_::PSHAPE;
		using					PCSHAPE=CANVAS_::PCSHAPE;

		//
		//		body:CANVAS_RGBA_ROM
		//

	private:
	public:
		constexpr /*VOID*/		CANVAS_RGBA_ROM(const PCUINT16 cpcui16csource)noexcept{
			SUPER::pcui8cThis=PCUINT8(cpcui16csource);
		}
	};

	//
	//		class:CANVAS_A_ROM
	//

	template<CUINT16 cui16nWidth,CUINT16 cui16nHeight>
	class CANVAS_A_ROM:public CANVAS_A_<cui16nWidth,cui16nHeight>{
	public:

		//
		//		const
		//

		//	IDBLEND
		using					IDBLEND=CANVAS_::IDBLEND;

		//
		//		class
		//

		//	SUPER
		using					SUPER=CANVAS_A_<cui16nWidth,cui16nHeight>;
		//	CANVAS_A_ROM
		using					CCANVAS_A_ROM=const CANVAS_A_ROM;
		using					PCANVAS_A_ROM=CANVAS_A_ROM*;
		using					PCCANVAS_A_ROM=CCANVAS_A_ROM*;
		//	SHAPE
		using					SHAPE=CANVAS_::SHAPE;
		using					CSHAPE=CANVAS_::CSHAPE;
		using					PSHAPE=CANVAS_::PSHAPE;
		using					PCSHAPE=CANVAS_::PCSHAPE;

		//
		//		body:CANVAS_A_ROM
		//

	private:
	public:
		constexpr /*VOID*/		CANVAS_A_ROM(const PCUINT16 cpcui16csource)noexcept{
			SUPER::pcui8cThis=PCUINT8(cpcui16csource);
		}
	};

	//
	//		class:CANVAS_RGB_RAM
	//

	template<CUINT16 cui16nWidth,CUINT16 cui16nHeight>
	class CANVAS_RGB_RAM:public CANVAS_RGB_<cui16nWidth,cui16nHeight>{
	public:

		//
		//		const
		//

		//	IDBLEND
		using					IDBLEND=CANVAS_::IDBLEND;

		//
		//		class
		//

		//	SUPER
		using					SUPER=CANVAS_RGB_<cui16nWidth,cui16nHeight>;
		//	CANVAS_RGB_RAM
		using					CCANVAS_RGB_RAM=const CANVAS_RGB_RAM;
		using					PCANVAS_RGB_RAM=CANVAS_RGB_RAM*;
		using					PCCANVAS_RGB_RAM=CCANVAS_RGB_RAM*;
		//	SHAPE
		using					SHAPE=CANVAS_::SHAPE;
		using					CSHAPE=CANVAS_::CSHAPE;
		using					PSHAPE=CANVAS_::PSHAPE;
		using					PCSHAPE=CANVAS_::PCSHAPE;

		//
		//		body:CANVAS_RGB_RAM
		//

	private:
		_ALIGN32_ UINT8			aui8cThis[SUPER::stcui32nPlanePitch*3+SUPER::stcui32nOverreadMargin];
	public:
		constexpr /*VOID*/		CANVAS_RGB_RAM(VOID)noexcept{
			SUPER::pcui8cThis=PCUINT8(aui8cThis);
		}
		_INLINE_ VOID			Fill(CUINT16 cui16ccolor,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			FillRect(cui16ccolor,{VECTOR2::stv2ImmediateZero(),SUPER::stcv2nSize},cidblend);
			return;
		}
		VOID					FillRect(CUINT16 cui16ccolor,CSHAPE& cshpshape,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			SUPER::stFill(aui8cThis,cui16ccolor,cshpshape,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		_INLINE_ VOID			FillAlpha(CUINT16 cui16ccolor,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			using					SCLASS_A=CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

			FillAlphaRect(cui16ccolor,ccvssourcea,{VECTOR2::stv2ImmediateZero(),SCLASS_A::stcv2nSize},cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		VOID					FillAlphaRect(CUINT16 cui16ccolor,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			SUPER::stFillAlpha(aui8cThis,cui16ccolor,ccvssourcea,cshpsource,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		_INLINE_ VOID			Copy(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			using					SCLASS=CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

			CopyRect(ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		_INLINE_ VOID			Copy(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			using					SCLASS=CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

			CopyRect(ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		VOID					CopyRect(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			SUPER::stCopy(aui8cThis,ccvssource,cshpsource,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		VOID					CopyRect(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			SUPER::stCopy(aui8cThis,ccvssource,cshpsource,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		_INLINE_ VOID			CopyAlpha(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			using					SCLASS=CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

			CopyAlphaRect(aui8cThis,ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition,ccvssourcea,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		_INLINE_ VOID			CopyAlpha(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			using					SCLASS=CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

			CopyAlphaRect(aui8cThis,ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition,ccvssourcea,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		VOID					CopyAlphaRect(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			SUPER::stCopyAlpha(aui8cThis,ccvssource,cshpsource,ccvssourcea,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		VOID					CopyAlphaRect(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			SUPER::stCopyAlpha(aui8cThis,ccvssource,cshpsource,ccvssourcea,cv2iposition,cidblend);
			return;
		}
	};

	//
	//		class:CANVAS_RGBA_RAM
	//

	template<CUINT16 cui16nWidth,CUINT16 cui16nHeight>
	class CANVAS_RGBA_RAM:public CANVAS_RGBA_<cui16nWidth,cui16nHeight>{
	public:

		//
		//		const
		//

		//	IDBLEND
		using					IDBLEND=CANVAS_::IDBLEND;

		//
		//		class
		//

		//	SUPER
		using					SUPER=CANVAS_RGBA_<cui16nWidth,cui16nHeight>;
		//	CANVAS_RGBA_RAM
		using					CCANVAS_RGBA_RAM=const CANVAS_RGBA_RAM;
		using					PCANVAS_RGBA_RAM=CANVAS_RGBA_RAM*;
		using					PCCANVAS_RGBA_RAM=CCANVAS_RGBA_RAM*;
		//	SHAPE
		using					SHAPE=CANVAS_::SHAPE;
		using					CSHAPE=CANVAS_::CSHAPE;
		using					PSHAPE=CANVAS_::PSHAPE;
		using					PCSHAPE=CANVAS_::PCSHAPE;

		//
		//		body:CANVAS_RGBA_RAM
		//

	private:
		_ALIGN32_ UINT8			aui8cThis[SUPER::stcui32nPlanePitch*4+SUPER::stcui32nOverreadMargin];
	public:
		constexpr /*VOID*/		CANVAS_RGBA_RAM(VOID)noexcept{
			SUPER::pcui8cThis=PCUINT8(aui8cThis);
		}
		_INLINE_ VOID			Fill(CUINT16 cui16ccolor,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			FillRect(cui16ccolor,{VECTOR2::stv2ImmediateZero(),SUPER::stcv2nSize},cidblend);
			return;
		}
		VOID					FillRect(CUINT16 cui16ccolor,CSHAPE& cshpshape,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			SUPER::stFill(aui8cThis,cui16ccolor,cshpshape,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		_INLINE_ VOID			FillAlpha(CUINT16 cui16ccolor,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			using					SCLASS_A=CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

			FillAlphaRect(cui16ccolor,ccvssourcea,{VECTOR2::stv2ImmediateZero(),SCLASS_A::stcv2nSize},cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		VOID					FillAlphaRect(CUINT16 cui16ccolor,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			SUPER::stFillAlpha(aui8cThis,cui16ccolor,ccvssourcea,cshpsource,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		_INLINE_ VOID			Copy(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			using					SCLASS=CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

			CopyRect(ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		_INLINE_ VOID			Copy(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			using					SCLASS=CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

			CopyRect(ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		VOID					CopyRect(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			SUPER::stCopy(aui8cThis,ccvssource,cshpsource,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		VOID					CopyRect(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			SUPER::stCopy(aui8cThis,ccvssource,cshpsource,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		_INLINE_ VOID			CopyAlpha(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			using					SCLASS=CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

			CopyAlphaRect(aui8cThis,ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition,ccvssourcea,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		_INLINE_ VOID			CopyAlpha(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			using					SCLASS=CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

			CopyAlphaRect(aui8cThis,ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition,ccvssourcea,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		VOID					CopyAlphaRect(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			SUPER::stCopyAlpha(aui8cThis,ccvssource,cshpsource,ccvssourcea,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		VOID					CopyAlphaRect(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			SUPER::stCopyAlpha(aui8cThis,ccvssource,cshpsource,ccvssourcea,cv2iposition,cidblend);
			return;
		}
	};

	//
	//		class:CANVAS_A_RAM
	//

	template<CUINT16 cui16nWidth,CUINT16 cui16nHeight>
	class CANVAS_A_RAM:public CANVAS_A_<cui16nWidth,cui16nHeight>{
	public:

		//
		//		const
		//

		//	IDBLEND
		using					IDBLEND=CANVAS_::IDBLEND;

		//
		//		class
		//

		//	SUPER
		using					SUPER=CANVAS_A_<cui16nWidth,cui16nHeight>;
		//	CANVAS_A_RAM
		using					CCANVAS_A_RAM=const CANVAS_A_RAM;
		using					PCANVAS_A_RAM=CANVAS_A_RAM*;
		using					PCCANVAS_A_RAM=CCANVAS_A_RAM*;
		//	SHAPE
		using					SHAPE=CANVAS_::SHAPE;
		using					CSHAPE=CANVAS_::CSHAPE;
		using					PSHAPE=CANVAS_::PSHAPE;
		using					PCSHAPE=CANVAS_::PCSHAPE;

		//
		//		body:CANVAS_A_RAM
		//

	private:
		_ALIGN32_ UINT8			aui8cThis[SUPER::stcui32nPlanePitch*1+SUPER::stcui32nOverreadMargin];
	public:
		constexpr /*VOID*/		CANVAS_A_RAM(VOID)noexcept{
			SUPER::pcui8cThis=PCUINT8(aui8cThis);
		}
		_INLINE_ VOID			Fill(CUINT8 cui8ialpha)noexcept{
			FillRect(cui8ialpha,{VECTOR2::stv2ImmediateZero(),SUPER::stcv2nSize});
			return;
		}
		VOID					FillRect(CUINT8 cui8ialpha,CSHAPE& cshpshape)noexcept{
			SUPER::stFill(aui8cThis,cui8ialpha,cshpshape);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		_INLINE_ VOID			Copy(const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CVECTOR2& cv2iposition)noexcept{
			using					SCLASS=CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

			CopyRect(ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		VOID					CopyRect(const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition)noexcept{
			SUPER::stCopy(aui8cThis,ccvssource,cshpsource,cv2iposition);
			return;
		}
	};
}

#endif
