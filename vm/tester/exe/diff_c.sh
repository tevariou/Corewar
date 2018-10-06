#!/bin/sh

	if [ -e diff_result_c ]
	then
		rm diff_result_c
	fi
limit=25000
for file in ../champions/compiled_c/*.cor
do
	echo $file
	echo $file >> diff_result_c
	if [ -e diff_trace_c ]
	then
		rm diff_trace_c
	fi
	touch diff_trace_c
	x=1
	while [ `cat diff_trace_c | wc -c` -eq 0 ] && [ $x -lt $limit ]
	do
	{
		./corewar -d $x $file | tail -64 > 01_c
		./../../corewar -dump $x $file | tail -64 > 02_c
		diff 01_c 02_c > diff_trace_c
		x=$((x+100))
	}
	done

	if [ $x -lt $limit ]
	then
	{
		rm diff_trace_c
		touch diff_trace_c
		x=$((x-200))
		while [ `cat diff_trace_c | wc -c` -eq 0 ]
		do
		{
			./corewar -d $x $file | tail -64 > 01_c
			./../../corewar -dump $x $file | tail -64 > 02_c
			diff 01_c 02_c > diff_trace_c
			x=$((x+10))
		}
		done
		echo "Stopped at $x" >> diff_result_c
		diff 01_c 02_c >> diff_result_c
	}
	else
		echo "Seems OK" >> diff_result_c
	fi

	rm 01_c
	rm 02_c
	diff_trace_c
done