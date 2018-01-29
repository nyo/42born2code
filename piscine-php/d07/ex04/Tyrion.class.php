<?php
class Tyrion {
	public function sleepWith($who) {
		if ($who instanceof Jaime)
			echo "Not even if I'm drunk !\n";
		else if ($who instanceof Sansa)
			echo "Let's do this.\n";
		else if ($who instanceof Cersei)
			echo "Not even if I'm drunk !\n";
	}
}
?>
