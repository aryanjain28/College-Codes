print macro str

mov dx, offset str
mov ah, 9h
int 21h
    
endm

.model small

.data
    Arr dw 5000h, 5000h, 3000h,2000h
    Result dw 0
    Temp db ?
    Msg db 'Addition is : $'
.code

main proc
  
    mov ax, @data
    mov ds, ax
    
    mov bx, offset Arr
    mov cx, 4h
    
    l1:
       
       mov ax, [bx]
       add Result, ax
       add bx, 2
    
    loop l1
    
    print Msg
    mov bx, Result
    
    mov Temp, bh  
    call display
    
    mov Temp, bl
    call display
    
    mov ah, 4ch
    int 21h
    
main endp
         
display proc
    
    mov dl, temp
    and dl, 0f0h
    mov cl, 04h
    shr dl, cl
    cmp dl, 09h
    jng change1 
    add dl, 7h
    
    change1:
        add dl, 30h
        mov ah, 2h
        int 21h
        
    mov dl, temp
    and dl, 0fh
    cmp dl, 09h
    jng change2 
    add dl, 7h
    
    change2:
        add dl, 30h
        mov ah, 2h
        int 21h
        
        
    ret    
        
display endp

end         

