.model small
.stack 10H
.data
num1 db 5h
res dw ?

.code
start:
mov ax,@data
mov ds,ax

mov ax, 1h
mov bl, num1
doit:
mul bl
dec bl
jnz doit

mov res,ax
         

mov ah,4ch
int 21h 
end start