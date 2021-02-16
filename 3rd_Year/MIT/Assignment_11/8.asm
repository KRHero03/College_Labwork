.model small
.stack 10H
.data
src db 100  dup('$')
message1 db "Enter String 1 : $"
message2 db "Enter String 2 : $"

print macro msg
mov dx,offset msg
mov ah,09h
int 21h
endm



.code
start:
mov ax,@data
mov ds,ax

mov si, 0h

print message1
loop1:
mov ah,01h
int 21h
cmp al,0dh
jmp exit1
mov src[si],al
inc si
jmp loop1

exit1:
print message2
loop2:
mov ah,01h
int 21h
cmp al,0dh
jz exit2
mov src[si],al
inc si
jmp loop2

print src


mov ah,4ch
int 21h 
end start
