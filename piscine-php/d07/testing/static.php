<?php

class ExempleA {

	public function __construct() {
		//...
	}

	public function __destruct() {
		//...
	}

	public function foo() {
		//...
	}
	
	public function test() {
		static::foo(); // foo() de B SI APPELE D B (et pas de A comme avev self::foo())
	}
}

class ExempleB extends ExempleA {

	public function __construct() {
		//...
	}

	public function __destruct() {
		//...
	}

	public function foo() { // override foo() de A
		//...
	}

}

exempleA->foo() // foo de A
exempleB->foo() // foo de B

exempleA->test() // foo de A
exempleB->test() // foo de B

/*
	avec static, c'est l'instance de la classe qui determine de quel fonction elle
	prend la fonction a executer
*/

?>
