;External to internal

mov dptr, #2000h
mov r0, #40h
mov r3, #0ah

l1:
	movx a, @dptr
	mov @r0, a
	inc dptr
	inc r0
	djnz r3, l1
	
end