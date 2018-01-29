#!/usr/bin/php
<?php

$arr = file("data.csv"); // tout dans un fichier, ligne par ligne
// file_gets_content() > tout dans une seule string

foreach ($arr as $line)
	echo $line; // pas besoin de "\n", retour chariot conserve avec file()

$handler = fopen("data.csv", "r");

while ($line = fgets($handler)) 
	echo "$line";

while ($arr = fgetcsv($handler, 0, ";"))
	print_r($arr);

fclose($handler);

?>
