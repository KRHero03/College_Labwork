
;<Question 13>

jmp start

;data


;code
start:	lhld 3000h
	mov a,h
	cma
	mov h,a
	mov a,l
	cma
	mov l,a
	inx h
	shld 3002h
	hlt