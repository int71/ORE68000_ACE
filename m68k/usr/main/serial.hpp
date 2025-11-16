/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'main/serial.hpp'								2025 written by int71	**
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
	class SERIAL;

	//
	//		class:SERIAL
	//

	class SERIAL:public common::SERIAL_<
		common::MAP::DEVICE::SERIAL_stcui16dOffsetM+common::MAP::DEVICE::SERIAL_stcui16dDataOffset
	>{
	};
}

#endif
