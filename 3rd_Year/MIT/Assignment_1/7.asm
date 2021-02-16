;<Question 7>
jmp start
;data

;code
start: LHLD 0000
XCHG
LHLD 0002
MOV A, E
SUB L
STA 0000
MOV A, D
SBB H
STA 0001
HLT