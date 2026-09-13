/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/pattern.cpp'								2025 written by int71	**
 ****************************************************************************/

//
//		include
//

#include				"base.hpp"
#include				"pattern.hpp"

//
//		using
//

using namespace m68k::i71::sub;

//
//		class:PATTERN
//

//	public

VOID					PATTERN::stNew(VOID)noexcept{
	return;
}

VOID					PATTERN::stDelete(VOID)noexcept{
	return;
}

VOID					PATTERN::stWrite(
	CUINT16					patternchr_cui16iaddressdestination,
	COFWSIZE				cszndestination,
	const PCVOID			cpcsource
)noexcept{
	AUTO					pui32destination=PUINT32(
		MAP::VRAM::stcui32iAddressS+(UINT32(patternchr_cui16iaddressdestination)<<5)
	);
	CAUTO					cpui32destination_end=PUINT32(PUINT8(pui32destination)+cszndestination);
	AUTO					pcui32source=PCUINT32(cpcsource);

	while(pui32destination<cpui32destination_end){
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
		*pui32destination=*pcui32source;++pui32destination;++pcui32source;
	}
	return;
}
