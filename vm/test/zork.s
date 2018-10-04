.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r0, %:live, %1
		and r0, %0, r0

live:	live %1
		zjmp %:live
