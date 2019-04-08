<?php
include_once("../utils/db.php");
if (isset($_POST["username"]) && isset($_POST["token"]) && (db_get("users", "username", $_POST["username"], "token", $PDO) === $_POST["token"])) {
	db_update("users", "id", db_get("users", "username", $_POST["username"], "id", $PDO), "verified", 1, $PDO);
	db_update("users", "id", db_get("users", "username", $_POST["username"], "id", $PDO), "token", null, $PDO);
	session_start();
	$_SESSION["status"] = true;
	$_SESSION["message"] = "Your email has been confirmed.";
}
else {
	session_start();
	$_SESSION["status"] = false;
	$_SESSION["message"] = "This token is expired or invalid.";
}
header("Location: ".$url."index.php");
die();
?>
