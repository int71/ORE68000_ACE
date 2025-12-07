##############################################################################
##																			##
##																			##
##									OFW										##
##																			##
##	'smf.pl'										2025 written by int71	##
##############################################################################

use strict;
use utf8;
use Encode();
require 'base.pl';
require 'base_image.pl';

#	SMF			::= HEADER #{ TRACK* }
#	HEADER		::= "MThd" LENGTH<U32> FORMAT NTRKS DIVISION
#	TRACK		::= "MTrk" LENGTH<U32> TRACK_DATA
#	FORMAT		::= <U16>
#		0:単一のマルチ・チャンネル・トラックだけを含むファイル
#		1:1つ以上の同時に演奏されるシーケンス・トラック(または MIDI OUT)を含むファイル
#		2:1つ以上のシーケンス的に独立した単一のトラック・パターンを含むファイル
#	NTRKS		::= <U16>
#		トラック・ブロックの数。
#	DIVISION	::= <S16>
#		4分音符の分解能。
#		もし負であるならば、それはトラックが拍子のかわりに実時間でイベントの発生を表現できるように、
#		ファイル中のデルタ・タイムを「秒」で表すことを表わす。
#	TRACK_DATA	::= #{ TRACK_EVENT* }
#	TRACK_EVENT	::= DELTA_TIME<可変長形式> EVENT
#	EVENT		::= MIDI_EVENT | SYSEX_EVENT | META_EVENT
#	MIDI_EVENT	::= [STATUS] #{ DATA* }
#	STATUS		::= <U8(MSB=1)>
#		MSB(ビット7)が1である8bit値。
#		省略される場合があり、その際は前回と同一の「ステータス・バイト」であると解釈(ランニング・ステータス)する。
#		0x8n NOTE<U7> VELOCITY<U7>:	ノート・オフ
#		0x9n NOTE<U7> VELOCITY<U7>:	ノート・オン
#			「VELOCITY」が「0」なら「ノート・オフ」として解釈する。
#		0xAn NOTE<U7> VELOCITY<U7>:	ポリフォニック・キー・プレッシャー
#		0xBn NUMBER<U7> VALUE<U7>:	コントロール・チェンジ
#			0xBn 0x00～0x1F 上位<U7>:	2バイト・データの操作子のMSB
#				0xBn 0x00 上位<U7>:			バンク・セレクト(上位7ビット)
#				0xBn 0x01 データ<U7>:		モジュレーション・ホイール
#				0xBn 0x02 データ<U7>:		ブレス・コントローラ
#				0xBn 0x04 データ<U7>:		フット・コントローラ
#				0xBn 0x05 データ<U7>:		ポルタメント・タイム
#				0xBn 0x06 上位<U7>:			RPN/NRPNデータ・エントリー上位
#				0xBn 0x07 データ<U7>:		チャンネル・ボリューム
#				0xBn 0x08 バランス<U7>:		バランス(0は左またはロワーの音源が最大音量、64は等バランス、127は右またはアッパーの音源が最大音量)
#				0xBn 0x0A 定位<U7>:			パン(0は左端、64は中央、127は右端)
#				0xBn 0x0B 強さ<U7>:			エクスプレッション
#			0xBn 0x20～0x3F 上位<U7>:	2バイト・データの操作子のLSB
#				0xBn 0x20 下位<U7>:			バンク・セレクト(下位7ビット)
#				0xBn 0x26 下位<U7>:			RPN/NRPNデータ・エントリー下位
#			0xBn 0x40～0x5F データ<U7>:	1バイト・データの操作子
#				0xBn 0x40 データ<U7>:		ホールド(0x00:オフ 0x7F:オン)
#				0xBn 0x44 データ<U7>:		レガート・フット・スイッチ(0x00～0x3F:Normal 40～7F:Legato(再アタック無しピッチ変更モード))
#				0xBn 0x46 データ<U7>:		サウンド・コントローラ(サウンド・バリエーション)
#				0xBn 0x47 データ<U7>:		サウンド・コントローラ(ティンバー/ハーモニック・インテンシティ)
#				0xBn 0x48 データ<U7>:		サウンド・コントローラ(リリース・タイム)
#				0xBn 0x49 データ<U7>:		サウンド・コントローラ(アタック・タイム)
#				0xBn 0x4A データ<U7>:		サウンド・コントローラ(ブライトネス)
#				0xBn 0x4B データ<U7>:		サウンド・コントローラ
#				0xBn 0x4C データ<U7>:		サウンド・コントローラ
#				0xBn 0x4D データ<U7>:		サウンド・コントローラ
#				0xBn 0x4E データ<U7>:		サウンド・コントローラ
#				0xBn 0x4F データ<U7>:		サウンド・コントローラ
#				0xBn 0x54 ノート番号<U7>:	ポルタメント・コントローラ
#				0xBn 0x5B データ<U7>:		エフェクト1(外部エフェクト)デプス
#				0xBn 0x5C データ<U7>:		エフェクト2(トレモロ)デプス
#				0xBn 0x5D データ<U7>:		エフェクト3(コーラス)デプス
#				0xBn 0x5E データ<U7>:		エフェクト4(デチューン)デプス
#				0xBn 0x5F データ<U7>:		エフェクト5(フェイザー)デプス
#			0xBn 0x60 ダミー<U7>:		RPN/NRPNデータ・インクリメント
#			0xBn 0x61 ダミー<U7>:		RPN/NRPNデータ・デクリメント
#			0xBn 0x62 番号下位<U7>:		NRPNパラメータ番号下位
#			0xBn 0x63 番号上位<U7>:		NRPNパラメータ番号上位
#			0xBn 0x64 番号下位<U7>:		RPNパラメータ番号下位
#			0xBn 0x65 番号上位<U7>:		RPNパラメータ番号上位
#			0xBn 0x66～0x77 データ<U7>:	未定義の1バイト操作子
#			0xBn 0x78～0x7F データ<U7>:	チャンネルモードメッセージ
#				0xBn 0x7B 0x00:				オール・ノート・オフ
#				0xBn 0x7C 0x00:				OMNI OFF
#				0xBn 0x7D 0x00:				OMNI ON
#				0xBn 0x7E 0x00 [チャンネル数<U7>]:	MONO(モード4(OMNI OFF/MONO)時「チャンネル数」を使用)
#		0xCn 番号<U7>:				プログラム・チェンジ
#		0xDn VELOCITY<U7>:			チャンネル・プレッシャー(「ポリフォニック・キー・プレッシャー」のチャンネル内全音版)
#		0xEn 下位<U7> 上位<U7>:		ピッチ・ベンド・チェンジ(に「8192」を加算した値)
#	DATA		::= <U7>
#	SYSEX_EVENT	::= (0xF0|0xF7) LENGTH<可変長形式> #{ <U8>* }
#		0xF0の1バイトはMIDIメッセージとして送信対象、0xF7は対象外。
#		受信側に終端を知らせるため、データ最終バイトは「0xF7」である必要があるが、
#		「SYSEX_EVENT」を分割するなら、データ上「0xF7」で終了しない場合もあり得る。
#	META_EVENT	::= 0xFF TYPE<U8> LENGTH<可変長形式> #{ <U8>* }
#		0xFF 0x00 0x02 <U16>:		シーケンス・ナンバー
#		0xFF 0x01 LEN<U8> TEXT:		テキスト・イベント
#		0xFF 0x02 LEN<U8> TEXT:		著作権表示
#		0xFF 0x03 LEN<U8> TEXT:		シーケンス名またはトラック名
#		0xFF 0x04 LEN<U8> TEXT:		楽器名
#		0xFF 0x05 LEN<U8> TEXT:		歌詞
#		0xFF 0x06 LEN<U8> TEXT:		マーカー
#		0xFF 0x07 LEN<U8> TEXT:		キュー・ポイント
#		0xFF 0x2F 0x00:				トラックの終わり
#		0xFF 0x51 0x03 <U24>:		テンポ設定(4分音符あたりのマイクロ秒)
#		0xFF 0x58 0x04 分子<U8> 分母2累乗<U8> <U8> <U8>:	拍子設定
#	<可変長形式>
#		「数値」1バイトを「データ」7ビットで表現する。
#		後続「データ」バイトがある場合MSB(ビット7)は1、終端である場合0となる。
#		<例>
#			数値(16進)	データ(16進)
#			00000000	00
#			00000040	40
#			0000007F	7F
#			00000080	81 00
#			00002000	C0 00
#			00003FFF	FF 7F
#			00004000	81 80 00
#			00100000	C0 80 00
#			001FFFFF	FF FF 7F
#			00200000	81 80 80 00
#			08000000	C0 80 80 00
#			0FFFFFFF	FF FF FF 7F

