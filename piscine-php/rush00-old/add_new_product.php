#!/usr/bin/php
<?php
include("api.php");

if ($argc != 3)
	exit("usage: $argv[0] <category_name> <product_name>\n");

$db = getDbContent("products");
addNewProduct($db, $argv[1], $argv[2]);
?>
