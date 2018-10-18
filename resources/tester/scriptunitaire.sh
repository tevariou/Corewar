rm diff
for f in champions/unitests/*.cor
do
	echo "\n" >> diff
	let "count=1000"
	../corewar -d  "$count" "$f" > dump_zaz
	../../corewar -dump "$count" -n 4294967295 "$f" > dump_cor
	grep '0x' dump_cor > diff_cor
	grep '0x' dump_zaz > diff_zaz
	echo "$f" >> diff
	diff diff_cor diff_zaz -i >> diff
done
rm dump_zaz dump_cor diff_cor diff_zaz
