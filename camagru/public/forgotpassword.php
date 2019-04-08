<!doctype html>
<html>
	<?php include_once("./static/head.php"); ?>
	<?php include_once("./static/header.php"); ?>
	<div id="cr-main">
	<form method="post" action="forgotpassword.php">
			<div id="cr-sign-form">
				<input type="email" placeholder="EMAIL" name="email" required>
				<button type="submit">SEND RECOVERY EMAIL</button>
			</div>
		</form>
	</div>
	<?php include_once("./static/footer.php"); ?>
	<?php 
	require_once("../utils/db.php");
	if(!isset($_SESSION)) {
		session_start();
	}
	if (isset($_SESSION["status"])) {
		echo '<script>printMessage("' . $_SESSION["message"] . '", "' . ($_SESSION["status"] == true ? "#47d147" : "#ff6666") . '");</script>';	
		$_SESSION["status"] = null;
		$_SESSION["message"] = null;
	}
	if (isset($_POST["email"])) {
		if (db_check("users", "email", $_POST["email"], $PDO)) {
			db_update("users", "email", $_POST["email"], "token", uniqid(), $PDO);
			$_SESSION["status"] = true;
			$_SESSION["message"] = "Password recovery email has been sent.";
			$message = "<html>
				<head>
					<title>Password recovery</title>
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
				<p>You requested a password reset, please click the button bellow to reset your password. This will be a onetime try button, after this the token will be invalid and you'll have to request password reset again.</p>
				<form method='post' action='" .$url. "resetpassword.php'>
				<input type='hidden' name='email' value='" . $_POST["email"] . "'>
				<input type='hidden' name='token' value='" . db_get("users", "email", $_POST["email"], "token", $PDO) . "'>
				<input id='cr-button' type='submit' value='CLICK ME'>
				</form>
				</center>
				</html>";
			$headers[] = 'MIME-Version: 1.0';
			$headers[] = 'Content-type: text/html; charset=iso-8859-1';
			mail($_POST["email"], "Password reset", $message, implode("\r\n", $headers));
			header("Location: " . $url . "forgotpassword.php");
			die();
		}
		else {
			$_SESSION["status"] = false;
			$_SESSION["message"] = "This email doesn't have an account.";
			header("Location: " . $url . "forgotpassword.php");
			die();
		}
	}
	?>
</html>
