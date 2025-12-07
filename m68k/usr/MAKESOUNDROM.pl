#!/usr/bin/perl
##############################################################################
##																			##
##																			##
##								ORE68000ACE									##
##																			##
##	'MAKESOUNDROM.pl'								2025 written by int71	##
##############################################################################
use strict;
$INC[@INC]='/usr/local/ofw/lib';
require 'base.pl';
my($sVersion,$sDate)=('1.00','2025/12/06');
my($COM_sDirectory)=('/d/Sync/Package/Cross/ORE68000_ACE/m68k');

new BASE::();

sub main{
	my($ref_array_argument,$ref_hash_option)=@_;
	my($sdirectorysource,%hash_switch);

	if(defined $$ref_hash_option{'v'}){
		&USR_version();
		return 0;
	}elsif(defined $$ref_hash_option{'h'}){
		&USR_help();
		return 0;
	}else{
		if($$ref_array_argument[0] ne ''){
			$sdirectorysource=$$ref_array_argument[0];
		}else{
			&USR_help();
			return 0;
		}
		if($$ref_hash_option{'o'} ne ''){
			$hash_switch{'NameBIN'}=$$ref_hash_option{'o'};
			if(substr($hash_switch{'NameBIN'},-4) eq '.bin'){
				$hash_switch{'NameBIN'}=substr($hash_switch{'NameBIN'},0,length($hash_switch{'NameBIN'})-4);
			}
		}else{
			$hash_switch{'NameBIN'}='SOUND';
		}
		if($$ref_hash_option{'c'} ne ''){
			$hash_switch{'NameHPP'}=$$ref_hash_option{'c'};
			if(substr($hash_switch{'NameHPP'},-4) eq '.hpp'){
				$hash_switch{'NameHPP'}=substr($hash_switch{'NameHPP'},0,length($hash_switch{'NameHPP'})-4);
			}
		}else{
			$hash_switch{'NameHPP'}='soundrom.hpp';
		}
		if($$ref_hash_option{'j'} ne ''){
			$hash_switch{'Project'}=$$ref_hash_option{'j'};
		}else{
			$hash_switch{'Project'}='ORE68000ACE';
		}
		if($$ref_hash_option{'r'} ne ''){
			$hash_switch{'Replace'}=' -r "'.$$ref_hash_option{'r'}.'"';
		}else{
			$hash_switch{'Replace'}='';
		}
	}
	{
		my($image_bin,$image_hpp,$itimestamp)=&USR_MAKESOUNDROM($sdirectorysource,\%hash_switch);

		if(defined $$ref_hash_option{'d'}){
			my($line);

			$image_hpp->SetCurrent(0);
			while(defined($line=$image_hpp->GetLINE())){
				BASE::Print("$line\n");
			}
		}else{
			my($sbin)="$hash_switch{'NameBIN'}.bin";
			my($shpp)="$hash_switch{'NameHPP'}.hpp";
			my($itimestampbin)=BASE::GetFileTimeStamp($sbin);

			if((not defined $itimestampbin)||($itimestampbin<$itimestamp)){
				$image_bin->Save($sbin);
				$image_hpp->Save($shpp);
			}
		}
	}
	return 0;
}

sub USR_version{
	BASE::Print("M68K_MAKESOUNDROM Version $sVersion Release $sDate Written by int71\n");
	return;
}

