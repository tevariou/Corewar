#!/bin/sh

	if [ -e diff_result_b ]
	then
		rm diff_result_b
	fi
limit=25000
for file in ../champions/compiled_b/*.cor
do
	echo $file
	echo $file >> diff_result_b
	if [ -e diff_trace_b ]
	then
		rm diff_trace_b
	fi
	touch diff_trace_b
	x=1
	while [ `cat diff_trace_b | wc -c` -eq 0 ] && [ $x -lt $limit ]
	do
	{
		./corewar -d $x $file | tail -64 > 01_b
		./../../corewar -dump $x $file | tail -64 > 02_b
		diff 01_b 02_b > diff_trace_b
		x=$((x+100))
	}
	done

	if [ $x -lt $limit ]
	then
	{
		rm diff_trace_b
		touch diff_trace_b
		x=$((x-200))
		while [ `cat diff_trace_b | wc -c` -eq 0 ]
		do
		{
			./corewar -d $x $file | tail -64 > 01_b
			./../../corewar -dump $x $file | tail -64 > 02_b
			diff 01_b 02_b > diff_trace_b
			x=$((x+10))
		}
		done
		echo "Stopped at $x" >> diff_result_b
		diff 01_b 02_b >> diff_result_b
	}
	else
		echo "Seems OK" >> diff_result_b
	fi

	rm 01_b
	rm 02_b
	rm diff_trace_b
done
