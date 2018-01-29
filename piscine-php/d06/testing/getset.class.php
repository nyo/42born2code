<?php

class exemple {
	
	private $_att = 0;

	public function getAtt() {
		return $this->_att;
	}
	
	public function setAtt($v) {
		if ($this->_att + $v > 50)
			$this->_att = 50;
		else
			$this->_att = $v;
		return;
	}

	public function __get($att) {
		echo "attempting to access $att attribute, this script should die\n";
		return;
	}

	public function __set($att, $val) {
		echo "attempting to set $att attribute to $val, this script should die\n";
		return;
	}

	public function __construct(array $kwargs) {
		echo "constructor called\n";
		$this->setAtt($kwargs["arg"]);
		echo '$this->getAtt(): '.$this->getAtt()."\n";
		return;
	}

	public function __destruct() {
		echo "destructor called\n";
		return;
	}
}

$instance = new exemple(array("arg" => 42));

echo '$intance->foo: '.$instance->foo."\n";
echo '$intance->_att: '.$instance->_att."\n";

$instance->foo = 21;
$instance->_att = 84;

?>
