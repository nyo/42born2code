<?php
session_start();

/*
**	admin.php is the admin page.
**	If the currently logged user is an administrator, the page content is displayed,
**	else, an error message is printed.
*/

if ($_SESSION["logged_on_user"] === "admin")
{
?>
<html>
<head>
	<meta charset="utf-8">
	<title>ft_minishop</title>
</head>
<body>
	<?php
	include("menu.php");
	displayMenu();
	?>
</body>
</html>
<?php
	echo "espace admin\n";
}
else
	echo "impossible de visualiser cette page\n";
?>
