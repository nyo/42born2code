<?php
function ft_is_sort($arr1)
{
	$arr2 = $arr1;

	sort($arr2);
	for ($i = 0; $i < count($arr1); $i++)
		if ($arr1[$i] !== $arr2[$i])
			return (false);
	return (true);
}
?>
