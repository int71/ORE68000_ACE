/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'main/boot.cpp'									2025 written by int71	**
 ****************************************************************************/

//
//		include
//

#include				"boot.hpp"	// IWYU pragma: keep
#include				"os.hpp"

//
//		using
//

using namespace m68k::i71::main;

//
//		entry
//

_STD_ INT				main(VOID)noexcept{
	OS::stNew();
	OS::stMain();
	OS::stDelete();
	return 0;
}
