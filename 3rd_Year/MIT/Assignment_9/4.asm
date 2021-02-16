;Author: KRHero
;IDE: VSCode

.model small
.stack 256

.data 
num1 dw 120h
num2 dw 256h
quotient dw ?
remainder dw ?

.code
start:
mov ax,@data
mov ds,ax

mov ax, num2
mov bx, num1
div bx

mov word ptr quotient,ax
mov word ptr remainder,dx


mov ah,4ch
int 21
end start
