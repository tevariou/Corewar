#!/bin/sh

	if [ -e diff_result_a ]
	then
		rm diff_result_a
	fi
limit=25000
for file in ../champions/compiled_a/*.cor
do
	echo $file
	echo $file >> diff_result_a
	if [ -e diff_trace_a ]
	then
		rm diff_trace_a
	fi
	touch diff_trace_a
	x=1
	while [ `cat diff_trace_a | wc -c` -eq 0 ] && [ $x -lt $limit ]
	do
	{
		./corewar -d $x $file | tail -64 > 01_a
		./../../corewar -dump $x $file | tail -64 > 02_a
		diff 01_a 02_a > diff_trace_a
		x=$((x+100))
	}
	done

	if [ $x -lt $limit ]
	then
	{
		rm diff_trace_a
		touch diff_trace_a
		x=$((x-200))
		while [ `cat diff_trace_a | wc -c` -eq 0 ]
		do
		{
			./corewar -d $x $file | tail -64 > 01_a
			./../../corewar -dump $x $file | tail -64 > 02_a
			diff 01_a 02_a > diff_trace_a
			x=$((x+10))
		}
		done
		echo "Stopped at $x" >> diff_result_a
		diff 01_a 02_a >> diff_result_a
	}
	else
		echo "Seems OK" >> diff_result_a
	fi

	rm 01_a
	rm 02_a
	rm diff_trace_a
done
