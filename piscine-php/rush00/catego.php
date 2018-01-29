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
	?>
	<!-- MAIN CONTENT -->
	<article>
		<h1>categories management</h1>
		<a href="create_catego.php"><font color="black">> create category <</font></a><br>
		<a href="mod_catego.php"><font color="black">> modify category <</font></a><br><br>
		<?php
			$catego = file_get_contents('data/catego.json');
			$catego = json_decode($catego, true);
			foreach ($catego as $g)
				echo $g['Cname']."<br>";
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
