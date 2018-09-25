.name ""#com
.comment";ok
wef"

l2:	sti r1,%:live,%1
	and r1, %0,r1

live:live%-1
		zjmp %:live
st r1, :l2
and -1, r1, r2
# comments
