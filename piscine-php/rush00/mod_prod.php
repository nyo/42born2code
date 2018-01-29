
<!-- page de modification de produit/article -->

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
		$u = file_get_contents('data/products.json');
		$u = json_decode($u, true);	
		//echo "<article>".count($u)."</article>";
		if (count($u) === 0)
			exit("<article>no product to modify</article>");
	?>
	<!-- MAIN CONTENT -->
	<article>
		<form action="mod.php" method="post">
			<label for="name">select the product to modify:</label><br><br>
			<SELECT  name="name" size="1">
			<?php
					$p = file_get_contents('data/products.json');
					$p = json_decode($p, true);
					$p = array_reverse($p);
		
					foreach ($p as $product)
					{
						echo "<option>";
						print($product['name']);
					}
			?>
			</SELECT><br><br>
			<input type="submit" name="submit" value="OK"/>
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
