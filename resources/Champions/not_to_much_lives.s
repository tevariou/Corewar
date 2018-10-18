.name "not_too_much_live"
.comment "....."

st r1, 6
live %0
fork %300
xor r2, r2, r2
zjmp %2147483630
