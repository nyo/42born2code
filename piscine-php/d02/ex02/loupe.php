#!/usr/bin/php
<?php

function loupe_line($line)
{
	$line = preg_replace_callback("/(<a )(.*?)(>)(.*)(<\/a>)/i", function($match)
	{
		$match[0] = preg_replace_callback("/( title=\")(.*?)(\")/i", function($match)
		{
			return ($match[1].strtoupper($match[2]).$match[3]);
		}, $match[0]);

		$match[0] = preg_replace_callback("/(>)(.*?)(<)/i", function($match)
		{
			return ($match[1].strtoupper($match[2]).$match[3]);
		}, $match[0]);

		return ($match[0]);
	}, $line);
	echo $line;
}

if ($argc < 2 || !file_exists($argv[1]))
	exit();

$arr = file($argv[1]) or die;
foreach ($arr as $line)
	echo loupe_line($line);

?>
