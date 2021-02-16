
;<Question 11>

jmp start

;data


;code
start:	mvi b,20h
	mvi c,30h
	mvi d,25h

	mov a,b
	ana c
	ana d
	sta 3000h

	mov a,b
	ora c
	ora d
	sta 3001h
	
	mov a,b
	xra c
	xra d
	sta 3002h


	hlt