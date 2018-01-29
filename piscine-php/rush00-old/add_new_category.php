#!/usr/bin/php
<?php
include("api.php");

if ($argc != 2)
	exit("usage: $argv[0] <category_to_add>\n");

$db = getDbContent("products");
addNewCategory($db, $argv[1]);
?>
