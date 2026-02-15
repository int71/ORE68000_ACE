#!/usr/bin/perl
use strict;
$INC[@INC]='/usr/local/ofw/lib';
require 'base.pl';
new BASE::();

sub main{
	my(@array_ref_array_palette)=(
		[
			'3f2c1507',
			'3f272112',
			'3f293617',
			'3f302607'
		],[
			'3f302102',
			'3f302718',
			'3f302716',
			'3f293617'
		]
	);
	my($i);

	for($i=0;$i<scalar(@array_ref_array_palette);++$i){
		my($ref_array_palette)=$array_ref_array_palette[$i];
		my($j);

		for($j=0;$j<scalar(@$ref_array_palette);++$j){
			my($out);

			$out=`../../../M68K_MAKEFBIMAGE "../VIDEO/10_BG_SYSTEM.png" -o "./10_BG_SYSTEM.P${i}${j}.tile.png" -p "$$ref_array_palette[$j]"`;
			if($out ne ''){
				BASE::Pause($out);
				return -1;
			}
		}
	}
	return 0;
}
