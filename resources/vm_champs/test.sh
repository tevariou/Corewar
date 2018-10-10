#!/bin/sh
for f in champs/*.s;
do
	echo $f; ./zaz $f
done
