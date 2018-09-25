.name ""#com
.comment";ok
wef"

l2:	l2: sti r1,2,%1
	and r1, %0,r1

live:live%-1
		zjmp %:live
and -1, r1, r2
ld 2,r2
# comments
