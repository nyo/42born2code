<?php
// creation d'un user
$root = getcwd();
require_once($root.'/redirect.php');
require_once($root.'/check_create.php');

if($_POST['login'] === ""| $_POST['passwd'] === "")
	{
		$error = "please, fill all the fields";
		echo '<script type="text/javascript">window.alert("'.$error.'");</script>';
		redirect('index.php');
		exit();
	}
elseif (!ctype_alnum($_POST['login']) || !ctype_alnum($_POST['passwd']))
{
 	echo "only alphanumeric characters are allowed";
	redirect('login.php');
	exit();
}
elseif(file_exists('data/users.json'))
{
	$new_user =  array('login' => $_POST[login], 'passwd' => hash("whirlpool", $_POST[passwd]));
	$u = file_get_contents('data/users.json');
	$u = json_decode($u, true);
	cpseudo($_POST[login], $u);
	$u[] = $new_user;
	$u = json_encode($u);
	file_put_contents('data/users.json', $u, LOCK_EX);
	redirect('index.php');
	}
?>
