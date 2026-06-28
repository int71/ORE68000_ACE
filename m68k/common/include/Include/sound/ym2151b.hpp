/****************************************************************************
**																			**
**																			**
**									m68k									**
**																			**
**	'm68k/sound/ym2151b.hpp'						2026 written by int71	**
 ****************************************************************************/
#ifndef M68K_SOUND_YM2151B
#define M68K_SOUND_YM2151B

//
//		include
//

#include				"../base.hpp"

//
//		namespace:m68k::sound
//

namespace m68k::sound{

	//
	//		class
	//

	class YM2151B;

	//
	//		class:YM2151B
	//

	class YM2151B{
	public:

		//
		//		const
		//

		//	FM_IDREGISTERW
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R番|名称                           |7  |6  |5  |4  |3  |2  |1  |0  |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R00|                               |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R01|LFOReset1                      |***********************|RST|***|RST/0:LFO位相リセット 1:LFO停止                                                    |
		//		|   |                               |                       |   |   |※LFOはFM/PCM共用                                                                  |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R02|LFOFrequency                   |累乗           |基本周波数     |「16+基本周波数*2^累乗」が周波数係数                                               |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R03|LFODepth7                      |種 |振幅                       |種/0:設定対象AMD 1:設定対象PMD                                                     |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R04|                               |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R05|LFOShape2                      |***********************|波形   |波形/0:ノコギリ 1:矩形 2:三角 4:ノイズ                                             |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R06|                               |                               |                                                                                   |
		//		|R07|                               |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R08|Key                            |DN |C2 |C1 |M2 |M1 |チャンネル |M1～C2/0:KeyOff 1:KeyOn DN(DeNoise)/0:無効果 1:連続KeyOnノイズ除去有効             |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R09|                               |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R0A|ClockAH                        |*******************************|                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R0B|ClockAL2                       |*******************************|                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R0C|ClockB                         |*******************************|                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R0D|                               |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R0E|Timer                          |*******************************|                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R0F|NoiseDivRatio5                 |EN |*******|ノイズ分周         |EN/0:FM#7ノイズOFF 1:FM#7ノイズON                                                  |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R10|Ch0StereoLevelL7               |***|Lチャンネル音量            |Lチャンネル音量/0:最大 127:最小                                                    |
		//		|R11|Ch1StereoLevelL7               |   |                           |※「ChnStereoLevelR7」の値と共に音源に反映                                         |
		//		|R12|Ch2StereoLevelL7               |   |                           |                                                                                   |
		//		|R13|Ch3StereoLevelL7               |   |                           |                                                                                   |
		//		|R14|Ch4StereoLevelL7               |   |                           |                                                                                   |
		//		|R15|Ch5StereoLevelL7               |   |                           |                                                                                   |
		//		|R16|Ch6StereoLevelL7               |   |                           |                                                                                   |
		//		|R17|Ch7StereoLevelL7               |   |                           |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R18|Ch0StereoLevelR7               |***|Rチャンネル音量            |Rチャンネル音量/0:最大 127:最小                                                    |
		//		|R19|Ch1StereoLevelR7               |   |                           |※即時反映でなく「ChnStereoLevelL7」書き込み時に反映                               |
		//		|R1A|Ch2StereoLevelR7               |   |                           |                                                                                   |
		//		|R1B|Ch3StereoLevelR7               |   |                           |                                                                                   |
		//		|R1C|Ch4StereoLevelR7               |   |                           |                                                                                   |
		//		|R1D|Ch5StereoLevelR7               |   |                           |                                                                                   |
		//		|R1E|Ch6StereoLevelR7               |   |                           |                                                                                   |
		//		|R1F|Ch7StereoLevelR7               |   |                           |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R20|Ch0Feedback3Connect3           |*******|FeedBack   |Connect    |                                                                                   |
		//		|R21|Ch1Feedback3Connect3           |       |           |           |                                                                                   |
		//		|R22|Ch2Feedback3Connect3           |       |           |           |                                                                                   |
		//		|R23|Ch3Feedback3Connect3           |       |           |           |                                                                                   |
		//		|R24|Ch4Feedback3Connect3           |       |           |           |                                                                                   |
		//		|R25|Ch5Feedback3Connect3           |       |           |           |                                                                                   |
		//		|R26|Ch6Feedback3Connect3           |       |           |           |                                                                                   |
		//		|R27|Ch7Feedback3Connect3           |       |           |           |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R28|Ch0Note7                       |***|オクターブ |ノートIndex    |ノートIndex/0:C# 1:D 2～3:D# 4:E 5:F 6～7:F# 8:G 9:G# 10～11:A 12:A# 13:B 14～15:C |
		//		|R29|Ch1Note7                       |   |           |               |オクターブ/0～7                                                                    |
		//		|R2A|Ch2Note7                       |   |           |               |周波数=440*2^(オクターブ-4+(ノート番号-8(A))/12)                                   |
		//		|R2B|Ch3Note7                       |   |           |               |                                                                                   |
		//		|R2C|Ch4Note7                       |   |           |               |                                                                                   |
		//		|R2D|Ch5Note7                       |   |           |               |                                                                                   |
		//		|R2E|Ch6Note7                       |   |           |               |                                                                                   |
		//		|R2F|Ch7Note7                       |   |           |               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R30|Ch0NoteFine6                   |音程微調整             |*******|音程微調整/0:補正「+0」 63:補正「+半音*63/64」                                     |
		//		|R31|Ch1NoteFine6                   |                       |       |                                                                                   |
		//		|R32|Ch2NoteFine6                   |                       |       |                                                                                   |
		//		|R33|Ch3NoteFine6                   |                       |       |                                                                                   |
		//		|R34|Ch4NoteFine6                   |                       |       |                                                                                   |
		//		|R35|Ch5NoteFine6                   |                       |       |                                                                                   |
		//		|R36|Ch6NoteFine6                   |                       |       |                                                                                   |
		//		|R37|Ch7NoteFine6                   |                       |       |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R38|Ch0PMS3AMS2                    |***|PMS        |*******|AMS    |                                                                                   |
		//		|R39|Ch1PMS3AMS2                    |   |           |       |       |                                                                                   |
		//		|R3A|Ch2PMS3AMS2                    |   |           |       |       |                                                                                   |
		//		|R3B|Ch3PMS3AMS2                    |   |           |       |       |                                                                                   |
		//		|R3C|Ch4PMS3AMS2                    |   |           |       |       |                                                                                   |
		//		|R3D|Ch5PMS3AMS2                    |   |           |       |       |                                                                                   |
		//		|R3E|Ch6PMS3AMS2                    |   |           |       |       |                                                                                   |
		//		|R3F|Ch7PMS3AMS2                    |   |           |       |       |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R40|Ch0M1DetuneFine3Multiply4      |***|DetuneFine |Multiply       |Multiply/0:周波数*0.5 1～15:周波数*n                                               |
		//		|R41|Ch1M1DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R42|Ch2M1DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R43|Ch3M1DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R44|Ch4M1DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R45|Ch5M1DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R46|Ch6M1DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R47|Ch7M1DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R48|Ch0M2DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R49|Ch1M2DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R4A|Ch2M2DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R4B|Ch3M2DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R4C|Ch4M2DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R4D|Ch5M2DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R4E|Ch6M2DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R4F|Ch7M2DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R50|Ch0C1DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R51|Ch1C1DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R52|Ch2C1DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R53|Ch3C1DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R54|Ch4C1DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R55|Ch5C1DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R56|Ch6C1DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R57|Ch7C1DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R58|Ch0C2DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R59|Ch1C2DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R5A|Ch2C2DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R5B|Ch3C2DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R5C|Ch4C2DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R5D|Ch5C2DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R5E|Ch6C2DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		|R5F|Ch7C2DetuneFine3Multiply4      |   |           |               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R60|Ch0M1TotalLevel7               |***|オペレータ音量             |オペレータ音量/0:最大 127:最小                                                     |
		//		|R61|Ch1M1TotalLevel7               |   |                           |                                                                                   |
		//		|R62|Ch2M1TotalLevel7               |   |                           |                                                                                   |
		//		|R63|Ch3M1TotalLevel7               |   |                           |                                                                                   |
		//		|R64|Ch4M1TotalLevel7               |   |                           |                                                                                   |
		//		|R65|Ch5M1TotalLevel7               |   |                           |                                                                                   |
		//		|R66|Ch6M1TotalLevel7               |   |                           |                                                                                   |
		//		|R67|Ch7M1TotalLevel7               |   |                           |                                                                                   |
		//		|R68|Ch0M2TotalLevel7               |   |                           |                                                                                   |
		//		|R69|Ch1M2TotalLevel7               |   |                           |                                                                                   |
		//		|R6A|Ch2M2TotalLevel7               |   |                           |                                                                                   |
		//		|R6B|Ch3M2TotalLevel7               |   |                           |                                                                                   |
		//		|R6C|Ch4M2TotalLevel7               |   |                           |                                                                                   |
		//		|R6D|Ch5M2TotalLevel7               |   |                           |                                                                                   |
		//		|R6E|Ch6M2TotalLevel7               |   |                           |                                                                                   |
		//		|R6F|Ch7M2TotalLevel7               |   |                           |                                                                                   |
		//		|R70|Ch0C1TotalLevel7               |   |                           |                                                                                   |
		//		|R71|Ch1C1TotalLevel7               |   |                           |                                                                                   |
		//		|R72|Ch2C1TotalLevel7               |   |                           |                                                                                   |
		//		|R73|Ch3C1TotalLevel7               |   |                           |                                                                                   |
		//		|R74|Ch4C1TotalLevel7               |   |                           |                                                                                   |
		//		|R75|Ch5C1TotalLevel7               |   |                           |                                                                                   |
		//		|R76|Ch6C1TotalLevel7               |   |                           |                                                                                   |
		//		|R77|Ch7C1TotalLevel7               |   |                           |                                                                                   |
		//		|R78|Ch0C2TotalLevel7               |   |                           |                                                                                   |
		//		|R79|Ch1C2TotalLevel7               |   |                           |                                                                                   |
		//		|R7A|Ch2C2TotalLevel7               |   |                           |                                                                                   |
		//		|R7B|Ch3C2TotalLevel7               |   |                           |                                                                                   |
		//		|R7C|Ch4C2TotalLevel7               |   |                           |                                                                                   |
		//		|R7D|Ch5C2TotalLevel7               |   |                           |                                                                                   |
		//		|R7E|Ch6C2TotalLevel7               |   |                           |                                                                                   |
		//		|R7F|Ch7C2TotalLevel7               |   |                           |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R80|Ch0M1KeyScale2AttackRate5      |KS     |***|AttackRate         |AttackRate/0～1:即KeyOff 2:最遅 31:最速                                            |
		//		|R81|Ch1M1KeyScale2AttackRate5      |       |   |                   |※即時反映でなく「Key」書き込みによるKeyOn時に反映                                 |
		//		|R82|Ch2M1KeyScale2AttackRate5      |       |   |                   |KS(KeyScale)/0:効果最弱 3:効果最強                                                 |
		//		|R83|Ch3M1KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R84|Ch4M1KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R85|Ch5M1KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R86|Ch6M1KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R87|Ch7M1KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R88|Ch0M2KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R89|Ch1M2KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R8A|Ch2M2KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R8B|Ch3M2KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R8C|Ch4M2KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R8D|Ch5M2KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R8E|Ch6M2KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R8F|Ch7M2KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R90|Ch0C1KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R91|Ch1C1KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R92|Ch2C1KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R93|Ch3C1KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R94|Ch4C1KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R95|Ch5C1KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R96|Ch6C1KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R97|Ch7C1KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R98|Ch0C2KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R99|Ch1C2KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R9A|Ch2C2KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R9B|Ch3C2KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R9C|Ch4C2KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R9D|Ch5C2KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R9E|Ch6C2KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		|R9F|Ch7C2KeyScale2AttackRate5      |       |   |                   |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|RA0|Ch0M1AME1Decay1Rate5           |AME|*******|Decay1Rate         |Decay1Rate/0:最遅 31:最速                                                          |
		//		|RA1|Ch1M1AME1Decay1Rate5           |   |       |                   |※即時反映でなく「Key」書き込みによるKeyOn時に反映                                 |
		//		|RA2|Ch2M1AME1Decay1Rate5           |   |       |                   |AME/0:振幅LFO無効 1:振幅LFO有効                                                    |
		//		|RA3|Ch3M1AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RA4|Ch4M1AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RA5|Ch5M1AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RA6|Ch6M1AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RA7|Ch7M1AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RA8|Ch0M2AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RA9|Ch1M2AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RAA|Ch2M2AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RAB|Ch3M2AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RAC|Ch4M2AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RAD|Ch5M2AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RAE|Ch6M2AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RAF|Ch7M2AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RB0|Ch0C1AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RB1|Ch1C1AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RB2|Ch2C1AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RB3|Ch3C1AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RB4|Ch4C1AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RB5|Ch5C1AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RB6|Ch6C1AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RB7|Ch7C1AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RB8|Ch0C2AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RB9|Ch1C2AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RBA|Ch2C2AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RBB|Ch3C2AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RBC|Ch4C2AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RBD|Ch5C2AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RBE|Ch6C2AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RBF|Ch7C2AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|RC0|Ch0M1DetuneRough2Decay2Rate5   |Det.R. |***|Decay2Rate         |Decay2Rate/0:最遅 31:最速                                                          |
		//		|RC1|Ch1M1DetuneRough2Decay2Rate5   |       |   |                   |※即時反映でなく「Key」書き込みによるKeyOn時に反映                                 |
		//		|RC2|Ch2M1DetuneRough2Decay2Rate5   |       |   |                   |Det.R.(DetuneRough)/0:効果最弱 3:効果最強                                          |
		//		|RC3|Ch3M1DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RC4|Ch4M1DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RC5|Ch5M1DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RC6|Ch6M1DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RC7|Ch7M1DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RC8|Ch0M2DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RC9|Ch1M2DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RCA|Ch2M2DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RCB|Ch3M2DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RCC|Ch4M2DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RCD|Ch5M2DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RCE|Ch6M2DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RCF|Ch7M2DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RD0|Ch0C1DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RD1|Ch1C1DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RD2|Ch2C1DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RD3|Ch3C1DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RD4|Ch4C1DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RD5|Ch5C1DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RD6|Ch6C1DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RD7|Ch7C1DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RD8|Ch0C2DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RD9|Ch1C2DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RDA|Ch2C2DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RDB|Ch3C2DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RDC|Ch4C2DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RDD|Ch5C2DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RDE|Ch6C2DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RDF|Ch7C2DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|RE0|Ch0M1DecayLevel4ReleaseRate4   |DecayLevel     |ReleaseRate    |ReleaseRate/0:最遅 15:最速                                                         |
		//		|RE1|Ch1M1DecayLevel4ReleaseRate4   |               |               |DecayLevel/0:下降幅最小 15:下降幅最大                                              |
		//		|RE2|Ch2M1DecayLevel4ReleaseRate4   |               |               |※上記いづれも即時反映でなく「Key」書き込みによるKeyOn時に反映                     |
		//		|RE3|Ch3M1DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RE4|Ch4M1DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RE5|Ch5M1DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RE6|Ch6M1DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RE7|Ch7M1DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RE8|Ch0M2DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RE9|Ch1M2DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|REA|Ch2M2DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|REB|Ch3M2DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|REC|Ch4M2DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RED|Ch5M2DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|REE|Ch6M2DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|REF|Ch7M2DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RF0|Ch0C1DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RF1|Ch1C1DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RF2|Ch2C1DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RF3|Ch3C1DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RF4|Ch4C1DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RF5|Ch5C1DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RF6|Ch6C1DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RF7|Ch7C1DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RF8|Ch0C2DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RF9|Ch1C2DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RFA|Ch2C2DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RFB|Ch3C2DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RFC|Ch4C2DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RFD|Ch5C2DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RFE|Ch6C2DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RFF|Ch7C2DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		class _FM_IDREGISTERW{
		public:
			enum BODY:UINT8{
				_00=					0x00,
				LFOReset1=				0x01,
				LFOFrequency=			0x02,
				LFODepth7=				0x03,
				_04=					0x04,
				LFOShape2=				0x05,
				_06=					0x06,
				_07=					0x07,
				Key=					0x08,
				_09=					0x09,
				ClockAH=				0x0a,
				ClockAL2=				0x0b,
				ClockB=					0x0c,
				_0D=					0x0d,
				Timer=					0x0e,
				NoiseDivRatio5=			0x0f,
				Ch0StereoLevelL7=		0x10,
				Ch1StereoLevelL7=		0x11,
				Ch2StereoLevelL7=		0x12,
				Ch3StereoLevelL7=		0x13,
				Ch4StereoLevelL7=		0x14,
				Ch5StereoLevelL7=		0x15,
				Ch6StereoLevelL7=		0x16,
				Ch7StereoLevelL7=		0x17,
				Ch0StereoLevelR7=		0x18,
				Ch1StereoLevelR7=		0x19,
				Ch2StereoLevelR7=		0x1a,
				Ch3StereoLevelR7=		0x1b,
				Ch4StereoLevelR7=		0x1c,
				Ch5StereoLevelR7=		0x1d,
				Ch6StereoLevelR7=		0x1e,
				Ch7StereoLevelR7=		0x1f,
				Ch0Feedback3Connect3=	0x20,
				Ch1Feedback3Connect3=	0x21,
				Ch2Feedback3Connect3=	0x22,
				Ch3Feedback3Connect3=	0x23,
				Ch4Feedback3Connect3=	0x24,
				Ch5Feedback3Connect3=	0x25,
				Ch6Feedback3Connect3=	0x26,
				Ch7Feedback3Connect3=	0x27,
				Ch0Note7=				0x28,
				Ch1Note7=				0x29,
				Ch2Note7=				0x2a,
				Ch3Note7=				0x2b,
				Ch4Note7=				0x2c,
				Ch5Note7=				0x2d,
				Ch6Note7=				0x2e,
				Ch7Note7=				0x2f,
				Ch0NoteFine6=			0x30,
				Ch1NoteFine6=			0x31,
				Ch2NoteFine6=			0x32,
				Ch3NoteFine6=			0x33,
				Ch4NoteFine6=			0x34,
				Ch5NoteFine6=			0x35,
				Ch6NoteFine6=			0x36,
				Ch7NoteFine6=			0x37,
				Ch0PMS3AMS2=			0x38,
				Ch1PMS3AMS2=			0x39,
				Ch2PMS3AMS2=			0x3a,
				Ch3PMS3AMS2=			0x3b,
				Ch4PMS3AMS2=			0x3c,
				Ch5PMS3AMS2=			0x3d,
				Ch6PMS3AMS2=			0x3e,
				Ch7PMS3AMS2=			0x3f,
				Ch0M1DetuneFine3Multiply4=	0x40,
				Ch1M1DetuneFine3Multiply4=	0x41,
				Ch2M1DetuneFine3Multiply4=	0x42,
				Ch3M1DetuneFine3Multiply4=	0x43,
				Ch4M1DetuneFine3Multiply4=	0x44,
				Ch5M1DetuneFine3Multiply4=	0x45,
				Ch6M1DetuneFine3Multiply4=	0x46,
				Ch7M1DetuneFine3Multiply4=	0x47,
				Ch0M2DetuneFine3Multiply4=	0x48,
				Ch1M2DetuneFine3Multiply4=	0x49,
				Ch2M2DetuneFine3Multiply4=	0x4a,
				Ch3M2DetuneFine3Multiply4=	0x4b,
				Ch4M2DetuneFine3Multiply4=	0x4c,
				Ch5M2DetuneFine3Multiply4=	0x4d,
				Ch6M2DetuneFine3Multiply4=	0x4e,
				Ch7M2DetuneFine3Multiply4=	0x4f,
				Ch0C1DetuneFine3Multiply4=	0x50,
				Ch1C1DetuneFine3Multiply4=	0x51,
				Ch2C1DetuneFine3Multiply4=	0x52,
				Ch3C1DetuneFine3Multiply4=	0x53,
				Ch4C1DetuneFine3Multiply4=	0x54,
				Ch5C1DetuneFine3Multiply4=	0x55,
				Ch6C1DetuneFine3Multiply4=	0x56,
				Ch7C1DetuneFine3Multiply4=	0x57,
				Ch0C2DetuneFine3Multiply4=	0x58,
				Ch1C2DetuneFine3Multiply4=	0x59,
				Ch2C2DetuneFine3Multiply4=	0x5a,
				Ch3C2DetuneFine3Multiply4=	0x5b,
				Ch4C2DetuneFine3Multiply4=	0x5c,
				Ch5C2DetuneFine3Multiply4=	0x5d,
				Ch6C2DetuneFine3Multiply4=	0x5e,
				Ch7C2DetuneFine3Multiply4=	0x5f,
				Ch0M1TotalLevel7=		0x60,
				Ch1M1TotalLevel7=		0x61,
				Ch2M1TotalLevel7=		0x62,
				Ch3M1TotalLevel7=		0x63,
				Ch4M1TotalLevel7=		0x64,
				Ch5M1TotalLevel7=		0x65,
				Ch6M1TotalLevel7=		0x66,
				Ch7M1TotalLevel7=		0x67,
				Ch0M2TotalLevel7=		0x68,
				Ch1M2TotalLevel7=		0x69,
				Ch2M2TotalLevel7=		0x6a,
				Ch3M2TotalLevel7=		0x6b,
				Ch4M2TotalLevel7=		0x6c,
				Ch5M2TotalLevel7=		0x6d,
				Ch6M2TotalLevel7=		0x6e,
				Ch7M2TotalLevel7=		0x6f,
				Ch0C1TotalLevel7=		0x70,
				Ch1C1TotalLevel7=		0x71,
				Ch2C1TotalLevel7=		0x72,
				Ch3C1TotalLevel7=		0x73,
				Ch4C1TotalLevel7=		0x74,
				Ch5C1TotalLevel7=		0x75,
				Ch6C1TotalLevel7=		0x76,
				Ch7C1TotalLevel7=		0x77,
				Ch0C2TotalLevel7=		0x78,
				Ch1C2TotalLevel7=		0x79,
				Ch2C2TotalLevel7=		0x7a,
				Ch3C2TotalLevel7=		0x7b,
				Ch4C2TotalLevel7=		0x7c,
				Ch5C2TotalLevel7=		0x7d,
				Ch6C2TotalLevel7=		0x7e,
				Ch7C2TotalLevel7=		0x7f,
				Ch0M1KeyScale2AttackRate5=	0x80,
				Ch1M1KeyScale2AttackRate5=	0x81,
				Ch2M1KeyScale2AttackRate5=	0x82,
				Ch3M1KeyScale2AttackRate5=	0x83,
				Ch4M1KeyScale2AttackRate5=	0x84,
				Ch5M1KeyScale2AttackRate5=	0x85,
				Ch6M1KeyScale2AttackRate5=	0x86,
				Ch7M1KeyScale2AttackRate5=	0x87,
				Ch0M2KeyScale2AttackRate5=	0x88,
				Ch1M2KeyScale2AttackRate5=	0x89,
				Ch2M2KeyScale2AttackRate5=	0x8a,
				Ch3M2KeyScale2AttackRate5=	0x8b,
				Ch4M2KeyScale2AttackRate5=	0x8c,
				Ch5M2KeyScale2AttackRate5=	0x8d,
				Ch6M2KeyScale2AttackRate5=	0x8e,
				Ch7M2KeyScale2AttackRate5=	0x8f,
				Ch0C1KeyScale2AttackRate5=	0x90,
				Ch1C1KeyScale2AttackRate5=	0x91,
				Ch2C1KeyScale2AttackRate5=	0x92,
				Ch3C1KeyScale2AttackRate5=	0x93,
				Ch4C1KeyScale2AttackRate5=	0x94,
				Ch5C1KeyScale2AttackRate5=	0x95,
				Ch6C1KeyScale2AttackRate5=	0x96,
				Ch7C1KeyScale2AttackRate5=	0x97,
				Ch0C2KeyScale2AttackRate5=	0x98,
				Ch1C2KeyScale2AttackRate5=	0x99,
				Ch2C2KeyScale2AttackRate5=	0x9a,
				Ch3C2KeyScale2AttackRate5=	0x9b,
				Ch4C2KeyScale2AttackRate5=	0x9c,
				Ch5C2KeyScale2AttackRate5=	0x9d,
				Ch6C2KeyScale2AttackRate5=	0x9e,
				Ch7C2KeyScale2AttackRate5=	0x9f,
				Ch0M1AME1Decay1Rate5=	0xa0,
				Ch1M1AME1Decay1Rate5=	0xa1,
				Ch2M1AME1Decay1Rate5=	0xa2,
				Ch3M1AME1Decay1Rate5=	0xa3,
				Ch4M1AME1Decay1Rate5=	0xa4,
				Ch5M1AME1Decay1Rate5=	0xa5,
				Ch6M1AME1Decay1Rate5=	0xa6,
				Ch7M1AME1Decay1Rate5=	0xa7,
				Ch0M2AME1Decay1Rate5=	0xa8,
				Ch1M2AME1Decay1Rate5=	0xa9,
				Ch2M2AME1Decay1Rate5=	0xaa,
				Ch3M2AME1Decay1Rate5=	0xab,
				Ch4M2AME1Decay1Rate5=	0xac,
				Ch5M2AME1Decay1Rate5=	0xad,
				Ch6M2AME1Decay1Rate5=	0xae,
				Ch7M2AME1Decay1Rate5=	0xaf,
				Ch0C1AME1Decay1Rate5=	0xb0,
				Ch1C1AME1Decay1Rate5=	0xb1,
				Ch2C1AME1Decay1Rate5=	0xb2,
				Ch3C1AME1Decay1Rate5=	0xb3,
				Ch4C1AME1Decay1Rate5=	0xb4,
				Ch5C1AME1Decay1Rate5=	0xb5,
				Ch6C1AME1Decay1Rate5=	0xb6,
				Ch7C1AME1Decay1Rate5=	0xb7,
				Ch0C2AME1Decay1Rate5=	0xb8,
				Ch1C2AME1Decay1Rate5=	0xb9,
				Ch2C2AME1Decay1Rate5=	0xba,
				Ch3C2AME1Decay1Rate5=	0xbb,
				Ch4C2AME1Decay1Rate5=	0xbc,
				Ch5C2AME1Decay1Rate5=	0xbd,
				Ch6C2AME1Decay1Rate5=	0xbe,
				Ch7C2AME1Decay1Rate5=	0xbf,
				Ch0M1DetuneRough2Decay2Rate5=	0xc0,
				Ch1M1DetuneRough2Decay2Rate5=	0xc1,
				Ch2M1DetuneRough2Decay2Rate5=	0xc2,
				Ch3M1DetuneRough2Decay2Rate5=	0xc3,
				Ch4M1DetuneRough2Decay2Rate5=	0xc4,
				Ch5M1DetuneRough2Decay2Rate5=	0xc5,
				Ch6M1DetuneRough2Decay2Rate5=	0xc6,
				Ch7M1DetuneRough2Decay2Rate5=	0xc7,
				Ch0M2DetuneRough2Decay2Rate5=	0xc8,
				Ch1M2DetuneRough2Decay2Rate5=	0xc9,
				Ch2M2DetuneRough2Decay2Rate5=	0xca,
				Ch3M2DetuneRough2Decay2Rate5=	0xcb,
				Ch4M2DetuneRough2Decay2Rate5=	0xcc,
				Ch5M2DetuneRough2Decay2Rate5=	0xcd,
				Ch6M2DetuneRough2Decay2Rate5=	0xce,
				Ch7M2DetuneRough2Decay2Rate5=	0xcf,
				Ch0C1DetuneRough2Decay2Rate5=	0xd0,
				Ch1C1DetuneRough2Decay2Rate5=	0xd1,
				Ch2C1DetuneRough2Decay2Rate5=	0xd2,
				Ch3C1DetuneRough2Decay2Rate5=	0xd3,
				Ch4C1DetuneRough2Decay2Rate5=	0xd4,
				Ch5C1DetuneRough2Decay2Rate5=	0xd5,
				Ch6C1DetuneRough2Decay2Rate5=	0xd6,
				Ch7C1DetuneRough2Decay2Rate5=	0xd7,
				Ch0C2DetuneRough2Decay2Rate5=	0xd8,
				Ch1C2DetuneRough2Decay2Rate5=	0xd9,
				Ch2C2DetuneRough2Decay2Rate5=	0xda,
				Ch3C2DetuneRough2Decay2Rate5=	0xdb,
				Ch4C2DetuneRough2Decay2Rate5=	0xdc,
				Ch5C2DetuneRough2Decay2Rate5=	0xdd,
				Ch6C2DetuneRough2Decay2Rate5=	0xde,
				Ch7C2DetuneRough2Decay2Rate5=	0xdf,
				Ch0M1DecayLevel4ReleaseRate4=	0xe0,
				Ch1M1DecayLevel4ReleaseRate4=	0xe1,
				Ch2M1DecayLevel4ReleaseRate4=	0xe2,
				Ch3M1DecayLevel4ReleaseRate4=	0xe3,
				Ch4M1DecayLevel4ReleaseRate4=	0xe4,
				Ch5M1DecayLevel4ReleaseRate4=	0xe5,
				Ch6M1DecayLevel4ReleaseRate4=	0xe6,
				Ch7M1DecayLevel4ReleaseRate4=	0xe7,
				Ch0M2DecayLevel4ReleaseRate4=	0xe8,
				Ch1M2DecayLevel4ReleaseRate4=	0xe9,
				Ch2M2DecayLevel4ReleaseRate4=	0xea,
				Ch3M2DecayLevel4ReleaseRate4=	0xeb,
				Ch4M2DecayLevel4ReleaseRate4=	0xec,
				Ch5M2DecayLevel4ReleaseRate4=	0xed,
				Ch6M2DecayLevel4ReleaseRate4=	0xee,
				Ch7M2DecayLevel4ReleaseRate4=	0xef,
				Ch0C1DecayLevel4ReleaseRate4=	0xf0,
				Ch1C1DecayLevel4ReleaseRate4=	0xf1,
				Ch2C1DecayLevel4ReleaseRate4=	0xf2,
				Ch3C1DecayLevel4ReleaseRate4=	0xf3,
				Ch4C1DecayLevel4ReleaseRate4=	0xf4,
				Ch5C1DecayLevel4ReleaseRate4=	0xf5,
				Ch6C1DecayLevel4ReleaseRate4=	0xf6,
				Ch7C1DecayLevel4ReleaseRate4=	0xf7,
				Ch0C2DecayLevel4ReleaseRate4=	0xf8,
				Ch1C2DecayLevel4ReleaseRate4=	0xf9,
				Ch2C2DecayLevel4ReleaseRate4=	0xfa,
				Ch3C2DecayLevel4ReleaseRate4=	0xfb,
				Ch4C2DecayLevel4ReleaseRate4=	0xfc,
				Ch5C2DecayLevel4ReleaseRate4=	0xfd,
				Ch6C2DecayLevel4ReleaseRate4=	0xfe,
				Ch7C2DecayLevel4ReleaseRate4=	0xff
			};
		};
		using					FM_IDREGISTERW=_FM_IDREGISTERW::BODY;
		class _FM_IDOPERATOR{
		public:
			enum BODY:UINT8{
				M1=0,
				M2=1,
				C1=2,
				C2=3
			};
		};
		using					FM_IDOPERATOR=_FM_IDOPERATOR::BODY;
		static constexpr UINT8	FM_stcui8nChannel=		8;
		static constexpr UINT8	FM_stcui8nOperator=		4;
		//	PCM_IDREGISTERW
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R番|名称                           |7  |6  |5  |4  |3  |2  |1  |0  |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R00|                               |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R01|LFOReset1                      |***********************|RST|***|RST/0:LFO位相リセット 1:LFO停止                                                    |
		//		|   |                               |                       |   |   |※LFOはFM/PCM共用                                                                  |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R02|LFOFrequency                   |累乗           |基本周波数     |「16+基本周波数*2^累乗」が周波数係数                                               |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R03|LFODepth7                      |種 |振幅                       |種/0:設定対象AMD 1:設定対象PMD                                                     |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R04|                               |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R05|LFOShape2                      |***********************|波形   |波形/0:ノコギリ 1:矩形 2:三角 4:ノイズ                                             |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R06|                               |                               |                                                                                   |
		//		|R07|                               |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R08|Key                            |DN |DNP|*******|E  |チャンネル |E/0:KeyOff 1:KeyOn DNP(DeNoisePhaseKeep)/0:無効果 1:連続KeyOn位相維持              |
		//		|   |                               |   |   |       |   |           |DN(DeNoise)/0:無効果 1:連続KeyOnノイズ除去有効                                     |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R09|                               |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R0A|ClockAH                        |*******************************|                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R0B|ClockAL2                       |*******************************|                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R0C|ClockB                         |*******************************|                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R0D|                               |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R0E|Timer                          |*******************************|                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R0F|NoiseDivRatio5                 |EN |*******|ノイズ分周         |EN/0:FM#7ノイズOFF 1:FM#7ノイズON                                                  |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R10|Ch0StereoLevelL7               |***|Lチャンネル音量            |Lチャンネル音量/0:最大 127:最小                                                    |
		//		|R11|Ch1StereoLevelL7               |   |                           |※「ChnStereoLevelR7」の値と共に音源に反映                                         |
		//		|R12|Ch2StereoLevelL7               |   |                           |                                                                                   |
		//		|R13|Ch3StereoLevelL7               |   |                           |                                                                                   |
		//		|R14|Ch4StereoLevelL7               |   |                           |                                                                                   |
		//		|R15|Ch5StereoLevelL7               |   |                           |                                                                                   |
		//		|R16|Ch6StereoLevelL7               |   |                           |                                                                                   |
		//		|R17|Ch7StereoLevelL7               |   |                           |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R18|Ch0StereoLevelR7               |***|Rチャンネル音量            |Rチャンネル音量/0:最大 127:最小                                                    |
		//		|R19|Ch1StereoLevelR7               |   |                           |※即時反映でなく「ChnStereoLevelL7」書き込み時に反映                               |
		//		|R1A|Ch2StereoLevelR7               |   |                           |                                                                                   |
		//		|R1B|Ch3StereoLevelR7               |   |                           |                                                                                   |
		//		|R1C|Ch4StereoLevelR7               |   |                           |                                                                                   |
		//		|R1D|Ch5StereoLevelR7               |   |                           |                                                                                   |
		//		|R1E|Ch6StereoLevelR7               |   |                           |                                                                                   |
		//		|R1F|Ch7StereoLevelR7               |   |                           |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R20|Ch0Interpolation2Deceleration4 |*******|補間   |Deceleration   |Deceleration/0～15:再生「2^(-n)」倍速 補間(サンプリング補間)/0:無し 1:線形         |
		//		|R21|Ch1Interpolation2Deceleration4 |       |       |               |                                                                                   |
		//		|R22|Ch2Interpolation2Deceleration4 |       |       |               |                                                                                   |
		//		|R23|Ch3Interpolation2Deceleration4 |       |       |               |                                                                                   |
		//		|R24|Ch4Interpolation2Deceleration4 |       |       |               |                                                                                   |
		//		|R25|Ch5Interpolation2Deceleration4 |       |       |               |                                                                                   |
		//		|R26|Ch6Interpolation2Deceleration4 |       |       |               |                                                                                   |
		//		|R27|Ch7Interpolation2Deceleration4 |       |       |               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R28|Ch0Note7                       |***|オクターブ |ノートIndex    |ノートIndex/0:C# 1:D 2～3:D# 4:E 5:F 6～7:F# 8:G 9:G# 10～11:A 12:A# 13:B 14～15:C |
		//		|R29|Ch1Note7                       |   |           |               |オクターブ/0～7                                                                    |
		//		|R2A|Ch2Note7                       |   |           |               |周波数=440*2^(オクターブ-4+(ノート番号-8(A))/12)                                   |
		//		|R2B|Ch3Note7                       |   |           |               |                                                                                   |
		//		|R2C|Ch4Note7                       |   |           |               |                                                                                   |
		//		|R2D|Ch5Note7                       |   |           |               |                                                                                   |
		//		|R2E|Ch6Note7                       |   |           |               |                                                                                   |
		//		|R2F|Ch7Note7                       |   |           |               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R30|Ch0NoteFine6                   |音程微調整             |*******|音程微調整/0:補正「+0」 63:補正「+半音*63/64」                                     |
		//		|R31|Ch1NoteFine6                   |                       |       |                                                                                   |
		//		|R32|Ch2NoteFine6                   |                       |       |                                                                                   |
		//		|R33|Ch3NoteFine6                   |                       |       |                                                                                   |
		//		|R34|Ch4NoteFine6                   |                       |       |                                                                                   |
		//		|R35|Ch5NoteFine6                   |                       |       |                                                                                   |
		//		|R36|Ch6NoteFine6                   |                       |       |                                                                                   |
		//		|R37|Ch7NoteFine6                   |                       |       |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R38|Ch0PMS3AMS2                    |***|PMS        |*******|AMS    |                                                                                   |
		//		|R39|Ch1PMS3AMS2                    |   |           |       |       |                                                                                   |
		//		|R3A|Ch2PMS3AMS2                    |   |           |       |       |                                                                                   |
		//		|R3B|Ch3PMS3AMS2                    |   |           |       |       |                                                                                   |
		//		|R3C|Ch4PMS3AMS2                    |   |           |       |       |                                                                                   |
		//		|R3D|Ch5PMS3AMS2                    |   |           |       |       |                                                                                   |
		//		|R3E|Ch6PMS3AMS2                    |   |           |       |       |                                                                                   |
		//		|R3F|Ch7PMS3AMS2                    |   |           |       |       |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R40|Ch0DetuneFine3Multiply4        |***|DetuneFine |Multiply       |Multiply/0:周波数*0.5 1～15:周波数*n                                               |
		//		|R41|Ch1DetuneFine3Multiply4        |   |           |               |                                                                                   |
		//		|R42|Ch2DetuneFine3Multiply4        |   |           |               |                                                                                   |
		//		|R43|Ch3DetuneFine3Multiply4        |   |           |               |                                                                                   |
		//		|R44|Ch4DetuneFine3Multiply4        |   |           |               |                                                                                   |
		//		|R45|Ch5DetuneFine3Multiply4        |   |           |               |                                                                                   |
		//		|R46|Ch6DetuneFine3Multiply4        |   |           |               |                                                                                   |
		//		|R47|Ch7DetuneFine3Multiply4        |   |           |               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R48|Ch0SampleStart8                |SampleStart                    |SampleStart/KeyOn波形メモリ再生開始アドレス上位8ビット                             |
		//		|R49|Ch1SampleStart8                |                               |※「Key」書き込みによるKeyOn時、「ChnSampleStartFine8」の値と共に音源に反映        |
		//		|R4A|Ch2SampleStart8                |                               |                                                                                   |
		//		|R4B|Ch3SampleStart8                |                               |                                                                                   |
		//		|R4C|Ch4SampleStart8                |                               |                                                                                   |
		//		|R4D|Ch5SampleStart8                |                               |                                                                                   |
		//		|R4E|Ch6SampleStart8                |                               |                                                                                   |
		//		|R4F|Ch7SampleStart8                |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R50|Ch0SampleStartFine8            |SampleStartFine                |SampleStartFine/KeyOn波形メモリ再生開始アドレス下位8ビット                         |
		//		|R51|Ch1SampleStartFine8            |                               |※即時反映でなく「ChnSampleStart8」書き込み時に反映                                |
		//		|R52|Ch2SampleStartFine8            |                               |                                                                                   |
		//		|R53|Ch3SampleStartFine8            |                               |                                                                                   |
		//		|R54|Ch4SampleStartFine8            |                               |                                                                                   |
		//		|R55|Ch5SampleStartFine8            |                               |                                                                                   |
		//		|R56|Ch6SampleStartFine8            |                               |                                                                                   |
		//		|R57|Ch7SampleStartFine8            |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R58|                               |                               |                                                                                   |
		//		|R59|                               |                               |                                                                                   |
		//		|R5A|                               |                               |                                                                                   |
		//		|R5B|                               |                               |                                                                                   |
		//		|R5C|                               |                               |                                                                                   |
		//		|R5D|                               |                               |                                                                                   |
		//		|R5E|                               |                               |                                                                                   |
		//		|R5F|                               |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R60|Ch0TotalLevel7                 |***|チャンネル音量             |チャンネル音量/0:最大 127:最小                                                     |
		//		|R61|Ch1TotalLevel7                 |   |                           |                                                                                   |
		//		|R62|Ch2TotalLevel7                 |   |                           |                                                                                   |
		//		|R63|Ch3TotalLevel7                 |   |                           |                                                                                   |
		//		|R64|Ch4TotalLevel7                 |   |                           |                                                                                   |
		//		|R65|Ch5TotalLevel7                 |   |                           |                                                                                   |
		//		|R66|Ch6TotalLevel7                 |   |                           |                                                                                   |
		//		|R67|Ch7TotalLevel7                 |   |                           |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R68|Ch0SampleLength8               |SampleLength                   |SampleLength/波形メモリ再生長上位8ビット                                           |
		//		|R69|Ch1SampleLength8               |                               |※「Key」書き込みによるKeyOn時、「ChnSampleLengthFine8」の値と共に音源に反映       |
		//		|R6A|Ch2SampleLength8               |                               |                                                                                   |
		//		|R6B|Ch3SampleLength8               |                               |                                                                                   |
		//		|R6C|Ch4SampleLength8               |                               |                                                                                   |
		//		|R6D|Ch5SampleLength8               |                               |                                                                                   |
		//		|R6E|Ch6SampleLength8               |                               |                                                                                   |
		//		|R6F|Ch7SampleLength8               |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R70|Ch0SampleLengthFine8           |SampleLengthFine               |SampleLengthFine/波形メモリ再生長下位8ビット                                       |
		//		|R71|Ch1SampleLengthFine8           |                               |※即時反映でなく「ChnSampleLength8」書き込み時に反映                               |
		//		|R72|Ch2SampleLengthFine8           |                               |                                                                                   |
		//		|R73|Ch3SampleLengthFine8           |                               |                                                                                   |
		//		|R74|Ch4SampleLengthFine8           |                               |                                                                                   |
		//		|R75|Ch5SampleLengthFine8           |                               |                                                                                   |
		//		|R76|Ch6SampleLengthFine8           |                               |                                                                                   |
		//		|R77|Ch7SampleLengthFine8           |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R78|                               |                               |                                                                                   |
		//		|R79|                               |                               |                                                                                   |
		//		|R7A|                               |                               |                                                                                   |
		//		|R7B|                               |                               |                                                                                   |
		//		|R7C|                               |                               |                                                                                   |
		//		|R7D|                               |                               |                                                                                   |
		//		|R7E|                               |                               |                                                                                   |
		//		|R7F|                               |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R80|Ch0KeyScale2AttackRate5        |KS     |***|AttackRate         |AttackRate/0～1:即KeyOff 2:最遅 31:最速                                            |
		//		|R81|Ch1KeyScale2AttackRate5        |       |   |                   |※即時反映でなく「Key」書き込みによるKeyOn時に反映                                 |
		//		|R82|Ch2KeyScale2AttackRate5        |       |   |                   |KS(KeyScale)/0:効果最弱 3:効果最強                                                 |
		//		|R83|Ch3KeyScale2AttackRate5        |       |   |                   |                                                                                   |
		//		|R84|Ch4KeyScale2AttackRate5        |       |   |                   |                                                                                   |
		//		|R85|Ch5KeyScale2AttackRate5        |       |   |                   |                                                                                   |
		//		|R86|Ch6KeyScale2AttackRate5        |       |   |                   |                                                                                   |
		//		|R87|Ch7KeyScale2AttackRate5        |       |   |                   |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R88|Ch0SampleLoopLength8           |                               |SampleLoopLength/波形メモリループ長上位8ビット                                     |
		//		|R89|Ch1SampleLoopLength8           |                               |※「Key」書き込みによるKeyOn時、「ChnSampleLoopLengthFine8」の値と共に音源に反映   |
		//		|R8A|Ch2SampleLoopLength8           |                               |                                                                                   |
		//		|R8B|Ch3SampleLoopLength8           |                               |                                                                                   |
		//		|R8C|Ch4SampleLoopLength8           |                               |                                                                                   |
		//		|R8D|Ch5SampleLoopLength8           |                               |                                                                                   |
		//		|R8E|Ch6SampleLoopLength8           |                               |                                                                                   |
		//		|R8F|Ch7SampleLoopLength8           |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R90|Ch0SampleLoopLengthFine8       |                               |SampleLoopLengthFine/波形メモリループ長下位8ビット                                 |
		//		|R91|Ch1SampleLoopLengthFine8       |                               |※即時反映でなく「ChnSampleLoopLength8」書き込み時に反映                           |
		//		|R92|Ch2SampleLoopLengthFine8       |                               |                                                                                   |
		//		|R93|Ch3SampleLoopLengthFine8       |                               |                                                                                   |
		//		|R94|Ch4SampleLoopLengthFine8       |                               |                                                                                   |
		//		|R95|Ch5SampleLoopLengthFine8       |                               |                                                                                   |
		//		|R96|Ch6SampleLoopLengthFine8       |                               |                                                                                   |
		//		|R97|Ch7SampleLoopLengthFine8       |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R98|                               |                               |                                                                                   |
		//		|R99|                               |                               |                                                                                   |
		//		|R9A|                               |                               |                                                                                   |
		//		|R9B|                               |                               |                                                                                   |
		//		|R9C|                               |                               |                                                                                   |
		//		|R9D|                               |                               |                                                                                   |
		//		|R9E|                               |                               |                                                                                   |
		//		|R9F|                               |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|RA0|Ch0M1AME1Decay1Rate5           |AME|*******|Decay1Rate         |Decay1Rate/0:最遅 31:最速                                                          |
		//		|RA1|Ch1M1AME1Decay1Rate5           |   |       |                   |AME/0:振幅LFO無効 1:振幅LFO有効                                                    |
		//		|RA2|Ch2M1AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RA3|Ch3M1AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RA4|Ch4M1AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RA5|Ch5M1AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RA6|Ch6M1AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		|RA7|Ch7M1AME1Decay1Rate5           |   |       |                   |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|RA8|                               |                               |                                                                                   |
		//		|RA9|                               |                               |                                                                                   |
		//		|RAA|                               |                               |                                                                                   |
		//		|RAB|                               |                               |                                                                                   |
		//		|RAC|                               |                               |                                                                                   |
		//		|RAD|                               |                               |                                                                                   |
		//		|RAE|                               |                               |                                                                                   |
		//		|RAF|                               |                               |                                                                                   |
		//		|RB0|                               |                               |                                                                                   |
		//		|RB1|                               |                               |                                                                                   |
		//		|RB2|                               |                               |                                                                                   |
		//		|RB3|                               |                               |                                                                                   |
		//		|RB4|                               |                               |                                                                                   |
		//		|RB5|                               |                               |                                                                                   |
		//		|RB6|                               |                               |                                                                                   |
		//		|RB7|                               |                               |                                                                                   |
		//		|RB8|                               |                               |                                                                                   |
		//		|RB9|                               |                               |                                                                                   |
		//		|RBA|                               |                               |                                                                                   |
		//		|RBB|                               |                               |                                                                                   |
		//		|RBC|                               |                               |                                                                                   |
		//		|RBD|                               |                               |                                                                                   |
		//		|RBE|                               |                               |                                                                                   |
		//		|RBF|                               |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|RC0|Ch0M1DetuneRough2Decay2Rate5   |Det.R. |***|Decay2Rate         |Decay2Rate/0:最遅 31:最速                                                          |
		//		|RC1|Ch1M1DetuneRough2Decay2Rate5   |       |   |                   |Det.R.(DetuneRough)/0:効果最弱 3:効果最強                                          |
		//		|RC2|Ch2M1DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RC3|Ch3M1DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RC4|Ch4M1DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RC5|Ch5M1DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RC6|Ch6M1DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		|RC7|Ch7M1DetuneRough2Decay2Rate5   |       |   |                   |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|RC8|                               |                               |                                                                                   |
		//		|RC9|                               |                               |                                                                                   |
		//		|RCA|                               |                               |                                                                                   |
		//		|RCB|                               |                               |                                                                                   |
		//		|RCC|                               |                               |                                                                                   |
		//		|RCD|                               |                               |                                                                                   |
		//		|RCE|                               |                               |                                                                                   |
		//		|RCF|                               |                               |                                                                                   |
		//		|RD0|                               |                               |                                                                                   |
		//		|RD1|                               |                               |                                                                                   |
		//		|RD2|                               |                               |                                                                                   |
		//		|RD3|                               |                               |                                                                                   |
		//		|RD4|                               |                               |                                                                                   |
		//		|RD5|                               |                               |                                                                                   |
		//		|RD6|                               |                               |                                                                                   |
		//		|RD7|                               |                               |                                                                                   |
		//		|RD8|                               |                               |                                                                                   |
		//		|RD9|                               |                               |                                                                                   |
		//		|RDA|                               |                               |                                                                                   |
		//		|RDB|                               |                               |                                                                                   |
		//		|RDC|                               |                               |                                                                                   |
		//		|RDD|                               |                               |                                                                                   |
		//		|RDE|                               |                               |                                                                                   |
		//		|RDF|                               |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|RE0|Ch0M1DecayLevel4ReleaseRate4   |DecayLevel     |ReleaseRate    |ReleaseRate/0:最遅 15:最速                                                         |
		//		|RE1|Ch1M1DecayLevel4ReleaseRate4   |               |               |DecayLevel/0:下降幅最小 15:下降幅最大                                              |
		//		|RE2|Ch2M1DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RE3|Ch3M1DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RE4|Ch4M1DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RE5|Ch5M1DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RE6|Ch6M1DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		|RE7|Ch7M1DecayLevel4ReleaseRate4   |               |               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|RE8|                               |                               |                                                                                   |
		//		|RE9|                               |                               |                                                                                   |
		//		|REA|                               |                               |                                                                                   |
		//		|REB|                               |                               |                                                                                   |
		//		|REC|                               |                               |                                                                                   |
		//		|RED|                               |                               |                                                                                   |
		//		|REE|                               |                               |                                                                                   |
		//		|REF|                               |                               |                                                                                   |
		//		|RF0|                               |                               |                                                                                   |
		//		|RF1|                               |                               |                                                                                   |
		//		|RF2|                               |                               |                                                                                   |
		//		|RF3|                               |                               |                                                                                   |
		//		|RF4|                               |                               |                                                                                   |
		//		|RF5|                               |                               |                                                                                   |
		//		|RF6|                               |                               |                                                                                   |
		//		|RF7|                               |                               |                                                                                   |
		//		|RF8|                               |                               |                                                                                   |
		//		|RF9|                               |                               |                                                                                   |
		//		|RFA|                               |                               |                                                                                   |
		//		|RFB|                               |                               |                                                                                   |
		//		|RFC|                               |                               |                                                                                   |
		//		|RFD|                               |                               |                                                                                   |
		//		|RFE|                               |                               |                                                                                   |
		//		|RFF|                               |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		class _PCM_IDREGISTERW{
		public:
			enum BODY:UINT8{
				_00=					0x00,
				LFOReset1=				0x01,
				LFOFrequency=			0x02,
				LFODepth7=				0x03,
				_04=					0x04,
				LFOShape2=				0x05,
				_06=					0x06,
				_07=					0x07,
				Key=					0x08,
				_09=					0x09,
				ClockAH=				0x0a,
				ClockAL2=				0x0b,
				ClockB=					0x0c,
				_0D=					0x0d,
				Timer=					0x0e,
				NoiseDivRatio5=			0x0f,
				Ch0StereoLevelL7=		0x10,
				Ch1StereoLevelL7=		0x11,
				Ch2StereoLevelL7=		0x12,
				Ch3StereoLevelL7=		0x13,
				Ch4StereoLevelL7=		0x14,
				Ch5StereoLevelL7=		0x15,
				Ch6StereoLevelL7=		0x16,
				Ch7StereoLevelL7=		0x17,
				Ch0StereoLevelR7=		0x18,
				Ch1StereoLevelR7=		0x19,
				Ch2StereoLevelR7=		0x1a,
				Ch3StereoLevelR7=		0x1b,
				Ch4StereoLevelR7=		0x1c,
				Ch5StereoLevelR7=		0x1d,
				Ch6StereoLevelR7=		0x1e,
				Ch7StereoLevelR7=		0x1f,
				Ch0Interpolation2Deceleration4=	0x20,
				Ch1Interpolation2Deceleration4=	0x21,
				Ch2Interpolation2Deceleration4=	0x22,
				Ch3Interpolation2Deceleration4=	0x23,
				Ch4Interpolation2Deceleration4=	0x24,
				Ch5Interpolation2Deceleration4=	0x25,
				Ch6Interpolation2Deceleration4=	0x26,
				Ch7Interpolation2Deceleration4=	0x27,
				Ch0Note7=				0x28,
				Ch1Note7=				0x29,
				Ch2Note7=				0x2a,
				Ch3Note7=				0x2b,
				Ch4Note7=				0x2c,
				Ch5Note7=				0x2d,
				Ch6Note7=				0x2e,
				Ch7Note7=				0x2f,
				Ch0NoteFine6=			0x30,
				Ch1NoteFine6=			0x31,
				Ch2NoteFine6=			0x32,
				Ch3NoteFine6=			0x33,
				Ch4NoteFine6=			0x34,
				Ch5NoteFine6=			0x35,
				Ch6NoteFine6=			0x36,
				Ch7NoteFine6=			0x37,
				Ch0PMS3AMS2=			0x38,
				Ch1PMS3AMS2=			0x39,
				Ch2PMS3AMS2=			0x3a,
				Ch3PMS3AMS2=			0x3b,
				Ch4PMS3AMS2=			0x3c,
				Ch5PMS3AMS2=			0x3d,
				Ch6PMS3AMS2=			0x3e,
				Ch7PMS3AMS2=			0x3f,
				Ch0DetuneFine3Multiply4=	0x40,
				Ch1DetuneFine3Multiply4=	0x41,
				Ch2DetuneFine3Multiply4=	0x42,
				Ch3DetuneFine3Multiply4=	0x43,
				Ch4DetuneFine3Multiply4=	0x44,
				Ch5DetuneFine3Multiply4=	0x45,
				Ch6DetuneFine3Multiply4=	0x46,
				Ch7DetuneFine3Multiply4=	0x47,
				Ch0SampleStart8=		0x48,
				Ch1SampleStart8=		0x49,
				Ch2SampleStart8=		0x4a,
				Ch3SampleStart8=		0x4b,
				Ch4SampleStart8=		0x4c,
				Ch5SampleStart8=		0x4d,
				Ch6SampleStart8=		0x4e,
				Ch7SampleStart8=		0x4f,
				Ch0SampleStartFine8=	0x50,
				Ch1SampleStartFine8=	0x51,
				Ch2SampleStartFine8=	0x52,
				Ch3SampleStartFine8=	0x53,
				Ch4SampleStartFine8=	0x54,
				Ch5SampleStartFine8=	0x55,
				Ch6SampleStartFine8=	0x56,
				Ch7SampleStartFine8=	0x57,
				_58=					0x58,
				_59=					0x59,
				_5a=					0x5a,
				_5b=					0x5b,
				_5c=					0x5c,
				_5d=					0x5d,
				_5e=					0x5e,
				_5f=					0x5f,
				Ch0TotalLevel7=			0x60,
				Ch1TotalLevel7=			0x61,
				Ch2TotalLevel7=			0x62,
				Ch3TotalLevel7=			0x63,
				Ch4TotalLevel7=			0x64,
				Ch5TotalLevel7=			0x65,
				Ch6TotalLevel7=			0x66,
				Ch7TotalLevel7=			0x67,
				Ch0SampleLength8=		0x68,
				Ch1SampleLength8=		0x69,
				Ch2SampleLength8=		0x6a,
				Ch3SampleLength8=		0x6b,
				Ch4SampleLength8=		0x6c,
				Ch5SampleLength8=		0x6d,
				Ch6SampleLength8=		0x6e,
				Ch7SampleLength8=		0x6f,
				Ch0SampleLengthFine8=	0x70,
				Ch1SampleLengthFine8=	0x71,
				Ch2SampleLengthFine8=	0x72,
				Ch3SampleLengthFine8=	0x73,
				Ch4SampleLengthFine8=	0x74,
				Ch5SampleLengthFine8=	0x75,
				Ch6SampleLengthFine8=	0x76,
				Ch7SampleLengthFine8=	0x77,
				_78=					0x78,
				_79=					0x79,
				_7a=					0x7a,
				_7b=					0x7b,
				_7c=					0x7c,
				_7d=					0x7d,
				_7e=					0x7e,
				_7f=					0x7f,
				Ch0KeyScale2AttackRate5=	0x80,
				Ch1KeyScale2AttackRate5=	0x81,
				Ch2KeyScale2AttackRate5=	0x82,
				Ch3KeyScale2AttackRate5=	0x83,
				Ch4KeyScale2AttackRate5=	0x84,
				Ch5KeyScale2AttackRate5=	0x85,
				Ch6KeyScale2AttackRate5=	0x86,
				Ch7KeyScale2AttackRate5=	0x87,
				Ch0SampleLoopLength8=	0x88,
				Ch1SampleLoopLength8=	0x89,
				Ch2SampleLoopLength8=	0x8a,
				Ch3SampleLoopLength8=	0x8b,
				Ch4SampleLoopLength8=	0x8c,
				Ch5SampleLoopLength8=	0x8d,
				Ch6SampleLoopLength8=	0x8e,
				Ch7SampleLoopLength8=	0x8f,
				Ch0SampleLoopLengthFine8=	0x90,
				Ch1SampleLoopLengthFine8=	0x91,
				Ch2SampleLoopLengthFine8=	0x92,
				Ch3SampleLoopLengthFine8=	0x93,
				Ch4SampleLoopLengthFine8=	0x94,
				Ch5SampleLoopLengthFine8=	0x95,
				Ch6SampleLoopLengthFine8=	0x96,
				Ch7SampleLoopLengthFine8=	0x97,
				_98=					0x98,
				_99=					0x99,
				_9a=					0x9a,
				_9b=					0x9b,
				_9c=					0x9c,
				_9d=					0x9d,
				_9e=					0x9e,
				_9f=					0x9f,
				Ch0Decay1Rate5=			0xa0,
				Ch1Decay1Rate5=			0xa1,
				Ch2Decay1Rate5=			0xa2,
				Ch3Decay1Rate5=			0xa3,
				Ch4Decay1Rate5=			0xa4,
				Ch5Decay1Rate5=			0xa5,
				Ch6Decay1Rate5=			0xa6,
				Ch7Decay1Rate5=			0xa7,
				_a8=					0xa8,
				_a9=					0xa9,
				_aa=					0xaa,
				_ab=					0xab,
				_ac=					0xac,
				_ad=					0xad,
				_ae=					0xae,
				_af=					0xaf,
				_b0=					0xb0,
				_b1=					0xb1,
				_b2=					0xb2,
				_b3=					0xb3,
				_b4=					0xb4,
				_b5=					0xb5,
				_b6=					0xb6,
				_b7=					0xb7,
				_b8=					0xb8,
				_b9=					0xb9,
				_ba=					0xba,
				_bb=					0xbb,
				_bc=					0xbc,
				_bd=					0xbd,
				_be=					0xbe,
				_bf=					0xbf,
				Ch0DetuneRough2Decay2Rate5=	0xc0,
				Ch1DetuneRough2Decay2Rate5=	0xc1,
				Ch2DetuneRough2Decay2Rate5=	0xc2,
				Ch3DetuneRough2Decay2Rate5=	0xc3,
				Ch4DetuneRough2Decay2Rate5=	0xc4,
				Ch5DetuneRough2Decay2Rate5=	0xc5,
				Ch6DetuneRough2Decay2Rate5=	0xc6,
				Ch7DetuneRough2Decay2Rate5=	0xc7,
				_c8=					0xc8,
				_c9=					0xc9,
				_ca=					0xca,
				_cb=					0xcb,
				_cc=					0xcc,
				_cd=					0xcd,
				_ce=					0xce,
				_cf=					0xcf,
				_d0=					0xd0,
				_d1=					0xd1,
				_d2=					0xd2,
				_d3=					0xd3,
				_d4=					0xd4,
				_d5=					0xd5,
				_d6=					0xd6,
				_d7=					0xd7,
				_d8=					0xd8,
				_d9=					0xd9,
				_da=					0xda,
				_db=					0xdb,
				_dc=					0xdc,
				_dd=					0xdd,
				_de=					0xde,
				_df=					0xdf,
				Ch0DecayLevel4ReleaseRate4=	0xe0,
				Ch1DecayLevel4ReleaseRate4=	0xe1,
				Ch2DecayLevel4ReleaseRate4=	0xe2,
				Ch3DecayLevel4ReleaseRate4=	0xe3,
				Ch4DecayLevel4ReleaseRate4=	0xe4,
				Ch5DecayLevel4ReleaseRate4=	0xe5,
				Ch6DecayLevel4ReleaseRate4=	0xe6,
				Ch7DecayLevel4ReleaseRate4=	0xe7,
				_e8=					0xe8,
				_e9=					0xe9,
				_ea=					0xea,
				_eb=					0xeb,
				_ec=					0xec,
				_ed=					0xed,
				_ee=					0xee,
				_ef=					0xef,
				_f0=					0xf0,
				_f1=					0xf1,
				_f2=					0xf2,
				_f3=					0xf3,
				_f4=					0xf4,
				_f5=					0xf5,
				_f6=					0xf6,
				_f7=					0xf7,
				_f8=					0xf8,
				_f9=					0xf9,
				_fa=					0xfa,
				_fb=					0xfb,
				_fc=					0xfc,
				_fd=					0xfd,
				_fe=					0xfe,
				_ff=					0xff
			};
		};
		using					PCM_IDREGISTERW=_PCM_IDREGISTERW::BODY;
		class _PCM_IDINTERPOLATION{
		public:
			enum BODY:UINT8{
				None=0,
				Linear=1,
				Reserved0=2,
				Reserved1=3
			};
		};
		using					PCM_IDINTERPOLATION=_PCM_IDINTERPOLATION::BODY;
		static constexpr UINT8	PCM_stcui8nChannel=		8;
		//	PCM_IDREGISTERR
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R番|名称                           |7  |6  |5  |4  |3  |2  |1  |0  |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R00|                               |                               |                                                                                   |
		//		|R01|                               |                               |                                                                                   |
		//		|R02|                               |                               |                                                                                   |
		//		|R03|                               |                               |                                                                                   |
		//		|R04|                               |                               |                                                                                   |
		//		|R05|                               |                               |                                                                                   |
		//		|R06|                               |                               |                                                                                   |
		//		|R07|                               |                               |                                                                                   |
		//		|R08|                               |                               |                                                                                   |
		//		|R09|                               |                               |                                                                                   |
		//		|R0A|                               |                               |                                                                                   |
		//		|R0B|                               |                               |                                                                                   |
		//		|R0C|                               |                               |                                                                                   |
		//		|R0D|                               |                               |                                                                                   |
		//		|R0E|                               |                               |                                                                                   |
		//		|R0F|                               |                               |                                                                                   |
		//		|R10|                               |                               |                                                                                   |
		//		|R11|                               |                               |                                                                                   |
		//		|R12|                               |                               |                                                                                   |
		//		|R13|                               |                               |                                                                                   |
		//		|R14|                               |                               |                                                                                   |
		//		|R15|                               |                               |                                                                                   |
		//		|R16|                               |                               |                                                                                   |
		//		|R17|                               |                               |                                                                                   |
		//		|R18|                               |                               |                                                                                   |
		//		|R19|                               |                               |                                                                                   |
		//		|R1A|                               |                               |                                                                                   |
		//		|R1B|                               |                               |                                                                                   |
		//		|R1C|                               |                               |                                                                                   |
		//		|R1D|                               |                               |                                                                                   |
		//		|R1E|                               |                               |                                                                                   |
		//		|R1F|                               |                               |                                                                                   |
		//		|R20|                               |                               |                                                                                   |
		//		|R21|                               |                               |                                                                                   |
		//		|R22|                               |                               |                                                                                   |
		//		|R23|                               |                               |                                                                                   |
		//		|R24|                               |                               |                                                                                   |
		//		|R25|                               |                               |                                                                                   |
		//		|R26|                               |                               |                                                                                   |
		//		|R27|                               |                               |                                                                                   |
		//		|R28|                               |                               |                                                                                   |
		//		|R29|                               |                               |                                                                                   |
		//		|R2A|                               |                               |                                                                                   |
		//		|R2B|                               |                               |                                                                                   |
		//		|R2C|                               |                               |                                                                                   |
		//		|R2D|                               |                               |                                                                                   |
		//		|R2E|                               |                               |                                                                                   |
		//		|R2F|                               |                               |                                                                                   |
		//		|R30|                               |                               |                                                                                   |
		//		|R31|                               |                               |                                                                                   |
		//		|R32|                               |                               |                                                                                   |
		//		|R33|                               |                               |                                                                                   |
		//		|R34|                               |                               |                                                                                   |
		//		|R35|                               |                               |                                                                                   |
		//		|R36|                               |                               |                                                                                   |
		//		|R37|                               |                               |                                                                                   |
		//		|R38|                               |                               |                                                                                   |
		//		|R39|                               |                               |                                                                                   |
		//		|R3A|                               |                               |                                                                                   |
		//		|R3B|                               |                               |                                                                                   |
		//		|R3C|                               |                               |                                                                                   |
		//		|R3D|                               |                               |                                                                                   |
		//		|R3E|                               |                               |                                                                                   |
		//		|R3F|                               |                               |                                                                                   |
		//		|R40|                               |                               |                                                                                   |
		//		|R41|                               |                               |                                                                                   |
		//		|R42|                               |                               |                                                                                   |
		//		|R43|                               |                               |                                                                                   |
		//		|R44|                               |                               |                                                                                   |
		//		|R45|                               |                               |                                                                                   |
		//		|R46|                               |                               |                                                                                   |
		//		|R47|                               |                               |                                                                                   |
		//		|R48|                               |                               |                                                                                   |
		//		|R49|                               |                               |                                                                                   |
		//		|R4A|                               |                               |                                                                                   |
		//		|R4B|                               |                               |                                                                                   |
		//		|R4C|                               |                               |                                                                                   |
		//		|R4D|                               |                               |                                                                                   |
		//		|R4E|                               |                               |                                                                                   |
		//		|R4F|                               |                               |                                                                                   |
		//		|R50|                               |                               |                                                                                   |
		//		|R51|                               |                               |                                                                                   |
		//		|R52|                               |                               |                                                                                   |
		//		|R53|                               |                               |                                                                                   |
		//		|R54|                               |                               |                                                                                   |
		//		|R55|                               |                               |                                                                                   |
		//		|R56|                               |                               |                                                                                   |
		//		|R57|                               |                               |                                                                                   |
		//		|R58|                               |                               |                                                                                   |
		//		|R59|                               |                               |                                                                                   |
		//		|R5A|                               |                               |                                                                                   |
		//		|R5B|                               |                               |                                                                                   |
		//		|R5C|                               |                               |                                                                                   |
		//		|R5D|                               |                               |                                                                                   |
		//		|R5E|                               |                               |                                                                                   |
		//		|R5F|                               |                               |                                                                                   |
		//		|R60|                               |                               |                                                                                   |
		//		|R61|                               |                               |                                                                                   |
		//		|R62|                               |                               |                                                                                   |
		//		|R63|                               |                               |                                                                                   |
		//		|R64|                               |                               |                                                                                   |
		//		|R65|                               |                               |                                                                                   |
		//		|R66|                               |                               |                                                                                   |
		//		|R67|                               |                               |                                                                                   |
		//		|R68|                               |                               |                                                                                   |
		//		|R69|                               |                               |                                                                                   |
		//		|R6A|                               |                               |                                                                                   |
		//		|R6B|                               |                               |                                                                                   |
		//		|R6C|                               |                               |                                                                                   |
		//		|R6D|                               |                               |                                                                                   |
		//		|R6E|                               |                               |                                                                                   |
		//		|R6F|                               |                               |                                                                                   |
		//		|R70|                               |                               |                                                                                   |
		//		|R71|                               |                               |                                                                                   |
		//		|R72|                               |                               |                                                                                   |
		//		|R73|                               |                               |                                                                                   |
		//		|R74|                               |                               |                                                                                   |
		//		|R75|                               |                               |                                                                                   |
		//		|R76|                               |                               |                                                                                   |
		//		|R77|                               |                               |                                                                                   |
		//		|R78|                               |                               |                                                                                   |
		//		|R79|                               |                               |                                                                                   |
		//		|R7A|                               |                               |                                                                                   |
		//		|R7B|                               |                               |                                                                                   |
		//		|R7C|                               |                               |                                                                                   |
		//		|R7D|                               |                               |                                                                                   |
		//		|R7E|                               |                               |                                                                                   |
		//		|R7F|                               |                               |                                                                                   |
		//		|R80|                               |                               |                                                                                   |
		//		|R81|                               |                               |                                                                                   |
		//		|R82|                               |                               |                                                                                   |
		//		|R83|                               |                               |                                                                                   |
		//		|R84|                               |                               |                                                                                   |
		//		|R85|                               |                               |                                                                                   |
		//		|R86|                               |                               |                                                                                   |
		//		|R87|                               |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R88|PCM_Ch0SampleCurrent8          |SampleCurrent                  |SampleCurrent/波形メモリ再生位置上位8ビット                                        |
		//		|R89|PCM_Ch1SampleCurrent8          |                               |※読み取りリクエスト受付次第「PCM_ChnSampleCurrentFine8」の値も固定                |
		//		|R8A|PCM_Ch2SampleCurrent8          |                               |                                                                                   |
		//		|R8B|PCM_Ch3SampleCurrent8          |                               |                                                                                   |
		//		|R8C|PCM_Ch4SampleCurrent8          |                               |                                                                                   |
		//		|R8D|PCM_Ch5SampleCurrent8          |                               |                                                                                   |
		//		|R8E|PCM_Ch6SampleCurrent8          |                               |                                                                                   |
		//		|R8F|PCM_Ch7SampleCurrent8          |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R90|PCM_Ch0SampleCurrentFine8      |SampleCurrentFine              |SampleCurrentFine/波形メモリ再生位置下位8ビット                                    |
		//		|R91|PCM_Ch1SampleCurrentFine8      |                               |※「PCM_ChnSampleCurrent8」読み取りリクエスト時点での値                            |
		//		|R92|PCM_Ch2SampleCurrentFine8      |                               |                                                                                   |
		//		|R93|PCM_Ch3SampleCurrentFine8      |                               |                                                                                   |
		//		|R94|PCM_Ch4SampleCurrentFine8      |                               |                                                                                   |
		//		|R95|PCM_Ch5SampleCurrentFine8      |                               |                                                                                   |
		//		|R96|PCM_Ch6SampleCurrentFine8      |                               |                                                                                   |
		//		|R97|PCM_Ch7SampleCurrentFine8      |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		//		|R98|                               |                               |                                                                                   |
		//		|R99|                               |                               |                                                                                   |
		//		|R9A|                               |                               |                                                                                   |
		//		|R9B|                               |                               |                                                                                   |
		//		|R9C|                               |                               |                                                                                   |
		//		|R9D|                               |                               |                                                                                   |
		//		|R9E|                               |                               |                                                                                   |
		//		|R9F|                               |                               |                                                                                   |
		//		|RA0|                               |                               |                                                                                   |
		//		|RA1|                               |                               |                                                                                   |
		//		|RA2|                               |                               |                                                                                   |
		//		|RA3|                               |                               |                                                                                   |
		//		|RA4|                               |                               |                                                                                   |
		//		|RA5|                               |                               |                                                                                   |
		//		|RA6|                               |                               |                                                                                   |
		//		|RA7|                               |                               |                                                                                   |
		//		|RA8|                               |                               |                                                                                   |
		//		|RA9|                               |                               |                                                                                   |
		//		|RAA|                               |                               |                                                                                   |
		//		|RAB|                               |                               |                                                                                   |
		//		|RAC|                               |                               |                                                                                   |
		//		|RAD|                               |                               |                                                                                   |
		//		|RAE|                               |                               |                                                                                   |
		//		|RAF|                               |                               |                                                                                   |
		//		|RB0|                               |                               |                                                                                   |
		//		|RB1|                               |                               |                                                                                   |
		//		|RB2|                               |                               |                                                                                   |
		//		|RB3|                               |                               |                                                                                   |
		//		|RB4|                               |                               |                                                                                   |
		//		|RB5|                               |                               |                                                                                   |
		//		|RB6|                               |                               |                                                                                   |
		//		|RB7|                               |                               |                                                                                   |
		//		|RB8|                               |                               |                                                                                   |
		//		|RB9|                               |                               |                                                                                   |
		//		|RBA|                               |                               |                                                                                   |
		//		|RBB|                               |                               |                                                                                   |
		//		|RBC|                               |                               |                                                                                   |
		//		|RBD|                               |                               |                                                                                   |
		//		|RBE|                               |                               |                                                                                   |
		//		|RBF|                               |                               |                                                                                   |
		//		|RC0|                               |                               |                                                                                   |
		//		|RC1|                               |                               |                                                                                   |
		//		|RC2|                               |                               |                                                                                   |
		//		|RC3|                               |                               |                                                                                   |
		//		|RC4|                               |                               |                                                                                   |
		//		|RC5|                               |                               |                                                                                   |
		//		|RC6|                               |                               |                                                                                   |
		//		|RC7|                               |                               |                                                                                   |
		//		|RC8|                               |                               |                                                                                   |
		//		|RC9|                               |                               |                                                                                   |
		//		|RCA|                               |                               |                                                                                   |
		//		|RCB|                               |                               |                                                                                   |
		//		|RCC|                               |                               |                                                                                   |
		//		|RCD|                               |                               |                                                                                   |
		//		|RCE|                               |                               |                                                                                   |
		//		|RCF|                               |                               |                                                                                   |
		//		|RD0|                               |                               |                                                                                   |
		//		|RD1|                               |                               |                                                                                   |
		//		|RD2|                               |                               |                                                                                   |
		//		|RD3|                               |                               |                                                                                   |
		//		|RD4|                               |                               |                                                                                   |
		//		|RD5|                               |                               |                                                                                   |
		//		|RD6|                               |                               |                                                                                   |
		//		|RD7|                               |                               |                                                                                   |
		//		|RD8|                               |                               |                                                                                   |
		//		|RD9|                               |                               |                                                                                   |
		//		|RDA|                               |                               |                                                                                   |
		//		|RDB|                               |                               |                                                                                   |
		//		|RDC|                               |                               |                                                                                   |
		//		|RDD|                               |                               |                                                                                   |
		//		|RDE|                               |                               |                                                                                   |
		//		|RDF|                               |                               |                                                                                   |
		//		|RE0|                               |                               |                                                                                   |
		//		|RE1|                               |                               |                                                                                   |
		//		|RE2|                               |                               |                                                                                   |
		//		|RE3|                               |                               |                                                                                   |
		//		|RE4|                               |                               |                                                                                   |
		//		|RE5|                               |                               |                                                                                   |
		//		|RE6|                               |                               |                                                                                   |
		//		|RE7|                               |                               |                                                                                   |
		//		|RE8|                               |                               |                                                                                   |
		//		|RE9|                               |                               |                                                                                   |
		//		|REA|                               |                               |                                                                                   |
		//		|REB|                               |                               |                                                                                   |
		//		|REC|                               |                               |                                                                                   |
		//		|RED|                               |                               |                                                                                   |
		//		|REE|                               |                               |                                                                                   |
		//		|REF|                               |                               |                                                                                   |
		//		|RF0|                               |                               |                                                                                   |
		//		|RF1|                               |                               |                                                                                   |
		//		|RF2|                               |                               |                                                                                   |
		//		|RF3|                               |                               |                                                                                   |
		//		|RF4|                               |                               |                                                                                   |
		//		|RF5|                               |                               |                                                                                   |
		//		|RF6|                               |                               |                                                                                   |
		//		|RF7|                               |                               |                                                                                   |
		//		|RF8|                               |                               |                                                                                   |
		//		|RF9|                               |                               |                                                                                   |
		//		|RFA|                               |                               |                                                                                   |
		//		|RFB|                               |                               |                                                                                   |
		//		|RFC|                               |                               |                                                                                   |
		//		|RFD|                               |                               |                                                                                   |
		//		|RFE|                               |                               |                                                                                   |
		//		|RFF|                               |                               |                                                                                   |
		//		+---+-------------------------------+---+---+---+---+---+---+---+---+-----------------------------------------------------------------------------------+
		class _IDREGISTERR{
		public:
			enum BODY:UINT8{
				_00=					0x00,
				_01=					0x01,
				_02=					0x02,
				_03=					0x03,
				_04=					0x04,
				_05=					0x05,
				_06=					0x06,
				_07=					0x07,
				_08=					0x08,
				_09=					0x09,
				_0a=					0x0a,
				_0b=					0x0b,
				_0c=					0x0c,
				_0d=					0x0d,
				_0e=					0x0e,
				_0f=					0x0f,
				_10=					0x10,
				_11=					0x11,
				_12=					0x12,
				_13=					0x13,
				_14=					0x14,
				_15=					0x15,
				_16=					0x16,
				_17=					0x17,
				_18=					0x18,
				_19=					0x19,
				_1a=					0x1a,
				_1b=					0x1b,
				_1c=					0x1c,
				_1d=					0x1d,
				_1e=					0x1e,
				_1f=					0x1f,
				_20=					0x20,
				_21=					0x21,
				_22=					0x22,
				_23=					0x23,
				_24=					0x24,
				_25=					0x25,
				_26=					0x26,
				_27=					0x27,
				_28=					0x28,
				_29=					0x29,
				_2a=					0x2a,
				_2b=					0x2b,
				_2c=					0x2c,
				_2d=					0x2d,
				_2e=					0x2e,
				_2f=					0x2f,
				_30=					0x30,
				_31=					0x31,
				_32=					0x32,
				_33=					0x33,
				_34=					0x34,
				_35=					0x35,
				_36=					0x36,
				_37=					0x37,
				_38=					0x38,
				_39=					0x39,
				_3a=					0x3a,
				_3b=					0x3b,
				_3c=					0x3c,
				_3d=					0x3d,
				_3e=					0x3e,
				_3f=					0x3f,
				_40=					0x40,
				_41=					0x41,
				_42=					0x42,
				_43=					0x43,
				_44=					0x44,
				_45=					0x45,
				_46=					0x46,
				_47=					0x47,
				_48=					0x48,
				_49=					0x49,
				_4a=					0x4a,
				_4b=					0x4b,
				_4c=					0x4c,
				_4d=					0x4d,
				_4e=					0x4e,
				_4f=					0x4f,
				_50=					0x50,
				_51=					0x51,
				_52=					0x52,
				_53=					0x53,
				_54=					0x54,
				_55=					0x55,
				_56=					0x56,
				_57=					0x57,
				_58=					0x58,
				_59=					0x59,
				_5a=					0x5a,
				_5b=					0x5b,
				_5c=					0x5c,
				_5d=					0x5d,
				_5e=					0x5e,
				_5f=					0x5f,
				_60=					0x60,
				_61=					0x61,
				_62=					0x62,
				_63=					0x63,
				_64=					0x64,
				_65=					0x65,
				_66=					0x66,
				_67=					0x67,
				_68=					0x68,
				_69=					0x69,
				_6a=					0x6a,
				_6b=					0x6b,
				_6c=					0x6c,
				_6d=					0x6d,
				_6e=					0x6e,
				_6f=					0x6f,
				_70=					0x70,
				_71=					0x71,
				_72=					0x72,
				_73=					0x73,
				_74=					0x74,
				_75=					0x75,
				_76=					0x76,
				_77=					0x77,
				_78=					0x78,
				_79=					0x79,
				_7a=					0x7a,
				_7b=					0x7b,
				_7c=					0x7c,
				_7d=					0x7d,
				_7e=					0x7e,
				_7f=					0x7f,
				_80=					0x80,
				_81=					0x81,
				_82=					0x82,
				_83=					0x83,
				_84=					0x84,
				_85=					0x85,
				_86=					0x86,
				_87=					0x87,
				PCM_Ch0SampleCurrent8=	0x88,
				PCM_Ch1SampleCurrent8=	0x89,
				PCM_Ch2SampleCurrent8=	0x8a,
				PCM_Ch3SampleCurrent8=	0x8b,
				PCM_Ch4SampleCurrent8=	0x8c,
				PCM_Ch5SampleCurrent8=	0x8d,
				PCM_Ch6SampleCurrent8=	0x8e,
				PCM_Ch7SampleCurrent8=	0x8f,
				PCM_Ch0SampleCurrentFine8=	0x90,
				PCM_Ch1SampleCurrentFine8=	0x91,
				PCM_Ch2SampleCurrentFine8=	0x92,
				PCM_Ch3SampleCurrentFine8=	0x93,
				PCM_Ch4SampleCurrentFine8=	0x94,
				PCM_Ch5SampleCurrentFine8=	0x95,
				PCM_Ch6SampleCurrentFine8=	0x96,
				PCM_Ch7SampleCurrentFine8=	0x97,
				_98=					0x98,
				_99=					0x99,
				_9a=					0x9a,
				_9b=					0x9b,
				_9c=					0x9c,
				_9d=					0x9d,
				_9e=					0x9e,
				_9f=					0x9f,
				_a0=					0xa0,
				_a1=					0xa1,
				_a2=					0xa2,
				_a3=					0xa3,
				_a4=					0xa4,
				_a5=					0xa5,
				_a6=					0xa6,
				_a7=					0xa7,
				_a8=					0xa8,
				_a9=					0xa9,
				_aa=					0xaa,
				_ab=					0xab,
				_ac=					0xac,
				_ad=					0xad,
				_ae=					0xae,
				_af=					0xaf,
				_b0=					0xb0,
				_b1=					0xb1,
				_b2=					0xb2,
				_b3=					0xb3,
				_b4=					0xb4,
				_b5=					0xb5,
				_b6=					0xb6,
				_b7=					0xb7,
				_b8=					0xb8,
				_b9=					0xb9,
				_ba=					0xba,
				_bb=					0xbb,
				_bc=					0xbc,
				_bd=					0xbd,
				_be=					0xbe,
				_bf=					0xbf,
				_c0=					0xc0,
				_c1=					0xc1,
				_c2=					0xc2,
				_c3=					0xc3,
				_c4=					0xc4,
				_c5=					0xc5,
				_c6=					0xc6,
				_c7=					0xc7,
				_c8=					0xc8,
				_c9=					0xc9,
				_ca=					0xca,
				_cb=					0xcb,
				_cc=					0xcc,
				_cd=					0xcd,
				_ce=					0xce,
				_cf=					0xcf,
				_d0=					0xd0,
				_d1=					0xd1,
				_d2=					0xd2,
				_d3=					0xd3,
				_d4=					0xd4,
				_d5=					0xd5,
				_d6=					0xd6,
				_d7=					0xd7,
				_d8=					0xd8,
				_d9=					0xd9,
				_da=					0xda,
				_db=					0xdb,
				_dc=					0xdc,
				_dd=					0xdd,
				_de=					0xde,
				_df=					0xdf,
				_e0=					0xe0,
				_e1=					0xe1,
				_e2=					0xe2,
				_e3=					0xe3,
				_e4=					0xe4,
				_e5=					0xe5,
				_e6=					0xe6,
				_e7=					0xe7,
				_e8=					0xe8,
				_e9=					0xe9,
				_ea=					0xea,
				_eb=					0xeb,
				_ec=					0xec,
				_ed=					0xed,
				_ee=					0xee,
				_ef=					0xef,
				_f0=					0xf0,
				_f1=					0xf1,
				_f2=					0xf2,
				_f3=					0xf3,
				_f4=					0xf4,
				_f5=					0xf5,
				_f6=					0xf6,
				_f7=					0xf7,
				_f8=					0xf8,
				_f9=					0xf9,
				_fa=					0xfa,
				_fb=					0xfb,
				_fc=					0xfc,
				_fd=					0xfd,
				_fe=					0xfe,
				_ff=					0xff
			};
		};
		using					IDREGISTERR=_IDREGISTERR::BODY;
		static constexpr UINT16	stcui16nRegisterW=		0x100;
		static constexpr UINT16	stcui16nRegisterR=		0x100;
		static constexpr UINT32	PCMRAM_stcui32nSize=	0x010000;
	};

	//
	//		custom
	//

	constexpr YM2151B::FM_IDREGISTERW	operator +(const YM2151B::FM_IDREGISTERW cidregister,CUINT8 cui8doffset)noexcept{
		return YM2151B::FM_IDREGISTERW(UINT8(cidregister)+cui8doffset);
	}
	constexpr YM2151B::PCM_IDREGISTERW	operator +(const YM2151B::PCM_IDREGISTERW cidregister,CUINT8 cui8doffset)noexcept{
		return YM2151B::PCM_IDREGISTERW(UINT8(cidregister)+cui8doffset);
	}
	constexpr YM2151B::IDREGISTERR	operator +(const YM2151B::IDREGISTERR cidregister,CUINT8 cui8doffset)noexcept{
		return YM2151B::IDREGISTERR(UINT8(cidregister)+cui8doffset);
	}
}

#endif
