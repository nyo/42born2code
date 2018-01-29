<?php
class Matrix {

	/*
	**	attributes
	*/

	public static $verbose = false;

	const IDENTITY = "IDENTITY";
	const SCALE = "SCALE";
	const RX = "Ox ROTATION";
	const RY = "Oy ROTATION";
	const RZ = "Oz ROTATION";
	const TRANSLATION = "TRANSLATION";
	const PROJECTION = "PROJECTION";

	private $_preset;
	private $_scale;
	private $_angle;
	private $_vtc;
	private $_fov;
	private $_ratio;
	private $_near;
	private $_far;

	protected $matrix = array();

	/*
	**	classic methods
	*/

	public function doc() {
		return (file_get_contents("Matrix.doc.txt"));
	}

	public function __construct(array $kwargs) {

		$this->_preset = $kwargs["preset"];
		if (array_key_exists("scale", $kwargs))
			$this->_scale = $kwargs["scale"];
		if (array_key_exists("angle", $kwargs))
			$this->_angle = $kwargs["angle"];
		if (array_key_exists("vtc", $kwargs))
			$this->_vtc = $kwargs["vtc"];
		if (array_key_exists("fov", $kwargs))
			$this->_fov = $kwargs["fov"];
		if (array_key_exists("ratio", $kwargs))
			$this->_ratio = $kwargs["ratio"];
		if (array_key_exists("near", $kwargs))
			$this->_near = $kwargs["near"];
		if (array_key_exists("far", $kwargs))
			$this->_far = $kwargs["far"];

		$this->matrixInit();
		$this->matrixSwitch();

		if (self::$verbose) {
			if ($this->_preset === self::IDENTITY) // check == or === ?
				echo "Matrix ".$this->_preset." instance constructed\n";
			else
				echo "Matrix ".$this->_preset." preset instance constructed\n";
		}
		return;
	}

	public function __destruct() {
		if (self::$verbose)
			echo "Matrix instance destructed\n";
		return;
	}

	public function __toString() {
		$this->matrixFormat();
		$ret =	"M | vtcX | vtcY | vtcZ | vtxO\n";
		$ret .=	"-----------------------------\n";
		$ret .=	"x | ".$this->matrix[0]." | ".$this->matrix[1]." | ".$this->matrix[2]." | ".$this->matrix[3]."\n";
		$ret .= "y | ".$this->matrix[4]." | ".$this->matrix[5]." | ".$this->matrix[6]." | ".$this->matrix[7]."\n";
		$ret .=	"z | ".$this->matrix[8]." | ".$this->matrix[9]." | ".$this->matrix[10]." | ".$this->matrix[11]."\n";
		$ret .=	"w | ".$this->matrix[12]." | ".$this->matrix[13]." | ".$this->matrix[14]." | ".$this->matrix[15];
		return ($ret);
	}

	/*
	**	private methods to do things with matrices
	*/

	private function matrixInit() {
		for ($i = 0; $i < 16; $i++)
			$this->matrix[$i] = 0;
	}

	private function matrixFormat() {
		for ($i = 0; $i < 16; $i++)
			$this->matrix[$i] = number_format($this->matrix[$i], 2);
	}

	private function matrixSwitch()
	{
		switch ($this->_preset)
		{
			case (self::IDENTITY):
				$this->identity(1);
				break;
			case (self::SCALE):
				$this->identity($this->_scale);
				break;
			case (self::RX):
				$this->rotationX();
				break;
			case (self::RY):
				$this->rotationY();
				break;
			case (self::RZ):
				$this->rotationZ();
				break;
			case (self::TRANSLATION):
				$this->translation();
				break;
			case (self::PROJECTION):
				$this->projection();
				break;
		}
	}

	private function identity($scale)
	{
		$this->matrix[0] = $scale;
		$this->matrix[5] = $scale;
		$this->matrix[10] = $scale;
		$this->matrix[15] = 1;
	}

	private function rotationX()
	{	
		$this->identity(1);

		$this->matrix[0] = 1;
		$this->matrix[5] = cos($this->_angle);
		$this->matrix[6] = -sin($this->_angle);
		$this->matrix[9] = sin($this->_angle);
		$this->matrix[10] = cos($this->_angle);
	}

	private function rotationY()
	{
		$this->identity(1);

		$this->matrix[0] = cos($this->_angle);
		$this->matrix[2] = sin($this->_angle);
		$this->matrix[5] = 1;
		$this->matrix[8] = -sin($this->_angle);
		$this->matrix[10] = cos($this->_angle);
	}

	private function rotationZ()
	{
		$this->identity(1);

		$this->matrix[0] = cos($this->_angle);
		$this->matrix[1] = -sin($this->_angle);
		$this->matrix[4] = sin($this->_angle);
		$this->matrix[5] = cos($this->_angle);
		$this->matrix[10] = 1;
	}

	private function translation()
	{
		$this->identity(1);

		$this->matrix[3] = $this->_vtc->getX();
		$this->matrix[7] = $this->_vtc->getY();
		$this->matrix[11] = $this->_vtc->getZ();
	}

	private function projection()
	{
		$this->identity(1);

		$this->matrix[5] = 1 / tan(0.5 * deg2rad($this->_fov));
		$this->matrix[0] = $this->matrix[5] / $this->_ratio;
		$this->matrix[10] = -1 * (-$this->_near - $this->_far) / ($this->_near - $this->_far);
		$this->matrix[14] = -1;
		$this->matrix[11] = (2 * $this->_near * $this->_far) / ($this->_near - $this->_far);
		$this->matrix[15] = 0;
	}

	/*
	**	public methods to do maths on matrices
	*/

	public function mult(Matrix $rhs)
	{
		$nM = array();

		for ($x = 0; $x < 16; $x += 4)
		{
			for ($y = 0; $y < 4; $y++)
			{
				$nM[$x + $y] = 0;
				$nM[$x + $y] += $this->matrix[$x + 0] * $rhs->matrix[$y + 0];
				$nM[$x + $y] += $this->matrix[$x + 1] * $rhs->matrix[$y + 4];
				$nM[$x + $y] += $this->matrix[$x + 2] * $rhs->matrix[$y + 8];
				$nM[$x + $y] += $this->matrix[$x + 3] * $rhs->matrix[$y + 12];
			}
		}

		$newMatrix = clone $this;
		$newMatrix->matrix = $nM;
		return ($newMatrix);
	}

	public function transformVertex(Vertex $vtx)
	{
		$nV = array();

		$nV["x"] = ($vtx->getX() * $this->matrix[0])
					+ ($vtx->getY() * $this->matrix[1])
					+ ($vtx->getZ() * $this->matrix[2])
					+ ($vtx->getW() * $this->matrix[3]);
		$nV["y"] = ($vtx->getX() * $this->matrix[4])
					+ ($vtx->getY() * $this->matrix[5])
					+ ($vtx->getZ() * $this->matrix[6])
					+ ($vtx->getW() * $this->matrix[7]);
		$nV["z"] = ($vtx->getX() * $this->matrix[8])
					+ ($vtx->getY() * $this->matrix[9])
					+ ($vtx->getZ() * $this->matrix[10])
					+ ($vtx->getW() * $this->matrix[11]);
		$nV["w"] = ($vtx->getX() * $this->matrix[11])
					+ ($vtx->getY() * $this->matrix[13])
					+ ($vtx->getZ() * $this->matrix[14])
					+ ($vtx->getW() * $this->matrix[15]);
		$nV["color"] = $vtx->getC();

		$newVertex = new Vertex($nV);
		return ($newVertex);
	}
}
?>
