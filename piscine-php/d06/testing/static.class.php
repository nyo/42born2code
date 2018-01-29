<?php

class exemple {

	public static $nb = 0;

	public static function doc() { // impossible d'utiliser $this
		return "this is a sample class with no real purpose";
	}

	public function __construct() {
		echo "constructor called\n";
		self::$nb++;
		return;
	}

	public function __destruct() {
		echo "destructor called\n";
		self::$nb--;
		echo "nb instances: ".exemple::$nb."\n";
		return;
	}
}

echo "exemple doc: ".exemple::doc()."\n"; // appel sans instance

echo "nb instances: ".exemple::$nb."\n";
$instance1 = new exemple();
echo "nb instances: ".exemple::$nb."\n";
$instance2 = new exemple();
echo "nb instances: ".exemple::$nb."\n";
$instance3 = new exemple();
echo "nb instances: ".exemple::$nb."\n";

?>