#
#	SMF
#

{
	package SMF;

	BEGIN{
		our($Version,$Date)=('1.5','2025/08/23');
		our(
			$cnTimeQuantize,
			$cnTimeQuantizePitchBend,
			$cnTimeModulationErrorMargin
		)=(
			5,
			1,
			20
		);

		return;
	}

	sub new{
		my($class,$sfilename)=@_;
		my($this);

		$this={};
		bless($this,$class);
		if(defined $sfilename){
			$this->Load($sfilename);
		}else{
			$this->Clear();
			$this->Initialize();
		}
		return $this;
	}

	sub Clear{
		my($this)=@_;

		%$this=(
			'Info'=>{
				'Artist'=>'',
				'Title'=>''
			},
			'Format'=>0x0000,
			'Division'=>48,
			'Header'=>{},
			'Track'=>[]
		);
		return;
	}

	sub Initialize{
		my($this)=@_;
		my($track);

		$$this{'BPMCurrent'}=0;
		$$this{'BeatCurrent'}=0;
		foreach $track(@{$$this{'Track'}}){
			$$track{'EventCurrent'}=0;
		}
		return;
	}

	sub itime_ref_array_ref_array_ref_hash_eventGet{
		my($this,$itime)=@_;
		my(@array_ref_array_ref_hash_event);

		if(defined $itime){
			my($itime_minimum)=0xffffffff;
			my($ref_hash_track);

			foreach $ref_hash_track(@{$$this{'Track'}}){
				my($nevent)=scalar(@{$$ref_hash_track{'Event'}});
				my($ievent);

				$$ref_hash_track{'EventCurrent'}=0;
				for($ievent=0;$ievent<$nevent;++$ievent){
					my($ref_hash_event)=$$ref_hash_track{'Event'}[$ievent];

					if($itime<=$$ref_hash_event{'Time'}){
						$$ref_hash_track{'EventCurrent'}=$ievent;
						if($$ref_hash_event{'Time'}<$itime_minimum){
							$itime_minimum=$$ref_hash_event{'Time'};
						}
						last;
					}
				}
			}
			$itime=$itime_minimum;
		}else{
			my($ref_hash_track);

			$itime=0xffffffff;
			foreach $ref_hash_track(@{$$this{'Track'}}){
				my($ievent)=$$ref_hash_track{'EventCurrent'};

				if($ievent<scalar(@{$$ref_hash_track{'Event'}})){
					my($itime_current)=$$ref_hash_track{'Event'}[$ievent]{'Time'};

					if($itime_current<$itime){
						$itime=$itime_current;
					}
				}
			}
		}
		if($itime==0xffffffff){
			undef $itime;
		}else{
			my($ntrack)=scalar(@{$$this{'Track'}});
			my($itrack);

			for($itrack=0;$itrack<$ntrack;++$itrack){
				my($ref_hash_track)=$$this{'Track'}[$itrack];
				my($ievent)=$$ref_hash_track{'EventCurrent'};

				$array_ref_array_ref_hash_event[$itrack]=[];
				if($ievent<scalar(@{$$ref_hash_track{'Event'}})){
					if($$ref_hash_track{'Event'}[$ievent]{'Time'}==$itime){
						my($ref_array_ref_hash_event)=$$ref_hash_track{'Event'}[$ievent]{'Body'};
						my($ref_hash_event);

						$array_ref_array_ref_hash_event[$itrack]=$ref_array_ref_hash_event;
						$$ref_hash_track{'EventCurrent'}=$ievent+1;
						foreach $ref_hash_event(@$ref_array_ref_hash_event){
							if($$ref_hash_event{'Type_Friendly'} eq 'BPM'){
								$$this{'BPMCurrent'}=$$ref_hash_event{'Value_Friendly'};
							}elsif($$ref_hash_event{'Type_Friendly'} eq 'Beat'){
								$$this{'BeatCurrent'}=$$ref_hash_event{'Value_Friendly'};
							}
						}
					}
				}
			}
		}
		return ($itime,\@array_ref_array_ref_hash_event);
	}

	sub ref_array_ref_eventSearchChannelUntil{
		my($this,$ichannel,$itime)=@_;
		my($ntrack)=scalar(@{$$this{'Track'}});
		my(@array_ref_event);
		my($itrack);

		for($itrack=0;$itrack<$ntrack;++$itrack){
			my($ref_hash_track)=$$this{'Track'}[$itrack];

			if(exists $$ref_hash_track{'Channel'}){
				#	このチェックを行わないとチャンネル「0」指定のつもりが「チャンネル概念無し」を引っかけてしまう
				if($$ref_hash_track{'Channel'}==$ichannel){
					my($nevent)=scalar(@{$$ref_hash_track{'Event'}});
					my($ievent);

					for($ievent=$$ref_hash_track{'EventCurrent'};$ievent<$nevent;++$ievent){
						my($ref_event)=$$ref_hash_track{'Event'}[$ievent];

						if($itime<$$ref_event{'Time'}){
							last;
						}else{
							push(@array_ref_event,$ref_event);
						}
					}
					last;
				}
			}
		}
		return \@array_ref_event;
	}

	sub Load{
		my($this,$sfilename)=@_;
		my($img_source,$nsize);

		$this->Clear();
		$img_source=new BASE_IMAGE::($sfilename);
		$nsize=$img_source->GetSize();
		$img_source->SetCurrent(0);
		while($img_source->GetCurrent()<$nsize){
			my($cid)=$img_source->GetSubBody(4);
			my($img_body)=$img_source->GetSub($img_source->GetDWORD_B());

			$this->Load_Body($cid,$img_body);
		}
		$this->Initialize();
		return;
	}

	sub AddEvent{
		my($this,$itime,$ref_hash_event_body)=@_;
		my($itrack);

		$itrack=0;
		if(exists $$ref_hash_event_body{'Channel'}){
			my($ichannel)=$$ref_hash_event_body{'Channel'};
			my($ntrack)=scalar(@{$$this{'Track'}});
			my($itrack_temp);

			for($itrack_temp=0;$itrack_temp<$ntrack;++$itrack_temp){
				if(exists $$this{'Track'}[$itrack_temp]{'Channel'}){
					if($$this{'Track'}[$itrack_temp]{'Channel'}==$ichannel){
						$itrack=$itrack_temp;
						last;
					}
				}
			}
		}
		{
			my($ref_hash_track)=$$this{'Track'}[$itrack];
			my($nevent)=scalar(@{$$ref_hash_track{'Event'}});
			my($ievent);

			for($ievent=0;$ievent<$nevent;++$ievent){
				my($ref_hash_event)=$$ref_hash_track{'Event'}[$ievent];

				if($itime==$$ref_hash_event{'Time'}){
					push(@{$$ref_hash_event{'Body'}},$ref_hash_event_body);
					return;
				}elsif($itime<$$ref_hash_event{'Time'}){
					last;
				}
			}
			splice(@{$$ref_hash_track{'Event'}},$ievent,0,(
				{
					'Time'=>$itime,
					'Body'=>[$ref_hash_event_body]
				}
			));
			if($ievent<$$ref_hash_track{'EventCurrent'}){
				++$$ref_hash_track{'EventCurrent'};
			}
		}
		return;
	}

	sub stref_hash_eventNewKeyOff{
		my($ichannel,$inote,$nvelocity)=@_;

		if(not defined $nvelocity){
			$nvelocity=64;
		}
		return {
			'Channel'=>$ichannel,
			'Type'=>'KeyOff',
			'Note'=>$inote,
			'Note_Friendly'=>&stsGetNote($inote),
			'Velocity'=>$nvelocity,
			'Velocity_Friendly'=>&stndbConvertfromVolume($nvelocity)
		};
	}

	sub stref_hash_eventNewKeyOn{
		my($ichannel,$inote,$nvelocity)=@_;

		if(0<$nvelocity){
			return {
				'Channel'=>$ichannel,
				'Type'=>'KeyOn',
				'Note'=>$inote,
				'Note_Friendly'=>&stsGetNote($inote),
				'Velocity'=>$nvelocity,
				'Velocity_Friendly'=>&stndbConvertfromVolume($nvelocity)
			};
		}else{
			return &stref_hash_eventNewKeyOff($ichannel,$inote);
		}
	}

	sub stref_hash_eventNewKeyPressure{
		my($ichannel,$inote,$nvelocity)=@_;

		return {
			'Channel'=>$ichannel,
			'Type'=>'KeyPressure',
			'Note'=>$inote,
			'Note_Friendly'=>&stsGetNote($inote),
			'Velocity'=>$nvelocity,
			'Velocity_Friendly'=>&stndbConvertfromVolume($nvelocity)
		};
	}

	sub stref_hash_eventNewControl{
		my($ichannel,$isub,$value,$ref_eomni,$img_source)=@_;
		my(%hash_return)=(
			'Channel'=>$ichannel,
			'Type'=>'Control',
			'TypeSub'=>$isub,
			'Value'=>$value
		);

		if($isub==0x7c){
			$$ref_eomni=0;
		}elsif($isub==0x7d){
			$$ref_eomni=1;
		}elsif($isub==0x7e){
			if($$ref_eomni==0){
				$hash_return{'Value_Append'}=$img_source->GetBYTE();
			}
		}
		if($hash_return{'TypeSub'}==0x01){
			$hash_return{'Type_Friendly'}='Modulation';
		}elsif($hash_return{'TypeSub'}==0x07){
			$hash_return{'Type_Friendly'}='Volume';
			$hash_return{'Value_Friendly'}=&stndbConvertfromVolume($value);
		}elsif($hash_return{'TypeSub'}==0x0a){
			$hash_return{'Type_Friendly'}='Pan';
			$value=BASE::Maximum(1,$value);
			$hash_return{'Value'}=$value;
			$hash_return{'Value_Friendly'}=$value-64;
		}elsif($hash_return{'TypeSub'}==0x0b){
			$hash_return{'Type_Friendly'}='Expression';
		}
		return \%hash_return;
	}

	sub stref_hash_eventNewProgramChange{
		my($ichannel,$value)=@_;

		return {
			'Channel'=>$ichannel,
			'Type'=>'ProgramChange',
			'Value'=>$value
		};
	}

	sub stref_hash_eventNewChannelPressure{
		my($ichannel,$nvelocity)=@_;

		return {
			'Channel'=>$ichannel,
			'Type'=>'ChannelPressure',
			'Velocity'=>$nvelocity
		};
	}

	sub stref_hash_eventNewPitchBend{
		my($ichannel,$value)=@_;

		return {
			'Channel'=>$ichannel,
			'Type'=>'PitchBend',
			'Value'=>$value,
			'Value_Friendly'=>($value-8192)/8192
		};
	}

	sub stref_hash_eventNewSysEx{
		my($isub,$img_data)=@_;

		return {
			'Type'=>'SysEx',
			'TypeSub'=>$isub,
			'Data'=>$img_data
		};
	}

	sub stref_hash_eventNewMeta{
		my($isub,$img_data)=@_;
		my(%hash_return)=(
			'Type'=>'Meta',
			'TypeSub'=>$isub,
			'Data'=>$img_data
		);

		if($isub==0x06){
			$hash_return{'Type_Friendly'}='Marker';
		}elsif($isub==0x2f){
			$hash_return{'Type_Friendly'}='End';
		}elsif($isub==0x51){
			$hash_return{'Type_Friendly'}='BPM';
			$img_data->SetCurrent(0);
			{
				my($data0)=$img_data->GetBYTE();
				my($data1)=$img_data->GetBYTE();
				my($data2)=$img_data->GetBYTE();

				$hash_return{'Value_Friendly'}=int(600000000/(($data0<<16)|($data1<<8)|$data2))/10;
			}
		}elsif($isub==0x58){
			$hash_return{'Type_Friendly'}='Beat';
			$img_data->SetCurrent(0);
			{
				my($nnumerator)=$img_data->GetBYTE();
				my($ndenominator)=2<<$img_data->GetBYTE();

				$hash_return{'Value_Friendly'}="$nnumerator/$ndenominator";
			}
		}
		return \%hash_return;
	}

	sub stsGetNote{
		my($note)=@_;

		return int($note/12).('C','C#','D','D#','E','F','F#','G','G#','A','A#','B')[$note%12];
	}

	sub stndbConvertfromVolume{
		my($nvolume)=@_;

		return 12*log($nvolume+1)/log(2)-84;
	}

	#	private

	sub Load_Body{
		my($this,$cid,$img_source)=@_;

		if($cid eq 'MThd'){
			$$this{'Header'}=&LOAD_stref_hash_headerRead($img_source);
			$$this{'Format'}=$$this{'Header'}{'Format'};
			$$this{'Division'}=$$this{'Header'}{'Division'};
		}elsif($cid eq 'MTrk'){
			my($ref_hash_track)=&LOAD_stref_hash_trackRead($img_source);

			if(scalar(@{$$this{'Track'}})==0){
				if(exists $$ref_hash_track{'Name'}){
					$$this{'Info'}{'Title'}=$$ref_hash_track{'Name'};
					Encode::from_to($$this{'Info'}{'Title'},'Shift_JIS','UTF-8');
				}
			}
			push(@{$$this{'Track'}},$ref_hash_track);
		}
		return;
	}

	sub LOAD_stvlRead{
		my($img_source)=@_;
		my($return)=0;

		while(1){
			my($value)=$img_source->GetBYTE();

			$return=($return<<7)|($value&0x7f);
			if(($value&0x80)==0){
				return $return;
			}
		}
	}

	sub LOAD_stref_hash_headerRead{
		my($img_source)=@_;
		my(%hash_return);

		$img_source->SetCurrent(0);
		$hash_return{'Format'}=$img_source->GetWORD_B();
		$img_source->GetWORD_B();
		$hash_return{'Division'}=$img_source->GetWORD_B();
		return \%hash_return;
	}

	sub LOAD_stref_hash_trackRead{
		my($img_source)=@_;
		my($nsize)=$img_source->GetSize();
		my($ichannel);
		my(@array_event);
		my($itime);
		my(%hash_return);
		my($cstatus);
		my($ref_key_last);
		my($dtimeoffset);
		my($eomni);

		undef $ichannel;
		undef @array_event;
		$itime=0;
		undef %hash_return;
		$cstatus=0x00;
		undef $ref_key_last;
		$dtimeoffset=0;
		$eomni=1;
		$img_source->SetCurrent(0);
		while($img_source->GetCurrent()<$nsize){
			my($ndelta)=&LOAD_stvlRead($img_source);
			my($data)=$img_source->GetBYTE();

			$dtimeoffset+=$ndelta;
			if($data&0x80){
				#	「ランニング・ステータス」ではない
				$cstatus=$data;
				$data=$img_source->GetBYTE();
			}
			{
				my($ref_hash_event)=&LOAD_stref_hash_eventRead($cstatus,$data,$img_source,\$eomni);

				if(exists $$ref_hash_event{'Channel'}){
					$ichannel=$$ref_hash_event{'Channel'};
				}
				if($$ref_hash_event{'Type'} eq 'KeyOff'){
					#	「KeyOff」時、直前「KeyOn」とオーバラップしているなら、ピッチベンド変化元になって欲しくない
					if(not defined $ref_key_last){
						$ref_key_last=$ref_hash_event;
						$dtimeoffset=0;
					}elsif(
						($$ref_key_last{'Type'} eq 'KeyOn')&&
						($$ref_key_last{'Note'} eq $$ref_hash_event{'Note'})
					){
						$ref_key_last=$ref_hash_event;
						$dtimeoffset=0;
					}
				}elsif($$ref_hash_event{'Type'} eq 'KeyOn'){
					$ref_key_last=$ref_hash_event;
					$dtimeoffset=0;
				}elsif($$ref_hash_event{'Type'} eq 'PitchBend'){
					#	ピッチベンドは変化元「KeyOn」、「KeyOff」イベントにも含める
					if(defined $ref_key_last){
						if(not exists $$ref_key_last{'PitchBend'}){
							$$ref_key_last{'PitchBend'}=[];
						}
						{
							my($ref_array_ref_pitch)=$$ref_key_last{'PitchBend'};
							my($npitch)=scalar(@$ref_array_ref_pitch);
							my($ref_pitch)={
								'TimeOffset'=>$dtimeoffset,
								'Value'=>$$ref_hash_event{'Value_Friendly'}
							};

							if(0<$npitch){
								my($ref_pitch_last)=$$ref_array_ref_pitch[$npitch-1];

								if(
									($$ref_pitch_last{'TimeOffset'}!=$$ref_pitch{'TimeOffset'})||
									($$ref_pitch_last{'Value'}!=$$ref_pitch{'Value'})
								){
									push(@$ref_array_ref_pitch,$ref_pitch);
								}
							}else{
								push(@$ref_array_ref_pitch,$ref_pitch);
							}
						}
					}
				}elsif($$ref_hash_event{'Type'} eq 'Meta'){
					if($$ref_hash_event{'TypeSub'}==0x03){
						$hash_return{'Name'}=$$ref_hash_event{'Data'}->GetBody();
					}
				}
				$itime+=$ndelta;
				&LOAD_stAddEvent(\@array_event,$ref_hash_event,$itime);
			}
		}
		if(defined $ichannel){
			$hash_return{'Channel'}=$ichannel;
		}
		$hash_return{'Event'}=\@array_event;
		return \%hash_return;
	}

	sub LOAD_stAddEvent{
		my($ref_array_event,$ref_hash_event,$itime)=@_;
		my($narray_event)=scalar(@$ref_array_event);
		#	Cubaseが出力する「.mid」はタイムスタンプが微妙らしいので丸める。
		#	ただしピッチベンドは(なぜか)「5」より小さい単位で記録されるらしいので回避。
		my($nquantize)=($$ref_hash_event{'Type'} eq 'PitchBend')?$SMF::cnTimeQuantizePitchBend:$SMF::cnTimeQuantize;
		my($event_entry);

		if($narray_event==0){
			$$ref_array_event[0]={
				'Time'=>0,
				'Body'=>[]
			};
			$event_entry=$$ref_array_event[0];
		}else{
			$event_entry=$$ref_array_event[$narray_event-1];
		}
		{
			my($itime_quantized)=BASE::Round($itime/$nquantize)*$nquantize;
			my($ndelta)=$itime_quantized-$$event_entry{'Time'};

			#	ピッチモジュレーションはタイムスタンプが微妙になりがちなので特別補正を実施
			if(($$ref_hash_event{'Type'} eq 'Control')&&($$ref_hash_event{'Type_Friendly'} eq 'Modulation')){
				if($ndelta<$SMF::cnTimeModulationErrorMargin){
					#	キー→遅れピッチモジュレーションパターン
					$ndelta=0;
				}
			}else{
				my($ref_array_body)=$$event_entry{'Body'};
				my($nbody)=scalar(@$ref_array_body);

				if($nbody){
					my($ibody);

					for($ibody=0;$ibody<$nbody;++$ibody){
						my($body)=$$ref_array_body[$ibody];

						if(!(
							($$body{'Type'} eq 'Control')&&
							($$body{'TypeSub'}==0x01)
						)){
							last;
						}
					}
					if($ibody==$nbody){
						if($ndelta<$SMF::cnTimeModulationErrorMargin){
							#	早めピッチモジュレーション→キーパターン
							$$event_entry{'Time'}=$itime_quantized;
							$ndelta=0;
						}
					}
				}
			}
			if(0<$ndelta){
				if($ndelta==1){
					#	恐らくMIDI的に同時にするわけにいかないイベントなのだろうが、
					#	関係無いので後の時刻を「正」にしてしまう。
					$$event_entry{'Time'}=$itime_quantized;
				}else{
					$$ref_array_event[$narray_event]={
						'Time'=>$itime_quantized,
						'Body'=>[]
					};
					$event_entry=$$ref_array_event[$narray_event];
				}
			}
		}
		push(@{$$event_entry{'Body'}},$ref_hash_event);
		return;
	}

	sub LOAD_stref_hash_eventRead{
		my($cstatus,$data,$img_source,$ref_eomni)=@_;
		my($cevent)=($cstatus>>4)&0xf;

		if($cevent==0x8){
			return &stref_hash_eventNewKeyOff($cstatus&0xf,$data,$img_source->GetBYTE());
		}elsif($cevent==0x9){
			return &stref_hash_eventNewKeyOn($cstatus&0xf,$data,$img_source->GetBYTE());
		}elsif($cevent==0xa){
			return &stref_hash_eventNewKeyPressure($cstatus&0xf,$data,$img_source->GetBYTE());
		}elsif($cevent==0xb){
			return &stref_hash_eventNewControl($cstatus&0xf,$data,$img_source->GetBYTE(),$ref_eomni,$img_source);
		}elsif($cevent==0xc){
			return &stref_hash_eventNewProgramChange($cstatus&0xf,$data);
		}elsif($cevent==0xd){
			return &stref_hash_eventNewChannelPressure($cstatus&0xf,$data);
		}elsif($cevent==0xe){
			return &stref_hash_eventNewPitchBend($cstatus&0xf,$data|($img_source->GetBYTE()<<7));
		}elsif(($cstatus==0xf0)||($cstatus==0xf7)){
			$img_source->SetCurrent($img_source->GetCurrent()-1);
			return &stref_hash_eventNewSysEx($cstatus,$img_source->GetSub(&LOAD_stvlRead($img_source)))
		}elsif($cstatus==0xff){
			return &stref_hash_eventNewMeta($data,$img_source->GetSub(&LOAD_stvlRead($img_source)));
		}
		return {
			'Status'=>$cstatus,
			'Type'=>'Unknown'
		};
	}
}

1;
