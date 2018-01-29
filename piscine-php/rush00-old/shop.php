<html>
<head>
	<meta charset="utf-8">
	<title>ft_minishop</title>
</head>
<body>
	<?php
	include("menu.php");
	displayMenu();
	?>
	<form action="shop2.php" method="POST">
		<label>selectionner la categorie a afficher:</label><br />
		<select name="catego" size="5">
			<?php
			include("api.php");
			$db = getDbContent("products");
			foreach ($db["products"] as $c)
				echo "<option>".key($c)."</option>";
			?>
			<input type="submit" name="submit" value="OK" />
		</select>
	</form>
</body>
</html>
