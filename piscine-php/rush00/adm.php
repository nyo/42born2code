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
		<h1>Welcome to the admin page!</h1>
		<div id="users">
			<h1 class="title">last users: </h1>
			<?php
				$u = file_get_contents('data/users.json');
				$u = json_decode($u, true);
				$u = array_reverse($u);
				$u = array_chunk($u, 10);
				foreach ($u[0] as $user)
					print($user['login']."<br>");
			?>
		</div>
		<div id="products">
			<h1 class="title">last products: </h1>
			<?php
				$p = file_get_contents('data/products.json');
				$p = json_decode($p, true);
				$p = array_reverse($p);
				$p = array_chunk($p, 10);
				foreach ($p[0] as $product)
					print($product['name']."<br>");
			?>
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
