.model small
.stack 10H
.data
src db "This is a string$"
s equ $-src
dest db s dup ('$') 

.code
start:
mov ax,@data
mov ds,ax

mov si, 0h
mov ax,s
sub ax,1h

loop1:
mov bl,src[si]
push bx
inc si
cmp si,ax
jnz loop1

mov si,0h
loop2:
pop bx
mov dest[si],bl
inc si
cmp si,ax
jnz loop2


mov dx, offset dest
mov ah,09h
int 21h


mov ah,4ch
int 21h 
end start
