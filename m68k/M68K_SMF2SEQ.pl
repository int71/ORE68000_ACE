#!/usr/bin/perl
##############################################################################
##																			##
##																			##
##									M68K									##
##																			##
##	'M68K_SMF2SEQ.pl'								2026 written by int71	##
##############################################################################
use strict;
$INC[@INC]='/usr/local/ofw/lib';
require 'smf.pl';
my($sVersion,$sDate)=('2.44','2026/08/21');
my($COM_sDirectory)=('/d/Sync/Package/Cross/ORE68000_ACE/m68k');
my($sChannelAdditionalVariableName)=('_INIT');
new BASE::();

sub main{
	my($argument,$option)=@_;
	my($source,$destination,%switch);

	if(defined $$option{'v'}){
		&USR_stShowVersion();
		return 0;
	}elsif(defined $$option{'h'}){
		&USR_stShowHelp();
		return 0;
	}else{
		my(%hash_ichannel)=(
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

		if($$argument[0] ne ''){
			$source=$$argument[0];
		}else{
			&USR_stShowHelp();
			return 0;
		}
		if($$option{'o'} ne ''){
			$destination=$$option{'o'};
			if(substr($destination,-3) eq '.sh'){
				$destination=substr($destination,0,length($destination)-3);
			}
		}else{
			$destination=$source;
		}
		if(defined $$option{'u'}){
			$switch{'UnitperMeasureBeat'}=$$option{'u'};
		}else{
			$switch{'UnitperMeasureBeat'}=8;
		}
		if(defined $$option{'a'}){
			$switch{'ControlAdditional'}=$$option{'a'};
		}else{
			$switch{'ControlAdditional'}='';
		}
		if(defined $$option{'c'}){
			$switch{'ChannelAdditional'}=$$option{'c'};
		}else{
			$switch{'ChannelAdditional'}='';
		}
		if(defined $$option{'op'}){
			$switch{'ProgramOffset'}=$$option{'op'};
		}else{
			$switch{'ProgramOffset'}=0;
		}
		if(defined $$option{'ov'}){
			$_=$$option{'ov'};
			if(substr($_,0,1) eq '_'){
				$switch{'VolumeOffset'}=-(substr($_,1)+0);
			}else{
				$switch{'VolumeOffset'}=$_+0;
			}
		}else{
			$switch{'VolumeOffset'}=0;
		}
		if(defined $$option{'m'}){
			if($$option{'m'} ne '-'){
				$switch{'FixedPitchModulation'}=BASE::Fit($$option{'m'},0,127);
			}else{
				$switch{'FixedPitchModulation'}='';
			}
		}else{
			$switch{'FixedPitchModulation'}='';
		}
		if($$option{'z'} ne ''){
			$switch{'HeaderFrame'}=$$option{'z'}
		}else{
			$switch{'HeaderFrame'}=0;
		}
		if(defined $$option{'f'}){
			foreach(split(/\,/,$$option{'f'})){
				if(exists $hash_ichannel{$_}){
					$_=$hash_ichannel{$_};
				}else{
					$_+=0;
				}
				$switch{'FullOutChannel'}{$_}='';
			}
		}else{
			$switch{'FullOutChannel'}={};
		}
		if(defined $$option{'n'}){
			foreach(split(/\,/,$$option{'n'})){
				if(exists $hash_ichannel{$_}){
					$_=$hash_ichannel{$_};
				}else{
					$_+=0;
				}
				$switch{'ForcedChannel'}{$_}='';
			}
		}
		if(defined $$option{'r'}){
			$switch{'Replace'}=require $$option{'r'};
		}else{
			$switch{'Replace'}={};
		}
	}
	{
		my($img_destination)=&USR_stSMF2SEQ($source,\%switch);

		if(defined $$option{'d'}){
			my($line);

			$img_destination->SetCurrent(0);
			while(defined($line=$img_destination->GetLINE())){
				BASE::Print("$line\n");
			}
		}else{
			$img_destination->Save("$destination.sh");
		}
	}
	return 0;
}

sub USR_stShowVersion{
	BASE::Print("M68K_SMF2SEQ Version $sVersion Release $sDate Written by int71\n");
	return;
}

sub USR_stShowHelp{
	BASE::Print(<<END
<概要>
  「.mid」SMF形式ファイルを「M68K_MAKESEQUENCE」演奏テキストに変換します。

<書式>
$BASE::Self (入力).mid [-v] [-h] [-o (演奏テキスト).sh] [-u (音符長分母)] [-a (追加制御文)[,(追加制御文)...]] [-c (演奏データ)] [-op (プログラム番号オフセット)] [-ov (音量オフセット)] [-m (ピッチモジュレーション固定値)] [-z (初期フレーム数)] [-f (チャンネル)[,(チャンネル)...]] [-n (チャンネル)[,(チャンネル)...]] [-r (置換文字列定義)] [-d]

<オプション>
-v: バージョンを表示します。
-h: このメッセージを表示します。
-o: 「M68K_MAKESEQUENCE」準拠の演奏テキストファイル名を指定します。デフォルト値は「(入力).sh」です。
-u: 演奏テキストの「時間単位」とする「(音符長分母)」を指定します。デフォルト値は「8」、つまり1行が8分音符に対応します。
-a: 演奏テキスト冒頭に追加する制御文を指定します。「TRANSPOSE」、「PMSPEED」辺りが対象となるでしょう。
-c: 演奏テキスト冒頭に追加するチャンネル毎の演奏データを指定します。消音目的の音色設定+キーオン辺りが対象となるでしょう。
-op:プログラム(音色)番号にオフセット「(プログラム番号オフセット)」を与えます。デフォルト値は「0」です。
-ov:チャンネル音量(「VM=n」)にオフセット「(音量オフセット)」を与えます。
  「(音量オフセット)」は数値で指定しますが、「_数値」と表記するとマイナス値として扱います。
  デフォルト値は「0」です。
-m: 「0」以外のピッチモジュレーション値を「0～127」の値で固定します。デフォルト値は「-(固定無し)」です。
-z: 冒頭の無音時間フレーム数を指定します。「1」なら1フレームに切り詰めます。「2」以上を指定すると初期化が分散され、瞬間的負荷上昇を緩和できます。デフォルト値は「0(切り詰め無し)」です。
-f: 指定チャンネルについて、「KeyOn」時の無変化パラメータ省略を行わないようにします。
  「(チャンネル)」は数値「0～15」、もしくはチャンネル名「FM0～7」、「PCM0～7」で表記し、カンマ区切りで複数列挙できます。
  ドラムパートで指定すると演奏テキストで文字列置換しやすくなります。
  省略されなくなるパラメータは下記の通りです。

  ・オクターブ(相対指定「>」、「<」は使用しません)
  ・ノート音量(チャンネル音量は省略されます)
  ・プログラム番号
  ・パン
  ・ピッチモジュレーション

  ノート音量(「VL=n」)、チャンネル音量(「VM=n」)は省略されますが、列挙位置が末尾であるため、文字列置換を阻害しません。
-n: 出力対象を指定チャンネルに強制します。
  「(チャンネル)」は数値「0～15」、もしくはチャンネル名「FM0～7」、「PCM0～7」で表記し、カンマ区切りで複数列挙できます。
  「(入力).mid」出力時のワーク用チャンネルミュート忘れによる「想定外チャンネル出力」事故を避けたり、「-c」と組み合わせる事で、多チャンネル演奏からの切り替え時に「ゴミ」が残らないようにできます。
-r: 演奏テキストの置換文字列定義ファイル名を指定します。
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
-d: ファイルでなく標準出力に出力します。

<「(入力).mid」について>
  「KeyOff」は音符に重なりが無い場合にのみ置かれ、重なりがある場合は「継続的(アタック無し)KeyOn」とされます。

  「テンポ」は「3600/テンポ」で「4分音符当たりのフレーム数」に変換しますが、結果は「0.25」単位で量子化します。

  ピッチベンドが設定されていると下記手順でポルタメント指示に変換します。

  ・音程変化は直線と解釈
  ・傾きの変化は上昇下降だけで解釈し、上昇、下降中の傾き変化は一直線の変化と解釈
  ・傾き変化ポイントには適宜「継続的(アタック無し)KeyOn」を追加

  そしていくつか注意点があります。

  ・ピッチベンド編集点の解像度は16段階である
    SMFファイル出力元、もしくは規格の精度的都合による制限です。
    これ以上の段階が必要であれば、ピッチベンドセンシティビティの変更で対応してください。
  ・ピッチベンド編集点は「音程」である必要がある
    ピッチベンド値が「-1.0」、「.0」、「+1.0」であれば「音程」から外れる事はありませんが、例えば「RPN#0」でピッチベンドセンシティビティを「1」とした状態でピッチベンド値を「.5」とすると、半音の半分、つまり「1/4音」とでも言うべき音程となり、音符になりません。
    この時、演奏テキスト中には「近い音符」として記述され、精度が落ちる事になります。
  ・ピッチベンドセンシティビティはピッチベンド編集点で指定したい段階の倍数とする必要がある
    「ピッチベンド編集点は『音程』である必要がある」という事と同じ事を言っています。
    「音程」から外れないようにするため、自然と守らねばならないルールです。
  ・音符長最短は16分音符を目安に
    少なくとも64分音符だとピッチベンド情報の粒度が怪しくなります。
    ただし、「テンポ75で64分音符」で問題が起きても「テンポ300で16分音符」とすると解決する可能性があります。

  マーカーが設定されていると演奏テキストに「#LABEL=(マーカー名)」が出力され、「LoopEnd」マーカーは特別に「#JUMP=LoopStart」になり、ループ再生指示となります。
  「マーカーが設定されている箇所」は「移動先になり得る箇所」と見なされ、「マーカー以後の初回イベント」は、値に変化が無かろうとイベントとして出力されます。
  また、「#LABEL=LoopStart」位置にキーイベントが無く、かつ「#JUMP=LoopEnd」位置にキーオフイベントがあった場合、「音鳴りっぱなし」防止のため「#LABEL=LoopStart」位置にキーオフを補完します。

  「#JUMP=LoopStart」以降は再生されないため、演奏テキストを設定しても意味を持ちませんが、ループ先頭修正の参考にできるよう、コメント的に演奏テキストを出力します。

<「(演奏テキスト).sh」について>
  演奏テキスト上の演奏終端は「(入力).mid」の終端に合わせられますが、「KeyOff」などのイベントとタイミングが一致している場合、イベント所要フレームは「1」に補正されます。
END
	);
	return;
}

sub USR_stSMF2SEQ{
	my($source,$ref_switch)=@_;
	my($nunitpermeasurebeat)=$$ref_switch{'UnitperMeasureBeat'};
	my($ref_hash_fulloutchannel)=$$ref_switch{'FullOutChannel'};
	my($smf);
	my($nchannel);
	my($nmarker);
	my(@array_ref_line);
	my(@array_nvelocity_initial,@array_nvolume_initial,@array_iprogram_initial,@array_ipan_initial,@array_nmodulation_initial);
	my(@array_schannel)=(
		'FM0','FM1','FM2','FM3','FM4','FM5','FM6','FM7','PCM0','PCM1','PCM2','PCM3','PCM4','PCM5','PCM6','PCM7'
	);

	$smf=new SMF::($source);
	$nchannel=0;
	$nmarker=0;
	undef @array_ref_line;
	undef @array_nvelocity_initial,@array_nvolume_initial,@array_iprogram_initial,@array_ipan_initial,@array_nmodulation_initial;
	{
		my($nqnoteperunit)=4/$nunitpermeasurebeat;
		my($ntimeperunit)=$$smf{'Division'}*(4/$nunitpermeasurebeat);
		my(@array_nkeyon,@array_inote_last,@array_ioctave_last,@array_iprogram_last,@array_ipan_last,@array_nmodulation_last,@array_nvelocity_last,@array_nvolume_last,@array_rpn_inumber,@array_nrpn_inumber,@array_rpn_slastwritten,@array_pitchbend_ndepth);
		my(@array_eprogram_undiscardable,@array_epan_undiscardable,@array_emodulation_undiscardable,@array_evelocity_undiscardable,@array_evolume_undiscardable);
		my($nframeperunit);
		my($nunitpermeasure);
		my($ntimeperframe);
		my($itime_end);
		my($itime_measurestart,$itime_measureend,$itime_last);
		my($sub_addline)=sub{
			my($ref_array_event)=@_;

			if($itime_measureend<$itime_last+1){
				$itime_measurestart=$itime_measureend;
				$itime_measureend+=$ntimeperunit*$nunitpermeasure;
				push(@array_ref_line,{
					'Type'=>'Measure'
				});
			}
			push(@array_ref_line,{
				'Type'=>'Channel',
				'Frame'=>$nframeperunit,
				'Event'=>$ref_array_event
			});
			$itime_last+=$ntimeperunit;
			return;
		};
		my($ref_line_marker0,$ref_line_markerlast);

		#	SMFから読み込んで「@array_ref_line」を作る
		undef @array_nkeyon,@array_inote_last,@array_ioctave_last,@array_iprogram_last,@array_ipan_last,@array_nmodulation_last,@array_nvelocity_last,@array_nvolume_last,@array_rpn_inumber,@array_nrpn_inumber,@array_rpn_slastwritten,@array_pitchbend_ndepth;
		undef @array_eprogram_undiscardable,@array_epan_undiscardable,@array_emodulation_undiscardable,@array_evelocity_undiscardable,@array_evolume_undiscardable;
		$nframeperunit=0;
		$nunitpermeasure=$nunitpermeasurebeat;
		$ntimeperframe=0;
		$itime_end=0;
		$itime_measurestart=0;
		$itime_measureend=$itime_measurestart+$ntimeperunit*$nunitpermeasure;
		$itime_last=0;
		undef $ref_line_marker0,$ref_line_markerlast;
		while(1){
			#	$itime
			#		タイムスタンプです。
			#		「undef」でないならイベントありです。
			#	$ref_array_ref_array_ref_hash_event
			#		イベント情報を保持する、チャンネル配列です。
			my($itime,$ref_array_ref_array_ref_hash_event)=$smf->itime_ref_array_ref_array_ref_hash_eventGet();

			if(defined $itime){
				my(@array_ref_channel);
				my(@array_ckey,@array_cnote,@array_dportamentovalueperframe,@array_iprogram,@array_ipan,@array_nmodulation,@array_nvelocity,@array_nvolume);
				my($smarker);
				#	$ref_array_ref_hash_event
				#		チャンネル内の同時イベント配列です。
				#		「チャンネル内」とは言いつつ、データフォーマット的には別「MIDIチャンネル」のイベントも入り得ます。
				my($ref_array_ref_hash_event);

				#	イベントあり
				undef @array_ref_channel;
				undef @array_ckey,@array_cnote,@array_dportamentovalueperframe,@array_iprogram,@array_ipan,@array_nmodulation,@array_nvelocity,@array_nvolume;
				undef $smarker;
				#	データフォーマット的に別MIDIチャンネルのイベントも入り得る事から、
				#	最初に全チャンネル通しでイベント取得してしまいます。
				foreach $ref_array_ref_hash_event(@$ref_array_ref_array_ref_hash_event){
					#	$ref_hash_event
					#		イベント情報です。
					my($ref_hash_event);

					foreach $ref_hash_event(@$ref_array_ref_hash_event){
						if($$ref_hash_event{'Type'} eq 'KeyOff'){
							my($ichannel)=$$ref_hash_event{'Channel'};
							my($eoff);

							$eoff=0;
							if(defined $array_inote_last[$ichannel]){
								#	MIDI的には前の音の「KeyOff」、今回の音の「KeyOn」が同時イベントになりますが、
								#	「M68K_MAKESEQUENCE」フォーマットは「KeyOn」だけで良いので、適宜「KeyOff」を捨てます。
								#	ただし純然たる「KeyOff」はあり得るので、その場合は生かします。
								#	「$array_ckey」の存在チェックをしているのは、
								#	前の音の「KeyOff」が今回の音の「KeyOn」より後ろに来た場合に備えるためです。

								if($array_inote_last[$ichannel]==$$ref_hash_event{'Note'}){
									#	直前の「KeyOn」と音程が一致したので正常な「KeyOff」と解釈
									if(not defined $array_ckey[$ichannel]){
										$eoff=1;
									}
									undef $array_inote_last[$ichannel];
								}else{
									#	直前の「KeyOn」と音程が一致しなかったので次の「KeyOn」はアタック無し「KeyOn」に
									$array_inote_last[$ichannel]='';
								}
							}
							#	MIDIイベント的に全音「KeyOff」された場合は直前「KeyOn」との音程一致如何に因らず「KeyOff」する
							if(0<$array_nkeyon[$ichannel]){
								--$array_nkeyon[$ichannel];
							}
							if(($array_nkeyon[$ichannel]==0)||$eoff){
								if(exists $$ref_hash_event{'PitchBend'}){
									#	音程変化「KeyOff」と解釈
									($array_ckey[$ichannel],$array_cnote[$ichannel],$array_dportamentovalueperframe[$ichannel])=(
										'ON-',
										$$ref_hash_event{'Note_Friendly'},
										&USR_SMF2SEQ_stdPortamentoValueperTimefromPitchBend($ref_hash_event,$smf,$itime,$array_pitchbend_ndepth[$ichannel]/128)*$ntimeperframe
									);
								}else{
									($array_ckey[$ichannel],$array_dportamentovalueperframe[$ichannel])=(
										'OFF',
										&USR_SMF2SEQ_stdPortamentoValueperTimefromPitchBend($ref_hash_event,$smf,$itime,$array_pitchbend_ndepth[$ichannel]/128)*$ntimeperframe
									);
								}
								undef $array_inote_last[$ichannel];
							}
						}elsif($$ref_hash_event{'Type'} eq 'KeyOn'){
							my($ichannel)=$$ref_hash_event{'Channel'};
							my($ckey)='ON';

							if(defined $array_inote_last[$ichannel]){
								#	「KeyOff」されていないのでアタック無し「KeyOn」と解釈
								$ckey='ON+';
							}
							$array_inote_last[$ichannel]=$$ref_hash_event{'Note'};
							($array_ckey[$ichannel],$array_cnote[$ichannel],$array_nvelocity[$ichannel],$array_dportamentovalueperframe[$ichannel])=(
								$ckey,
								$$ref_hash_event{'Note_Friendly'},
								&USR_SMF2SEQ_stnDB2Value($$ref_hash_event{'Velocity_Friendly'}),
								&USR_SMF2SEQ_stdPortamentoValueperTimefromPitchBend($ref_hash_event,$smf,$itime,$array_pitchbend_ndepth[$ichannel]/128)*$ntimeperframe
							);
							if(!$$ref_hash_event{'AddedEvent'}){
								++$array_nkeyon[$ichannel];
							}
						}elsif($$ref_hash_event{'Type'} eq 'Control'){
							my($ichannel)=$$ref_hash_event{'Channel'};

							if($$ref_hash_event{'Type_Friendly'} eq 'Modulation'){
								my($value)=((BASE::Minimum($$ref_hash_event{'Value'}+1,127))>>3)&15;

								#	後勝ちにします。
								if(($value==0)||($$ref_switch{'FixedPitchModulation'} eq '')){
									($array_nmodulation[$ichannel])=($value<<3)|(($value>>1)&7);
								}else{
									($array_nmodulation[$ichannel])=$$ref_switch{'FixedPitchModulation'};
								}
							}elsif($$ref_hash_event{'TypeSub'}==0x06){
								if($array_rpn_slastwritten[$ichannel] eq 'NRPN'){
								}elsif($array_rpn_slastwritten[$ichannel] eq 'RPN'){
									if($array_rpn_inumber[$ichannel]==0){
										$array_pitchbend_ndepth[$ichannel]=($array_pitchbend_ndepth[$ichannel]&0x007f)|($$ref_hash_event{'Value'}<<7);
									}
								}
							}elsif($$ref_hash_event{'Type_Friendly'} eq 'Volume'){
								($array_nvolume[$ichannel])=(
									BASE::Fit(
										&USR_SMF2SEQ_stnDB2Value($$ref_hash_event{'Value_Friendly'})+$$ref_switch{'VolumeOffset'},
										0,
										255
									)
								);
							}elsif($$ref_hash_event{'Type_Friendly'} eq 'Pan'){
								($array_ipan[$ichannel])=(
									$$ref_hash_event{'Value_Friendly'}
								);
							}elsif($$ref_hash_event{'TypeSub'}==0x26){
								if($array_rpn_slastwritten[$ichannel] eq 'NRPN'){
								}elsif($array_rpn_slastwritten[$ichannel] eq 'RPN'){
									if($array_rpn_inumber[$ichannel]==0){
										$array_pitchbend_ndepth[$ichannel]=($array_pitchbend_ndepth[$ichannel]&0x3f80)|$$ref_hash_event{'Value'};
									}
								}
							}elsif($$ref_hash_event{'TypeSub'}==0x62){
								$array_nrpn_inumber[$ichannel]=($array_nrpn_inumber[$ichannel]&0x3f80)|$$ref_hash_event{'Value'};
								$array_rpn_slastwritten[$ichannel]='NRPN';
							}elsif($$ref_hash_event{'TypeSub'}==0x63){
								$array_nrpn_inumber[$ichannel]=($array_nrpn_inumber[$ichannel]&0x007f)|($$ref_hash_event{'Value'}<<7);
								$array_rpn_slastwritten[$ichannel]='NRPN';
							}elsif($$ref_hash_event{'TypeSub'}==0x64){
								$array_rpn_inumber[$ichannel]=($array_rpn_inumber[$ichannel]&0x3f80)|$$ref_hash_event{'Value'};
								$array_rpn_slastwritten[$ichannel]='RPN';
							}elsif($$ref_hash_event{'TypeSub'}==0x65){
								$array_rpn_inumber[$ichannel]=($array_rpn_inumber[$ichannel]&0x007f)|($$ref_hash_event{'Value'}<<7);
								$array_rpn_slastwritten[$ichannel]='RPN';
							}
						}elsif($$ref_hash_event{'Type'} eq 'ProgramChange'){
							my($ichannel)=$$ref_hash_event{'Channel'};

							($array_iprogram[$ichannel])=(
								$$ref_hash_event{'Value'}+$$ref_switch{'ProgramOffset'}
							);
						}elsif($$ref_hash_event{'Type'} eq 'Meta'){
							if($$ref_hash_event{'Type_Friendly'} eq 'Marker'){
								my($sname)=$$ref_hash_event{'Data'}->GetBody();

								if($sname ne ''){
									$smarker=$sname;
								}else{
									$smarker=$nmarker;
									++$nmarker;
								}
							}elsif($$ref_hash_event{'Type_Friendly'} eq 'End'){
								$itime_end=$itime;
							}elsif($$ref_hash_event{'Type_Friendly'} eq 'BPM'){
								$nframeperunit=&USR_SMF2SEQ_stnQuantizeFrameperUnit((60*60/$$ref_hash_event{'Value_Friendly'})*$nqnoteperunit);
								$ntimeperframe=$ntimeperunit/$nframeperunit;
							}elsif($$ref_hash_event{'Type_Friendly'} eq 'Beat'){
								my($nnumerator,$ndenominator)=split(/\//,$$ref_hash_event{'Value_Friendly'});

								$nunitpermeasure=$nunitpermeasurebeat*($nnumerator/$ndenominator);
								$itime_measurestart=$itime;
								$itime_measureend=$itime_measurestart+$ntimeperunit*$nunitpermeasure;
							}
						}
					}
				}
				#	タイムスタンプ「$itime」分のイベントを、「MIDIチャンネル」単位で纏めます。
				#	「M68K_MAKESEQUENCE」フォーマットが気にするのは、
				#	SMFフォーマット上のチャンネルでなく「MIDIチャンネル」です。
				if($nchannel<scalar(@array_ckey)){
					$nchannel=scalar(@array_ckey);
				}
				if($nchannel<scalar(@array_nvelocity)){
					$nchannel=scalar(@array_nvelocity);
				}
				if($nchannel<scalar(@array_nvolume)){
					$nchannel=scalar(@array_nvolume);
				}
				if($nchannel<scalar(@array_iprogram)){
					$nchannel=scalar(@array_iprogram);
				}
				if($nchannel<scalar(@array_ipan)){
					$nchannel=scalar(@array_ipan);
				}
				if($nchannel<scalar(@array_nmodulation)){
					$nchannel=scalar(@array_nmodulation);
				}
				{
					my($ichannel);

					for($ichannel=0;$ichannel<$nchannel;++$ichannel){
						my($efulloutchannel)=(exists $$ref_hash_fulloutchannel{$ichannel});

						$array_ref_channel[$ichannel]=[];
						if(defined $smarker){
							#	「defined $smarker」を判定条件にしないのは、
							#	ラベルと同一フレームに音符があるとは限らないため。
							#	ラベルがあった後の「初回」でパラメータ明示化する必要がある。
							$array_eprogram_undiscardable[$ichannel]=1;
							$array_epan_undiscardable[$ichannel]=1;
							$array_emodulation_undiscardable[$ichannel]=1;
							$array_evelocity_undiscardable[$ichannel]=1;
							$array_evolume_undiscardable[$ichannel]=1;
						}
						if(substr($array_ckey[$ichannel],0,2) eq 'ON'){
							my($sprefix)=substr($array_ckey[$ichannel],2);

							$sprefix=($sprefix ne '')?$sprefix:' ';
							if($efulloutchannel){
								push(@{$array_ref_channel[$ichannel]},' '.substr($array_cnote[$ichannel].' ',0,3));
							}else{
								my($ioctave,$cnote)=(
									substr($array_cnote[$ichannel],0,1),
									substr($array_cnote[$ichannel].' ',1,2)
								);

								if(
									(not defined $array_ioctave_last[$ichannel])||
									($ioctave!=$array_ioctave_last[$ichannel])
								){
									my($soctave)=(not defined $array_ioctave_last[$ichannel])?$ioctave:(
										($ioctave==$array_ioctave_last[$ichannel]-1)?'<':(
											($ioctave==$array_ioctave_last[$ichannel]+1)?'>':$ioctave
										)
									);

									$array_ioctave_last[$ichannel]=$ioctave;
									$cnote="$sprefix$soctave$cnote";
								}else{
									$cnote="$sprefix $cnote";
								}
								push(@{$array_ref_channel[$ichannel]},$cnote);
							}
							if($array_dportamentovalueperframe[$ichannel]!=0){
								push(@{$array_ref_channel[$ichannel]},"PTX=$array_dportamentovalueperframe[$ichannel]");
							}
						}else{
							$efulloutchannel=0;
							if($array_ckey[$ichannel] eq 'OFF'){
								push(@{$array_ref_channel[$ichannel]},'-   ');
								if($array_dportamentovalueperframe[$ichannel]!=0){
									push(@{$array_ref_channel[$ichannel]},"PTX=$array_dportamentovalueperframe[$ichannel]");
								}
							}else{
								push(@{$array_ref_channel[$ichannel]},'');
							}
						}
						#	プログラム番号(出力固定化可能)
						if(defined $array_iprogram[$ichannel]){
							my($iprogram)=$array_iprogram[$ichannel];
							#	マーカーがありかつ明示的数値指定があるなら同一値であろうがイベント化する
							my($epush)=$array_eprogram_undiscardable[$ichannel];

							#	明示的数値指定あり
							if(not defined $array_iprogram_initial[$ichannel]){
								#	初期値は「$itime==0」地点にあるとは限らない
								$array_iprogram_initial[$ichannel]=$iprogram;
							}elsif(($iprogram!=$array_iprogram_last[$ichannel])||$efulloutchannel){
								$epush=1;
							}
							if($epush){
								&USR_SMF2SEQ_stPushEvent($array_ref_channel[$ichannel],&USR_SMF2SEQ_stsChannelEventProgram($iprogram));
							}
							$array_iprogram_last[$ichannel]=$iprogram;
							$array_eprogram_undiscardable[$ichannel]=0;
						}elsif($efulloutchannel){
							#	明示的数値指定無しかつ出力固定
							$array_iprogram_last[$ichannel]+=0;
							#	初期値としても出力され得るだろうが重複除去されるため構わずpushする
							&USR_SMF2SEQ_stPushEvent($array_ref_channel[$ichannel],&USR_SMF2SEQ_stsChannelEventProgram($array_iprogram_last[$ichannel]));
						}
						#	パン(出力固定化可能)
						if(defined $array_ipan[$ichannel]){
							my($ipan)=$array_ipan[$ichannel];
							#	マーカーがありかつ明示的数値指定があるなら同一値であろうがイベント化する
							my($epush)=$array_epan_undiscardable[$ichannel];

							#	明示的数値指定あり
							if(not defined $array_ipan_initial[$ichannel]){
								#	初期値は「$itime==0」地点にあるとは限らない
								$array_ipan_initial[$ichannel]=$ipan;
							}elsif(($ipan!=$array_ipan_last[$ichannel])||$efulloutchannel){
								$epush=1;
							}
							if($epush){
								&USR_SMF2SEQ_stPushEvent($array_ref_channel[$ichannel],&USR_SMF2SEQ_stsChannelEventPan($ipan));
							}
							$array_ipan_last[$ichannel]=$ipan;
							$array_epan_undiscardable[$ichannel]=0;
						}elsif($efulloutchannel){
							#	明示的数値指定無しかつ出力固定
							$array_ipan_last[$ichannel]+=0;
							#	初期値としても出力され得るだろうが重複除去されるため構わずpushする
							&USR_SMF2SEQ_stPushEvent($array_ref_channel[$ichannel],&USR_SMF2SEQ_stsChannelEventPan($array_ipan_last[$ichannel]));
						}
						#	ピッチモジュレーション(出力固定化可能)
						if(defined $array_nmodulation[$ichannel]){
							my($nmodulation)=$array_nmodulation[$ichannel];
							#	マーカーがありかつ明示的数値指定があるなら同一値であろうがイベント化する
							my($epush)=$array_emodulation_undiscardable[$ichannel];

							#	明示的数値指定あり
							if(not defined $array_nmodulation_initial[$ichannel]){
								#	初期値は「$itime==0」地点にあるとは限らない
								$array_nmodulation_initial[$ichannel]=$nmodulation;
							}elsif(($nmodulation!=$array_nmodulation_last[$ichannel])||$efulloutchannel){
								#	「$nmodulation」と「$array_nmodulation_last[$ichannel]」が違う、
								#	つまり変化がある場合だけイベント化したいんだが、
								#	Cubase出力だと微妙に±1程度の雑音が入るみたいなんで幅を見ての比較が必要。
								#	ただし既に16段階化しているのでそのまま比較でOK
								$epush=1;
							}
							if($epush){
								&USR_SMF2SEQ_stPushEvent($array_ref_channel[$ichannel],&USR_SMF2SEQ_stsChannelEventModulation($nmodulation));
							}
							$array_nmodulation_last[$ichannel]=$nmodulation;
							$array_emodulation_undiscardable[$ichannel]=0;
						}elsif($efulloutchannel){
							#	明示的数値指定無しかつ出力固定
							$array_nmodulation_last[$ichannel]+=0;
							#	初期値としても出力され得るだろうが重複除去されるため構わずpushする
							&USR_SMF2SEQ_stPushEvent($array_ref_channel[$ichannel],&USR_SMF2SEQ_stsChannelEventModulation($array_nmodulation_last[$ichannel]));
						}
						#	ノート音量
						if(defined $array_nvelocity[$ichannel]){
							my($nvelocity)=$array_nvelocity[$ichannel];
							#	マーカーがありかつ明示的数値指定があるなら同一値であろうがイベント化する
							my($epush)=$array_evelocity_undiscardable[$ichannel];

							#	明示的数値指定あり
							if(not defined $array_nvelocity_initial[$ichannel]){
								#	初期値は「$itime==0」地点にあるとは限らない
								$array_nvelocity_initial[$ichannel]=$nvelocity;
							}elsif($nvelocity!=$array_nvelocity_last[$ichannel]){
								$epush=1;
							}
							if($epush){
								&USR_SMF2SEQ_stPushEvent($array_ref_channel[$ichannel],&USR_SMF2SEQ_stsChannelEventVelocity($nvelocity));
							}
							$array_nvelocity_last[$ichannel]=$nvelocity;
							$array_evelocity_undiscardable[$ichannel]=0;
						}
						#	チャンネル音量
						if(defined $array_nvolume[$ichannel]){
							my($nvolume)=$array_nvolume[$ichannel];
							#	マーカーがありかつ明示的数値指定があるなら同一値であろうがイベント化する
							my($epush)=$array_evolume_undiscardable[$ichannel];

							#	明示的数値指定あり
							if(not defined $array_nvolume_initial[$ichannel]){
								#	初期値は「$itime==0」地点にあるとは限らない
								$array_nvolume_initial[$ichannel]=$nvolume;
							}elsif($nvolume!=$array_nvolume_last[$ichannel]){
								$epush=1;
							}
							if($epush){
								&USR_SMF2SEQ_stPushEvent($array_ref_channel[$ichannel],&USR_SMF2SEQ_stsChannelEventVolume($nvolume));
							}
							$array_nvolume_last[$ichannel]=$nvolume;
							$array_evolume_undiscardable[$ichannel]=0;
						}
					}
				}
				{
					my($eevent);

					if(defined $smarker){
						$eevent=1;
					}else{
						my($ichannel);

						$eevent=0;
						for($ichannel=0;$ichannel<$nchannel;++$ichannel){
							my($ref_channel)=$array_ref_channel[$ichannel];
							my($nevent)=scalar(@$ref_channel);

							if(0<$nevent){
								if(!(($nevent==1)&&($$ref_channel[0] eq ''))){
									$eevent=1;
									last;
								}
							}
						}
					}
					if($eevent){
						#	タイムスタンプ「$itime」のイベントを置く前のタイミング調整を行います。
						#	下記が留意点です。
						#	・空イベントを置く必要があるか
						#	・「SPEED」を変更する必要があるか
						#	・デフォルト音符長と異なる場合向けに「SPEED」を変更する必要があるか
						{
							my($nunit_diff)=($itime-$itime_last)/$ntimeperunit;

							if($nunit_diff-int($nunit_diff)==0){
								#	イベント間隔がタイムスタンプ単位の整数倍なので、
								#	前回イベントから空イベントでタイミング調整すべき
								while($itime_last<$itime){
									$sub_addline->([]);
								}
							}else{
								#	短音なのか3連符なのか、イベント間隔がタイムスタンプ単位の整数倍ではないようなので、
								#	「SPEED」変更で対応
								$itime_last-=$ntimeperunit;
								$nunit_diff=($itime-$itime_last)/$ntimeperunit;
								$itime_last+=$ntimeperunit*$nunit_diff;
								$array_ref_line[scalar(@array_ref_line)-1]{'Frame'}=$nframeperunit*$nunit_diff;
							}
							$sub_addline->(\@array_ref_channel);
						}
					}elsif(($itime==0)||(defined $smarker)){
						$sub_addline->([]);
					}
				}
				if(defined $smarker){
					my($ref_line)=$array_ref_line[scalar(@array_ref_line)-1];

					$$ref_line{'Marker'}=$smarker;
					if($smarker eq 'LoopStart'){
						$ref_line_marker0=$ref_line;
					}elsif($smarker eq 'LoopEnd'){
						$ref_line_markerlast=$ref_line;
					}
				}
			}else{
				last;
			}
		}
		#	1フレーム未満の間隔を詰める(合成する)
		for(my($iline,$nline)=(0,scalar(@array_ref_line));$iline<$nline;++$iline){
			my($ref_line)=$array_ref_line[$iline];

			if($$ref_line{'Type'} eq 'Channel'){
				if($$ref_line{'Frame'}<1.0){
					my($iline_next);

					for($iline_next=$iline+1;$iline_next<$nline;++$iline_next){
						if($array_ref_line[$iline_next]{'Type'} eq 'Channel'){
							last;
						}
					}
					if($iline_next<$nline){
						my($ref_line_next)=$array_ref_line[$iline_next];

						$$ref_line{'Frame'}+=$$ref_line_next{'Frame'};
						for(my($ichannel)=0;$ichannel<$nchannel;++$ichannel){
							my($snote,@array_parameter)=@{$$ref_line{'Event'}[$ichannel]};
							my($snote_next,@array_parameter_next)=@{$$ref_line_next{'Event'}[$ichannel]};

							#	ノート合成
							if($snote ne ''){
								if($snote_next ne ''){
									my($smodify)=substr($snote,0,1);
									my($soctave)=substr($snote,1,1);

									#	修飾子の合成
									{
										my($smodify_next)=substr($snote_next,0,1);

										#	合成が必要
										#	処理中「 」、合成対象「+」の場合に限り、処理中「 」を優先
										#	それ以外の場合、合成対象の修飾子を使用
										if(($smodify ne ' ')||($smodify_next ne '+')){
											$smodify=$smodify_next;
										}
									}
									#	オクターブの合成
									{
										my($soctave_next)=substr($snote_next,1,1);

										if($soctave eq ' '){
											if($soctave_next eq ' '){
												#	何もする必要無し
											}elsif($soctave_next eq '<'){
												--$array_ioctave_last[$ichannel];
												$soctave='<';
											}elsif($soctave_next eq '>'){
												++$array_ioctave_last[$ichannel];
												$soctave='>';
											}else{
												$array_ioctave_last[$ichannel]=$soctave_next;
												$soctave=$soctave_next;
											}
										}elsif($soctave eq '<'){
											if($soctave_next eq ' '){
												--$array_ioctave_last[$ichannel];
											}elsif($soctave_next eq '<'){
												$array_ioctave_last[$ichannel]-=2;
												$soctave=$array_ioctave_last[$ichannel];
											}elsif($soctave_next eq '>'){
												$soctave=' ';
											}else{
												$array_ioctave_last[$ichannel]=$soctave_next;
												$soctave=$soctave_next;
											}
										}elsif($soctave eq '>'){
											if($soctave_next eq ' '){
												++$array_ioctave_last[$ichannel];
											}elsif($soctave_next eq '<'){
												$soctave=' ';
											}elsif($soctave_next eq '>'){
												$array_ioctave_last[$ichannel]+=2;
												$soctave=$array_ioctave_last[$ichannel];
											}else{
												$array_ioctave_last[$ichannel]=$soctave_next;
												$soctave=$soctave_next;
											}
										}else{
											if($soctave_next eq ' '){
											}elsif($soctave_next eq '<'){
												--$soctave;
											}elsif($soctave_next eq '>'){
												++$soctave;
											}else{
												$soctave=$soctave_next;
											}
											$array_ioctave_last[$ichannel]=$soctave;
										}
									}
									$snote=$smodify.$soctave.substr($snote_next,2);
								}
							}else{
								#	処理中ラインのノートは空白なんで、合成対象ラインのノートを持ち込み
								$snote=$snote_next;
							}
							#	パラメータ合成
							{
								my(%hash_parameter);

								foreach my($sparameter)(@array_parameter){
									my($sname,$svalue)=split(/\=/,$sparameter);

									$hash_parameter{$sname}=$svalue;
								}
								foreach my($sparameter)(@array_parameter_next){
									my($sname,$svalue)=split(/\=/,$sparameter);

									$hash_parameter{$sname}=$svalue;
								}
								undef @array_parameter;
								foreach my($sname)(sort keys %hash_parameter){
									push(@array_parameter,"$sname=$hash_parameter{$sname}");
								}
							}
							$$ref_line{'Event'}[$ichannel]=[$snote,@array_parameter];
						}
						splice(@array_ref_line,$iline_next,1);
						--$nline;
					}else{
						$$ref_line{'Frame'}=1;
					}
				}
			}
		}
		#	ループ終了音鳴りっぱなし防止のためのキーオフ補完
		if((defined $ref_line_marker0)&&(defined $ref_line_markerlast)){
			my($ref_array_event0)=$$ref_line_marker0{'Event'};
			my($ref_array_eventlast)=$$ref_line_markerlast{'Event'};
			my($nevent)=BASE::Maximum(scalar(@$ref_array_event0),scalar(@$ref_array_eventlast));
			my($ievent);

			for($ievent=0;$ievent<$nevent;++$ievent){
				if(not defined $$ref_array_event0[$ievent]){
					#	ループ開始点には何もイベントが無い
					if(defined $$ref_array_eventlast[$ievent]){
						foreach(@{$$ref_array_eventlast[$ievent]}){
							if(/^\-/){
								#	ループ終了点直後にキーオフがあるのでループ開始点に設定
								$$ref_array_event0[$ievent]=[$_];
								last;
							}
						}
					}
				}else{
					my($enote)=0;

					#	ループ開始点にイベントはあるが、キーイベントかどうかは分からない
					foreach(@{$$ref_array_event0[$ievent]}){
						if(($_ ne '')&&((/^\-/)||($_!~/\=/))){
							$enote=1;
							last;
						}
					}
					if(!$enote){
						#	キーイベントは無かった
						foreach(@{$$ref_array_eventlast[$ievent]}){
							if(/^\-/){
								#	ループ終了点直後にキーオフがあるのでループ開始点に設定
								if($$ref_array_event0[$ievent][0] eq ''){
									#	ループ開始点イベントの0番目要素が空であるのでそこにキーオフを設定
									$$ref_array_event0[$ievent][0]=$_;
								}else{
									#	(あり得るか分からんが)ループ開始点イベントの0番目要素が空でないので挿入
									$$ref_array_event0[$ievent]=[$_,@{$$ref_array_event0[$ievent]}];
								}
								last;
							}
						}
					}
				}
			}
		}
		#	「エンド」イベントに従った末尾カット
		if(($nmarker==0)&&(0<$itime_end)){
			my($iframe_end)=BASE::Round($nframeperunit*$itime_end/$ntimeperunit);
			my($iframe);
			my($ref_line);

			$iframe=0;
			foreach $ref_line(@array_ref_line){
				my($nframe)=$$ref_line{'Frame'};

				$iframe+=$nframe;
				if($iframe_end<$iframe){
					$nframe-=$iframe-$iframe_end;
					if($nframe<1){
						$nframe=1;
					}
					$$ref_line{'Frame'}=$nframe;
				}
			}
		}
	}
	#	未使用チャンネルを詰める
	{
		my($ref_line);
		my(@array_eused);

		#	未使用チャンネルを調査
		if(exists $$ref_switch{'ForcedChannel'}){
			my($ichannel);

			for($ichannel=0;$ichannel<$nchannel;++$ichannel){
				$array_eused[$ichannel]=(exists $$ref_switch{'ForcedChannel'}{$ichannel});
			}
		}else{
			foreach $ref_line(@array_ref_line){
				my($ichannel);

				for($ichannel=0;$ichannel<$nchannel;++$ichannel){
					if($array_eused[$ichannel]!=1){
						if(exists $$ref_line{'Event'}){
							if(defined $$ref_line{'Event'}[$ichannel]){
								my($ref_array_event)=$$ref_line{'Event'}[$ichannel];
								my($nevent)=scalar(@$ref_array_event);

								if($nevent==1){
									if($$ref_array_event[0] ne ''){
										$array_eused[$ichannel]=1;
									}
								}elsif(1<$nevent){
									$array_eused[$ichannel]=1;
								}
							}
						}
					}
				}
			}
		}
		#	確定できたので実際の削除
		foreach $ref_line(@array_ref_line){
			my($ichannel);

			for($ichannel=$nchannel;0<$ichannel;--$ichannel){
				if($array_eused[$ichannel-1]!=1){
					splice(@{$$ref_line{'Event'}},$ichannel-1,1);
				}
			}
		}
		{
			my($ichannel);

			#	使用チャンネルの名前の整理とチャンネル数の変更
			for($ichannel=$nchannel;0<$ichannel;--$ichannel){
				if($array_eused[$ichannel-1]!=1){
					splice(@array_schannel,$ichannel-1,1);
					splice(@array_nvelocity_initial,$ichannel-1,1);
					splice(@array_nvolume_initial,$ichannel-1,1);
					splice(@array_iprogram_initial,$ichannel-1,1);
					splice(@array_ipan_initial,$ichannel-1,1);
					splice(@array_nmodulation_initial,$ichannel-1,1);
					--$nchannel;
				}
			}
		}
	}
	splice(@array_schannel,$nchannel);
	{
		my($nframe_header)=$$ref_switch{'HeaderFrame'};
		my($ichannel);

		#	冒頭の空白時間切り詰め
		if($nframe_header&&scalar(@array_ref_line)){
			{
				my($nline)=scalar(@array_ref_line);
				my($iline);

				for($iline=0;$iline<$nline;++$iline){
					my($ref_line)=$array_ref_line[$iline];
					my($edelete);

					$edelete=0;
					if($$ref_line{'Type'} eq 'Channel'){
						if(scalar(@{$$ref_line{'Event'}})==0){
							$edelete=1;
						}
					}elsif($$ref_line{'Type'} eq 'Measure'){
						$edelete=1;
					}
					if($edelete){
						splice(@array_ref_line,0,1);
						--$iline;
						--$nline;
					}else{
						last;
					}
				}
			}
			#	初期値設定用nフレームの準備
			{
				my(@array_ref_line_header);
				my($iframe);

				for($iframe=0;$iframe<$$ref_switch{'HeaderFrame'};++$iframe){
					my(@array_event);

					for($ichannel=0;$ichannel<$nchannel;++$ichannel){
						push(@array_event,['']);
					}
					push(@array_ref_line_header,{
						'Type'=>'Channel',
						'Frame'=>1,
						'Event'=>[@array_event]
					});
				}
				@array_ref_line=(@array_ref_line_header,@array_ref_line);
			}
		}else{
			$nframe_header=1;
		}
		#	初期値設定
		for($ichannel=0;$ichannel<$nchannel;++$ichannel){
			my($iline)=int($ichannel*$nframe_header/$nchannel);
			my($ref_line)=$array_ref_line[$iline];

			if(not defined $$ref_line{'Event'}[$ichannel]){
				$$ref_line{'Event'}[$ichannel]=[''];
			}
			{
				my($ref_array_event)=$$ref_line{'Event'}[$ichannel];
				my($iprogram)=(defined $array_iprogram_initial[$ichannel])?$array_iprogram_initial[$ichannel]:0;
				my($ipan)=(defined $array_ipan_initial[$ichannel])?$array_ipan_initial[$ichannel]:0;
				my($nmodulation)=(defined $array_nmodulation_initial[$ichannel])?$array_nmodulation_initial[$ichannel]:0;
				my($nvelocity)=(defined $array_nvelocity_initial[$ichannel])?$array_nvelocity_initial[$ichannel]:127;
				my($nvolume)=(defined $array_nvolume_initial[$ichannel])?$array_nvolume_initial[$ichannel]:127;

				&USR_SMF2SEQ_stPushEvent($ref_array_event,&USR_SMF2SEQ_stsChannelEventProgram($iprogram));
				&USR_SMF2SEQ_stPushEvent($ref_array_event,&USR_SMF2SEQ_stsChannelEventPan($ipan));
				&USR_SMF2SEQ_stPushEvent($ref_array_event,&USR_SMF2SEQ_stsChannelEventModulation($nmodulation));
				&USR_SMF2SEQ_stPushEvent($ref_array_event,&USR_SMF2SEQ_stsChannelEventVelocity($nvelocity));
				&USR_SMF2SEQ_stPushEvent($ref_array_event,&USR_SMF2SEQ_stsChannelEventVolume($nvolume));
			}
		}
		#	冒頭無音にボリューム0のダミー音符を追加
		#	チャンネル単位で事を進める
		for(my($ichannel)=0;$ichannel<$nchannel;++$ichannel){
			#	ライン0番が「チャンネル」かは分からないので辿る
			for(my($iline,$nline)=(0,scalar(@array_ref_line));$iline<$nline;++$iline){
				my($ref_line)=$array_ref_line[$iline];

				if(
					($$ref_line{'Type'} eq 'Channel')&&
					(defined $$ref_line{'Event'}[$ichannel])
				){
					#	冒頭「チャンネル」イベントに到達
					my($snote,@array_parameter)=@{$$ref_line{'Event'}[$ichannel]};

					while($snote eq ''){
						#	冒頭無音であった
						for(my($iline_next)=$iline+1;$iline_next<$nline;++$iline_next){
							my($ref_line_next)=$array_ref_line[$iline_next];

							if(
								($$ref_line_next{'Type'} eq 'Channel')&&
								(defined $$ref_line_next{'Event'}[$ichannel])
							){
								#	2(以降)番目「チャンネル」イベントに到達
								my($snote_next,@array_parameter_next)=@{$$ref_line_next{'Event'}[$ichannel]};

								if($snote_next ne ''){
									#	発音イベントに到達したので、音量指定を移動させる
									my(%hash_parameter,$nvolume);

									#	ダミー無音イベント化する
									$snote=' 0C ';
									$nvolume=$array_nvolume_initial[$ichannel];
									#	冒頭無音「チャンネル」イベントのパラメータを収集
									undef %hash_parameter;
									foreach my($sparameter)(@array_parameter){
										my($sname,$svalue)=split(/\=/,$sparameter);

										if($sname eq 'VM'){
											$nvolume=$svalue+0;
											$svalue='0';
										}
										$hash_parameter{$sname}=$svalue;
									}
									if(not exists $hash_parameter{'VM'}){
										$hash_parameter{'VM'}='0';
									}
									#	冒頭無音「チャンネル」イベントのパラメータ指定を作り直す
									undef @array_parameter;
									foreach my($sname)(sort keys %hash_parameter){
										push(@array_parameter,"$sname=$hash_parameter{$sname}");
									}
									#	発音「チャンネル」イベントのパラメータを収集
									undef %hash_parameter;
									foreach my($sparameter)(@array_parameter_next){
										my($sname,$svalue)=split(/\=/,$sparameter);

										$hash_parameter{$sname}=$svalue;
									}
									$hash_parameter{'VM'}=$nvolume;
									#	発音「チャンネル」イベントのパラメータ指定を作り直す
									undef @array_parameter_next;
									foreach my($sname)(sort keys %hash_parameter){
										push(@array_parameter_next,"$sname=$hash_parameter{$sname}");
									}
									$$ref_line_next{'Event'}[$ichannel]=[$snote_next,@array_parameter_next];
									last;
								}
							}
						}
						last;
					}
					if($snote ne ''){
						$$ref_line{'Event'}[$ichannel]=[$snote,@array_parameter];
					}
					last;
				}
			}
		}
	}
	{
		my($img_return);
		my($ref_hash_replace)=$$ref_switch{'Replace'};

		#	最終出力
		$img_return=new BASE_IMAGE::();
		$img_return->AddLINE("#!$COM_sDirectory/M68K_MAKESEQUENCE.pl");
		$img_return->AddLINE('#');
		$img_return->AddLINE("#	TITLE:$$smf{'Info'}{'Title'}");
		$img_return->AddLINE('#');
		$img_return->AddLINE('#');
		$img_return->AddLINE('');
		#	マクロ的変数宣言
		{
			my($emacro)=0;

			if($$ref_switch{'ChannelAdditional'} ne ''){
				$img_return->AddLINE('my($'.$sChannelAdditionalVariableName.")='".$$ref_switch{'ChannelAdditional'}."';");
				$emacro=1;
			}
			{
				my(%hash_line);

				foreach(keys %$ref_hash_replace){
					my($sfrom,$sto)=($_,$$ref_hash_replace{$_});

					$hash_line{$sto}=$sfrom;
					$emacro=1;
				}
				foreach(sort keys %hash_line){
					my($sto,$sfrom)=($_,$hash_line{$_});

					$img_return->AddLINE('my($'.$sto.")='".$sfrom."';");
					$emacro=1;
				}
			}
			if($emacro){
				$img_return->AddLINE('');
			}
		}
		$img_return->AddLINE('[');
		if(0<$nchannel){
			my($line_nchannel)=12;
			my($nline)=scalar(@array_ref_line);
			my($sblank)=(((' 'x$line_nchannel).'/')x($nchannel-1)).(' 'x$line_nchannel);
			my($imeasure);
			my($nframe);
			my($eend);
			my($iline);
			my($sub_addmeasure)=sub{
				$img_return->AddLINE('	#'.('='x(($line_nchannel+1)*$nchannel)).sprintf("	%4d",$imeasure));
				++$imeasure;
				return;
			};

			#	全体での冒頭追加
			$_=$$ref_switch{'ControlAdditional'};
			if($_ ne ''){
				$_=",$_";
			}
			$img_return->AddLINE("	\"#CHANNEL=".join('/',@array_schannel)."$_\",");
			$imeasure=0;
			$nframe=0;
			$eend=0;
			if($$ref_switch{'ChannelAdditional'} ne ''){
				my(@array_ref_event);
				my($ichannel);

				#	チャンネル毎の冒頭追加
				for($ichannel=0;$ichannel<$nchannel;++$ichannel){
					push(@array_ref_event,[
						'$'.$sChannelAdditionalVariableName
					]);
				}
				@array_ref_line=(
					{
						'Type'=>'Channel',
						'Frame'=>1,
						'Event'=>[@array_ref_event]
					},@array_ref_line
				);
				++$nline;
			}
			$sub_addmeasure->();
			for($iline=0;$iline<$nline;++$iline){
				my($line)=$array_ref_line[$iline];

				if($$line{'Type'} eq 'Channel'){
					my($ref_array_ref_array_event)=$$line{'Event'};

					if($nframe!=$$line{'Frame'}){
						$nframe=$$line{'Frame'};
						$img_return->AddLINE("	\"#SPEED=$nframe\",");
					}
					if(0<scalar(@$ref_array_ref_array_event)){
						my(@array_event);
						my($ref_array_event);

						foreach $ref_array_event(@$ref_array_ref_array_event){
							my($nevent)=scalar(@$ref_array_event);
							my($ievent);

							for($ievent=0;$ievent<$nevent;++$ievent){
								my($variable,$value)=split(/\=/,$$ref_array_event[$ievent]);

								if($variable eq 'PTX'){
									if((BASE::Absolute($value)<.01)&&($$ref_array_event[0] ne '')){
										#	キーイベントがある場合、ポルタメント変化ゼロ化は省略可能
										splice(@$ref_array_event,$ievent,1);
										--$ievent;
										--$nevent;
									}else{
										my($dportamento)=$value*$$line{'Frame'};
										my($nportamentoframe)=1;
										my($dportamentoresult)=$dportamento;

										#	「16時間単位で12音階」等、1時間単位当たりの変化音階が整数でない場合、
										#	所要フレーム数を与えて誤差が出ないようにする。
										#	半端閾値「.25」だと爆発する場合あるんで「.5」でいく。
										while(.25<BASE::Absolute($dportamentoresult-BASE::Round($dportamentoresult))){
											++$nportamentoframe;
											$dportamentoresult=$dportamento*$nportamentoframe;
										}
										#	一旦「BASE::Round」でなく切り捨てでいく。
										$dportamentoresult=BASE::Round($dportamentoresult);
										if(0<=$dportamentoresult){
											$dportamentoresult='+'.$dportamentoresult;
										}
										if($nportamentoframe==1){
											$$ref_array_event[$ievent]="PT=$dportamentoresult";
										}else{
											$$ref_array_event[$ievent]="PT=$dportamentoresult&$nportamentoframe";
										}
									}
								}
							}
							{
								my($sevent)=join(',',@$ref_array_event);

								foreach(keys %$ref_hash_replace){
									my($sfrom,$sto)=($_,$$ref_hash_replace{$_});
									my($imatch)=index($sevent,$sfrom);

									if(0<=$imatch){
										substr($sevent,$imatch,length($sfrom))='$'.$sto;
									}
								}
								if(substr($sevent,0,1) eq ','){
									#	音符、休符無しの場合でも位置合わせのため「''」を放り込んでいます。
									$sevent='     '.substr($sevent,1);
								}
								if(length($sevent)<$line_nchannel){
									$sevent=substr($sevent.(' 'x$line_nchannel),0,$line_nchannel);
								}
								push(@array_event,$sevent);
							}
						}
						{
							my($nlack)=$nchannel-scalar(@array_event);

							if($nlack){
								my($i);

								#	イベント無しチャンネルの空白があるので補完
								for($i=0;$i<$nlack;++$i){
									push(@array_event,'            ');
								}
							}
						}
						$_=join('/',@array_event);
					}else{
						$_=$sblank;
					}
					if(exists $$line{'Marker'}){
						my($smarker)=$$line{'Marker'};

						if($smarker eq 'LoopEnd'){
							$img_return->AddLINE("	\"#JUMP=LoopStart\",");
							$eend=1;
						}else{
							$img_return->AddLINE("	\"#LABEL=$smarker\",");
						}
					}
					if(!$eend){
						$img_return->AddLINE("	\"$_\",");
					}else{
						$img_return->AddLINE("#	\"$_\",");
					}
				}elsif($$line{'Type'} eq 'Measure'){
					$sub_addmeasure->();
				}
			}
			$img_return->AddLINE('];');
			return $img_return;
		}
	}
}

sub USR_SMF2SEQ_stPushEvent{
	my($ref_array_event,$sevent)=@_;
	my($seventtype)=split(/\=/,$sevent,2);
	my($nevent)=scalar(@$ref_array_event);
	my($ievent);

	for($ievent=0;$ievent<$nevent;++$ievent){
		my($sevent_current)=$$ref_array_event[$ievent];
		my($seventtype_current)=split(/\=/,$sevent_current,2);

		if($seventtype_current eq $seventtype){
			splice(@$ref_array_event,$ievent,1);
			last;
		}
	}
	push(@$ref_array_event,$sevent);
	return;
}

sub USR_SMF2SEQ_stsChannelEventVelocity{
	my($nvelocity)=@_;

	return 'VL='.$nvelocity;
}

sub USR_SMF2SEQ_stsChannelEventVolume{
	my($nvolume)=@_;

	return 'VM='.$nvolume;
}

sub USR_SMF2SEQ_stsChannelEventProgram{
	my($iprogram)=@_;

	return 'PG='.$iprogram;
}

sub USR_SMF2SEQ_stsChannelEventPan{
	my($ipan)=@_;

	return 'PN='.($ipan*2);
}

sub USR_SMF2SEQ_stsChannelEventModulation{
	my($nmodulation)=@_;

	return 'PM='.(($nmodulation<<1)|($nmodulation>>6));
}

sub USR_SMF2SEQ_stnDB2Value{
	my($ndb)=@_;
	my($value)=255-int(-$ndb*1.3333333333333333333333333333333*2+.5);

	return ($value<0)?0:(
		($value<256)?$value:255
	);
}

sub USR_SMF2SEQ_stnQuantizeFrameperUnit{
	my($nframeperunit)=@_;

	#	「0.25」単位で丸める
	return BASE::Round($nframeperunit*4)/4;
}

sub USR_SMF2SEQ_stdQuantizeTimeOffset{
	my($itimeoffset)=@_;

	#	「'TimeOffset'」は最小単位1で丸める
	return BASE::Round($itimeoffset);
}

sub USR_SMF2SEQ_stQuantizePitchBend{
	my($ref_array_ref_hash_pitchbend,$ipitchbend,$ref_npitchbend,$ref_ipitchbend)=@_;
	my($ref_hash_pitchbend)=$$ref_array_ref_hash_pitchbend[$ipitchbend];

	$$ref_hash_pitchbend{'Value'}=&USR_SMF2SEQ_stdQuantizePitchBendValue($$ref_hash_pitchbend{'Value'});
	$$ref_hash_pitchbend{'TimeOffset'}=&USR_SMF2SEQ_stdQuantizeTimeOffset($$ref_hash_pitchbend{'TimeOffset'});
	if($ipitchbend+1<scalar(@$ref_array_ref_hash_pitchbend)){
		my($ref_hash_pitchbend_next)=$$ref_array_ref_hash_pitchbend[$ipitchbend+1];

		if($$ref_hash_pitchbend_next{'TimeOffset'}==$$ref_hash_pitchbend{'TimeOffset'}){
			splice(@$ref_array_ref_hash_pitchbend,$ipitchbend+1,1);
			--$$ref_npitchbend;
		}
	}
	if(0<$ipitchbend){
		my($ref_hash_pitchbend_previous)=$$ref_array_ref_hash_pitchbend[$ipitchbend-1];

		if($$ref_hash_pitchbend_previous{'TimeOffset'}==$$ref_hash_pitchbend{'TimeOffset'}){
			splice(@$ref_array_ref_hash_pitchbend,$ipitchbend-1,1);
			--$$ref_npitchbend;
			--$$ref_ipitchbend;
		}
	}
	return;
}

sub USR_SMF2SEQ_stdQuantizePitchBendValue{
	my($dvalue)=@_;

	#	16段階(0、正負それぞれ16段階で合計33段階)で丸める
	return BASE::Round($dvalue*16)/16;
}

sub USR_SMF2SEQ_stdPortamentoValueperTimefromPitchBend{
	my($ref_hash_event,$smf,$itime,$pitchbend_ndepth)=@_;

	if(exists $$ref_hash_event{'PitchBend'}){
		my($ref_array_ref_hash_pitchbend)=$$ref_hash_event{'PitchBend'};
		my($npitchbend)=scalar(@$ref_array_ref_hash_pitchbend);

		if(0<$npitchbend){
			my($ipitchbend);

			#	ピッチベンド開始時刻「$$ref_array_ref_hash_pitchbend[0]{'TimeOffset'}」がゼロでない場合、
			#	「傾き0の変化」として拾えるよう、明示化しておく必要あり。
			if(0<$$ref_array_ref_hash_pitchbend[0]{'TimeOffset'}){
				@$ref_array_ref_hash_pitchbend=(
					{
						'TimeOffset'=>0,
						'Value'=>&USR_SMF2SEQ_stdQuantizePitchBendValue($$ref_array_ref_hash_pitchbend[0]{'Value'})
					},@$ref_array_ref_hash_pitchbend
				);
				++$npitchbend;
			}
			{
				my($value_quantized)=&USR_SMF2SEQ_stdQuantizePitchBendValue($$ref_array_ref_hash_pitchbend[$npitchbend-1]{'Value'});
				my($dvaluediff)=$value_quantized-$$ref_array_ref_hash_pitchbend[$npitchbend-1]{'Value'};

				if($dvaluediff!=0){
					#	同じく、終了値が中途半端な場合は欠落の可能性があるので補間しておく
					if($npitchbend==1){
						$$ref_array_ref_hash_pitchbend[$npitchbend-1]{'Value'}=$value_quantized;
					}elsif($$ref_array_ref_hash_pitchbend[$npitchbend-1]{'Value'}==$$ref_array_ref_hash_pitchbend[$npitchbend-2]{'Value'}){
						$$ref_array_ref_hash_pitchbend[$npitchbend-1]{'Value'}=$value_quantized;
						$$ref_array_ref_hash_pitchbend[$npitchbend-2]{'Value'}=$value_quantized;
					}else{
						#	$itimeoffset
						#		ゼロ方向に向かう想定でのキリ良き「TimeOffset」。
						my($itimeoffset)=&USR_SMF2SEQ_stdQuantizeTimeOffset(
							$$ref_array_ref_hash_pitchbend[$npitchbend-1]{'TimeOffset'}+$dvaluediff*(
								($$ref_array_ref_hash_pitchbend[$npitchbend-1]{'TimeOffset'}-$$ref_array_ref_hash_pitchbend[$npitchbend-2]{'TimeOffset'})/
								($$ref_array_ref_hash_pitchbend[$npitchbend-1]{'Value'}-$$ref_array_ref_hash_pitchbend[$npitchbend-2]{'Value'})
							)
						);
						#	$dtimeoffset_diff
						#		マイナスならゼロでない方向への補間が必要
						my($dtimeoffset_diff)=$itimeoffset-$$ref_array_ref_hash_pitchbend[$npitchbend-1]{'TimeOffset'};

						++$npitchbend;
						if(0<$dtimeoffset_diff){
							#	想定通りゼロ方向に向かう補間
							push(@$ref_array_ref_hash_pitchbend,{
								'TimeOffset'=>$itimeoffset,
								'Value'=>$value_quantized
							});
						}else{
							#	ゼロでない方向への補間
							push(@$ref_array_ref_hash_pitchbend,{
								'TimeOffset'=>$itimeoffset-$dtimeoffset_diff*2,
								'Value'=>$value_quantized-$dvaluediff*2
							});
							#	逆方向補間だと再度量子化が必要
							&USR_SMF2SEQ_stQuantizePitchBend($ref_array_ref_hash_pitchbend,$npitchbend-1,\$npitchbend,\$ipitchbend);
						}
					}
				}
			}
			#	変化開始の傾き∞は読み飛ばす
			for($ipitchbend=0;$ipitchbend<$npitchbend-1;++$ipitchbend){
				if(
					$$ref_array_ref_hash_pitchbend[$ipitchbend]{'TimeOffset'}<
					$$ref_array_ref_hash_pitchbend[$ipitchbend+1]{'TimeOffset'}
				){
					last;
				}
			}
			#	「$ipitchbend」がピッチベンドパラメータの「開始」と見なすべき位置
			#	「$$ref_array_ref_hash_pitchbend[$ipitchbend+1]{'TimeOffset'}」以降変化が始まる
			#	この時点では「$ipitchbend==$npitchbend-1」の可能性がある
			{
				my($ref_hash_pitchbend_previous)=$$ref_array_ref_hash_pitchbend[$ipitchbend];
				my($ichannel)=$$ref_hash_event{'Channel'};
				my($inote)=$$ref_hash_event{'Note'};
				my($nvelocity)=$$ref_hash_event{'Velocity'};
				my($dtimeoffset)=$$ref_hash_pitchbend_previous{'TimeOffset'};
				my($dnoteoffset);

				$dnoteoffset=0;
				if($dtimeoffset==0){
					#	変化開始が変化「0」ではなかったのでノート番号を更新
					$dnoteoffset=BASE::Round($$ref_hash_pitchbend_previous{'Value'}*$pitchbend_ndepth);
					$$ref_hash_event{'Note'}+=$dnoteoffset;
					$$ref_hash_event{'Note_Friendly'}=&SMF::stsGetNote($$ref_hash_event{'Note'});
					if($ipitchbend==$npitchbend-1){
						#	継続的変化は無かったので「単音トランスポーズ指示」と解釈
						return 0;
					}
				}else{
					if($ipitchbend==$npitchbend-1){
						#	継続的変化は無かったが「トランスポーズ指示」にオフセットがあったので「変化」と解釈
						#	ただし「$$ref_hash_pitchbend_previous{'Value'}」がゼロ(実際の変化がゼロ)の可能性はある
						return $$ref_hash_pitchbend_previous{'Value'}*$pitchbend_ndepth/$dtimeoffset;
					}
				}
				#	この時点で「$ipitchbend<$npitchbend-1」までは確定
				++$ipitchbend;
				{
					my($ref_hash_pitchbend)=$$ref_array_ref_hash_pitchbend[$ipitchbend];
					my($cvalueoffsetsign)=BASE::Sign($$ref_hash_pitchbend{'Value'}-$$ref_hash_pitchbend_previous{'Value'});

					#	分割が必要であるかの判定のため、傾き変化を見ていく
					for(++$ipitchbend;$ipitchbend<$npitchbend;++$ipitchbend){
						$ref_hash_pitchbend=$$ref_array_ref_hash_pitchbend[$ipitchbend];
						if(
							$cvalueoffsetsign!=
							BASE::Sign($$ref_hash_pitchbend{'Value'}-$$ref_hash_pitchbend_previous{'Value'})
						){
							my($ref_hash_event_add)=($$ref_hash_event{'Type'} eq 'KeyOff')?&SMF::stref_hash_eventNewKeyOff(
								$ichannel,
								$inote,
								$nvelocity
							):&SMF::stref_hash_eventNewKeyOn(
								$ichannel,
								$inote,
								$nvelocity
							);

							#	「$ipitchbend」時点から傾きの変化があるのでKey分割が必要
							if($$ref_array_ref_hash_pitchbend[$ipitchbend-1]{'TimeOffset'}!=$$ref_hash_pitchbend{'TimeOffset'}){
								#	同一「'TimeOffset'」での変化ではないので、「$ipitchbend-1」を変化開始位置と見なす。
								#
								#		-3 -2 -1  0 +1
								#		 |  |  |  |  |
								#		 |  |／ ＼|  |
								#		 |／       ＼|
								#
								#	変化前側にも「-1」相当のKeyが必要なのでコピーする。
								#
								#		-3 -2 -1  0 +1 +2
								#		 |  |  |  |  |  |
								#		 |  |／    ＼|  |
								#		 |／          ＼|
								#
								#	コピー後は「$ipitchbend」がそのまま変化開始位置になる。

								#	新しい境界になるのでコピー前に量子化しておく。
								&USR_SMF2SEQ_stQuantizePitchBend($ref_array_ref_hash_pitchbend,$ipitchbend-1,\$npitchbend,\$ipitchbend);
								{
									#	@array_ref_hash_pitchbend_tail
									#		旧「$ipitchbend-1」以降の配列
									my(@array_ref_hash_pitchbend_tail)=splice(@$ref_array_ref_hash_pitchbend,$ipitchbend-1);
									#	%hash_pitchbend_border
									#		新「$ipitchbend-1」位置に置くコピー。
									#		情報として独立させる必要があるため、ハッシュ変数としてディープコピーを作る。
									my(%hash_pitchbend_border)=%{$array_ref_hash_pitchbend_tail[0]};

									@$ref_array_ref_hash_pitchbend=(@$ref_array_ref_hash_pitchbend,\%hash_pitchbend_border,@array_ref_hash_pitchbend_tail);
									++$npitchbend;
								}
								$ref_hash_pitchbend=$$ref_array_ref_hash_pitchbend[$ipitchbend];
							}
							$dtimeoffset=$$ref_hash_pitchbend{'TimeOffset'};
							$$ref_hash_event_add{'PitchBend'}=[splice(
								@{$ref_array_ref_hash_pitchbend},
								$ipitchbend
							)];
							{
								my($itime_destination)=$itime+$dtimeoffset;
								my($ref_array_ref_event_found)=$smf->ref_array_ref_eventSearchChannelUntil($ichannel,$itime_destination);
								my($ref_event_found,$ref_event_keyon,$ref_event_keyoff,$ref_event_pitchbend);
								my($inote_last);

								#	傾き変化以降のカットはできたので、Key追加が必要であるかを確認する。
								#	もし同一時刻でピッチベンドがあるならKey追加は不要と言うか追加してはならない。
								undef $ref_event_keyon,$ref_event_keyoff,$ref_event_pitchbend;
								$inote_last=0;
								foreach $ref_event_found(@$ref_array_ref_event_found){
									if($$ref_event_found{'Time'}<$itime_destination){
										my($ref_body_found);

										#	最後の「KeyOn」ノートを調べておいて、「KeyOff」がダミーでない事を確認できるようにする
										foreach $ref_body_found(@{$$ref_event_found{'Body'}}){
											my($stype)=$$ref_body_found{'Type'};

											if($stype eq 'KeyOn'){
												$inote_last=$$ref_body_found{'Note'};
											}
										}
									}else{
										my($ref_body_found);

										foreach $ref_body_found(@{$$ref_event_found{'Body'}}){
											my($stype)=$$ref_body_found{'Type'};

											if($stype eq 'KeyOn'){
												$ref_event_keyon=$ref_body_found;
											}elsif($stype eq 'KeyOff'){
												#	傾き変化のタイミングでKeyイベントはあったが、
												#	「モノフォニック時の継続KeyOn」用ダミーである可能性があるのでチェック
												if($$ref_body_found{'Note'}==$inote_last){
													#	最後の「KeyOn」ノートと一致したのでこの「KeyOff」はダミーではない
													$ref_event_keyoff=$ref_body_found;
												}
											}
											if(
												(($stype eq 'KeyOn')||($stype eq 'KeyOff'))&&
												(exists $$ref_body_found{'PitchBend'})
											){
												#	追加してはならないケースに該当
												$ref_event_pitchbend=$ref_body_found;
												last;
											}
										}
										if(defined $ref_event_pitchbend){
											last;
										}
									}
								}
								if(not defined $ref_event_pitchbend){
									#	分割先用に「'TimeOffset'」の補正も必要
									foreach(@{$$ref_hash_event_add{'PitchBend'}}){
										$$_{'TimeOffset'}-=$dtimeoffset;
									}
									if(defined $ref_event_keyon){
										#	KeyOnがあるのでこちらにピッチベンドを追加
										$$ref_event_keyon{'PitchBend'}=$$ref_hash_event_add{'PitchBend'};
									}elsif(defined $ref_event_keyoff){
										#	KeyOnが無いのでやむなくKeyOff側にピッチベンドを追加
										$$ref_event_keyoff{'PitchBend'}=$$ref_hash_event_add{'PitchBend'};
									}else{
										#	既存Keyイベントは無いようなので分割したKeyを追加
										#	「KeyOff無しKeyOn」との区別のために追加イベントにマークを設定
										$$ref_hash_event_add{'AddedEvent'}=1;
										$smf->AddEvent(
											$itime_destination,
											$ref_hash_event_add
										);
									}
								}
							}
							last;
						}
						$ref_hash_pitchbend_previous=$ref_hash_pitchbend;
					}
					#	「$ipitchbend-1」まで傾きの変化は無かった
					#	末尾補間、途中分割のいづれも無い場合に向けて、ここでも量子化必要。
					&USR_SMF2SEQ_stQuantizePitchBend($ref_array_ref_hash_pitchbend,$ipitchbend-1,\$npitchbend,\$ipitchbend);
					$ref_hash_pitchbend=$$ref_array_ref_hash_pitchbend[$ipitchbend-1];
					$dtimeoffset=$$ref_hash_pitchbend{'TimeOffset'};
					if(0<$dtimeoffset){
						if(($ipitchbend==$npitchbend)&&($cvalueoffsetsign!=0)){
							#	途中の傾き変化は無かったかも知れないが、傾きがあるなら、ピッチベンド終了後の固定は必要。
							#	もしピッチベンド終了までに当該チャンネル内で「KeyOn」、「KeyOff」イベントが無いなら追加。
							my($itime_add)=$itime+$dtimeoffset;
							#	ピッチベンドが連続する場合、最後のピッチイベントは次のキーイベントに含まれるかもしれないので、
							#	イベントインデックス+1までを検索対象とする。
							my($ref_array_ref_event_found)=$smf->ref_array_ref_eventSearchChannelUntil($ichannel,$itime+BASE::Ceil($dtimeoffset*($npitchbend+1)/$npitchbend)+10);
							my($eadd)=1;
							my($ref_event_found);

							foreach $ref_event_found(@$ref_array_ref_event_found){
								my($ref_body_found);

								foreach $ref_body_found(@{$$ref_event_found{'Body'}}){
									my($stype)=$$ref_body_found{'Type'};

									if(($stype eq 'KeyOn')||($stype eq 'KeyOff')){
										$eadd=0;
										last;
									}
								}
								if(!$eadd){
									last;
								}
							}
							if($eadd){
								my($inote_fixed)=$inote+BASE::Round($$ref_hash_pitchbend{'Value'}*$pitchbend_ndepth);
								my($ref_hash_event_add)=($$ref_hash_event{'Type'} eq 'KeyOff')?&SMF::stref_hash_eventNewKeyOff(
									$ichannel,
									$inote_fixed,
									$nvelocity
								):&SMF::stref_hash_eventNewKeyOn(
									$ichannel,
									$inote_fixed,
									$nvelocity
								);
								#	「KeyOff無しKeyOn」との区別のために追加イベントにマークを設定
								$$ref_hash_event_add{'AddedEvent'}=1;
								$smf->AddEvent(
									$itime_add,
									$ref_hash_event_add
								);
							}
						}
						return ($$ref_hash_pitchbend{'Value'}*$pitchbend_ndepth-$dnoteoffset)/$dtimeoffset;
					}
				}
			}
		}
	}
	return 0;
}
