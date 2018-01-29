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
	  	menuUser();
		$u = file_get_contents('data/products.json');
		$u = json_decode($u, true);	
		if (count($u) === 0)
			exit("<article>no product available</article>");
	?>
	<!-- MAIN CONTENT -->
	<article>
		<h1>new products!</h1>
		<?php
		$root = getcwd();
		require_once($root.'/function1.php');
		last3();
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
