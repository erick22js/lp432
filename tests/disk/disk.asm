.onmark
.mark


//
//	CODE TEXT
//

.scope intrDiskDevice
	// Saving old procedure values
	psh edx
	
	// End of function
	end:
	pop edx
	ret
.endscope

//
//	readFromDisk
//	args:
//	- ess => Disk Source seek
//	- esd => Memory Destination seek
//	- ecx => Stream Length
//
.scope readFromDisk
	// Saving old procedure values
	psh edx
	psh ebx
	
	// Gathering the extenal device
	mov ebx, 0
	mov bl, [device_disk]
	jr.eqz ebx, @end
	
	// Processing event
	lsh ebx, 8
	add ebx, 12
	out bx, ess
	add ebx, 4
	out bx, esd
	add ebx, 4
	out bx, ecx
	add ebx, 4
	mov dl, 0x02
	out bx, dl
	
	// End of function
	end:
	pop ebx
	pop edx
	ret
.endscope

//
//	writeToDisk
//	args:
//	- ess => Memory Source seek
//	- esd => Disk Destination seek
//	- ecx => Stream Length
//
.scope writeToDisk
	// Saving old procedure values
	psh edx
	psh ebx
	
	// Gathering the extenal device
	mov ebx, 0
	mov bl, [device_disk]
	jr.eqz ebx, @end
	
	// Processing event
	lsh ebx, 8
	add ebx, 12
	out bx, esd
	add ebx, 4
	out bx, ess
	add ebx, 4
	out bx, ecx
	add ebx, 4
	mov dl, 0x04
	out bx, dl
	
	// End of function
	end:
	pop ebx
	pop edx
	ret
.endscope

