<?php

class exemple {

	public function __construct() {
		echo "constructor called\n";
		return;
	}

	public function __destruct() {
		echo "destructor called\n";
		return;
	}

	public function __call($f, $args) {
		echo "attempt to call function $f with params ";
		print_r($args);
		return;
	}

	public static function __callstatic($f, $args) {
		echo "attempt to call static function $f with params ";
		print_r($args);
		return;
	}
}

$instance = new exemple();
$instance->foo(1, 2, 3);
exemple::bar(4, 5, 6);

?>
