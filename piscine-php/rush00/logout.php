<?php
session_start();
$root = getcwd();
require_once($root.'/redirect.php');
if ($_SESSION['login'] !== "") {
	$_SESSION['login'] = "";
	$_SESSION['total'] = "";
	$_SESSION['tab'] = "";
	$_SESSION['qty'] = "";
}
redirect('index.php');
?>
