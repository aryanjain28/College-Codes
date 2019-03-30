print macro str
    mov dx, offset str
    mov ah, 9h
    int 21h
endm

nextline macro
    mov dx, 10
    mov ah, 2h
    int 21h
    
    mov dx, 13
    mov ah, 2h
    int 21h
endm

.model small

.data
    Operations db 10, 13, '====MENU===='
         db 10, 13, '1.Enter new string.'
         db 10, 13, '2.Find length.'
         db 10, 13, '3.Display in reverse.'
         db 10, 13, '4.Find whether string is palidrome or not.'
         db 10, 13, '9.Exit.'
         db 10, 13, 'Your choice : $'
         
    Thanks db 'Thank you!$'
    Enter db 'Enter your string : $'
    Len db 'Length of your string is : $'
    Rev db 'Reversed string is : $'
    paliY db 'It is a palidrome.$'
    paliN db 'It is not a palidrome.$'
    String db 20h
           db ?
           db 20h dup(0)     
.code
main proc
    mov ax, @data
    mov ds, ax
    
    Menu:
    nextline
    print Operations
    
    mov ah, 1h
    int 21h
    
    cmp al, '1'
    je next1
    
    cmp al, '2'
    je next2
    
    cmp al, '3'
    je next3
    
    cmp al, '4'
    je next4
    
    cmp al, '9'
    je next9
    
    next1: call input
    jmp Menu
    next2: call slength
    jmp Menu
    next3: call reverse
    jmp Menu
    next4: call palidrome
    jmp Menu
    
    next9: 
    nextline
    print Thanks
    mov ah, 4ch
    int 21h
    
     
main endp

input proc
    nextline
    print Enter
    mov ah, 0ah
    mov dx, offset String
    int 21h
    ret
input endp

slength proc
    nextline
    print len
    mov dl, [String+1]
    add dl, 30h
    cmp dl, 39h
    jng down
    add dl, 7h
    down:
    mov ah, 2h
    int 21h
    ret
slength endp

reverse proc
    nextline
    print Rev
    mov cx, 0000h
    mov cl, [String+1]
    up:
    mov bx, cx
    inc bx
    mov dl, [String+bx]
    mov ah, 2h
    int 21h
    loop up
    
    ret
reverse endp

palidrome proc
    nextline
    mov cx, 0000h
    mov cl,[String+1]
    mov si, offset String
    mov di, offset String
    add si, 02h
    add di, cx
    inc di
    up1:
    mov dl, [si]
    cmp dl, [di]
    jnz down1
    inc si
    dec di
    dec cl
    jnz up1
    print paliy
    jmp exit
    
    down1:
    print palin
    exit:
    ret
palidrome endp

end
