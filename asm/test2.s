.name "llo@"
.comment ";ok
wef"

sti	r1, %:live, %1
and	r1, %0, r1
live:live	%1
zjmp	%:live
