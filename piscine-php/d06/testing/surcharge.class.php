<?php

class exemple {
	
	public $att1 = 0;
	public $att2 = 0;
	public $att3 = 0;

	public function __construct( array $kwargs ) {
		echo "constructor called\n";
		
		if (array_key_exists("arg1", $kwargs))
			$this->att1 = $kwargs["arg1"];
		else
			$this->att1 = -1;

		$this->att2 = $kwargs["arg2"];

		if (array_key_exists("arg3", $kwargs))
			$this->att3 = $kwargs["arg3"];
		else
			$this->att3 = $this->att1;

		echo '$this->att1: '.$this->att1."\n";
		echo '$this->att2: '.$this->att2."\n";
		echo '$this->att3: '.$this->att3."\n";

		return;
	}

	public function __destruct() {
		echo "destructor called\n";
		return;
	}
}

$instance = new exemple(array("arg1" => 53, "arg2" => 42, "arg3" => 31));
$instance = new exemple(array("arg1" => 31, "arg2" => 42, "arg3" => 53));
$instance = new exemple(array("arg1" => 53, "arg2" => 42));
$instance = new exemple(array("arg2" => 42));
$instance = new exemple(array("arg3" => 31, "arg2" => 42));

?>
