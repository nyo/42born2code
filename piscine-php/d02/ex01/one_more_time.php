#!/usr/bin/php
<?php

function check_d($d)
{
	$week = array("lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi", "dimanche");

	foreach ($week as $o)
		if ($o === lcfirst($d))
			return (true);
	return (false);
}

function check_n($n)
{
	if (preg_match("/^[1-9]$|^0[0-9]$|^[1-2][0-9]$|^3[0-1]$/", $n) === 1)
		return (true);
	else
		return (false);
}

function check_m($m)
{
	$months = array("janvier", "février", "mars", "avril", "mai", "juin", "juillet", "août", "septembre", "octobre", "novembre", "décembre");

	foreach ($months as $o)
		if ($o === lcfirst($m))
			return (true);
	return (false);
}

function check_y($y)
{
	if (preg_match("/^[0-9]{4}$/", $y) === 1)
		return (true);
	else
		return (false);
}

function check_h($h)
{
	if (preg_match("/^([0-1][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9])$/", $h) === 1)
		return (true);
	else
		return (false);
}

function get_month_number($m)
{
	$month = array(
		1 => "janvier",
		2 => "février",
		3 => "mars",
		4 => "avril",
		5 => "mai",
		6 => "juin",
		7 => "juillet",
		8 => "août",
		9 => "septembre",
		10 => "octobre",
		11 => "novembre",
		12 => "décembre");
	$ret = array_search(lcfirst($m), $month);
	return ($ret);
}

if ($argc < 2)
	exit();

$date = explode(" ", $argv[1]);
if (!check_d($date[0]) || !check_n($date[1]) || !check_m($date[2]) || !check_y($date[3]) || !check_h($date[4]))
	exit("Wrong Format\n");

$month_nb = get_month_number($date[2]);
$format = "$date[1]-$month_nb-$date[3] $date[4]";
date_default_timezone_set('Europe/Paris');
exit(strtotime($format)."\n");

?>
