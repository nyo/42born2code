#!/bin/sh

[ $# -eq 0 ] && { echo "Usage: sh $0 [FILES ...]"; exit 1; }

LOGIN=anyo

grep -R -r -H "By:" $@ | grep -v $LOGIN
grep -R -r -H "Created:" $@ | grep -v $LOGIN
grep -R -r -H "Updated:" $@ | grep -v $LOGIN
