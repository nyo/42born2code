<?php
include("auth.php");
session_start();

/*
**	login.php chekcs if the login credentials are valid.
**	If so, it stores the username in the session variable "logged_on_user".
**	Else, it stores an empty string instead.
*/

$username = $_POST["username"];
$password = $_POST["password"];

if (auth($username, $password) === true)
{
	$_SESSION["logged_on_user"] = $username;
	header("Location: index.php");
}
else
{
	$_SESSION["logged_on_user"]= "";
	echo "identifiant ou mot de passe invalide(s).\n";
	echo "<br><a href=\"login.html\"><i>retourner a la page de connexion?</i></a>\n";
}
?>
