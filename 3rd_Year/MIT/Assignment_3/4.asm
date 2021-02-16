
;<Question 4>

jmp start

;data


;code
start:	lxi h,2000h
	mov a,m
	lxi h,4001h
	sub m
	sta 4002h
	hlt