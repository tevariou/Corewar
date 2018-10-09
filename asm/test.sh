#!/bin/sh
for f in ../resources/vm_champs/champs/*.s;
do
	echo $f; ./asm $f
done
