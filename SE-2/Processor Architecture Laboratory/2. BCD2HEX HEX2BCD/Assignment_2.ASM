nextline macro
     
      mov dx, 10
      mov ah, 2h
      int 21h
      
      mov dx, 13
      mov ah, 2h
      int 21h  
endm

print macro str
     
     mov dx, offset str
     mov ah, 9h
     int 21h
    
endm

.model small

.data
    Arr dw 2710h, 03e8h, 0064h, 000ah, 0001h
    count dw ?
    choice db ?
    num dw ?
    res dw 0000h
    temp db ?
    
    input1 db 'Enter 4-digit hex : $'
    input2 db 'Enter 5-digit bcd : $'
    
    result db 'Result : $'
    
    op1 db '1.Convert HEX to BCD.$'
    op2 db '2.Convert BCD to HEX.$'
    op3 db '3.Exit.$'
    thanx db 'Thank you.$'

.code
main proc
    mov ax, @data
    mov ds, ax
    
    l1:
    
    nextline
    print op1
    nextline
    print op2
    nextline
    print op3
    nextline
    
    mov ah, 1h
    int 21h
    
    mov choice, al
    
    cmp choice, '1'
    jne next1
    call HEX2BCD
    
    next1:
    cmp choice, '2'
    jne next2
    call BCD2HEX
    
    next2:
    cmp choice, '3'
    jne l1
        
    call exit
main endp


HEX2BCD proc
     
     call input
     mov ax, bx
     mov bx, 10
     mov cx, 0h
     
     up3:
     mov dx, 0
     div bx
     push dx
     inc cx
     or ax, ax
     jnz up3
     
     
     nextline
     print result
     
     up4:
     pop dx
     add dl, 30h
     mov ah, 2h
     int 21h
     dec cl
     jnz up4
     
     
     ret
HEX2BCD endp

BCD2HEX proc
    
    nextline
    print input2
    
    mov si, offset Arr
    mov cx, 5
    mov count, cx
    mov bx, 0000h
    
    level1:
    mov ah, 1h
    int 21h
    sub al, 30h
    mov ah, 0h
    mov cx, [si]
    mul cx
    add res, ax
    inc si
    inc si
    dec count
    jnz level1
    
    nextline
    print result
    mov bx, res
    mov temp, bh
    call display
    mov temp, bl
    call display
    
    ret
    
BCD2HEX endp   


display proc
    
    mov dl, temp
    and dl, 0f0h
    mov cl, 04h
    shr dl, cl
    add dl, 30h
    cmp dl, 39h
    jng down8
    add dl, 7h
    down8:
    mov ah, 2h
    int 21h
    
    mov dl, temp
    and dl, 0fh
    add dl, 30h
    cmp dl, 39h
    jng down9
    add dl, 7h
    down9:
    mov ah, 2h
    int 21h
    
    ret
    
display endp




input proc
    
    mov cl, 4h
    nextline
    print input1
    
    mov si, 4h
    mov cl, 4h
    
    up1:
    mov ah, 1h
    int 21h
    
    cmp al, 39h
    jng down1
    
    cmp al, 46h
    jng down2
    
    sub al, 20h
    
    down2:
    sub al, 7h
    
    down1:
    sub al, 30h    
    shl bx, cl
    add bl, al
        
    dec si
    jnz up1
    
    ret
    
input endp

exit proc
    
    nextline
    print thanx
    mov ah, 4ch
    int 21h
    ret
    
exit endp

end


