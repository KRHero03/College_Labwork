;<Question 4>
jmp start
;data
;code
start: lxi H,07D1H
xra A
mov B,A
mov B, M
inx H
LOOP: add M
jnc SKIP
inr C
SKIP: dcr B
jnz LOOP
lxi H,07D0H
mov M, A
hlt