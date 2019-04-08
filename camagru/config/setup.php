<?php

require_once("database.php");
require_once("../utils/db.php");

try {

	$PDO = new PDO($DB_DSN, $DB_USER, $DB_PASS, [ PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION ]);
	echo "[+] Successfully connected to MySQL.\n";

	$PDO->exec("DROP DATABASE IF EXISTS db_camagru; CREATE DATABASE IF NOT EXISTS db_camagru;");
	echo "[+] Created database 'db_camagru'.\n";

	$table_users	=	"id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
						creation_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
						username TEXT,
						password TEXT,
						email TEXT,
						verified BOOLEAN NOT NULL DEFAULT FALSE,
						alerts BOOLEAN NOT NULL DEFAULT TRUE,
						admin BOOLEAN NOT NULL DEFAULT FALSE,
						token TEXT";
	$table_posts	=	"id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
						user_id INT NOT NULL,
						creation_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
						img_url TEXT";
	$table_comments =	"creation_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
						post_id INT NOT NULL,
						user_id INT NOT NULL,
						comment TEXT";
	$table_likes 	= 	"post_id INT NOT NULL,
						user_id INT NOT NULL";

	$table_filters	=	"id INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
						img_url TEXT";

	$PDO->exec("CREATE TABLE IF NOT EXISTS db_camagru.users ($table_users)");
	$PDO->exec("CREATE TABLE IF NOT EXISTS db_camagru.posts ($table_posts)");
	$PDO->exec("CREATE TABLE IF NOT EXISTS db_camagru.comments ($table_comments)");
	$PDO->exec("CREATE TABLE IF NOT EXISTS db_camagru.likes ($table_likes)");
	$PDO->exec("CREATE TABLE IF NOT EXISTS db_camagru.filters ($table_filters)");
	echo "[+] Created all tables in 'db_camagru'.\n";

	db_add("users", array(	"username"	=> $ADMIN_NAME,
							"password"	=> hash("whirlpool", $ADMIN_PASS),
							"email"		=> $ADMIN_MAIL,
							"verified"	=> TRUE,
							"alerts" 	=> TRUE,
							"admin"		=> TRUE), $PDO);
	echo "[+] Created admin user in 'db_camagru'.\n";
	
	for ($i = 0; $i < 6; $i++) {
		db_add("filters", array("img_url" => $url . "imgs/filters-".$i.".png"), $PDO);
	}
	echo "[+] Created filters in 'db_camagru'.\n";

} catch (\PDOException $e) {
	
	echo "connection failed...\n";
	throw new \PDOException($e->getMessage(), (int)$e->getCode());

}

?>
