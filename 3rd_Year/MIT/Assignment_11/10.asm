.model small
.stack 10H
.data
src db 200  dup('$')
message1 db "Enter String : $"
message2 db "Enter Character: $"
message3 db 10,"Occurence Found: $"
message4 db 10,"No character position found! $"
base_10 dw 000dh

print macro msg
mov dx,offset msg
mov ah,09h
int 21h
endm

printNum macro num
local repeat_loop, print_char

mov ax, num
xor cx, cx   
repeat_loop:
xor dx, dx
div base_10
push dx                 
inc cx                 
test ax, ax
jnz repeat_loop 
print_char:
pop dx
add dl, 30h            
mov ah, 02h            
int 21h
loop print_char

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
jz exit1
mov src[si],al
inc si
jmp loop1

exit1:
print message2
mov ah,01h
int 21h
mov bl,al

mov si,0h
loop2:
cmp src[si],bl
jnz exit2
print message3
printNum si

exit2:
cmp src[si],24h
jz exit3
inc si
jmp loop2


exit3:
mov ah,4ch
int 21h 
end start
