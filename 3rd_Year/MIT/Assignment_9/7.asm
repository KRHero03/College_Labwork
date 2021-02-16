;Author: KRHero
;IDE: VSCode

.model small
.stack 256

.data 
num1 dw ?

.code
start:
mov ax,@data
mov ds,ax

;Immediate Addressing
MOV AX, 2000H

;Register Addressing
mov BX, AX

;Displacement or Direct Mode Addressing
mov [num1],BX

;Register Indirect Mode Addressing
MOV AX, [SI+2000]

;Base Indexed Mode Addressing
MOV AL, [BP+ 0100]

;Base Indexed Displacement Mode Addressing
mov AL, [SI+BP+2000] 




mov ah,4ch
int 21
end start
