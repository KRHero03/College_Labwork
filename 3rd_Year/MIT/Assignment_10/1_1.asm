.model small
.stack 10H
.data
num dw 200h
res dd ?

.code
start:
mov ax,@data
mov ds,ax

mov ax,num
mov bx, num 
mul bx
mov word ptr res,ax
mov word ptr res+2,dx

mov ah,4ch
int 21h 
end start