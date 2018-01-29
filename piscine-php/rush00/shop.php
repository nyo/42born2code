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
	?>
	<!-- MAIN CONTENT -->
	<article>
		<?php echo "<br><strong>hello ".$_SESSION['login']."!</strong><br><br>"?>
		<form action="shop.php" method="post">
			<label for="catego">please, select a category</label><br><br>
			<SELECT  name="catego" size="5">
			<?php
				$g = file_get_contents('data/catego.json');
				$g = json_decode($g, true);
				foreach ($g as $group)
					echo "<option>".$group[Cname];
			?>
			</SELECT>
			<br><br><input type="submit" name="submit" value="OK"/>
		</form>
		<hr>
		<div class="boutique">
		<?php
			$root = getcwd();
			require_once($root.'/function1.php');
			group($_POST['catego']);
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
