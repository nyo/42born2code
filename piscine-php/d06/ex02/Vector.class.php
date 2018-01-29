<?php
class Vector {

	public static $verbose = false;

	private $_x;
	private $_y;
	private $_z;
	private $_w;

	public static function doc() {
		return (file_get_contents("Vector.doc.txt"));
	}

	public function getX() { return ($this->_x); }
	public function getY() { return ($this->_y); }
	public function getZ() { return ($this->_z); }
	public function getW() { return ($this->_w); }

	public function __construct(array $kwargs) {
		if (array_key_exists("orig", $kwargs)) {
			$orig = clone $kwargs["orig"];
		} else {
			$orig = new Vertex(array("x" => 0, "y" => 0, "z" => 0));
		}
		$this->_x = number_format($kwargs["dest"]->getX() - $orig->getX(), 2);
		$this->_y = number_format($kwargs["dest"]->getY() - $orig->getY(), 2);
		$this->_z = number_format($kwargs["dest"]->getZ() - $orig->getZ(), 2);
		$this->_w = number_format(0, 2);
	
		if (self::$verbose)
			echo "Vector( x:".$this->_x.", y:".$this->_y.", z:".$this->_z.", w:".$this->_w." ) constructed\n";
		return;
	}

	public function __destruct() {
	
		if (self::$verbose)
			echo "Vector( x:".$this->_x.", y:".$this->_y.", z:".$this->_z.", w:".$this->_w." ) destructed\n";
		return;
	}

	public function __toString() {
		return ("Vector( x:".$this->_x.", y:".$this->_y.", z:".$this->_z.", w:".$this->_w." )");
	}

	/*
	**	-------------------------------------
	**	public methods to do maths on vectors
	**	-------------------------------------
	*/
	
	public function magnitude() {
		$a = pow($this->_x, 2) + pow($this->_y, 2) + pow($this->_z, 2);
		return (float)(sqrt($a));
	}
	
	public function normalize() {

		if ($this->magnitude() === 1) {
			return (clone $this);
		}
		else {
	
			$x = $this->_x / $this->magnitude();
			$y = $this->_y / $this->magnitude();
			$z = $this->_z / $this->magnitude();
		
			return (new Vector(array("dest" => new Vertex(array("x" => $x, "y" => $y, "z" => $z)))));
		}
	}

	public function add(Vector $rhs) {
	
		$x = $this->_x + $rhs->getX();
		$y = $this->_y + $rhs->getY();
		$z = $this->_z + $rhs->getZ();
	
		return (new Vector(array("dest" => new Vertex(array("x" => $x, "y" => $y, "z" => $z)))));
	}
	
	public function sub(Vector $rhs) {

		$x = $this->_x - $rhs->getX();
		$y = $this->_y - $rhs->getY();
		$z = $this->_z - $rhs->getZ();
	
		return (new Vector(array("dest" => new Vertex(array("x" => $x, "y" => $y, "z" => $z)))));
	}

	public function opposite() {

		$x = $this->_x * -1;
		$y = $this->_y * -1;
		$z = $this->_z * -1;

		return (new Vector(array("dest" => new Vertex(array("x" => $x, "y" => $y, "z" => $z)))));
	}
		
	public function scalarProduct($k) {

		$x = $this->_x * $k;
		$y = $this->_y * $k;
		$z = $this->_z * $k;
		
		return (new Vector(array("dest" => new Vertex(array("x" => $x, "y" => $y, "z" => $z)))));
	}
	
	public function dotProduct(Vector $rhs) {

		$x = $this->_x * $rhs->getX();
		$y = $this->_y * $rhs->getY();
		$z = $this->_z * $rhs->getZ();
		return (float)($x + $y + $z);
	}
	
	public function cos(Vector $rhs) {
		$a = pow($this->_x, 2) + pow($this->_y, 2) + pow($this->_z, 2);
		$b = pow($rhs->getX(), 2) + pow($rhs->getY(), 2) + pow($rhs->getZ(), 2);
		return (float)($this->dotProduct($rhs) / sqrt($a * $b));
	}

	public function crossProduct(Vector $rhs) {
		$x = $this->_y * $rhs->getZ() - $this->_z * $rhs->getY();
		$y = $this->_z * $rhs->getX() - $this->_x * $rhs->getZ();
		$z = $this->_x * $rhs->getY() - $this->_y * $rhs->getX();
		return (new Vector(array("dest" => new Vertex(array("x" => $x, "y" => $y, "z" => $z)))));
	}

}
?>
