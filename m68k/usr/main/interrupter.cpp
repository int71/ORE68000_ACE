/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'main/interrupter.cpp'							2025 written by int71	**
 ****************************************************************************/

//
//		include
//

#include				"interrupter.hpp"

//
//		using
//

using namespace m68k::i71::main;

//
//		class:INTERRUPTER::ST
//

VOID					INTERRUPTER::ST::Delete(VOID)noexcept{
	return;
}

//
//		class:INTERRUPTER
//

//	public

VOID					INTERRUPTER::stNew(VOID)noexcept{
	return;
}

VOID					INTERRUPTER::stDelete(VOID)noexcept{
	st.Delete();
	return;
}
