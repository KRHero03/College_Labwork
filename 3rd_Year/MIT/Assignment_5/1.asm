
;<Question 1>

jmp start

;data


;code
start:	lxi d,2090h
	lxi h, 2070h
	mvi b,30h
	mvi c,40h		
loop:	mov a,m
	sbi 0dh
	jz exit
	adi 0dh
	cmp b
	jc skip
	cmp c
	jnc skip
	xchg
	mov m,a
	inx h
	xchg
skip:	inx h
	jmp loop	
exit:	hlt