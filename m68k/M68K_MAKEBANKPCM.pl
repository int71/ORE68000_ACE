#!/usr/bin/perl
##############################################################################
##																			##
##																			##
##									M68K									##
##																			##
##	'M68K_MAKEBANKPCM.pl'							2025 written by int71	##
##############################################################################
use strict;
use XML::Parser;
use MIME::Base64;
$INC[@INC]='/usr/local/ofw/lib';
require 'base.pl';
my($Version,$Date)=('1.01','2025/11/08');
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
	}
	{
		my($image,$error)=&USR_PCMBANK($source,\%switch);

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
	BASE::Print("M68K_MAKEBANKPCM Version $Version Release $Date Written by int71\n");
	return;
}

sub USR_help{
	BASE::Print(<<END
<概要>
  「.xml」PCM音色定義ファイルをORE68000 ACE音色データに変換します。

<書式>
$BASE::Self (入力) [-v] [-h] [-o (出力).bin] [-d]

<オプション>
-v: バージョンを表示します。
-h: このメッセージを表示します。
-o: 出力ファイル名を指定します。デフォルト値は「(入力).bin」です。
-d: 音色データの内容を表示します。
END
	);
	return;
}

sub USR_PCMBANK{
	my($source,$switch)=@_;
	my(@error);
	my($xml)=new XML::Parser::(Style=>'Tree');
	my($ref_array_xmltree_source)=$xml->parsefile($source);
	my($image_destination)=&USR_makeimage($$ref_array_xmltree_source[1],$switch);

	return $image_destination,\@error;
}

