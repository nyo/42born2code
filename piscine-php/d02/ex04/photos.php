#!/usr/bin/php
<?php

function get_html($url)
{
	$ch = curl_init($url);
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
	if (($html = curl_exec($ch)) === false)
		exit(curl_error($ch)."\n");
	curl_close($ch);
	return ($html);
}

function get_imgs($html, $url)
{
	$ret = [];
	preg_match_all("/<img[^>]+src=([^\s>]+)/i", $html, $matches);
	foreach ($matches[0] as $match)
	{
		preg_match("/src=\"(.*)\"/i", $match, $arr);
		$target = $arr[1];
		if (!preg_match("/^http(s?):\/\//", $target))
			if (preg_match("/^\//", $target))
				$target = $url.$target;
		array_push($ret, $target);
	}
	return ($ret);
}

function get_name($img_url)
{
	$file_parts = pathinfo($img_url);
	return ($file_parts['basename']);
}

function dir_create($url)
{
	$dirname = preg_replace("/^.*:\/\//", "", $url);
	if (!file_exists($dirname))
		mkdir($dirname);
	return ($dirname);
}

function img_dl($imgs_url, $dirname)
{
	foreach ($imgs_url as $img_url)
	{
		$target = $dirname."/".get_name($img_url);
		$ch = curl_init($img_url);
		$fp = fopen($target, "wb");
		curl_setopt($ch, CURLOPT_FILE, $fp);
		curl_setopt($ch, CURLOPT_HEADER, false);
		if (curl_exec($ch) === false)
			exit(curl_error($ch)."\n");
		curl_close($ch);
		fclose($fp);
	}
}

if ($argc < 2)
	exit();

$url = $argv[1];
$html = get_html($url);
$imgs_url = get_imgs($html, $url);
$dirname = dir_create($url);
img_dl($imgs_url, $dirname);

?>
