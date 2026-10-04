#!/usr/bin/perl
use strict;
$INC[@INC]='/usr/local/ofw/lib';
require 'base.pl';
new BASE::();

sub main{
	my($image);

	BASE::Print("\t\tstatic constexpr UINT8	stacui8cBlend_Back[]={\n");
	BASE::Print("\t\t\t// 0    1    2    3    4    5    6    7    8    9    a    b    c    d    e    f\t\t//	alpha\n");
	for(my($idestination)=0;$idestination<16;++$idestination){
		for(my($isource)=0;$isource<16;++$isource){
			BASE::Print("\t\t\t");
			for(my($ialpha)=0;$ialpha<16;++$ialpha){
				my($iback)=$idestination;
				my($iback_source)=BASE::Minimum($iback+$isource,15);
				my($iback_sourcealpha)=BASE::Minimum($iback+((($isource+1)*($ialpha+1)-1)>>4),15);

				BASE::Print(sprintf("0x%02x",$iback_source|($iback_sourcealpha<<4)));
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

	BASE::Print("\t\tstatic constexpr UINT8	stacui8cBlend_BackNega[]={\n");
	BASE::Print("\t\t\t// 0    1    2    3    4    5    6    7    8    9    a    b    c    d    e    f\t\t//	alpha\n");
	for(my($idestination)=0;$idestination<16;++$idestination){
		for(my($isource)=0;$isource<16;++$isource){
			BASE::Print("\t\t\t");
			for(my($ialpha)=0;$ialpha<16;++$ialpha){
				my($ibacknega)=(($idestination+1)*(16-$ialpha)-1)>>4;
				my($ibacknega_source)=BASE::Minimum($ibacknega+$isource,15);
				my($ibacknega_sourcealpha)=$ibacknega+((($isource+1)*($ialpha+1)-1)>>4);

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
