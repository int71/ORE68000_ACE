#!/usr/bin/perl
use strict;
$INC[@INC]='/usr/local/ofw/lib';
require 'base.pl';
new BASE::();

sub main{
	my($ref_array_argument,$ref_hash_option)=@_;

	if(BASE::STRING_GetExtension($$ref_array_argument[0]) eq 'o68k'){
		system("'/d/Sync/Package/Cross/ORE68000_ACE/ORE68000 ACE.exe' $$ref_array_argument[0]&");
	}else{
		BASE::Pause("\".o68k\"ファイルを選択した状態で実行してください。\n");
	}
	return 0;
}
