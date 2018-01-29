<!-- Modification de category -->

<!DOCTYPE html>
<html>
<head>
	<title>42: ft_minishop</title>
	<link rel="icon" type="image/png" href="/wp-content/uploads/fbrfg/favicon-16x16.png" sizes="16x16">
	<link rel="stylesheet" type="text/css" href="style.css"/>
	<meta charset="utf-8">
</head>
<body>
	<!-- HEADER -->
	<?php
		$root = getcwd();
		require_once($root.'/menu/menu.php');
		require_once($root.'/redirect.php');
	  	require_once($root.'/check_create.php');
	  	menuAdm();
	?>
	<!-- MAIN CONTENT -->
	<article>
	<?php

	$group = file_get_contents('data/catego.json');
	$group = json_decode($group, true);
	foreach ($group as $g)
	{
		if ($g['Cname'] === $_POST['Cname'])
		{
echo'	<div id="forme">
		<div id="dep">
			<form action="modg.php" method="post">';
echo "			<input type='text' name='Cname' value='{$g[Cname]}' placeholder='category'>";
echo "			<input type='text' name='newCname' value='' placeholder='new category'>";

echo'			<input type="checkbox" name="Validate">validate changes</input>
				<input type="checkbox" name="Supress">delete the category</input>
				<input type="submit" name="submit" value="OK"/>
			</form>
		</div>
	</div>';
	}
}
	?>
<?php

if ($_POST['Validate'] === "on")
{
	if (!empty($_POST['newCname']))
	{	
		$prod = file_get_contents('data/products.json');
		$prod = json_decode($prod, true);
		foreach ($prod as $k => $v)
		{
			$ret = explode(":", $prod[$k]["catego"]);
			foreach ($ret as $a => $b)
			{
				if ($ret[$a] === strtolower($_POST["Cname"]))
				{
					unset($ret[$a]);
					array_push($ret, $_POST["newCname"]);
					$prod[$k]["catego"] = implode(":", $ret);
				}
			}
		}
		$prod = json_encode($prod);
		file_put_contents('data/products.json', $prod, LOCK_EX);
	
		$group = file_get_contents('data/catego.json');
		$group = json_decode($group, true);
		
		foreach ($group as $g => $value)
		{
			if($group[$g]['Cname'] === strtolower($_POST['Cname']))
			{
				if ($_POST['newCname'] !== NULL)
				{
						$group[$g]['Cname'] = $_POST['newCname'];
				}
			}
		}
		$group = json_encode($group);
		file_put_contents('data/catego.json', $group, LOCK_EX);
	}
	redirect('mod_catego.php');
}

if ($_POST['Supress'] === "on")
{

$group = file_get_contents('data/catego.json');
$group = json_decode($group, true);

foreach ($group as $p => $value)
	{
		echo "<br>".$p."<br>";

		if($group[$p]['Cname'] === $_POST['Cname'])
		{
			unset($group[$p]);
		}

	$catego = json_encode($group);
	file_put_contents('data/catego.json', $catego, LOCK_EX);
	redirect('mod_catego.php');
}
}
?>
	</article>
	<!-- FOOTER -->
	<footer>
		<div class="copyright">
			<p>copyright © 2017 ft_minishop</p>
		</div>
	</footer>
</body>
</html>
