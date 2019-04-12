;Internal to external

mov dptr, #2000h
mov r0, #40h
mov r3, #0ah

l1:
	mov a, @r0
	movx @dptr, a
	inc dptr
	inc r0
	djnz r3, l1
	
end
