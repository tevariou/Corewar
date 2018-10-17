.name "Stargate"
.comment "infinity"



###tentative 1 creation Stargate

#load de facon stupide un code entier sur les 6 derniers registres
#ld %72614403, r15
#ld %50746378, r14
#ld %168428400, r13
#ld %67111427, r12
#ld %1879244809, r11
#ld %2785017856, r2
#ld %655335, r3
#ld %57673009, r4
#st r15, 510
#st r14, 509
#st r13, 508
#st r12, 507
#st r11, 506
#add r7, r7, r7
#zjmp %480

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

########################
#### stargate fonctionelle #####
# r2 is diff for bomb
# r3 is the jump
# r4 is the bomb
#### code stargate
ld %117440512, r2
ld %2718563841, r3
ld %57672961, r4
add r2, r3, r3
and r10, r10, r10
st r4, 496
st r3, 495
zjmp %486
