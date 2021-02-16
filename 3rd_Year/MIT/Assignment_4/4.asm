
;<Question 4>

jmp start

;data


;code
start:	stc
	cmc
	mvi b,00ffh
	inr b
	jnc nocarry
	mvi a,01h
	out 00h
	jmp exit
nocarry: mov a,b
	out 00h
exit:	hlt