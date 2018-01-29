#!/usr/bin/php
<?php

if ($argc < 2)
	exit();

$ret = preg_replace("/[ \t]+/", " ", $argv[1]);
$ret = preg_replace("/^[ \t]+/", "", $ret);
$ret = preg_replace("/[ \t]+$/", "", $ret);

if (strlen($ret) > 0)
	exit($ret."\n");

?>
