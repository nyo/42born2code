#!/usr/bin/php
<?php
if ($argc != 2)
	exit("Incorrect Parameters\n");

$ops = array("+", "-", "*", "/", "%");
$err = "Syntax Error\n";

for ($i = 0; $i < count($ops); $i++)
{
	$arr = explode($ops[$i], $argv[1]);
	if (count($arr) > 1)
	{
		$op = $ops[$i];
		break;
	}
}

if (count($arr) != 2)
	exit($err);
else {
	$nb1 = str_replace(' ', '', $arr[0]);
	$nb2 = str_replace(' ', '', $arr[1]);
	if (!is_numeric($nb1) || !is_numeric($nb2))
		exit($err);
}

if ($op == '+')
	$res = $nb1 + $nb2;
else if ($op == '-')
	$res = $nb1 - $nb2;
else if ($op == '*')
	$res = $nb1 * $nb2;
else if ($op == '/')
	$res = $nb1 / $nb2;
else if ($op == '%')
	$res = $nb1 % $nb2;
else
	exit($err);
exit($res."\n");
?>
