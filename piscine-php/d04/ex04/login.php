<?php
include("auth.php");

$login = $_POST["login"];
$passwd = $_POST["passwd"];

session_start();
if (auth($login, $passwd) === true)
{
	$_SESSION["logged_on_user"] = $login;
?>

<html>
	<body>
		<iframe name="chat" src="chat.php" width="100%" height="550px"></iframe>
		<br />
		<iframe name="speak" src="speak.php" width="100%" height="50px"></iframe>
	</body>
</html>

<?php
}
else
{
	$_SESSION["logged_on_user"] = "";
	echo "ERROR\n";
}
?>
