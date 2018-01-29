<?php
function fileInit($file_json, $file_data, $file_name)
{
        if (!file_exists($file_data))
        {
                mkdir($file_data);
                echo "<i>fileInit(): created <strong>$file_data</strong>...</i><br>\n";
        }
        $content = file_get_contents($file_json.$file_name);
        file_put_contents($file_data.$file_name, $content, LOCK_EX);
        echo "<i>fileInit(): created & filled <strong>$file_data$file_name</strong>...</i><br>\n";
}

$file_json = "fileJson/";
$file_data = "data/";
$file_names = array("users.json", "products.json", "catego.json", "orders.json");

foreach ($file_names as $k => $v)
        fileInit($file_json, $file_data, $file_names[$k]);
?>
