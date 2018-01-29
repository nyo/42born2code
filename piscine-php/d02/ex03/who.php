#!/usr/bin/php
<?php

date_default_timezone_set('Europe/Paris');

/*

filesize($file_path) = 1884 bytes
1884 / 3 = 628 bytes

+ - - - - - - - - - - +

format to use when packing data (see http://php.net/manual/en/function.pack.php)
	[...]
	a - NUL-padded string
	i - signed integer
	I - unsigned integer
	[...]

+ - - - - - - - - - - +

struct utmp (see utmp(5) man)
{
	char    ut_user[UT_NAMESIZE];	// Username
	char    ut_id[4];				// Terminal name suffix, or inittab(5) ID
	char    ut_line[UT_LINESIZE];	// Device name of tty - "/dev/"
	pid_t   ut_pid;					// PID of login process
	short   ut_type;				// Type of record
	time_t  ut_time;
	[...]
}

*/

$file_path = "/var/run/utmpx";
$fp = fopen($file_path, "r"); // open file handler

while ($content = fread($fp, filesize($file_path) / 3)) 
{
	$array = unpack("a256user/a4id/a32line/ipid/itype/Itime", $content);

	// print_r($array); // uncomment to see details of utmpx content

	if ($array["type"] === 7)
		$data[$array["line"]] = array(
			"user" => $array["user"],
			"tty" => $array["line"],
			"date" => $array["time"]);
}

fclose($fp); // close file hander

ksort($data, SORT_REGULAR); // sort the array by ascii value, as who(1) does

// print_r($data); // uncomment to see details before formatting and printing output

foreach ($data as $profile)
{
	echo str_pad(substr(trim($profile["user"]), 0, 8), 8, " ")." ";
	echo str_pad(substr(trim($profile["tty"]), 0, 8), 8, " ")." ";
	echo date("M", $profile["date"]).str_pad(date("j", $profile["date"]), 3, " ", STR_PAD_LEFT)." ".date("H:i", $profile["date"])."\n";
}

?>
