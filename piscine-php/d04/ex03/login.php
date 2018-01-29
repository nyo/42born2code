<?php
include("auth.php");

$login = $_GET["login"];
$passwd = $_GET["passwd"];

session_start();
if (auth($login, $passwd) === true)
{
	$_SESSION["logged_on_user"] = $login;
	echo "OK\n";
}
else
{
	$_SESSION["logged_on_user"] = "";
	echo "ERROR\n";
}
?>
