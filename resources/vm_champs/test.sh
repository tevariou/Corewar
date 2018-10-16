#!/bin/sh

cor=".cor"
dir="champs"

for f in $dir/*.s
do
	./zaz $f &>/dev/null
	if [ -f "$(echo $f | rev | cut -c3- | rev)$cor" ]
	then
		hexdump -C $(echo $f | rev | cut -c3- | rev)$cor > $dir/zaz
		rm -f $(echo $f | rev | cut -c3- | rev)$cor
	fi
	./tev $f &>/dev/null
	if [ -f "$(echo $f | rev | cut -c3- | rev)$cor" ]
	then
		hexdump -C $(echo $f | rev | cut -c3- | rev)$cor > $dir/tev
		rm -f $(echo $f | rev | cut -c3- | rev)$cor
	fi
	if [ -f "$dir/tev" ] && [ -f "$dir/zaz" ]
	then
		echo "Testing $(echo $f | rev | cut -c3- | rev) ..."
		diff -s $dir/zaz $dir/tev
	fi
	if [ -f "$dir/tev" ]
	then
		rm -f $dir/tev
	fi
	if [ -f "$dir/zaz" ]
	then
		rm -f $dir/zaz
	fi
done
