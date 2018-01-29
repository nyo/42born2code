<?php

/*
**	getDbContent() returns the content of a database file as an array.
**	$type can be: "users", "orders" & "products".
*/

function getDbContent($type)
{
	$db = file_get_contents("fileJson/".$type.".json");
	$db = json_decode($db, true);
	return ($db);
}

/*
**	addNewUser() adds data for a new user in the users.json file.
**	The first param is the -decoded- database content, the second is the
**	user's name, and the last one is his password in PLAINTEXT.
*/

function addNewUser($db_content, $username, $password)
{
	$hash = hash("whirlpool", $password); // ALREADY HASHING PASSWORD HERE!
	$new_user = array("username" => $username, "password" => $hash);
	$new_user = json_encode($new_user);
	array_push($db_content["users"], $new_user);
	file_put_contents("fileJson/users.json", json_encode($db_content), LOCK_EX);
}

/*
**	removeUser() removes all data of the specified user in the users.json file.
**	The first param is the -decoded- database content, the second is the username.
*/

function removeUser($db_content, $username)
{
	foreach ($db_content["users"] as $k => $v)
		if (json_decode($v, true)["username"] === $username)
			array_splice($db_content["users"], $k);
	file_put_contents("fileJson/users.json", json_encode($db_content), LOCK_EX);
}

/*
**	addNewCategory() adds data for a new category in the products.json file.
**	The first param is the -decoded- database content, the second is a
**	string of the category name to add.
*/

function addNewCategory($db_content, $category)
{
	foreach ($db_content["products"] as $c)
		if (key($c) === $category)
			exit ("category already existing. nothing done.\n");
	array_push($db_content["products"], array($category => array()));
	file_put_contents("fileJson/products.json", json_encode($db_content), LOCK_EX);
	exit ("added new category '$category'!\n");
}

/*
**	addNewProduct() adds data for a new category > product in the products.json file.
**	The first param is the decoded database content,
**	the second is a json object of the product to add.
*/

function addNewProduct($db_content, $category, $product)
{
	foreach ($db_content["products"] as $k => $v)
	{
		if (key($v) === $category)
		{
			foreach ($db_content["products"][$k][$category] as $p)
				if ($p === $product)
					exit ("product already existing. nothing done.\n");
			array_push($db_content["products"][$k][$category], $product);
			file_put_contents("fileJson/products.json", json_encode($db_content), LOCK_EX);
			exit ("added new product '$product' in category '$category'!\n");
		}
	}
	array_push($db_content["products"], array($category => array()));
	array_push($db_content["products"][count($db_content["products"]) - 1][$category], $product);
	file_put_contents("fileJson/products.json", json_encode($db_content), LOCK_EX);
	exit ("added new product '$product' in category '$category'!\n");
}

/*
**	addNewOrder() adds data for a new order in the orders.json file. 
**	The first param is the -decoded- database content, the second is
**	an array containing all keys => value for the order.
*/

function addNewOrder($db_content, $order_array)
{
	$new_order = json_encode($order_array);
	array_push($db_content["orders"], $new_order);
	file_put_contents("fileJson/orders.json", json_encode($db_content), LOCK_EX);
}

?>
