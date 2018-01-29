<?php

/*
	class...
*/

$instance1 = new exemple(array("arg1" => 21, "arg2" => 42));
$instance2 = new exemple(array("arg1" => 21, "arg2" => 42));
$instance3 = $instance1;

if ($instance1 === $instance3)
	// true, same memory area
if ($instance1 === $instance2)
	// false, different memory area
if ($instance1 == $instance2)
	// true, same structure

?>
