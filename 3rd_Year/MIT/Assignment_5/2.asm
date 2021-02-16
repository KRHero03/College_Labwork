
;<Question 2>

jmp start

;data


;code
start:	lxi d,2060h
	lxi h,2050h
	mvi b,0ah
loop:	mov a,m
	mvi c,3ch
	cmp c
	jc skip
	mvi c,65h
	cmp c
	jnc skip
	xchg
	mov m,a
	inx h
	xchg
skip:	inx h
	dcr b
	jnz loop
	hlt