<?php

function menuUser()
{
	$root = getcwd();
	$ret = file_get_contents($root.'/menu/menu_user.php');

	echo $ret;
}

function menuAdm()
{
	$root = getcwd();
	$ret = file_get_contents($root.'/menu/menu_adm.php');
	echo $ret;
}
?>
