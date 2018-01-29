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
for ($i = 0; $i < count($arr); $i++)
{
	echo $arr[$i];
	if ($i !== (count($arr) - 1))
		echo " ";
	else
		echo "\n";
}
?>
