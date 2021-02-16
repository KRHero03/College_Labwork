;Author: KRHero
;IDE: VSCode

.model small
.stack 256

.data 
cnt db 05h
num1 dw 1450h,2450h,2123h,7568h,8920h
num2 dw ?

.code
start:
mov ax,@data
mov ds,ax

mov BL,cnt
mov SI,0000h

loop1:
mov AX,[num1 + SI]
mov [num2 + SI],AX
inc SI
inc SI
DEC BL
JZ exit
JMP loop1

exit:
mov ah,4ch
int 21
end start