sub USR_help{
	BASE::Print(<<END
<概要>
  音色定義、BGM、SE演奏データを一つのROMファイルにまとめ、位置情報を「.hpp」で出力します。
  いわゆる「make」的に、ファイル日付の比較によって処理を最小化します。

<書式>
$BASE::Self (入力) [-v] [-h] [-o (出力).bin] [-c (Cヘッダ).hpp] [-j (プロジェクト名)] [-r (置換文字列定義)]

<オプション>
-v: バージョンを表示します。
-h: このメッセージを表示します。
-o: 出力ファイル名を指定します。デフォルト値は「SOUND.bin」です。
-c: 出力Cヘッダファイル名を指定します。デフォルト値は「soundrom.hpp」です。
-j: Cヘッダファイル内コメントとして記載するプロジェクト名を指定します。デフォルト値は「ORE68000」です。
-r: BGM演奏テキストの置換文字列定義ファイル名を指定します。
  「(置換文字列定義)」はPerlスクリプトであるので、変数、コメントの記述方法もPerlのそれに準じます。

    --------サンプルここから--------
    {
        ' 4A ,PG=64,PN=-18,PM=0'=>   'BD',
        ' 4A ,PG=65,PN=64,PM=0'=>    'SD',
        ' 5C ,PG=67,PN=96,PM=0'=>    'TMh',
        ' 4G#,PG=67,PN=0,PM=0'=>     'TMm',
        ' 4D#,PG=67,PN=-96,PM=0'=>   'TMl',
        ' 4A ,PG=68,PN=62,PM=0'=>    'HHc',
        ' 4A ,PG=69,PN=62,PM=0'=>    'HHo',
        ' 4A ,PG=70,PN=-80,PM=0'=>   'CS',
        ' 4A ,PG=71,PN=-66,PM=0'=>   'RD'
    };
    --------サンプルここまで--------

  「変換元=>変換先」列挙による「ハッシュ参照」として定義します。
-d: ファイルでなく標準出力に出力します。現状「Cヘッダファイル」のみの出力です。中間「.bin」は通常通り作成されます。

<「(入力)」について>
  「(入力)」はディレクトリで、配下の下記ファイルを処理対象とします。

  ・FM音色データ「*.opm」→「.bin」に変換
  ・PCM音色データ「*.xml」→「.bin」に変換
  ・BGM演奏MIDIファイル「BGM*.mid」→BGM演奏テキストファイル「BGM*.sh」に変換
  ・BGM演奏テキストファイル「BGM*.sh」→「BGM*.bin」に変換
  ・SE演奏MIDIファイル「SE*.mid」→SE演奏テキストファイル「SE*.sh」に変換
  ・SE演奏テキストファイル「SE*.sh」→「SE*.bin」に変換
  ・音声サンプリングデータ「VC*.wav」→「VC*.bin」に変換

<「(出力).bin」について>
  「(入力)」配下に作成された「.bin」を1つの「(出力).bin」にまとめます。
  音色、BGM、SEの順で、それぞれ昇順ソートされます。
  特にSEの並び順は「PlayDynamic」で再生上書きできるかどうかを左右するので重要です。

<「(Cヘッダ).hpp」について>
  基本的に「ファイル名」が「変数名」になりますが、「ファイル名」にソート順調整のための文字列が付加されている場合、変更都度プログラム側の「変数名」指定を修正する必要があるため、「_」区切り2要素目が16進数表記であるなら、「変数名」から除外します。
  例えば「BGM_10_Air0」であるなら「BGM_Air0_stcui32iAddressS」のような「変数名」が与えられます。
END
	);
	return;
}

