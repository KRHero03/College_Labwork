.model small
.stack 10H
.data
num1 dw 25h
res dw ?

.code
start:
mov ax,@data
mov ds,ax

mov ax, num1
and ax,1h
jz evennum

mov res,1h
jmp exit

evennum:
mov res,0h


exit:
mov ah,4ch
int 21h 
end start