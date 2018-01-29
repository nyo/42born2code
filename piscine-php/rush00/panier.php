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
		<?php echo "<br><strong>hello ".$_SESSION['login']."!</strong><br>"?>
		<h1>YOUR CART</h1>
			<?php
				$root = getcwd();
				require_once($root."/check_create.php");
				require_once($root."/redirect.php");
				$order = file_get_contents('data/orders.json');
				if($order)
				{
					$stock = array("");
					$order = file_get_contents('data/orders.json');
					$order = json_decode($order, true);
					foreach ($order as $key => $value) {

						if($key === $_SESSION['login'])
						{

							echo "please wait, your order has been sent to the administrator.";
							exit();
						}
					}
				}
					if (!$_SESSION['tab'])
					{
						echo "oops, your cart is empty..."."<br>";
					}
					else
					{
						$i = 0;
						$_SESSION['total'] = 0;
						foreach (array_combine($_SESSION['tab'], $_SESSION['qty']) as $poke => $qty )
						{
			 				if($poke)
			 				{
				 				echo $poke." ".cprice($poke)."$ "."x".$qty." "."= ".cprice($poke) * $qty."$"."<br>";
			 					$tmp =  $poke." ".cprice($poke)."$ "."x".$qty." "."= ".cprice($poke) * $qty."$"."<br>";
			 				}
							$_SESSION['total'] += intval(cprice($poke)) * intval($qty);
			 				$stock[$i] = $tmp;
			 				$i++;
			 			}
			 		}
			 		$total = $_SESSION[total];
			 		echo "<br>"."total: ".($total ? $total : "0")."$"."<br>";
			 	if ($_SESSION['login'] === "")
				{
					echo "you need to login in order to continue with your order"."<br>";
					echo ' <form  action="panier.php" method="post">'."<br>";
					echo'	<input type="checkbox" name="Supress">empty the cart</input>
							<input type="submit" name="submit" value="OK"/>
							</form>
						</div>
					</div>';
				}
				else
				{
					echo ' <form  action="panier.php" method="post">'."<br>";
					echo'			<input type="checkbox" name="Validate">validate the order</input><br>
								<input type="checkbox" name="Supress">empty the cart</input><br>
								<input type="submit" name="submit" value="OK"/>
							</form>
						</div>
					</div>';
				}

		if ($_POST['Validate'] === "on" && !empty($stock))
		{
			$order = file_get_contents('data/orders.json');
			$order = json_decode($order, true);
			$order[$_SESSION[login]] = $stock;
			$order = json_encode($order);
			$order = file_put_contents('data/orders.json', $order, LOCK_EX);
			unset($stock);
			redirect('panier.php');
		}
		if ($_POST['Supress'] === "on")
		{
			unset($_SESSION['total']);
			unset($_SESSION['tab']);
			unset($_SESSION['qty']);
			unset($stock);
			redirect('panier.php');
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
