.onmark
.mark

.include "../drivers/disk.asm"
.include "../util/util.asm"


//
//	MEMORY SYMBOLS
//

.const fs_cluster_marks 0x10000 // Length: 0x2000, clusters marks cluster
.const fs_cluster_info 0x12000 // Length: 0x2000, clusters counter cluster

.const fs_available 0x13000 // Word, available storage clusters in File System
.const fs_seek 0x13004 // Word, the seek pointer to start finding empty clusters for allocation
.const fs_state 0x13008 // Dword, state of general File System
.const fs_dstate 0x13FFC // Half, state of Disk System
.const fs_fsstate 0x13FFE // Half, state of File System

.const FS_STATE_NOT_BUSY 0
.const FS_FSSTATE_SETUP 1
.const FS_FSSTATE_FORMAT 2
.const FS_DSTATE_READING 1
.const FS_DSTATE_WRITING 2


//
//	CODE TEXT
//

//
//	_fsInterruptionEvent
//
.scope _fsInterruptionEvent
	psh eax
	mov eax, FS_STATE_NOT_BUSY
	mov [fs_state], eax
	pop eax
	ret
.endscope

//
//	_fsClusterLoad
//	args:
//	- edx => Index of cluster
//	- esd => Buffer to Load to
//
.scope _fsClusterLoad
	// Saving old procedure values
	_saveCtx
	
	// Reading base clusters
	mov ess, edx
	lsh ess, 13
	mov ecx, 0x2000
	ba diskReadFrom
	
	// End of function
	end:
	_restoreCtx
	ret
.endscope

//
//	_fsClusterSave
//	args:
//	- edx => Index of cluster
//	- ess => Buffer to Save from
//
.scope _fsClusterSave
	// Saving old procedure values
	_saveCtx
	
	// Writing base clusters
	mov esd, edx
	lsh esd, 13
	mov ecx, 0x2000
	ba diskWriteTo
	
	// End of function
	end:
	_restoreCtx
	ret
.endscope

//
//	_fsClusterAllocate
//	args:
//	- ebx => Pointer to list to receive clusters indices
//	- ecx => Count to number of clusters to allocate
//	return:
//	**- eax => 0 if done, otherwise is error
//
.scope _fsClusterAllocate
	// Saving old procedure values
	_saveCtx
	
	/*
		register __asm("ebx") u16* base;
		register __asm("ecx") int count;
		register __asm("eax") int cluster_index = 0;
		register __asm("eex") int byte = 0;
		byteloop: while (true){
			register __asm("egx") u8* byte_index = (cluster_index>>3) + fs_cluster_marks;
			byte = *byte_index;
			bitloop: for (register __asm("ehx") int bit_index = cluster_index&0x7; bit_index < 8; bit_index++){
				register __asm("efx") int bit = (byte>>bit_index)&1;
				if (bit==0){
					bit = 1;
					byte |= bit<<bit_index;
					*base = cluster_index;
					base += 2;
					count--;
					if (count==0){
						break bitloop;
					}
				}
				cluster_index++;
			}
			*byte_index = byte;
			if (count==0){
				break byteloop;
			}
		}
	*/
	//register __asm("ebx") u16* base;
	//register __asm("ecx") int count;
	//register __asm("eax") int cluster_index = fs_seek;
	mov eax, [fs_seek]
	//register __asm("eex") int byte = 0;
	mov eex, 0
	//byteloop: while (true){
	byteloop:
	//	register __asm("egx") u8* byte_index = (cluster_index>>3) + fs_cluster_marks;
		mov egx, eax
		rsh egx, 3
		add egx, fs_cluster_marks
	//	byte = *byte_index;
		mov eex, [egx]
	//	bitloop: for (register __asm("ehx") int bit_index = cluster_index&0x7; bit_index < 8; bit_index++){
		mov ehx, eax
		and ehx, 0x7
		bitloop:
	//		register __asm("efx") int bit = (byte>>bit_index)&1;
			mov efx, eex
			rsh efx, ehx
			and efx, 1
	//		if (bit==0){
				jr.nez efx, @bitsetted
	//			bit = 1;
				mov efx, 1
	//			byte |= bit<<bit_index;
				lsh efx, ehx
				or eex, efx
	//			*base = cluster_index;
				mov [ebx], ax
	//			base += 2;
				add ebx, 2
	//			count--;
				dec ecx
	//			if (count==0){
	//				break bitloop;
				jr.eqz ecx, @endbitloop
	//			}
	//		}
			bitsetted:
	//		cluster_index++;
			inc eax
	//	}
			inc ehx
			cmp ehx, 8
			jr.lt @bitloop
		endbitloop:
	//	*byte_index = byte;
		mov [egx], el
	//	if (count==0){
	//		break byteloop;
		jr.eqz ecx, @endbyteloop
	//	}
	//}
		jr @byteloop
	endbyteloop:
	
	// End of function
	end:
	inc eax
	mov eax, [fs_seek]
	_restoreCtx
	ret
