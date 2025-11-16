#!/usr/bin/perl
use strict;
$INC[@INC]='/usr/local/ofw/lib';
require 'base.pl';
new BASE::();

sub main{
	my($out);

	$out=`./make_main.sh`;
	BASE::DeleteFile('out');
	if($out ne ''){
		BASE::Pause($out);
		return -1;
	}
	$out=`./make_sub.sh`;
	BASE::DeleteFile('out');
	if($out ne ''){
		BASE::Pause($out);
		return -1;
	}
	return 0;
}
