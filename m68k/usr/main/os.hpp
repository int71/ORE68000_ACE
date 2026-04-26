/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'main/os.hpp'									2025 written by int71	**
 ****************************************************************************/
#ifndef I71_MAIN_OS
#define I71_MAIN_OS

//
//		include
//

#include				"base.hpp"
#include				"collider.hpp"

//
//		namespace:m68k::i71::main
//

namespace m68k::i71::main{

	//
	//		class
	//

	//	OS
	class OS;

	//
	//		class:OS
	//

	class OS{
	public:

		//
		//		const
		//

		static constexpr AUTO	RAM_stcui32iStackInitialAddress=				RAM_stcui32iAddress+RAM_stcui32nSize;

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
			constexpr /*VOID*/		ST(VOID)noexcept{}
			VOID					Delete(VOID)noexcept;
		};

		//
		//		body:OS
		//

	private:
		static inline ST		st;
	public:
		static VOID				stNew(VOID)noexcept;
		static VOID				stDelete(VOID)noexcept;
		static VOID				stMain(VOID)noexcept;
		static _INLINE_ VOID	HPC_stReset(VOID)noexcept{
			DEVICE_HPC_stui16Delegate()=0;
			return;
		}
		static _INLINE_ UINT32	HPC_stui32Read(VOID)noexcept{
			CAUTO					cui16h=DEVICE_HPC_stui16Delegate();

			return ((UINT32(cui16h)<<16)|UINT32(DEVICE_HPC_stui16Delegate()))-12;
		}
		static _INLINE_ VOID	LFSR_stSetSeed(CUINT32 cui32cseed)noexcept{
			DEVICE_LFSR_stui16Delegate()=0x0000|((cui32cseed>>24)&0xff);
			DEVICE_LFSR_stui16Delegate()=0x0100|((cui32cseed>>16)&0xff);
			DEVICE_LFSR_stui16Delegate()=0x0200|((cui32cseed>> 8)&0xff);
			DEVICE_LFSR_stui16Delegate()=0x0300|((cui32cseed>> 0)&0xff);
			return;
		}
		static _INLINE_ UINT16	LFSR_stui16Read(VOID)noexcept{
			return DEVICE_LFSR_stui16Delegate();
		}
		static _INLINE_ COLLIDER&	COLLIDERRAM_stcldrDelegate(VOID)noexcept{
			return COLLIDER::COLLIDERRAM_stcldrDelegate();
		}
		static _INLINE_ VOID	COLLIDER_stWrite(const COLLIDER::IDREGISTERW cidregisterw,CUINT16 cui16value)noexcept{
			COLLIDER::stWrite(cidregisterw,cui16value);
			return;
		}
		static _INLINE_ VOID	COLLIDER_stWrite_Select(const COLLIDER::IDREGISTERW cidregisterw)noexcept{
			COLLIDER::stWrite_Select(cidregisterw);
			return;
		}
		static _INLINE_ VOID	COLLIDER_stWrite_Write(CUINT16 cui16value)noexcept{
			COLLIDER::stWrite_Write(cui16value);
			return;
		}
		static _INLINE_ _UNDISCARDABLE_ CUINT16&	COLLIDER_stui16Read(const COLLIDER::IDREGISTERR cidregisterr)noexcept{
			return COLLIDER::stui16Read(cidregisterr);
		}
		static _INLINE_ VOID	COLLIDER_stRead_Select(const COLLIDER::IDREGISTERR cidregisterr)noexcept{
			COLLIDER::stRead_Select(cidregisterr);
			return;
		}
		static _INLINE_ _UNDISCARDABLE_ CUINT16&	COLLIDER_stui16Read_Read(VOID)noexcept{
			return COLLIDER::stui16Read_Read();
		}
		static _INLINE_ VOID	COLLIDER_stSetTargetA(CUINT8 cui8istart,CUINT8 cui8iend)noexcept{
			COLLIDER::stSetTargetA(cui8istart,cui8iend);
			return;
		}
		static _INLINE_ VOID	COLLIDER_stSetTargetB(CUINT8 cui8istart,CUINT8 cui8iend)noexcept{
			COLLIDER::stSetTargetB(cui8istart,cui8iend);
			return;
		}
		static _INLINE_ VOID	COLLIDER_stDetectCollision(VOID)noexcept{
			COLLIDER::stDetectCollision();
			return;
		}
		static _INLINE_ _UNDISCARDABLE_ CUINT16&	COLLIDER_stui16ReadCollidedB(CUINT8 cui8iset)noexcept{
			return COLLIDER::stui16ReadCollidedB(cui8iset);
		}
		static _INLINE_ VOID	COLLIDER_stReadCollidedB_WaitforDone(CUINT8 cui8iset)noexcept{
			COLLIDER::stReadCollidedB_WaitforDone(cui8iset);
			return;
		}
		static _INLINE_ _UNDISCARDABLE_ CUINT16&	COLLIDER_stui16ReadCollidedB_Read(CUINT8 cui8iset)noexcept{
			return COLLIDER::stui16ReadCollidedB_Read(cui8iset);
		}
	private:
		static _HANDLER_ VOID	stINT1(VOID)noexcept;
		static _HANDLER_ VOID	stINT2(VOID)noexcept;
		static _HANDLER_ VOID	stINT3(VOID)noexcept;
		static _HANDLER_ VOID	stINT4(VOID)noexcept;
		static _HANDLER_ VOID	stINT5(VOID)noexcept;
		static _HANDLER_ VOID	stINT6(VOID)noexcept;
		static _HANDLER_ VOID	stINT7(VOID)noexcept;
		static _INLINE_ _UNDISCARDABLE_ UINT16&	DEVICE_HPC_stui16Delegate(VOID)noexcept{
			return MEMORY::DEVICE_stui16DelegateThis(MAP::DEVICE::HPC_stcui16dOffsetM);
		}
		static _INLINE_ _UNDISCARDABLE_ UINT16&	DEVICE_LFSR_stui16Delegate(VOID)noexcept{
			return MEMORY::DEVICE_stui16DelegateThis(MAP::DEVICE::LFSR_stcui16dOffsetM);
		}
	};
}

#endif
