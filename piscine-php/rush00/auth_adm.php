<?php
session_start();

$root = getcwd();
require_once($root.'/redirect.php');

if ($_SESSION['login'] === "admin" && $_SESSION['passwd'] === hash("whirlpool", "admin"))
	header('Location: adm.php');
else
{
	echo "you're not allowed here. redirecting...";
	redirect('index.php');
}
?>
