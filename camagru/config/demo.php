<?php

include_once("../utils/db.php");

try {
	
	# creation des users
	$usernames = array(
		"ibuprofenlollies",
		"jessclam",
		"pagingbasmati",
		"daintyeggs",
		"shortagesalami",
		"modcoconut",
		"figaropolenta",
		"spiltapricots",
		"grillsalt",
		"traintacos"
	);
	foreach ($usernames as $username) {
		db_add("users", array("username" => $username, "password" => hash("whirlpool", "123"), "email" => $username."@camag.ru", "verified" => TRUE, "alerts" => TRUE, "admin" => 0), $PDO);
	}
	echo "[+] Created ".count($usernames)." fake users.\n";

	# creation des posts
	for ($i = 0; $i < 10; $i++) {
		db_add("posts", array("user_id" => rand(1, 10 + 1), "img_url" => $url . "imgs/default-".$i.".png"), $PDO);
		if ($i === 10)
			$i = 0;
	}
	echo "[+] Created fake posts.\n";

	# creation des commentaires
	$comment = "TEST_";
	for ($i = 1; $i <= 10 + 1; $i++) {
		for ($j = 1; $j <= 10 + 1; $j++) {
			db_add("comments", array("post_id" => $j, "user_id" => $i, "comment" => $comment.$i.$j), $PDO);
		}
	}
	echo "[+] Created fake comments.\n";

	# creation des likes
	for ($i = 2; $i < 10 + 10; $i++) {
		for ($j = 1; $j <= 10 + 10; $j++) {
			db_add("likes", array("post_id" => $j, "user_id" => $i), $PDO);
		}
	}
	echo "[+] Created fake likes.\n";

} catch (\PDOException $e) {

	echo "[!] Error while creating fake data.\n";
	throw new \PDOException($e->getMessage(), (int)$e->getCode());

}

?>
