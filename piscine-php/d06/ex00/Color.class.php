<?php

class Color {

	public static $verbose = false;

	public $red = 0;
	public $green = 0;
	public $blue = 0;

	public static function doc() {
		return (file_get_contents("Color.doc.txt"));
	}

	public function __construct(array $kwargs) {

		$this->red = array_key_exists("rgb", $kwargs) ? 0xFF & (intval($kwargs["rgb"]) >> 16) : intval($kwargs["red"]);
		$this->green = array_key_exists("rgb", $kwargs) ? 0xFF & (intval($kwargs["rgb"]) >> 8) : intval($kwargs["green"]);
		$this->blue = array_key_exists("rgb", $kwargs) ? 0xFF & intval($kwargs["rgb"]) : intval($kwargs["blue"]);

		if (self::$verbose === true) {
			echo "Color( red: ".str_pad((string)$this->red, 3, " ", STR_PAD_LEFT)
				.", green: ".str_pad((string)$this->green, 3, " ", STR_PAD_LEFT)
				.", blue: ".str_pad((string)$this->blue, 3, " ", STR_PAD_LEFT)." ) constructed.\n";
		}
		return;
	}

	public function __destruct () {
		if (self::$verbose === true) {
			echo "Color( red: ".str_pad((string)$this->red, 3, " ", STR_PAD_LEFT)
				.", green: ".str_pad((string)$this->green, 3, " ", STR_PAD_LEFT)
				.", blue: ".str_pad((string)$this->blue, 3, " ", STR_PAD_LEFT)." ) destructed.\n";
		}
		return;
	}

	public function __toString() {
		return ("Color( red: ".str_pad((string)$this->red, 3, " ", STR_PAD_LEFT)
				.", green: ".str_pad((string)$this->green, 3, " ", STR_PAD_LEFT)
				.", blue: ".str_pad((string)$this->blue, 3, " ", STR_PAD_LEFT)." )");
	}

	public function add($rhs) {
		return (new Color(array("red" => ($this->red + $rhs->red),
								"green" => ($this->green + $rhs->green),
								"blue" => ($this->blue + $rhs->blue))));
	}

	public function sub($rhs) {
		return (new Color(array("red" => ($this->red - $rhs->red),
								"green" => ($this->green - $rhs->green),
								"blue" => ($this->blue - $rhs->blue))));
	}

	public function mult($f) {
		return (new Color(array("red" => ($this->red * $f),
								"green" => ($this->green * $f),
								"blue" => ($this->blue * $f))));
	}
}

?>
