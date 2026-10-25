/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/canvasbg.hpp'								2026 written by int71	**
 ****************************************************************************/
#ifndef I71_SUB_CANVASBG
#define I71_SUB_CANVASBG

//
//		include
//

#include				"vector2.hpp"

//
//		macro
//

#define __O68K_CANVASBG_ROM(cpcustrfilename,...)	[](VOID)constexpr noexcept{\
	static constexpr UINT16	stacui16csource[]={0x0000};\
\
	return CANVASBG_ROM<{1,1}>(stacui16csource);\
}()

//
//		namespace:m68k::i71::sub
//

namespace m68k::i71::sub{

	//
	//		class
	//

	//	CANVASBG_
	class CANVASBG_;
	using					CCANVASBG_=const CANVASBG_;
	using					PCANVASBG_=CANVASBG_*;
	using					PCCANVASBG_=CCANVASBG_*;
	//	CANVASBG_SIZED_
	template<CVECTOR2 cv2nSize>
	class CANVASBG_SIZED_;
	//	CANVASBG_ROM
	template<CVECTOR2 cv2nSize>
	class CANVASBG_ROM;
	//	CANVASBG_RAM
	template<CVECTOR2 cv2nSize>
	class CANVASBG_RAM;

	//
	//		class:CANVASBG_
	//

	class CANVASBG_{
	public:

		//
		//		class
		//

		//	SHAPE
		class SHAPE;
		using					CSHAPE=const SHAPE;
		using					PSHAPE=SHAPE*;
		using					PCSHAPE=CSHAPE*;

		//
		//		class:SHAPE
		//

		class SHAPE{
		public:
			VECTOR2					v2iPosition;
			VECTOR2					v2nSize;
		};

		//
		//		body:CANVASBG_
		//

	protected:
		PCUINT16				pcui16cThis;
	public:
		constexpr PCUINT16		pcui16cGetThis(VOID)const noexcept{
			return pcui16cThis;
		}
		//	VOID					stTrimReceiving(SHAPE& shpsource,VECTOR2& v2iposition,CVECTOR2& cv2ntrim)
		//		矩形「shpsource」および「v2iposition」を、「cv2ntrim」に収まるようトリムします。
		static _INLINE_ VOID	stTrimReceiving(SHAPE& shpsource,VECTOR2& v2iposition,CVECTOR2& cv2ntrim)noexcept{
			//	横方向
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
			if(cv2ntrim.i16nWidth()<v2iposition.i16iX()+shpsource.v2nSize.i16nWidth()){
				if(v2iposition.i16iX()<cv2ntrim.i16nWidth())shpsource.v2nSize.i16nWidth()=cv2ntrim.i16nWidth()-v2iposition.i16iX();
				else{
					v2iposition.i16iX()=cv2ntrim.i16nWidth();
					shpsource.v2nSize.i16nWidth()=0;
				}
			}
			//	縦方向
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
			if(cv2ntrim.i16nHeight()<v2iposition.i16iY()+shpsource.v2nSize.i16nHeight()){
				if(v2iposition.i16iY()<cv2ntrim.i16nHeight())shpsource.v2nSize.i16nHeight()=cv2ntrim.i16nHeight()-v2iposition.i16iY();
				else{
					v2iposition.i16iY()=cv2ntrim.i16nHeight();
					shpsource.v2nSize.i16nHeight()=0;
				}
			}
			return;
		}
	protected:
		static VOID				stFill(const PUINT16 cpui16cdestinationbase,CUINT16 cui16idestinationposition,CUINT16 cui16ddestinationoffsetend,CUINT16 cui16ndestinationh,CUINT16 cui16ndestinationpitch,CUINT16 cui16csource)noexcept;
		static VOID				stCopy(const PUINT16 cpui16cdestinationbase,CUINT16 cui16idestinationposition,CUINT16 cui16ddestinationoffsetend,CUINT16 cui16ndestinationh,CUINT16 cui16ndestinationpitch,const PCUINT16 cpcui16csourcebase,CUINT16 cui16isourceposition,CUINT16 cui16nsourcepitch)noexcept;
	};

