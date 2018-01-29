#!/usr/bin/php
<?php

$res = preg_match("/toto/", "ahtotodasidghsaidatotoahdbaidbasd");
echo $res."\n"; // match "toto"

$res = preg_match_all("/toto/", "ahtotodasidghsaidatotoahdbaidbasd");
echo $res."\n"; // match every occurences of "toto"

$res = preg_match("/^toto/", "totoahtotodasidghsaidatotoahdbaidbasd");
echo $res."\n"; // match "toto" at the beginning of the string

$res = preg_match("/toto$/", "ahtotodasidghsaidatotoahdbaidbasdtoto");
echo $res."\n"; // match "toto" at the end of the string

$res = preg_match_all("/t[oi]t[oi]/", "toto toto titi toto");
echo $res."\n"; // match "toto" or "titi" or "toti" or "tito"

$res = preg_match_all("/t[0-9]t[a-z]/", "toto t0ts titi toto");
echo $res."\n"; // match every words built this way: "t"+"0,1,2,..,9"+"t"+"a,b,c,..,z"

$res = preg_match_all("/t[0-9]+t[a-z]/", "toto t0ts titi toto");
echo $res."\n"; // match every words built this way: "t"+"0,1,2,..,9"+"t"+"a,b,c,..,z"

$res = preg_match_all("/t[0-9]+t[a-z]/", "toto t0ts titi toto");
echo $res."\n"; // "+" character ("[0-9]") found ONE or more times

$res = preg_match_all("/t[0-9]*t[a-z]/", "toto t0ts titi toto");
echo $res."\n"; // "*" character ("[0-9]") found ZERO or more times

$res = preg_match_all("/t[0-9]?t[a-z]/", "toto t0ts titi toto");
echo $res."\n"; // "?" character ("[0-9]") found ZERO or ONE time

$res = preg_match_all("/t[0-9]{4}t[a-z]/", "toto t0000ts titi toto");
echo $res."\n"; // "{4}" character ("[0-9]") found FOUR times

$res = preg_match_all("/t[^0-9]t[a-z]/", "toto t0ts titi toto");
echo $res."\n"; // match every words built this way: "t"+ -TOUT SAUF DES CHIFFRES- +"t"+"a,b,c,..,z"

$res = preg_match_all("/t([oi])t\1/", "toto toto titi toto"); // VERIF DANS LE MAN
echo $res."\n"; // match "toto" or "titi" ONLY, "\1" > "qu'est ce qui a match dans la premiere sequence de pattern"

?>
