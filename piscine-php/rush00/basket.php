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
	  	menuAdm();
	?>
	<!-- MAIN CONTENT -->
	<article>
		<h1>orders waiting for validation: </h1>
		<?php
			$order = file_get_contents('data/orders.json');
			$order = json_decode($order, true);
			if (!$order)
				echo "no order to check! great!"."<br>";
			else
			{
				$i = 0;
				foreach ($order as $p => $value)
				{
					echo $p." " ;
					foreach ($order[$p] as $k)
					{
						echo $k;
					}
					echo "<hr>";
					$i++;
				}
			}
			echo '<form  action="basket.php" method="post">'."<br>";
			echo '<input type="checkbox" name="Validate">validate the order</input><br>';
			echo '<input type="submit" name="submit" value="OK"/>';
			echo '</form>';
			echo '</div>';
			echo '</div>';
			if ($_POST['Validate'] === "on")
			{
				file_put_contents('data/orders.json', NULL, LOCK_EX);
				unset($_SESSION['total']);
				unset($_SESSION['valid']);
				unset($valid);
				unset($_SESSION['tab']);
				unset($_SESSION['qty']);
				redirect('basket.php');
			}
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
