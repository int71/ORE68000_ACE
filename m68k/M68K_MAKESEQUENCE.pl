#!/usr/bin/perl
##############################################################################
##																			##
##																			##
##									M68K									##
##																			##
##	'M68K_MAKESEQUENCE.pl'							2025 written by int71	##
##############################################################################
use strict;
$INC[@INC]='/usr/local/ofw/lib';
require 'base.pl';
my($Version,$Date)=('2.71','2025/11/08');
new BASE::();

sub main{
	my($argument,$option)=@_;
	my($source,$destination);

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
		my($image,$error)=&USR_MAKESEQUENCE(require $source);

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
	BASE::Print("M68K_MAKESEQUENCE Version $Version Release $Date Written by int71\n");
	return;
}

sub USR_help{
	BASE::Print(<<END
<概要>
  演奏記述テキストファイルをORE68000(ACE)演奏データに変換します。

<書式>
$BASE::Self (入力) [-v] [-h] [-o (出力).bin] [-d]

<オプション>
-v: バージョンを表示します。
-h: このメッセージを表示します。
-o: 出力ファイル名を指定します。デフォルト値は「(入力).bin」です。
-d: 演奏データの内容を表示します。

<「(入力)」について>
  「(入力)」はPerlスクリプトで、演奏指示を文字列配列参照として記述します。
  Perlスクリプトであるので、変数、コメントの記述方法もPerlのそれに準じます。

    --------サンプルここから--------
    \$PG='PG=5';
    [
        #	コメント
        "#CHANNEL=FM5/FM6/FM7,SPEED=32,TRANSPOSE=0",
        "4E,\$PG,VL=255,PN=0,PT=+3&2,DT=0,PM=0/4G,\$PG,VL=255,PN=0,PT=+0,DT=0,PM=0",
        "+G / B"
    ];
    --------サンプルここまで--------

  演奏記述テキストは、1文字列中の「/」区切りでチャンネル毎の演奏指示、文字列の配列並びで時系列を表現します。
  以降、配列(インデックス)の単位を「時間単位」と表記します。
  1文字列が「#」で始まると制御文として解釈されます。
  制御文は「時間単位」として扱われず、経過時間は「0」です。

  演奏文、制御文は下記文法に従います。

    <書式>
    演奏文:[チャンネル文][/[チャンネル文]]...
      チャンネル文:(音符|休符|チャンネルパラメータ)[,チャンネルパラメータ...]
        音符:[+|-][オクターブ]ノート
          「+」を付与するとKeyOnによるエンベロープ変化を伴わない音程変更のみの指示となり、「-」を付与するとKeyOffしながらの音程変更指示となります。
          「オクターブ」は絶対値「0～7」、相対+1「>(複数可)」、相対-1「<(複数可)」の値を取り、指定以降、当該チャンネルのデフォルト値となります。
          指定が無い場合、初期値「4」、もしくは制御単文「OCTAVE」で指定される値となります。
          「ノート」は「C～B」で指定します。
          ポルタメント指定は「0」にリセットされます。
        休符:-
          KeyOff指示が行われます。
          ポルタメント指定は「0」にリセットされます。
        チャンネルパラメータ:
          VL=ノート音量値
            ノート単位の音量を指定します。
            「VM」で指定される「チャンネル音量値」とかけ合わせて実際の音量となります。
            「ノート音量値」は音量最小「0」、最大「255」で、「音量(dB)=(ノート音量値-255)*3/8」の関係があります。
            「ノート音量値」を始めとしたいくつかのパラメータは、明示的指定があっても値の変化が無い限り演奏データには出力されませんが、「ラベル名」設定以後の初回指定は、値に変化が無かろうと演奏データに出力されます。
          VM=チャンネル音量値
            チャンネル単位の音量を指定します。
            「VL」で指定される「ノート音量値」とかけ合わせて実際の音量となります。
            「チャンネル音量値」は音量最小「0」、最大「255」で、「音量(dB)=(チャンネル音量値-255)*3/8」の関係があります。
            演奏データ出力仕様は、「ノート音量値」のそれに準じます。
          PN=パン値
            左右定位を指定します。
            「パン値」は最左「-128」、中央「0」、最右「127」です。
            演奏データ出力仕様は、「ノート音量値」のそれに準じます。
          PT=((+|-)目標ノート差分値)|([オクターブ]目標ノート)[&時間単位数]
            ポルタメント(継続的音程変化)を指定します。
            相対的ノート番号数値による指定を行う場合、プラスマイナスの符号(必須)を付けて「目標ノート差分値」を記載します。
            「C」から「D」に変化させるなら「C→C#→D」で「+2」になります。
            ノート文字による指定を行う場合、「目標ノート」を「C～B#」で指定します。
            この時「オクターブ」指定も可能ですが、デフォルト値の変更は行いません。
            「時間単位数」は目標ノート到達までの時間で、1「時間単位」が16フレームであるなら、「時間単位数」*16フレーム後に目標ノートの音程に達する事になります。
            省略時は「1」となります。
            「音符」、「休符」指定によってポルタメント指定は「0」にリセットされます。
          DT=デチューン値
            音程調整を指定します。
            「デチューン値」は100/256セント単位で、「+256」を指定すると半音高い音となります。
            演奏データ出力仕様は、「ノート音量値」のそれに準じます。
          PM=ピッチモジュレーション深度値
            ピッチモジュレーションのかかり具合を指定します。
            「ピッチモジュレーション深度値」は音源毎の定義となります。
            FM音源(YM2151)の場合、「224」時「±700」セント、「192」時「±400」セントです。
            演奏データ出力仕様は、「ノート音量値」のそれに準じます。
          PG=音色番号
            音色を指定します。
            「音色番号」は「0」～「255」の値を取れます。
            演奏データ出力仕様は、「ノート音量値」のそれに準じます。
    制御文:#制御単文[,制御単文]...
      制御単文:
        CHANNEL=[チャンネル名][/[チャンネル名]]...
          「演奏文」中の「チャンネル文」がドライバ内のどのチャンネルに対応するかを指定します。
          「チャンネル名」には「FM0」～「FM7」を指定できます。
          デフォルト値は「FM0/FM1/FM2/FM3/FM4/FM5/FM6/FM7/PCM0/PCM1/PCM2/PCM3/PCM4/PCM5/PCM6/PCM7」です。
        LABEL=ラベル名
          演奏位置にラベルを付与します。
          「ラベル名」はアルファベットで表現され、ジャンプ(ループ)、コール(演奏パーツ呼び出し)先として使用できます。
          大文字、小文字は区別されます。
          チャンネルパラメータ補完は行わないので、「ジャンプ元状態に関わらずパラメータを一定にしたい」場合、明示的パラメータ指定が必要です。
        JUMP=ラベル名
          演奏位置を変更します。
          「ラベル名」は「LABEL」で定義しておく必要がありますが、定義位置は前方、後方いづれでも構いません。
          定義が無い場合、エラーとして標準出力に表示します。
        CALL=ラベル名
          現在演奏位置への復帰を前提として、演奏位置を変更します。
          「ラベル名」は「LABEL」で定義しておく必要がありますが、定義位置は前方、後方いづれでも構いません。
          定義が無い場合、エラーとして標準出力に表示します。
        RETURN
          最終「CALL」指示位置に復帰します。
        SPEED=単位フレーム数
          指定以降の「時間単位」の長さを指定します。
          「単位フレーム数」は演奏ドライバ実行間隔を「1」とする正の値です。
          通常「単位フレーム数」×「1/60」秒が「時間単位」の長さとなるでしょう。
          「10.5」等の小数点値も設定できますが、演奏データとしては整数区切り、例えば「10,11,10,11…」のように再現されます。
          デフォルト値は「64」です。
        TRANSPOSE=[+|-]移調値
          指定以降の調を指定します。
          「移調値」は半音を「1」とする符号付き整数です。
          デフォルト値は「0」です。
        OCTAVE=オクターブ値
          指定以降の全チャンネルのデフォルトオクターブを指定します。
          「オクターブ値」には「0」～「7」を指定します。
          デフォルト値は「4」です。
        PMSPEED=ピッチモジュレーション周波数
          指定以降のピッチモジュレーションの周波数を指定します。
          「ピッチモジュレーション周波数」は音源毎の定義となります。
          FM音源(YM2151)の場合、「0」時「0.0008」Hz、「255」時「59.8」Hzです。
          デフォルト値は音源毎の定義となり、FM音源(YM2151)の場合「0」です。
END
	);
	return;
}

