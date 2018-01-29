<?php

class exemple {
	
	const CST1 = 1;
	const CST2 = 1;

	public function __construct(array $kwargs) {
		echo "constructor called\n";
		if ($kwargs["arg"] == self::CST1)
			// ...;
		else if ($kwargs["arg"] == self::CST2)
			// ...;
		else
			echo "arg is not a class constant";
		return;
	}

	public function __destruct() {
		echo "destructor called\n";
		return;
	}
}

$instance1 = new exemple(array("arg" => exemple::CST1));
$instance2 = new exemple(array("arg" => exemple::CST1));

?>
