/****************************************************************************
**																			**
**																			**
**									I71										**
**																			**
**	'common/serial_.hpp'							2025 written by int71	**
 ****************************************************************************/
#ifndef I71_COMMON_SERIAL_
#define I71_COMMON_SERIAL_

//
//		include
//

#include				"map.hpp"

//
//		namespace:m68k::i71::common
//

namespace m68k::i71::common{

	//
	//		class
	//

	//	SERIAL_
	template<CUINT16 cui16dOffset>
	class SERIAL_;

	//
	//		class:SERIAL_
	//

	template<CUINT16 cui16dOffset>
	class SERIAL_{
	public:

		//
		//		const
		//

		static constexpr AUTO	stcui32iDataAddress=							MAP::DEVICE::stcui32iAddress+UINT32(cui16dOffset);
		static constexpr USTR	stacustrHex[]={
			'0','1','2','3',
			'4','5','6','7',
			'8','9','A','B',
			'C','D','E','F'
		};

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
			VOID					Delete(VOID)noexcept{
				return;
			}
		};

		//
		//		body:SERIAL_
		//

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
		static VOID				stWrite(const PCUSTR cpcustrsource)noexcept{
			for(AUTO pcustrsource=cpcustrsource;*pcustrsource;++pcustrsource)DEVICE_stustrDelegate()=*pcustrsource;
			return;
		}
		static VOID				stWrite(CINT8 ci8source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWrite(INT16(ci8source),cui8ndigitminimum);
			return;
		}
		static VOID				stWrite(CUINT8 cui8source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWrite(UINT16(cui8source),cui8ndigitminimum);
			return;
		}
		static VOID				stWrite(CINT16 ci16source,CUINT8 cui8ndigitminimum=0)noexcept{
			if(0<=ci16source)stWrite_Body(UINT16(ci16source),cui8ndigitminimum,FALSE);
			else stWrite_Body(UINT16(-ci16source),(1<=cui8ndigitminimum)?cui8ndigitminimum-1:0,TRUE);
			return;
		}
		static VOID				stWrite(CUINT16 cui16source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWrite_Body(cui16source,cui8ndigitminimum,FALSE);
			return;
		}
		static VOID				stWrite(CINT32 ci32source,CUINT8 cui8ndigitminimum=0)noexcept{
			if(0<=ci32source)stWrite_Body(UINT32(ci32source),cui8ndigitminimum,FALSE);
			else stWrite_Body(UINT32(-ci32source),(1<=cui8ndigitminimum)?cui8ndigitminimum-1:0,TRUE);
			return;
		}
		static VOID				stWrite(CUINT32 cui32source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWrite_Body(cui32source,cui8ndigitminimum,FALSE);
			return;
		}
		static VOID				stWriteHex(CINT8 ci8source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWriteHex_Body(UINT8(ci8source),cui8ndigitminimum,(0<=ci8source)?'0':stacustrHex[0xf]);
			return;
		}
		static VOID				stWriteHex(CUINT8 cui8source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWriteHex_Body(cui8source,cui8ndigitminimum,'0');
			return;
		}
		static VOID				stWriteHex(CINT16 ci16source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWriteHex_Body(UINT16(ci16source),cui8ndigitminimum,(0<=ci16source)?'0':stacustrHex[0xf]);
			return;
		}
		static VOID				stWriteHex(CUINT16 cui16source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWriteHex_Body(cui16source,cui8ndigitminimum,'0');
			return;
		}
		static VOID				stWriteHex(CINT32 ci32source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWriteHex_Body(UINT32(ci32source),cui8ndigitminimum,(0<=ci32source)?'0':stacustrHex[0xf]);
			return;
		}
		static VOID				stWriteHex(CUINT32 cui32source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWriteHex_Body(cui32source,cui8ndigitminimum,'0');
			return;
		}
		static VOID				stWriteLine(const PCUSTR cpcustrsource)noexcept{
			stWrite(cpcustrsource);
			stWrite("\n");
			return;
		}
		static VOID				stWriteLine(CINT8 ci8source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWrite(ci8source,cui8ndigitminimum);
			stWrite("\n");
			return;
		}
		static VOID				stWriteLine(CUINT8 cui8source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWrite(cui8source,cui8ndigitminimum);
			stWrite("\n");
			return;
		}
		static VOID				stWriteLine(CINT16 ci16source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWrite(ci16source,cui8ndigitminimum);
			stWrite("\n");
			return;
		}
		static VOID				stWriteLine(CUINT16 cui16source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWrite(cui16source,cui8ndigitminimum);
			stWrite("\n");
			return;
		}
		static VOID				stWriteLine(CINT32 ci32source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWrite(ci32source,cui8ndigitminimum);
			stWrite("\n");
			return;
		}
		static VOID				stWriteLine(CUINT32 cui32source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWrite(cui32source,cui8ndigitminimum);
			stWrite("\n");
			return;
		}
		static VOID				stWriteHexLine(CINT8 ci8source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWriteHex(ci8source,cui8ndigitminimum);
			stWrite("\n");
			return;
		}
		static VOID				stWriteHexLine(CUINT8 cui8source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWriteHex(cui8source,cui8ndigitminimum);
			stWrite("\n");
			return;
		}
		static VOID				stWriteHexLine(CINT16 ci16source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWriteHex(ci16source,cui8ndigitminimum);
			stWrite("\n");
			return;
		}
		static VOID				stWriteHexLine(CUINT16 cui16source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWriteHex(cui16source,cui8ndigitminimum);
			stWrite("\n");
			return;
		}
		static VOID				stWriteHexLine(CINT32 ci32source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWriteHex(ci32source,cui8ndigitminimum);
			stWrite("\n");
			return;
		}
		static VOID				stWriteHexLine(CUINT32 cui32source,CUINT8 cui8ndigitminimum=0)noexcept{
			stWriteHex(cui32source,cui8ndigitminimum);
			stWrite("\n");
			return;
		}
		static VOID				stWriteHex(const PCUINT8 cpcui8source,CUINT16 cui16nsource)noexcept{
			for(UINT16 ui16isource=0;ui16isource<cui16nsource;stWrite("\n")){
				stWriteHex(ui16isource,4);
				stWrite(":");
				for(UINT8 ui8icolumn=0;(ui8icolumn<32)&&(ui16isource<cui16nsource);++ui8icolumn){
					if(0<ui8icolumn)stWrite(" ");
					stWriteHex(cpcui8source[ui16isource],2);
					++ui16isource;
				}
			}
			return;
		}
		static VOID				stWriteHex(const PCUINT16 cpcui16source,CUINT16 cui16nsource)noexcept{
			for(UINT16 ui16isource=0;ui16isource<cui16nsource;stWrite("\n")){
				stWriteHex(UINT16(ui16isource<<1),4);
				stWrite(":");
				for(UINT8 ui8icolumn=0;(ui8icolumn<16)&&(ui16isource<cui16nsource);++ui8icolumn){
					if(0<ui8icolumn)stWrite(" ");
					stWriteHex(cpcui16source[ui16isource],4);
					++ui16isource;
				}
			}
			return;
		}
		static VOID				stWriteHex(const PCUINT32 cpcui32source,CUINT16 cui16nsource)noexcept{
			for(UINT16 ui16isource=0;ui16isource<cui16nsource;stWrite("\n")){
				stWriteHex(UINT16(ui16isource<<2),4);
				stWrite(":");
				for(UINT8 ui8icolumn=0;(ui8icolumn<8)&&(ui16isource<cui16nsource);++ui8icolumn){
					if(0<ui8icolumn)stWrite(" ");
					stWriteHex(cpcui32source[ui16isource],8);
					++ui16isource;
				}
			}
			return;
		}
	protected:
		static _INLINE_ _UNDISCARDABLE_ USTR&	DEVICE_stustrDelegate(VOID)noexcept{
			return *PUSTR(stcui32iDataAddress);
		}
	private:
		static VOID				stWrite_Body(CUINT32 cui32source,CUINT8 cui8ndigitminimum,COFWBOOL ceminus)noexcept{
			stWrite_Body_Head(10,cui8ndigitminimum);
			stWrite_Body_Digit(cui32source,cui8ndigitminimum,ceminus,' ');
			return;
		}
		static VOID				stWrite_Body(CUINT16 cui16source,CUINT8 cui8ndigitminimum,COFWBOOL ceminus)noexcept{
			stWrite_Body_Head(5,cui8ndigitminimum);
			stWrite_Body_Digit(cui16source,cui8ndigitminimum,ceminus,' ');
			return;
		}
		static VOID				stWrite_Body_Head(CUINT8 cui8ndigit,CUINT8 cui8ndigitminimum)noexcept{
			for(AUTO ui8ndigit=cui8ndigitminimum;cui8ndigit<ui8ndigit;--ui8ndigit)DEVICE_stustrDelegate()=' ';
			return;
		}
		static VOID				stWrite_Body_Digit(CUINT32 cui32source,CUINT8 cui8ndigitminimum,COFWBOOL ceminus,CUSTR custrzero)noexcept{
			AUTO					ui32source=cui32source;
			AUTO					eminus=ceminus;
			AUTO					ustrzero=custrzero;

			for(AUTO ui8ndigit=UINT8(10);5<=ui8ndigit;--ui8ndigit){
				static constexpr UINT32	stacui32unit[]={
					       10'000,			//	 5
					      100'000,			//	 6
					    1'000'000,			//	 7
					   10'000'000,			//	 8
					  100'000'000,			//	 9
					1'000'000'000			//	10
				};
				CAUTO					cui32unit=stacui32unit[ui8ndigit-5];
				USTR					ustrnumber;

				for(ustrnumber='0';cui32unit<=ui32source;++ustrnumber)ui32source-=cui32unit;
				if('0'<ustrnumber){
					if(eminus){
						DEVICE_stustrDelegate()='-';
						eminus=FALSE;
					}
					DEVICE_stustrDelegate()=ustrnumber;
					ustrzero='0';
				}else if((ui8ndigit<=cui8ndigitminimum)||(ustrzero=='0')){
					DEVICE_stustrDelegate()=ustrzero;
				}
			}
			stWrite_Body_Digit(UINT16(ui32source),cui8ndigitminimum,eminus,ustrzero);
			return;
		}
		static VOID				stWrite_Body_Digit(CUINT16 cui16source,CUINT8 cui8ndigitminimum,COFWBOOL ceminus,CUSTR custrzero)noexcept{
			AUTO					ui16source=cui16source;
			AUTO					eminus=ceminus;
			USTR					ustrzero=custrzero;

			for(AUTO ui8ndigit=UINT8(5);2<=ui8ndigit;--ui8ndigit){
				static constexpr UINT16	stacui16unit[]={
					           10,			//	2
					          100,			//	3
					        1'000,			//	4
					       10'000			//	5
				};
				CAUTO					cui16unit=stacui16unit[ui8ndigit-2];
				USTR					ustrnumber;

				for(ustrnumber='0';cui16unit<=ui16source;++ustrnumber)ui16source-=cui16unit;
				if('0'<ustrnumber){
					if(eminus){
						DEVICE_stustrDelegate()='-';
						eminus=FALSE;
					}
					DEVICE_stustrDelegate()=ustrnumber;
					ustrzero='0';
				}else if((ui8ndigit<=cui8ndigitminimum)||(ustrzero=='0')){
					DEVICE_stustrDelegate()=ustrzero;
				}
			}
			if(eminus){
				DEVICE_stustrDelegate()='-';
				eminus=FALSE;
			}
			DEVICE_stustrDelegate()='0'+USTR(ui16source);
			return;
		}
		static VOID				stWriteHex_Body(CUINT32 cui32source,CUINT8 cui8ndigitminimum,CUSTR custrsign)noexcept{
			stWriteHex_Body_Head(8,cui8ndigitminimum,custrsign);
			stWriteHex_Body_Digit(cui32source,cui8ndigitminimum,FALSE);
			return;
		}
		static VOID				stWriteHex_Body(CUINT16 cui16source,CUINT8 cui8ndigitminimum,CUSTR custrsign)noexcept{
			stWriteHex_Body_Head(4,cui8ndigitminimum,custrsign);
			stWriteHex_Body_Digit(cui16source,cui8ndigitminimum,FALSE);
			return;
		}
		static VOID				stWriteHex_Body(CUINT8 cui8source,CUINT8 cui8ndigitminimum,CUSTR custrsign)noexcept{
			stWriteHex_Body_Head(2,cui8ndigitminimum,custrsign);
			stWriteHex_Body_Digit(cui8source,cui8ndigitminimum,FALSE);
			return;
		}
		static VOID				stWriteHex_Body_Head(CUINT8 cui8ndigit,CUINT8 cui8ndigitminimum,CUSTR custrsign)noexcept{
			for(AUTO ui8ndigit=cui8ndigitminimum;cui8ndigit<ui8ndigit;--ui8ndigit)DEVICE_stustrDelegate()=custrsign;
			return;
		}
		static VOID				stWriteHex_Body_Digit(CUINT32 cui32source,CUINT8 cui8ndigitminimum,COFWBOOL cezero)noexcept{
			AUTO					ezero=cezero;

			for(AUTO ui8ndigit=UINT8(8);5<=ui8ndigit;--ui8ndigit){
				CAUTO					cui8inumber=UINT8(UINT8(cui32source>>((ui8ndigit-1)<<2))&UINT8(0xf));

				if(cui8inumber){
					DEVICE_stustrDelegate()=stacustrHex[cui8inumber];
					ezero=TRUE;
				}else if((ui8ndigit<=cui8ndigitminimum)||ezero){
					DEVICE_stustrDelegate()='0';
				}
			}
			stWriteHex_Body_Digit(UINT16(cui32source),cui8ndigitminimum,ezero);
			return;
		}
		static VOID				stWriteHex_Body_Digit(CUINT16 cui16source,CUINT8 cui8ndigitminimum,COFWBOOL cezero)noexcept{
			AUTO					ezero=cezero;

			for(AUTO ui8ndigit=UINT8(4);3<=ui8ndigit;--ui8ndigit){
				CAUTO					cui8inumber=UINT8(UINT8(cui16source>>((ui8ndigit-1)<<2))&UINT8(0xf));

				if(cui8inumber){
					DEVICE_stustrDelegate()=stacustrHex[cui8inumber];
					ezero=TRUE;
				}else if((ui8ndigit<=cui8ndigitminimum)||ezero){
					DEVICE_stustrDelegate()='0';
				}
			}
			stWriteHex_Body_Digit(UINT8(cui16source),cui8ndigitminimum,ezero);
			return;
		}
		static VOID				stWriteHex_Body_Digit(CUINT8 cui8source,CUINT8 cui8ndigitminimum,COFWBOOL cezero)noexcept{
			AUTO					ezero=cezero;

			{
				constexpr AUTO			cui8ndigit=UINT8(2);
				CAUTO					cui8inumber=UINT8(UINT8(cui8source>>((cui8ndigit-1)<<2))&UINT8(0xf));

				if(cui8inumber){
					DEVICE_stustrDelegate()=stacustrHex[cui8inumber];
					ezero=TRUE;
				}else if((cui8ndigit<=cui8ndigitminimum)||ezero){
					DEVICE_stustrDelegate()='0';
				}
			}
			DEVICE_stustrDelegate()=stacustrHex[cui8source&0xf];
			return;
		}
	};
}

#endif
