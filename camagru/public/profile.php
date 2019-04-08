<!doctype html>
<html>
	<?php include_once("../utils/db.php"); ?>
	<?php include_once("./static/head.php"); ?>
	<?php include_once("./static/header.php"); ?>
	<div id="cr-main">
		<center><p id="cr-profile-title">- user data -</p></center>
		<div id="cr-profile">
			<div id="cr-user-data">
				<img src="imgs/profile.png">
				<table>
				<tr><td>username</td><td align="right"><?php echo db_get('users', 'id', $_SESSION['id'], 'username', $PDO); ?></td></tr>
					<tr><td>e-mail</td><td align="right"><?php echo db_get('users', 'id', $_SESSION['id'], 'email', $PDO); ?></td></tr>
					<tr><td>receive notifications</td><td align="right"><input type="checkbox" id="cr-notif" <?php if (db_get("users", "id", $_SESSION["id"], "alerts", $PDO)) { echo "checked"; } else { echo ""; } ?> ></td></tr>
				</table>
			</div>
		</div>
		<center><p id="cr-settings-title">- settings -</p></center>
		<div id="cr-settings">
			<div class="cr-setting">
				<center>
				<form method="post" action="#">
					<p>username</p>
					<input type="hidden" name="change" value="username">
					<input type="text" name="new" placeholder="NEW" required>
					<input type="password" name="password" placeholder="PASSWORD" required>
					<button type="submit">SAVE</button>
				</form>
				</center>
			</div>
			<div class="cr-setting">
				<center>
				<form method="post" action="#">
					<p>password</p>
					<input type="hidden" name="change" value="password">
					<input type="password" name="current" placeholder="CURRENT" required>
					<input type="password" name="new" placeholder="NEW" required>
					<input type="password" name="confirm" placeholder="CONFIRM NEW" required>
					<button type="submit">SAVE</button>
				</form>
				</center>
			</div>
			<div class="cr-setting">
				<center>
				<form method="post" action="#">
					<p>e-mail</p>
					<input type="hidden" name="change" value="email">
					<input type="text" name="new" placeholder="NEW" required>
					<input type="password" name="password" placeholder="PASSWORD" required>
					<button type="submit">SAVE</button>
				</form>
				</center>
			</div>
		</div>
		<center><p id="cr-settings-title">- gallery -</p></center>
		<center><div id="cr-upload-gallery">
			<table>
			<?php
			$posts = array_reverse(db_table("posts", $PDO));
			foreach($posts as $post) {
				if ($post["user_id"] === $_SESSION["id"]) {
					echo "<tr>\n";
					echo "	<div id=\"cr-gallery-post\">\n";
					echo "		<img src=\"" . $post["img_url"] . "\" width=\"250\" height=\"250\">\n";
					echo "		<form method=\"post\" action=\"#\">\n";
					echo "			<input type=\"hidden\" name=\"deletepost\" value=\"" . $post["id"] . "\">\n";
					echo "			<button type=\"submit\" class=\"cr-delete-button\">DELETE</button>\n";
					echo "		</form>\n";
					echo "	</div>\n";
					echo "</tr>\n";
				}
			}
			?>
			</table>
		</div></center>
	</div>
	<?php include_once("./static/footer.php"); ?>
	<script>
			var checkbox = document.getElementById("cr-notif");
			checkbox.onclick = function () {
				$.ajax({
					url: 'ajax.php',
					type: 'post',
					data: {'user_id' : <?= $_SESSION["id"] ?> }
				});
			}
	</script>
	<?php
	#interacting with db
	if (!isset($_SESSION["id"])) {
		include_once("redirect.php");
		die();
	}
	else if (isset($_SESSION["status"])) {
		echo '<script>printMessage("' . $_SESSION["message"] . '", "' . ($_SESSION["status"] == true ? "#47d147" : "#ff6666") . '");</script>';	
		$_SESSION["status"] = null;
		$_SESSION["message"] = null;
	}
	if (isset($_POST["deletepost"]) && (db_get("posts", "id", $_POST["deletepost"], "user_id", $PDO) === $_SESSION["id"])) {
		db_delete("posts", "id", $_POST["deletepost"], $PDO);
		$_SESSION["status"]	= true;
		$_SESSION["message"] = "Your post has been deleted.";
		header("Location: " . $url . "profile.php");
		die();
	}
	if (isset($_POST["change"]) && $_POST["change"] === "password") {
		if (isset($_POST["current"]) && isset($_POST["new"]) && isset($_POST["confirm"])) {
			if ($_POST["new"] === $_POST["confirm"] &&
			hash('whirlpool', $_POST["current"]) === db_get("users", "id", $_SESSION["id"], "password", $PDO)) {
				db_update('users', 'id', $_SESSION["id"], "password", hash('whirlpool', $_POST["new"]), $PDO);
				$_SESSION["status"] = true;
				$_SESSION["message"] = "Your password has been changed.";
			}
			else {
				$_SESSION["status"] = false;
				$_SESSION["message"] = "Incorrect password.";
			}
		}
		header("Location: " . $url . "profile.php");
		die();
	}
	if (isset($_POST["change"]) && $_POST["change"] === "username") {
		if (isset($_POST["new"]) && isset($_POST["password"])) {
			$_SESSION["status"] = true;
			$_SESSION["message"] = "Your username has been changed.";
			if (db_check("users", "username", $_POST["new"], $PDO)) {
				$_SESSION["status"] = false;
				$_SESSION["message"] = "Username already exists.";
			}
			else if (!db_check("users", "username", $_POST["new"], $PDO) && (hash('whirlpool', $_POST["password"]) !== db_get('users', 'id', $_SESSION["id"], 'password', $PDO))) {
				$_SESSION["status"] = false;
				$_SESSION["message"] = "Incorrect password.";
			}
			else if (!db_check("users", "username", $_POST["new"], $PDO) && (hash('whirlpool', $_POST["password"]) === db_get('users', 'id', $_SESSION["id"], 'password', $PDO))){
				db_update('users', 'id', $_SESSION["id"], "username", $_POST["new"], $PDO);
			}
		}
		header("Location: " . $url . "profile.php");
		die();
	}
	if (isset($_POST["change"]) && $_POST["change"] === "email") {
		if (isset($_POST["new"]) && isset($_POST["password"])) {
			$_SESSION["status"] = true;
			$_SESSION["message"] = "Your email has been changed.";
			if (db_check("users", "email", $_POST["new"], $PDO)) {
				$_SESSION["status"] = false;
				$_SESSION["message"] = "Email already in use.";
			}
			else if (!db_check("users", "email", $_POST["new"], $PDO) && (hash('whirlpool', $_POST["password"]) !== db_get('users', 'id', $_SESSION["id"], 'password', $PDO))) {
				$_SESSION["status"] = false;
				$_SESSION["message"] = "Incorrect password.";
			}
			else if (!db_check("users", "email", $_POST["new"], $PDO) && (hash('whirlpool', $_POST["password"]) === db_get('users', 'id', $_SESSION["id"], 'password', $PDO))){
				db_update('users', 'id', $_SESSION["id"], "email", $_POST["new"], $PDO);
			}
		}
		header("Location: " . $url . "profile.php");
		die();
	}
	?>
</html>
