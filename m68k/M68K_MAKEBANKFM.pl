#!/usr/bin/perl
##############################################################################
##																			##
##																			##
##									M68K									##
##																			##
##	'M68K_MAKEBANKFM.pl'							2025 written by int71	##
##############################################################################
use strict;
$INC[@INC]='/usr/local/ofw/lib';
require 'base.pl';
my($Version,$Date)=('1.02','2025/11/08');
new BASE::();

sub main{
	my($argument,$option)=@_;
	my($source,$destination,%switch);

	if(defined $$option{'v'}){
		&USR_version();
		return 0;
	}elsif(defined $$option{'h'}){
		&USR_help();
		return 0;
	}else{
		if($$argument[0] ne ''){
			$source=$$argument[0];
		}else{
			&USR_help();
			return 0;
		}
		if($$option{'o'} ne ''){
			$destination=$$option{'o'};
			if(substr($destination,-4) eq '.bin'){
				$destination=substr($destination,0,length($destination)-4);
			}
		}else{
			$destination=$source;
		}
		if(defined $$option{'x'}){
			$switch{'HEX'}='';
		}
	}
	{
		my($image,$error)=&USR_BANKFM($source,\%switch);

		if(scalar(@$error)){
			foreach(@$error){
				BASE::Print("$_\n");
			}
		}else{
			if(defined $$option{'d'}){
				my($ndata)=$image->GetSize();
				my($idata);

				$image->SetCurrent(0);
				BASE::Print("       00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\n");
				BASE::Print("       -----------------------------------------------\n");
				for($idata=0;$idata<$ndata;++$idata){
					my($x)=$idata&0xf;

					if($x==0){
						BASE::Print(sprintf("%06X:",$idata));
					}
					BASE::Print(sprintf("%02X",$image->GetBYTE()));
					if($x<0xf){
						BASE::Print(' ');
					}else{
						BASE::Print("\n");
					}
				}
				if(0<($idata&0xf)){
					BASE::Print("\n");
				}
			}else{
				$image->Save("$destination.bin");
			}
		}
	}
	return 0;
}

sub USR_version{
	BASE::Print("M68K_MAKEBANKFM Version $Version Release $Date Written by int71\n");
	return;
}

sub USR_help{
	BASE::Print(<<END
<概要>
  「.opm」音色定義ファイルをORE68000(ACE)音色データに変換します。

<書式>
$BASE::Self (入力) [-v] [-h] [-o (出力).bin] [-x] [-d]

<オプション>
-v: バージョンを表示します。
-h: このメッセージを表示します。
-o: 出力ファイル名を指定します。デフォルト値は「(入力).bin」です。
-x: 音色番号を16進数として解釈します。
-d: 音色データの内容を表示します。
END
	);
	return;
}

sub USR_BANKFM{
	my($source,$switch)=@_;
	my($image_source,$image_destination);
	my(@error);
	my($line);

	$image_source=new BASE_IMAGE::($source);
	$image_source->SetCurrent(0);
	$image_destination=new BASE_IMAGE::();
	while(defined ($line=$image_source->GetLINE())){
		if($line=~/\@\:([0-9A-Fa-f]+)\s+([\S\s]+)/){
			my($index,$name)=($1,$2);

			if($$switch{'x'}){
				$index=BASE::STRING_Hex2Num($index);
			}
			$image_source->GetLINE();
			$image_destination->SetCurrent($index<<5);
			{
				my(undef,undef,$fb,$con)=split(/\s+/,$image_source->GetLINE());

				$image_destination->SetBYTE((($fb&7)<<3)|$con);
				$image_destination->SetBYTE(0);
				$image_destination->SetBYTE(0);
				$image_destination->SetBYTE(0);
				$image_destination->SetBYTE(0);
				$image_destination->SetBYTE(0);
				$image_destination->SetBYTE(0);
				$image_destination->SetBYTE(0);
			}
			{
				my(@ar,@d1r,@d2r,@rr,@d1l,@tl,@ks,@mul,@dt1,@dt2);
				my($operator);

				for($operator=0;$operator<4;++$operator){
					(
						undef,
						$ar[$operator],
						$d1r[$operator],
						$d2r[$operator],
						$rr[$operator],
						$d1l[$operator],
						$tl[$operator],
						$ks[$operator],
						$mul[$operator],
						$dt1[$operator],
						$dt2[$operator]
					)=split(/\s+/,$image_source->GetLINE());
				}
				$image_destination->SetBYTE((($dt1[0]&7)<<4)|($mul[0]&15));	#	DFMP-M1
				$image_destination->SetBYTE((($dt1[2]&7)<<4)|($mul[2]&15));	#	DFMP-M2
				$image_destination->SetBYTE((($dt1[1]&7)<<4)|($mul[1]&15));	#	DFMP-C1
				$image_destination->SetBYTE((($dt1[3]&7)<<4)|($mul[3]&15));	#	DFMP-C2
				$image_destination->SetBYTE(($tl[0]&127));					#	TL-M1
				$image_destination->SetBYTE(($tl[2]&127));					#	TL-M2
				$image_destination->SetBYTE(($tl[1]&127));					#	TL-C1
				$image_destination->SetBYTE(($tl[3]&127));					#	TL-C2
				$image_destination->SetBYTE((($ks[0]&3)<<6)|($ar[0]&31));	#	KSAR-M1
				$image_destination->SetBYTE((($ks[2]&3)<<6)|($ar[2]&31));	#	KSAR-M2
				$image_destination->SetBYTE((($ks[1]&3)<<6)|($ar[1]&31));	#	KSAR-C1
				$image_destination->SetBYTE((($ks[3]&3)<<6)|($ar[3]&31));	#	KSAR-C2
				$image_destination->SetBYTE(($d1r[0]&31));					#	AMSD1R-M1
				$image_destination->SetBYTE(($d1r[2]&31));					#	AMSD1R-M2
				$image_destination->SetBYTE(($d1r[1]&31));					#	AMSD1R-C1
				$image_destination->SetBYTE(($d1r[3]&31));					#	AMSD1R-C2
				$image_destination->SetBYTE((($dt2[0]&3)<<6)|($d2r[0]&31));	#	DRD2R-M1
				$image_destination->SetBYTE((($dt2[2]&3)<<6)|($d2r[2]&31));	#	DRD2R-M2
				$image_destination->SetBYTE((($dt2[1]&3)<<6)|($d2r[1]&31));	#	DRD2R-C1
				$image_destination->SetBYTE((($dt2[3]&3)<<6)|($d2r[3]&31));	#	DRD2R-C2
				$image_destination->SetBYTE((($d1l[0]&15)<<4)|($rr[0]&15));	#	DLRR-M1
				$image_destination->SetBYTE((($d1l[2]&15)<<4)|($rr[2]&15));	#	DLRR-M2
				$image_destination->SetBYTE((($d1l[1]&15)<<4)|($rr[1]&15));	#	DLRR-C1
				$image_destination->SetBYTE((($d1l[3]&15)<<4)|($rr[3]&15));	#	DLRR-C2
			}
		}
#		&USR_Error(\@error,$lineno,"LABEL \"$value\" is NOT defined.");
	}
	return $image_destination,\@error;
}

sub USR_Error{
	my($error,$lineno,$message)=@_;

	push(@$error,sprintf("%4d:%s",$lineno,$message));
	return;
}
