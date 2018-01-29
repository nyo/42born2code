<?php
/*
try {
	throw new Exception("message d'exception!", 42);
	echo "the script stops right before this line ^ (this will never be displayed)\n";
}
catch (Exception $exc) {
	echo "\n\tgot an exception!\n\n";
	echo "\$exc->getMessage(): ".$exc->getMessage()."\n";
	echo "\$exc->getCode(): ".$exc->getCode()."\n";
	echo "\$exc->getFile(): ".$exc->getFile()."\n";
	echo "\$exc->getLine(): ".$exc->getLine()."\n";
	echo "\$exc:\n".$exc."\n";
}
*/

class AwesomeException extends Exception {

	public function __construct($message = "", $code = 0, $previous = null) {
		parent::__construct($message, $code, $previous);
		echo "AwesomeException constructed!\n";
		return;
	}

	public function howIsThisException() {
		return ("awesome!");
	}
}

try {
	throw new AwesomeException("message d'exception!", 42);
	echo "the script stops right before this line ^ (this will never be displayed)\n";
}
catch (Exception $exc) {
	echo "\n\tgot an exception!\n\n";
	echo "\$exc->howIsThisException(): ".$exc->howIsThisException()."\n";
	echo "\$exc->getMessage(): ".$exc->getMessage()."\n";
	echo "\$exc->getCode(): ".$exc->getCode()."\n";
	echo "\$exc->getFile(): ".$exc->getFile()."\n";
	echo "\$exc->getLine(): ".$exc->getLine()."\n";
	echo "\$exc:\n".$exc."\n";
}
?>
