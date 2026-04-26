/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'common/collider_.hpp'							2026 written by int71	**
 ****************************************************************************/
#ifndef I71_COMMON_COLLIDER_
#define I71_COMMON_COLLIDER_

//
//		include
//

#include				<misc/collider.hpp>
#include				"map.hpp"
#include				"vector2_.hpp"

//
//		namespace:m68k::i71::common
//

namespace m68k::i71::common{

	//
	//		class
	//

	//	COLLIDER_
	template<CUINT16 cui16dOffset,CUINT32 COLLIDERRAM_cui32iAddress>
	class COLLIDER_;

	//
	//		class:COLLIDER_
	//

	template<CUINT16 cui16dOffset,CUINT32 COLLIDERRAM_cui32iAddress>
	class COLLIDER_{
	public:

		//
		//		const
		//

		using					IDREGISTERW=misc::COLLIDER::IDREGISTERW;
		using					IDREGISTERR=misc::COLLIDER::IDREGISTERR;
		using					IDCOMMAND=misc::COLLIDER::IDCOMMAND;
		static constexpr AUTO	stcui16nTargetMaximumA=							misc::COLLIDER::stcui16nTargetMaximumA;
		static constexpr AUTO	stcui16nTargetMaximumB=							misc::COLLIDER::stcui16nTargetMaximumB;
		static constexpr AUTO	COLLIDERRAM_stcui16dOffsetTargetA=				misc::COLLIDER::COLLIDERRAM_stcui16dOffsetTargetA;
		static constexpr AUTO	COLLIDERRAM_stcui16dOffsetTargetB=				misc::COLLIDER::COLLIDERRAM_stcui16dOffsetTargetB;
		static constexpr AUTO	REGISTERW_Command_stcui8iExecBit=				misc::COLLIDER::REGISTERW_Command_stcui8iExecBit;
		static constexpr AUTO	REGISTERW_Command_stcui16cExecMask=				misc::COLLIDER::REGISTERW_Command_stcui16cExecMask;
		static constexpr AUTO	REGISTERW_TargetA_stcui8iStartBit=				misc::COLLIDER::REGISTERW_TargetA_stcui8iStartBit;
		static constexpr AUTO	REGISTERW_TargetA_stcui16cStartMask=			misc::COLLIDER::REGISTERW_TargetA_stcui16cStartMask;
		static constexpr AUTO	REGISTERW_TargetA_stcui8iEndBit=				misc::COLLIDER::REGISTERW_TargetA_stcui8iEndBit;
		static constexpr AUTO	REGISTERW_TargetA_stcui16cEndMask=				misc::COLLIDER::REGISTERW_TargetA_stcui16cEndMask;
		static constexpr AUTO	REGISTERW_TargetB_stcui8iStartBit=				misc::COLLIDER::REGISTERW_TargetB_stcui8iStartBit;
		static constexpr AUTO	REGISTERW_TargetB_stcui16cStartMask=			misc::COLLIDER::REGISTERW_TargetB_stcui16cStartMask;
		static constexpr AUTO	REGISTERW_TargetB_stcui8iEndBit=				misc::COLLIDER::REGISTERW_TargetB_stcui8iEndBit;
		static constexpr AUTO	REGISTERW_TargetB_stcui16cEndMask=				misc::COLLIDER::REGISTERW_TargetB_stcui16cEndMask;
		static constexpr AUTO	REGISTERR_Status_stcui8iCommandBit=				misc::COLLIDER::REGISTERR_Status_stcui8iCommandBit;
		static constexpr AUTO	REGISTERR_Status_stcui16cCommandMask=			misc::COLLIDER::REGISTERR_Status_stcui16cCommandMask;
		static constexpr AUTO	REGISTERR_Status_stcui8iBusyBit=				misc::COLLIDER::REGISTERR_Status_stcui8iBusyBit;
		static constexpr AUTO	REGISTERR_Status_stcui16cBusyMask=				misc::COLLIDER::REGISTERR_Status_stcui16cBusyMask;
		static constexpr AUTO	stcui32iSelectWAddress=							MAP::DEVICE::stcui32iAddress+UINT32(cui16dOffset)+UINT32(MAP::DEVICE::COLLIDER_stcui16dSelectWOffset);
		static constexpr AUTO	stcui32iSelectRAddress=							MAP::DEVICE::stcui32iAddress+UINT32(cui16dOffset)+UINT32(MAP::DEVICE::COLLIDER_stcui16dSelectROffset);
		static constexpr AUTO	stcui32iDataAddress=							MAP::DEVICE::stcui32iAddress+UINT32(cui16dOffset)+UINT32(MAP::DEVICE::COLLIDER_stcui16dDataOffset);

		//
		//		class
		//

