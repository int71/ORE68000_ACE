/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/graphic.hpp'								2026 written by int71	**
 ****************************************************************************/
#ifndef I71_SUB_GRAPHIC
#define I71_SUB_GRAPHIC

//
//		include
//

#include				"vector2.hpp"
#include				"canvas_sized.hpp"

//
//		namespace:m68k::i71::sub
//

namespace m68k::i71::sub{

	//
	//		class
	//

	//	GRAPHIC
	class GRAPHIC;

	//
	//		class:GRAPHIC
	//

	class GRAPHIC{
	public:

		//
		//		const
		//

		//	IDBLEND
		using					IDBLEND=CANVAS_::IDBLEND;
		//	IDPART
		enum class IDPART{
			Upper,
			Lower
		};

		//
		//		class
		//

		//	SHAPE
		using					SHAPE=CANVAS_::SHAPE;
		using					CSHAPE=CANVAS_::CSHAPE;
		using					PSHAPE=CANVAS_::PSHAPE;
		using					PCSHAPE=CANVAS_::PCSHAPE;
		//	CANVAS_PART
		template<const IDPART cidPart>
		class CANVAS_PART;
		//	CANVAS_PART_UPPER
		using					CANVAS_PART_UPPER=CANVAS_PART<IDPART::Upper>;
		using					CCANVAS_PART_UPPER=const CANVAS_PART_UPPER;
		//	CANVAS_PART_LOWER
		using					CANVAS_PART_LOWER=CANVAS_PART<IDPART::Lower>;
		using					CCANVAS_PART_LOWER=const CANVAS_PART_LOWER;
		//	ST
		class ST;
		using					CST=const ST;
		using					PST=ST*;
		using					PCST=CST*;

		//
		//		class:CANVAS_PART
		//

		template<const IDPART cidPart>
		class CANVAS_PART:public CANVAS_RGB_<1024,256>{
		public:

			//
			//		const
			//

			static constexpr AUTO	stcui32iThis=MAP::VRAM::stcui32iAddressS+(
				(cidPart==IDPART::Upper)?UINT32(
					0x000000
				):UINT32(
					0x080000				//	バンク#1オフセット
				)
			);

			//
			//		class
			//

			//	SUPER
			using					SUPER=CANVAS_RGB_;
			//	CANVAS_PART
			using					CCANVAS_PART=const CANVAS_PART;
			using					PCANVAS_PART=CANVAS_PART*;
			using					PCCANVAS_PART=CCANVAS_PART*;

			//
			//		body:CANVAS_PART
			//

		public:
			static _INLINE_ VOID	stFill(CUINT16 cui16ccolor,const IDBLEND cidblend)noexcept{
				SUPER::stFill(PUINT8(stcui32iThis),cui16ccolor,{VECTOR2::stv2ImmediateZero(),stcv2nSize},cidblend);
				return;
			}
			static _INLINE_ VOID	stFillRect(CUINT16 cui16ccolor,CSHAPE& cshpshape,const IDBLEND cidblend)noexcept{
				AUTO					shpshape=cshpshape;

				if constexpr(cidPart==IDPART::Lower)shpshape.v2iPosition.i16iY()-=stcv2nSize.i16nHeight();
				SUPER::stFill(PUINT8(stcui32iThis),cui16ccolor,shpshape,cidblend);
				return;
			}
			template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
			static VOID				stFillAlpha(CUINT16 cui16ccolor,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				using					SCLASS_A=CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

				stFillAlphaRect(cui16ccolor,ccvssourcea,{VECTOR2::stv2ImmediateZero(),SCLASS_A::stcv2nSize},cv2iposition,cidblend);
				return;
			}
			template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
			static VOID				stFillAlphaRect(CUINT16 cui16ccolor,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				AUTO					v2iposition=cv2iposition;

				if constexpr(cidPart==IDPART::Lower)v2iposition.i16iY()-=stcv2nSize.i16nHeight();
				SUPER::stFillAlpha(PUINT8(stcui32iThis),cui16ccolor,ccvssourcea,cshpsource,v2iposition,cidblend);
				return;
			}
			template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
			static _INLINE_ VOID	stCopy(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				using					SCLASS=CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

				stCopyRect(ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition,cidblend);
				return;
			}
			template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
			static _INLINE_ VOID	stCopy(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				using					SCLASS=CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

				stCopyRect(ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition,cidblend);
				return;
			}
			template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
			static _INLINE_ VOID	stCopyRect(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				AUTO					v2iposition=cv2iposition;

				if constexpr(cidPart==IDPART::Lower)v2iposition.i16iY()-=stcv2nSize.i16nHeight();
				SUPER::stCopy(PUINT8(stcui32iThis),ccvssource,cshpsource,v2iposition,cidblend);
				return;
			}
			template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
			static _INLINE_ VOID	stCopyRect(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				AUTO					v2iposition=cv2iposition;

				if constexpr(cidPart==IDPART::Lower)v2iposition.i16iY()-=stcv2nSize.i16nHeight();
				SUPER::stCopy(PUINT8(stcui32iThis),ccvssource,cshpsource,v2iposition,cidblend);
				return;
			}
			template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
			static _INLINE_ VOID	stCopyAlpha(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				using					SCLASS=CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

				stCopyAlphaRect(ccvssource,ccvssourcea,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition,cidblend);
				return;
			}
			template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
			static _INLINE_ VOID	stCopyAlpha(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				using					SCLASS=CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

				stCopyAlphaRect(ccvssource,ccvssourcea,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition,cidblend);
				return;
			}
			template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
			static _INLINE_ VOID	stCopyAlphaRect(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				AUTO					v2iposition=cv2iposition;

				if constexpr(cidPart==IDPART::Lower)v2iposition.i16iY()-=stcv2nSize.i16nHeight();
				SUPER::stCopyAlpha(PUINT8(stcui32iThis),ccvssource,ccvssourcea,cshpsource,v2iposition,cidblend);
				return;
			}
			template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
			static _INLINE_ VOID	stCopyAlphaRect(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				AUTO					v2iposition=cv2iposition;

				if constexpr(cidPart==IDPART::Lower)v2iposition.i16iY()-=stcv2nSize.i16nHeight();
				SUPER::stCopyAlpha(PUINT8(stcui32iThis),ccvssource,ccvssourcea,cshpsource,v2iposition,cidblend);
				return;
			}
		};

