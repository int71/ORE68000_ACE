#!/usr/bin/perl
use strict;
$INC[@INC]='/usr/local/ofw/lib';
require 'base.pl';
new BASE::();

sub main{
	if(system('./build.sh')==0){
		system("'/d/User/C/User/ORE68000ACE/x64/Release/ORE68000 ACE.exe' image&");
	}
	return 0;
}
