#!/usr/bin/perl
##############################################################################
##																			##
##																			##
##									M68K									##
##																			##
##	'M68K_TMX2BIN.pl'								2026 written by int71	##
##############################################################################
use strict;
use integer;
$INC[@INC]='/usr/local/ofw/lib';
require 'base.pl';
my($sVersion,$sDate)=('1.55','2026/09/03');
my($CLASS_sStage)='STAGE';
my($CLASS_STAGE_sArea)='AREA';
my($CLASS_STAGE_sBGM)='BGM_PLAY';
my($CLASS_STAGE_sSetScroll)='SETSCROLL';
my($CLASS_sScroll)='SCROLL';
my($CLASS_SCROLL_sSetPattern)='SETPATTERN';
my($CLASS_SCROLL_sSetBGPalette)='SETBGPALETTE';
my($CLASS_SCROLL_sSetHSpeed)='SETHSPEED';
my($CLASS_SCROLL_sSetVRange256)='SETVRANGE256';
my($CLASS_sNormal)='NORMAL';
my($CLASS_sTerrain)='TERRAIN';

new BASE::();

sub main{
	my($argument,$option)=@_;
	my($source,%switch);

	if(defined $$option{'v'}){
		&USR_stShowVersion();
		return 0;
	}elsif(defined $$option{'h'}){
		&USR_stShowHelp();
		return 0;
	}else{
		if($$argument[0] ne ''){
			$source=$$argument[0];
		}else{
			&USR_stShowHelp();
			return 0;
		}
		if($$option{'o'} ne ''){
			$switch{'NameBIN'}=$$option{'o'};
			if(substr($switch{'NameBIN'},-4) eq '.bin'){
				$switch{'NameBIN'}=substr($switch{'NameBIN'},0,length($switch{'NameBIN'})-4);
			}
		}else{
			$switch{'NameBIN'}=$source;
		}
		if($$option{'c'} ne ''){
			$switch{'NameCPP'}=$$option{'c'};
			if(substr($switch{'NameCPP'},-4) eq '.cpp'){
				$switch{'NameCPP'}=substr($switch{'NameCPP'},0,length($switch{'NameCPP'})-4);
			}
		}else{
			$switch{'NameCPP'}=$source;
		}
		if($$option{'j'} ne ''){
			$switch{'Project'}=$$option{'j'};
		}else{
			$switch{'Project'}='ORE68000ACE';
		}
		if($$option{'p'} ne ''){
			$switch{'Palette'}=$$option{'p'}&15;
		}else{
			$switch{'Palette'}=0x0;
		}
		if($$option{'ps'} ne ''){
			foreach(split(/\,/,$$option{'ps'})){
				my($iiy,$iipalette)=split(/\=/);

				if(($iiy ne '')&&($iipalette ne '')){
					$switch{'PaletteSpecific'}{$iiy+0}=($iipalette&15)<<12;
				}
			}
		}else{
			$switch{'PaletteSpecific'}={};
		}
		if($$option{'f'} ne ''){
			foreach(split(/\,/,$$option{'f'})){
				$switch{'StageSpecific'}{$_}='';
			}
		}else{
			undef $switch{'StageSpecific'};
		}
		if($$option{'t'} ne ''){
			$switch{'Transpose'}=$$option{'t'}
		}else{
			$switch{'Transpose'}=0;
		}
	}
	{
		my($img_destination,$img_destination_c)=&USR_stTMX2BIN($source,\%switch);

		if(defined $$option{'d'}){
			if(defined $img_destination_c){
				my($line);

				$img_destination_c->SetCurrent(0);
				while(defined($line=$img_destination_c->GetLINE())){
					BASE::Print("$line\n");
				}
			}
		}elsif(defined $$option{'dx'}){
			my($ndata)=$img_destination->GetSize()>>1;

			if($ndata){
				my($idata);

				$img_destination->SetCurrent(0);
				BASE::Print(sprintf("0x%04x",$img_destination->GetWORD_B()));
				for($idata=1;$idata<$ndata;++$idata){
					BASE::Print(sprintf(",0x%04x",$img_destination->GetWORD_B()));
				}
				BASE::Print("\n");
			}
		}else{
			$img_destination->Save("$switch{'NameBIN'}.bin");
			if(defined $img_destination_c){
				$img_destination_c->Save("$switch{'NameCPP'}.cpp");
			}
		}
	}
	return 0;
}

sub USR_stShowVersion{
	BASE::Print("M68K_TMX2BIN Version $sVersion Release $sDate Written by int71\n");
	return;
}

