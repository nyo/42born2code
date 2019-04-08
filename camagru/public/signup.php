<!doctype html>
<html>
	<?php include_once("./static/head.php");?>
	<?php include_once("./static/header.php");?>
	<div id="cr-main">
		<form method="post" action="signup.php">
			<div id="cr-sign-form">
				<input type="email" placeholder="E-MAIL" name="e-mail" required>
				<input type="text" placeholder="USERNAME" name="username" required>
				<input type="password" placeholder="PASSWORD" name="password" required>
				<button type="submit">SIGN UP</button>
			</div>
		</form>
	</div>
	<?php include_once("./static/footer.php");?>
	<?php
	include("../utils/db.php");
	if (isset($_SESSION["status"])) {
		echo '<script>printMessage("' . $_SESSION["message"] . '", "' . ($_SESSION["status"] == true ? "#47d147" : "#ff6666") . '");</script>';	
		$_SESSION["status"] = null;
		$_SESSION["message"] = null;
	}
	if (isset($_POST["e-mail"]) && isset($_POST["username"]) && isset($_POST["password"]))
	{
		$ret = user_register($_POST["username"], $_POST["password"], $_POST["e-mail"], $PDO);
		$_SESSION["status"] = $ret["status"];
		$_SESSION["message"] = $ret["message"];
		if ($ret["status"] === true)
		{
			$message = "<html>
		<head>
			<title>Email confirmation</title>
			<style>
				body {
					background-color	: #e5e6eb;
					color				: black;
					font-size			: 1em;
					font-family			: 'Roboto', sans-serif;
				}
				#cr-button {
					margin: 0 auto;
					font-size: 1.5rem;
					padding: 1.0rem 2.0rem;
					display: block;
					background-color: #009ac9;
					border: 1px solid transparent;
					color: #ffffff;
					font-weight: 200;
					border-radius: 3px;
				}
				#cr-button:hover {
					background-color: #ffffff;
					color: #009ac9;
					border-color: #009ac9;
				}
			</style>
		</head>
		<center>
		<p>Thank you for signing up on camag.ru, please confirm your email by clicking the button below</p>
		<form method='post' action='" .$url. "confirm.php'>
		<input type='hidden' name='username' value='" . $_POST["username"] . "'>
		<input type='hidden' name='token' value='" . db_get("users", "username", $_POST["username"], "token", $PDO) . "'>
		<input id='cr-button' type='submit' value='CLICK ME'>
		</form>
		</center>
		</html>";
			$headers[] = 'MIME-Version: 1.0';
			$headers[] = 'Content-type: text/html; charset=iso-8859-1';
			mail($_POST["e-mail"], "Email confirmation", $message, implode("\r\n", $headers));
			header("Location: " . $url . "index.php");
		}
		else
			header("Location: " . $url . "signup.php");
		die();
	}
	?>
</html>