sub USR_makeimage{
	my($ref_array_xmltree,$switch)=@_;
	my($ref_array_xmltree_source)=&USR_maketree($ref_array_xmltree,$switch);
	my($image_destination)=new BASE_IMAGE::();
	my(%hash_sample_source);

	#	サンプル(音色データから参照するための辞書)
	{
		my($ref_hash_sample)=$$ref_array_xmltree_source{'PCM_Sample'};
		my($isample,$ssample);

		for($isample=0;$ssample=sprintf('_%02X',$isample),exists $$ref_hash_sample{$ssample};++$isample){
			my($ref_hash_sample_current)=$$ref_hash_sample{$ssample};
			my($sname)=$$ref_hash_sample_current{'Name'};

			$hash_sample_source{$sname}={};
			{
				my($ref_sample)=$hash_sample_source{$sname};

				$$ref_sample{'SampleStart'}=$$ref_hash_sample_current{'SampleStart'};
				$$ref_sample{'SampleLength'}=$$ref_hash_sample_current{'SampleLength'};
				$$ref_sample{'SampleLoopLength'}=$$ref_hash_sample_current{'SampleLoopLength'};
				$$ref_sample{'Deceleration'}=$$ref_hash_sample_current{'Deceleration'};
				$$ref_sample{'ToneAdjust'}=$$ref_hash_sample_current{'ToneAdjust'};
				$$ref_sample{'Denoise'}=($$ref_hash_sample_current{'DenoisePhaseKeep'} eq 'TRUE')?1:0;
				$$ref_sample{'Interpolation'}=($$ref_hash_sample_current{'Interpolation'} eq 'None')?0:(
					($$ref_hash_sample_current{'Interpolation'} eq 'Linear')?1:(
						($$ref_hash_sample_current{'Interpolation'} eq 'Reserved0')?2:3
					)
				);
			}
		}
	}
	#	音色
	{
		my($ref_hash_program)=$$ref_array_xmltree_source{'PCM_Program'};
		my($iprogram);

		for($iprogram=0;$iprogram<128;++$iprogram){
			my($sprogram)=sprintf('_%02X',$iprogram);
			my($ref_hash_program_current)=$$ref_hash_program{$sprogram};
			my($ref_hash_sample_current)=$hash_sample_source{$$ref_hash_program_current{'Sample'}};
			my(
				$attackrate,
				$decay1rate,
				$decay2rate,
				$releaserate,
				$decaylevel,
				$totallevel,
				$keyscale,
				$multiply,
				$detunefine,
				$detunerough,
				$samplestart,
				$samplelength,
				$samplelooplength,
				$deceleration,
				$toneadjust,
				$denoise,
				$interpolation
			)=(
				$$ref_hash_program_current{'AttackRate'},
				$$ref_hash_program_current{'Decay1Rate'},
				$$ref_hash_program_current{'Decay2Rate'},
				$$ref_hash_program_current{'ReleaseRate'},
				$$ref_hash_program_current{'DecayLevel'},
				$$ref_hash_program_current{'TotalLevel'},
				$$ref_hash_program_current{'KeyScale'},
				$$ref_hash_program_current{'Multiply'},
				$$ref_hash_program_current{'DetuneFine'},
				$$ref_hash_program_current{'DetuneRough'},
				$$ref_hash_sample_current{'SampleStart'},
				$$ref_hash_sample_current{'SampleLength'},
				$$ref_hash_sample_current{'SampleLoopLength'},
				$$ref_hash_sample_current{'Deceleration'},
				$$ref_hash_sample_current{'ToneAdjust'},
				$$ref_hash_sample_current{'Denoise'},
				$$ref_hash_sample_current{'Interpolation'}
			);

			$image_destination->SetCurrent($iprogram<<4);
			$image_destination->SetBYTE((($interpolation&3)<<4)|($deceleration&15));	#	ChnInterpolation2Deceleration4
			$image_destination->SetBYTE((($detunefine&7)<<4)|($multiply&15));			#	ChnDetuneFine3Multiply4
			$image_destination->SetBYTE($totallevel&127);								#	ChnTotalLevel7
			$image_destination->SetBYTE((($keyscale&3)<<6)|($attackrate&31));			#	ChnKeyScale2AttackRate5
			$image_destination->SetBYTE($decay1rate&31);								#	ChnDecay1Rate5
			$image_destination->SetBYTE((($detunerough&3)<<6)|($decay2rate&31));		#	ChnDetuneRough2Decay2Rate5
			$image_destination->SetBYTE((($decaylevel&15)<<4)|($releaserate&15));		#	ChnDecayLevel4ReleaseRate4
			#	0x80:eDenoise※ドライバ側でわざわざOR演算しないで済むよう、音色データ時点で埋め込んでおく
			#	0x40:eDenoisePhaseKeep
			#	0x08:eKeyOn
			$image_destination->SetBYTE(0x80|(($denoise&1)<<6));						#	Key
			$image_destination->SetBYTE(($samplestart>>8)&255);							#	ChnSampleStart8
			$image_destination->SetBYTE($samplestart&255);								#	ChnSampleStartFine8
			$image_destination->SetBYTE(($samplelength>>8)&255);						#	ChnSampleLength8
			$image_destination->SetBYTE($samplelength&255);								#	ChnSampleLengthFine8
			$image_destination->SetBYTE(($samplelooplength>>8)&255);					#	ChnSampleLoopLength8
			$image_destination->SetBYTE($samplelooplength&255);							#	ChnSampleLoopLengthFine8
			$image_destination->SetBYTE(($toneadjust>>8)&255);							#	ToneAdjust(H)
			$image_destination->SetBYTE($toneadjust&255);								#	ToneAdjust(L)
		}
	}
	#	波形メモリ
	{
		my($ref_hash_memory)=$$ref_array_xmltree_source{'PCM_Sample'}{'Image'};
		my($isource,$ssource);
		my($smemory);

		$image_destination->SetCurrent();
		$smemory='';
		for($isource=0;$ssource=sprintf('_%03X',$isource),exists $$ref_hash_memory{$ssource};++$isource){
			$smemory.=$$ref_hash_memory{$ssource};
		}
		$image_destination->SetFREE(MIME::Base64::decode_base64($smemory),0x00800);
	}
	$image_destination->SetSize(0x10800);
	return $image_destination;
}

sub USR_maketree{
	my($ref_array_xmltree,$switch)=@_;

	if(exists $$ref_array_xmltree[0]{'value'}){
		return $$ref_array_xmltree[0]{'value'};
	}
	{
		my($nbody)=scalar(@$ref_array_xmltree);
		my($nsub)=(7<=$nbody)?($nbody-3)>>2:0;
		my(%image);
		my($isub);

		for($isub=0;$isub<$nsub;++$isub){
			my($itree_base)=($isub<<2)+3;
			my($ssub,$ref_array_xmltree_sub)=($$ref_array_xmltree[$itree_base+0],$$ref_array_xmltree[$itree_base+1]);

			$image{$ssub}=&USR_maketree($ref_array_xmltree_sub,$switch);
		}
		return \%image;
	}
}

sub USR_Error{
	my($error,$message)=@_;

	push(@$error,$message);
	return;
}
