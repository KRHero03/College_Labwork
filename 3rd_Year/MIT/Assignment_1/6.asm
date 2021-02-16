;<Question 6>
jmp start
;data

;code
start: LDA 0002
MOV B,A
LDA 0003
ADD B
STA 002
HLT