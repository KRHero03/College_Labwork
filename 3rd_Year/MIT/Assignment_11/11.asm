.model small
.stack 10H
.data
s1 db 200  dup('$')
s2 db 200 dup('$')
message1 db "Enter String : $"
message2 db "Enter Substring to Find: $"
message3 db 10,"Occurence Found: $"
message4 db 10,"No Occurence Found! $"

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
mov s1[si],al
inc si
jmp loop1

exit1:
print message2
mov si,0h
loop2:
mov ah,01h
int 21h
cmp al,0dh
jz exit2
mov s2[si],al
inc si
jmp loop2

exit2:
mov bx,0h

loopA:
mov si,bx
mov di,0h

loopB:
mov al,s1[si]
mov cl,s2[di]
cmp al,cl

jnz exit3
cmp cl,24h
jnz continue
print message3
printNum bx
jmp done

continue:
inc si
inc di
jmp loopB

exit3:
cmp al,24h
jz notfound
inc bx
jmp loopA

notfound:
print message4


done:
mov ah,4ch
int 21h 
end start
