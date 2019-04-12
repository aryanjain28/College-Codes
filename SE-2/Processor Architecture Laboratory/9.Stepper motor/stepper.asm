; stepper motor

ljmp start

delay:

		mov r0, #0x0f
		mov r1, #0x10

	l1:
		djnz r0, l1
		djnz r1, l0
		ret

start:
	mov a, #0x00

	l2:
		mov P1, #0x01
		lcall delay
		mov P1, #0x04
		lcall delay
		mov P1, #0x02
		lcall delay
		mov P1, #0x08
		lcall delay
end
		
