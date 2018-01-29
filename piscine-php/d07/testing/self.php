<?php
class ExempleA {

	function foo()
		//...

	function test()
		self::foo();

}

class ExempleB extends ExempleA {
	
	function foo() // redefinition

}

exempleA->foo(); // foo de A
exempleB->foo(); // foo de B
exempleA->test(); // test (foo) de A
exempleB->test(); // test (foo) de A

?>
