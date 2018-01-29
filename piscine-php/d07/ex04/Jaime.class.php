<?php
class Jaime {
	public function sleepWith($who) {
		if ($who instanceof Tyrion)
			echo "Not even if I'm drunk !\n";
		else if ($who instanceof Sansa)
			echo "Let's do this.\n";
		else if ($who instanceof Cersei)
			echo "With pleasure, but only in a tower in Winterfell, then.\n";
	}
}
?>
