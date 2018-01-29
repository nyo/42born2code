<?php
$root = getcwd();
require_once($root.'/redirect.php');

//verifie si le login est valide

function cpseudo($login, $tab)
{
	foreach ($tab as $name)
	{
		if($name['login'] === $login)
		{
			echo "That login is not available"."<br/>";
			redirect('inscription.php');
			exit();
		}
	}
}

//verifie si la category qu l'on veut ajouter a l'article est deja present
function caddgroup($grp, $tab)
{
	foreach ($tab as $catego)
	{
		if($catego === $grp)
		{
			echo "This Drink is in this Category already "."<br/>";
			redirect('mod_prod.php');
			exit();
		}
	}
}

//verifie si la category est deja existante

function cgroup($grp, $tab)
{
	foreach ($tab as $catego)
	{
		if($catego['login'] === $grp)
		{
			echo "That Category already exist"."<br/>";
			redirect('create_catego.php');
			exit();
		}
	}
}


function auth($login, $passwd , $tab)
{
	foreach ($tab as $elem)
	{
		if ($elem['login'] === $login && $elem['passwd'] === $passwd)
			return (1);

	}
	return (-1);
}

//verifie si le produit que l'on veut ajouter est deja dans la boutique

function cname($product, $tab)
{
	foreach ($tab as $name)
	{
		if($name['name'] === $product)
		{
			echo "That drink is Already in sell"."<br/>";
			redirect('products.php');
			exit();
		}
	}
}

function cprice($product)
{
	$tab = file_get_contents('data/products.json');
	$tab = json_decode($tab, true);

	foreach ($tab as $name)
	{
		if($name['name'] === $product)
		{
			return $name['price'];
		}
	}
}

?>
