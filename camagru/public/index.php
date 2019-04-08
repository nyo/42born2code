<?php
require_once("../utils/db.php");
if(!isset($_SESSION)) {
	session_start();
}
if (isset($_POST["new_comment"]) && isset($_POST["post_id"])) {
	if (isset($_SESSION["id"]))
	{
		if ($_POST["new_comment"] === "")
		{
			$_SESSION["status"] = false;
			$_SESSION["message"] = "You cannot post an empty comment.";
			header("Location: ".$url."index.php");
			die();
		}
		else
		{
			db_add("comments", array("post_id" => $_POST["post_id"], "user_id" => $_SESSION["id"], "comment" => filter_var($_POST["new_comment"], FILTER_SANITIZE_STRING)), $PDO);
			$_SESSION["status"] = true;
			$_SESSION["message"] = "Your comment has been posted.";
			comment_notification($_SESSION["id"], $_POST["post_id"], $PDO);
			header("Location: ".$url."index.php");
			die();
		}
	}
	else
	{
		$_SESSION["status"] = false;
		$_SESSION["message"] = "Please login before trying to comment.";
		header("Location: ".$url."index.php");
		die();
	}
}
if (isset($_POST["post_id"]) && $_POST["like"] === "OK") {
	$_SESSION["status"] = true;
	$_SESSION["message"] = "Like succesfully added.";
	if (!isset($_SESSION["id"])) {
		$_SESSION["status"] = false;
		$_SESSION["message"] = "You need to login to like a post.";
		header("Location: ".$url."index.php");
		die();
	}
	$likes = db_table("likes", $PDO);
	foreach($likes as $like)
	{
		if ($like["post_id"] === $_POST["post_id"] && $like["user_id"] === $_SESSION["id"]) {
			header("Location: ".$url."index.php");
			die();
		}
	}
	db_add("likes", array("post_id" => $_POST["post_id"], "user_id" => $_SESSION["id"]), $PDO);
	header("Location: ".$url."index.php");
	die();
}
?>
<!doctype html>
<html>
	<?php include_once("./static/head.php"); ?>
	<?php include_once("./static/header.php"); ?>
	<div id="cr-main">
		<div id="cr-feed">
			<a href="upload.php" id="cr-upload-link"></a>
			<?php
			include_once("../utils/db.php");
			$posts = array_reverse(db_table("posts", $PDO));
			if (count($posts) === 0) {
				echo "oh non! il n'y a rien ici... :-(";
			}
			foreach ($posts as $post) {
				$img_src = $post["img_url"];
				$owner = db_get("users", "id", $post["user_id"], "username", $PDO);
				$date = $post["creation_date"];
				$likes = db_get("likes", "post_id", $post["id"], null, $PDO);
				$nb_likes = count($likes);
				$comments = db_get("comments", "post_id", $post["id"], null, $PDO);	
			?>
				<div class="cr-post">
				<div id="cr-post-like">
					<form action="#" method="post">
						<input type="hidden" name="post_id" value="<?= $post["id"] ?>">
					    <button type="submit" name="like" value="OK"><i class="fas fa-heart"></i> | <?= $nb_likes ?> likes</button>
					</form>	
				</div>
				<img src="<?= $img_src ?>"></img>
				<div class="cr-post-data">
					<div class="cr-post-owner">
					<?= $owner ?> | <span> <?= $date ?></span>
					</div>
					<div class="cr-post-comments" name="<?= $post["id"] ?>">
				<?php
				foreach ($comments as $comment) {
					$user = db_get("users", "id", $comment["user_id"], "username", $PDO);
					echo '<p><b>'.$user.'</b> '.$comment["comment"].'</p><hr>';
				}
				?></div>
					<div class="cr-post-comment">
						<form method="post" action="#">
						<input type="hidden" name="post_id" value="<?= $post["id"] ?>">
							<input type="text" name="new_comment" placeholder="comment...">
							<button type="submit"><i class="fas fa-comment"></i></button>
						</form>
					</div>
				</div>
				</div>
				<?php } ?>
		</div>
	</div>
	<?php include_once("./static/footer.php"); ?>
	<?php
	if (isset($_SESSION["status"])) {
		echo '<script>printMessage("' . $_SESSION["message"] . '", "' . ($_SESSION["status"] == true ? "#47d147" : "#ff6666") . '");</script>';	
		$_SESSION["status"] = null;
		$_SESSION["message"] = null;
	}
	?>
	<script>
		var messages = [
			"make a new post today!",
			"feel like sharing a moment?",
			"upload a pic and get more followers!"
		];
		var rn = Math.floor(Math.random() * messages.length);
		document.getElementById("cr-upload-link").innerHTML = messages[rn];
		// https://www.sitepoint.com/community/t/retain-scroll-position-on-page-reload/8230/5
	</script>
</html>
