<?php
	function is_email($email)
	{
		// check for valid email format
		if (preg_match("/\A([\w+\-].?)+@[a-z\d\-]+(\.[a-z]+)*\.[a-z]+\z/i", $email))
			return true;
		else
			return false;
	}
	function is_password($password)
	{
		// password must be at least 8 characters 
		if (preg_match("^\S*(?=\S{8,})(?=\S*[a-z])(?=\S*[A-Z])(?=\S*[\d])\S*^", $password))
			return true;
		else
			return false;
	}
?>
