#!/usr/bin/perl
##############################################################################
##																			##
##																			##
##								ORE68000ACE									##
##																			##
##	'convert.sh'									2025 written by int71	##
##############################################################################
use strict;
$INC[@INC]='/usr/local/ofw/lib';
require 'base.pl';
my($sVersion,$sDate)=('1.00','2025/12/07');
my($COM_sDirectory)=('/d/Sync/Package/Cross/ORE68000_ACE/m68k');

new BASE::();

sub main{
	my($ref_array_argument,$ref_hash_option)=@_;

	system("$COM_sDirectory/M68K_SMF2SEQ.pl \"$$ref_array_argument[0]\"");
	return 0;
}
