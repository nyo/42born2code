#!/bin/sh

[ $# -eq 0 ] && { echo "Usage: sh $0 [FILES ...]"; exit 1; }

LOGIN=xxxxxxx

sed -i -e "s/$LOGIN/anyo   /g" $@
sed -i -e "s/anyo    <marvin@42.fr>/anyo <marvin@42.fr>   /g" $@
