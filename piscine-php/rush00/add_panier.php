<?php
session_start();

$root = getcwd();
require_once($root.'/redirect.php');

$_SESSION['tab'] = array_merge((array) $_SESSION['tab'],(array)  $_POST['ajout']);
$_SESSION['qty'] = array_merge((array) $_SESSION['qty'],(array)  $_POST['qty']);

echo "product added to cart<br>";
redirect('shop.php');
?>
