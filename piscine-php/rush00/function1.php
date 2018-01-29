<?php
//affiche les 3 derniers articles ajouter
function last3()
{
	$p = file_get_contents('data/products.json');
	$p = json_decode($p, true);
	$p = array_reverse($p);
	$p = array_chunk($p, 3);
	foreach ($p[0] as $product)
	{
		echo "<img class='tof' src='{$product['img']}'/>"."<br>";
		echo $product['name']."<br>";
		echo $product['price']."$"."<br>"."<br>";
		echo '<form  action="add_panier.php" method="post">'."<br>";
		echo '<input type="number" min="0" name="qty" value="1">';
		echo "<input type='submit' name='ajout' value='{$product[name]}' placeholder='Name'>"."<br>";
		echo '</form>';
	}
}

//affiche tous les articles

function group($group)
{
	if(!$group)
		$group = "alcool";
	$p = file_get_contents('data/products.json');
	$p = json_decode($p, true);

	foreach ($p as $product)
	{
		if((stripos($product['catego'],$group)) !== FALSE )
		{
			echo "<img src='{$product['img']}'/>" ."<br>";
			echo($product['name']."<br>");
			echo($product['price']."$"."<br>"."<br>");
			echo ' <form  action="add_panier.php" method="post">'."<br>";
			echo '<input type="number" min="0" name="qty" value="1">';
			echo"<input type='submit' name='ajout' value='{$product[name]}' placeholder='Name'>"."<br>";
			echo ' </form>';
			echo ' <hr>';
		}
	}
}
?>
