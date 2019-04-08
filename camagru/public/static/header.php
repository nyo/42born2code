<?php
if(!isset($_SESSION)) {
	session_start();
}
$logged = '<body>
	<div id="cr-header">
		<a href="index.php">
			<div id="cr-logo">
					<img src="./imgs/logo.png">
					<h3>CAMAG.RU</h3>
			</div>
		</a>
		<div id="cr-buttons">
			<div class="cr-button"><a href="profile.php"><span>profile</span></a></div>
			<div class="cr-button"><a href="signout.php"><span>sign-out</span></a></div>
		</div>
	</div>';
$unlogged = '<body>
	<div id="cr-header">
		<a href="index.php">
			<div id="cr-logo">
					<img src="./imgs/logo.png">
					<h3>CAMAG.RU</h3>
			</div>
		</a>
		<div id="cr-buttons">
			<div class="cr-button"><a href="signin.php"><span>sign-in</span></a></div>
			<div class="cr-button"><a href="signup.php"><span>sign-up</span></a></div>
		</div>
	</div>';
if (isset($_SESSION["id"]))
	echo $logged;
else
	echo $unlogged;
?>
