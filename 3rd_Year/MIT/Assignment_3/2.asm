
;<Question 2>

jmp start

;data


;code
start:	lxi h,4000h
	mov b,m
	xchg
	lxi h,2000h
	mov a,m
	mov m,b
	xchg
	mov m,a
	hlt