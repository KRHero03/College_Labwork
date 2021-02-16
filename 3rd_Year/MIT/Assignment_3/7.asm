
;<Question 7>

jmp start

;data


;code
start:	lda 4000h
	cma
	sta 4001h
	hlt
