/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'main/serial.hpp'								2026 written by int71	**
 ****************************************************************************/
#ifndef I71_MAIN_SERIAL
#define I71_MAIN_SERIAL

//
//		include
//

#include				"../common/serial_.hpp"

//
//		namespace:m68k::i71::main
//

namespace m68k::i71::main{

	//
	//		class
	//

	//	SERIAL
	using					SERIAL=common::SERIAL_<common::MAP::DEVICE::SERIAL_stcui16dOffsetM>;
}

//
//		class:SERIAL
//

extern template class m68k::i71::common::SERIAL_<m68k::i71::common::MAP::DEVICE::SERIAL_stcui16dOffsetM>;

#endif
