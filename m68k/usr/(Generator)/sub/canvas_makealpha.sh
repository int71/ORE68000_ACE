#!/usr/bin/perl
use strict;
$INC[@INC]='/usr/local/ofw/lib';
require 'base.pl';
new BASE::();

sub main{
	my($image);

	BASE::Print("\t\tstatic constexpr UINT8	stacui8cBlend[]={\n");
	BASE::Print("\t\t\t// 0    1    2    3    4    5    6    7    8    9    a    b    c    d    e    f\t\t//	alpha\n");
	for(my($idestination)=0;$idestination<16;++$idestination){
		for(my($isource)=0;$isource<16;++$isource){
			BASE::Print("\t\t\t");
			for(my($ialpha)=0;$ialpha<16;++$ialpha){
				my($ibacknega16)=$idestination*(16-$ialpha);
				my($ibacknega_source)=BASE::Minimum(($ibacknega16>>4)+$isource,15);
				my($ibacknega_sourcealpha)=($ibacknega16+$isource*($ialpha+1))>>4;

				BASE::Print(sprintf("0x%02x",$ibacknega_source|($ibacknega_sourcealpha<<4)));
				if($ialpha<15){
					BASE::Print(",");
				}
			}
			if(($idestination<15)||($isource<15)){
				BASE::Print(",");
			}else{
				BASE::Print("\t");
			}
			BASE::Print(sprintf("\t//\tdst:%x src:%x\n",$idestination,$isource));
		}
	}
	BASE::Print("\t\t};\n");
	return 0;
}
