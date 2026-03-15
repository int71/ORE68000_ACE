/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'main/vector2.cpp'								2025 written by int71	**
 ****************************************************************************/

//
//		include
//

#include				"vector2.hpp"	// IWYU pragma: keep

//
//		using
//

using namespace m68k::i71::main;

//
//		class:VECTOR2
//

//	public

UINT8					VECTOR2::TRIG_ui8iGetAngle(VOID)const noexcept{
	if(0<=i16iX()){
		if(0<=i16iY())return TRIG_ui8iGetAngle_Positive();
		else return UINT8(TRIG_stcui16nAngle-VECTOR2(i16iX(),-i16iY()).TRIG_ui8iGetAngle_Positive());
	}else{
		if(0<=i16iY())return UINT8((TRIG_stcui16nAngle>>1)-VECTOR2(-i16iX(),i16iY()).TRIG_ui8iGetAngle_Positive());
		else return UINT8((TRIG_stcui16nAngle>>1)+VECTOR2(-i16iX(),-i16iY()).TRIG_ui8iGetAngle_Positive());
	}
}

//	private

_INLINE_ UINT8			VECTOR2::TRIG_ui8iGetAngle_Positive(VOID)const noexcept{
	AUTO					i16ix=i16iX();
	AUTO					i16iy=i16iY();

	while((ATAN_stcui16nTableSide<=i16ix)||(ATAN_stcui16nTableSide<=i16iy)){
		i16ix>>=1;
		i16iy>>=1;
	}
	return MEMORY::ROM_ATAN_stcui8GetThis(UINT8(i16ix),UINT8(i16iy));
}
