<?php
final ExempleA { // classe dont on ne peut PAS heriter 
	final public function foo() {
		// empeche de redefinir foo() dans une classe fille
		// (stupide ici, car cette classe est theoriquement impossible a heriter)
	}
}

?>
