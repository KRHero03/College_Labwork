
;<Question 4>

jmp start

;data


;code
start:	lxi h,2000h
	mov b,m
	mov c,m
LOOP:	call REPEAT
	dcr b
	mov a,b
	cpi 00h
	jnz LOOP	
	jmp END
REPEAT: mov a,d
	add c
	mov d,a
	ret
END:	inx h
	mov m,d
	hlt