	//
	//		class:CANVASBG_SIZED_
	//

	template<CVECTOR2 cv2nSize>
	class CANVASBG_SIZED_:public CANVASBG_{
	public:

		//
		//		const
		//

		static constexpr AUTO&	stcv2nSize=cv2nSize;
		static constexpr AUTO	stcui16nPitch=UINT16(cv2nSize.i16nWidth()<<1);

		//
		//		class
		//

		//	SUPER
		using					SUPER=CANVASBG_;
		//	CANVASBG_SIZED_
		using					CCANVASBG_SIZED_=const CANVASBG_SIZED_;
		using					PCANVASBG_SIZED_=CANVASBG_SIZED_*;
		using					PCCANVASBG_SIZED_=CCANVASBG_SIZED_*;

		//
		//		body:CANVASBG_SIZED_
		//

	public:
		//	UINT16					stui16iGetPosition(CVECTOR2& cv2iposition)
		//		2次元座標「cv2iposition」に対応する、1次元のBGデータ内位置を「バイト単位」で返します。
		static constexpr UINT16	stui16iGetPosition(CVECTOR2& cv2iposition)noexcept{
			return UINT16(
				sti16dGetOffset(cv2iposition.i16iY())+
				(cv2iposition.i16iX()<<1)
			);
		}
		//	INT16					sti16dGetOffset(CINT16 ci16dyoffset)
		//		2次元座標「(0,ci16dyoffset」に対応する、1次元のBGデータ内位置を「バイト単位」で返します。
		static constexpr INT16	sti16dGetOffset(CINT16 ci16dyoffset)noexcept{
			return INT16(ci16dyoffset*stcui16nPitch);
		}
		//	VOID					stTrim(SHAPE& shpshape)
		//		矩形「shpshape」を、「cv2nSize」に収まるようトリムします。
		static VOID				stTrim(SHAPE& shpshape)noexcept{
			//	横方向
			if(shpshape.v2iPosition.i16iX()<0){
				shpshape.v2nSize.i16nWidth()+=shpshape.v2iPosition.i16iX();
				shpshape.v2iPosition.i16iX()=0;
			}
			shpshape.v2nSize.i16nWidth()=STD::stxGetMaximum(shpshape.v2nSize.i16nWidth(),0);
			if(cv2nSize.i16nWidth()<shpshape.v2iPosition.i16iX()+shpshape.v2nSize.i16nWidth()){
				if(shpshape.v2iPosition.i16iX()<cv2nSize.i16nWidth())shpshape.v2nSize.i16nWidth()=cv2nSize.i16nWidth()-shpshape.v2iPosition.i16iX();
				else{
					shpshape.v2iPosition.i16iX()=cv2nSize.i16nWidth();
					shpshape.v2nSize.i16nWidth()=0;
				}
			}
			//	縦方向
			if(shpshape.v2iPosition.i16iY()<0){
				shpshape.v2nSize.i16nHeight()+=shpshape.v2iPosition.i16iY();
				shpshape.v2iPosition.i16iY()=0;
			}
			shpshape.v2nSize.i16nHeight()=STD::stxGetMaximum(shpshape.v2nSize.i16nHeight(),0);
			if(cv2nSize.i16nHeight()<shpshape.v2iPosition.i16iY()+shpshape.v2nSize.i16nHeight()){
				if(shpshape.v2iPosition.i16iY()<cv2nSize.i16nHeight())shpshape.v2nSize.i16nHeight()=cv2nSize.i16nHeight()-shpshape.v2iPosition.i16iY();
				else{
					shpshape.v2iPosition.i16iY()=cv2nSize.i16nHeight();
					shpshape.v2nSize.i16nHeight()=0;
				}
			}
			return;
		}
		//	VOID					stTrimSending(SHAPE& shpthis,VECTOR2& v2iposition)
		//		矩形「shpthis」を、「cv2nSize」に収まるようトリムします。
		//		「v2iposition」は「転送先」座標であり、「shpthis」の変化に応じ更新されますが、
		//		「cv2nSize」に縛られるものではないため、
		//		(「stTrimReceiving」とは異なり)単体チェックは行いません。
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
			shpthis.v2nSize=shpthis.v2nSize.v2GetMinimum(cv2nSize-shpthis.v2iPosition).v2GetMaximum(VECTOR2::stv2ImmediateZero());
			return;
		}
		//	VOID					stTrimReceiving(SHAPE& shpsource,VECTOR2& v2iposition)
		//		矩形「shpsource」および「v2iposition」を、「cv2nSize」に収まるようトリムします。
		static VOID				stTrimReceiving(SHAPE& shpsource,VECTOR2& v2iposition)noexcept{
			SUPER::stTrimReceiving(shpsource,v2iposition,cv2nSize);
			return;
		}
	protected:
		//	VOID					stFill(const PUINT16 cpui16cdestinationbase,CUINT16 cui16csource,CSHAPE& cshpshape)
		//		BG「cpui8cdestinationbase」に対し、「cui16csource」での塗りつぶしを実行します。
		static _INLINE_ VOID	stFill(const PUINT16 cpui16cdestinationbase,CUINT16 cui16csource,CSHAPE& cshpshape)noexcept{
			AUTO					shpshape=cshpshape;

			stTrim(shpshape);
			SUPER_stFill(cpui16cdestinationbase,cui16csource,shpshape);
			return;
		}
		//	VOID					stCopy(const PUINT16 cpui16cdestinationbase,const CANVASBG_SIZED_& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition)
		//		BG「cpui8cdestinationbase」に対し、BG「ccvssource」をコピーします。
		template<CVECTOR2 SCLASS_cv2nSize>
		static _INLINE_ VOID	stCopy(const PUINT16 cpui16cdestinationbase,const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition)noexcept{
			using					SCLASS=CANVASBG_SIZED_<SCLASS_cv2nSize>;
			AUTO					shpsource=cshpsource;
			AUTO					v2iposition=cv2iposition;

			SCLASS::stTrimSending(shpsource,v2iposition);
			stTrimReceiving(shpsource,v2iposition);
			SUPER_stCopy(
				cpui16cdestinationbase,
				ccvssource.pcui16cGetThis(),
				SCLASS::stui16iGetPosition(shpsource.v2iPosition),
				SCLASS::stcui16nPitch,
				shpsource.v2nSize,
				v2iposition
			);
			return;
		}
	private:
		static _INLINE_ VOID	SUPER_stFill(const PUINT16 cpui16cdestinationbase,CUINT16 cui16csource,CSHAPE& cshpshape)noexcept{
			SUPER::stFill(
				cpui16cdestinationbase,
				stui16iGetPosition(cshpshape.v2iPosition),
				sti16dGetOffset(cshpshape.v2nSize.i16nHeight()),
				UINT16(cshpshape.v2nSize.i16nWidth()<<1),
				stcui16nPitch,
				cui16csource
			);
			return;
		}
		static _INLINE_ VOID	SUPER_stCopy(const PUINT16 cpui16cdestinationbase,const PCUINT16 cpcui16csourcebase,CUINT16 cui16isourceposition,CUINT16 cui16nsourcepitch,CVECTOR2& cv2nsource,CVECTOR2& cv2iposition)noexcept{
			SUPER::stCopy(
				cpui16cdestinationbase,
				stui16iGetPosition(cv2iposition),
				sti16dGetOffset(cv2nsource.i16nHeight()),
				UINT16(cv2nsource.i16nWidth()<<1),
				stcui16nPitch,
				cpcui16csourcebase,
				cui16isourceposition,
				cui16nsourcepitch
			);
			return;
		}
	};

	//
	//		class:CANVASBG_ROM
	//

	template<CVECTOR2 cv2nSize>
	class CANVASBG_ROM:public CANVASBG_SIZED_<cv2nSize>{
	public:

		//
		//		class
		//

		//	SUPER
		using					SUPER=CANVASBG_SIZED_<cv2nSize>;
		//	CANVASBG_ROM
		using					CCANVASBG_ROM=const CANVASBG_ROM;
		using					PCANVASBG_ROM=CANVASBG_ROM*;
		using					PCCANVASBG_ROM=CCANVASBG_ROM*;
		//	SHAPE
		using					SHAPE=CANVASBG_::SHAPE;
		using					CSHAPE=CANVASBG_::CSHAPE;
		using					PSHAPE=CANVASBG_::PSHAPE;
		using					PCSHAPE=CANVASBG_::PCSHAPE;

		//
		//		body:CANVASBG_ROM
		//

	private:
	public:
		constexpr /*VOID*/		CANVASBG_ROM(CANVASBG_ROM&& cvssource)noexcept{
			SUPER::pcui16cThis=cvssource.pcui16cGetThis();
		}
		constexpr /*VOID*/		CANVASBG_ROM(const PCUINT16 cpcui16csource)noexcept{
			SUPER::pcui16cThis=cpcui16csource;
		}
	};

	//
	//		class:CANVASBG_RAM
	//

	template<CVECTOR2 cv2nSize>
	class CANVASBG_RAM:public CANVASBG_SIZED_<cv2nSize>{
	public:

		//
		//		class
		//

		//	SUPER
		using					SUPER=CANVASBG_SIZED_<cv2nSize>;
		//	CANVASBG_RAM
		using					CCANVASBG_RAM=const CANVASBG_RAM;
		using					PCANVASBG_RAM=CANVASBG_RAM*;
		using					PCCANVASBG_RAM=CCANVASBG_RAM*;
		//	SHAPE
		using					SHAPE=CANVASBG_::SHAPE;
		using					CSHAPE=CANVASBG_::CSHAPE;
		using					PSHAPE=CANVASBG_::PSHAPE;
		using					PCSHAPE=CANVASBG_::PCSHAPE;

		//
		//		body:CANVASBG_RAM
		//

	private:
		UINT16					aui16cThis[SUPER::stcui16nPitch*UINT16(SUPER::stcv2nSize.i16nHeight())];
	public:
		constexpr /*VOID*/		CANVASBG_RAM(VOID)noexcept{
			SUPER::pcui16cThis=aui16cThis;
		}
		//	VOID					Fill(CUINT16 cui16ccolor)
		//		「cui16csource」での塗りつぶしを実行します。
		_INLINE_ VOID			Fill(CUINT16 cui16csource)noexcept{
			FillRect(cui16csource,{VECTOR2::stv2ImmediateZero(),SUPER::stcv2nSize});
			return;
		}
		//	VOID					FillRect(CUINT16 cui16csource,CSHAPE& cshpshape)
		//		「cui16csource」での塗りつぶしを実行します。
		VOID					FillRect(CUINT16 cui16ccolor,CSHAPE& cshpshape)noexcept{
			SUPER::stFill(aui16cThis,cui16ccolor,cshpshape);
			return;
		}
		//	VOID					Copy(const CANVASBG_SIZED_& ccvssource,CVECTOR2& cv2iposition)
		//		BG「ccvssource」をコピーします。
		template<CVECTOR2 SCLASS_cv2nSize>
		_INLINE_ VOID			Copy(const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CVECTOR2& cv2iposition)noexcept{
			using					SCLASS=CANVASBG_SIZED_<SCLASS_cv2nSize>;

			CopyRect(ccvssource,{VECTOR2::stv2ImmediateZero(),SCLASS::stcv2nSize},cv2iposition);
			return;
		}
		//	VOID					CopyRect(const CANVASBG_SIZED_& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition)
		//		BG「ccvssource」をコピーします。
		template<CVECTOR2 SCLASS_cv2nSize>
		VOID					CopyRect(const CANVASBG_SIZED_<SCLASS_cv2nSize>& ccvssource,CSHAPE& cshpsource,CVECTOR2& cv2iposition)noexcept{
			SUPER::stCopy(aui16cThis,ccvssource,cshpsource,cv2iposition);
			return;
		}
	};
}

#endif