sub USR_MAKESOUNDROM{
	my($sdirectorysource,$ref_hash_switch)=@_;
	my($smacro)=BASE::STRING_Upper($$ref_hash_switch{'Project'}.'_'.BASE::STRING_Replace($$ref_hash_switch{'NameHPP'},'/','_'));
	my($snamespace)=BASE::STRING_Lower($$ref_hash_switch{'Project'});
	my(@array_sfilesource)=&USR_ListAllFile($sdirectorysource);
	my($image_bin,$image_hpp);
	my($itimestamp);
	my($image_bank_hpp);
	my(@array_image_bgm_hpp);
	my(@array_image_se_hpp);
	my(@array_image_voice_hpp);
	my($sfilesource);

	$image_bin=new BASE_IMAGE::();
	$image_hpp=new BASE_IMAGE::();
	$itimestamp=0;

	#
	#		BANK
	#

	$image_bank_hpp=new BASE_IMAGE::();
	#	BANK/FM
	foreach $sfilesource(@array_sfilesource){
		if($sfilesource=~/\.opm$/){
			my($sdirectory,$sfile,$sname,$soption)=&USR_sMakeName($sfilesource);

			$itimestamp=BASE::Maximum($itimestamp,&USR_itimestampEntry(
				$image_bin,$image_bank_hpp,$sname,
				"$sdirectory/$sfile.bin",
				$sfilesource,
				"$COM_sDirectory/M68K_MAKEBANKFM.pl$soption"
			));
		}
	}
	#	BANK/PCM
	foreach $sfilesource(@array_sfilesource){
		if($sfilesource=~/\.xml$/){
			my($sdirectory,$sfile,$sname,$soption)=&USR_sMakeName($sfilesource);
			my($iaddress)=$image_bin->GetCurrent();

			$itimestamp=BASE::Maximum($itimestamp,&USR_itimestampEntry(
				$image_bin,$image_bank_hpp,$sname,
				"$sdirectory/$sfile.bin",
				$sfilesource,
				"$COM_sDirectory/M68K_MAKEBANKPCM.pl$soption"
			));
			$image_bank_hpp->AddLINE(
				"\t\t\t".&USR_sTabLeft(
					"static constexpr UINT32\t${sname}_PCMM_stcui32iAddressS=",18
				).sprintf("stcui32iAddressS+0x%06x;",$iaddress+0x00800)
			);
		}
	}

	#
	#		BGM
	#

	@array_image_bgm_hpp=(new BASE_IMAGE::(),new BASE_IMAGE::(),new BASE_IMAGE::());
	foreach $sfilesource(@array_sfilesource){
		if($sfilesource=~/BGM.+\.mid$/){
			my($sdirectory,$sfile,$sname,$soption)=&USR_sMakeName($sfilesource,'BGM_');

			$itimestamp=BASE::Maximum($itimestamp,&USR_itimestampMake(
				"$sdirectory/$sfile.sh",
				$sfilesource,
				"$COM_sDirectory/M68K_SMF2SEQ.pl$soption -a \"TRANSPOSE=0,PMSPEED=204\" -u 32 -f PCM3,PCM4,PCM5,PCM6 -c \"  C ,PG=127\" -m 63 -z 4 -n FM0,FM1,FM2,FM3,FM4,FM5,PCM0,PCM1,PCM2,PCM3,PCM4,PCM5,PCM6".$$ref_hash_switch{'Replace'}
			));
			if($array_image_bgm_hpp[0]->GetCurrent()){
				$array_image_bgm_hpp[0]->AddLINE(',');
			}
			$array_image_bgm_hpp[0]->AddTEXT("\t\t\t\t$sname");
			$itimestamp=BASE::Maximum($itimestamp,&USR_itimestampEntry(
				$image_bin,$array_image_bgm_hpp[1],$sname,
				"$sdirectory/$sfile.bin",
				"$sdirectory/$sfile.sh",
				"$COM_sDirectory/M68K_MAKESEQUENCE.pl"
			));
			if($array_image_bgm_hpp[2]->GetCurrent()){
				$array_image_bgm_hpp[2]->AddLINE(',');
			}
			$array_image_bgm_hpp[2]->AddTEXT("\t\t\t\t${sname}_stcui32iAddressS");
		}
	}

	#
	#		SE
	#

	@array_image_se_hpp=(new BASE_IMAGE::(),new BASE_IMAGE::(),new BASE_IMAGE::());
	foreach $sfilesource(@array_sfilesource){
		if($sfilesource=~/SE\S+\.mid$/){
			my($sdirectory,$sfile,$sname,$soption)=&USR_sMakeName($sfilesource,'SE_');

			$itimestamp=BASE::Maximum($itimestamp,&USR_itimestampMake(
				"$sdirectory/$sfile.sh",
				$sfilesource,
				"$COM_sDirectory/M68K_SMF2SEQ.pl$soption -op 128"
			));
			if($array_image_se_hpp[0]->GetCurrent()){
				$array_image_se_hpp[0]->AddLINE(',');
			}
			$array_image_se_hpp[0]->AddTEXT("\t\t\t\t$sname");
			$itimestamp=BASE::Maximum($itimestamp,&USR_itimestampEntry(
				$image_bin,$array_image_se_hpp[1],$sname,
				"$sdirectory/$sfile.bin",
				"$sdirectory/$sfile.sh",
				"$COM_sDirectory/M68K_MAKESEQUENCE.pl"
			));
			if($array_image_se_hpp[2]->GetCurrent()){
				$array_image_se_hpp[2]->AddLINE(',');
			}
			$array_image_se_hpp[2]->AddTEXT("\t\t\t\t${sname}_stcui32iAddressS");
		}
	}

	#
	#		VOICE
	#

	@array_image_voice_hpp=(new BASE_IMAGE::(),new BASE_IMAGE::(),new BASE_IMAGE::(),new BASE_IMAGE::());
	foreach $sfilesource(@array_sfilesource){
		if($sfilesource=~/VOICE\S+\.wav$/){
			my($sdirectory,$sfile,$sname,$soption)=&USR_sMakeName($sfilesource,'VOICE_');

			if($array_image_voice_hpp[0]->GetCurrent()){
				$array_image_voice_hpp[0]->AddLINE(',');
			}
			$array_image_voice_hpp[0]->AddTEXT("\t\t\t\t$sname");
			$itimestamp=BASE::Maximum($itimestamp,&USR_itimestampEntry(
				$image_bin,$array_image_voice_hpp[1],$sname,
				"$sdirectory/$sfile.bin",
				$sfilesource,
				"$COM_sDirectory/M68K_MAKEVOICE$soption",
				1
			));
			if($array_image_voice_hpp[2]->GetCurrent()){
				$array_image_voice_hpp[2]->AddLINE(',');
			}
			$array_image_voice_hpp[2]->AddTEXT("\t\t\t\t${sname}_stcui32iAddressS");
			if($array_image_voice_hpp[3]->GetCurrent()){
				$array_image_voice_hpp[3]->AddLINE(',');
			}
			$array_image_voice_hpp[3]->AddTEXT("\t\t\t\t${sname}_stcui16nBlock");
		}
	}

	#
	#		全体まとめ
	#

	$image_hpp->AddTEXT(<<END
/****************************************************************************
**																			**
**																			**
END
	);
	$image_hpp->AddLINE('**'.&USR_sTabCenter($$ref_hash_switch{'Project'},19).'**');
	$image_hpp->AddTEXT(<<END
**																			**
END
	);
	$image_hpp->AddLINE("**\t".&USR_sTabLeft("'".$$ref_hash_switch{'NameHPP'}.".hpp'",12)."2025 written by int71\t**");
	$image_hpp->AddTEXT(<<END
 ****************************************************************************/
#ifndef $smacro
#define $smacro

//
//		include
//

#include				"map.hpp"

//
//		namespace:m68k::${snamespace}::common
//

namespace m68k::${snamespace}::common{

	//
	//		class
	//

	class ROM_SOUND;

	//
	//		class:ROM_SOUND
	//

	class ROM_SOUND{
	public:

		//
		//		const
		//

		static constexpr AUTO	stcui32iAddressS=								ore68000ace::ROM_SOUND_stcui32iAddressS;
END
	);
	if($array_image_bgm_hpp[0]->GetSize()){
		#	第1ブロック「識別子列挙」/BGM
		$image_hpp->AddTEXT(<<END
		class _IDBGM{
		public:
			enum BODY:UINT16{
				Null,
END
		);
		$image_hpp->Add($array_image_bgm_hpp[0]);
		$image_hpp->AddLINE('');
		$image_hpp->AddTEXT(<<END
			};
		};
		using					IDBGM=_IDBGM::BODY;
END
		);
	}
	if($array_image_se_hpp[0]->GetSize()){
		#	第1ブロック「識別子列挙」/SE
		$image_hpp->AddTEXT(<<END
		class _IDSE{
		public:
			enum BODY:UINT16{
END
		);
		$image_hpp->Add($array_image_se_hpp[0]);
		$image_hpp->AddLINE('');
		$image_hpp->AddTEXT(<<END
			};
		};
		using					IDSE=_IDSE::BODY;
END
		);
	}
	if($array_image_voice_hpp[0]->GetSize()){
		#	第1ブロック「識別子列挙」/VOICE
		$image_hpp->AddTEXT(<<END
		class _IDVOICE{
		public:
			enum BODY:UINT16{
END
		);
		$image_hpp->Add($array_image_voice_hpp[0]);
		$image_hpp->AddLINE('');
		$image_hpp->AddTEXT(<<END
			};
		};
		using					IDVOICE=_IDVOICE::BODY;
END
		);
	}
	#	クラスプロトタイプ宣言
	$image_hpp->AddTEXT(<<END

		//
		//		class
		//

END
	);
	if($image_bank_hpp->GetSize()){
		$image_hpp->AddTEXT(<<END
		//	BANK
		class BANK;
END
		);
	}
	if($array_image_bgm_hpp[1]->GetSize()){
		$image_hpp->AddTEXT(<<END
		//	BGM
		class BGM;
END
		);
	}
	if($array_image_se_hpp[1]->GetSize()){
		$image_hpp->AddTEXT(<<END
		//	SE
		class SE;
END
		);
	}
	if($array_image_voice_hpp[1]->GetSize()){
		$image_hpp->AddTEXT(<<END
		//	VOICE
		class VOICE;
END
		);
	}
	if($image_bank_hpp->GetSize()){
		#	クラス宣言/BANK
		$image_hpp->AddTEXT(<<END

		//
		//		class:BANK
		//

		class BANK{
		public:

			//
			//		const
			//

END
		);
		#	第2ブロック「アドレス設定本体」/BANK
		$image_hpp->Add($image_bank_hpp);
		$image_hpp->AddTEXT(<<END
		};
END
		);
	}
	if($array_image_bgm_hpp[1]->GetSize()){
		#	クラス宣言/BGM
		$image_hpp->AddTEXT(<<END

		//
		//		class:BGM
		//

		class BGM{
		public:

			//
			//		const
			//

END
		);
		#	第2ブロック「アドレス設定本体」/BGM
		$image_hpp->Add($array_image_bgm_hpp[1]);
		$image_hpp->AddTEXT(<<END
			static constexpr UINT32	stacui32iAddressS[]={
				0x000000,
END
		);
		#	第3ブロック「アドレス列挙」/BGM
		$image_hpp->Add($array_image_bgm_hpp[2]);
		$image_hpp->AddLINE('');
		$image_hpp->AddTEXT(<<END
			};
		};
END
		);
	}
	if($array_image_se_hpp[1]->GetSize()){
		#	クラス宣言/SE
		$image_hpp->AddTEXT(<<END

		//
		//		class:SE
		//

		class SE{
		public:

			//
			//		const
			//

END
		);
		#	第2ブロック「アドレス設定本体」/SE
		$image_hpp->Add($array_image_se_hpp[1]);
		$image_hpp->AddTEXT(<<END
			static constexpr UINT32	stacui32iAddressS[]={
END
		);
		#	第3ブロック「アドレス列挙」/SE
		$image_hpp->Add($array_image_se_hpp[2]);
		$image_hpp->AddLINE('');
		$image_hpp->AddTEXT(<<END
			};
		};
END
		);
	}
	if($array_image_voice_hpp[1]->GetSize()){
		#	クラス宣言/VOICE
		$image_hpp->AddTEXT(<<END

		//
		//		class:VOICE
		//

		class VOICE{
		public:

			//
			//		const
			//

END
		);
		#	第2ブロック「アドレス設定本体」/VOICE
		$image_hpp->Add($array_image_voice_hpp[1]);
		$image_hpp->AddTEXT(<<END
			static constexpr UINT32	stacui32iAddressS[]={
END
		);
		#	第3ブロック「アドレス列挙」/VOICE
		$image_hpp->Add($array_image_voice_hpp[2]);
		$image_hpp->AddLINE('');
		$image_hpp->AddTEXT(<<END
			};
			static constexpr UINT16	stacui16nBlock[]={
END
		);
		#	第4ブロック「サイズ列挙」/VOICE
		$image_hpp->Add($array_image_voice_hpp[3]);
		$image_hpp->AddLINE('');
		$image_hpp->AddTEXT(<<END
			};
		};
END
		);
	}
	$image_hpp->AddTEXT(<<END
	};
}
#endif
END
	);
	return $image_bin,$image_hpp,$itimestamp;
}

