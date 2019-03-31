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
	extrn String1 : byte
	extrn String2 : byte

	
	con db 'Concatenated string : $'
	come db 'Equal.$'
	comne db 'Not Equal.$'

	String3 db 30h
	        db 0h
	        db 30h dup('$')
.code

	public Concatenate
	public Compare

	mov ax, @data
	mov ds, ax

Concatenate proc far
	nextline	
	print con
	mov cl, 13      
	
	mov di, offset [String3+2]
	mov si, offset [String1+2]

	up3:
	mov bl, 00h
	mov bl, [si]
	mov [di], bl
	movsb
	cmp [si], cl
	jne up3

	mov si, offset [String2+2]

	up4:
	mov bl, 00h
	mov bl, [si]
	mov [di], bl
	movsb  
	cmp [si], cl
	jne up4

	print [String3+2]

	ret 
Concatenate endp

Compare proc far
	mov cl, [String1+1]
	mov bl, [String2+1]
	mov bh, 00h
	mov ch, 00h
	cmp bl, cl
	jnz down

	mov si, offset [String1+2]
	mov di, offset [String2+2]

	up8:
	mov bl, 00h
	mov bl, [si]
	cmp [di], bl
	jne down
	movsb
	loop up8

	nextline
	print come
	ret

	down:
	nextline
	print comne
	ret
Compare endp

end
