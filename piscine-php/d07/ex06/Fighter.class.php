<?php
class Fighter {
	private $_who;
	public function __construct($who) { $this->_who = $who; }
	public function getWho() { return ($this->_who); }
}
?>
