rm diff
for f in champions/unitests/*.cor
do
	let "count=1000"
	../../resources/vm_champs/corewar -d "$count" "$f" > dump_zaz
	../corewar -dump "$count" "$f" > dump_cor
	grep '0x' dump_cor > diff_cor
	grep '0x' dump_zaz > diff_zaz
	diff diff_cor diff_zaz -i >> diff
done
