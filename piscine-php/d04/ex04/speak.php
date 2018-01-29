<?php
session_start();
date_default_timezone_set("Europe/Paris");

function checkRequest()
{
	if (isset($_POST["submit"]) && $_POST["submit"] === "OK"
		&& isset($_POST["msg"]) && !empty($_POST["msg"]))
		return (true);
	else
		return (false);
}

function chatInit()
{
	if (!file_exists("../private"))
		mkdir("../private");
	if (!file_exists("../private/chat"))
		file_put_contents("../private/chat", null);
}

if (empty($_SESSION["logged_on_user"]))
	exit("ERROR\n");
if (checkRequest() === true)
{
	$login = $_SESSION["logged_on_user"];
	$time = time();
	$msg = $_POST["msg"];

	chatInit();
	$entry = array("login" => $login, "time" => $time, "msg" => $msg);
	$chat_content = unserialize(file_get_contents("../private/chat"));
	$chat_content[] = $entry;
	if (file_put_contents("../private/chat", serialize($chat_content), LOCK_EX) === false)
		exit("ERROR\n");
}
?>
<html>
<head>
<script langage="javascript">top.frames["chat"].location = "chat.php";</script>
</head>
<body>
	<form action="speak.php" method="POST">
		<input type="text" name="msg" />
		<input type="submit" name="submit" value="OK" />
	</form>
</body>
</html>
