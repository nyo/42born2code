#!/usr/bin/php
<?php
if ($argc != 4)
	exit("Incorrect Parameters\n");


for ($i = 1; $i < $argc; $i++)
{
	$argv[$i] = str_replace(' ', '', $argv[$i]);
	$argv[$i] = str_replace('\t', '', $argv[$i]);
}

if ($argv[2] == '+')
	$res = ($argv[1] + $argv[3]);
else if ($argv[2] == '-')
	$res = ($argv[1] - $argv[3]);
else if ($argv[2] == '*')
	$res = ($argv[1] * $argv[3]);
else if ($argv[2] == '/')
	$res = ($argv[1] / $argv[3]);
else if ($argv[2] == '%')
	$res = ($argv[1] % $argv[3]);

exit($res."\n");
?>
