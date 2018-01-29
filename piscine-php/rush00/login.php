<?php
session_start();
?>
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
	  	menuUser();
	?>
	<!-- LOGIN FORM -->
	<article>
	<div id="forme">
		<?php
		  	if ($_SESSION['login'])
  			{
  				echo "<br>"."please, logout first";
  				redirect('index.php');
  				exit();
			}
		?>
		<div id="dep">
			<form action="log.php" method="post">
				<input type="text" name="login" placeholder="username">
				<input type="password" name="passwd" placeholder="password">
				<input type="submit" name="submit" value="OK"/>
			</form>
		</div>
	</div>
	</article>
	<!-- FOOTER -->
	<footer>
		<div class="copyright">
			<p>copyright © 2017 ft_minishop</p>
		</div>
	</footer>
</body>
</html>
