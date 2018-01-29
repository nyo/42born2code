#!/usr/bin/php
<?php

// http://php.net/manual/en/book.curl.php

$handler = curl_init("http://www.42.fr");
$str = curl_exec($handler);
echo $str;

?>
