<?php
//verifie pour la creation d'un groupe
$root = getcwd();
require_once($root.'/redirect.php');
require_once($root.'/check_create.php');

if($_POST['Cname'] === "" )
	{
		$error = "please, fill all the fields";
		echo '<script type="text/javascript">window.alert("'.$error.'");</script>';
		redirect('create_catego.php');
		exit();
	}
	if(file_exists('data/catego.json'))
	{
		$new_catego =  array('Cname' => $_POST[Cname]);
		$u = file_get_contents('data/catego.json');
		$u = json_decode($u, true);
		cgroup($_POST[Cname],$u);
		$u[] = $new_catego;
		$u =json_encode($u);
		file_put_contents('data/catego.json', $u, LOCK_EX);
		redirect('catego.php');
	}
?>
