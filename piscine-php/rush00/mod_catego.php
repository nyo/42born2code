<!-- page de modification de category -->

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
		<form action="modg.php" method="post">
			<label for="name">select the category to modify:</label><br />
			<SELECT  name="Cname" size="1">
				<?php
					$g = file_get_contents('data/catego.json');
					$g = json_decode($g, true);
					foreach ($g as $group)
					{
						echo "<option>";
						print($group[Cname]);
					}
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