		//
		//		class:ST
		//

		class ST{
		public:
			OFWBOOL					eShow;
		public:
			VOID					Delete(VOID)noexcept;
		};

		//
		//		body:GRAPHIC
		//

	private:
		static inline ST		st;
	public:
		static VOID				stNew(COFWBOOL ceshow=TRUE)noexcept;
		static VOID				stDelete(VOID)noexcept;
		static VOID				stShow(COFWBOOL ceshow)noexcept;
		static VOID				stFill(CUINT16 cui16ccolor,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CANVAS_PART_UPPER::stFill(cui16ccolor,cidblend);
			CANVAS_PART_LOWER::stFill(cui16ccolor,cidblend);
			return;
		}
		static VOID				stFillRect(CUINT16 cui16ccolor,CSHAPE& cshpshape,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CANVAS_PART_UPPER::stFillRect(cui16ccolor,cshpshape,cidblend);
			CANVAS_PART_LOWER::stFillRect(cui16ccolor,cshpshape,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stFillAlpha(CUINT16 cui16ccolor,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CANVAS_PART_UPPER::stFillAlpha(cui16ccolor,ccvssourcea,cv2iposition,cidblend);
			CANVAS_PART_LOWER::stFillAlpha(cui16ccolor,ccvssourcea,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stFillAlphaRect(CUINT16 cui16ccolor,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CANVAS_PART_UPPER::stFillAlphaRect(cui16ccolor,ccvssourcea,cshpsource,cv2iposition,cidblend);
			CANVAS_PART_LOWER::stFillAlphaRect(cui16ccolor,ccvssourcea,cshpsource,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopy(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CANVAS_PART_UPPER::stCopy(ccvssource,cv2iposition,cidblend);
			CANVAS_PART_LOWER::stCopy(ccvssource,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopy(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CANVAS_PART_UPPER::stCopy(ccvssource,cv2iposition,cidblend);
			CANVAS_PART_LOWER::stCopy(ccvssource,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopyRect(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CANVAS_PART_UPPER::stCopyRect(ccvssource,cshpsource,cv2iposition,cidblend);
			CANVAS_PART_LOWER::stCopyRect(ccvssource,cshpsource,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopyRect(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CANVAS_PART_UPPER::stCopyRect(ccvssource,cshpsource,cv2iposition,cidblend);
			CANVAS_PART_LOWER::stCopyRect(ccvssource,cshpsource,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopyAlpha(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CANVAS_PART_UPPER::stCopyAlpha(ccvssource,ccvssourcea,cv2iposition,cidblend);
			CANVAS_PART_LOWER::stCopyAlpha(ccvssource,ccvssourcea,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopyAlpha(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CANVAS_PART_UPPER::stCopyAlpha(ccvssource,ccvssourcea,cv2iposition,cidblend);
			CANVAS_PART_LOWER::stCopyAlpha(ccvssource,ccvssourcea,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopyAlphaRect(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CANVAS_PART_UPPER::stCopyAlphaRect(ccvssource,ccvssourcea,cshpsource,cv2iposition,cidblend);
			CANVAS_PART_LOWER::stCopyAlphaRect(ccvssource,ccvssourcea,cshpsource,cv2iposition,cidblend);
			return;
		}
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopyAlphaRect(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CANVAS_PART_UPPER::stCopyAlphaRect(ccvssource,ccvssourcea,cshpsource,cv2iposition,cidblend);
			CANVAS_PART_LOWER::stCopyAlphaRect(ccvssource,ccvssourcea,cshpsource,cv2iposition,cidblend);
			return;
		}
	};
}

#endif
