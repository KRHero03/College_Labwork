
;<Question 3>

jmp start

;data


;code
start:	lxi d,2064h
	lxi h,205fh
	mvi b,11h
loop:	mov a,m
	mvi m,00h
	xchg
	mov m,a
	dcx h
	xchg
	dcx h
	dcr b
	jnz loop
	hlt