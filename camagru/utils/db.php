<?php
include("../config/database.php");
include("checks.php");

$PDO = new PDO($DB_DSN, $DB_USER, $DB_PASS, [ PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION ]);
$url = "http://localhost:8080/camagru/public/";

function user_register($username, $password, $email, $PDO)
{
	if (!is_password($password)) {
		$ret = array("status" => false, "message" => "Password has wrong format.");
	} else {
		$ret = array("status" => true, "message" => "Activate your account via email.");
		$username = filter_var($username, FILTER_SANITIZE_STRING);
		if (!filter_var($email, FILTER_VALIDATE_EMAIL))
			$ret = ["status" => false, "message" => "Specify a correct email address."];
		if (db_check('users', 'username', $username, $PDO))
			$ret = ["status" => false, "message" => "Username already in use."];
		if (db_check('users', 'email', $email, $PDO))
			$ret = ["status" => false, "message" => "Email address already in use."];
		if ($ret["status"] == true)
			db_add('users', array('username' => $username, 'password' => hash('whirlpool', $password), 'email' => $email, 'token' => uniqid()), $PDO);
	}
	return $ret;
}

function user_login($username, $password, $PDO)
{
	$ret = array("status" => true, "message" => "You logged in succesfully.");
	if (!db_check("users", "username", $username, $PDO))
		$ret = ["status" => false, "message" => "This username doesn't exist."];
	if (db_check("users", "username", $username, $PDO) && (db_get('users', 'username', $username, 'password', $PDO) !== hash('whirlpool', $password)))
		$ret = ["status" => false, "message" => "The username or password is incorrect."];
	if (db_check("users", "username", $username, $PDO) && db_get("users", "username", $username, "verified", $PDO) == 0)
		$ret = ["status" => false, "message" => "Activate your account via email."];
	return $ret;
}

function db_add($table, array $entry, $PDO)
{
	# users table format: id, creation_date, username, password, email, admin
	$sql = "INSERT INTO db_camagru.".$table." (".implode(", ", array_keys($entry)).") VALUES ('".implode("', '", array_values($entry))."')";
	$query = $PDO->prepare($sql);
	$query->execute();
}

function db_check($table, $column, $value, $PDO)
{
	$query = $PDO->prepare("SELECT * FROM db_camagru.".$table." WHERE ".$column." = ?");
	$query->execute([$value]);
	$count = $query->rowCount();
	if ($count === 1)
		return true;
	else
		return false;
}

function db_get($table, $column, $value, $ret, $PDO)
{
	$query = $PDO->prepare("SELECT * FROM db_camagru.".$table." WHERE ".$column." = ?");
	$query->execute([$value]);
	$result = $query->fetchAll();
	return ($ret ? $result[0][$ret] : $result);
}
function db_update($table, $column, $old, $tomodify, $value, $PDO)
{
	# users table format: id, creation_date, username, password, email, admin
	$sql = "UPDATE db_camagru.".$table." SET ".$tomodify." = '".$value."' WHERE ".$column." = '".$old."'";
	$query = $PDO->prepare($sql);
	$query->execute();
}

function db_delete($table, $column, $value, $PDO)
{
	$query = $PDO->prepare("DELETE FROM db_camagru.".$table." WHERE ".$column." = ?");
	$query->execute([$value]);
}

function db_table($table, $PDO)
{
	$query = $PDO->prepare("SELECT * FROM db_camagru.".$table);
	$query->execute();
	return ($query->fetchAll());
}

function toggle_notifications($user_id, $PDO)
{
	(db_get("users", "id", $user_id, "alerts", $PDO) ? db_update("users", "id", $user_id, "alerts", 0, $PDO) : db_update("users", "id", $user_id, "alerts", 1, $PDO));
}

function comment_notification($user_id, $post_id, $PDO)
{
	$post_owner = db_get("posts", "id", $post_id, "user_id", $PDO);
	if (db_get("users", "id", $post_owner, "alerts", $PDO)) {
		$message = "<html>
	<head>
		<title>You have a new comment !</title>
		<style>
			body {
				background-color	: #e5e6eb;
				color				: black;
				font-size			: 1em;
				font-family			: 'Roboto', sans-serif;
			}
			#cr-button {
				margin: 0 auto;
				font-size: 1.5rem;
				padding: 1.0rem 2.0rem;
				display: block;
				background-color: #009ac9;
				border: 1px solid transparent;
				color: #ffffff;
				font-weight: 200;
				border-radius: 3px;
			}
			#cr-button:hover {
				background-color: #ffffff;
				color: #009ac9;
				border-color: #009ac9;
			}
		</style>
	</head>
	<center>
	<p>You have a new comment from " . db_get("users", "id", $user_id, "username", $PDO) . " on one of your posts !</p>
	</center>
	</html>";
		$headers[] = 'MIME-Version: 1.0';
		$headers[] = 'Content-type: text/html; charset=iso-8859-1';
		mail(db_get("users", "id", $post_owner, "email", $PDO), "You have a new comment !", $message, implode("\r\n", $headers));
	}
}
?>
