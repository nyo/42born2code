<?php

class exemple {

	private $_att = 0;

	public function getAtt() { return $this->_att; }
	public function setAtt($v) { $this->_att = $v; return; }

	public function __construct (array $kwargs) {
		echo "constructor called\n";
		$this->setAtt($kwargs["arg"]);
		return;
	}

	public function __destruct () {
		echo "destructor called\n";
		return;
	}

	public function __toString() {
		return ('exemple( $_att = '.$this->getAtt().' )');
	}
}

$instance = new exemple(array("arg" => 42));
echo $instance."\n";

?>
