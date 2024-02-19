.address 0x8000
ja sys_start

//
//	MEMORY SYMBOLS
//

.const intr_address 0x1000


//
//	CODE TEXT
//

// System Code
.scope sys_start
	mov bx, 0x218
	mov al, 1
	out bx, al
	ja sys_loop
.endscope

.scope sys_loop
	ja sys_loop
.endscope






