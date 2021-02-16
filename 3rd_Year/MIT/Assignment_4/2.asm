
;<Question 2>

jmp start

;data


;code
start:	mvi a,0fh
	mvi d, 008eh
	mvi e, 00f7h
	ana d
	mov d,a
	mvi a, 0fh
	ana e
	xra d
	out 00h
	

hlt