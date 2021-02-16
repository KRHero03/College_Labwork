
;<Question 5>

jmp start

;data


;code
start:	lda 4000h
	mov b,a
	lda 4002h
	add b
	sta 4004h
	lda 4001h
	mov b,a
	lda 4003h
	add b
	sta 4005h
	hlt