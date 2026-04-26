/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/serial.hpp'								2026 written by int71	**
 ****************************************************************************/
#ifndef I71_SUB_SERIAL
#define I71_SUB_SERIAL

//
//		include
//

#include				"../common/serial_.hpp"

//
//		namespace:m68k::i71::sub
//

namespace m68k::i71::sub{

	//
	//		class
	//

	//	SERIAL
	using					SERIAL=common::SERIAL_<common::MAP::DEVICE::SERIAL_stcui16dOffsetS>;
}

//
//		class:SERIAL
//

extern template class m68k::i71::common::SERIAL_<m68k::i71::common::MAP::DEVICE::SERIAL_stcui16dOffsetS>;

#endif
