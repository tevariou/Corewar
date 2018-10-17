#!/bin/sh

	if [ -e unitests_result ]
	then
		rm unitests_result
	fi

for file in ../champions/unitests/*.cor
do
	echo $file
	echo $file >> unitests_result
	if [ -e diff_result ]
	then
		rm diff_result
	fi
	touch diff_result
	./corewar -d 1500 $file | tail -64 > 01
	./../../corewar -dump 1500 $file | tail -64 > 02
	diff 01 02 
	rm 01
	rm 02
done
