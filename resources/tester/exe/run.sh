#!/bin/bash

if [ -e trace ]
then
	rm trace
fi

for file in ../testingdir/*
do
	echo "Run ./corewar $1 $file"
	echo "\nFile: $file (mine)" >> trace
	./../../vm/corewar $1 $file >> trace 2>&1
done