.endscope

//
//	_fsClusterFree
//	args:
//	- ebx => Pointer to list to indicate clusters indices
//	- ecx => Count to number of clusters to free
//	return:
//	**- eax => 0 if done, otherwise is error
//
.scope _fsClusterFree
	// Saving old procedure values
	_saveCtx
	
	/*
		u16* base;
		int count;
		while (count > 0){
			int cluster = *base;
			int bit_offset = cluster&0x7;
			u8* byte_offset = cluster>>3 + fs_cluster_marks;
			int byte = *byte_offset;
			bit_offset = ~(1<<bit_offset);
			byte &= bit_offset;
			*byte_offset = byte;
			base += 2;
			count--;
		}
	*/
	//register __asm("ebx") u16* base;
	//register __asm("ecx") int count;
	//while (count > 0){
	clusterloop:
	//	register __asm("eax") int cluster = *base;
		mov eax, 0
		mov ax, [ebx]
	//	register __asm("edx") int bit_offset = cluster&0x7;
		mov edx, eax
		and edx, 0x7
	//	register __asm("eex") u8* byte_offset = cluster>>3 + fs_cluster_marks;
		mov eex, eax
		rsh eex, 3
		add eex, fs_cluster_marks
	//	register __asm("efx") int byte = *byte_offset;
		mov fl, [eex]
	//	bit_offset = ~(1<<bit_offset);
		psh eax
		mov eax, 1
		lsh eax, edx
		mov edx, eax
		not edx
		pop eax
	//	byte &= bit_offset;
		and efx, edx
	//	*byte_offset = byte;
		mov [eex], fl
	//	base += 2;
		add ebx, 2
	//	count--;
		dec ecx
	//}
		jr.nez ecx, @clusterloop
	
	// End of function
	end:
	_restoreCtx
	ret
.endscope

//
//	fsSetup
//
.scope fsSetup
	// Saving old procedure values
	_saveCtx
	
	// Setup configurations
	mov eax, _fsInterruptionEvent
	mov [disk_event_callback], eax
	mov ax, FS_FSSTATE_SETUP
	mov [fs_fsstate], ax
	
	// Reading base clusters
	mov ess, 0
	mov esd, fs_cluster_marks
	mov ecx, 0x4000
	ba diskReadFrom
	
	// End of function
	end:
	_restoreCtx
	ret
.endscope

//
//	fsFormat
//
.scope fsFormat
	// Saving old procedure values
	_saveCtx
	
	// Skipping on busy state
	mov eax, [fs_state]
	jr.nez eax, @end
	
	// Gathering size of mass storage of disk
	ba diskGetStorageLength
	mov edx, eax
	rsh edx, 13
	
	// Reseting clusters info
	mov ecx, 0x10000
	bloop:
		// Translating to byte index
		mov ebx, ecx
		dec ebx
		div ebx, 8
		add ebx, fs_cluster_marks
		
		// Clearing the data
		mov eax, 0
		
		// Bit setting
		mov eex, 8
		cloop:
			// Following cluster and bit index
			dec ecx
			dec eex
			
			// Reseting and loading bit value
			lrot al, 1
			
			or al, 1
			// ecx>2 && ecx<edx
			cmp ecx, 2
			jr.le @one
			cmp ecx, edx
			jr.ge @one
			zero:
				and al, 0xFE
			one:
			jr.nez eex, @cloop
		
		// Saving up the bit change
		mov [ebx], al
		jr.nez ecx, @bloop
	mov ax, FS_FSSTATE_FORMAT
	mov [fs_fsstate], ax
	
	// Writing base clusters
	mov ess, fs_cluster_marks
	mov esd, 0
	mov ecx, 0x4000
	ba diskWriteTo
	
	// End of function
	end:
	_restoreCtx
	ret
.endscope

//
//	fsBusy
//	return:
//	- eax => The File System current state
//
.scope fsBusy
	mov eax, [fs_state]
	ret
.endscope


