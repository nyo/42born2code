<?php

abstract class ExempleA {
	// abstract INTERDIT d'instancier cette classe
	// -> a utiliser uniquement en tant que classe mere
	
	abstract public function foo(); // cette syntaxe oblige les class
	// filles a implementer cette methode (impose un 'contrat')
}

// appele "interface" -> classe qui oblige juste des comportements/regles pour
// ses classes filles
// syntaxe:

interface IExemple { // convention -> I<nom>

	function foo(); // pas besoin de specifier "abstract"

}

class Exemple implements IExemple {
	// ... (doit implementer foo etc)
}

?>
