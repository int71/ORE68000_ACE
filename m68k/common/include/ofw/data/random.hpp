/****************************************************************************
**																			**
**																			**
**									m68k									**
**																			**
**	'm68k/ofw/data/random.hpp'						2025 written by int71	**
 ****************************************************************************/
#ifndef M68K_OFW_DATA_RANDOM
#define M68K_OFW_DATA_RANDOM

//
//		include
//

#include				<ofw/std/std.hpp>

//
//		namespace:m68k
//

namespace m68k::ofw::data{

	//
	//		class
	//

	//	RANDOM
	class RANDOM;
	using					CRANDOM=const RANDOM;
	using					PRANDOM=RANDOM*;
	using					PCRANDOM=CRANDOM*;

	//
	//		class:RANDOM
	//

	class RANDOM{
	private:
		UINT32					ui32cGenerator;
	public:
		VOID					New(CUINT32 cui32cseed=0)noexcept;
		VOID					Delete(VOID)noexcept;
		UINT8					ui8GetValue1(VOID)noexcept;
		UINT8					ui8GetValue(VOID)noexcept;
		UINT16					ui16GetValue(VOID)noexcept;
		UINT32					ui32GetValue(VOID)noexcept;
	};
}

#endif
