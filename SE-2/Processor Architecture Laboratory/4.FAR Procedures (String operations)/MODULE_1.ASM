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

	public String1
	public String2
	
	String1 db 30h
		db 0h
		db 30h dup('$')

	String2 db 30h
		db 0h
		db 30h dup('$')

	Menu db 10, 13, '1.Enter strings.'
	     db 10, 13, '2.Concatenate strings.'
	     db 10, 13, '3.Compare strings.'
	     db 10, 13, '9.Exit.'
	     db 10, 13, 'Your choice : $'

	Str1 db 'Enter string 1 : $'
	Str2 db 'Enter string 2 : $'
	
	Thanks db 'Thank you!$'

	
.code
	extrn Concatenate : far
	extrn Compare : far

main proc
	mov ax, @data
	mov ds, ax
	
	up:
	nextline
	print Menu
	
	mov ah, 1h
	int 21h

	cmp al, 31h
	je input1

	cmp al, 32h
	je Concatenate1

	cmp al, 33h
	je Compare1

	cmp al, 39h
	je Exit

	input1: call input
	jmp up

	Concatenate1: call Concatenate
	jmp up

	Compare1: call Compare
	jmp up 

	Exit:
	nextline	
	print Thanks
	mov ah, 4ch
	int 21h
		
main endp

input proc
	nextline
	print Str1
	mov ah, 0ah
	mov dx, offset String1
	int 21h

	nextline
	print Str2
	mov ah, 0ah
	mov dx, offset String2
	int 21h

	ret
input endp

end
