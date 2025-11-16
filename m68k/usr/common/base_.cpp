/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'common/base_.cpp'								2025 written by int71	**
 ****************************************************************************/

//
//		include
//

#include				"base_.hpp"

//
//		using
//

using namespace m68k::i71::common;

//
//		class:BASE_::ST
//

//	public

VOID					BASE_::ST::Delete(VOID)noexcept{
	return;
}

//
//		class:BASE_
//

//	public

VOID					BASE_::stNew(VOID)noexcept{
	return;
}

VOID					BASE_::stDelete(VOID)noexcept{
	st.Delete();
	return;
}
