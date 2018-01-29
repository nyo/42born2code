<?php
$root = getcwd();
require_once($root.'/redirect.php');
require_once($root.'/check_create.php');

if($_POST['name'] === "" | $_POST['price'] === "")
	{
		$error = "please, fill all the fields";
		echo '<script type="text/javascript">window.alert("'.$error.'");</script>';
		redirect('products.php');
		exit();
	}
	if(file_exists('data/products.json'))
	{
		$new_product =  array('catego' => $_POST[catego], 'name' => $_POST[name],'price' => $_POST[price],'img' => $_POST[img],
		'vodka' => $_POST[vodka], 'rhum' => $_POST[rhum], 'vins' => $_POST[vins],
		'biere' => $_POST[biere]);
		$u = file_get_contents('data/products.json');
		$u = json_decode($u, true);
		cname($_POST[name], $u);
		$u[] = $new_product;
		$u =json_encode($u);
		file_put_contents('data/products.json', $u, LOCK_EX);
		redirect('products.php');
	}
?>
