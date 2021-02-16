;<Question 5>
jmp start
;data

;code
start: LHLD 0000H
XCHG
LHLD 0002H
MOV A, E
ADD L
MOV L, A
MOV A, D
ADC H
MOV H, A
SHLD 0000H
HLT