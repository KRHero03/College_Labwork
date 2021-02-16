;Author: KRHero
;IDE: VSCode

.model small
.stack 100h

.data
num1 db 12h
num2 db 25h
res db ?

.code
start:

;Load data variables into existence
mov ax,@data
mov ds,ax

;Load values from variables
mov al,num1
mov bl,num2

;Add the values
sub bl,al

;Store the result in res variables
mov res,bl

;Exit the program
mov ah,4ch
int 21
end start


