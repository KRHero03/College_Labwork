
;<Question 3>

jmp start

;data


;code
start:	lxi h,2000h
	mov b,m
	mvi c,00h
repeat: inx h
	mov a,m
	cpi 39h
	jc digit
	sbi 41h
	adi 0ah
	jmp sum
digit:	sui 30h
sum:	add c
	mov c,a	
	dcr b
	jnz repeat
	mov a,c
	sta 1fffh	
	hlt