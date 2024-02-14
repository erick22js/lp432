#include "encoder.h"


//
//	ENCODER FUNCTIONS
//

void encOut8(u8 data) {
	if (asm_info.phase_two){
		asm_info.bin[asm_info.bs] = data;
	}
	asm_info.bs++;
	asm_info.ps++;
	if (asm_info.bs>asm_info.bin_size){
		asm_info.bin_size = asm_info.bs;
	}
}

void encOut16(u16 data) {
	if (asm_info.phase_two){
		asm_info.bin[asm_info.bs] = (data)&0xFF;
		asm_info.bin[asm_info.bs+1] = (data>>8)&0xFF;
	}
	asm_info.bs += 2;
	asm_info.ps += 2;
	if (asm_info.bs>asm_info.bin_size){
		asm_info.bin_size = asm_info.bs;
	}
}

void encOut32(u32 data) {
	if (asm_info.phase_two){
		asm_info.bin[asm_info.bs] = (data)&0xFF;
		asm_info.bin[asm_info.bs+1] = (data>>8)&0xFF;
		asm_info.bin[asm_info.bs+2] = (data>>16)&0xFF;
		asm_info.bin[asm_info.bs+3] = (data>>24)&0xFF;
	}
	asm_info.bs += 4;
	asm_info.ps += 4;
	if (asm_info.bs>asm_info.bin_size){
		asm_info.bin_size = asm_info.bs;
	}
}

void encOut64(u64 data) {
	if (asm_info.phase_two){
		asm_info.bin[asm_info.bs] = (data)&0xFF;
		asm_info.bin[asm_info.bs+1] = (data>>8)&0xFF;
		asm_info.bin[asm_info.bs+2] = (data>>16)&0xFF;
		asm_info.bin[asm_info.bs+3] = (data>>24)&0xFF;
		asm_info.bin[asm_info.bs+4] = (data>>32)&0xFF;
		asm_info.bin[asm_info.bs+5] = (data>>40)&0xFF;
		asm_info.bin[asm_info.bs+6] = (data>>48)&0xFF;
		asm_info.bin[asm_info.bs+7] = (data>>56)&0xFF;
	}
	asm_info.bs += 8;
	asm_info.ps += 8;
	if (asm_info.bs>asm_info.bin_size){
		asm_info.bin_size = asm_info.bs;
	}
}

void encInstruction(InstrEncode *enc, Value *args, int sufix) {
	// Instruction composition flags
	bool has_os1 = enc->desc!=NO_DESC, has_os2 = false, has_os3 = false;
	bool has_mem = false;
	int imm_size = 0;
	
	// Instruction composition values
	u8 os1 = 0, os2 = 0, os3 = 0;
	MemAccess *mem = null;
	u64 imm = 0;
	
	// Gathering encode values
	for (int i=0; i<enc->params_len; i++){
		Param *param = &enc->params[i];
		Value *arg = &args[i];
		
		switch (param->encode){
			case ENCODE_REGM:
			case ENCODE_REGM1: {
				os1 = (u8)((os1&0xF0) | (arg->val.code));
				has_os1 = true;
			}
			break;
			case ENCODE_REGO:
			case ENCODE_REGO1:
			case ENCODE_DESC:
			case ENCODE_DESC1: {
				os1 = (u8)((os1&0x0F) | (arg->val.code<<4));
				has_os1 = true;
			}
			break;
			case ENCODE_REGM2: {
				os2 = (u8)((os2&0xF0) | (arg->val.code));
				has_os2 = true;
			}
			break;
			case ENCODE_REGO2:
			case ENCODE_DESC2: {
				os2 = (u8)((os2&0x0F) | (arg->val.code<<4));
				has_os2 = true;
			}
			break;
			case ENCODE_REGM3: {
				os3 = (u8)((os3&0xF0) | (arg->val.code));
				has_os3 = true;
			}
			break;
			case ENCODE_REGO3:
			case ENCODE_DESC3: {
				os3 = (u8)((os3&0x0F) | (arg->val.code<<4));
				has_os3 = true;
			}
			break;
			case ENCODE_MEM: {
				mem = &arg->mem;
				has_mem = true;
			}
			break;
			case ENCODE_MV8: {
				imm = arg->val.lit&0xFF;
				imm_size = 1;
			}
			break;
			case ENCODE_MV16: {
				imm = arg->val.lit&0xFFFF;
				imm_size = 2;
			}
			break;
			case ENCODE_MV32: {
				imm = arg->val.lit&0xFFFFFFFF;
				imm_size = 4;
			}
			break;
			case ENCODE_MV64: {
				imm = arg->val.lit;
				imm_size = 8;
			}
			break;
			default: {}
		}
	}
	
	// Encoding opcode
	encOut8(enc->opcode);
	
	// Encoding operands
	if (has_os1){
		if (enc->desc != NO_DESC){
			os1 = (os1&0x0F) | (enc->desc<<4);
		}
		if (enc->desc == COND_DESC || enc->desc == CONDO_DESC){
			os1 = (os1&0x0F) | (sufix<<4);
		}
		encOut8(os1);
	}
	if (has_os2){
		encOut8(os2);
	}
	if (has_os3){
		encOut8(os3);
	}
	
	// Encoding memory
	if (has_mem){
		bool has_na = mem->mode >= ADRM_IDXI;
		int mv_size = 0;
		
		if (mem->mode == ADRM_DYNI){
			mv_size = 2;
		}
		else if (mem->mode >= ADRM_STC8){
			mv_size = 1<<(mem->mode-ADRM_STC8);
		}
		else {
			if ((mem->mode&3)!=3){
				mv_size = 1<<(mem->mode&3);
			}
		}
		
		encOut8(mem->regi | (mem->mode<<4));
		if (has_na){
			encOut8(mem->reg1 | (mem->reg2<<4));
		}
		if (mv_size==1){
			encOut8(mem->nv);
		}
		if (mv_size==2){
			encOut16(mem->nv);
		}
		if (mv_size==4){
			encOut32(mem->nv);
		}
	}
	
	// Encoding immediate
	if (imm_size==1){
		encOut8((u8)imm);
	}
	if (imm_size==2){
		encOut16((u16)imm);
	}
	if (imm_size==4){
		encOut32((u32)imm);
	}
	if (imm_size==8){
		encOut64(imm);
	}
}


