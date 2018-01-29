<?php
include("api.php");

/*
**	checkRequest() checks if the data received as POST exists & is valid.
*/

function checkRequest()
{
	if (isset($_POST["submit"]) && $_POST["submit"] === "OK"
		&& isset($_POST["username"]) && !empty($_POST["username"])
		&& isset($_POST["password"]) && !empty($_POST["password"]))
		return (true);
	else
		return (false);
}

/*
**	checkUsername() checks if the username is available to register.
*/

function checkUsername($username, $db)
{
	foreach ($db["users"] as $k => $v)
	{
		$user_data = json_decode($v, true);
		if ($user_data["username"] === $username)
			return (false);
	}
	return (true);
}

if (checkRequest() === true)
{
	$db = getDbContent("users");

	if (checkUsername($_POST["username"], $db) === false)
	{	
		echo "ce nom d'utilisateur n'est pas disponible.\n";
		exit("<br><a href=\"register.html\"><i>retourner a la page d'inscription?</i></a>\n");
	}
	addNewUser($db, $_POST["username"], $_POST["password"]);
	header("Location: index.php");
}
else
	exit("request error.\n");
?>
