
;<Question 2>

jmp start

;data


;code
start:	mvi b,1h
	mov a,b
	mvi c,08h
	mvi b,00h
loop:	rar
	jnc skip
	inr b
skip:	dcr c
	jnz loop
	hlt