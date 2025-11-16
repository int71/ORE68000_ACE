/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/serial.hpp'								2025 written by int71	**
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
	class SERIAL;
	using					CSERIAL=const SERIAL;

	//
	//		class:SERIAL
	//

	class SERIAL:public common::SERIAL_<
		common::MAP::DEVICE::SERIAL_stcui16dOffsetS+common::MAP::DEVICE::SERIAL_stcui16dDataOffset
	>{
	};
}

#endif
