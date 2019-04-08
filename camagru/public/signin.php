<!doctype html>
<html>
	<?php include_once("./static/head.php");?>
	<?php include_once("./static/header.php");?>
	<div id="cr-main">
		<form method="post" action="signin.php">
			<div id="cr-sign-form">
				<input type="text" placeholder="USERNAME" name="username" required>
				<input type="password" placeholder="PASSWORD" name="password" required>
				<button type="submit">SIGN IN</button>
				<a onMouseOver='this.style.textDecoration="underline"' onMouseOut='this.style.textDecoration="none"' href="forgotpassword.php">Forgotten password?</a>
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
	if (isset($_POST["username"]) && isset($_POST["password"])) {
		$ret = user_login($_POST["username"], $_POST["password"], $PDO);
		if ($ret["status"] == true) {
			$_SESSION["id"] = db_get("users", "username", $_POST["username"], "id", $PDO);
			$_SESSION["status"] = $ret["status"];
			$_SESSION["message"] = $ret["message"];
			header("Location: " . $url . "profile.php");
		}
		else {
			$_SESSION["status"] = $ret["status"];
			$_SESSION["message"] = $ret["message"];
			header("Location: " . $url . "signin.php");
		}
		die();
	}
	?>
	</html>
