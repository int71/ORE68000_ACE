#!/usr/bin/perl
use strict;
$INC[@INC]='/usr/local/ofw/lib';
require 'base.pl';
my($CONST_fontname)='KHドット小伝馬町16 幾何学的カナ';
my($CONST_fontfilename)='/c/Windows/Fonts/KH-Dot-Kodenmachou-16-Ki.ttf';
new BASE::();

sub main{
	my($ref_array_argument,$ref_hash_option)=@_;
	my($sdirectorybase)=BASE::STRING_RemoveRelative(BASE::GetCurrentDirectory().'/..');
	my($img_main)=&USR_generate_make(
		$sdirectorybase,'main','000','',0x7efc00,[
			'ofw/ofw',
			'ofw/std/std',
			'ore68000ace/memory'
		]
	);
	my($img_sub)=&USR_generate_make(
		$sdirectorybase,'sub','','020',0x3ffc00,[
			'ofw/ofw',
			'ofw/std/std',
			'ore68000ace/memory',
			'ore68000ace/driver/video',
			'ore68000ace/driver/sound'
		]
	);

	if(defined $$ref_hash_option{'d'}){
		my($sline);

		BASE::Print(<<END
#
#	make_main.sh
#

END
		);
		$img_main->SetCurrent(0);
		while(defined($sline=$img_main->GetLINE())){
			BASE::Print("$sline\n");
		}
		BASE::Print(<<END

#
#	make_sub.sh
#

END
		);
		$img_sub->SetCurrent(0);
		while(defined($sline=$img_sub->GetLINE())){
			BASE::Print("$sline\n");
		}
	}else{
		$img_main->Save('make_main.sh');
		$img_sub->Save('make_sub.sh');
	}
	return 0;
}

