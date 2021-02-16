.model small
.stack 10H
.data

message db "Enter N: $"
n dw 0h

message1 db "Enter Number whose Occurence needs to be found: $"
num1 dw 0h

message2 db "Enter Number: $"
num2 dw ?


message3 db "Answer: $"
cnt dw 0h




print macro msg
mov dx,offset msg
mov ah, 09h
int 21h
endm

getint macro num
local loop1
local next
loop1:
mov ah,01h
int 21h

cmp al,30h
jc next

cmp al,3Ah
jnc next

mov bl,al
sub bl,30h
mov ax,num
mov cx,0ah
mul cx
add ax,bx
mov num,ax

next:
cmp al,0dh
jnz loop1

endm

printNum macro num
local repeat_loop, print_char

mov bx,0ah
mov ax, num
xor cx, cx   
repeat_loop:
xor dx, dx
div bx
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

print message
getint n

print message1
getint num1

mov si,n
loop3:
mov num2,0h
print message2
getint num2
mov ax, num1
mov bx,num2
cmp ax,bx
jnz next3
inc cnt
next3:
dec si
jnz loop3

print message3

printNum cnt


mov ah,4ch
int 21h 
end start
