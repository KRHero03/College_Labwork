
;<Question 4>

jmp start

;data


;code
start:	lxi h,2050h
	mov c,m
	mov d,m
loop1:	lxi h,2051h
	mov b,d
	dcr b
loop2:	mov a,m
	inx h
	cmp m
	jnc skip
	mov e,m
	mov m,a
	dcx h
	mov m,e
	inx h
skip:	dcr b
	jnz loop2
	dcr c
	jnz loop1
	hlt