		//	COLLIDER
		using					COLLIDER=COLLIDER_<cui16dOffset,COLLIDERRAM_cui32iAddress>;
		using					CCOLLIDER=const COLLIDER;
		using					PCOLLIDER=COLLIDER*;
		using					PCCOLLIDER=CCOLLIDER*;
		//	SQUARE
		class SQUARE;
		using					CSQUARE=const SQUARE;
		using					PSQUARE=SQUARE*;
		using					PCSQUARE=CSQUARE*;
		//	ST
		class ST;
		using					CST=const ST;
		using					PST=ST*;
		using					PCST=CST*;

		//
		//		class:SQUARE
		//

		class SQUARE{
		public:
			VECTOR2_				v2iPosition;
			VECTOR2_				v2nSizeHalf;
		};

		//
		//		class:ST
		//

		class ST{
		public:
		public:
			VOID					Delete(VOID)noexcept{
				return;
			}
		};

		//
		//		body:COLLIDER_
		//

	public:
		SQUARE					asqrTargetA[stcui16nTargetMaximumA];
		SQUARE					asqrTargetB[stcui16nTargetMaximumB];
	private:
		static inline ST		st;
	public:
		static VOID				stNew(VOID)noexcept{
			return;
		}
		static VOID				stDelete(VOID)noexcept{
			st.Delete();
			return;
		}
		static _INLINE_ COLLIDER&	COLLIDERRAM_stcldrDelegate(VOID)noexcept{
			return *PCOLLIDER(COLLIDERRAM_cui32iAddress);
		}
		static _INLINE_ VOID	stWrite(const IDREGISTERW cidregisterw,CUINT16 cui16value)noexcept{
			stWrite_Select(cidregisterw);
			stWrite_Write(cui16value);
			return;
		}
		static _INLINE_ VOID	stWrite_Select(const IDREGISTERW cidregisterw)noexcept{
			DEVICE_stui16Delegate(stcui32iSelectWAddress)=UINT16(cidregisterw);
			return;
		}
		static _INLINE_ VOID	stWrite_Write(CUINT16 cui16value)noexcept{
			DEVICE_stui16Delegate(stcui32iDataAddress)=cui16value;
			return;
		}
		static _INLINE_ _UNDISCARDABLE_ CUINT16&	stui16Read(const IDREGISTERR cidregisterr)noexcept{
			stRead_Select(cidregisterr);
			return stui16Read_Read();
		}
		static _INLINE_ VOID	stRead_Select(const IDREGISTERR cidregisterr)noexcept{
			DEVICE_stui16Delegate(stcui32iSelectRAddress)=UINT16(cidregisterr);
			return;
		}
		static _INLINE_ _UNDISCARDABLE_ CUINT16&	stui16Read_Read(VOID)noexcept{
			return DEVICE_stcui16GetThis(stcui32iDataAddress);
		}
		static _INLINE_ VOID	stSetTargetA(CUINT8 cui8istart,CUINT8 cui8iend)noexcept{
			stWrite(
				IDREGISTERW::TargetA,
				UINT16(
					(UINT16(cui8istart)<<REGISTERW_TargetA_stcui8iStartBit)|
					(UINT16(cui8iend)<<REGISTERW_TargetA_stcui8iEndBit)
				)
			);
			return;
		}
		static _INLINE_ VOID	stSetTargetB(CUINT8 cui8istart,CUINT8 cui8iend)noexcept{
			stWrite(
				IDREGISTERW::TargetB,
				UINT16(
					(UINT16(cui8istart)<<REGISTERW_TargetB_stcui8iStartBit)|
					(UINT16(cui8iend)<<REGISTERW_TargetB_stcui8iEndBit)
				)
			);
			return;
		}
		static _INLINE_ VOID	stDetectCollision(VOID)noexcept{
			stWrite(
				IDREGISTERW::Command,
				UINT16(
					REGISTERW_Command_stcui16cExecMask|
					UINT16(IDCOMMAND::DetectCollision)
				)
			);
			return;
		}
		static _INLINE_ _UNDISCARDABLE_ CUINT16&	stui16ReadCollidedB(CUINT8 cui8iset)noexcept{
			stReadCollidedB_WaitforDone(cui8iset);
			return stui16ReadCollidedB_Read(cui8iset);
		}
		static _INLINE_ VOID	stReadCollidedB_WaitforDone(CUINT8 cui8iset)noexcept{
			stRead_Select(IDREGISTERR::ProcessingB);
			while(stui16Read_Read()<=cui8iset);
			return;
		}
		static _INLINE_ _UNDISCARDABLE_ CUINT16&	stui16ReadCollidedB_Read(CUINT8 cui8iset)noexcept{
			return stui16Read(IDREGISTERR(UINT8(IDREGISTERR::CollidedB0)+cui8iset));
		}
	private:
		static _INLINE_ _UNDISCARDABLE_ UINT16&	DEVICE_stui16Delegate(CUINT32 cui32iaddress)noexcept{
			return *PUINT16(cui32iaddress);
		}
		static _INLINE_ _UNDISCARDABLE_ CUINT16&	DEVICE_stcui16GetThis(CUINT32 cui32iaddress)noexcept{
			return *PCUINT16(cui32iaddress);
		}
	};
}

#endif