sub USR_generate_make{
	my($sdirectorybase,$suser,$sromprogram,$sromfont,$icodesize,$ref_array_add)=@_;
	my($img_destination);
	my(@array_sname);

	$img_destination=new BASE_IMAGE::();

	#
	#	冒頭
	#

	$img_destination->AddTEXT(<<END
#!/usr/local/ofw/bin/ofwmake
\$MAKEBIN='../M68K_MAKEBIN.exe';
END
	);
	if($sromfont ne ''){
		$img_destination->AddTEXT(<<END
\$MAKEFONT='../M68K_MAKEFONT.exe';
END
		);
	}
	$img_destination->AddTEXT(<<END
\$User='$suser';
\$Source='$sdirectorybase/common/src';
\$Include='$sdirectorybase/common/include';
\$Object='$suser.o';
\$Release='../../image';
\$C2OBJ="\$MAKEBIN -m c2obj -I \$Include";
END
	);
	if($sromprogram ne ''){
		$img_destination->AddTEXT(<<END
\$OBJ2BIN="\$MAKEBIN -m obj2bin -padding 0";
END
		);
	}
	if($sromfont ne ''){
		$img_destination->AddTEXT(<<END
\$FONT2BIN="\$MAKEFONT -s 16 -f \\\"$CONST_fontname\\\"";
END
		);
	}
	if($sromprogram ne ''){
		$img_destination->AddTEXT(<<END
\$ROM_PROGRAM="\$Release/$sromprogram.bin";
END
		);
	}
	if($sromfont ne ''){
		$img_destination->AddTEXT(<<END
\$ROM_FONT="\$Release/$sromfont.bin";
END
		);
	}

	#
	#	変数宣言
	#

	#	OFW系
	foreach(@$ref_array_add){
		my($sadd)=$_;
		my(@array_sdirectory)=split(/\//,$sadd);
		my($sobject)=join('_',@array_sdirectory);
		my($sname)=BASE::STRING_Upper($sobject);

		$img_destination->AddTEXT(<<END
\$${sname}_CPP="\$Source/$sadd.cpp";
\$${sname}_OBJ="\$Object/$sobject.o";
END
		);
		push(@array_sname,$sname);
	}
	#	common/
	foreach(BASE::ListAllFile('common')){
		if(/^(\S+)\.cpp$/){
			my($sadd)=$1;
			my(@array_sdirectory)=split(/\//,$sadd);
			my($sobject)=join('_',@array_sdirectory);
			my($sname)=BASE::STRING_Upper($sobject);

			$img_destination->AddTEXT(<<END
\$${sname}_CPP="$sadd.cpp";
\$${sname}_OBJ="\$Object/$sobject.o";
END
			);
			push(@array_sname,$sname);
		}
	}
	#	$User/
	foreach(BASE::ListAllFile("$suser")){
		if(/^$suser\/(\S+)\.cpp$/){
			my($sadd)=$1;
			my(@array_sdirectory)=split(/\//,$sadd);
			my($sobject)=join('_',@array_sdirectory);
			my($sname)=BASE::STRING_Upper($sobject);

			$img_destination->AddTEXT(<<END
\$${sname}_CPP="\$User/$sadd.cpp";
\$${sname}_OBJ="\$Object/$sobject.o";
END
			);
			push(@array_sname,$sname);
		}
	}

	#
	#	定義本体
	#

	if($sromfont ne ''){
		$img_destination->AddTEXT(<<END
\$FONT='/c/Windows/Fonts/$CONST_fontfilename';
END
		);
	}
	$img_destination->AddTEXT(<<END

{
	'.phony'=>['all','clean'],
	'.include_c'=>[\$Include],
	'all'=>{
		depend=>[
END
	);
	{
		my($inname)=scalar(@array_sname);
		my($iiname);

		if($sromprogram ne ''){
			if($sromfont ne ''){
				$img_destination->AddTEXT(<<END
			\$ROM_PROGRAM,
			\$ROM_FONT
END
				);
			}else{
				$img_destination->AddTEXT(<<END
			\$ROM_PROGRAM
END
				);
			}
		}else{
			if($sromfont ne ''){
				for($iiname=0;$iiname<$inname;++$iiname){
					my($sname)=$array_sname[$iiname];

					$img_destination->AddTEXT(<<END
			\$${sname}_OBJ,
END
					);
				}
				$img_destination->AddTEXT(<<END
			\$ROM_FONT
END
				);
			}else{
				for($iiname=0;$iiname<$inname;++$iiname){
					my($sname)=$array_sname[$iiname];

					if($iiname<$inname-1){
						$img_destination->AddTEXT(<<END
			\$${sname}_OBJ,
END
						);
					}else{
						$img_destination->AddTEXT(<<END
			\$${sname}_OBJ
END
						);
					}
				}
			}
		}
		$img_destination->AddTEXT(<<END
		]
	},
	'clean'=>{
		exec=>[
			"rm -f \\"\$Object/\\"*.o \\"\$Object/\\"*/*.o \\"\$Release/\\"*.bin"
		]
	},
END
		);
		if($sromprogram ne ''){
			$img_destination->AddTEXT(<<END
	\$ROM_PROGRAM=>{
		depend=>[
END
			);
			for($iiname=0;$iiname<$inname;++$iiname){
				my($sname)=$array_sname[$iiname];

				if($iiname<$inname-1){
					$img_destination->AddTEXT(<<END
			\$${sname}_OBJ,
END
					);
				}else{
					$img_destination->AddTEXT(<<END
			\$${sname}_OBJ
END
					);
				}
			}
			$img_destination->AddTEXT(<<END
		],
END
			);
			$img_destination->AddLINE(
			"\t\texec=>[\"\$OBJ2BIN \\\"\$".join('_OBJ\\" \\"$',@array_sname).sprintf("_OBJ\\\" -o \\\"\$ROM_PROGRAM\\\" -ca 000400 -cs %06x -da 800000 -ds 200000\"]",$icodesize)
			);
			$img_destination->AddTEXT(<<END
	},
END
			);
		}
		if($sromfont ne ''){
			$img_destination->AddTEXT(<<END
	\$ROM_FONT=>{
		depend=>[\$FONT],
		exec=>[\"\$FONT2BIN -o \\\"\$ROM_FONT\\\"\"]
	},
END
			);
		}
		for($iiname=0;$iiname<$inname;++$iiname){
			my($sname)=$array_sname[$iiname];

			$img_destination->AddTEXT(<<END
	\$${sname}_OBJ=>{
		depend_c=>[
			\$${sname}_CPP
		],
		exec=>["\$C2OBJ \\"\$${sname}_CPP\\" -o \\"\$${sname}_OBJ\\""]
END
			);
			if($iiname<$inname-1){
				$img_destination->AddTEXT(<<END
	},
END
				);
			}else{
				$img_destination->AddTEXT(<<END
	}
END
				);
			}
		}
	}
	$img_destination->AddTEXT(<<END
};
END
	);
	return $img_destination;
}
