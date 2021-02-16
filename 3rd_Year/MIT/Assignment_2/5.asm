;<Question 5>
jmp start
;data
;code
start: lxi H, 07D0H
mov B,M
inx H
mov A,M
cmp B
jnc STORE
mov A,B
STORE: sta 07D2H
hlt