mov r0,#0ah
mov r1,#40h
mov a,#00h
mov r3,#00h

l1: 
	add a,@r1
 	jnc l2
 	inc r3

l2: 
	inc r1
	djnz r0,l1
 	mov r6,a
 	mov a,r3
 	mov r7,a
end