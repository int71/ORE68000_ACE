/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/collider.hpp'								2026 written by int71	**
 ****************************************************************************/
#ifndef I71_SUB_COLLIDER
#define I71_SUB_COLLIDER

//
//		include
//

#include				"../common/collider_.hpp"

//
//		namespace:m68k::i71::sub
//

namespace m68k::i71::sub{

	//
	//		class
	//

	//	COLLIDER
	using					COLLIDER=common::COLLIDER_<common::MAP::DEVICE::COLLIDER_stcui16dOffsetS,common::MAP::COLLIDERRAM::stcui32iAddressS>;
	using					CCOLLIDER=const COLLIDER;
	using					PCOLLIDER=COLLIDER*;
	using					PCCOLLIDER=CCOLLIDER*;
}

//
//		class:COLLIDER
//

extern template class m68k::i71::common::COLLIDER_<m68k::i71::common::MAP::DEVICE::COLLIDER_stcui16dOffsetS,m68k::i71::common::MAP::COLLIDERRAM::stcui32iAddressS>;

#endif
