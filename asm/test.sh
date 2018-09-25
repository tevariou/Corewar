#!/bin/sh
for f in ../resources/vm_champs/champs/championships/*/*/*.s;
do
	echo $f; ./asm $f
done
