;<Question 2>
jmp start
;data

;code
start: LDA 0002
MOV D, A
LDA 0003
MOV E, A
MOV A, D
STA 0003
MOV A, E
STA 0002
HLT