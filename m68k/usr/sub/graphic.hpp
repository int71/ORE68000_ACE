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
		//		primitive
		//

		//	FP_BRUSH
		using					FP_BRUSH=UINT16(*)(CVECTOR2& cv2isource,CUINT16 cui16ccolorback,const PVOID cpobject)noexcept;

		//
		//		const
		//

		//	IDPART
		enum class IDPART{
			Upper,
			Lower
		};
		//	IDSIDE
		enum class IDSIDE{
			Left,
			Right
		};

		//
		//		class
		//

		//	SHAPE
		class SHAPE;
		using					CSHAPE=const SHAPE;
		using					PSHAPE=SHAPE*;
		using					PCSHAPE=CSHAPE*;
		//	BITMAP
		class BITMAP;
		using					CBITMAP=const BITMAP;
		using					PBITMAP=BITMAP*;
		using					PCBITMAP=CBITMAP*;
		//	ST
		class ST;
		using					CST=const ST;
		using					PST=ST*;
		using					PCST=CST*;

		//
		//		class:SHAPE
		//

		class SHAPE{
		public:
			VECTOR2					v2iPosition;
			VECTOR2					v2nSize;
		public:
			template<const IDPART cidPart>
			SHAPE					shpMakePart(VOID)const noexcept{
				if constexpr(cidPart==IDPART::Upper){
					if(v2iPosition.i16iY()<256){
						if(v2iPosition.i16iY()+v2nSize.i16nHeight()<=256)return *this;
						else return {
							v2iPosition,{
								v2nSize.i16nWidth(),INT16(256-v2iPosition.i16iY())
							}
						};
					}else return {
						{
							v2iPosition.i16iX(),INT16(256)
						},{
							v2nSize.i16nWidth(),INT16(0)
						}
					};
				}else{
					if(256<=v2iPosition.i16iY()){
						return *this;
					}else{
						if(
							CAUTO					ci16iyd=v2iPosition.i16iY()+v2nSize.i16nHeight();
							ci16iyd<=256
						)return {
							{
								v2iPosition.i16iX(),INT16(256)
							},{
								v2nSize.i16nWidth(),INT16(0)
							}
						};
						else return {
							{
								v2iPosition.i16iX(),INT16(256)
							},{
								v2nSize.i16nWidth(),INT16(ci16iyd-256)
							}
						};
					}
				}
			}
			template<CUINT8 cui8nAlignBit>
			_INLINE_ SHAPE			shpMakeUnit(VOID)const noexcept{
				constexpr AUTO			ci16naligndot=INT16(cui8nAlignBit>>2);
				constexpr AUTO			ci16cmask=INT16(ci16naligndot-1);
				CAUTO					ci16il=v2iPosition.i16iX();
				CAUTO					ci16ir=INT16(ci16il+v2nSize.i16nWidth());
				CAUTO					ci16il_aligned=INT16((ci16il+ci16cmask)&~ci16cmask);
				CAUTO					ci16ir_aligned=INT16(ci16ir&~ci16cmask);

				return {
					{
						ci16il_aligned,v2iPosition.i16iY()
					},{
						STD::stxGetMaximum(INT16(ci16ir_aligned-ci16il_aligned),INT16(0)),
						v2nSize.i16nHeight()
					}
				};
			}
			template<CUINT8 cui8nAlignBit,const IDSIDE cidSide>
			SHAPE					shpMakeFraction(VOID)const noexcept{
				constexpr AUTO			ci16naligndot=INT16(cui8nAlignBit>>2);
				CAUTO					ci16il=v2iPosition.i16iX();
				CAUTO					ci16ir=INT16(ci16il+v2nSize.i16nWidth());

				if constexpr(cidSide==IDSIDE::Left){
					constexpr AUTO			ci16cmask=INT16(ci16naligndot-1);
					CAUTO					ci16il_aligned=INT16((ci16il+ci16cmask)&~ci16cmask);
					CAUTO					ci16nwidth=INT16(ci16ir-ci16il_aligned);

					return {
						{
							ci16il_aligned,v2iPosition.i16iY()
						},{
							(
								//	「cui8nAlignBit」が「キリ番」になる開始位置であるかどうかで見る。
								//	「ci16il<=ci16il_aligned」は暗黙的に満たされている。
								(ci16il_aligned&ci16naligndot)&&
								(ci16naligndot<=ci16nwidth)
							)?ci16naligndot:INT16(0),
							v2nSize.i16nHeight()
						}
					};
				}else{
					//	INT16					ci16cmask
					//		「<<1」しているのは、開始位置が「一回り大きな単位でのキリ番」である必要があるから。
					constexpr AUTO			ci16cmask=INT16((ci16naligndot<<1)-1);
					CAUTO					ci16ir_aligned=INT16(ci16ir&~ci16cmask);
					CAUTO					ci16nwidth=INT16(ci16ir-ci16ir_aligned);

					return {
						{
							ci16ir_aligned,v2iPosition.i16iY()
						},{
							(
								(ci16il<=ci16ir_aligned)&&
								(ci16naligndot<=ci16nwidth)
							)?ci16naligndot:INT16(0),
							v2nSize.i16nHeight()
						}
					};
				}
			}
		};

		//
		//		class:BITMAP
		//

		class BITMAP{
		private:
			PCUINT16				pcui16cThis;
			VECTOR2					v2nSize;
			PCUINT16				pcui16cLast;
			INT16					i16iYLast;
		public:
			_INLINE_ /*VOID*/		BITMAP(const PCUINT16 cpcui16cthis){
				pcui16cThis=cpcui16cthis+2;
				v2nSize={INT16(cpcui16cthis[0]),INT16(cpcui16cthis[1])};
				i16iYLast=-1;
			}
			CVECTOR2&				v2nGetSize(VOID)const noexcept{
				return v2nSize;
			}
			_INLINE_ UINT16			ui16cGetColor(CVECTOR2& cv2iposition)noexcept{
				if(i16iYLast!=cv2iposition.i16iY()){
					i16iYLast=cv2iposition.i16iY();
					pcui16cLast=pcui16cThis+i16iYLast*v2nSize.i16nWidth();
				}
				return pcui16cLast[cv2iposition.i16iX()];
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
		static VOID				stDrawRect(CUINT16 cui16ccolor,CSHAPE& cshpshape)noexcept;
		static VOID				stCopy(BITMAP& bmpsource,CVECTOR2& cv2iposition)noexcept;
		static VOID				stCopyRect(BITMAP& bmpsource,CSHAPE& cshpsource,CVECTOR2& cv2iposition)noexcept;
	private:
		static _INLINE_ UINT16	stui16cGetColorBack0(const PCUINT16 cpcui16csource)noexcept;
		static _INLINE_ UINT16	stui16cGetColorBack1(const PCUINT16 cpcui16csource)noexcept;
		template<const IDPART cidPart>
		static _INLINE_ PUINT8	stpui8cGetDestination(CVECTOR2& cv2iposition)noexcept;
		template<const FP_BRUSH cfp_brushThis>
		static _INLINE_ VOID	stProcess(CSHAPE& cshpshape,const PVOID cpobject)noexcept;
		template<const FP_BRUSH cfp_brushThis,const IDPART cidPart>
		static VOID				stProcessPart(CSHAPE& cshpshape,const PVOID cpobject)noexcept;
		template<const FP_BRUSH cfp_brushThis,const IDPART cidPart,CUINT8 cui8nAlignBit>
		static VOID				stProcessUnit(CVECTOR2& cv2iorigin,CSHAPE& cshppart,const PVOID cpobject)noexcept;
		template<const FP_BRUSH cfp_brushThis,const IDPART cidPart,CUINT8 cui8nAlignBit,const IDSIDE cidSide>
		static VOID				stProcessFraction(CVECTOR2& cv2iorigin,CSHAPE& cshppart,const PVOID cpobject)noexcept;
	};
}

#endif
