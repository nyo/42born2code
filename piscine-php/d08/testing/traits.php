<?php

/*
**	bases des trait(s)
*/

trait Dump {
	// ...
}

class ExempleA { // plus de `extends` ...
	use Dump;
}

/*
**	plusieurs traits definissent la meme methode?
*/

trait JsonSerializer {
	// ...
	public function serialize() {
		// ...
	}
}

trait HTMLSerializer {
	// ...
	public function serialize() {
		// ...
	}
}

class ExempleB {
	use JsonSerializer, HTMLSerializer {
		HTMLSerializer::serialize insteadof JsonSerializer;
	}

	// ou renommer une des methodes

	use JsonSerializer, HTMLSerializer {
		seralizeJson as serialize; // sorte d'alias
	}
}

/*
**	equivalent des interfaces pour les traits
*/

trait Serializer {
	public abstract function serialize(array $dict);
} // tous les traits qui utilisent celui la, devront definir serialize()

trait JsonSerializer {
	use Serializer;

	public function serialize(array $dict) {
		// ...
	}
}

?>