sub USR_stShowHelp{
	BASE::Print(<<END
<概要>
  「.tmx」形式マップファイルをBGアトリビュート形式バイナリに変換します。

<書式>
$BASE::Self (入力).tmx [-v] [-h] [-o (出力).bin] [-c (Cソース).cpp] [-j (プロジェクト名)] [-p (パレット番号)] [-ps (タイルY座標)=(パレット番号)[,...]] [-t 0|1] [-f (ステージ固有フラグ)[,...]] [-d] [-dx]

<オプション>
-v: バージョンを表示します。
-h: このメッセージを表示します。
-o: 出力ファイル名を指定します。デフォルト値は「(入力).bin」です。
-c: 出力イベントCソースファイル名を指定します。デフォルト値は「(入力).cpp」です。
-j: Cソースファイル内コメントとして記載するプロジェクト名を指定します。デフォルト値は「ORE68000ACE」です。
-p: パレット番号を指定します。デフォルト値は「0」です。パレット違いの同一画像を複数タイルセットとする場合、この指定値は「基準値」となり、タイルセット番号がオフセットとなります。例えば4タイルセット存在する状態で「-p 2」と指定すると、パレット番号は「2～5」が使用される事になります。
-ps:パレット番号をタイルY座標単位で個別指定します。カンマ区切りで列挙でき、「30=15,31=15」と書けば「タイルY座標30、31のタイルのみパレット15」という意味になります。
-t: 「0」を指定すると「横(列)方向のデータを縦(行)方向」に、「1」を指定すると「縦(行)方向のデータを横(列)方向」に出力します。デフォルト値は「0」です。
-f: 当該「ステージ固有フラグ」をONにします。カンマ区切りで列挙でき、現状下記を指定できます。
    RistrictedMissile:ミサイルが地形で這わなくなります。
-d: ファイルでなく標準出力に出力します。現状「Cソースファイル」のみの出力です。
-dx: 「(出力).bin」データの内容「のみ」を1行のC配列形式「0xnn[,...]」で表示します。

<「(入力).tmx」について>
・マップサイズ
  スクロール前景(「MAP」)/背景(「BACK」)用途なら「縦幅」、特殊画像(「SPECIAL」)用途なら「横幅」が「2の累乗である」必要があります。

・タイルサイズ
  自動判別しますが、マップを構成するタイルの横幅は「2の累乗である」事を前提とします。
  もしそうでなければ、「左端2タイル分はパレット定義領域である」と解釈します。

・イベント属性
  「イベント」扱いさせるためには、属性値「名前」と「Class」の設定が必須です。
  これら属性値には「//」でコメントを付ける事が出来るため、文字列が「//」で始まっていると、「イベント」扱いされません。

<「(Cソース).cpp」について>
・メタ文字
  「Tiled」上で見える「名前」、「カスタムプロパティ」にはメタ文字を含める事ができ、「(Cソース).cpp」出力時に置換されます。
  これにより、同一属性情報による別クラス指定を行う事ができます。
  メタ文字は下記を使用できます。

    \${H}:「Tiled」オブジェクト左右反転属性無し時「R」、あり時「L」で置換。
    \${V}:「Tiled」オブジェクト左右反転属性上下反転無し時「U」、あり時「D」で置換。

・イベント発生契機
  「(Cソース).cpp」内では一貫して「スクロール位置」がイベント発生契機になっていますが、「マップと位置を合わせつつ画面右から出現」させたいオブジェクトの場合、「オブジェクト位置」と「スクロール位置」の間にオフセットが必要です。
  一方「スクロール停止イベント」のように「スクロール位置」そのままを契機にしたい場合もあります。

  ・「画面右表示開始」がイベント契機(デフォルト)
    「(Cソース).cpp」内に記載される「発生タイミング」座標が、「Tiled」座標より「画面幅(+オブジェクト幅÷2)」分だけマイナスされます。
    「敵」のように「マップと位置を合わせつつ画面右から出現」させたいオブジェクトに使用します。
    これはデフォルトの動作になります。

  ・「スクロール位置の到達」がイベント契機
    「(Cソース).cpp」内に記載される「発生タイミング」座標は「Tiled」座標そのもの(もしくは「オブジェクト幅÷2」分だけプラス)になります。
    「イベントオブジェクト起点の右1画面全体が表示された時点」を契機にしたい場合の他、「画面左から出現」させたいオブジェクトにも使用できます。
    「Tiled」オブジェクトに左右反転属性付与、もしくは「カスタムプロパティ」に名前「.trigger」、値「left」を指定する事でこの扱いになります。
    ただし左右反転属性を付与していても、「.trigger」に「right」を指定している場合は通常通り「画面右表示開始」がイベント契機となります。

  ・イベント発生と無関係
    「(Cソース).cpp」内に記載されない「発生タイミング」無関係のオブジェクトで、座標補正は行われません。
    エリアイベント(Class:「STAGE」、名前:「AREA」)が該当します。

・イベント発生タイミング
  「イベント発生契機」の種類、イベント設置X座標のどちらも同一である場合、Y座標が若い(上にある)方が発生順として「先」になります。

・イベント発生先行
  イベント「スクロール位置」より先行して「画面外に配置」したい、例えばイベント「スクロール位置」をずらしつつ処理開始を同一タイミングに合わせたい等の場合があります。
  「カスタムプロパティ」に名前「.precede」、値「先行幅(数値)」を指定する事でイベント発生タイミングが早まります。
  「.delay」とは排他です。

・イベント発生遅延
  「画面左右端以外の位置から出現」させたい、つまり「マップと位置を合わせつつ、イベント生成タイミングを特定スクロール位置到達時点に変更」させたい場合があります。
  「カスタムプロパティ」に名前「.delay」、値「スクロール位置(数値)」を指定する事でこの扱いになります。
  イベント生成タイミング変更に向け「(Cソース).cpp」内処理を待たせるため、必要に応じて「STAGE_NONE」イベントが追加されます。
  「.precede」とは排他です。

・復活固定イベント配置
  地形固定敵イベント(Class:「TERRAIN」)は、復活時に画面内配置するため「先行的」にイベント登録を行います。
  イベントデータから見ると、開始スクロール位置より「過去(左方向)」のイベントが記録される事になり、
  「地形固定敵イベント位置」から「イベント開始スクロール位置」を減じた結果の(負の)値を、
  「画面右端起点での左方向オフセット」と見なす事で画面内配置する事ができます。
END
	);
	return;
}

