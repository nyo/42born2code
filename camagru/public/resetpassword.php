<!doctype html>
<html>
	<?php include_once("./static/head.php"); ?>
	<?php include_once("./static/header.php"); ?>
	<?php
	require_once("../utils/db.php");
	if (isset($_POST["token"]) && isset($_POST["email"])) {
		if ($_POST["token"] === db_get("users", "email", $_POST["email"], "token", $PDO)) {
			echo "
		<div id='cr-main'>
		<form method='post' action='resetpassword.php'>
			<div id='cr-sign-form'>
				<input type='password' placeholder='NEW PASSWORD' name='new' required>
				<input type='password' placeholder='CONFIRM' name='confirm' required>
				<input type='hidden' name='token_' value='" . $_POST["token"] . "'>
				<input type='hidden' name='email_' value='" . $_POST["email"] . "'>
				<button type='submit'>CHANGE PASSWORD</button>
			</div>
		</form>
		</div>";
		}
		else {
			echo "<div id='cr-main'>";
			echo "<center><h1>Invalid token.</h1></center>";
			echo "</div>";
		}
	}
	if (isset($_POST["new"]) && isset($_POST["confirm"]) && isset($_POST["email_"]) && isset($_POST["token_"])) {
		if (($_POST["new"] === $_POST["confirm"]) && ($_POST["token_"] === db_get("users", "email", $_POST["email_"], "token", $PDO))) {
			db_update("users", "email", $_POST["email_"], "token", null, $PDO);
			db_update("users", "email", $_POST["email_"], "password", hash("whirlpool", $_POST["new"]), $PDO);
			if(!isset($_SESSION)) {
				session_start();
			}
			$_SESSION["status"] = true;
			$_SESSION["message"] = "Your password has been changed.";
			header("Location: " . $url . "index.php");
			die();
		}
		else {
			if(!isset($_SESSION)) {
				session_start();
			}
			$_SESSION["status"] = false;
			$_SESSION["message"] = "Passwords does not match.";
			header("Location: " . $url . "index.php");
			die();
		}
	}
	?>
	<?php include_once("./static/footer.php");?>
</html>
