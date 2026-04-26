/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'main/collider.hpp'								2026 written by int71	**
 ****************************************************************************/
#ifndef I71_MAIN_COLLIDER
#define I71_MAIN_COLLIDER

//
//		include
//

#include				"../common/collider_.hpp"

//
//		namespace:m68k::i71::main
//

namespace m68k::i71::main{

	//
	//		class
	//

	//	COLLIDER
	using					COLLIDER=common::COLLIDER_<common::MAP::DEVICE::COLLIDER_stcui16dOffsetM,common::MAP::COLLIDERRAM::stcui32iAddressM>;
	using					CCOLLIDER=const COLLIDER;
	using					PCOLLIDER=COLLIDER*;
	using					PCCOLLIDER=CCOLLIDER*;
}

//
//		class:COLLIDER
//

extern template class m68k::i71::common::COLLIDER_<m68k::i71::common::MAP::DEVICE::COLLIDER_stcui16dOffsetM,m68k::i71::common::MAP::COLLIDERRAM::stcui32iAddressM>;

#endif
