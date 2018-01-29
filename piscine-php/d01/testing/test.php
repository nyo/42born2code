#!/usr/bin/php
<?php

function my_add($p1, $p2)
{
	return $p1 + $p2;
}

$my_int = 42;;
$my_str = "hello";
$my_arr = array("zero", "one", "two");
$my_hash = array("key1" => "val1", "key2" => "val2");

echo "test: echo\n";
print("test: print\n");

echo "+ ---------- +\n";

echo $my_int.$my_str."\n";	// with concatenate
echo "$my_int$my_str\n";	// without concatenate

echo "+ ---------- +\n";

$result = "21" + "21";
echo "$result\n";

echo "+ ---------- +\n";

echo $my_arr[0]."\n";
echo $my_hash["key1"]."\n";

echo "+ ---------- +\n";

echo $my_arr;		// prints type
print_r($my_arr);	// prints content

echo "+ ---------- +\n";

echo my_add(1300, 37)."\n";

echo "+ ---------- +\n";

if ($my_arr[1] == "one") {
	echo "OK\n";
}
else {
	echo "KO\n";
}

echo "+ ---------- +\n";

$i = 0;
while ($i < 10)
{
	echo $i."\n";
	$i++;
}

echo "+ ---------- +\n";

echo "$argc\n";
print_r($argv);

echo "+ ---------- +\n";

echo count($my_arr)."\n";

echo "+ ---------- +\n";

foreach ($my_arr as $o)
{
	print($o."\n");
}

echo "+ ---------- +\n";

$my_tab = explode(";", "zero;one;two;three");
print_r($my_tab);

?>
