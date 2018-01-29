<?php
//verification pour se log
$root = getcwd();
require_once($root.'/redirect.php');
require_once($root.'/check_create.php');
session_start();

if ($_POST['login'] === "" || $_POST['passwd'] === "")
{
	echo "please, fill all the fields";
	redirect('login.php');
	exit();
}
else if (!ctype_alnum($_POST['login']) || !ctype_alnum($_POST['passwd']))
{
 	echo "only alphanumerics are allowed";
	redirect('login.php');
	exit();
}

$tab = file_get_contents('data/users.json');
$tab = json_decode($tab, true);

if ($_POST["submit"] === "OK")
{
	if ((auth($_POST['login'], hash("whirlpool", $_POST['passwd']) ,$tab)) === 1)
	{
		echo "hello ".$_POST['login']."!";
	}
	else
	{
		echo "incorrect username/password";
		redirect('login.php');
		exit();
	}

	if ($_POST["login"])
 		$_SESSION["login"] = $_POST["login"];
 	if ($_POST["passwd"])
 		$_SESSION["passwd"] = hash("whirlpool", $_POST["passwd"]);
 	if (!$_SESSION["login"])
		$_SESSION["login"] = "";
	if (!$_SESSION["passwd"])
		$_SESSION["passwd"] = "";
}
redirect('index.php');
?>
