
;<Question 2>

jmp start

;data


;code
start:	lxi h,2000h
	mov a,m
	cpi 00h
	jz END
	mov d,m
	mvi b,00h
	mvi c,01h
	inx h
	mvi m,00h
LOOP:	call REPEAT
	inx h 
	mov m,b
	dcr d
	mov a,d
	cpi 00h
	jnz LOOP
	jmp END
REPEAT: mov a,b
	mov b,c
	add b
	mov c,a
	ret

END:	hlt