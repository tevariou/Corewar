#!/bin/sh
for f in results_p/*;
do
	for f2 in results/*;
	do
		if [ "$(echo $f2 | rev | cut -c5- | rev | cut -c9-)" = "$(echo $f | rev | cut -c5- | rev | cut -c11-)" ]; then	
			diff $f $f2
			break
		fi
	done
done
