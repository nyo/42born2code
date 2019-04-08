<?php
include_once("../utils/db.php");
if(!isset($_SESSION)) {
	session_start();
}
session_destroy();
$_SESSION["status"] = true;
$_SESSION["message"] = "Succesfully logged out.";
$_SESSION["id"] = null;
header("Location: ".$url."index.php");
die();
?>
