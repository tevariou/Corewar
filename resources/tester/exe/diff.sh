#!/bin/sh

	if [ -e diff_trace ]
	then
		rm diff_trace
	fi
limit=25000
for file in ../champions/compiled/*.cor
do
	echo $file
	echo $file >> diff_trace
	if [ -e diff_result ]
	then
		rm diff_result
	fi
	touch diff_result
	x=1
	while [ `cat diff_result | wc -c` -eq 0 ] && [ $x -lt $limit ]
	do
	{
		./corewar -d $x $file | tail -64 > 01
		./../../corewar -dump $x $file | tail -64 > 02
		diff 01 02 > diff_result
		x=$((x+100))
	}
	done

	if [ $x -lt $limit ]
	then
	{
		rm diff_result
		touch diff_result
		x=$((x-200))
		while [ `cat diff_result | wc -c` -eq 0 ]
		do
		{
			./corewar -d $x $file | tail -64 > 01
			./../../corewar -dump $x $file | tail -64 > 02
			diff 01 02 > diff_result
			x=$((x+10))
		}
		done
		echo "Stopped at $x" >> diff_trace
		diff 01 02 >> diff_trace
	}
	else
		echo "Seems OK" >> diff_trace
	fi

	rm 01
	rm 02
	rm diff_trace
done
