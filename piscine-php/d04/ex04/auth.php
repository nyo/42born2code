<?php
function auth($login, $passwd)
{
	if (!$login || !$passwd)
		return (false);

	$db = unserialize(file_get_contents("../private/passwd"));
	$hash = hash("whirlpool", $passwd);

	if ($db)
		foreach ($db as $user)
			if ($user["login"] === $login && $user["passwd"] === $hash)
				return (true);
	return (false);
}
?>
