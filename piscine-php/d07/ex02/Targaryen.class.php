<?php
class Targaryen {
	public function resistsFire() { return false; }
	public function getBurned() {
		if (static::resistsFire() === true)
			return ("emerges naked but unharmed");
		else
			return ("burns alive");
	}
}
?>
