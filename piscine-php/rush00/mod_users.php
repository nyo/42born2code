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
	  	menuAdm();
		$u = file_get_contents('data/users.json');
		$u = json_decode($u, true);	
		if (count($u) === 1)
			exit("<article>no user to modify</article>");
	?>
	<!-- MAIN CONTENT -->
	<article>
	<label for="login">select the user to modify:</label><br />
	<form action="modu.php" method="post">
		<SELECT  name="login" size="1">
		<?php
			$u = array_reverse($u);
			foreach ($u as $user)
				if ($user['login'] !== "admin")
					echo "<option>".$user['login'];
		?>
		<input type="submit" name="submit" value="OK"/>
		</SELECT>
	</form>
	</article>
	<!-- FOOTER -->
	<footer>
		<div class="copyright">
			<p>copyright © 2017 ft_minishop</p>
		</div>
	</footer>
</body>
</html>
