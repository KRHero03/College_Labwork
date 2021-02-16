;Author: KRHero
;IDE: VSCode

.model small
.stack 100h

.data
num1 dw 257h
num2 dw 352h
res dw ?

.code
start:

;Load data variables into existence
mov ax,@data
mov ds,ax

;Load values from variables
mov ax,num1 
mov bx,num2

;Add the values
add bx,ax

;Store the result in res variables
mov res,bx

;Exit the program
mov ah,4ch
int 21
end start


