<?php
$image_path = "../img/42.png";
$correct_user = "zaz";
$correct_pass = "jaimelespetitsponeys";

if ($_SERVER['PHP_AUTH_USER'] === $correct_user && $_SERVER['PHP_AUTH_PW'] === $correct_pass)
{
	$raw = file_get_contents($image_path); 
	$base64 = base64_encode($raw);
	echo "<html><body>\n";
	echo "Bonjour Zaz<br />\n";
	echo "<img src='data:image/png;base64,$base64'>\n";
	echo "</body></html>\n";
}
else
{
	header("HTTP/1.0 401 Unauthorized");
	header("WWW-Authenticate: Basic realm=''Espace membres''");
	echo "<html><body>Cette zone est accessible uniquement aux membres du site</body></html>\n";
}
?>
