.name "live test"
.comment "live test"

ld %0,r2
sti r1,%:debut,%1
debut:
live %1
zjmp %:debut
