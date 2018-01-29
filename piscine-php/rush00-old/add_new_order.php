#!/usr/bin/php
<?php
include("api.php");

if ($argc != 4)
	exit("usage: $argv[0] <product_1> <product_2> <date>\n");

$db = getDbContent("orders");
$order_array = array("product_1" => $argv[1], "product_2" => $argv[2], "date" => $argv[3]);
addNewOrder($db, $order_array);
?>
