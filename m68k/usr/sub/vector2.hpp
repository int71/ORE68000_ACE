/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/vector2.hpp'								2025 written by int71	**
 ****************************************************************************/
#ifndef I71_SUB_VECTOR2
#define I71_SUB_VECTOR2

//
//		include
//

#include				"../common/vector2_.hpp"
#include				"base.hpp"

//
//		namespace:m68k::i71::sub
//

namespace m68k::i71::sub{

	//
	//		class
	//

	//	VECTOR2
	class VECTOR2;
	using					CVECTOR2=const VECTOR2;
	using					PVECTOR2=VECTOR2*;
	using					PCVECTOR2=CVECTOR2*;

	//
	//		class:VECTOR2
	//

	class VECTOR2:public common::VECTOR2_{
	public:

		//
		//		const
		//

		static constexpr AUTO	ATAN_stcui8nTableBit=	ore68000ace::ATAN_stcui8nTableBit;
		static constexpr AUTO	ATAN_stcui16nTableSide=	ore68000ace::ATAN_stcui16nTableSide;
		static constexpr AUTO	TRIG_stcui16nAngle=		ore68000ace::TRIG_stcui16nAngle;
		static constexpr AUTO	TRIG_stcui8nWidthBit=	ore68000ace::TRIG_stcui8nWidthBit;
		static constexpr AUTO	TRIG_stci16nWidth=		ore68000ace::TRIG_stci16nWidth;

		//
		//		body:VECTOR2
		//

	public:
		static _INLINE_ VECTOR2	stv2Trigonometric(CUINT8 cui8iangle)noexcept{
			return {
				MEMORY::ROM_COS_stci16GetThis(cui8iangle),
				MEMORY::ROM_SIN_stci16GetThis(cui8iangle)
			};
		}
		constexpr /*VOID*/		VECTOR2(VOID)noexcept{}
		constexpr /*VOID*/		VECTOR2(common::CVECTOR2_& cv2source)noexcept{
			v2Equal(cv2source);
		}
		constexpr /*VOID*/		VECTOR2(CINT16 ci16value0,CINT16 ci16value1)noexcept{
			v2Equal(ci16value0,ci16value1);
		}
		constexpr VECTOR2&		v2Equal(common::CVECTOR2_& cv2source)noexcept{
			return v2Equal(cv2source.i16Value0(),cv2source.i16Value1());
		}
		constexpr VECTOR2&		v2Equal(CINT16 ci16value0,CINT16 ci16value1)noexcept{
			i16Value0_Body=ci16value0;
			i16Value1_Body=ci16value1;
			return *this;
		}
		UINT8					ui8Atan(VOID)const noexcept;
	private:
		_INLINE_ UINT8			ui8Atan_Positive(VOID)const noexcept;
	};
}

#endif
