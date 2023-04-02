#!/usr/bin/perl

print "Enter a string: ";
my $input = <STDIN>;
chomp $input;

my $reverse = reverse $input;

if ($input eq $reverse) {
    print "$input is a palindrome.\n";
} else {
    print "$input is not a palindrome.\n";
}