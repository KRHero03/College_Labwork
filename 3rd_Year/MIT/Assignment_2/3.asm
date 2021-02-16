;<Question 3>
jmp start
;data
;code
start: lxi H,0BB8H
mov C, M
lxi H, 0BB9H
xra A
mov E, A
LOOP: add M
jnc SKIP
inr E
SKIP: dcr C
inx H
jnz LOOP
lxi H,0BB7H
mov M, A
inx H
mov M, E
hlt