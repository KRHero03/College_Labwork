;<Question 4>
jmp start
;data

;code
start: MVI B, 12H
MVI C, 25H
MOV A,C
SUB B
MOV B,A
HLT