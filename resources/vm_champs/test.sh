#!/bin/sh
for f in champs/*.s;
do
	echo $f; ./tev $f
done
