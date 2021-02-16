.model small
.stack 10H
.data
src db "This is a string$"

.code
start:
mov ax,@data
mov ds,ax

mov si, 0

loop1:

mov al, src[si]
cmp al,97
jc continue
cmp al,122
jnc continue
sub al,20h
mov src[si],al
jmp continue3

continue:
cmp al,65
jc continue2
cmp al,90
jnc continue2
add al,20h
mov src[si],al
jmp continue3

continue2:
cmp src[si],'$'
jz exit
continue3:
inc si
jmp loop1

exit:


mov dx, offset src
mov ah,09h
int 21h


mov ah,4ch
int 21h 
end start
