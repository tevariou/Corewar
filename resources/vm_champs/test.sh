#!/bin/sh
for f in champs/*.s;
do
	echo $f; ./asm $f
done