sub USR_ListAllFile{
	my($sdirectorysource)=@_;
	my(@array_sfilesource);
	my($sfile);
	
	foreach $sfile(BASE::ListAllFile($sdirectorysource)){
		if(
			($sfile!~/\(Recycle\)/)&&
			($sfile!~/\(Source\)/)&&
			($sfile!~/\(Work\)/)
		){
			push(@array_sfilesource,$sfile);
		}
	}
	return @array_sfilesource;
}

sub USR_sMakeName{
	my($sfilesource,$sprefix)=@_;
	my($sdirectory,$sfile)=(BASE::STRING_GetPath($sfilesource),BASE::STRING_RemoveExtension(BASE::STRING_GetFile($sfilesource)));
	my($soption);

	$soption='';
	{
		my($iifrom,$iito)=(index($sfile,'('),rindex($sfile,')'));

		if((0<=$iifrom)&&($iifrom<$iito)){
			$soption=substr($sfile,$iifrom+1,$iito-$iifrom-1);
			$sfile=substr($sfile,0,$iifrom).substr($sfile,$iito+1);
			if($soption ne ''){
				$soption=" $soption";
			}
		}
	}
	{
		my($sname)=$sfile;
		my(@array_sname)=split(/_/,$sname);
		my($npart)=scalar(@array_sname);
		my($ipart);

		#	数字部分の削除
		for($ipart=0;$ipart<$npart;++$ipart){
			if($array_sname[$ipart]=~/^[0-9A-Fa-f]+$/){
				splice(@array_sname,$ipart,1);
			}
		}
		$sname=join('_',@array_sname);
		if(defined $sprefix){
			my($inprefix)=length($sprefix);

			if(substr($sname,0,$inprefix) eq $sprefix){
				$sname=substr($sname,$inprefix);
			}
		}
		return ($sdirectory,$sfile,$sname,$soption);
	}
}

