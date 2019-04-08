<?php
require_once("../utils/db.php");
if (isset($_POST["user_id"]))
	toggle_notifications($_POST["user_id"], $PDO);
die();
?>
