.model small
.stack 10H
.data
num1 dw -25h
res dw ?

.code
start:
mov ax,@data
mov ds,ax

mov ax, num1
and ax,8000h
jz positive
mov res,-1h
jmp exit

positive:
mov res, 1h

exit:
mov ah,4ch
int 21h 
end start