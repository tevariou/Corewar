make
cp a.out ../ressources/champs/
cp asm ../ressources/champs/
cd ../ressources/champs/
for f in *.s
do
	if [ -f diff ]; then
		rm diff
	fi
	if [ -f comp1 ]; then
		rm comp1
	fi
	if [ -f comp2 ]; then
		rm comp2
	fi
	echo "FILENAME :" $f
	./a.out $f > /dev/null
	if [ -f ${f/.s/.cor} ]; then
		hexdump -C ${f/.s/.cor} > comp1
	fi
	./asm $f > /dev/null
	if [ -f ${f/.s/.cor} ]; then
		hexdump -C ${f/.s/.cor} > comp2
	fi
	if [ -f comp1 ] && [ -f comp2 ]; then
		diff comp1 comp2 > diff
	fi
	if [ -f diff ]; then
		cat diff
	fi
done
