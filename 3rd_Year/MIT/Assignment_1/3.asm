;<Question 3>
jmp start
;data

;code
start: MVI B, 12H
MVI C, 25H
MOV A,B
ADD C
MOV B,A
HLT