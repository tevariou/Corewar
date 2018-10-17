#!/bin/sh

	if [ -e diff_result_d ]
	then
		rm diff_result_d
	fi
limit=25000
for file in ../champions/compiled_d/*.cor
do
	echo $file
	echo $file >> diff_result_d
	if [ -e diff_trace_d ]
	then
		rm diff_trace_d
	fi
	touch diff_trace_d
	x=1
	while [ `cat diff_trace_d | wc -c` -eq 0 ] && [ $x -lt $limit ]
	do
	{
		./corewar -d $x $file | tail -64 > 01_d
		./../../vm/corewar -d $x $file | tail -64 > 02_d
		diff 01_d 02_d > diff_trace_d
		x=$((x+100))
	}
	done

	if [ $x -lt $limit ]
	then
	{
		rm diff_trace_d
		touch diff_trace_d
		x=$((x-200))
		while [ `cat diff_trace_d | wc -c` -eq 0 ]
		do
		{
			./corewar -d $x $file | tail -64 > 01_d
			./../../vm/corewar -d $x $file | tail -64 > 02_d
			diff 01_d 02_d > diff_trace_d
			x=$((x+10))
		}
		done
		echo "Stopped at $x" >> diff_result_d
		diff 01_d 02_d >> diff_result_d
	}
	else
		echo "Seems OK" >> diff_result_d
	fi

	rm 01_d
	rm 02_d
	rm diff_trace_d
done