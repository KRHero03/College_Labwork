.model small
.stack 10H
.data
num1 dw 12h
num2 dw 10h
hcf dw ?
lcm dw ?

.code
start:
mov ax,@data
mov ds,ax

mov ax,num1
mov bx, num2

doit: 
mov dx,0
mov cx,bx
div bx
mov bx,dx
mov ax,cx
cmp bx,0
jne doit

mov hcf,ax
mov cx,ax
mov ax,num1
mov bx,num2
mul bx
div cx

mov lcm,ax
         

mov ah,4ch
int 21h 
end start