<?php
include_once("../utils/db.php");
if(!isset($_SESSION)) {
	session_start();
}
if (!isset($_SESSION["id"])) {
	include_once("redirect.php");
	die();
}
if (isset($_POST["deletepost"]) && (db_get("posts", "id", $_POST["deletepost"], "user_id", $PDO) === $_SESSION["id"])) {
	db_delete("posts", "id", $_POST["deletepost"], $PDO);
	$_SESSION["status"]	= true;
	$_SESSION["message"] = "Your post has been deleted.";
	header("Location: ".$url."upload.php");
	die();
}
if (isset($_POST["submit"]) && preg_match("/data:image\/png;base64,/", $_POST["snapshot"])) {
	
	$data = str_replace("data:image/png;base64,", "", $_POST["snapshot"]);
	$data = str_replace(" ", "+", $data);
	$dst = base64_decode($data);

	$filename = "imgs/" . mktime() . ".png";
	if ($_POST["filter"]) {
		$dst = imagecreatefromstring($dst);
		imagealphablending($dst, true);
		imagesavealpha($dst, true);
		$src = imagecreatefrompng(__DIR__ . "/" . $_POST["filter"]);
		imagecopyresized($dst, $src, 0, 0, 0, 0, 500, 500, imagesx($src), imagesy($src));
		imagedestroy($src);
		imagepng($dst, $filename);
		imagedestroy($dst);
	} else {
		file_put_contents($filename, $dst);
	}

	db_add("posts", array("user_id" => $_SESSION["id"], "img_url" => $url . $filename), $PDO);
	$_SESSION["status"] = true;
	$_SESSION["message"] = "Your picture has been posted.";
	header("Location: ".$url."index.php");
	die();
}
?>
<!doctype html>
<html>
	<?php include_once("./static/head.php"); ?>
	<?php include_once("./static/header.php"); ?>
	<script src="js/upload.js"></script>
	<div id="cr-main">
		<div id="cr-upload-page">
			<h3>choose a picture</h3>
			<div id="cr-upload-box">
				<div id="cr-preview-box">
					<div id="cr-filters-left">
						<?php
						$filters = db_table("filters", $PDO);
						foreach ($filters as $filter) {
							if ($filter["id"] < 4) {
								echo "<img src=\"".$filter["img_url"]."\" class=\"cr-filters-handler\">\n";
							}
						}
						?>
					</div>
					<div id="cr-webcam">
						<video id="cr-webcam-source" width="666" height="500" autoplay>
						<!-- <video id="cr-webcam-source" width="500" height="375" autoplay> -->
							Your browser does not support the video tag.
						</video>
					</div>
					<canvas width="500" height="500" id="cr-filters"></canvas>
					<canvas width="500" height="500" id="cr-canvas"></canvas>
					<div id="cr-filters-right">
						<?php
						$filters = db_table("filters", $PDO);
						foreach ($filters as $filter) {
							if ($filter["id"] > 3) {
								echo "<img src=\"".$filter["img_url"]."\" class=\"cr-filters-handler\">\n";
							}
						}
						?>
					</div>
				</div>
				<div id="cr-upload-method">
					<input id="cr-from-webcam" type="button" disabled="true" value="from webcam"></input>
					<input id="cr-reset-filter" type="button" disabled="true" value="reset filter"></input>
					<input id="cr-from-computer" type="file" accept="image/*"></input>
				</div>
			</div>
			<h3>then</h3>
			<form action="#" method="post" accept-charset="utf-8" id="cr-submit-box">
				<input name="snapshot" type="hidden" id="cr-snapshot"></input>
				<input name="filter" type="hidden" id="cr-filter-url"></input>
				<input name="submit" type="submit" disabled="true" value="submit image" id="cr-submit-button"></input>
			</form>
			<h3>gallery</h3>
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
					echo "			<button type=\"submit\" id=\"cr-delete-button\">DELETE</button>\n";
					echo "		</form>\n";
					echo "	</div>\n";
					echo "</tr>\n";
				}
			}
			?>
			</table>
			</div></center>
		</div>
	</div>
	<?php include_once("./static/footer.php"); ?>
	<?php 
	if (isset($_SESSION["status"])) {
		echo '<script>printMessage("' . $_SESSION["message"] . '", "' . ($_SESSION["status"] == true ? "#47d147" : "#ff6666") . '");</script>';	
		$_SESSION["status"] = null;
		$_SESSION["message"] = null;
	} ?>
</html>
