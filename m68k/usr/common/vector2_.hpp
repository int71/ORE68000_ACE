/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'common/vector2_.hpp'							2025 written by int71	**
 ****************************************************************************/
#ifndef I71_COMMON_VECTOR2_
#define I71_COMMON_VECTOR2_

//
//		include
//

#include				<ore68000ace/memory.hpp>
#include				<ofw/std/std.hpp>

//
//		namespace:m68k::i71::common
//

namespace m68k::i71::common{

	//
	//		class
	//

	//	VECTOR2_
	class VECTOR2_;
	using					CVECTOR2_=const VECTOR2_;
	using					PVECTOR2_=VECTOR2_*;
	using					PCVECTOR2_=CVECTOR2_*;

	//
	//		class:VECTOR2_
	//

	class VECTOR2_{
	protected:
		INT16					i16Value0_Body;
		INT16					i16Value1_Body;
	public:
		static constexpr VECTOR2_	stv2ImmediateZero(VOID)noexcept{
			return {
				0,
				0
			};
		}
		static constexpr UINT16	FIXEDU_stui16cGetMask(CUINT8 fixedl_cui8nbit)noexcept{
			return UINT16(UINT32(1<<(16-fixedl_cui8nbit))-1);
		}
		constexpr /*VOID*/		VECTOR2_(VOID)noexcept{}
		constexpr /*VOID*/		VECTOR2_(CVECTOR2_& cv2source)noexcept{
			v2Equal(cv2source);
		}
		constexpr /*VOID*/		VECTOR2_(CINT16 ci16value0,CINT16 ci16value1)noexcept{
			v2Equal(ci16value0,ci16value1);
		}
		constexpr INT16			i16Value0(VOID)const noexcept{
			return i16Value0_Body;
		}
		constexpr INT16			i16Value1(VOID)const noexcept{
			return i16Value1_Body;
		}
		constexpr INT16			i16iX(VOID)const noexcept{
			return i16Value0_Body;
		}
		constexpr INT16			i16iY(VOID)const noexcept{
			return i16Value1_Body;
		}
		constexpr INT16			i16nWidth(VOID)const noexcept{
			return i16Value0_Body;
		}
		constexpr INT16			i16nHeight(VOID)const noexcept{
			return i16Value1_Body;
		}
		constexpr INT16&		i16iX(VOID)noexcept{
			return i16Value0_Body;
		}
		constexpr INT16&		i16iY(VOID)noexcept{
			return i16Value1_Body;
		}
		constexpr INT16&		i16nWidth(VOID)noexcept{
			return i16Value0_Body;
		}
		constexpr INT16&		i16nHeight(VOID)noexcept{
			return i16Value1_Body;
		}
		constexpr VECTOR2_&		v2Equal(CVECTOR2_& cv2source)noexcept{
			return v2Equal(cv2source.i16Value0_Body,cv2source.i16Value1_Body);
		}
		constexpr VECTOR2_&		v2Equal(CINT16 ci16value0,CINT16 ci16value1)noexcept{
			i16Value0_Body=ci16value0;
			i16Value1_Body=ci16value1;
			return *this;
		}
		constexpr VECTOR2_		v2GetMinimum(CVECTOR2_& cv2source)noexcept{
			return {
				STD::stxGetMinimum(i16Value0_Body,cv2source.i16Value0_Body),
				STD::stxGetMinimum(i16Value1_Body,cv2source.i16Value1_Body)
			};
		}
		constexpr VECTOR2_		v2GetMaximum(CVECTOR2_& cv2source)noexcept{
			return {
				STD::stxGetMaximum(i16Value0_Body,cv2source.i16Value0_Body),
				STD::stxGetMaximum(i16Value1_Body,cv2source.i16Value1_Body)
			};
		}
		constexpr VECTOR2_		v2GetAbs(VOID)const noexcept{
			return {
				STD::stxGetAbs(i16Value0_Body),
				STD::stxGetAbs(i16Value1_Body)
			};
		}
		//	OFWBOOL					FIXED_eIsHit<CUINT8 FIXEDL_cui8nBit>(CVECTOR2_& cv2iposition,CVECTOR2_& cv2nsizehalf)
		//		「cv2iposition」と衝突しているかを判定します。
		//		衝突していれば「TRUE」を返します。
		//		「cv2nsizehalf」は自身と判定対象の「1/2サイズ」の合計値です。
		//		自身のサイズが「4」、判定対象のサイズが「6」だとすると、
		//		座標の差が「4*1/2+6*1/2=5」以下で衝突となります。
		//		「cv2nsizehalf」で指定するのはこの「5」相当の値です。
		//		なお、衝突の条件が「未満」でなく「以下」なのは、判定アルゴリズムの都合です。
		template<CUINT8 FIXEDL_cui8nBit>
		constexpr OFWBOOL		FIXED_eIsHit(CVECTOR2_& cv2iposition,CVECTOR2_& cv2nsizehalf)const noexcept{
			constexpr AUTO			cui16cmask=FIXEDU_stui16cGetMask(FIXEDL_cui8nBit);
			CAUTO					ci16nsizehalf_width=cv2nsizehalf.i16nWidth();

			if(UINT16((i16iX()-cv2iposition.i16iX()+ci16nsizehalf_width)&cui16cmask)<=UINT16(ci16nsizehalf_width<<1)){
				CAUTO					ci16nsizehalf_height=cv2nsizehalf.i16nHeight();

				return (UINT16((i16iY()-cv2iposition.i16iY()+ci16nsizehalf_height)&cui16cmask)<=UINT16(ci16nsizehalf_height<<1));
			}
			return FALSE;
		}
		constexpr OFWBOOL		FIXED256_eIsHit(CVECTOR2_& cv2iposition,CVECTOR2_& cv2nsizehalf)const noexcept{
			return FIXED_eIsHit<8>(cv2iposition,cv2nsizehalf);
		}
		constexpr OFWBOOL		FIXED512_eIsHit(CVECTOR2_& cv2iposition,CVECTOR2_& cv2nsizehalf)const noexcept{
			return FIXED_eIsHit<7>(cv2iposition,cv2nsizehalf);
		}
		constexpr OFWBOOL		FIXED1024_eIsHit(CVECTOR2_& cv2iposition,CVECTOR2_& cv2nsizehalf)const noexcept{
			return FIXED_eIsHit<6>(cv2iposition,cv2nsizehalf);
		}
		//	OFWBOOL					FIXED_eIsHit<CUINT8 FIXEDL_cui8nBit>(CVECTOR2_& cv2nthissizehalf,CVECTOR2_& cv2iposition,CVECTOR2_& cv2nsizehalf)
		//		「cv2iposition」と衝突しているかを判定します。
		//		衝突していれば「TRUE」を返します。
		//		「cv2nthissizehalf」は自身の「1/2サイズ」、「cv2nsizehalf」は判定対象の「1/2サイズ」です。
		//		自身のサイズが「4」、判定対象のサイズが「6」だとすると、
		//		座標の差が「4*1/2+6*1/2=5」以下で衝突となります。
		//		なお、衝突の条件が「未満」でなく「以下」なのは、判定アルゴリズムの都合です。
		template<CUINT8 FIXEDL_cui8nBit>
		constexpr OFWBOOL		FIXED_eIsHit(CVECTOR2_& cv2nthissizehalf,CVECTOR2_& cv2iposition,CVECTOR2_& cv2nsizehalf)const noexcept{
			constexpr AUTO			cui16cmask=FIXEDU_stui16cGetMask(FIXEDL_cui8nBit);
			CAUTO					ci16nsizehalf_width=INT16(cv2nthissizehalf.i16nWidth()+cv2nsizehalf.i16nWidth());

			if(UINT16((i16iX()-cv2iposition.i16iX()+ci16nsizehalf_width)&cui16cmask)<=UINT16(ci16nsizehalf_width<<1)){
				CAUTO					ci16nsizehalf_height=INT16(cv2nthissizehalf.i16nHeight()+cv2nsizehalf.i16nHeight());

				return (UINT16((i16iY()-cv2iposition.i16iY()+ci16nsizehalf_height)&cui16cmask)<=UINT16(ci16nsizehalf_height<<1));
			}
			return FALSE;
		}
		constexpr OFWBOOL		FIXED256_eIsHit(CVECTOR2_& cv2nthissizehalf,CVECTOR2_& cv2iposition,CVECTOR2_& cv2nsizehalf)const noexcept{
			return FIXED_eIsHit<8>(cv2nthissizehalf,cv2iposition,cv2nsizehalf);
		}
		constexpr OFWBOOL		FIXED512_eIsHit(CVECTOR2_& cv2nthissizehalf,CVECTOR2_& cv2iposition,CVECTOR2_& cv2nsizehalf)const noexcept{
			return FIXED_eIsHit<7>(cv2nthissizehalf,cv2iposition,cv2nsizehalf);
		}
		constexpr OFWBOOL		FIXED1024_eIsHit(CVECTOR2_& cv2nthissizehalf,CVECTOR2_& cv2iposition,CVECTOR2_& cv2nsizehalf)const noexcept{
			return FIXED_eIsHit<6>(cv2nthissizehalf,cv2iposition,cv2nsizehalf);
		}
		constexpr OFWBOOL		operator ==(CVECTOR2_& cv2source)const noexcept{
			return (
				(i16Value0_Body==cv2source.i16Value0_Body)&&
				(i16Value1_Body==cv2source.i16Value1_Body)
			);
		}
		constexpr VECTOR2_		operator +(VOID)const noexcept{
			return *this;
		}
		constexpr VECTOR2_		operator -(VOID)const noexcept{
			return {
				INT16(-i16Value0_Body),
				INT16(-i16Value1_Body)
			};
		}
		constexpr VECTOR2_		operator +(CVECTOR2_& cv2source)const noexcept{
			return {
				INT16(i16Value0_Body+cv2source.i16Value0_Body),
				INT16(i16Value1_Body+cv2source.i16Value1_Body)
			};
		}
		constexpr VECTOR2_		operator -(CVECTOR2_& cv2source)const noexcept{
			return {
				INT16(i16Value0_Body-cv2source.i16Value0_Body),
				INT16(i16Value1_Body-cv2source.i16Value1_Body)
			};
		}
		constexpr VECTOR2_		operator *(CINT16 ci16source)const noexcept{
			return {
				INT16(i16Value0_Body*ci16source),
				INT16(i16Value1_Body*ci16source)
			};
		}
		constexpr VECTOR2_		operator >>(CUINT8 cui8nshift)const noexcept{
			return {
				INT16(i16Value0_Body>>cui8nshift),
				INT16(i16Value1_Body>>cui8nshift)
			};
		}
		constexpr VECTOR2_		operator <<(CUINT8 cui8nshift)const noexcept{
			return {
				INT16(i16Value0_Body<<cui8nshift),
				INT16(i16Value1_Body<<cui8nshift)
			};
		}
		constexpr VECTOR2_&		operator +=(CVECTOR2_& cv2source)noexcept{
			return *this=*this+cv2source;
		}
		constexpr VECTOR2_&		operator -=(CVECTOR2_& cv2source)noexcept{
			return *this=*this-cv2source;
		}
		constexpr VECTOR2_		operator *=(CINT16 ci16source)noexcept{
			return *this=*this*ci16source;
		}
		constexpr VECTOR2_		operator >>=(CUINT8 cui8nshift)noexcept{
			return *this=*this>>cui8nshift;
		}
		constexpr VECTOR2_		operator <<=(CUINT8 cui8nshift)noexcept{
			return *this=*this<<cui8nshift;
		}
	};
}

#endif
