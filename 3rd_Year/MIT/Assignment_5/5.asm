
;<Question 5>

jmp start

;data


;code
start:	lxi h,2050h
	mov d,m
	mvi b,00h
	mvi c,00ffh
loop:	mov a,m
	cmp b
	jc next
	mov b,a
next:	cmp c
	jnc skip
	mov c,a
skip:	inx h
	dcr d
	jnz loop
	hlt