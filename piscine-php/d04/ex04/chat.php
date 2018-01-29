<?php
date_default_timezone_set("Europe/Paris");

function chatInit()
{
	if (!file_exists("../private"))
		mkdir("../private");
	if (!file_exists("../private/chat"))
		file_put_contents("../private/chat", null);
}

$chat_content = unserialize(file_get_contents("../private/chat"));
foreach ($chat_content as $k => $v)
{
	echo "[".date("H:i", $chat_content[$k]["time"])."] ";
	echo "<b>".$chat_content[$k]["login"]."</b>: ";
	echo $chat_content[$k]["msg"]."<br />\n";
}
?>