sub USR_MAKESEQUENCE{
	my($source)=@_;
	my($image);
	my(@error);
	my(%label);
	my(@unresolved);

	$image=new BASE_IMAGE::();
	#	ラベル未解決のまま一通りスキャン
	{
		my(%hash_channelindex)=(
			'FM0'=>		 0,
			'FM1'=>		 1,
			'FM2'=>		 2,
			'FM3'=>		 3,
			'FM4'=>		 4,
			'FM5'=>		 5,
			'FM6'=>		 6,
			'FM7'=>		 7,
			'PCM0'=>	 8,
			'PCM1'=>	 9,
			'PCM2'=>	10,
			'PCM3'=>	11,
			'PCM4'=>	12,
			'PCM5'=>	13,
			'PCM6'=>	14,
			'PCM7'=>	15
		);
		my(%hash_noteindex)=(
			'C'=>		 0,
			'C#'=>		 1,
			'D'=>		 2,
			'D#'=>		 3,
			'E'=>		 4,
			'F'=>		 5,
			'F#'=>		 6,
			'G'=>		 7,
			'G#'=>		 8,
			'A'=>		 9,
			'A#'=>		10,
			'B'=>		11
		);
		my($line);
		my($lineno)=0;
		my($lengthunit_all)=64;
		my($transpose_all)=0;
		my(@array_channelindex);
		my(@array_octave_perchannel);
		my(@array_velocity_perchannel);
		my(@array_volume_perchannel);
		my(@array_pan_perchannel);
		my(@array_detune_perchannel);
		my(@array_pitchmodulation_perchannel);
		my(@array_program_perchannel);
		my(@array_lastnote_perchannel);
		my(@array_velocity_eundiscardable);
		my(@array_volume_eundiscardable);
		my(@array_pan_eundiscardable);
		my(@array_detune_eundiscardable);
		my(@array_pitchmodulation_eundiscardable);
		my(@array_program_eundiscardable);
		my($address_length_next);
		my($address_length_current);
		my($length_decimal);
		my($width_length_current);
		my($channel_progressing);
		my($terminated);
		my($sub_openchannelprogressing)=sub{
			if(!$channel_progressing){
				#	チャンネル系が新たに始まった
				$channel_progressing=1;
				$address_length_current=$address_length_next;
				#	一旦、可変長8bitとして仮決め
				$width_length_current=1;
				$address_length_next=$image->GetCurrent();
				&USR_Add($image,0);
			}
			return;
		};
		my($sub_closechannelprogressing)=sub{
			if($channel_progressing){
				#	チャンネル系がイベント無しで開きっぱなしだった
				$address_length_next=-1;
				$channel_progressing=0;
				&USR_Subtract($image);
			}
			return;
		};
		my($sub_getnote)=sub{
			my($source,$octave)=@_;

			if($source=~/([\+\-]?)([\d\>\<]*)([A-G]\#?)/){
				my($keep,$match_octave,$match_note)=($1,$2,$3);

				if($match_octave=~/(\d+)/){
					$$octave=$1;
				}
				{
					my($i);

					for($i=index($match_octave,'>');$i!=-1;$i=index($match_octave,'>',$i+1)){
						++$$octave;
					}
					for($i=index($match_octave,'<');$i!=-1;$i=index($match_octave,'<',$i+1)){
						--$$octave;
					}
				}
				if(defined $hash_noteindex{$match_note}){
					return $$octave*12+$hash_noteindex{$match_note},$keep;
				}else{
					&USR_Error(\@error,$lineno,"INVALID NOTE \"$source\" is found.");
				}
			}
			return undef,0;
		};
		my($sub_setundiscardable)=sub{
			my($eundiscardable)=@_;
			my($ichannel);

			for($ichannel=0;$ichannel<16;++$ichannel){
				$array_velocity_eundiscardable[$ichannel]=$eundiscardable;
				$array_volume_eundiscardable[$ichannel]=$eundiscardable;
				$array_pan_eundiscardable[$ichannel]=$eundiscardable;
				$array_detune_eundiscardable[$ichannel]=$eundiscardable;
				$array_pitchmodulation_eundiscardable[$ichannel]=$eundiscardable;
				$array_program_eundiscardable[$ichannel]=$eundiscardable;
			}
			return;
		};

		{
			my($octave_default)=4;
			my($note_default)=$octave_default*12+0;
			my($ichannel);

			for($ichannel=0;$ichannel<16;++$ichannel){
				$array_channelindex[$ichannel]=$ichannel;
				$array_octave_perchannel[$ichannel]=$octave_default;
				undef $array_velocity_perchannel[$ichannel];
				undef $array_volume_perchannel[$ichannel];
				undef $array_pan_perchannel[$ichannel];
				undef $array_detune_perchannel[$ichannel];
				undef $array_pitchmodulation_perchannel[$ichannel];
				undef $array_program_perchannel[$ichannel];
			}
			$sub_setundiscardable->(0);
		}
		$address_length_next=-1;
		$length_decimal=.0;
		$channel_progressing=0;
		foreach $line(@$source){
			$line=~s/\s+//g;
			$line=BASE::STRING_Upper($line);
			$terminated=0;
			if(substr($line,0,1) eq '#'){
				my($command);

				#	制御系
				foreach $command(split(/\,/,substr($line,1))){
					my($operator,$value)=split(/\=/,$command);

					if($operator eq 'CHANNEL'){
						my(@channelname)=split(/\//,$value);
						my($nchannel)=scalar(@channelname);
						my($ichannel_localindex);

						for($ichannel_localindex=0;$ichannel_localindex<$nchannel;++$ichannel_localindex){
							my($name)=$channelname[$ichannel_localindex];

							if(exists $hash_channelindex{$name}){
								$array_channelindex[$ichannel_localindex]=$hash_channelindex{$name};
							}
						}
					}elsif($operator eq 'LABEL'){
						#	ジャンプで飛んでくる可能性があるという事は、この時点で確定が必要
						$sub_closechannelprogressing->();
						$label{$value}=$image->GetCurrent();
						$sub_setundiscardable->(1);
					}elsif($operator eq 'JUMP'){
						$sub_closechannelprogressing->();
						&USR_Add($image,0x00,0x00,0x00,0x00);
						push(@unresolved,sprintf("%d:%08x:JUMP=%s",$lineno,$image->GetCurrent(),$value));
						#	直後のデータは演奏され得ないのでそのままデータ終了可
						$terminated=1;
					}elsif($operator eq 'CALL'){
						$sub_closechannelprogressing->();
						&USR_Add($image,0x00,0x40,0x00,0x00);
						push(@unresolved,sprintf("%d:%08x:CALL=%s",$lineno,$image->GetCurrent(),$value));
					}elsif($operator eq 'RETURN'){
						$sub_closechannelprogressing->();
						&USR_Add($image,0x00,0x80);
						#	直後のデータは演奏され得ないのでそのままデータ終了可
						$terminated=1;
					}elsif($operator eq 'SPEED'){
						$lengthunit_all=$value;
					}elsif($operator eq 'TRANSPOSE'){
						$transpose_all=$value;
					}elsif($operator eq 'OCTAVE'){
						foreach(@array_octave_perchannel){
							$_=$value;
						}
					}elsif($operator eq 'PMSPEED'){
						$sub_openchannelprogressing->();
						&USR_Add($image,0xf0,$value);
					}else{
						&USR_Error(\@error,$lineno,"UNKNOWN COMMAND \"$command\" is found.");
					}
				}
			}else{
				my(@channel)=split(/\//,$line);
				my($nchannel)=scalar(@channel);
				my($ichannel_localindex);

				$sub_openchannelprogressing->();
				#	チャンネル系
				for($ichannel_localindex=0;$ichannel_localindex<$nchannel;++$ichannel_localindex){
					my($ichannel)=$array_channelindex[$ichannel_localindex];
					my($channel)=$channel[$ichannel_localindex];
					my($nvolume);
					my($command);

					undef $nvolume;
					foreach $command(split(/\,/,$channel)){
						my($operator,$value)=split(/\=/,$command);

						$operator=BASE::STRING_Upper($operator);
						if(not defined $value){
							my($note,$keep)=$sub_getnote->($operator,\$array_octave_perchannel[$ichannel]);

							#	音符
							if(defined $note){
								if($keep eq ''){
									&USR_Add($image,0x00|$ichannel,$note+$transpose_all);
								}elsif($keep eq '+'){
									&USR_Add($image,0x20|$ichannel,$note+$transpose_all);
								}elsif($keep eq '-'){
									&USR_Add($image,0x30|$ichannel,$note+$transpose_all);
								}
								$array_lastnote_perchannel[$ichannel]=$note;
							}elsif($operator eq '-'){
								&USR_Add($image,0x10|$ichannel);
							}else{
								&USR_Error(\@error,$lineno,"INVALID NOTE \"$operator\" is found.");
							}
						}else{
							#	パラメータ
							if($operator eq 'VL'){
								#	ノート音量
								if(
									(not defined $array_velocity_perchannel[$ichannel])||
									($value!=$array_velocity_perchannel[$ichannel])||
									$array_velocity_eundiscardable[$ichannel]
								){
									$array_velocity_perchannel[$ichannel]=$value;
									$nvolume=$value+$array_volume_perchannel[$ichannel]-255;
									$array_velocity_eundiscardable[$ichannel]=0;
								}
							}elsif($operator eq 'VM'){
								#	チャンネル音量
								if(
									(not defined $array_volume_perchannel[$ichannel])||
									($value!=$array_volume_perchannel[$ichannel])||
									$array_volume_eundiscardable[$ichannel]
								){
									$array_volume_perchannel[$ichannel]=$value;
									$nvolume=$array_velocity_perchannel[$ichannel]+$value-255;
									$array_volume_eundiscardable[$ichannel]=0;
								}
							}elsif($operator eq 'PN'){
								#	パン
								if(
									(not defined $array_pan_perchannel[$ichannel])||
									($value!=$array_pan_perchannel[$ichannel])||
									$array_pan_eundiscardable[$ichannel]
								){
									$array_pan_perchannel[$ichannel]=$value;
									&USR_Add($image,0x50|$ichannel,$value);
									$array_pan_eundiscardable[$ichannel]=0;
								}
							}elsif($operator eq 'PT'){
								my($note,$unitspan)=split(/\&/,$value);

								#	ポルタメント
								if($note=~/[\+\-]\d+/){
									$note+=$array_lastnote_perchannel[$ichannel];
								}else{
									my($octave)=$array_octave_perchannel[$ichannel];

									#	ターゲットノートのオクターブ指定ではデフォルト値変えず
									($note,undef)=$sub_getnote->($note,\$octave);
								}
								if(not defined $unitspan){
									$unitspan=1;
								}
								if(defined $note){
									my($span)=$length_decimal+$unitspan*$lengthunit_all;
									my($tone_diff)=($note-$array_lastnote_perchannel[$ichannel])*256;
									my($portament)=BASE::Round($tone_diff/$span)&0xffff;

									&USR_Add($image,0x80|$ichannel,$portament>>8,$portament&0xff);
								}
							}elsif($operator eq 'DT'){
								#	デチューン
								if(
									(not defined $array_detune_perchannel[$ichannel])||
									($value!=$array_detune_perchannel[$ichannel])||
									$array_detune_eundiscardable[$ichannel]
								){
									$array_detune_perchannel[$ichannel]=$value;
									&USR_Add($image,0x90|$ichannel,$value>>8,$value&0xff);
									$array_detune_eundiscardable[$ichannel]=0;
								}
							}elsif($operator eq 'PM'){
								#	ピッチモジュレーション深度
								if(
									(not defined $array_pitchmodulation_perchannel[$ichannel])||
									($value!=$array_pitchmodulation_perchannel[$ichannel])||
									$array_pitchmodulation_eundiscardable[$ichannel]
								){
									$array_pitchmodulation_perchannel[$ichannel]=$value;
									&USR_Add($image,0xa0|$ichannel,$value);
									$array_pitchmodulation_eundiscardable[$ichannel]=0;
								}
							}elsif($operator eq 'PG'){
								#	プログラムチェンジ
								if(
									(not defined $array_program_perchannel[$ichannel])||
									($value!=$array_program_perchannel[$ichannel])||
									$array_program_eundiscardable[$ichannel]
								){
									$array_program_perchannel[$ichannel]=$value;
									&USR_Add($image,0xc0|$ichannel,$value);
									$array_program_eundiscardable[$ichannel]=0;
								}
							}else{
								&USR_Error(\@error,$lineno,"UNKNOWN COMMAND \"$command\" is found.");
							}
						}
					}
					if(defined $nvolume){
						#	「VL」、「VM」が連続したなら1つにまとめる
						&USR_Add(
							$image,0x40|$ichannel,
							($nvolume<0)?0:(
								(255<$nvolume)?255:$nvolume
							)
						);
					}
				}
				#	イベントがあったかどうかチェック
				if(
					($address_length_current==-1)||
					($address_length_next+1<$image->GetCurrent())
				){
					#	最初の行、フロー制御直後、もしくはイベントがあったなら、
					#	一旦イベントあり扱いで先に進める
					&USR_Add($image,0xff);
					$address_length_current=$address_length_next;
					$channel_progressing=0;
				}
				{
					my($address_save)=$image->GetCurrent();
					my($length,$length_encoded);
					my($width);

					#	SMF準拠可変長データとしてデコード
					$length=0;
					for($width=0;$width<$width_length_current;++$width){
						$length=($length<<7)|($image->GetBYTE($address_length_current+$width)&0x7f);
					}
					#	読み取った後、デフォルト長を加算(小数以下の端数も含める)
					$length+=$lengthunit_all+$length_decimal;
					$length_decimal=$length;
					$length=int($length);
					$length_decimal-=$length;
					#	SMF準拠可変長データとしてエンコード
					$length_encoded=0;
					for($width=0;0<$length;++$width){
						$length_encoded|=(($length&0x7f)|0x80)<<($width<<3);
						$length>>=7;
					}
					$length_encoded&=~0x80;
					{
						my($diff)=$width-$width_length_current;

						if(0<$diff){
							#	デフォルト長加算の結果、SMF準拠可変長データのサイズが変化
							$image->SetSubBody("\0"x$diff,0,$address_length_current);
							$address_save+=$diff;
							$address_length_next+=$diff;
							$width_length_current=$width;
						}
					}
					#	SMF準拠可変長データとして書き込み
					for($width=0;$width<$width_length_current;++$width){
						$image->SetBYTE(
							($length_encoded>>(($width_length_current-1-$width)<<3))&0xff,
							$address_length_current+$width
						);
					}
					$image->SetCurrent($address_save);
				}
			}
			++$lineno;
		}
		#	もしフロー制御無しで終了してたなら終了コードを追加
		if(!$terminated){
			if($address_length_current+2==$address_length_next){
				#	「一旦イベントあり扱い」とされていたもの
				$image->SetSize($address_length_current);
			}elsif($channel_progressing){
				#	チャンネル系がイベント無しで開きっぱなし、
				#	つまり「$address_length_next」が設定されている。
				#	これ以外はカットすべきデータが無い。
				$image->SetSize($address_length_next);
			}
			&USR_Add($image,0x00,0xff);
		}
	}
	#	ラベル解決
	{
		my($unresolved);

		foreach $unresolved(@unresolved){
			my($lineno,$address,$command)=split(/\:/,$unresolved);
			my($operator,$value)=split(/\=/,$command);

			$address=BASE::STRING_Hex2Num($address);
			if(defined $label{$value}){
				my($displacement)=$label{$value}-$address;

				$image->SetCurrent($address-3);
				if($operator eq 'JUMP'){
					&USR_Add($image,
						0x00|(($displacement>>16)&0x3f),
						($displacement>>8)&0xff,
						$displacement&0xff
					);
				}elsif($operator eq 'CALL'){
					&USR_Add($image,
						0x40|(($displacement>>16)&0x3f),
						($displacement>>8)&0xff,
						$displacement&0xff
					);
				}
			}else{
				&USR_Error(\@error,$lineno,"LABEL \"$value\" is NOT defined.");
			}
		}
	}
	return $image,\@error;
}

sub USR_Add{
	my($image,@code)=@_;
	my($code);

	foreach $code(@code){
		$image->SetBYTE($code&0xff);
	}
	return;
}

sub USR_Subtract{
	my($image)=@_;

	#	「-1」は「$sub_openchannelprogressing」内「&USR_Add($image,0)」の追加1バイトに対応
	$image->SetSize($image->GetCurrent()-1);
	return;
}

sub USR_Error{
	my($error,$lineno,$message)=@_;

	push(@$error,sprintf("%4d:%s",$lineno,$message));
	return;
}
