.name"ok"#COM
.comment"lo"

label1: sti r1,%:live,%1
and r1, %0, r1
label1:live %1
live:zjmp %:label1
	zjmp %:labelr2

