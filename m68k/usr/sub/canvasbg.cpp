/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/canvasbg.cpp'								2026 written by int71	**
 ****************************************************************************/

//
//		include
//

#include				"canvasbg.hpp"

//
//		using
//

using namespace m68k::i71::sub;

//
//		class:CANVASBG
//

//	protected

VOID					CANVASBG_::stFill(
	const PUINT16			cpui16cdestinationbase,
	CUINT16					cui16idestinationposition,
	CUINT16					cui16ddestinationoffsetend,
	CUINT16					cui16ndestinationh,
	CUINT16					cui16ndestinationpitch,
	CUINT16					cui16csource
)noexcept{
	CAUTO					cui16ndestinationnext=cui16ndestinationpitch-cui16ndestinationh;
	AUTO					pui8cdestination=PUINT8(cpui16cdestinationbase)+cui16idestinationposition;

	for(
		CAUTO					cpui8cdestination_end=pui8cdestination+cui16ddestinationoffsetend;
		pui8cdestination<cpui8cdestination_end;
		pui8cdestination+=cui16ndestinationnext
	){
		for(
			CAUTO					cpui8cdestinationhline_end=pui8cdestination+cui16ndestinationpitch;
			pui8cdestination<cpui8cdestinationhline_end;
			pui8cdestination+=SIZEOF(UINT16)
		)*PUINT16(pui8cdestination)=cui16csource;
	}
	return;
}

VOID					CANVASBG_::stCopy(
	const PUINT16			cpui16cdestinationbase,
	CUINT16					cui16idestinationposition,
	CUINT16					cui16ddestinationoffsetend,
	CUINT16					cui16ndestinationh,
	CUINT16					cui16ndestinationpitch,
	const PCUINT16			cpcui16csourcebase,
	CUINT16					cui16isourceposition,
	CUINT16					cui16nsourcepitch
)noexcept{
	CAUTO					cui16ndestinationnext=UINT16(cui16ndestinationpitch-cui16ndestinationh);
	CAUTO					cui16nsourcenext=UINT16(cui16nsourcepitch-cui16ndestinationh);
	AUTO					pui8cdestination=PUINT8(cpui16cdestinationbase)+cui16idestinationposition;
	AUTO					pcui8csource=PCUINT8(cpcui16csourcebase)+cui16isourceposition;

	for(
		CAUTO					cpui8cdestination_end=pui8cdestination+cui16ddestinationoffsetend;
		pui8cdestination<cpui8cdestination_end;
		pui8cdestination+=cui16ndestinationnext,pcui8csource+=cui16nsourcenext
	){
		for(
			CAUTO					cpui8cdestinationhline_end=pui8cdestination+cui16ndestinationpitch;
			pui8cdestination<cpui8cdestinationhline_end;
			pui8cdestination+=SIZEOF(UINT16),pcui8csource+=SIZEOF(UINT16)
		)*PUINT16(pui8cdestination)=*PCUINT16(pcui8csource);
	}
	return;
}

