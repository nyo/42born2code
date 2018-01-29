#!/bin/sh

cat $1 | grep -i 'bomber' | grep -i 'nicolas' | grep '-' | grep -v 'nicolasbomber' | grep -v 'bombernicolas' | cut -f 3
