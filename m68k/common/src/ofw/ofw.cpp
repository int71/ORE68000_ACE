/****************************************************************************
**																			**
**																			**
**									m68k									**
**																			**
**	'm68k/ofw/ofw.cpp'								2024 written by int71	**
 ****************************************************************************/

//
//		include
//

#include				<ofw/ofw.hpp>

//
//		primitive
//

using					FP_STARTUP=VOID(*)(VOID)noexcept;

//
//		class:OFW
//

//
//		entry
//

_STD_ UINT8				_init_aui8dst[];
_STD_ UINT8				_init_aui8dst_end[];
_STD_ CUINT8			_init_acui8src[];
_STD_ FP_STARTUP		_init_afp_startup[];
_STD_ FP_STARTUP		_init_afp_startup_end[];

_STD_ _NORETURN_		_main(VOID)noexcept{
	{
		AUTO					pui8dst=_init_aui8dst;
		AUTO					pcui8src=_init_acui8src;

		while(pui8dst<_init_aui8dst_end){
			*pui8dst=*pcui8src;
			++pui8dst;
			++pcui8src;
		}
	}
	for(AUTO fp_startup=_init_afp_startup;fp_startup<_init_afp_startup_end;++fp_startup)(*fp_startup)();
	main();
	while(TRUE);
	NEVER;
}