sub USR_itimestampEntry{
	my(
		$image_bin,$image_hpp,$sname,
		$sfiledestination,
		$sfilesource,
		$scommand,
		$ehpp_writesize
	)=@_;
	my($itimestampdestination)=&USR_itimestampMake($sfiledestination,$sfilesource,$scommand);
	my($img_destination)=new BASE_IMAGE::($sfiledestination);

	$image_hpp->AddLINE(
		"\t\t\t".&USR_sTabLeft(
			"static constexpr UINT32\t${sname}_stcui32iAddressS=",18
		).sprintf("stcui32iAddressS+0x%06x;",$image_bin->GetCurrent())
	);
	if($ehpp_writesize){
		$image_hpp->AddLINE(
			"\t\t\t".&USR_sTabLeft(
				"static constexpr UINT32\t${sname}_stcui32nSize=",18
			).sprintf("0x%06x;",$img_destination->GetSize())
		);
		$image_hpp->AddLINE(
			"\t\t\t".&USR_sTabLeft(
				"static constexpr UINT16\t${sname}_stcui16nBlock=",18
			)."${sname}_stcui32nSize>>8;"
		);
	}
	$image_bin->Add($img_destination);
	return $itimestampdestination;
}

sub USR_itimestampMake{
	my($sfiledestination,$sfilesource,$scommand)=@_;
	my($itimestampdestination)=BASE::GetFileTimeStamp($sfiledestination);
	my($itimestampsource)=BASE::GetFileTimeStamp($sfilesource);

	if((not defined $itimestampdestination)||($itimestampdestination<$itimestampsource)){
		BASE::Print(`$scommand \"$sfilesource\" -o \"$sfiledestination\"`);
		$itimestampdestination=BASE::GetFileTimeStamp($sfiledestination);
	}
	return $itimestampdestination;
}

sub USR_sTabLeft{
	my($ssource,$ntab)=@_;
	my($ntabrest);

	$ntabrest=$ntab-(length(&USR_sTab2Space($ssource))>>2);
	if($ntabrest<1){
		$ntabrest=1;
	}
	return $ssource.("\t"x$ntabrest);
}

sub USR_sTabCenter{
	my($ssource,$ntab)=@_;
	my($ntabrest);

	$ntabrest=$ntab-(length($ssource)>>2);
	return ("\t"x($ntabrest>>1)).$ssource.("\t"x($ntabrest-($ntabrest>>1)));
}

sub USR_sTab2Space{
	my($ssource)=@_;
	my($iitab)=0;

	while(1){
		$iitab=index($ssource,"\t",$iitab);
		if(0<=$iitab){
			substr($ssource,$iitab,1)=' 'x(4-($iitab&3));
			$iitab=($iitab+4)&(~3);
		}else{
			last;
		}
	}
	return $ssource;
}
