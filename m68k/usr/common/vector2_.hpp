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
	//		const
	//

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
		constexpr VECTOR2_		v2GetAbs(VOID)const noexcept{
			return {
				STD::stxGetAbs(i16Value0_Body),
				STD::stxGetAbs(i16Value1_Body)
			};
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
