#!/usr/bin/perl
use strict;
$INC[@INC]='/usr/local/ofw/lib';
require 'base.pl';
new BASE::();

sub main{
	system('./make_main.sh clean');
	system('./make_sub.sh clean');
	return 0;
}
