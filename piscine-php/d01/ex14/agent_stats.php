#!/usr/bin/php
<?php
function get_database()
{
	$db = [];

	while (!feof(STDIN))
	{
		$line = fgets(STDIN);
		if (!empty($line))
		{
			$data = explode(";", $line);
			array_push($db, $data);
		}
	}
	array_shift($db);
	return ($db);
}

function already_exists($arr, $str)
{
	foreach ($arr as $name)
		if ($name === $str)
			return (true);
	return (false);
}

function get_user_list($db)
{
	$user_list = [];

	for ($i = 0; $i < count($db); $i++)
	{
		if (!already_exists($user_list, $db[$i][0]))
			array_push($user_list, $db[$i][0]);
	}
	sort($user_list, SORT_STRING);
	return ($user_list);
}

$db = get_database();

if ($argv[1] === "moyenne")
{
	$grades = 0;
	$total = 0;

	for ($i = 0; $i < count($db); $i++)
	{
		if (!empty($db[$i][1]) && is_numeric($db[$i][1]))
		{
			$total = $total + $db[$i][1];
			$grades++;
		}
	}
	exit(($total / $grades)."\n");
}
else if ($argv[1] === "moyenne_user")
{
	$user_list = get_user_list($db);
	foreach ($user_list as $user_name)
	{
		$user_total = 0;
		$user_grades = 0;
		foreach ($db as $user_data)
		{
			if ($user_data[0] === $user_name)
			{
				if (!empty($user_data[1]))
				{
					$user_total = $user_total + $user_data[1];
					$user_grades++;
				}
			}
		}
		echo $user_name.":".($user_total / $user_grades)."\n";
	}
}
else if ($argv[1] === "ecart_moulinette") // si user a pas de note, on affiche pas
{
	$user_list = get_user_list($db);
	foreach ($user_list as $user_name)
	{
		$user_total_stud = 0;
		$user_total_mlin = 0;
		$user_grades_stud = 0;
		$user_grades_mlin = 0;
		foreach ($db as $user_data)
		{
			if ($user_data[0] === $user_name)
			{
				if (!empty($user_data[1]))
				{
					if ($user_data[2] == "moulinette")
					{
						$user_total_mlin = $user_total_mlin + $user_data[1];
						$user_grades_mlin++;
					}
					else
					{
						$user_total_stud = $user_total_stud + $user_data[1];
						$user_grades_stud++;
					}
				}
			}
		}
		echo $user_name.":".(($user_total_stud / $user_grades_stud) - ($user_total_mlin / $user_grades_mlin))."\n";
	}
}
?>
