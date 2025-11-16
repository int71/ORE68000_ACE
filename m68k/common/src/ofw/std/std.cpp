/****************************************************************************
**																			**
**																			**
**									m68k									**
**																			**
**	'm68k/ofw/std/std.cpp'							2024 written by int71	**
 ****************************************************************************/

//
//		include
//

#include				<ofw/std/std.hpp>

//
//		std
//

_STD_ PVOID 			memset(
	const PVOID				cpdestination,
	CINT					cisource,
	COFWSIZE				cszndestination
)noexcept{
	CAUTO					cbsource=BYTE(cisource);

	if(
		(PTRINT(cpdestination)&1)||
		(cszndestination&1)
	){
		AUTO					pbdestination=PBYTE(cpdestination);
		CAUTO					cpbdestinationend=pbdestination+cszndestination;

		while(pbdestination<cpbdestinationend){
			BARRIER;
			*pbdestination=cbsource;
			++pbdestination;
		}
	}else{
		CAUTO					cwsource=WORD(cbsource)|(WORD(cbsource)<<8);

		if(cszndestination&3){
			AUTO					pwdestination=PWORD(cpdestination);
			CAUTO					cpwdestinationend=pwdestination+(cszndestination>>1);

			while(pwdestination<cpwdestinationend){
				BARRIER;
				*pwdestination=cwsource;
				++pwdestination;
			}
		}else{
			CAUTO					cdwsource=DWORD(cwsource)|(DWORD(cwsource)<<16);
			AUTO					pdwdestination=PDWORD(cpdestination);
			CAUTO					cpdwdestinationend=pdwdestination+(cszndestination>>2);

			while(pdwdestination<cpdwdestinationend){
				BARRIER;
				*pdwdestination=cdwsource;
				++pdwdestination;
			}
		}
	}
	return cpdestination;
}

_STD_ PVOID 			memcpy(
	const PVOID				cpdestination,
	const PCVOID			cpcsource,
	COFWSIZE				csznsource
)noexcept{
	if(
		(PTRINT(cpdestination)&1)||
		(PTRINT(cpcsource)&1)||
		(csznsource&1)
	){
		AUTO					pbdestination=PBYTE(cpdestination);
		AUTO					pcbsource=PCBYTE(cpcsource);
		CAUTO					cpcbsourceend=pcbsource+csznsource;

		while(pcbsource<cpcbsourceend){
			BARRIER;
			*pbdestination=*pcbsource;
			++pbdestination;
			++pcbsource;
		}
	}else if(csznsource&3){
		AUTO					pwdestination=PWORD(cpdestination);
		AUTO					pcwsource=PCWORD(cpcsource);
		CAUTO					cpcwsourceend=pcwsource+(csznsource>>1);

		while(pcwsource<cpcwsourceend){
			BARRIER;
			*pwdestination=*pcwsource;
			++pwdestination;
			++pcwsource;
		}
	}else{
		AUTO					pdwdestination=PDWORD(cpdestination);
		AUTO					pcdwsource=PCDWORD(cpcsource);
		CAUTO					cpcdwsourceend=pcdwsource+(csznsource>>2);

		while(pcdwsource<cpcdwsourceend){
			BARRIER;
			*pdwdestination=*pcdwsource;
			++pdwdestination;
			++pcdwsource;
		}
	}
	return cpdestination;
}

_STD_ PVOID 			memmove(
	const PVOID				cpdestination,
	const PCVOID			cpcsource,
	COFWSIZE				csznsource
)noexcept{
	if(cpdestination<cpcsource)return memcpy(cpdestination,cpcsource,csznsource);
	if(
		(PTRINT(cpdestination)&1)||
		(PTRINT(cpcsource)&1)||
		(csznsource&1)
	){
		AUTO					pbdestination=PBYTE(cpdestination)+csznsource;
		CAUTO					cpcbsourcestart=PCBYTE(cpcsource);
		AUTO					pcbsource=cpcbsourcestart+csznsource;

		while(cpcbsourcestart<pcbsource){
			BARRIER;
			--pbdestination;
			--pcbsource;
			*pbdestination=*pcbsource;
		}
	}else if(csznsource&3){
		AUTO					pwdestination=PWORD(cpdestination)+(csznsource>>1);
		CAUTO					cpcwsourcestart=PCWORD(cpcsource);
		AUTO					pcwsource=cpcwsourcestart+(csznsource>>1);

		while(cpcwsourcestart<pcwsource){
			BARRIER;
			--pwdestination;
			--pcwsource;
			*pwdestination=*pcwsource;
		}
	}else{
		AUTO					pdwdestination=PDWORD(cpdestination)+(csznsource>>2);
		CAUTO					cpcdwsourcestart=PCDWORD(cpcsource);
		AUTO					pcdwsource=cpcdwsourcestart+(csznsource>>2);

		while(cpcdwsourcestart<pcdwsource){
			BARRIER;
			--pdwdestination;
			--pcdwsource;
			*pdwdestination=*pcdwsource;
		}
	}
	return cpdestination;
}

//
//		class:STD
//

//	public

UINT16					STD::stui16cRead(
	PCUSTR&					pcustrsource
)noexcept{
	if(pcustrsource)if(
		CAUTO					cui8csource=UINT8(*pcustrsource);
		cui8csource
	){
		if(
			(cui8csource<0x80)||(
				(0xa0<=cui8csource)&&
				(cui8csource<0xe0)
			)
		){
			++pcustrsource;
			return UINT16(cui8csource);
		}else{
			++pcustrsource;
			{
				CAUTO					cui8csourcel=UINT8(*pcustrsource);

				++pcustrsource;
				return (UINT16(cui8csource)<<8)|UINT16(cui8csourcel);
			}
		}
	}
	return 0;
}

VOID					STD::stFill(
	const PUINT16			cpui16destination,
	COFWSIZE				cszndestination,
	CUINT16					cui16source
)noexcept{
	AUTO					pui16destination=cpui16destination;
	CAUTO					cpui16destinationend=pui16destination+cszndestination;

	while(pui16destination<cpui16destinationend){
		BARRIER;
		*pui16destination=cui16source;
		++pui16destination;
	}
	return;
}

VOID					STD::stFill(
	const PUINT32			cpui32destination,
	COFWSIZE				cszndestination,
	CUINT32					cui32source
)noexcept{
	AUTO					pui32destination=cpui32destination;
	CAUTO					cpui32destinationend=pui32destination+cszndestination;

	while(pui32destination<cpui32destinationend){
		BARRIER;
		*pui32destination=cui32source;
		++pui32destination;
	}
	return;
}

VOID					STD::stCopy(
	const PUSTR				cpustrdestination,
	COFWSIZE				cszndestination,
	const PCUSTR			cpcustrsource
)noexcept{
	CAUTO					cpustrdestinationend=cpustrdestination+cszndestination-1;
	AUTO					pustrdestination=cpustrdestination;

	for(AUTO pcustrsource=cpcustrsource;(pustrdestination<cpustrdestinationend)&&(*pcustrsource!=0);++pcustrsource){
		*pustrdestination=*pcustrsource;
		++pustrdestination;
	}
	*pustrdestination=0;
	if(cpustrdestination<pustrdestination){
		--pustrdestination;
		if((*pustrdestination)&0x80)*pustrdestination=0;
	}
	return;
}
