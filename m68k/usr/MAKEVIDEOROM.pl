#!/usr/bin/perl
##############################################################################
##																			##
##																			##
##								ORE68000 ACE								##
##																			##
##	'ORE68000ACE_MAKEVIDEOROM.pl'					2025 written by int71	##
##############################################################################
use strict;
$INC[@INC]='/usr/local/ofw/lib';
require 'base.pl';
my($sVersion,$sDate)=('1.00','2025/11/23');
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
			$hash_switch{'NameBIN'}='VIDEO';
		}
		if($$ref_hash_option{'c'} ne ''){
			$hash_switch{'NameHPP'}=$$ref_hash_option{'c'};
			if(substr($hash_switch{'NameHPP'},-4) eq '.hpp'){
				$hash_switch{'NameHPP'}=substr($hash_switch{'NameHPP'},0,length($hash_switch{'NameHPP'})-4);
			}
		}else{
			$hash_switch{'NameHPP'}='patternrom.hpp';
		}
		if($$ref_hash_option{'j'} ne ''){
			$hash_switch{'Project'}=$$ref_hash_option{'j'};
		}else{
			$hash_switch{'Project'}='ORE68000';
		}
	}
	{
		my($image_bin,$image_hpp,$itimestamp)=&USR_MAKEVIDEOROM($sdirectorysource,\%hash_switch);

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
	BASE::Print("ORE68000ACE_MAKEVIDEOROM Version $sVersion Release $sDate Written by int71\n");
	return;
}

sub USR_help{
	BASE::Print(<<END
<概要>
  音色定義、BGM、SE演奏データを一つのROMファイルにまとめ、位置情報を「.hpp」で出力します。
  いわゆる「make」的に、ファイル日付の比較によって処理を最小化します。

<書式>
$BASE::Self (入力) [-v] [-h] [-o (出力).bin] [-c (Cヘッダ).hpp] [-j (プロジェクト名)]

<オプション>
-v: バージョンを表示します。
-h: このメッセージを表示します。
-o: 出力ファイル名を指定します。デフォルト値は「VIDEO.bin」です。
-c: 出力Cヘッダファイル名を指定します。デフォルト値は「patternrom.hpp」です。
-j: Cヘッダファイル内コメントとして記載するプロジェクト名を指定します。デフォルト値は「ORE68000」です。
-d: ファイルでなく標準出力に出力します。現状「Cヘッダファイル」のみの出力です。中間「.bin」は通常通り作成されます。

<「(入力)」について>
  「(入力)」はディレクトリで、配下の下記ファイルを処理対象とします。

  ・パターン画像「*.png」
    パターンデータ、パレットデータ「.bin」に変換します。
    パレットデータ作成には、ファイル名にオプション指示「(-p)」を含める必要があります。
    出力ファイルの名称は、パターンが文字列「PATTERN_」、パレットが文字列「PALETTE_」を接頭辞にし、入力ファイル名先頭の「数字_」は省略します。
    これは「数字_」による列挙順制御を想定しているからです。

      「00_SPRITE_SYSTEM.png」→「PATTERN_SPRITE_SYSTEM」、「PALETTE_SPRITE_SYSTEM」
      「SPR_ADD.png」→「PATTERN_SPR_ADD」、「PALETTE_SPR_ADD」

  ・マップデータ「(サブディレクトリ)/MAP.tmx」
    マップデータ「(サブディレクトリ)/MAP.bin」およびイベントプログラムコードに変換します。
  ・背景データ「(サブディレクトリ)/BACK.tmx」
    マップデータ「(サブディレクトリ)/BACK.bin」に変換します。
    「MAP」共々、ファイル名を決め打ちしているのは、タイル画像作成用「.tmx」を処理対象から除外するためです。

  パターン画像、マップデータ共通の機能として、ファイル名に「(オプション文字列)」を含める事で変換処理のオプションとする事ができます。

    「SPR(-p 0,1,2,3,4,5).png」→「M68K_MAKEPATTERN.exe」にオプション「-p 0,1,2,3,4,5」を指定

  このオプション文字列は出力名からは除外されます。

<「(出力).bin」について>
  「(入力)」配下に作成された「.bin」を1つの「(出力).bin」にまとめます。
  アライン要求の強さに準じ、下記データ種別単位でまとめて出力します。

  ・マップ/背景データ(8,192(縦32パターン時)～32,768(縦128パターン時)バイトアライン)
  ・パターンデータ(アライン不要)
  ・パレットデータ(アライン不要)

  これによってもアライン要求を満たせない場合はパディングによるサイズ調整を行います。
END
	);
	return;
}

