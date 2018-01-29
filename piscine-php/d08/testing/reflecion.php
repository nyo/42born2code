<?php

/*
**	http://php.net/manual/en/class.reflection.php
*/

class Exemple {

	const CST1 = 1;
	const CST2 = 2;
	const CST3 = 3;

	public $foo = 21;
	private $_foo = 42;
	protected $__foo = 84;

	public function __construct() {
		echo "class exemple constructed!\n";
		return;
	}
	
	public function __destruct() {
		echo "class exemple destructed!\n";
		return;
	}

	public function publicFct() {
		echo "public function...\n";
		return;
	}

	private function _privateFct() {
		echo "private function...\n";
		return;
	}

	protected function _protectedFct() {
		echo "protected function...\n";
		return;
	}
}

$instance = new Exemple();

$classExemple = new ReflectionClass("Exemple"); // sous forme de string
/* $alsoClassExemple = new ReflectionObject($instance); // sous forme d'instance */

echo "class ".$classExemple->getName().":\n";
print_r($classExemple->getConstants());
print_r($classExemple->getProperties());
print_r($classExemple->getMethods());

?>
