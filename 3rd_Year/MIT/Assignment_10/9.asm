.model small
.stack 10H
.data
num1 dw 1001h
res dw ?

.code
start:
mov ax,@data
mov ds,ax
mov ax,num1
mov bx,num1

and ax,0f000h
and bx,0fh
rcr ax,12
cmp ax,bx

jnz exit

mov ax,num1
mov bx,num1

and ax,0f00h
and bx,00f0h
rcr ax,8
rcr bx,4

cmp ax,bx

jnz exit

mov res,1h
jmp exit1


exit:
mov res,0h

exit1:
mov ah,4ch
int 21h 
end start