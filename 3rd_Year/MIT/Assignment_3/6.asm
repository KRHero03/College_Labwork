
;<Question 6>

jmp start

;data


;code
start:	lda 4000h
	mov h,a
	lda 4001h
	add h
	mov l,a
	mvi a,0
	adc a
	mov h,a
	shld 4002h
	hlt