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
		<?php
			echo '<div id="dep">
			<br>
			<form  action="product.php" method="post">
			<label for="group">add a new product to a category:</label><br><br>
			<SELECT  name="catego" size="1">';
			$u = file_get_contents('data/catego.json');
			$u = json_decode($u, true);
			$u = array_reverse($u);

			foreach ($u as $user)
			{
				echo "<option>".$user['Cname'];
			}
			echo '</SELECT><br>';
		?>
		<br>
		<input type="text" name="name" placeholder="name"><br><br>
		<input type="number" min="5" max="5000" name="price" placeholder="price"><br><br>
		<input type="url" name="image" placeholder="image url"><br><br>
		<input type="submit" name="submit" value="OK"/>
		</form>
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
