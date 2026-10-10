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

#include				"pattern.hpp"
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

	//	GRAPHIC
	//		ビデオ機能「VI71B」のフルカラーモードを使用した描画クラスです。
	//		描画域は1,024×512ドットですが、
	//		これはビットマップ割り当て領域の切り替えで実現されており、
	//		(非表示領域が無いため)ダブルバッファ的な使い方はできません。
	//		加えて、BG0と1、BG2と3はパターン共用となります。
	//		<VRAM割り当て>
	//		0x000000    +-----------------------------------+
	//		            |領域(0,0)-(1023,255)Rプレーン      |
	//		0x020000    +-----------------------------------+
	//		            |領域(0,0)-(1023,255)Gプレーン      |
	//		0x040000    +-----------------------------------+
	//		            |領域(0,0)-(1023,255)Bプレーン      |
	//		0x060000    +-----------------------------------+
	//		            |スプライトパターン                 |
	//		0x068000    +-----------------------------------+
	//		            |スプライトアトリビュート           |
	//		0x068800    +-----------------------------------+
	//		            |(未使用)                           |
	//		0x070000    +-----------------------------------+
	//		            |BG0/1パターン                      |
	//		0x078000    +-----------------------------------+
	//		            |BG2/3パターン                      |
	//		0x080000    +-----------------------------------+
	//		            |領域(0,256)-(1023,511)Rプレーン    |
	//		0x0a0000    +-----------------------------------+
	//		            |領域(0,256)-(1023,511)Gプレーン    |
	//		0x0c0000    +-----------------------------------+
	//		            |領域(0,256)-(1023,511)Bプレーン    |
	//		0x0e0000    +-----------------------------------+
	//		            |BG0アトリビュート                  |
	//		0x0e8000    +-----------------------------------+
	//		            |BG1アトリビュート                  |
	//		0x0f0000    +-----------------------------------+
	//		            |BG2アトリビュート                  |
	//		0x0f8000    +-----------------------------------+
	//		            |BG3アトリビュート                  |
	//		0x100000    +-----------------------------------+
	class GRAPHIC{
	public:

		//
		//		primitive
		//

		//	FP_CALLBACK
		using					FP_CALLBACK=VOID(*)(const PVOID cpobject)noexcept;

		//
		//		const
		//

		//	IDREGISTERW
		using					IDREGISTERW=VIDEO_DRIVER::IDREGISTERW;
		//	IDLAYER
		using					IDLAYER=VIDEO_DRIVER::IDLAYER;
		//	IDBLEND
		using					IDBLEND=CANVAS_::IDBLEND;
		//	IDPART
		enum class IDPART{
			Upper,
			Lower
		};
		static constexpr VECTOR2	stcv2nScreen={640,480};
		static constexpr UINT32	VRAM_PATTERN_SPRITE_stcui32dOffset=				0x060000;
		static constexpr AUTO	VRAM_PATTERNCHR_SPRITE_stcui16dOffset=			UINT16(VRAM_PATTERN_SPRITE_stcui32dOffset>>5);
		static constexpr UINT32	VRAM_PATTERN_BG01_stcui32dOffset=				0x070000;
		static constexpr AUTO	VRAM_PATTERNCHR_BG01_stcui16dOffset=			UINT16(VRAM_PATTERN_BG01_stcui32dOffset>>5);
		static constexpr UINT32	VRAM_PATTERN_BG23_stcui32dOffset=				0x078000;
		static constexpr AUTO	VRAM_PATTERNCHR_BG23_stcui16dOffset=			UINT16(VRAM_PATTERN_BG23_stcui32dOffset>>5);
		static constexpr UINT32	VRAM_ATTRIBUTE_SPRITE_stcui32dOffset=			0x068000;
		static constexpr UINT32	VRAM_ATTRIBUTE_BG0_stcui32dOffset=				0x0e0000;
		static constexpr UINT32	VRAM_ATTRIBUTE_BG1_stcui32dOffset=				0x0e8000;
		static constexpr UINT32	VRAM_ATTRIBUTE_BG2_stcui32dOffset=				0x0f0000;
		static constexpr UINT32	VRAM_ATTRIBUTE_BG3_stcui32dOffset=				0x0f8000;

		//
		//		class
		//

		//	DRIVER
		using					DRIVER=											VIDEO_DRIVER;
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
			//	VOID					Fill(CUINT16 cui16ccolor,const IDBLEND cidblend)
			//		「cui16ccolor」での塗りつぶしを実行します。
			//		合成方法は「cidblend」に従います。
			static _INLINE_ VOID	stFill(CUINT16 cui16ccolor,const IDBLEND cidblend)noexcept{
				SUPER::stFill(PUINT8(stcui32iThis),cui16ccolor,{VECTOR2::stv2ImmediateZero(),stcv2nSize},cidblend);
				return;
			}
			//	VOID					FillRect(CUINT16 cui16ccolor,CSHAPE& cshpshape,const IDBLEND cidblend)
			//		「cui16ccolor」での塗りつぶしを実行します。
			//		合成方法は「cidblend」に従います。
			static _INLINE_ VOID	stFillRect(CUINT16 cui16ccolor,CSHAPE& cshpshape,const IDBLEND cidblend)noexcept{
				AUTO					shpshape=cshpshape;

				if constexpr(cidPart==IDPART::Lower)shpshape.v2iPosition.i16iY()-=stcv2nSize.i16nHeight();
				SUPER::stFill(PUINT8(stcui32iThis),cui16ccolor,shpshape,cidblend);
				return;
			}
			//	VOID					FillAlpha(CUINT16 cui16ccolor,const CANVAS_A_& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend)
			//		アルファ画像「ccvssourcea」を乗じた「cui16ccolor」での塗りつぶしを実行します。
			//		合成方法は「cidblend」に従います。
			//		アルファ値は、画像「ccvssourcea」と「cui16ccolor」内のアルファ値を乗じたものが使用されます。
			template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
			static VOID				stFillAlpha(CUINT16 cui16ccolor,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				using					SCLASS_A=CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

				stFillAlphaRect(cui16ccolor,ccvssourcea,{VECTOR2::stv2ImmediateZero(),SCLASS_A::stcv2nSize},cv2iposition,cidblend);
				return;
			}
			//	VOID					FillAlphaRect(CUINT16 cui16ccolor,const CANVAS_A_& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)
			//		アルファ画像「ccvssourcea」を乗じた「cui16ccolor」での塗りつぶしを実行します。
			//		合成方法は「cidblend」に従います。
			//		アルファ値は、画像「ccvssourcea」と「cui16ccolor」内のアルファ値を乗じたものが使用されます。
			template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
			static VOID				stFillAlphaRect(CUINT16 cui16ccolor,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				AUTO					v2iposition=cv2iposition;

				if constexpr(cidPart==IDPART::Lower)v2iposition.i16iY()-=stcv2nSize.i16nHeight();
				SUPER::stFillAlpha(PUINT8(stcui32iThis),cui16ccolor,ccvssourcea,cshpsource,v2iposition,cidblend);
				return;
			}
			//	VOID					Copy(const CANVAS_RGB_& ccvssource,CVECTOR2& cv2iposition,const IDBLEND cidblend)
			//		RGB画像「ccvssource」をコピーします。
			//		合成方法は「cidblend」に従います。
			template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
			static _INLINE_ VOID	stCopy(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				using					SCLASS=CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

				stCopyRect(ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition,cidblend);
				return;
			}
			//	VOID					Copy(const CANVAS_RGBA_& ccvssource,CVECTOR2& cv2iposition,const IDBLEND cidblend)
			//		RGBA画像「ccvssource」をコピーします。
			//		合成方法は「cidblend」に従います。
			template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
			static _INLINE_ VOID	stCopy(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				using					SCLASS=CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

				stCopyRect(ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition,cidblend);
				return;
			}
			//	VOID					CopyRect(const CANVAS_RGB_& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)
			//		RGB画像「ccvssource」をコピーします。
			//		合成方法は「cidblend」に従います。
			template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
			static _INLINE_ VOID	stCopyRect(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				AUTO					v2iposition=cv2iposition;

				if constexpr(cidPart==IDPART::Lower)v2iposition.i16iY()-=stcv2nSize.i16nHeight();
				SUPER::stCopy(PUINT8(stcui32iThis),ccvssource,cshpsource,v2iposition,cidblend);
				return;
			}
			//	VOID					CopyRect(const CANVAS_RGBA_& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)
			//		RGBA画像「ccvssource」をコピーします。
			//		合成方法は「cidblend」に従います。
			template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
			static _INLINE_ VOID	stCopyRect(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				AUTO					v2iposition=cv2iposition;

				if constexpr(cidPart==IDPART::Lower)v2iposition.i16iY()-=stcv2nSize.i16nHeight();
				SUPER::stCopy(PUINT8(stcui32iThis),ccvssource,cshpsource,v2iposition,cidblend);
				return;
			}
			//	VOID					CopyAlpha(const CANVAS_RGB_& ccvssource,const CANVAS_A_& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend)
			//		アルファ値を画像「ccvssourcea」としたRGB画像「ccvssource」をコピーします。
			//		「ccvssourcea」と「ccvssource」は同一サイズである必要があります。
			//		合成方法は「cidblend」に従います。
			//		アルファ値は画像「ccvssourcea」の値がそのまま使用され、「ccvssource」がアルファ値を持っていても使用されません。
			template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
			static _INLINE_ VOID	stCopyAlpha(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				using					SCLASS=CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

				stCopyAlphaRect(ccvssource,ccvssourcea,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition,cidblend);
				return;
			}
			//	VOID					CopyAlpha(const CANVAS_RGBA_& ccvssource,const CANVAS_A_& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend)
			//		アルファ値を画像「ccvssourcea」としたRGBA画像「ccvssource」をコピーします。
			//		「ccvssourcea」と「ccvssource」は同一サイズである必要があります。
			//		合成方法は「cidblend」に従います。
			//		アルファ値は画像「ccvssourcea」の値がそのまま使用され、「ccvssource」がアルファ値を持っていても使用されません。
			template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
			static _INLINE_ VOID	stCopyAlpha(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				using					SCLASS=CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>;

				stCopyAlphaRect(ccvssource,ccvssourcea,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition,cidblend);
				return;
			}
			//	VOID					CopyAlphaRect(const CANVAS_RGB_& ccvssource,const CANVAS_A_& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)
			//		アルファ値を画像「ccvssourcea」としたRGB画像「ccvssource」をコピーします。
			//		「ccvssourcea」と「ccvssource」は同一サイズである必要があります。
			//		合成方法は「cidblend」に従います。
			//		アルファ値は画像「ccvssourcea」の値がそのまま使用され、「ccvssource」がアルファ値を持っていても使用されません。
			template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
			static _INLINE_ VOID	stCopyAlphaRect(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				AUTO					v2iposition=cv2iposition;

				if constexpr(cidPart==IDPART::Lower)v2iposition.i16iY()-=stcv2nSize.i16nHeight();
				SUPER::stCopyAlpha(PUINT8(stcui32iThis),ccvssource,ccvssourcea,cshpsource,v2iposition,cidblend);
				return;
			}
			//	VOID					CopyAlphaRect(const CANVAS_RGBA_& ccvssource,const CANVAS_A_& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)
			//		アルファ値を画像「ccvssourcea」としたRGBA画像「ccvssource」をコピーします。
			//		「ccvssourcea」と「ccvssource」は同一サイズである必要があります。
			//		合成方法は「cidblend」に従います。
			//		アルファ値は画像「ccvssourcea」の値がそのまま使用され、「ccvssource」がアルファ値を持っていても使用されません。
			template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
			static _INLINE_ VOID	stCopyAlphaRect(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				AUTO					v2iposition=cv2iposition;

				if constexpr(cidPart==IDPART::Lower)v2iposition.i16iY()-=stcv2nSize.i16nHeight();
				SUPER::stCopyAlpha(PUINT8(stcui32iThis),ccvssource,ccvssourcea,cshpsource,v2iposition,cidblend);
				return;
			}
			//	VOID					DrawString(const PCUSTR cpcustrsource,CUINT16 cui16ccolor,CVECTOR2& cv2iposition,const IDBLEND cidblend)
			//		文字列「cpcustrsource」を「cui16ccolor」で描画します。
			//		合成方法は「cidblend」を使用しますが、文字イメージはアルファ値であるため、
			//		「*_SourceAlpha」を指定しないと単なる塗りつぶしとなります。
			static _INLINE_ VOID	stDrawString(const PCUSTR cpcustrsource,CUINT16 cui16ccolor,CVECTOR2& cv2iposition,const IDBLEND cidblend)noexcept{
				AUTO					v2iposition=cv2iposition;

				if constexpr(cidPart==IDPART::Lower)v2iposition.i16iY()-=stcv2nSize.i16nHeight();
				SUPER::stDrawString(PUINT8(stcui32iThis),cpcustrsource,cui16ccolor,v2iposition,cidblend);
				return;
			}
		};

		//
		//		class:ST
		//

		class ST{
		public:
			OFWBOOL					eShow;
			FP_CALLBACK				VBLANK_fp_callbackThis;
			PVOID					VBLANK_pObject;
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
		static _INLINE_ VOID	VBLANK_stSetCallback(const FP_CALLBACK cfp_callbackthis,const PVOID cpobject)noexcept{
			st.VBLANK_fp_callbackThis=cfp_callbackthis;
			st.VBLANK_pObject=cpobject;
			return;
		}
		//	VOID					stFill(CUINT16 cui16ccolor,const IDBLEND cidblend)
		//		テキスト画面に対し、「cui16ccolor」での塗りつぶしを実行します。
		//		合成方法は「cidblend」に従います。
		static VOID				stFill(CUINT16 cui16ccolor,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CANVAS_PART_UPPER::stFill(cui16ccolor,cidblend);
			CANVAS_PART_LOWER::stFill(cui16ccolor,cidblend);
			return;
		}
		//	VOID					stFillRect(CUINT16 cui16ccolor,CSHAPE& cshpshape,const IDBLEND cidblend)
		//		テキスト画面に対し、「cui16ccolor」での塗りつぶしを実行します。
		//		合成方法は「cidblend」に従います。
		static VOID				stFillRect(CUINT16 cui16ccolor,CSHAPE& cshpshape,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			if(steIsInUpper(cshpshape))CANVAS_PART_UPPER::stFillRect(cui16ccolor,cshpshape,cidblend);
			if(steIsInLower(cshpshape))CANVAS_PART_LOWER::stFillRect(cui16ccolor,cshpshape,cidblend);
			return;
		}
		//	VOID					stFillAlpha(CUINT16 cui16ccolor,const CANVAS_A_& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend)
		//		テキスト画面に対し、アルファ画像「ccvssourcea」を乗じた「cui16ccolor」での塗りつぶしを実行します。
		//		合成方法は「cidblend」に従います。
		//		アルファ値は、画像「ccvssourcea」と「cui16ccolor」内のアルファ値を乗じたものが使用されます。
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stFillAlpha(CUINT16 cui16ccolor,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CAUTO					cshpshape=SHAPE({cv2iposition,{INT16(SCLASS_cui16nWidth),INT16(SCLASS_cui16nHeight)}});

			if(steIsInUpper(cshpshape))CANVAS_PART_UPPER::stFillAlpha(cui16ccolor,ccvssourcea,cv2iposition,cidblend);
			if(steIsInLower(cshpshape))CANVAS_PART_LOWER::stFillAlpha(cui16ccolor,ccvssourcea,cv2iposition,cidblend);
			return;
		}
		//	VOID					stFillAlphaRect(CUINT16 cui16ccolor,const CANVAS_A_& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)
		//		テキスト画面に対し、アルファ画像「ccvssourcea」を乗じた「cui16ccolor」での塗りつぶしを実行します。
		//		合成方法は「cidblend」に従います。
		//		アルファ値は、画像「ccvssourcea」と「cui16ccolor」内のアルファ値を乗じたものが使用されます。
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stFillAlphaRect(CUINT16 cui16ccolor,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CAUTO					cshpshape=SHAPE({cv2iposition,cshpsource.v2nSize});

			if(steIsInUpper(cshpshape))CANVAS_PART_UPPER::stFillAlphaRect(cui16ccolor,ccvssourcea,cshpsource,cv2iposition,cidblend);
			if(steIsInLower(cshpshape))CANVAS_PART_LOWER::stFillAlphaRect(cui16ccolor,ccvssourcea,cshpsource,cv2iposition,cidblend);
			return;
		}
		//	VOID					stCopy(const CANVAS_RGB_& ccvssource,CVECTOR2& cv2iposition,const IDBLEND cidblend)
		//		テキスト画面に対し、RGB画像「ccvssource」をコピーします。
		//		合成方法は「cidblend」に従います。
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopy(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CAUTO					cshpshape=SHAPE({cv2iposition,{INT16(SCLASS_cui16nWidth),INT16(SCLASS_cui16nHeight)}});

			if(steIsInUpper(cshpshape))CANVAS_PART_UPPER::stCopy(ccvssource,cv2iposition,cidblend);
			if(steIsInLower(cshpshape))CANVAS_PART_LOWER::stCopy(ccvssource,cv2iposition,cidblend);
			return;
		}
		//	VOID					stCopy(const CANVAS_RGBA_& ccvssource,CVECTOR2& cv2iposition,const IDBLEND cidblend)
		//		テキスト画面に対し、RGBA画像「ccvssource」をコピーします。
		//		合成方法は「cidblend」に従います。
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopy(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CAUTO					cshpshape=SHAPE({cv2iposition,{INT16(SCLASS_cui16nWidth),INT16(SCLASS_cui16nHeight)}});

			CANVAS_PART_UPPER::stCopy(ccvssource,cv2iposition,cidblend);
			CANVAS_PART_LOWER::stCopy(ccvssource,cv2iposition,cidblend);
			return;
		}
		//	VOID					stCopyRect(const CANVAS_RGB_& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)
		//		テキスト画面に対し、RGB画像「ccvssource」をコピーします。
		//		合成方法は「cidblend」に従います。
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopyRect(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CAUTO					cshpshape=SHAPE({cv2iposition,cshpsource.v2nSize});

			if(steIsInUpper(cshpshape))CANVAS_PART_UPPER::stCopyRect(ccvssource,cshpsource,cv2iposition,cidblend);
			if(steIsInLower(cshpshape))CANVAS_PART_LOWER::stCopyRect(ccvssource,cshpsource,cv2iposition,cidblend);
			return;
		}
		//	VOID					stCopyRect(const CANVAS_RGBA_& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)
		//		テキスト画面に対し、RGBA画像「ccvssource」をコピーします。
		//		合成方法は「cidblend」に従います。
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopyRect(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CAUTO					cshpshape=SHAPE({cv2iposition,cshpsource.v2nSize});

			if(steIsInUpper(cshpshape))CANVAS_PART_UPPER::stCopyRect(ccvssource,cshpsource,cv2iposition,cidblend);
			if(steIsInLower(cshpshape))CANVAS_PART_LOWER::stCopyRect(ccvssource,cshpsource,cv2iposition,cidblend);
			return;
		}
		//	VOID					stCopyAlpha(const CANVAS_RGB_& ccvssource,const CANVAS_A_& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend)
		//		テキスト画面に対し、アルファ値を画像「ccvssourcea」としたRGB画像「ccvssource」をコピーします。
		//		「ccvssourcea」と「ccvssource」は同一サイズである必要があります。
		//		合成方法は「cidblend」に従います。
		//		アルファ値は画像「ccvssourcea」の値がそのまま使用され、「ccvssource」がアルファ値を持っていても使用されません。
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopyAlpha(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CAUTO					cshpshape=SHAPE({cv2iposition,{INT16(SCLASS_cui16nWidth),INT16(SCLASS_cui16nHeight)}});

			if(steIsInUpper(cshpshape))CANVAS_PART_UPPER::stCopyAlpha(ccvssource,ccvssourcea,cv2iposition,cidblend);
			if(steIsInLower(cshpshape))CANVAS_PART_LOWER::stCopyAlpha(ccvssource,ccvssourcea,cv2iposition,cidblend);
			return;
		}
		//	VOID					stCopyAlpha(const CANVAS_RGBA_& ccvssource,const CANVAS_A_& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend)
		//		テキスト画面に対し、アルファ値を画像「ccvssourcea」としたRGBA画像「ccvssource」をコピーします。
		//		「ccvssourcea」と「ccvssource」は同一サイズである必要があります。
		//		合成方法は「cidblend」に従います。
		//		アルファ値は画像「ccvssourcea」の値がそのまま使用され、「ccvssource」がアルファ値を持っていても使用されません。
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopyAlpha(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CAUTO					cshpshape=SHAPE({cv2iposition,{INT16(SCLASS_cui16nWidth),INT16(SCLASS_cui16nHeight)}});

			if(steIsInUpper(cshpshape))CANVAS_PART_UPPER::stCopyAlpha(ccvssource,ccvssourcea,cv2iposition,cidblend);
			if(steIsInLower(cshpshape))CANVAS_PART_LOWER::stCopyAlpha(ccvssource,ccvssourcea,cv2iposition,cidblend);
			return;
		}
		//	VOID					stCopyAlphaRect(const CANVAS_RGB_& ccvssource,const CANVAS_A_& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)
		//		テキスト画面に対し、アルファ値を画像「ccvssourcea」としたRGB画像「ccvssource」をコピーします。
		//		「ccvssourcea」と「ccvssource」は同一サイズである必要があります。
		//		合成方法は「cidblend」に従います。
		//		アルファ値は画像「ccvssourcea」の値がそのまま使用され、「ccvssource」がアルファ値を持っていても使用されません。
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopyAlphaRect(const CANVAS_RGB_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CAUTO					cshpshape=SHAPE({cv2iposition,cshpsource.v2nSize});

			if(steIsInUpper(cshpshape))CANVAS_PART_UPPER::stCopyAlphaRect(ccvssource,ccvssourcea,cshpsource,cv2iposition,cidblend);
			if(steIsInLower(cshpshape))CANVAS_PART_LOWER::stCopyAlphaRect(ccvssource,ccvssourcea,cshpsource,cv2iposition,cidblend);
			return;
		}
		//	VOID					stCopyAlphaRect(const CANVAS_RGBA_& ccvssource,const CANVAS_A_& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend)
		//		テキスト画面に対し、アルファ値を画像「ccvssourcea」としたRGBA画像「ccvssource」をコピーします。
		//		「ccvssourcea」と「ccvssource」は同一サイズである必要があります。
		//		合成方法は「cidblend」に従います。
		//		アルファ値は画像「ccvssourcea」の値がそのまま使用され、「ccvssource」がアルファ値を持っていても使用されません。
		template<CUINT16 SCLASS_cui16nWidth,CUINT16 SCLASS_cui16nHeight>
		static VOID				stCopyAlphaRect(const CANVAS_RGBA_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssource,const CANVAS_A_<SCLASS_cui16nWidth,SCLASS_cui16nHeight>& ccvssourcea,CSHAPE& cshpsource,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::Source)noexcept{
			CAUTO					cshpshape=SHAPE({cv2iposition,cshpsource.v2nSize});

			if(steIsInUpper(cshpshape))CANVAS_PART_UPPER::stCopyAlphaRect(ccvssource,ccvssourcea,cshpsource,cv2iposition,cidblend);
			if(steIsInLower(cshpshape))CANVAS_PART_LOWER::stCopyAlphaRect(ccvssource,ccvssourcea,cshpsource,cv2iposition,cidblend);
			return;
		}
		//	VOID					stDrawString(const PCUSTR cpcustrsource,CUINT16 cui16ccolor,CVECTOR2& cv2iposition,const IDBLEND cidblend)
		//		テキスト画面に対し、文字列「cpcustrsource」を「cui16ccolor」で描画します。
		//		合成方法は「cidblend」を使用しますが、文字イメージはアルファ値であるため、
		//		「*_SourceAlpha」を指定しないと単なる塗りつぶしとなります。
		static VOID				stDrawString(const PCUSTR cpcustrsource,CUINT16 cui16ccolor,CVECTOR2& cv2iposition,const IDBLEND cidblend=IDBLEND::BackNega_SourceAlpha)noexcept{
			CAUTO					cshpshape=SHAPE({cv2iposition,{INT16(16),INT16(16)}});

			if(steIsInUpper(cshpshape))CANVAS_PART_UPPER::stDrawString(cpcustrsource,cui16ccolor,cv2iposition,cidblend);
			if(steIsInLower(cshpshape))CANVAS_PART_LOWER::stDrawString(cpcustrsource,cui16ccolor,cv2iposition,cidblend);
			return;
		}
		static _INLINE_ VOID	PALETTE_stSetWrite(CUINT8 cui8iaddress)noexcept{
			DRIVER::PALETTE_stSetWrite(cui8iaddress);
			return;
		}
		static _INLINE_ VOID	PALETTE_stWrite(CUINT16 cui16ccolor)noexcept{
			DRIVER::PALETTE_stWrite(cui16ccolor);
			return;
		}
		static _INLINE_ VOID	PALETTE_stWrite(CUINT8 cui8iaddress,const PCUINT16 cpcui16ccolor,CUINT8 cui8nsize)noexcept{
			DRIVER::PALETTE_stWrite(cui8iaddress,cpcui16ccolor,cui8nsize);
			return;
		}
		static _INLINE_ VOID	PATTERN_SPRITE_stWrite(CUINT16 patternchr_cui16daddressoffset,CUINT16 cui16ndestination,const PCVOID cpcsource)noexcept{
			PATTERN::stWrite(
				VRAM_PATTERNCHR_SPRITE_stcui16dOffset+patternchr_cui16daddressoffset,
				OFWSIZE(cui16ndestination)<<5,
				cpcsource
			);
			return;
		}
		static _INLINE_ VOID	PATTERN_BG01_stWrite(CUINT16 patternchr_cui16daddressoffset,CUINT16 cui16ndestination,const PCVOID cpcsource)noexcept{
			PATTERN::stWrite(
				VRAM_PATTERNCHR_BG01_stcui16dOffset+patternchr_cui16daddressoffset,
				OFWSIZE(cui16ndestination)<<5,
				cpcsource
			);
			return;
		}
		static _INLINE_ VOID	PATTERN_BG23_stWrite(CUINT16 patternchr_cui16daddressoffset,CUINT16 cui16ndestination,const PCVOID cpcsource)noexcept{
			PATTERN::stWrite(
				VRAM_PATTERNCHR_BG23_stcui16dOffset+patternchr_cui16daddressoffset,
				OFWSIZE(cui16ndestination)<<5,
				cpcsource
			);
			return;
		}
		static _INLINE_ VOID	SPRITE_stWriteAttribute(CUINT8 cui8isprite,CUINT16 cui16cattribute0,CUINT16 cui16cattribute1,CUINT16 cui16cattribute2,CUINT16 cui16cattribute3)noexcept{
			CAUTO					cui32doffset=VRAM_ATTRIBUTE_SPRITE_stcui32dOffset+(UINT32(cui8isprite)<<3);

			MEMORY::VRAM_stui16DelegateThis(cui32doffset+0x00)=cui16cattribute0;
			MEMORY::VRAM_stui16DelegateThis(cui32doffset+0x02)=cui16cattribute1;
			MEMORY::VRAM_stui16DelegateThis(cui32doffset+0x04)=cui16cattribute2;
			MEMORY::VRAM_stui16DelegateThis(cui32doffset+0x06)=cui16cattribute3;
			return;
		}
		static _INLINE_ VOID	SPRITE_stWrite8(CUINT8 cui8isprite,CVECTOR2& cv2iposition,CUINT8 cui8ipattern,CUINT8 cui8ispritepalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE,CUINT8 cui8ipriority=1)noexcept{
			SPRITE_stWriteAttribute(
				cui8isprite,
				UINT16(cv2iposition.i16iX()),
				UINT16(cv2iposition.i16iY()),
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ispritepalette)<<12),
				0x0000|(UINT16(cui8ipriority)<<8)
			);
			return;
		}
		static _INLINE_ VOID	SPRITE_stWrite16(CUINT8 cui8isprite,CVECTOR2& cv2iposition,CUINT8 cui8ipattern,CUINT8 cui8ispritepalette,COFWBOOL ceinverth=FALSE,COFWBOOL ceinvertv=FALSE,CUINT8 cui8ipriority=1)noexcept{
			SPRITE_stWriteAttribute(
				cui8isprite,
				UINT16(cv2iposition.i16iX()),
				UINT16(cv2iposition.i16iY()),
				UINT16(cui8ipattern)|(UINT16(ceinverth)<<10)|(UINT16(ceinvertv)<<11)|(UINT16(cui8ispritepalette)<<12),
				0x5000|(UINT16(cui8ipriority)<<8)
			);
			return;
		}
		static _INLINE_ VOID	SPRITE_stErase(CUINT8 cui8isprite)noexcept{
			CAUTO					cui32doffset=VRAM_ATTRIBUTE_SPRITE_stcui32dOffset+(UINT32(cui8isprite)<<3);

			MEMORY::VRAM_stui16DelegateThis(cui32doffset+0x06)=0x0000;
			return;
		}
		//	フォントROM
		static _INLINE_ VOID	FONTROM_stWriteBank(CUINT16 cui16value)noexcept{
			ore68000ace::MEMORYS::DEVICE_stui16DelegateThis(ore68000ace::DEVICE_FONTROM_stcui16dOffsetS+ore68000ace::DEVICE_FONTROM_stcui16dBankOffset)=cui16value;
			return;
		}
		static _INLINE_ VOID	FONTROM_stWriteData(CUINT16 cui16value)noexcept{
			ore68000ace::MEMORYS::DEVICE_stui16DelegateThis(ore68000ace::DEVICE_FONTROM_stcui16dOffsetS+ore68000ace::DEVICE_FONTROM_stcui16dDataOffset)=cui16value;
			return;
		}
		static _INLINE_ _UNDISCARDABLE_ CUINT16&	FONTROM_stui16ReadBank(VOID)noexcept{
			return ore68000ace::MEMORYS::DEVICE_stcui16GetThis(ore68000ace::DEVICE_FONTROM_stcui16dOffsetS+ore68000ace::DEVICE_FONTROM_stcui16dBankOffset);
		}
		static _INLINE_ _UNDISCARDABLE_  CUINT16&	FONTROM_stui16ReadData(VOID)noexcept{
			return ore68000ace::MEMORYS::DEVICE_stcui16GetThis(ore68000ace::DEVICE_FONTROM_stcui16dOffsetS+ore68000ace::DEVICE_FONTROM_stcui16dDataOffset);
		}
	private:
		static constexpr OFWBOOL	steIsInUpper(CSHAPE& cshpshape)noexcept{
			if(cshpshape.v2iPosition.i16iY()<0)return OFWBOOL(
				0<cshpshape.v2iPosition.i16iY()+cshpshape.v2nSize.i16nHeight()
			);
			else return OFWBOOL(
				cshpshape.v2iPosition.i16iY()<256
			);
		}
		static constexpr OFWBOOL	steIsInLower(CSHAPE& cshpshape)noexcept{
			if(cshpshape.v2iPosition.i16iY()<256)return OFWBOOL(
				256<cshpshape.v2iPosition.i16iY()+cshpshape.v2nSize.i16nHeight()
			);
			else return OFWBOOL(
				cshpshape.v2iPosition.i16iY()<480
			);
		}
	};
}

#endif
