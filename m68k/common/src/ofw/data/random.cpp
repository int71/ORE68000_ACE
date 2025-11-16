/****************************************************************************
**																			**
**																			**
**									m68k									**
**																			**
**	'm68k/ofw/data/random.cpp'						2024 written by int71	**
 ****************************************************************************/

//
//		include
//

#include				<ofw/data/random.hpp>

//
//		using
//

using namespace m68k::ofw::data;

//
//		class:RANDOM
//

//	public

VOID					RANDOM::New(
	CUINT32					cui32cseed
)noexcept{
	ui32cGenerator=cui32cseed;
	return;
}

VOID					RANDOM::Delete(VOID)noexcept{
	return;
}

UINT8					RANDOM::ui8GetValue1(VOID)noexcept{
	ui32cGenerator=(ui32cGenerator<<1)|((
		(ui32cGenerator>>31)^(ui32cGenerator>>21)^(ui32cGenerator>>1)^(ui32cGenerator>>0)^1
	)&1);
	return ui32cGenerator&1;
}

UINT8					RANDOM::ui8GetValue(VOID)noexcept{
	return 
		(ui8GetValue1()<<7)|
		(ui8GetValue1()<<6)|
		(ui8GetValue1()<<5)|
		(ui8GetValue1()<<4)|
		(ui8GetValue1()<<3)|
		(ui8GetValue1()<<2)|
		(ui8GetValue1()<<1)|
		(ui8GetValue1()<<0);
}

UINT16					RANDOM::ui16GetValue(VOID)noexcept{
	return (UINT16(ui8GetValue())<<8)|UINT16(ui8GetValue());
}

UINT32					RANDOM::ui32GetValue(VOID)noexcept{
	return (UINT32(ui16GetValue())<<16)|UINT32(ui16GetValue());
}
