<html>
<head>
	<meta charset="utf-8">
	<title>ft_minishop</title>
</head>
<body>
	<?php
	include("menu.php");
	include("api.php");
	
	displayMenu();
	function checkRequest()
	{
		if (isset($_POST["submit"]) && $_POST["submit"] === "OK"
			&& isset($_POST["catego"]) && !empty($_POST["catego"]))
			return (true);
		else
			return (false);
	}
	
	if (checkRequest() === true)
	{
		$db = getDbContent("products");
		foreach ($db["products"] as $k => $v)
			if (key($v) === $_POST["catego"])
				foreach ($v as $ps)
					foreach ($ps as $p)
						echo $p."<br>";
	}
	?>
</body>
</html>
