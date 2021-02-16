;Author: KRHero
;IDE: VSCode

.model small
.stack 256

.data 
num1 dw 2541h
num2 dw 8456h
res dd ?

.code
start:
mov ax,@data
mov ds,ax

mov ax, num1
mov bx, num2
mul bx

mov word ptr res,ax
mov word ptr res+2,dx


mov ah,4ch
int 21
end start
