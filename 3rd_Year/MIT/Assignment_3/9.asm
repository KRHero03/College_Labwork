
;<Question 9>

jmp start

;data


;code
start:	lhld 4002h
	xchg
	lda 4000h
	mov a,e
	sta 4004h
	mov a,d
	sbb h
	sta 4005h
	hlt