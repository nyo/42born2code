<?php

/*
	class...
*/

echo "---- sharing ----";
$instance1 = new exemple(array("arg" => 42));
$instance2 = $instance1;
echo $instance1->getAtt()."\n"; // output: 42
echo $instance2->getAtt()."\n"; // output: 42
$instance1->setAtt(30);
echo $instance1->getAtt()."\n"; // output: 30
echo $instance2->getAtt()."\n"; // output: 30 (same memory area)

echo "---- cloning ----";
$instance3 = new exemple(array("arg" => 42));
$instance4 = clone $instance3;
echo $instance3->getAtt()."\n"; // output: 42
echo $instance4->getAtt()."\n"; // output: 42
$instance3->setAtt(30);
echo $instance3->getAtt()."\n"; // output: 30
echo $instance4->getAtt()."\n"; // output: 42 (different memory are)

?>
