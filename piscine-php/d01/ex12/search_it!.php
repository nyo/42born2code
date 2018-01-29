#!/usr/bin/php
<?php
for ($i = 2; $i < $argc; $i++)
{
	$tmp = explode(":", $argv[$i]);
	if ($argv[1] === $tmp[0])
		$val = $tmp[1];
}

if (empty($val))
	exit();
else
	exit($val."\n");
?>
