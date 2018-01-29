<?php
class ExempleA {
	public $att = 0;

	public function __construct() {
		echo "constructor A called\n";
		$this->att = 42;
		return;
	}

	public function __destruct() {
		echo "detructor A called\n";
		return;
	}

	public function foo() {
		echo "foo() class ExempleA, att: $this->att\n";
		return;
	}
}

class ExempleB extends ExempleA {
	public function __construct() {
		echo "constructor B called\n";
		$this->att = 42;
		return;
	}

	public function __destruct() {
		echo "destructor B called\n";
		return;
	}

	public function foo() { // redefinition de foo()
		parent::foo();
		echo "foo() class ExempleB, att: $this->att\n";
		return;
	}
}

//$instanceA = new ExempleA();
//$instanceA->foo();
$instanceB = new ExempleB();
$instanceB->foo();
?>
