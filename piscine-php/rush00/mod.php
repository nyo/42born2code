<!-- conseil regarde le site en meme temps rendra les choses plus claire  -->

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
	  	require_once($root.'/check_create.php');
	  	menuAdm();
	?>
	<!-- MAIN CONTENT -->
	<article>
	<?php

	$product = file_get_contents('data/products.json');
	$product = json_decode($product, true);

		foreach ($product as $p)
		{
			if ($p['name'] === $_POST['name'])
			{
	echo '<div id="dep"><br>
			<form  action="mod.php" method="post">
			<label for="group">categories you can add the product to:</label><br>
			<SELECT  name="catego" size="1">';
			$u = file_get_contents('data/catego.json');
			$u = json_decode($u, true);
			$u = array_reverse($u);
			echo "<option> NONE";
			foreach ($u as $user)
			{
				echo "<option>".$user['Cname'];
			}
	echo '</SELECT><br>';
	echo '	<br><label for="remove">categories you can remove the product from:</label><br>
			<SELECT  name="remove" size="1">';
			$u = file_get_contents('data/products.json');
			$u = json_decode($u, true);
			$u = array_reverse($u);
			echo "<option> NONE";
			if ($p['name'] === $_POST['name'])
			{
				$gr = explode(":", $p['catego']);
				foreach ($gr as $catego)
				{
					echo "<option>";
					echo $catego;
				}
			}

	echo '</SELECT><br>';
echo '<br><label for="remove">modify product informations:</label><br>';
echo"			<input type='text' name='name' value='{$p[name]}' placeholder='name'>";
echo"				<input type='text' name='newname' value='' placeholder='new name'>";
echo "			<input type='number' min='5' max='5000' name='price' value='{$p[price]}' placeholder='price'>
					<br/>";

echo "			<input type='url' name='image' value='{$p[img]}' placeholder=\"url de l'image\">";

echo'			<br><input type="checkbox" name="Validate">validate changes</input>
				<input type="checkbox" name="Supress">delete the product</input>
				<input type="submit" name="submit" value="OK"/>
			</form>
		</div>
	</div>';
			}
		}
	?>
<?php

if ($_POST['Validate'] === "on")
{

$product = file_get_contents('data/products.json');
$product = json_decode($product, true);

foreach ($product as $p => $value)
	{
		echo "<br>".$p."<br>";

		if($product[$p]['name'] === $_POST['name'])
		{
			if ($_POST['catego'] !== NULL && $_POST['catego'] !== "NONE" )
			{
					$tmp2 = explode(":", $product[$p]['catego']);
					caddgroup($_POST['catego'], $tmp2);
					$product[$p]['catego'] = $product[$p]['catego'].":".$_POST['catego'];

			}
			if ($_POST['remove'] !== NULL && $_POST['remove'] !== "NONE")
			{
					$tmp = explode(":", $product[$p]['catego']);
					foreach ($tmp as $key => $value)
					{
						echo $key." ".$value."<br>";
						echo $tmp[$key]." ".$value."<br>";
						if($_POST['remove'] === $value)
						 	unset($tmp[$key]);
					}
					print_r($tmp);
					$product[$p]['catego'] = implode(":", $tmp);
			}
			if (!empty($_POST['newname']))
			{
					$product[$p]['name'] = $_POST['newname'];
			}
			if ($_POST['price'] !== NULL)
			{
					$product[$p]['price'] = $_POST['price'];
			}
				if ($_POST['alcool'] !== NULL)
			{
					$product[$p]['alcool'] = $_POST['alcool'];
			}
				if ($_POST['vodka'] !== NULL)
			{
					$product[$p]['vodka'] = $_POST['vodka'];
			}
				if ($_POST['rhum'] !== NULL)
			{
					$product[$p]['rhum'] = $_POST['rhum'];
			}
			if ($_POST['biere'] !== NULL)
			{
					$product[$p]['biere'] = $_POST['biere'];
			}
				if ($_POST['vins'] !== NULL)
			{
					$product[$p]['vins'] = $_POST['vins'];
			}
			if ($_POST['img'] !== NULL)
			{
					$product[$p]['img'] = $_POST['img'];
			}
		}
	}
	$products = json_encode($product);
	file_put_contents('data/products.json', $products, LOCK_EX);
	redirect('mod_prod.php');
}

if ($_POST['Supress'] === "on")
{

$product = file_get_contents('data/products.json');
$product = json_decode($product, true);

foreach ($product as $p => $value)
	{
		echo "<br>".$p."<br>";

		if($product[$p]['name'] === $_POST['name'])
		{
			unset($product[$p]);
		}

	$products = json_encode($product);
	file_put_contents('data/products.json', $products, LOCK_EX);
	redirect('mod_prod.php');
	}
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
