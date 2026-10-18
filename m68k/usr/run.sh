#!/usr/bin/perl
use strict;
$INC[@INC]='/usr/local/ofw/lib';
require 'base.pl';
new BASE::();

sub main{
	if(system('./build.sh')==0){
		system("'/d/Sync/Package/Cross/ORE68000_ACE/ORE68000 ACE.exe'&");
	}
	return 0;
}
