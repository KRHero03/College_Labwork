.model small
.stack 10H
.data
num1 dw 2404h
res dw ?

.code
start:
mov ax,@data
mov ds,ax

mov dx, num1
mov cx,0h
mov bx,10h

doit:
mov ax,dx
and ax,1h
jz notone
inc cx

notone:
rcr dx,1
dec bx
jnz doit

mov res,cx



exit:
mov ah,4ch
int 21h 
end start