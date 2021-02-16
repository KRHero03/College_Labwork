
;<Question 6>

jmp start

;data


;code
start:	mvi b,00f8h
	mvi c,23h
	mov a,b
	sub c
	jm neg
	out 01h
	jmp exit
neg:	xri 00ffh
	adi 01h
	out 01h
exit: 	hlt