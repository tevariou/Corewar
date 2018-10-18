.name "Stargate 1 .1"
.comment "infinity"



###bigger champ
and r2,r2,r2
zjmp %508
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
live %0
zjmp %33
live %0
live %0
live %0
live %0
live %0
live %0
st r1, 11
st r8,  2147483647
live %0

###tentative 1 creation Stargate

#code hexa d'un bomber
#04 54 02 03 
#03 06 54 0A 
#0A 0A 03 70 
#04 01 F0 03 
#70 03 01 EF 
#09 01 E6 00

#load de facon stupide un code entier sur les 6 derniers registres
ld %72614403, r16
ld %50746378, r15
ld %168428400, r14
ld %67235843, r13
ld %1879245295, r12
ld %151119360, r11
ld %100663296, r2
ld %2685009409, r3
ld %57672961, r4
ld %252645135, r5
st r16, 511
st r15, 510
st r14, 509
st r13, 508
st r12, 507
st r11, 506
and r6 ,r6 ,r6
zjmp %479



########################
#### stargate fonctionelle #####
# r2 is diff for bomb
# r3 is the jump
# r4 is the bomb
#### code stargate
#ld %2785017856, r2
#ld %654849, r3
#ld %57673009, r4
#add r2, r3, r3
#and r10, r10, r10
#st r4, 496
#st r3, 495
#zjmp %486
