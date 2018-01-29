#!/usr/bin/php
<?php

function ft_split($string)
{
	$arr = explode(" ", $string);
	$ret = [];

	for ($i = 0; $i < count($arr); $i++)
		if (!empty($arr[$i]))
			array_push($ret, $arr[$i]);
	return ($ret);
}

$arr = ft_split($argv[1]);
if (count($arr) == 0)
	exit();

$tmp = $arr[0];
array_shift($arr);
array_push($arr, $tmp);

for ($i = 0; $i < count($arr); $i++)
{
	echo $arr[$i];
	if ($i !== (count($arr) - 1))
		echo " ";
	else
		echo "\n";
}
?>
