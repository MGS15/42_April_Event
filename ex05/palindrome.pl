#!/usr/bin/perl
use strict;
use warnings;
 
print "Enter a string: ";
my $word = <STDIN>;
my $i = 0;
my $j = length($word) - 2;
my $char1 = '';
my $char2 = '';
my $res = 0;
chomp $word;
if ($word eq "")
{
	exit(1);
}
for $i (0..(length($word) - 1) / 2)
{
	$char1 = substr($word, $i, 1);
	$char2 = substr($word, $j, 1);
	$res = $char1 cmp $char2;
	if ($res != 0)
	{
		print "The string is not a palindrome.\n";
		exit 1;
	}
	$j--;
}
print "The string is a palindrome!\n";