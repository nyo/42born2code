<?php
include("api.php");

/*
**	auth() checks if the username & password match an account in the databse.
*/

function auth($username, $password)
{
	if (!$username || !$password)
		return (false);

	$db = getDbContent("users");
	$hash = hash("whirlpool", $password);
	foreach ($db["users"] as $k => $v)
	{
		$user_data = json_decode($v, true);
		if ($user_data["username"] === $username && $user_data["password"] === $hash)
			return (true);
	}
	return (false);
}
?>