sub USR_MAKEVIDEOROM{
	my($sdirectorysource,$ref_hash_switch)=@_;
	my($smacro)=BASE::STRING_Upper($$ref_hash_switch{'Project'}.'_'.BASE::STRING_Replace($$ref_hash_switch{'NameHPP'},'/','_'));
	my($snamespace)=BASE::STRING_Lower($$ref_hash_switch{'Project'});

	$sdirectorysource=~s/\/$//;
	{
		my($ndirectorysource)=length($sdirectorysource);
		my(@array_sfilesource)=&USR_ListAllFile($sdirectorysource);
		my($image_map_bin,@array_image_map_hpp,$in_map_topalign);
		my($image_back_bin,@array_image_back_hpp,$in_back_topalign);
		my($image_pattern_bin,@array_image_pattern_hpp,$image_patternchr_hpp);
		my($image_palette_bin,@array_image_palette_hpp);
		my($itimestamp);
		my($sfilesource);

		$image_map_bin=new BASE_IMAGE::();
		@array_image_map_hpp=(new BASE_IMAGE::(),new BASE_IMAGE::(),new BASE_IMAGE::(),new BASE_IMAGE::(),new BASE_IMAGE::(),new BASE_IMAGE::(),new BASE_IMAGE::(),new BASE_IMAGE::(),new BASE_IMAGE::());
		undef $in_map_topalign;
		$image_back_bin=new BASE_IMAGE::();
		@array_image_back_hpp=(new BASE_IMAGE::(),new BASE_IMAGE::(),new BASE_IMAGE::(),new BASE_IMAGE::(),new BASE_IMAGE::(),new BASE_IMAGE::(),new BASE_IMAGE::());
		undef $in_back_topalign;
		$image_pattern_bin=new BASE_IMAGE::();
		@array_image_pattern_hpp=(new BASE_IMAGE::(),new BASE_IMAGE::(),new BASE_IMAGE::(),new BASE_IMAGE::());
		$image_patternchr_hpp=new BASE_IMAGE::();
		$image_palette_bin=new BASE_IMAGE::();
		@array_image_palette_hpp=(new BASE_IMAGE::(),new BASE_IMAGE::(),new BASE_IMAGE::(),new BASE_IMAGE::());
		$itimestamp=0;
		foreach $sfilesource(@array_sfilesource){
			my($sdirectory,$sfile,$sextension)=(BASE::STRING_GetPath($sfilesource),BASE::STRING_RemoveExtension(BASE::STRING_GetFile($sfilesource)),BASE::STRING_GetExtension($sfilesource));
			my($sdirectory_short)=$sdirectory;

			if($sdirectory_short eq $sdirectorysource){
				$sdirectory_short='';
			}elsif(substr($sdirectory_short,0,$ndirectorysource+1) eq "$sdirectorysource/"){
				$sdirectory_short=substr($sdirectory_short,$ndirectorysource+1)
			}
			if($sfile!~/\./){
				if($sdirectory_short eq ''){
					#	共通系
					if(($sextension eq 'png')){
						my($sname,$soption)=&USR_ExtractName($sfile);

						if($soption=~/\-p\b/){
							$itimestamp=BASE::Maximum($itimestamp,&USR_itimestampEntry(
								$sfile,
								$image_pattern_bin,\@array_image_pattern_hpp,$image_patternchr_hpp,"$sdirectory/PATTERN_$sname.bin",$sname,'PATTERN',
								$image_palette_bin,\@array_image_palette_hpp,undef,"$sdirectory/PALETTE_$sname.bin",$sname,'PALETTE',
								"$sdirectory/$sfile.png",
								"$COM_sDirectory/M68K_MAKEPATTERN.exe$soption"
							));
						}else{
							$itimestamp=BASE::Maximum($itimestamp,&USR_itimestampEntry(
								$sfile,
								$image_pattern_bin,\@array_image_pattern_hpp,$image_patternchr_hpp,"$sdirectory/PATTERN_$sname.bin",$sname,'PATTERN',
								undef,undef,undef,'','','',
								"$sdirectory/$sfile.png",
								"$COM_sDirectory/M68K_MAKEPATTERN.exe$soption"
							));
						}
					}
				}else{
					#	ステージ別系
					if($sextension eq 'tmx'){
						my($sname,$soption)=&USR_ExtractName($sfile);
						my($sdestination)=BASE::STRING_Lower(BASE::STRING_GetFile($sdirectory));

						if($sname eq 'MAP'){
							$itimestamp=BASE::Maximum($itimestamp,&USR_itimestampEntry(
								$sdirectory_short.$sfile,
								$image_map_bin,\@array_image_map_hpp,undef,"$sdirectory/MAP.bin",$sdirectory_short,'MAP',
								undef,undef,undef,'','','',
								"$sdirectory/$sfile.tmx",
								"$COM_sDirectory/M68K_TMX2BIN.pl -c \"main/stage/$sdestination.cpp\" -j $$ref_hash_switch{'Project'}$soption",
								\$in_map_topalign
							));
						}elsif($sname eq 'BACK'){
							$itimestamp=BASE::Maximum($itimestamp,&USR_itimestampEntry(
								$sdirectory_short.$sfile,
								$image_back_bin,\@array_image_back_hpp,undef,"$sdirectory/BACK.bin",$sdirectory_short,'BACK',
								undef,undef,undef,'','','',
								"$sdirectory/$sfile.tmx",
								"$COM_sDirectory/M68K_TMX2BIN.pl$soption",
								\$in_back_topalign
							));
						}
					}elsif($sextension eq 'png'){
						my($sname,$soption)=&USR_ExtractName($sfile);

						if($soption=~/\-p\b/){
							$itimestamp=BASE::Maximum($itimestamp,&USR_itimestampEntry(
								$sdirectory_short.$sfile,
								$image_pattern_bin,\@array_image_pattern_hpp,$image_patternchr_hpp,"$sdirectory/PATTERN_$sname.bin",$sname.'_'.$sdirectory_short,'PATTERN',
								$image_palette_bin,\@array_image_palette_hpp,undef,"$sdirectory/PALETTE_$sname.bin",$sname.'_'.$sdirectory_short,'PALETTE',
								"$sdirectory/$sfile.png",
								"$COM_sDirectory/M68K_MAKEPATTERN.exe$soption"
							));
						}else{
							$itimestamp=BASE::Maximum($itimestamp,&USR_itimestampEntry(
								$sdirectory_short.$sfile,
								$image_pattern_bin,\@array_image_pattern_hpp,$image_patternchr_hpp,"$sdirectory/PATTERN_$sname.bin",$sname.'_'.$sdirectory_short,'PATTERN',
								undef,undef,undef,'','','',
								"$sdirectory/$sfile.png",
								"$COM_sDirectory/M68K_MAKEPATTERN.exe$soption"
							));
						}
					}
				}
			}
		}
		#	最後のまとめ
		{
			my($image_bin,$image_hpp);

			$image_bin=new BASE_IMAGE::();
			$image_hpp=new BASE_IMAGE::();
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

#include				<ore68000ace/map.hpp>

//
//		namespace:m68k::${snamespace}::common
//

namespace m68k::${snamespace}::common{

	//
	//		class
	//

	class ROM_VIDEO;

	//
	//		class:ROM_VIDEO
	//

	class ROM_VIDEO{
	public:

		//
		//		const
		//

		static constexpr AUTO	stcui32iAddressS=								ore68000ace::ROM_VIDEO_stcui32iAddressS;
END
			);
			if($array_image_map_hpp[0]->GetSize()){
				#	第1ブロック「識別子列挙」/MAP
				$image_hpp->AddTEXT(<<END
		class _IDMAP{
		public:
			enum BODY:UINT16{
END
				);
				$image_hpp->Add($array_image_map_hpp[0]);
				$image_hpp->AddLINE('');
				$image_hpp->AddTEXT(<<END
			};
		};
		using					IDMAP=_IDMAP::BODY;
END
				);
			}
			if($array_image_pattern_hpp[0]->GetSize()){
				#	第1ブロック「識別子列挙」/PATTERN
				$image_hpp->AddTEXT(<<END
		class _IDPATTERN{
		public:
			enum BODY:UINT16{
END
				);
				$image_hpp->Add($array_image_pattern_hpp[0]);
				$image_hpp->AddLINE('');
				$image_hpp->AddTEXT(<<END
			};
		};
		using					IDPATTERN=_IDPATTERN::BODY;
END
				);
			}
			if($array_image_palette_hpp[0]->GetSize()){
				#	第1ブロック「識別子列挙」/PALETTE
				$image_hpp->AddTEXT(<<END
		class _IDPALETTE{
		public:
			enum BODY:UINT16{
END
				);
				$image_hpp->Add($array_image_palette_hpp[0]);
				$image_hpp->AddLINE('');
				$image_hpp->AddTEXT(<<END
			};
		};
		using					IDPALETTE=_IDPALETTE::BODY;
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
			if($array_image_map_hpp[1]->GetSize()){
				$image_hpp->AddTEXT(<<END
		//	MAP
		class MAP;
END
				);
			}
			if($array_image_back_hpp[1]->GetSize()){
				$image_hpp->AddTEXT(<<END
		//	BACK
		class BACK;
END
				);
			}
			if($image_patternchr_hpp->GetSize()){
				$image_hpp->AddTEXT(<<END
		//	PATTERNCHR
		class PATTERNCHR;
END
				);
			}
			if($array_image_pattern_hpp[1]->GetSize()){
				$image_hpp->AddTEXT(<<END
		//	PATTERN
		class PATTERN;
END
				);
			}
			if($array_image_palette_hpp[1]->GetSize()){
				$image_hpp->AddTEXT(<<END
		//	PALETTE
		class PALETTE;
END
				);
			}
			if($array_image_map_hpp[1]->GetSize()){
				#	クラス宣言/MAP
				$image_hpp->AddTEXT(<<END

		//
		//		class:MAP
		//

		class MAP{
		public:

			//
			//		const
			//

END
				);
				#	第2ブロック「アドレス、サイズ設定本体」/MAP
				&USR_Align($image_bin,$in_map_topalign);
				$image_hpp->AddLINE(sprintf(
					"\t\t\tstatic constexpr UINT32\tstcui32iBaseAddressS=\t\t\t\t\t\t\tstcui32iAddressS+0x%06x;",
					$image_bin->GetCurrent()
				));
				$image_hpp->Add($array_image_map_hpp[1]);
				$image_bin->Add($image_map_bin);
				$image_hpp->AddTEXT(<<END
			static constexpr UINT32	stacui32iAddressS[]={
END
				);
				#	第3ブロック「アドレス列挙」/MAP
				$image_hpp->Add($array_image_map_hpp[2]);
				$image_hpp->AddLINE('');
				$image_hpp->AddTEXT(<<END
			};
			static constexpr UINT32	stacui32nSize[]={
END
				);
				#	第4ブロック「サイズ列挙」/MAP
				$image_hpp->Add($array_image_map_hpp[3]);
				$image_hpp->AddLINE('');
				$image_hpp->AddTEXT(<<END
			};
			static constexpr UINT8	stacui8nVBlockBit[]={
END
				);
				#	第5ブロック「ブロックサイズ列挙」/MAP
				$image_hpp->Add($array_image_map_hpp[4]);
				$image_hpp->AddLINE('');
				$image_hpp->AddTEXT(<<END
			};
			static constexpr IDPATTERN	SPRITE_acidPattern[]={
END
				);
				#	第6ブロック「SPRITEパターンID列挙」/MAP
				$image_hpp->Add($array_image_map_hpp[5]);
				$image_hpp->AddLINE('');
				$image_hpp->AddTEXT(<<END
			};
			static constexpr IDPATTERN	BG1_acidPattern[]={
END
				);
				#	第7ブロック「BG1パターンID列挙」/MAP
				$image_hpp->Add($array_image_map_hpp[6]);
				$image_hpp->AddLINE('');
				$image_hpp->AddTEXT(<<END
			};
			static constexpr IDPALETTE	SPRITE_acidPalette[]={
END
				);
				#	第8ブロック「SPRITEパレットID列挙」/MAP
				$image_hpp->Add($array_image_map_hpp[7]);
				$image_hpp->AddLINE('');
				$image_hpp->AddTEXT(<<END
			};
			static constexpr IDPALETTE	BG1_acidPalette[]={
END
				);
				#	第9ブロック「BG1パレットID列挙」/MAP
				$image_hpp->Add($array_image_map_hpp[8]);
				$image_hpp->AddLINE('');
				$image_hpp->AddTEXT(<<END
			};
		};
END
				);
			}
			if($array_image_back_hpp[1]->GetSize()){
				#	クラス宣言/BACK
				$image_hpp->AddTEXT(<<END

		//
		//		class:BACK
		//

		class BACK{
		public:

			//
			//		const
			//

END
				);
				#	第2ブロック「アドレス、サイズ設定本体」/BACK
				&USR_Align($image_bin,$in_back_topalign);
				$image_hpp->AddLINE(sprintf(
					"\t\t\tstatic constexpr UINT32\tstcui32iBaseAddressS=\t\t\t\t\t\t\tstcui32iAddressS+0x%06x;",
					$image_bin->GetCurrent()
				));
				$image_hpp->Add($array_image_back_hpp[1]);
				$image_bin->Add($image_back_bin);
				$image_hpp->AddTEXT(<<END
			static constexpr UINT32	stacui32iAddressS[]={
END
				);
				#	第3ブロック「アドレス列挙」/BACK
				$image_hpp->Add($array_image_back_hpp[2]);
				$image_hpp->AddLINE('');
				$image_hpp->AddTEXT(<<END
			};
			static constexpr UINT32	stacui32nSize[]={
END
				);
				#	第4ブロック「サイズ列挙」/BACK
				$image_hpp->Add($array_image_back_hpp[3]);
				$image_hpp->AddLINE('');
				$image_hpp->AddTEXT(<<END
			};
			static constexpr UINT8	stacui8nVBlockBit[]={
END
				);
				#	第5ブロック「ブロックサイズ列挙」/BACK
				$image_hpp->Add($array_image_back_hpp[4]);
				$image_hpp->AddLINE('');
				$image_hpp->AddTEXT(<<END
			};
			static constexpr IDPATTERN	BG3_acidPattern[]={
END
				);
				#	第6ブロック「BG3パターンID列挙」/BACK
				$image_hpp->Add($array_image_back_hpp[5]);
				$image_hpp->AddLINE('');
				$image_hpp->AddTEXT(<<END
			};
			static constexpr IDPALETTE	BG3_acidPalette[]={
END
				);
				#	第7ブロック「BG3パレットID列挙」/BACK
				$image_hpp->Add($array_image_back_hpp[6]);
				$image_hpp->AddLINE('');
				$image_hpp->AddTEXT(<<END
			};
		};
END
				);
			}
			if($image_patternchr_hpp->GetSize()){
				#	クラス宣言/PATTERNCHR
				$image_hpp->AddTEXT(<<END

		//
		//		class:PATTERNCHR
		//

		class PATTERNCHR{
		public:

			//
			//		const
			//

END
				);
				#	第2ブロック「サイズ設定本体」/PATTERNCHR
				$image_hpp->Add($image_patternchr_hpp);
				$image_hpp->AddTEXT(<<END
		};
END
				);
			}
			if($array_image_pattern_hpp[1]->GetSize()){
				#	クラス宣言/PATTERN
				$image_hpp->AddTEXT(<<END

		//
		//		class:PATTERN
		//

		class PATTERN{
		public:

			//
			//		const
			//

END
				);
				#	第2ブロック「アドレス、サイズ設定本体」/PATTERN
				$image_hpp->AddLINE(sprintf("\t\t\tstatic constexpr UINT32\tstcui32iBaseAddressS=\t\t\t\t\t\t\tstcui32iAddressS+0x%06x;",$image_bin->GetCurrent()));
				$image_hpp->Add($array_image_pattern_hpp[1]);
				$image_bin->Add($image_pattern_bin);
				$image_hpp->AddTEXT(<<END
			static constexpr UINT32	stacui32iAddressS[]={
END
				);
				#	第3ブロック「アドレス列挙」/PATTERN
				$image_hpp->Add($array_image_pattern_hpp[2]);
				$image_hpp->AddLINE('');
				$image_hpp->AddTEXT(<<END
			};
			static constexpr UINT32	stacui32nSize[]={
END
				);
				#	第4ブロック「サイズ列挙」/PATTERN
				$image_hpp->Add($array_image_pattern_hpp[3]);
				$image_hpp->AddLINE('');
				$image_hpp->AddTEXT(<<END
			};
		};
END
				);
			}
			if($array_image_palette_hpp[1]->GetSize()){
				#	クラス宣言/PALETTE
				$image_hpp->AddTEXT(<<END

		//
		//		class:PALETTE
		//

		class PALETTE{
		public:

			//
			//		const
			//

END
				);
				#	第2ブロック「アドレス、サイズ設定本体」/PALETTE
				$image_hpp->AddLINE(sprintf("\t\t\tstatic constexpr UINT32\tstcui32iBaseAddressS=\t\t\t\t\t\t\tstcui32iAddressS+0x%06x;",$image_bin->GetCurrent()));
				$image_hpp->Add($array_image_palette_hpp[1]);
				$image_bin->Add($image_palette_bin);
				$image_hpp->AddTEXT(<<END
			static constexpr UINT32	stacui32iAddressS[]={
END
				);
				#	第3ブロック「アドレス列挙」/PALETTE
				$image_hpp->Add($array_image_palette_hpp[2]);
				$image_hpp->AddLINE('');
				$image_hpp->AddTEXT(<<END
			};
			static constexpr UINT32	stacui32nSize[]={
END
				);
				#	第4ブロック「サイズ列挙」/PALETTE
				$image_hpp->Add($array_image_palette_hpp[3]);
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
	}
}

sub USR_Align{
	my($image_this,$inalign)=@_;
	my($insize)=$image_this->GetCurrent();
	my($infragment)=$insize&($inalign-1);

	if(0<$infragment){
		$image_this->SetCurrent($insize+$inalign-$infragment);
	}
	return;
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
	return sort{
		my($sfile_a)=BASE::STRING_GetFile($a);
		my($sfile_b)=BASE::STRING_GetFile($b);

		#	ファイル名のカッコ部分は「違い」と見なしたくないので削除
		$sfile_a=~s/\([\S\s]*\)//g;
		$sfile_b=~s/\([\S\s]*\)//g;
		if($sfile_a ne $sfile_b){
			#	ディレクトリ階層が深かろうが浅かろうが、まずファイル名でソートする
			return ($sfile_a cmp $sfile_b);
		}else{
			#	ファイル名が同じなら、ディレクトリ名含めて比較
			return ($a cmp $b);
		}
	}@array_sfilesource;
}

sub USR_ExtractName{
	my($sfile)=@_;
	my($soption);

	if($sfile=~/([^\(\)]+)\(([^\(\)]+)\)/){
		$sfile=$1;
		$soption=" $2";
	}
	{
		my($sname,$ssubname)=split(/_/,$sfile,2);

		#	ソート用の文字が先頭に付与されていたなら除去
		if($sname=~/^\d+/){
			($sname,$ssubname)=split(/_/,$ssubname,2);
		}
		if($ssubname ne ''){
			$ssubname="_$ssubname";
		}
		return ("$sname$ssubname",$soption);
	}
}

sub USR_itimestampEntry{
	my(
		$sname,
		$image_bin,$ref_array_image_hpp,$imagechr_hpp,$sfiledestination,$svariable,$sbasevariable,
		$image_addition_bin,$ref_array_image_addition_hpp,$imagechr_addition_hpp,$sfiledestination_addition,$svariable_addition,$sbasevariable_addition,
		$sfilesource,
		$scommand,
		$ref_in_topalign
	)=@_;
	my($itimestampdestination)=&USR_itimestampMake($sfiledestination,$sfiledestination_addition,$sfilesource,$scommand);
	my($sub_block1)=sub{
		#	第1ブロック「識別子列挙」
		if($$ref_array_image_hpp[0]->GetCurrent()){
			$$ref_array_image_hpp[0]->AddLINE(',');
		}
		$$ref_array_image_hpp[0]->AddTEXT("\t\t\t\t$svariable");
		return;
	};
	my($sub_block2)=sub{
		#	第2ブロック「アドレス」
		$$ref_array_image_hpp[1]->AddLINE(
			"\t\t\t".&USR_sTabLeft(
				"static constexpr UINT32\t${svariable}_stcui32iAddressS=",18
			).sprintf("stcui32iBaseAddressS+0x%06x;",$image_bin->GetCurrent())
		);
		return;
	};

	$sub_block1->();
	if($sbasevariable eq 'PATTERN'){
		$sub_block2->();
		#	第2ブロック「サイズ設定本体」
		$imagechr_hpp->AddLINE(
			"\t\t\t".&USR_sTabLeft(
				"static constexpr UINT16\t${svariable}_stcui16nSize=",18
			).sprintf("0x%04x;",BASE::GetFileSize($sfiledestination)>>5)
		);
		#	第2ブロック「PATTERNCHR」
		$$ref_array_image_hpp[1]->AddLINE(
			"\t\t\t".&USR_sTabLeft(
				"static constexpr UINT32\t${svariable}_stcui32nSize=",18
			)."UINT32(PATTERNCHR::${svariable}_stcui16nSize)<<5;"
		);
	}else{
		my($sub_block25)=sub{
			my($inheight)=@_;
			my($inheightbit)=0;

			while((1<<$inheightbit)<$inheight){
				++$inheightbit;
			}
			{
				my($inalign)=256<<$inheightbit;

				&USR_Align($image_bin,$inalign);
				if(defined $ref_in_topalign){
					if(not defined $$ref_in_topalign){
						$$ref_in_topalign=$inalign;
					}
				}
			}
			$sub_block2->();
			#	第2ブロック「サイズ設定本体」
			$$ref_array_image_hpp[1]->AddLINE(
				"\t\t\t".&USR_sTabLeft(
					"static constexpr UINT32\t${svariable}_stcui32nSize=",18
				).sprintf("0x%06x;",BASE::GetFileSize($sfiledestination))
			);
			#	第2ブロック「VBlockBit」
			$$ref_array_image_hpp[1]->AddLINE(
				"\t\t\t".&USR_sTabLeft(
					"static constexpr UINT8\t${svariable}_stcui8nVBlockBit=",18
				).sprintf("%d;",$inheightbit)
			);
			#	第5ブロック「ブロックサイズ列挙」
			if($$ref_array_image_hpp[4]->GetCurrent()){
				$$ref_array_image_hpp[4]->AddLINE(',');
			}
			$$ref_array_image_hpp[4]->AddTEXT("\t\t\t\t${svariable}_stcui8nVBlockBit");
			return;
		};

		if($sbasevariable eq 'MAP'){
			my($image_source);

			$image_source=new BASE_IMAGE::($sfilesource);
			$image_source->SetCurrent(0);
			while(defined ($_=$image_source->GetLINE())){
				if(/\<layer\s+id\=\"(\d+)"\s+name\=\"(\S+)\"\s+width\=\"(\d+)\"\s+height\=\"(\d+)\"/){
					my($icid,$sname,$inwidth,$inheight)=($1,$2,$3,$4);

					$sub_block25->($inheight);
					#	第6ブロック「SPRITEパターンID列挙」
					if($$ref_array_image_hpp[5]->GetCurrent()){
						$$ref_array_image_hpp[5]->AddLINE(',');
					}
					$$ref_array_image_hpp[5]->AddTEXT("\t\t\t\tIDPATTERN::SPRITE_${svariable}");
					#	第7ブロック「BG1パターンID列挙」
					if($$ref_array_image_hpp[6]->GetCurrent()){
						$$ref_array_image_hpp[6]->AddLINE(',');
					}
					$$ref_array_image_hpp[6]->AddTEXT("\t\t\t\tIDPATTERN::BG1_${svariable}");
					#	第8ブロック「SPRITEパレットID列挙」
					if($$ref_array_image_hpp[7]->GetCurrent()){
						$$ref_array_image_hpp[7]->AddLINE(',');
					}
					$$ref_array_image_hpp[7]->AddTEXT("\t\t\t\tIDPALETTE::SPRITE_${svariable}");
					#	第9ブロック「BG1パレットID列挙」
					if($$ref_array_image_hpp[8]->GetCurrent()){
						$$ref_array_image_hpp[8]->AddLINE(',');
					}
					$$ref_array_image_hpp[8]->AddTEXT("\t\t\t\tIDPALETTE::BG1_${svariable}");
					last;
				}
			}
		}elsif($sbasevariable eq 'BACK'){
			my($image_source);

			$image_source=new BASE_IMAGE::($sfilesource);
			$image_source->SetCurrent(0);
			while(defined ($_=$image_source->GetLINE())){
				if(/\<layer\s+id\=\"(\d+)"\s+name\=\"(\S+)\"\s+width\=\"(\d+)\"\s+height\=\"(\d+)\"/){
					my($icid,$sname,$inwidth,$inheight)=($1,$2,$3,$4);

					$sub_block25->($inheight);
					#	第6ブロック「BG3パターンID列挙」
					if($$ref_array_image_hpp[5]->GetCurrent()){
						$$ref_array_image_hpp[5]->AddLINE(',');
					}
					$$ref_array_image_hpp[5]->AddTEXT("\t\t\t\tIDPATTERN::BG3_${svariable}");
					#	第7ブロック「BG3パレットID列挙」
					if($$ref_array_image_hpp[6]->GetCurrent()){
						$$ref_array_image_hpp[6]->AddLINE(',');
					}
					$$ref_array_image_hpp[6]->AddTEXT("\t\t\t\tIDPALETTE::BG3_${svariable}");
					last;
				}
			}
		}
	}
	#	第3ブロック「アドレス列挙」
	if($$ref_array_image_hpp[2]->GetCurrent()){
		$$ref_array_image_hpp[2]->AddLINE(',');
	}
	$$ref_array_image_hpp[2]->AddTEXT("\t\t\t\t${svariable}_stcui32iAddressS");
	#	第4ブロック「サイズ列挙」
	if($$ref_array_image_hpp[3]->GetCurrent()){
		$$ref_array_image_hpp[3]->AddLINE(',');
	}
	$$ref_array_image_hpp[3]->AddTEXT("\t\t\t\t${svariable}_stcui32nSize");
	$image_bin->Add(new BASE_IMAGE::($sfiledestination));
	if($sfiledestination_addition ne ''){
		#	第1ブロック「識別子列挙」
		if($$ref_array_image_addition_hpp[0]->GetCurrent()){
			$$ref_array_image_addition_hpp[0]->AddLINE(',');
		}
		$$ref_array_image_addition_hpp[0]->AddTEXT("\t\t\t\t$svariable_addition");
		#	第2ブロック「アドレス、サイズ設定本体」
		$$ref_array_image_addition_hpp[1]->AddLINE(
			"\t\t\t".&USR_sTabLeft(
				"static constexpr UINT32\t${svariable_addition}_stcui32iAddressS=",18
			).sprintf("stcui32iBaseAddressS+0x%06x;",$image_addition_bin->GetCurrent())
		);
		$$ref_array_image_addition_hpp[1]->AddLINE(
			"\t\t\t".&USR_sTabLeft(
				"static constexpr UINT32\t${svariable_addition}_stcui32nSize=",18
			).sprintf("0x%06x;",BASE::GetFileSize($sfiledestination_addition))
		);
		$image_addition_bin->Add(new BASE_IMAGE::($sfiledestination_addition));
		#	第3ブロック「アドレス列挙」
		if($$ref_array_image_addition_hpp[2]->GetCurrent()){
			$$ref_array_image_addition_hpp[2]->AddLINE(',');
		}
		$$ref_array_image_addition_hpp[2]->AddTEXT("\t\t\t\t${svariable_addition}_stcui32iAddressS");
		#	第4ブロック「サイズ列挙」
		if($$ref_array_image_addition_hpp[3]->GetCurrent()){
			$$ref_array_image_addition_hpp[3]->AddLINE(',');
		}
		$$ref_array_image_addition_hpp[3]->AddTEXT("\t\t\t\t${svariable_addition}_stcui32nSize");
	}
	return $itimestampdestination;
}

sub USR_itimestampMake{
	my($sfiledestination,$sfiledestination_addition,$sfilesource,$scommand)=@_;
	my($itimestampdestination)=BASE::GetFileTimeStamp($sfiledestination);
	my($itimestampsource)=BASE::GetFileTimeStamp($sfilesource);

	if($sfiledestination_addition ne ''){
		my($itimestampdestination_addition)=BASE::GetFileTimeStamp($sfiledestination_addition);

		if(
			(not defined $itimestampdestination)||($itimestampdestination<$itimestampsource)||
			(not defined $itimestampdestination_addition)||($itimestampdestination_addition<$itimestampsource)
		){
			BASE::Print(`$scommand \"$sfilesource\" -o \"$sfiledestination\" -op \"$sfiledestination_addition\"`);
			$itimestampdestination=BASE::Maximum(
				BASE::GetFileTimeStamp($sfiledestination),
				BASE::GetFileTimeStamp($sfiledestination_addition)
			);
		}
	}else{
		if(
			(not defined $itimestampdestination)||($itimestampdestination<$itimestampsource)
		){
			BASE::Print(`$scommand \"$sfilesource\" -o \"$sfiledestination\"`);
			$itimestampdestination=BASE::GetFileTimeStamp($sfiledestination);
		}
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
