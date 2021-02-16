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

mov si, 0               

call copyStr      

mov ah, 09h
lea dx, dest
int 21h

mov ah, 04ch
int 21h

copyStr proc 

mov bx, 0

compute:            

mov bl, src [si]


mov dest[si], bl


inc si

cmp src[si], '$'
je return                      
jmp compute

return:

mov dest[si], '$' 
ret     

copyStr endp    


mov ah,4ch
int 21h 
end start
