/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'sub/interrupter.hpp'							2025 written by int71	**
 ****************************************************************************/
#ifndef I71_SUB_INTERRUPTER
#define I71_SUB_INTERRUPTER

//
//		include
//

#include				"base.hpp"

//
//		namespace:m68k::i71::sub
//

namespace m68k::i71::sub{

	//
	//		class
	//

	//	INTERRUPTER
	class INTERRUPTER;
	using					CINTERRUPTER=const INTERRUPTER;
	using					PINTERRUPTER=INTERRUPTER*;
	using					PCINTERRUPTER=CINTERRUPTER*;

	//
	//		class:INTERRUPTER
	//

	class INTERRUPTER{
	public:

		//
		//		class
		//

		//	ST
		class ST;
		using					CST=const ST;
		using					PST=ST*;
		using					PCST=CST*;

		//
		//		class:ST
		//

		class ST{
		public:
		public:
			VOID					Delete(VOID)noexcept;
		};

		//
		//		body:INTERRUPTER
		//

	private:
		static inline ST		st;
	public:
		static VOID				stNew(VOID)noexcept;
		static VOID				stDelete(VOID)noexcept;
		static _INLINE_ VOID	stRaiseS2M(CUINT8 cui8ilevel)noexcept{
			DEVICE_stui8Delegate(0+MAP::DEVICE::INTERRUPTER_stcui16dDataOffset)=cui8ilevel;
			return;
		}
	private:
		static _INLINE_ _UNDISCARDABLE_ UINT8&	DEVICE_stui8Delegate(CUINT16 cui16iaddress)noexcept{
			return MEMORY::DEVICE_stui8DelegateThis(MAP::DEVICE::INTERRUPTER_stcui16dOffsetS+cui16iaddress);
		}
	};
}

#endif
