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

//	private

VOID					PATTERN::stWrite_Body(
	const PUINT32			cpui32destination,
	COFWSIZE				cszndestination,
	const PCUINT32			cpcui32source
)noexcept{
	AUTO					pui32destination=cpui32destination;
	CAUTO					cpui32destination_end=PUINT32(PUINT8(pui32destination)+cszndestination);
	AUTO					pcui32source=cpcui32source;

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
