<?php include_once("./static/head.php")?>
<?php include_once("./static/header.php")?>
	<div id="cr-main">
		<br/> <br/> <br/> <br/> <br/> <br/> <br/>
		<div id="cr-sign-form">
			<span>YOU NEED TO BE LOGGED IN ORDER TO ACCESS THIS PAGE</span>
			<div id="cr-redirect">REDIRECTING</div>
		</div>
	</div>
<script type="text/javascript">
	var i = 0;
	var span = document.getElementById("cr-redirect");
	setInterval(function() {
		  i = ++i % 4;
		   span.innerHTML = "REDIRECTING " + Array(i + 1).join(".");
	}, 800);
	setTimeout(function redirect() { window.location = "<?= $url . "index.php"?>"; }, 3000);
</script>
<?php include_once("./static/footer.php")?>
