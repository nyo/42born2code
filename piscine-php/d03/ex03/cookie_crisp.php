<?php
if (isset($_GET["action"]))
{
	if ($_GET["action"] === "set")
	{
		if (isset($_GET["name"]) && isset($_GET["value"]))
			setcookie($_GET["name"], $_GET["value"]);
	}
	else if ($_GET["action"] === "get")
	{
		if (isset($_GET["name"]) && isset($_COOKIE[$_GET["name"]]))
			echo $_COOKIE[$_GET["name"]]."\n";
	}
	else if ($_GET["action"] === "del")
	{
		if (isset($_GET["name"]))
		{
			unset($_COOKIE[$_GET["name"]]);
			setcookie($_GET["name"], "", time() - 3600);
		}
	}
}
?>
