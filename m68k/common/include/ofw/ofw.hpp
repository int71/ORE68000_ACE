/****************************************************************************
**																			**
**																			**
**									m68k									**
**																			**
**	'm68k/ofw/ofw.hpp'								2026 written by int71	**
 ****************************************************************************/
#ifndef M68K_OFW_OFW
#define M68K_OFW_OFW

//
//		include
//

#include				<ofw/std/std.hpp>

//
//		namespace:m68k::ofw
//

namespace m68k::ofw{

	//
	//		class
	//

	class OFW;

	//
	//		class:OFW
	//

	//	OFW
	//		クラス初期化操作は不要で、各種機能は直接呼び出せます。
	class OFW{
	public:
		static _INLINE_ VOID	stNOP(VOID)noexcept{
			ASM(R"(
				NOP
			)");
			return;
		}
		static _INLINE_ VOID	stEnableInterrupt(VOID)noexcept{
			ASM(R"(
				MOVE.W					#0x2000,%SR
			)");
			return;
		}
		static _INLINE_ VOID	stDisableInterrupt(VOID)noexcept{
			ASM(R"(
				MOVE.W					#0x2700,%SR
			)");
			return;
		}
	};
}

//
//		entry
//

_STD_ INT				main(VOID)noexcept;
_STD_ _NORETURN_		_main(VOID)noexcept;

#endif
