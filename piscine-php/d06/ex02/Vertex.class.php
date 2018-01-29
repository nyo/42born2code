<?php

require_once("Color.class.php");

class Vertex {

	public static $verbose = false;

	private $_x;
	private $_y;
	private $_z;
	private $_w;
	private $_c;

	public static function doc() {
		return (file_get_contents("Vertex.doc.txt"));
	}

	public function getX() { return ($this->_x); }
	public function getY() { return ($this->_y); }
	public function getZ() { return ($this->_z); }
	public function getW() { return ($this->_w); }
	public function getC() { return ($this->_c); }

	public function setX($x) { $this->_x = number_format($x, 2); }
	public function setY($y) { $this->_y = number_format($y, 2); }
	public function setZ($z) { $this->_z = number_format($z, 2); }
	public function setW($w) { if (isset($w)) { $this->_w = number_format($w, 2); } else { $this->_w = number_format(1, 2); } }
	public function setC($c) { if (isset($c)) { $this->_c = $c; } else { $this->_c = new Color(array("red" => 255, "green" => 255, "blue" => 255)); } }

	public function __construct(array $kwargs) {
		$this->setX($kwargs["x"]);
		$this->setY($kwargs["y"]);
		$this->setZ($kwargs["z"]);
		$this->setW($kwargs["w"]);
		$this->setC($kwargs["color"]);
		if (self::$verbose === true)
			echo "Vertex( x: ".$this->getX().", y: ".$this->getY().", z:".$this->getZ().", w:".$this->getW().", ".$this->getC()." ) constructed\n";
		return;
	}

	public function __destruct() {
		if (self::$verbose === true)
			echo "Vertex( x: ".$this->getX().", y: ".$this->getY().", z:".$this->getZ().", w:".$this->getW().", ".$this->getC()." ) destructed\n";
		return;
	}

	public function __toString() {
		if (self::$verbose === true)
			return ("Vertex( x: ".$this->getX().", y: ".$this->getY().", z:".$this->getZ().", w:".$this->getW().", ".$this->getC()." )");
		else
			return ("Vertex( x: ".$this->getX().", y: ".$this->getY().", z:".$this->getZ().", w:".$this->getW()." )");
	}
}

?>
