.model small
.stack 10H
.data
nums dw 2000h, 2043h, 2031h, 1234h
count dw 04h
res dd ?

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
add ax,cx
jnc next
add dx,1h
next:
sub bx,2h
jnz loop1
mov word ptr res,ax
mov word ptr res+2,dx


mov ah,4ch
int 21h 
end start
