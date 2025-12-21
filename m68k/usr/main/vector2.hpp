/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'main/vector2.hpp'								2025 written by int71	**
 ****************************************************************************/
#ifndef I71_MAIN_VECTOR2
#define I71_MAIN_VECTOR2

//
//		include
//

#include				"../common/vector2_.hpp"
#include				"base.hpp"

//
//		namespace:m68k::i71::main
//

namespace m68k::i71::main{

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
		//	VECTOR2					stv2Trigonometric(CUINT8 cui8iangle)
		//		角度「cui8iangle」に応じたCOS/SINを固定小数点値で返します。
		//		「1<<TRIG_stcui8nWidthBit」が「1.0」に対応します。
		//		スクリーン座標は右下がプラス方向となるので、角度は下記に対応します。
		//		    192
		//		     |
		//		128--+--  0
		//		     |
		//		     64
		static _INLINE_ VECTOR2	stv2Trigonometric(CUINT8 cui8iangle)noexcept{
			return {
				MEMORY::ROM_COS_stci16GetThis(cui8iangle),
				MEMORY::ROM_SIN_stci16GetThis(cui8iangle)
			};
		}
		static _INLINE_ VECTOR2	stv2dGetDirection(CUINT8 cui8iangle,CINT16 ci16nspeed)noexcept{
			CAUTO					cv2idunit=stv2Trigonometric(cui8iangle);

			return {
				INT16(STD::sti32Multiply(cv2idunit.i16iX(),ci16nspeed)>>TRIG_stcui8nWidthBit),
				INT16(STD::sti32Multiply(cv2idunit.i16iY(),ci16nspeed)>>TRIG_stcui8nWidthBit)
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
