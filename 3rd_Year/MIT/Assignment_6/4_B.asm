
;<Question 4 B>

jmp start

;data

;logic
;	x^2 = n
;	d = 01h, 03h,05h,07h,09h,0bh
;	n = ceil(sum(di)) i = 1 to x

;code
start:	mvi d,01h
	mvi e,01h
	lda 5000h
LOOP:	sub d
	jm END1
	jz END
	inr d
	inr d
	inr e
	jmp LOOP
END:	mov a,e
	jmp STORE
END1:	mov a,e
	dcr a
STORE:	sta 5001h
	hlt
	