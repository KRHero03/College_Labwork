
;<Question 1>

jmp start

;data


;code
start:	mvi c,00a8h
	mov a,c
	ani 000fh
	out 00h
hlt