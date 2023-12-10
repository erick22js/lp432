; Map the address of program ROM in memory
.program_adr 0x8000

sys_start:
	mov ecx, hello_world_end-hello_world
	mov ebx, hello_world
	print_letter:
		mov al, [ebx]
		out 0xB, al
		inc ebx
		dec ecx
		jr.gtz ecx, @print_letter
	ja sys_loop

sys_consts:
hello_world: .text "Hello World!"
hello_world_end:

sys_loop:
	ja sys_loop
