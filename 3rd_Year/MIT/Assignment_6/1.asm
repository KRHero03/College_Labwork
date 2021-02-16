
;<Question 1>

jmp start

;data


;code
start:	lxi h,2000h	
	mvi b,01h
	mov c,m
LOOP1:	call REPEAT
	dcr c	
	mov a,c
	cpi 00h
	jnz LOOP1
	jmp END
REPEAT: mov d,c
	xra a	
LOOP:	add b
	dcr d
	jnz LOOP
	mov b,a
	ret
END:	inx h
	mov m,b	
	hlt