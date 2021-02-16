.model small
.stack 10H
.data
num1 dw 8001h
res dw ?

.code
start:
mov ax,@data
mov ds,ax
mov cx,10h
mov ax,num1

doit:
rcr ax,1
rcl bx,1
dec cx
jnz doit

ender:
mov ax,num1
cmp ax, bx

jz equal
mov res, 00h
jmp exit

equal:
mov res,1h

exit:
mov ah,4ch
int 21h 
end start