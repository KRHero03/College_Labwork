.model small
.stack 10H
.data
nums dw 2000h, 2043h, 2031h, 1234h
count dw 04h
res dw ?

.code
start:
mov ax,@data
mov ds,ax
mov si, offset nums
mov bx,count
add bx,bx
mov ax,0h
loop1:
mov cx,[si + bx - 2]
cmp ax,cx
jnc next
mov ax,cx
next:
sub bx,2h
jnz loop1
mov res,ax


mov ah,4ch
int 21h 
end start