sub USR_stTMX2BIN{
	my($source,$ref_switch)=@_;
	my(@array_ref_array_attribute,$nwidth);
	my(@array_ref_event);
	my($cpalettebase)=$$ref_switch{'Palette'};
	my($ref_palettespecific)=$$ref_switch{'PaletteSpecific'};
	my($inpatternwidthbit);
	my($inpaletteunit);
	my($inpatternwidth);
	my($inpatternwidthwithpalette);
	my($sub_pattern);
	my($icfirstid_current);

	$nwidth=0;
	{
		my($img_source);

		$img_source=new BASE_IMAGE::($source);
		$img_source->SetCurrent(0);
		while(defined ($_=$img_source->GetLINE())){
			if(/\<tileset\s+firstgid\=\"(\d+)\"\s+name\=\"(\S+)\"\s+tilewidth\=\"(\d+)\"\s+tileheight\=\"(\d+)\"\s+tilecount\=\"(\d+)\"\s+columns\=\"(\d+)\"/){
				my($icfirstid,$sname,$intilewidth,$intileheight,$intile,$inwidth)=($1,$2,$3,$4,$5,$6);

				$icfirstid_current=$icfirstid;
				#	タイルセット
				if($icfirstid==1){
					#	マップデータを成すタイルセットは複数あるやも知れぬが、
					#	基本パラメータは属性「firstgid="1"」の「tileset」であると解釈。
					#	まずはタイルサイズからビット幅(2の累乗)算出。
					for($inpatternwidthbit=1;(1<<$inpatternwidthbit)<=$inwidth;++$inpatternwidthbit){
						$inpatternwidth=1<<$inpatternwidthbit;
					}
					--$inpatternwidthbit;
					$inpaletteunit=$intile;
					$inpatternwidthwithpalette=$inpatternwidth+2;
					#	端数無ければ横幅「2の累乗ジャスト」、あればパレット指定ありの「2の累乗+2」と解釈
					$sub_pattern=($inpatternwidth==$inwidth)?sub{
						my($ipattern)=@_;
						my($cpalette);

						--$ipattern;
						$cpalette=($cpalettebase+int($ipattern/$inpaletteunit))<<12;
						$ipattern=($ipattern%$inpaletteunit)&1023;
						{
							my($iiy)=$ipattern>>$inpatternwidthbit;

							if(exists $$ref_palettespecific{$iiy}){
								return $ipattern|$$ref_palettespecific{$iiy};
							}
						}
						return $ipattern|$cpalette;
					}:sub{
						my($ipattern)=@_;
						my($cpalette);

						--$ipattern;
						$ipattern=(($ipattern/$inpatternwidthwithpalette)<<$inpatternwidthbit)+($ipattern%$inpatternwidthwithpalette)-2;
						$cpalette=($cpalettebase+int($ipattern/$inpaletteunit))<<12;
						$ipattern=($ipattern%$inpaletteunit)&1023;
						{
							my($iiy)=$ipattern>>$inpatternwidthbit;

							if(exists $$ref_palettespecific{$iiy}){
								return $ipattern|$$ref_palettespecific{$iiy};
							}
						}
						return $ipattern|$cpalette;
					};
				}
				while(defined ($_=$img_source->GetLINE())){
					if(/\<\/tileset/){
						last;
					}
				}
			}elsif(/\<data\s+/){
				my($iy)=0;

				#	マップデータ
				while(defined ($_=$img_source->GetLINE())){
					if(/\<\/data/){
						last;
					}else{
						$array_ref_array_attribute[$iy]=[];
						{
							my($ref_array_attribute)=$array_ref_array_attribute[$iy];
							my($ix)=0;

							foreach(split(/\,/)){
								my($cattribute)=$_;
								my($ipattern)=$cattribute&~0xc0000000;
								my($einverth)=(($cattribute&0x80000000)!=0);
								my($einvertv)=(($cattribute&0x40000000)!=0);

								if($ipattern){
									$ipattern=$sub_pattern->($ipattern);
								}
								$$ref_array_attribute[$ix]=$ipattern|($einverth<<10)|($einvertv<<11);
								++$ix;
							}
							$nwidth=($nwidth<$ix)?$ix:$nwidth;
						}
						++$iy;
					}
				}
			}elsif(/\<objectgroup\s+id\=\"\d+\"\s+name\=\"EVENT\"/){
				my($ref_event);

				#	イベントデータ
				undef $ref_event;
				while(defined ($_=$img_source->GetLINE())){
					if(/\<\/objectgroup/){
						last;
					}else{
						if(/\<object\s+id\=\"(\d+)"\s+name\=\"(\S+)\"\s+type\=\"(\S+)\"\s+gid\=\"(\d+)\"\s+x\=\"(\-?\d+)\"\s+y\=\"(\-?\d+)\"\s+width\=\"(\d+)\"\s+height\=\"(\d+)\"/){
							my($id,$name,$class,$gid,$ix,$iy,$nwidth,$nheight)=($1,$2,$3,$4,$5,$6,$7,$8);

							$name=&USR_RemoveComment($name);
							$class=&USR_RemoveComment($class);
							if(($name ne '')&&($class ne '')){
								my($nevent)=scalar(@array_ref_event);

								#	タイル
								$array_ref_event[$nevent]={
									'ID'=>$id,
									'Name'=>$name,
									'Class'=>$class,
									'GID'=>$gid,
									'X'=>$ix,
									'Y'=>$iy,
									'Width'=>$nwidth,
									'Height'=>$nheight,
									'Argument'=>[]
								};
								$ref_event=$array_ref_event[$nevent];
							}else{
								undef $ref_event;
							}
						}elsif(/\<object\s+id\=\"(\d+)"\s+name\=\"(\S+)\"\s+type\=\"(\S+)\"\s+x\=\"(\-?\d+)\"\s+y\=\"(\-?\d+)\"\s+width\=\"(\d+)\"\s+height\=\"(\d+)\"/){
							my($id,$name,$class,$ix,$iy,$nwidth,$nheight)=($1,$2,$3,$4,$5,$6,$7);

							$name=&USR_RemoveComment($name);
							$class=&USR_RemoveComment($class);
							if(($name ne '')&&($class ne '')){
								my($nevent)=scalar(@array_ref_event);

								#	四角形
								$array_ref_event[$nevent]={
									'ID'=>$id,
									'Name'=>$name,
									'Class'=>$class,
									'GID'=>'',
									'X'=>$ix,
									'Y'=>$iy,
									'Width'=>$nwidth,
									'Height'=>$nheight,
									'Argument'=>[]
								};
								$ref_event=$array_ref_event[$nevent];
							}else{
								undef $ref_event;
							}
						}elsif(/\<object\s+id\=\"(\d+)"\s+name\=\"(\S+)\"\s+type\=\"(\S+)\"\s+x\=\"(\-?\d+)\"\s+y\=\"(\-?\d+)\"/){
							my($id,$name,$class,$ix,$iy)=($1,$2,$3,$4,$5);

							$name=&USR_RemoveComment($name);
							$class=&USR_RemoveComment($class);
							if(($name ne '')&&($class ne '')){
								my($nevent)=scalar(@array_ref_event);

								#	点
								$array_ref_event[$nevent]={
									'ID'=>$id,
									'Name'=>$name,
									'Class'=>$class,
									'GID'=>'',
									'X'=>$ix,
									'Y'=>$iy,
									'Width'=>0,
									'Height'=>0,
									'Argument'=>[]
								};
								$ref_event=$array_ref_event[$nevent];
							}else{
								undef $ref_event;
							}
						}elsif(defined $ref_event){
							if(/\<property\s+name\=\"(\S+)\"\s+type\=\"(\S+)\"\s+value\=\"(\S+)\"/){
								my($name,$type,$value)=($1,$2,$3);

								$name=&USR_RemoveComment($name);
								$type=&USR_RemoveComment($type);
								if(($name ne '')&&($type ne '')){
									if(substr($name,0,1) eq '.'){
										#	「.」で始まる「カスタムプロパティ」は内部制御用
										$$ref_event{BASE::STRING_Lower(substr($name,1))}=$value;
									}else{
										my($nargument)=scalar(@{$$ref_event{'Argument'}});

										#	文字列以外の属性としてイベント引数に
										$$ref_event{'Argument'}[$nargument]={
											'Name'=>$name,
											'Type'=>$type,
											'Value'=>$value
										};
									}
								}else{
									undef $ref_event;
								}
							}elsif(/\<property\s+name\=\"(\S+)\"\s+value\=\"(\S+)\"/){
								my($name,$value)=($1,$2);

								$name=&USR_RemoveComment($name);
								if($name ne ''){
									if(substr($name,0,1) eq '.'){
										$$ref_event{BASE::STRING_Lower(substr($name,1))}=$value;
									}else{
										my($nargument)=scalar(@{$$ref_event{'Argument'}});

										#	文字列の属性としてイベント引数に
										$$ref_event{'Argument'}[$nargument]={
											'Name'=>$name,
											'Type'=>'',
											'Value'=>$value
										};
									}
								}else{
									undef $ref_event;
								}
							}
						}
					}
				}
			}
		}
	}
	{
		my($img_destination,$img_destination_c);

		{
			my($nheight)=scalar(@array_ref_array_attribute);

			#	マップデータまとめ
			$img_destination=new BASE_IMAGE::();
			if($$ref_switch{'Transpose'}==0){
				my($iy);

				for($iy=0;$iy<$nheight;++$iy){
					my($ref_array_attribute)=$array_ref_array_attribute[$iy];
					my($ix);

					for($ix=0;$ix<$nwidth;++$ix){
						$img_destination->SetWORD_B($$ref_array_attribute[$ix]);
					}
				}
			}else{
				my($ix);

				for($ix=0;$ix<$nwidth;++$ix){
					my($iy);

					for($iy=0;$iy<$nheight;++$iy){
						$img_destination->SetWORD_B($array_ref_array_attribute[$iy][$ix]);
					}
				}
			}
		}
		if(scalar(@array_ref_event)){
			my(@array_ref_area);
			my(@array_ref_eventrestart_stage_bgm);
			my(@array_ref_eventrestart_stage_pattern);
			my(@array_ref_eventrestart_stage_scroll);

			{
				my($nevent)=scalar(@array_ref_event);

				#	イベントデータまとめ
				$img_destination_c=new BASE_IMAGE::();
				foreach my($ref_event)(@array_ref_event){
					if(exists $$ref_event{'parent'}){
						my($idparent)=$$ref_event{'parent'};

						foreach my($ref_event_parent)(@array_ref_event){
							if($$ref_event_parent{'ID'} eq $idparent){
								$$ref_event{'Parent'}=$ref_event_parent;
								last;
							}
						}
					}
				}
				#	エリア情報整理
				for(my($ievent)=0;$ievent<$nevent;++$ievent){
					my($ref_event)=$array_ref_event[$ievent];

					if($$ref_event{'Class'} eq $CLASS_sStage){
						if($$ref_event{'Name'} eq $CLASS_STAGE_sArea){
							#	エリア
							$array_ref_area[scalar(@array_ref_area)]={
								'HScroll'=>$$ref_event{'X'},
								'Event'=>[],
								'EventRestart'=>[]
							};
							splice(@array_ref_event,$ievent,1);
							--$nevent;
							--$ievent;
						}elsif($$ref_event{'Name'} eq $CLASS_STAGE_sBGM){
							#	復活時に明示的に含めるべきイベント「BGM」
							push(@array_ref_eventrestart_stage_bgm,$ref_event);
						}elsif($$ref_event{'Name'} eq $CLASS_STAGE_sSetScroll){
							#	復活時に明示的に含めるべきイベント「スクロール」
							push(@array_ref_eventrestart_stage_scroll,$ref_event);
						}
					}elsif($$ref_event{'Class'} eq $CLASS_sScroll){
						if(
							($$ref_event{'Name'} eq $CLASS_SCROLL_sSetPattern)||
							($$ref_event{'Name'} eq $CLASS_SCROLL_sSetBGPalette)
						){
							#	復活時に明示的に含めるべきイベント「パターン」
							push(@array_ref_eventrestart_stage_pattern,$ref_event);
						}elsif(
							($$ref_event{'Name'} eq $CLASS_SCROLL_sSetHSpeed)||
							($$ref_event{'Name'} eq $CLASS_SCROLL_sSetVRange256)
						){
							#	復活時に明示的に含めるべきイベント「スクロール」
							push(@array_ref_eventrestart_stage_scroll,$ref_event);
						}
					}
				}
				#	データ整理
				foreach my($ref_event)(@array_ref_event){
					&USR_Make($ref_event);
				}
				#	親子参照解決
				#	データ整理と分けているのは、前方参照がありうるから。
				foreach my($ref_event)(@array_ref_event){
					&USR_SolveParent($ref_event);
				}
				#	所属エリアは右から左に検索するので一旦降順ソート
				@array_ref_area=sort{$$b{'HScroll'}<=>$$a{'HScroll'}}(@array_ref_area);
				#	イベント整理
				for(my($ievent)=0;$ievent<$nevent;++$ievent){
					my($ref_event)=$array_ref_event[$ievent];
					my($ref_area);

					if($$ref_event{'Class'} eq $CLASS_sTerrain){
						my($narea)=scalar(@array_ref_area);
						my($iarea);

						for($iarea=0;$iarea<$narea;++$iarea){
							my($ref_area)=$array_ref_area[$iarea];

							if($$ref_area{'HScroll'}<=$$ref_event{'X'}){
								if($$ref_area{'HScroll'}<=$$ref_event{'SortKey'}){
									#	両方の座標で当該エリアに含まれる事が分かったので「復活」枠考慮不要
									push(@{$$ref_area{'Event'}},$ref_event);
									last;
								}else{
									#	当該エリアでは「復活」時のみ含まれる
									push(@{$$ref_area{'EventRestart'}},$ref_event);
									for(;$iarea<$narea;++$iarea){
										$ref_area=$array_ref_area[$iarea];
										if($$ref_area{'HScroll'}<=$$ref_event{'HScroll'}){
											#	通常進行での所属エリア決定
											push(@{$$ref_area{'Event'}},$ref_event);
											last;
										}
									}
									last;
								}
							}
						}
					}else{
						foreach $ref_area(@array_ref_area){
							if($$ref_area{'HScroll'}<=$$ref_event{'SortKey'}){
								#	所属エリア判明
								if($$ref_event{'restart'} eq 'true'){
									push(@{$$ref_area{'EventRestart'}},$ref_event);
									splice(@array_ref_event,$ievent,1);
									--$nevent;
									--$ievent;
								}else{
									push(@{$$ref_area{'Event'}},$ref_event);
								}
								last;
							}
						}
					}
				}
			}
			#	同じく復活用イベントも降順ソート
			@array_ref_eventrestart_stage_bgm=&USR_array_ref_Sort(\@array_ref_eventrestart_stage_bgm);
			@array_ref_eventrestart_stage_pattern=&USR_array_ref_Sort(\@array_ref_eventrestart_stage_pattern);
			@array_ref_eventrestart_stage_scroll=&USR_array_ref_Sort(\@array_ref_eventrestart_stage_scroll);
			#	所属エリアが一通り決まったので改めて昇順ソート
			@array_ref_area=sort{$$a{'HScroll'}<=>$$b{'HScroll'}}(@array_ref_area);
			#	結果発表
			{
				my($sfile)=BASE::STRING_GetFile($$ref_switch{'NameCPP'});
				my($sclass)=BASE::STRING_Upper($sfile);
				my($sidclass);
				my($sorderroot);

				$sclass=~s/\.//g;
				$sidclass=$sclass;
				$sorderroot=$sclass;
				{
					my($idelimiter)=index($sidclass,'_');

					if(0<$idelimiter){
						$sidclass=substr($sidclass,$idelimiter+1);
						$sorderroot=$sidclass;
					}
				}
				$sidclass=substr($sidclass,0,1).BASE::STRING_Lower(substr($sidclass,1));
				$img_destination_c->AddTEXT(<<END
/****************************************************************************
**																			**
**																			**
END
				);
				$img_destination_c->AddLINE('**'.&USR_sTabCenter($$ref_switch{'Project'},19).'**');
				$img_destination_c->AddTEXT(<<END
**																			**
END
				);
				$img_destination_c->AddLINE("**\t".&USR_sTabLeft("'$$ref_switch{'NameCPP'}.cpp'",12)."2026 written by int71\t**");
				$img_destination_c->AddTEXT(<<END
 ****************************************************************************/

//
//		include
//

END
				);
				if(defined $$ref_switch{'StageSpecific'}){
					$img_destination_c->AddTEXT(<<END
#include				"../game.hpp"
END
					);
				}else{
					$img_destination_c->AddTEXT(<<END
#include				"../event.hpp"
END
					);
				}
				$img_destination_c->AddTEXT(<<END
#include				"$sfile.hpp"

//
//		using
//

using namespace m68k::oredius68k::main::stage;


//
//		class:$sclass
//

//	private

VOID					${sclass}::Attach_Self(VOID)noexcept{
	OREDIUS68K_CHECKINHERITANCE;
	STAGE_::Attach_Self();
END
				);
				if(defined $$ref_switch{'StageSpecific'}){
					my($sflag);

					$img_destination_c->AddTEXT(<<END
	{
		AUTO&					spcfthis=GAME::STAGE_stspcfDelegateThis();

END
					);
					foreach $sflag(keys %{$$ref_switch{'StageSpecific'}}){
						$img_destination_c->AddTEXT(<<END
		spcfthis.e$sflag=TRUE;
END
						);
					}
					$img_destination_c->AddTEXT(<<END
	}
END
					);
				}
				$img_destination_c->AddTEXT(<<END
	idClass=IDCLASS::$sidclass;
	return;
}

VOID					${sclass}::Detach_Self(VOID)noexcept{
	STAGE_::Detach_Self();
	return;
}

PCUINT8					${sclass}::pcui8Start_Self(VOID)noexcept{
END
				);
				{
					my($narea)=scalar(@array_ref_area);
					my($iarea);

					#	イベント整理:エリア(本体)
					for($iarea=0;$iarea<$narea;++$iarea){
						my($ref_area)=$array_ref_area[$iarea];
						my($ref_array_ref_event)=$$ref_area{'Event'};
						my($sarea)=sprintf("%02x",$iarea);
						my($sorder)=sprintf("%s-0-%02X",$sorderroot,$iarea);

						$img_destination_c->AddTEXT(<<END
	//	AREA$iarea:BODY
	static constexpr _ORDERED_("$sorder") UINT8	acui8event${sarea}body[]={
END
						);
						#	「イベント発生遅延」の有無チェック
						{
							my(%hash_idelayhscroll);
							my($idelayhscroll);

							foreach(@$ref_array_ref_event){
								if(exists $$_{'SortKey'}){
									if($$_{'SortKey'}!=$$_{'HScroll'}){
										$hash_idelayhscroll{$$_{'SortKey'}}='';
									}
								}
							}
							foreach $idelayhscroll(keys %hash_idelayhscroll){
								my($eexists)=0;

								#	遅延タイミングでのイベント有無チェック
								foreach(@$ref_array_ref_event){
									if($idelayhscroll==$$_{'HScroll'}){
										#	遅延タイミングでのイベントがあったので「$idelayhscroll」時点の「STAGE_NONE」追加は不要
										$eexists=1;
										last;
									}
								}
								if(!$eexists){
									push(@$ref_array_ref_event,{
										'ID'=>'',
										'Name'=>'NONE',
										'Class'=>$CLASS_sStage,
										'GID'=>'',
										'X'=>$idelayhscroll,
										'Y'=>0,
										'Width'=>0,
										'Height'=>0,
										'Argument'=>[],
										'HInvert'=>'',
										'VInvert'=>'',
										'HScroll'=>$idelayhscroll,
										'SortKey'=>$idelayhscroll
									});
								}
							}
						}
						#	エリア内イベントを昇順ソート
						@$ref_array_ref_event=sort{
							($$a{'SortKey'}==$$b{'SortKey'})?(
								($$a{'HScroll'}==$$b{'HScroll'})?(
									($$a{'SortSubKey'}==$$b{'SortSubKey'})?(
										$$a{'Y'}<=>$$b{'Y'}
									):(
										$$a{'SortSubKey'}<=>$$b{'SortSubKey'}
									)
								):(
									$$b{'HScroll'}<=>$$a{'HScroll'}	#	遅延せき止め用「STAGE_NONE」イベントを前方に持ってくるため降順に
								)
							):(
								$$a{'SortKey'}<=>$$b{'SortKey'}
							)
						}(@$ref_array_ref_event);
						{
							my($nevent)=scalar(@$ref_array_ref_event);

							if(0<$nevent){
								my($ievent);

								for($ievent=0;$ievent<$nevent;++$ievent){
									my($ref_event)=$$ref_array_ref_event[$ievent];
									my($scode)=&USR_sGetCode($ref_event);

									if($ievent<$nevent-1){
										$scode.=',';
									}
									$img_destination_c->AddTEXT(<<END
		$scode
END
									);
								}
							}else{
								$img_destination_c->AddTEXT(<<END
		EVENT_STAGE_NONE($$ref_area{'HScroll'})
END
								);
							}
						}
						$img_destination_c->AddTEXT(<<END
	};
END
						);
						if($iarea==0){
							$img_destination_c->AddTEXT(<<END
	static constexpr INT32	ci32doffset${sarea}body=0;
END
							);
						}else{
							my($sarea_previous)=sprintf("%02x",$iarea-1);

							$img_destination_c->AddTEXT(<<END
	static constexpr INT32	ci32doffset${sarea}body=ci32doffset${sarea_previous}body+ci32nsize${sarea_previous}body;
END
							);
						}
						$img_destination_c->AddTEXT(<<END
	static constexpr INT32	ci32nsize${sarea}body=INT32(SIZEOF(acui8event${sarea}body));
END
						);
					}
					#	イベント整理:エリア(エントリ(復活))
					for($iarea=0;$iarea<$narea;++$iarea){
						my($ref_area)=$array_ref_area[$iarea];
						my($ref_array_ref_event)=$$ref_area{'Event'};
						my($ref_array_ref_eventrestart)=$$ref_area{'EventRestart'};
						my($sarea)=sprintf("%02x",$iarea);
						my($sorder)=sprintf("%s-1-%02X",$sorderroot,$iarea);
						my($ihscroll)=$$ref_area{'HScroll'};
						my(@array_scode);
						my($ref_event);

						#	エリア内復活用イベントを昇順ソート
						@$ref_array_ref_eventrestart=sort{
							($$a{'SortKey'}==$$b{'SortKey'})?(
								($$a{'HScroll'}==$$b{'HScroll'})?(
									($$a{'SortSubKey'}==$$b{'SortSubKey'})?(
										$$a{'Y'}<=>$$b{'Y'}
									):(
										$$a{'SortSubKey'}<=>$$b{'SortSubKey'}
									)
								):(
									$$b{'HScroll'}<=>$$a{'HScroll'}	#	遅延せき止め用「STAGE_NONE」イベントを前方に持ってくるため降順に
								)
							):(
								$$a{'SortKey'}<=>$$b{'SortKey'}
							)
						}(@$ref_array_ref_eventrestart);
						#	復活用イベントなので過去イベント、つまりキースクロール座標が若いので冒頭で追加
						foreach $ref_event(@$ref_array_ref_eventrestart){
							push(@array_scode,&USR_sGetCode($ref_event));
						}
						#	補完すべきイベントの収集
						foreach $ref_event(@array_ref_eventrestart_stage_bgm){
							if($$ref_event{'HScroll'}==$ihscroll){
								#	エリア開始時点で明示的指定があったので追加不要
								last;
							}elsif($$ref_event{'HScroll'}<$ihscroll){
								#	明示的指定が無いので直前のイベントから拝借
								push(@array_scode,&USR_sGetCode($ref_event,$ihscroll));
								last;
							}
						}
						foreach $ref_event(@array_ref_eventrestart_stage_pattern){
							if($$ref_event{'HScroll'}==$ihscroll){
								#	エリア開始時点で明示的指定があったので追加不要
								last;
							}elsif($$ref_event{'HScroll'}<$ihscroll){
								#	明示的指定が無いので直前のイベントから拝借
								push(@array_scode,&USR_sGetCode($ref_event,$ihscroll));
								last;
							}
						}
						foreach $ref_event(@array_ref_eventrestart_stage_scroll){
							if($$ref_event{'HScroll'}==$ihscroll){
								#	エリア開始時点で明示的指定があれば追加不要であるが、
								#	「SETSCROLL」以外だと役不足であるので、
								#	引数合成が行われているようであれば直前のイベントから拝借
								if($$ref_event{'Merged'}){
									push(@array_scode,&USR_sGetCode($ref_event,$ihscroll));
								}
								last;
							}elsif($$ref_event{'HScroll'}<$ihscroll){
								#	明示的指定が無いので直前のイベントから拝借
								push(@array_scode,&USR_sGetCode($ref_event,$ihscroll));
								last;
							}
						}
						if(scalar(@array_scode)==0){
							$_='';
						}else{
							$_=join(',
		',@array_scode);

							$_=<<END;

		$_
END
							$_.='	';
						}
						$img_destination_c->AddTEXT(<<END
	//	AREA$iarea:ENTRY
	static constexpr _ORDERED_("$sorder-0") UINT8	acui8event${sarea}[]={$_};
END
						);
						if($iarea==0){
							my($sarea_previous)=sprintf("%02x",$narea-1);

							$img_destination_c->AddTEXT(<<END
	static constexpr INT32	ci32doffset${sarea}=ci32doffset${sarea_previous}body+ci32nsize${sarea_previous}body;
END
							);
						}else{
							my($sarea_previous)=sprintf("%02x",$iarea-1);

							$img_destination_c->AddTEXT(<<END
	static constexpr INT32	ci32doffset${sarea}=ci32doffset${sarea_previous}+ci32nsize${sarea_previous};
END
							);
						}
						$img_destination_c->AddTEXT(<<END
	static constexpr INT32	ci32nsize${sarea}=INT32(SIZEOF(acui8event${sarea})+EVENT::stci32nEVENT_JUMP);
	DECL_EVENT_JUMP("$sorder-1",$ihscroll,ci32doffset${sarea}+ci32nsize${sarea},ci32doffset${sarea}body);
END
						);
					}
					#	イベント整理:残り
					$img_destination_c->AddTEXT(<<END
	AUTO					pcui8start=STAGE_::pcui8Start_Self();

END
					);
					#	復活ポイント処理
					for($iarea=0;$iarea<$narea;++$iarea){
						my($ref_area)=$array_ref_area[$iarea];
						my($ihscroll)=$$ref_area{'HScroll'};
						my($ihscroll_next);
						my($sarea)=sprintf("%02x",$iarea);

						undef $ihscroll_next;
						if($iarea+1<$narea){
							$ihscroll_next=$array_ref_area[$iarea+1]{'HScroll'};
						}
						if($iarea==0){
							if(defined $ihscroll_next){
								$img_destination_c->AddTEXT(<<END
	if(SCROLL_i32iHPosition<($ihscroll_next<<FIXEDL_stcui8nBit)){
		SCROLL_i32iHPosition=$ihscroll<<FIXEDL_stcui8nBit;
		pcui8start=PCUINT8(acui8event$sarea);
END
								);
							}else{
								$img_destination_c->AddTEXT(<<END
	SCROLL_i32iHPosition=$ihscroll<<FIXEDL_stcui8nBit;
	pcui8start=PCUINT8(acui8event$sarea);
END
								);
							}
						}else{
							if(defined $ihscroll_next){
								$img_destination_c->AddTEXT(<<END
	}else if(SCROLL_i32iHPosition<($ihscroll_next<<FIXEDL_stcui8nBit)){
		SCROLL_i32iHPosition=$ihscroll<<FIXEDL_stcui8nBit;
		pcui8start=PCUINT8(acui8event$sarea);
END
								);
							}else{
								$img_destination_c->AddTEXT(<<END
	}else{
		SCROLL_i32iHPosition=$ihscroll<<FIXEDL_stcui8nBit;
		pcui8start=PCUINT8(acui8event$sarea);
	}
END
								);
							}
						}
					}
					$img_destination_c->AddTEXT(<<END
	return pcui8start;
}

VOID					${sclass}::End_Self(VOID)noexcept{
	STAGE_::End_Self();
	return;
}
END
					);
				}
			}
		}
		return $img_destination,$img_destination_c;
	}
}

sub USR_RemoveComment{
	my($ssource)=@_;
	my($icomment)=index($ssource,'//');

	if(0<=$icomment){
		substr($ssource,$icomment)='';
	}
	return $ssource;
}

sub USR_Make{
	my($ref_event)=@_;

	if($$ref_event{'GID'} ne ''){
		$$ref_event{'HInvert'}=(($$ref_event{'GID'}&0x80000000)!=0);
		$$ref_event{'VInvert'}=(($$ref_event{'GID'}&0x40000000)!=0);
		$$ref_event{'X'}+=$$ref_event{'Width'}/2;
		$$ref_event{'Y'}+=$$ref_event{'Height'}/2-$$ref_event{'Height'};
	}else{
		$$ref_event{'HInvert'}=0;
		$$ref_event{'VInvert'}=0;
		$$ref_event{'X'}+=$$ref_event{'Width'}/2;
		$$ref_event{'Y'}+=$$ref_event{'Height'}/2;
	}
	if(
		($$ref_event{'trigger'} eq 'left')||(
			$$ref_event{'HInvert'}&&($$ref_event{'trigger'} ne 'right')
		)
	){
		#	「スクロール位置の到達」がイベント契機
		$$ref_event{'HScroll'}=$$ref_event{'X'}+$$ref_event{'Width'}/2;
	}else{
		#	「画面右表示開始」がイベント契機
		$$ref_event{'HScroll'}=$$ref_event{'X'}-(320+$$ref_event{'Width'}/2);
	}
	if($$ref_event{'HScroll'}<0){
		$$ref_event{'HScroll'}=0;
	}
	$$ref_event{'SortKey'}=$$ref_event{'HScroll'};
	$$ref_event{'SortSubKey'}=0;
	if($$ref_event{'delay'}=~/\d+/){
		if($$ref_event{'HScroll'}<$$ref_event{'delay'}){
			$$ref_event{'SortKey'}=$$ref_event{'delay'};
			$$ref_event{'SortSubKey'}=1;
		}
	}elsif($$ref_event{'precede'}=~/\d+/){
		if(0<$$ref_event{'precede'}){
			$$ref_event{'HScrollOriginal'}=$$ref_event{'HScroll'};
			$$ref_event{'HScroll'}-=$$ref_event{'precede'};
			$$ref_event{'SortKey'}=$$ref_event{'HScroll'};
			$$ref_event{'SortSubKey'}=1;
		}
	}
	return;
}

sub USR_SolveParent{
	my($ref_event)=@_;

	if(exists $$ref_event{'Parent'}){
		my($ref_event_parent)=$$ref_event{'Parent'};

		$$ref_event{'HScrollOriginal'}=$$ref_event{'HScroll'}-($$ref_event_parent{'Width'}-$$ref_event{'Width'})/2;
		$$ref_event{'HScroll'}=$$ref_event_parent{'HScroll'};
		$$ref_event{'SortKey'}=$$ref_event{'HScroll'};
		$$ref_event{'SortSubKey'}=$$ref_event_parent{'Y'};
	}
	&USR_SolveParent_Replace($ref_event,$ref_event,'Name');
	{
		my($ref_argument);

		foreach $ref_argument(@{$$ref_event{'Argument'}}){
			&USR_SolveParent_Replace($ref_event,$ref_argument,'Name');
			&USR_SolveParent_Replace($ref_event,$ref_argument,'Value');
		}
	}
	return;
}

sub USR_SolveParent_Replace{
	my($ref_event,$ref_this,$key)=@_;

	$$ref_this{$key}=BASE::STRING_Replace($$ref_this{$key},
		'${H}',
		$$ref_event{'HInvert'}?'L':'R'
	);
	$$ref_this{$key}=BASE::STRING_Replace($$ref_this{$key},
		'${V}',
		$$ref_event{'VInvert'}?'D':'U'
	);
	if(($key eq 'Value')&&(0<=index($$ref_this{$key},'${Parent}'))){
		if(exists $$ref_event{'Parent'}){
			my($ref_argument);

			foreach $ref_argument(@{$$ref_event{'Parent'}{'Argument'}}){
				if($$ref_this{'Name'} eq $$ref_argument{'Name'}){
					$$ref_this{$key}=BASE::STRING_Replace($$ref_this{$key},
						'${Parent}',
						$$ref_argument{'Value'}
					);
					last;
				}
			}
		}
		$$ref_this{$key}=BASE::STRING_Replace($$ref_this{$key},'${Parent}','');
	}
	return;
}

sub USR_sGetCode{
	my($ref_event,$ihscroll)=@_;
	my($seventclass)='EVENT_'.$$ref_event{'Class'}.'_'.$$ref_event{'Name'};
	my($iy)=$$ref_event{'Y'}>>3;
	my($sarg)=(
		($$ref_event{'Class'} eq $CLASS_sNormal)||
		($$ref_event{'Class'} eq $CLASS_sTerrain)
	)?','.$iy:'';

	if(not defined $ihscroll){
		$ihscroll=$$ref_event{'HScroll'};
	}
	foreach(@{$$ref_event{'Argument'}}){
		$sarg.=','.$$_{'Value'};
	}
	if(exists $$ref_event{'HScrollOriginal'}){
		return "EVENT_OVERRIDEHPOSITION($ihscroll),$seventclass($$ref_event{'HScrollOriginal'}$sarg)";
	}else{
		return "$seventclass($ihscroll$sarg)";
	}
}

sub USR_sTabLeft{
	my($ssource,$ntab)=@_;
	my($ntabrest);

	$ntabrest=$ntab-(length($ssource)>>2);
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

sub USR_array_ref_Sort{
	my($ref_array_ref_event)=@_;
	#	右から左に検索しやすいよう降順ソート
	my(@array_ref_event)=sort{$$b{'SortKey'}<=>$$a{'SortKey'}}(@$ref_array_ref_event);
	my($nevent)=scalar(@array_ref_event);
	my($ievent);

	#	直前イベントからの引継ぎをやりやすいよう、パラメータを前方コピー
	for($ievent=$nevent;1<$ievent;--$ievent){
		#	念のためディープコピー
		$array_ref_event[$ievent-2]={%{$array_ref_event[$ievent-2]}};
		$array_ref_event[$ievent-2]{'Argument'}=[&USR_array_ref_MergeArgument(
			$array_ref_event[$ievent-1]{'Argument'},
			$array_ref_event[$ievent-2]{'Argument'}
		)];
		#	ついでにイベント名も元から引き継いで同一化
		$array_ref_event[$ievent-2]{'Name'}=$array_ref_event[$ievent-1]{'Name'};
		$array_ref_event[$ievent-2]{'Class'}=$array_ref_event[$ievent-1]{'Class'};
		$array_ref_event[$ievent-2]{'Merged'}=1;
	}
	return @array_ref_event;
}

sub USR_array_ref_MergeArgument{
	my($ref_array_ref_argument0,$ref_array_ref_argument1)=@_;
	my(%hash_ref_argument);
	my(@array_ref_argument);

	#	引数をマージする。
	#	名は「$ref_array_ref_argument0」、値は「$ref_array_ref_argument1」を使用
	foreach(@$ref_array_ref_argument0,@$ref_array_ref_argument1){
		my(%argument)=%{$_};
		my($skey)=$argument{'Name'};
		my($idelimiter)=index($skey,':');

		if(0<$idelimiter){
			#	Tiled向け引数ソート値を除去して引数引継ぎ判定
			$skey=substr($skey,$idelimiter+1);
		}
		if(exists $hash_ref_argument{$skey}){
			#	Tiled向け引数ソート値は引継ぎ元の値から継承
			$argument{'Name'}=$hash_ref_argument{$skey}{'Name'};
		}
		$hash_ref_argument{$skey}={%argument};
	}
	#	ソート用にハッシュキーを置き換え
	#	「衝突は無い」と決め打ち
	foreach(keys %hash_ref_argument){
		my($ref_argument)=$hash_ref_argument{$_};

		delete $hash_ref_argument{$_};
		$hash_ref_argument{$$ref_argument{'Name'}}=$ref_argument;
	}
	foreach(sort keys %hash_ref_argument){
		push(@array_ref_argument,$hash_ref_argument{$_});
	}
	return @array_ref_argument;
}
