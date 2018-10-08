#!/bin/bash
rm diff
for f in champions/unitests/*.cor #path champ1
do
    for m in champions/unitests/*.cor #path champ2
    do
        let "count=10"
        for n in `seq 1 3`
        do
           	let "nb=$count*$n"
           	../../resources/vm_champs/corewar "$f" "$m" -d "$nb" > dump_zaz
        	../corewar "$f" "$m" -dump "$nb" > dump_cor  #ton corwar avec option pour dump
            grep '0x' dump_zaz > dump_zaz
           	grep '0x' dump_cor > dump_cor
           	diff dump_cor dump_zaz -i >> diff
        done
    done
done
