
;<Question 3>

jmp start

;data


;code
start:	lxi h,4000h
	mov a,m
	lxi h,4001h
	add m
	sta 4002h


hlt