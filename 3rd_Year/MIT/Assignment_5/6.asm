
;<Question 6>

jmp start

;data


;code
start:	lxi d,3000h
	lxi h,2000h
loop:	mov a,m
	xchg
	mov m,a
	xchg
	inx d
	inx h
	mvi a,30h
	cmp h
	jnz loop
	mvi a,00h
	cmp l
	jnz loop
	hlt