<?php
abstract class House {
	public function introduce() {
		echo "House ".static::getHouseName().
				" of ".static::getHouseSeat().
				" : \"".static::getHouseMotto()."\"\n";
	}
	abstract public function getHouseName();
	abstract public function getHouseSeat();
	abstract public function getHouseMotto();
}
?>
