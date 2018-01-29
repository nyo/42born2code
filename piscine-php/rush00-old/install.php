#!/usr/bin/php
<?php

/*
**	fileInit() creates (if not existing) the directory & files for the database.
*/

function fileInit($file_path, $file_name)
{
	if (!file_exists($file_path))
	{
		mkdir($file_path);
		echo "fileInit(): created $file_path...\n";
	}
	if (!file_exists($file_path.$file_name))
	{
		file_put_contents($file_path.$file_name, null, LOCK_EX);
		echo "fileInit(): created $file_path$file_name...\n";
	}
}

/*
**	dbInit() initializes a file as a database (it creates the main array).
*/

function dbInit($file_path, $type)
{
	$base = json_encode(array($type => array()));
	file_put_contents($file_path.$type.".json", $base, LOCK_EX);
	echo "dbInit(): '$type' database has been initialized!\n";
}

$file_path = "fileJson/";
$file_names = array("users" => "users.json",
					"orders" => "orders.json",
					"products" => "products.json");

foreach ($file_names as $k => $v)
	fileInit($file_path, $file_names[$k]);

foreach ($file_names as $k => $v)
	dbInit($file_path, $k);

?>
