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
mov bx, count
add bx,bx

mov cx,0h
loop1:
mov si,00h
loop2:
mov ax, [nums + si]
mov dx, [nums + si + 2h]
cmp ax,dx
jc next
mov [nums + si + 2],ax
mov [nums + si],dx
next:
add si,2h
mov ax,si
add ax,2h
cmp ax,bx
jnz loop2
add cx,2h
cmp cx,bx
jnz loop1


mov ah,4ch
int 21h 
end start
