
;<Question 3>

jmp start

;data


;code
start:	mvi b,91h
	mvi c,87h
	mvi a,0001h
	ana b
	mov b,a
	mvi a,0001h
	ana c
	mov c,a


hlt