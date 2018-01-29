<!-- modification d'user -->

<!DOCTYPE html>
<html>
<head>
	<title>42: ft_minishop</title>
	<link rel="icon" type="image/png" href="/wp-content/uploads/fbrfg/favicon-16x16.png" sizes="16x16">
	<link rel="stylesheet" type="text/css" href="style.css"/>
	<meta charset="utf-8">
</head>
<body>
	<!-- HEADER -->
	<?php
		$root = getcwd();
		require_once($root.'/menu/menu.php');
		require_once($root.'/redirect.php');
  		menuAdm();
	?>
	<!-- MAIN CONTENT -->
	<article>
	<?php
	$user = file_get_contents('data/users.json');
	$user = json_decode($user, true);

		foreach ($user as $u)
		{
			if ($u['login'] === $_POST['login'])
			{
				echo "login : ".$u['login']."<br>";
				echo "password : ".$u['password']."<br>";

echo'	<div id="forme">
		<div id="dep">
			<form action="modu.php" method="post">';
echo "			<input type='text' name='login' value='{$u[login]}' placeholder='old username'>";
echo "			<input type='text' name='newlogin' value='' placeholder='new username'>";
echo "			<input type='password' name='passwd' value='' placeholder='password'>";


echo'			<input type="checkbox" name="Validate">valide changes</input>
				<input type="checkbox" name="Supress">delete the user</input>
				<input type="submit" name="submit" value="OK"/>
			</form>
		</div>
	</div>';
			}
		}
	?>
<?php

if ($_POST['Validate'] === "on")
{
	$user = file_get_contents('data/users.json');
	$user = json_decode($user, true);
	foreach ($user as $u => $value)
	{
		echo "<br>".$u."<br>";

		if($user[$u]['login'] === $_POST['login'])
		{
			if ($_POST['newlogin'])
			{
					$user[$u]['login'] = $_POST['newlogin'];
			}
				if ($_POST['passwd'] !== NULL)
			{
					$user[$u]['passwd'] = hash("whirlpool", $_POST['passwd']);
			}
		}
	}

	$users = json_encode($user);
	file_put_contents('data/users.json', $users, LOCK_EX);
	redirect('mod_users.php');
}
if ($_POST['Supress'] === "on" && $_POST['login'] != "admin")
{
	$user = file_get_contents('data/users.json');
	$user = json_decode($user, true);
	foreach ($user as $u => $value)
	{
		echo "<br>".$u."<br>";

		if($user[$u]['login'] === $_POST['login'])
		{
			unset($user[$u]);
		}
		$users = json_encode($user);
		file_put_contents('data/users.json', $users, LOCK_EX);
		redirect('mod_users.php');
	}
}
?>
	</article>
	<!-- FOOTER -->
	<footer>
		<div class="copyright">
			<p>copyright © 2017 ft_minishop</p>
		</div>
	</footer>
</body>
</html>
