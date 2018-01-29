<?php
class ExempleA {
	public $var1 = 0; // accessible a la classe fille, comme en dehors de toutes classes
	private $_var2 = 0; // inaccesible a la classe fille, comme en dehors de toutes classes
	protected $var3 = 0; // accessible a la classe fille, pas en dehors (de l'exterieur, protected = private)

	/*
		...
	*/
}

class ExempleB extends ExempleA {
	
	/*
		possible d'acceder a public var1, et protected var3
		impossible d'acceder a private var2
	*/
}

/*
	possible d'acceder a public var1
	impossible d'acceder a private var2 et protected var3
*/

?>
