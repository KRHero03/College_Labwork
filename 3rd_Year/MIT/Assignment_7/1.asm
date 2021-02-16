
;<Question 1>

jmp start

;data


;code
start:	lxi d,5000h
	push h
	lxi h,2000h
	mvi b,06h
loop1:	push b
	push d
	call find
	mov c,d
	mov b,a
	pop d
	xchg
	ani 0fh
	mov m,a
	inx h
	mov a,b
	rrc
	rrc
	rrc
	rrc
	ani 0fh
	mov m,a
	inx h
	mov a,c
	ani 0fh
	mov m,a
	inx h
	xchg
	inx h
	pop b
	dcr b
	jnz loop1	
	hlt	

find:	mov c,m
	xra a
	mvi d,00h
	mvi e,00h
LOOP2:	adi 01h
	daa
	jnc LOOP1
	inr d
LOOP1:	dcr c
	jnz LOOP2	
	ret

	hlt



 