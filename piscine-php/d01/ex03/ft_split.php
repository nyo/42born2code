<?php
function ft_split($string)
{
	$arr = explode(" ", $string);
	$ret = [];

	for ($i = 0; $i < count($arr); $i++)
		if (!empty($arr[$i]))
			array_push($ret, $arr[$i]);
	sort($ret, SORT_STRING);
	return ($ret);
}
?>
