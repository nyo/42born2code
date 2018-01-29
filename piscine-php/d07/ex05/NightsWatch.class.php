<?php
class NightsWatch {
	private $_rc = array();
	public function recruit($who) {
		array_push($this->_rc, $who);
	}
	public function fight() {
		foreach ($this->_rc as $who)
			if (method_exists($who, fight))
				$who->fight();
	}
}
?>
