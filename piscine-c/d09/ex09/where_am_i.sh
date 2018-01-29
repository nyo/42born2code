#!/bin/sh

ifconfig | grep 'inet ' | cut -d ' ' -f 2

line=$(ifconfig | grep 'inet ' | cut -d ' ' -f 2)
if [ "${line:-null}" = null ]
then
    printf "Je suis perdu!\n"
fi
