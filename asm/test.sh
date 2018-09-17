#!/bin/sh
for f in ../resources/vm_champs/champs/*.s;
do
	./asm $f; echo "\n"
done
