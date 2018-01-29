#!/usr/bin/php
<?php

if ("Hello" == "World") // KO
	echo "OK\n";
else
	echo "KO\n";

if (0 == "World") // OK
	echo "OK\n";
else
	echo "KO\n";

if (0 === "World") // KO
	echo "OK\n";
else
	echo "KO\n";

?>
