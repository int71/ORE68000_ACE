#!/usr/bin/perl
##############################################################################
##																			##
##																			##
##								ORE68000ACE									##
##																			##
##	'MAKESOUND.pl'									2026 written by int71	##
##############################################################################
use strict;
$INC[@INC]='/usr/local/ofw/lib';
require 'base.pl';
my($sVersion,$sDate)=('1.01','2026/10/30');
my($COM_sDirectory)=('/d/Sync/Package/Cross/ORE68000_ACE/m68k');

new BASE::();

sub main{
	#	BGM
	foreach(BASE::ListAllFile('./')){
		if(/(BGM\w+\.mid)/){
			my($sfile)=$1;

			foreach(`$COM_sDirectory/M68K_SMF2SEQ.pl ./$sfile -n PCM0,PCM1,PCM2 -mt 2.0 -d`){
				my($sline)=$_;

				BASE::Print("$sline");
			}
		}
	}
	#	SE
	foreach(BASE::ListAllFile('./')){
		if(/(SE\w+\.mid)/){
			my($sfile)=$1;

			foreach(`$COM_sDirectory/M68K_SMF2SEQ.pl ./$sfile -n PCM3 -mt 2.0 -d`){
				my($sline)=$_;

				BASE::Print("$sline");
			}
		}
	}
	return 0;
}
