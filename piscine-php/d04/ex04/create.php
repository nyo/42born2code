<?php
$DB_PATH = "../private/";
$DB_FILE = "passwd";
$FAILURE = "ERROR\n";
$SUCCESS = "OK\n";

function checkRequest()
{
	if (isset($_POST["submit"]) && $_POST["submit"] === "OK"
		&& isset($_POST["login"]) && !empty($_POST["login"])
		&& isset($_POST["passwd"]) && !empty($_POST["passwd"]))
		return (true);
	else
		return (false);
}

function dbInit($path, $file)
{
	if (!file_exists($path))
		mkdir($path);
	if (!file_exists($path.$file))
		file_put_contents($path.$file, null);
}

function checkLogin($db, $login)
{
	if ($db)
		foreach ($db as $user)
			if ($user["login"] === $login)
				return (false);
	return (true);
}

function addEntry($db, $path, $req)
{
	$hash = hash("whirlpool", $req["passwd"]);
	$entry = array("login" => $req["login"], "passwd" => $hash);
	$db[] = $entry;
	if (file_put_contents($path, serialize($db)) === false)
		return (false);
	return (true);
}

if (checkRequest() === true)
{
	dbInit($DB_PATH, $DB_FILE);
	$db = unserialize(file_get_contents($DB_PATH.$DB_FILE));
	if (checkLogin($db, $_POST["login"]) === false)
		exit($FAILURE);
	if (addEntry($db, $DB_PATH.$DB_FILE, $_POST) === false)
		exit($FAILURE);
	header("Location: index.html");
	echo $SUCCESS;
}
else
	exit($FAILURE);
?>
