#!/usr/bin/php
<?php
$arr = [];

for ($i = 1; $i < $argc; $i++)
{
	$tmp = explode(" ", $argv[$i]);
	for ($j = 0; $j < count($tmp); $j++)
		if (!empty($tmp[$j]))
			array_push($arr, $tmp[$j]);
}

sort($arr, SORT_STRING);
for ($i = 0; $i < count($arr); $i++)
	echo $arr[$i]."\n";
?>
