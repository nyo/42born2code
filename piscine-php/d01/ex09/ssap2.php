#!/usr/bin/php
<?php
function is_alpha($string)
{
	for ($i = 0; $string[$i]; $i++)
		if (!($string[$i] >= 'A' && $string[$i] <= 'Z') && !($string[$i] >= 'a' && $string[$i] <= 'z'))
			return (false);
	return (true);
}

$alp = [];
$num = [];
$oth = [];

for ($i = 1; $i < $argc; $i++)
{
	$tmp = explode(" ", $argv[$i]);
	for ($j = 0; $j < count($tmp); $j++)
	{
		if (!empty($tmp[$j]))
		{
			if (is_numeric($tmp[$j]))
				array_push($num, $tmp[$j]);
			else if (is_alpha($tmp[$j]))
				array_push($alp, $tmp[$j]);
			else
				array_push($oth, $tmp[$j]);
		}
	}
}

sort($alp, SORT_STRING | SORT_FLAG_CASE);
sort($num, SORT_STRING | SORT_FLAG_CASE);
sort($oth, SORT_STRING | SORT_FLAG_CASE);
$arr = array_merge($alp, $num, $oth);

for ($i = 0; $i < count($arr); $i++)
	echo $arr[$i]."\n";
?>
