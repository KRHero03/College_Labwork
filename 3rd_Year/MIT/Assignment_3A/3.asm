
;<Question 3>

jmp start

;data


;code
start:	lxi h,4201h
	mov c,m
	lxi h,4202h
	mvi b,09h
loop:	mov a,m
	cmp b
	jnc skip
	inr d
skip:	inx h
	dcr c
	jnz loop
exit:	hlt
