.name "llo@"
.comment ";ok
wef"

fork %:live
#sti	r1, %:live, %1
#and	r1, %0, r1
live:live	%1
#zjmp	%:live
#ld %917504, r12
fork %:live
