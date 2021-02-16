
;<Question 2>

jmp start

;data


;code
start:	lxi h,2000h
	mvi b,0ah
	mvi d,00h
	mvi e,00h
repeat: push d
	inx h
	mov a,m
	mov d,a
	ani 0fh
	mov e,a
	mov a,d
	ani 0f0h
	rrc
	mov d,a
	rrc
	rrc
	add d
	add e
	pop d
	add e
	mov e,a
	jnc done
	inr d
done:	dcr b
	jnz repeat
	xchg
	shld 1fffh	
	hlt