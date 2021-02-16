;Author: KRHero
;IDE: VSCode

.model small
.stack 256

.data 
num1 db 08h
num2 dw 256h
quotient db ?
remainder db ?

.code
start:
mov ax,@data
mov ds,ax

mov ax, num2
mov bl, num1
div bl

mov quotient,al
mov remainder,ah


mov ah,4ch
int 21
end start
