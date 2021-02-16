
;<Question 8>

jmp start

;data


;code
start:	lda 4000h
	cma
	inr a
	sta 4001h
	hlt