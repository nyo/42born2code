#!/bin/sh

CURTIME=`stat -s bomb.txt | cut -d ' ' -f 10 | cut -c 10-20`
NEWTIME=$(( CURTIME - 1 ))
echo $NEWTIME
