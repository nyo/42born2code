<?php

class exemple {

	public $foo = 0; // attribut

	public $publicFoo = 0;
	private $_privateFoo = "hello";

	function __construct() { // method
		echo "constructor called\n";
		
		echo '$this->publicFoo: '.$this->publicFoo."\n";
		$this->publicFoo = 42;
		echo '$this->publicFoo: '.$this->publicFoo."\n";

		echo '$this->_privateFoo: '.$this->_privateFoo."\n";
		$this->_privateFoo = "world";
		echo '$this->_privateFoo: '.$this->_privateFoo."\n";

		$this->publicBar();
		$this->_privateBar();

		return;
	}
	
	function __destruct() {
		echo "destructor called\n";
		return;
	}

	function publicBar() {
		echo "method publicBar called\n";
		return;
	}

	private function _privateBar() {
		echo "method _privateBar() called\n";
		return;
	}
}

$instance = new exemple();

echo '$instance->publicFoo: '.$instance->publicFoo."\n";
$instance->publicFoo = 100;
echo '$instance->publicFoo: '.$instance->publicFoo."\n";

$instance->publicBar();

echo '$instance->_privateFoo: '.$instance->_privateFoo."\n";
$instance->_privateFoo = 100;
echo '$instance->_privateFoo: '.$instance->_privateFoo."\n";

$instance->_privateBar();
?>
