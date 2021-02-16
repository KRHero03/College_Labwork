
;<Question 1>

jmp start

;data


;code
start:	mvi b,00h
	inr b
	lda 3000h
	lxi h,3002h
	rar
	rar
	rar
	ana b
	jz zero
	mvi m,00ffh
	jmp exit
zero:	mvi m,00h
exit:	hlt