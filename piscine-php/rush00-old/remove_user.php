#!/usr/bin/php
<?php
include("api.php");

if ($argc != 2)
	exit("usage: $argv[0] <username_to_remove>\n");

$db = getDbContent("users");
removeUser($db, $argv[1]);
?>
