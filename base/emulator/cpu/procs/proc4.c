#include "procedures.h"


cpuInterr proc44(Cpu *cpu_s){
	cpuFetchOS();

	switch (cpu_s->os_desc){
		case 0x0: {
			// Instruction: mveq r8:regm1, imm8:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV8();
			if (cpuReadReg32(cpu_s->os_regm)==cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg8(dest, cpu_s->mv);
			}
		}
		break;
		case 0x1: {
			// Instruction: mvne r8:regm1, imm8:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV8();
			if (cpuReadReg32(cpu_s->os_regm)!=cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg8(dest, cpu_s->mv);
			}
		}
		break;
		case 0x2: {
			// Instruction: mvgt r8:regm1, imm8:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV8();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))>u32ToInt(cpuReadReg32(cpu_s->os_rego))){
				cpuWriteReg8(dest, cpu_s->mv);
			}
		}
		break;
		case 0x3: {
			// Instruction: mvlt r8:regm1, imm8:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV8();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))<u32ToInt(cpuReadReg32(cpu_s->os_rego))){
				cpuWriteReg8(dest, cpu_s->mv);
			}
		}
		break;
		case 0x4: {
			// Instruction: mvge r8:regm1, imm8:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV8();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))>=u32ToInt(cpuReadReg32(cpu_s->os_rego))){
				cpuWriteReg8(dest, cpu_s->mv);
			}
		}
		break;
		case 0x5: {
			// Instruction: mvle r8:regm1, imm8:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV8();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))<=u32ToInt(cpuReadReg32(cpu_s->os_rego))){
				cpuWriteReg8(dest, cpu_s->mv);
			}
		}
		break;
		case 0x6: {
			// Instruction: mvab r8:regm1, imm8:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV8();
			if (cpuReadReg32(cpu_s->os_regm)>cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg8(dest, cpu_s->mv);
			}
		}
		break;
		case 0x7: {
			// Instruction: mvbl r8:regm1, imm8:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV8();
			if (cpuReadReg32(cpu_s->os_regm)<cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg8(dest, cpu_s->mv);
			}
		}
		break;
		case 0x8: {
			// Instruction: mvae r8:regm1, imm8:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV8();
			if (cpuReadReg32(cpu_s->os_regm)>=cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg8(dest, cpu_s->mv);
			}
		}
		break;
		case 0x9: {
			// Instruction: mvbe r8:regm1, imm8:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV8();
			if (cpuReadReg32(cpu_s->os_regm)<=cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg8(dest, cpu_s->mv);
			}
		}
		break;
		case 0xA: {
			// Instruction: mveqz r8:regm1, imm8:MV, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV8();
			if (cpuReadReg32(cpu_s->os_regm)==0){
				cpuWriteReg8(dest, cpu_s->mv);
			}
		}
		break;
		case 0xB: {
			// Instruction: mvnez r8:regm1, imm8:MV, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV8();
			if (cpuReadReg32(cpu_s->os_regm)!=0){
				cpuWriteReg8(dest, cpu_s->mv);
			}
		}
		break;
		case 0xC: {
			// Instruction: mvgtz r8:regm1, imm8:MV, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV8();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))>0){
				cpuWriteReg8(dest, cpu_s->mv);
			}
		}
		break;
		case 0xD: {
			// Instruction: mvltz r8:regm1, imm8:MV, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV8();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))<0){
				cpuWriteReg8(dest, cpu_s->mv);
			}
		}
		break;
		case 0xE: {
			// Instruction: mvgez r8:regm1, imm8:MV, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV8();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))>=0){
				cpuWriteReg8(dest, cpu_s->mv);
			}
		}
		break;
		case 0xF: {
			// Instruction: mvlez r8:regm1, imm8:MV, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV8();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))<=0){
				cpuWriteReg8(dest, cpu_s->mv);
			}
		}
		break;
		default: {
			cpu_s->iregs[0] = cpu_s->reg_lpc;
			cpu_s->iregs[1] = cpu_s->opcode;
			cpu_s->iregs[2] = cpu_s->os_desc;
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr proc45(Cpu *cpu_s){
	cpuFetchOS();

	switch (cpu_s->os_desc){
		case 0x0: {
			// Instruction: mveq r16:regm1, imm16:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV16();
			if (cpuReadReg32(cpu_s->os_regm)==cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg16(dest, cpu_s->mv);
			}
		}
		break;
		case 0x1: {
			// Instruction: mvne r16:regm1, imm16:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV16();
			if (cpuReadReg32(cpu_s->os_regm)!=cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg16(dest, cpu_s->mv);
			}
		}
		break;
		case 0x2: {
			// Instruction: mvgt r16:regm1, imm16:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV16();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))>u32ToInt(cpuReadReg32(cpu_s->os_rego))){
				cpuWriteReg16(dest, cpu_s->mv);
			}
		}
		break;
		case 0x3: {
			// Instruction: mvlt r16:regm1, imm16:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV16();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))<u32ToInt(cpuReadReg32(cpu_s->os_rego))){
				cpuWriteReg16(dest, cpu_s->mv);
			}
		}
		break;
		case 0x4: {
			// Instruction: mvge r16:regm1, imm16:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV16();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))>=u32ToInt(cpuReadReg32(cpu_s->os_rego))){
				cpuWriteReg16(dest, cpu_s->mv);
			}
		}
		break;
		case 0x5: {
			// Instruction: mvle r16:regm1, imm16:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV16();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))<=u32ToInt(cpuReadReg32(cpu_s->os_rego))){
				cpuWriteReg16(dest, cpu_s->mv);
			}
		}
		break;
		case 0x6: {
			// Instruction: mvab r16:regm1, imm16:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV16();
			if (cpuReadReg32(cpu_s->os_regm)>cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg16(dest, cpu_s->mv);
			}
		}
		break;
		case 0x7: {
			// Instruction: mvbl r16:regm1, imm16:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV16();
			if (cpuReadReg32(cpu_s->os_regm)<cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg16(dest, cpu_s->mv);
			}
		}
		break;
		case 0x8: {
			// Instruction: mvae r16:regm1, imm16:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV16();
			if (cpuReadReg32(cpu_s->os_regm)>=cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg16(dest, cpu_s->mv);
			}
		}
		break;
		case 0x9: {
			// Instruction: mvbe r16:regm1, imm16:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV16();
			if (cpuReadReg32(cpu_s->os_regm)<=cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg16(dest, cpu_s->mv);
			}
		}
		break;
		case 0xA: {
			// Instruction: mveqz r16:regm1, imm16:MV, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV16();
			if (cpuReadReg32(cpu_s->os_regm)==0){
				cpuWriteReg16(dest, cpu_s->mv);
			}
		}
		break;
		case 0xB: {
			// Instruction: mvnez r16:regm1, imm16:MV, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV16();
			if (cpuReadReg32(cpu_s->os_regm)!=0){
				cpuWriteReg16(dest, cpu_s->mv);
			}
		}
		break;
		case 0xC: {
			// Instruction: mvgtz r16:regm1, imm16:MV, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV16();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))>0){
				cpuWriteReg16(dest, cpu_s->mv);
			}
		}
		break;
		case 0xD: {
			// Instruction: mvltz r16:regm1, imm16:MV, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV16();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))<0){
				cpuWriteReg16(dest, cpu_s->mv);
			}
		}
		break;
		case 0xE: {
			// Instruction: mvgez r16:regm1, imm16:MV, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV16();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))>=0){
				cpuWriteReg16(dest, cpu_s->mv);
			}
		}
		break;
		case 0xF: {
			// Instruction: mvlez r16:regm1, imm16:MV, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV16();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))<=0){
				cpuWriteReg16(dest, cpu_s->mv);
			}
		}
		break;
		default: {
			cpu_s->iregs[0] = cpu_s->reg_lpc;
			cpu_s->iregs[1] = cpu_s->opcode;
			cpu_s->iregs[2] = cpu_s->os_desc;
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr proc46(Cpu *cpu_s){
	cpuFetchOS();

	switch (cpu_s->os_desc){
		case 0x0: {
			// Instruction: mveq r32:regm1, imm32:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV32();
			if (cpuReadReg32(cpu_s->os_regm)==cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg32(dest, cpu_s->mv);
			}
		}
		break;
		case 0x1: {
			// Instruction: mvne r32:regm1, imm32:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV32();
			if (cpuReadReg32(cpu_s->os_regm)!=cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg32(dest, cpu_s->mv);
			}
		}
		break;
		case 0x2: {
			// Instruction: mvgt r32:regm1, imm32:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV32();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))>u32ToInt(cpuReadReg32(cpu_s->os_rego))){
				cpuWriteReg32(dest, cpu_s->mv);
			}
		}
		break;
		case 0x3: {
			// Instruction: mvlt r32:regm1, imm32:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV32();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))<u32ToInt(cpuReadReg32(cpu_s->os_rego))){
				cpuWriteReg32(dest, cpu_s->mv);
			}
		}
		break;
		case 0x4: {
			// Instruction: mvge r32:regm1, imm32:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV32();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))>=u32ToInt(cpuReadReg32(cpu_s->os_rego))){
				cpuWriteReg32(dest, cpu_s->mv);
			}
		}
		break;
		case 0x5: {
			// Instruction: mvle r32:regm1, imm32:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV32();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))<=u32ToInt(cpuReadReg32(cpu_s->os_rego))){
				cpuWriteReg32(dest, cpu_s->mv);
			}
		}
		break;
		case 0x6: {
			// Instruction: mvab r32:regm1, imm32:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV32();
			if (cpuReadReg32(cpu_s->os_regm)>cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg32(dest, cpu_s->mv);
			}
		}
		break;
		case 0x7: {
			// Instruction: mvbl r32:regm1, imm32:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV32();
			if (cpuReadReg32(cpu_s->os_regm)<cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg32(dest, cpu_s->mv);
			}
		}
		break;
		case 0x8: {
			// Instruction: mvae r32:regm1, imm32:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV32();
			if (cpuReadReg32(cpu_s->os_regm)>=cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg32(dest, cpu_s->mv);
			}
		}
		break;
		case 0x9: {
			// Instruction: mvbe r32:regm1, imm32:MV, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV32();
			if (cpuReadReg32(cpu_s->os_regm)<=cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg32(dest, cpu_s->mv);
			}
		}
		break;
		case 0xA: {
			// Instruction: mveqz r32:regm1, imm32:MV, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV32();
			if (cpuReadReg32(cpu_s->os_regm)==0){
				cpuWriteReg32(dest, cpu_s->mv);
			}
		}
		break;
		case 0xB: {
			// Instruction: mvnez r32:regm1, imm32:MV, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV32();
			if (cpuReadReg32(cpu_s->os_regm)!=0){
				cpuWriteReg32(dest, cpu_s->mv);
			}
		}
		break;
		case 0xC: {
			// Instruction: mvgtz r32:regm1, imm32:MV, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV32();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))>0){
				cpuWriteReg32(dest, cpu_s->mv);
			}
		}
		break;
		case 0xD: {
			// Instruction: mvltz r32:regm1, imm32:MV, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV32();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))<0){
				cpuWriteReg32(dest, cpu_s->mv);
			}
		}
		break;
		case 0xE: {
			// Instruction: mvgez r32:regm1, imm32:MV, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV32();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))>=0){
				cpuWriteReg32(dest, cpu_s->mv);
			}
		}
		break;
		case 0xF: {
			// Instruction: mvlez r32:regm1, imm32:MV, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			cpuFetchMV32();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))<=0){
				cpuWriteReg32(dest, cpu_s->mv);
			}
		}
		break;
		default: {
			cpu_s->iregs[0] = cpu_s->reg_lpc;
			cpu_s->iregs[1] = cpu_s->opcode;
			cpu_s->iregs[2] = cpu_s->os_desc;
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr proc48(Cpu *cpu_s){
	// Instruction: cvbtw r32:regm, r8:rego
	cpuFetchOS();
	sint32 data = u8ToInt(cpuReadReg8(cpu_s->os_rego));
	cpuWriteReg32(cpu_s->os_regm, (uint32)data);
	return 0;
}

cpuInterr proc49(Cpu *cpu_s){
	cpuFetchOS();

	if (cpu_s->os_desc==0x00){
		// Instruction: cvbtw r32:regm, imm8:MV
		cpuFetchMV8();
		sint32 data = u8ToInt(cpu_s->mv);
		cpuWriteReg32(cpu_s->os_regm, (uint32)data);
	}
	else if (cpu_s->os_desc==0x01){
		// Instruction: cvbtw r32:regm, mem8
		cpuFetchMemIndex();
		cpuReadMem8(cpu_s->mem_adr);
		sint32 data = u8ToInt(cpu_s->data);
		cpuWriteReg32(cpu_s->os_regm, (uint32)data);
	}
	else {
		cpu_s->iregs[0] = cpu_s->reg_lpc;
		cpu_s->iregs[1] = cpu_s->opcode;
		cpu_s->iregs[2] = cpu_s->os_desc;
		cpuThrowInterruption(INTR_INVALID_OPCODE);
	}
	return 0;
}

cpuInterr proc4A(Cpu *cpu_s){
	// Instruction: cvhtw r32:regm, r16:rego
	cpuFetchOS();
	sint32 data = u16ToInt(cpuReadReg16(cpu_s->os_rego));
	cpuWriteReg32(cpu_s->os_regm, (uint32)data);
	return 0;
}

cpuInterr proc4B(Cpu *cpu_s){
	cpuFetchOS();

	if (cpu_s->os_desc==0x00){
		// Instruction: cvbtw r32:regm, imm16:MV
		cpuFetchMV16();
		sint32 data = u16ToInt(cpu_s->mv);
		cpuWriteReg32(cpu_s->os_regm, (uint32)data);
	}
	else if (cpu_s->os_desc==0x01){
		// Instruction: cvbtw r32:regm, mem16
		cpuFetchMemIndex();
		cpuReadMem16(cpu_s->mem_adr);
		sint32 data = u16ToInt(cpu_s->data);
		cpuWriteReg32(cpu_s->os_regm, (uint32)data);
	}
	else {
		cpu_s->iregs[0] = cpu_s->reg_lpc;
		cpu_s->iregs[1] = cpu_s->opcode;
		cpu_s->iregs[2] = cpu_s->os_desc;
		cpuThrowInterruption(INTR_INVALID_OPCODE);
	}
	return 0;
}

cpuInterr proc4C(Cpu *cpu_s){
	// Instruction: cvbth r16:regm, r8:rego
	cpuFetchOS();
	sint16 data = u8ToInt(cpuReadReg8(cpu_s->os_rego));
	cpuWriteReg16(cpu_s->os_regm, (uint16)data);
	return 0;
}

cpuInterr proc4D(Cpu *cpu_s){
	cpuFetchOS();

	if (cpu_s->os_desc==0x00){
		// Instruction: cvbtw r16:regm, imm32:MV
		cpuFetchMV8();
		sint32 data = u8ToInt(cpu_s->mv);
		cpuWriteReg16(cpu_s->os_regm, (uint32)data);
	}
	else if (cpu_s->os_desc==0x01){
		// Instruction: cvbtw r16:regm, mem8
		cpuFetchMemIndex();
		cpuReadMem8(cpu_s->mem_adr);
		sint32 data = u8ToInt(cpu_s->data);
		cpuWriteReg16(cpu_s->os_regm, (uint32)data);
	}
	else {
		cpu_s->iregs[0] = cpu_s->reg_lpc;
		cpu_s->iregs[1] = cpu_s->opcode;
		cpu_s->iregs[2] = cpu_s->os_desc;
		cpuThrowInterruption(INTR_INVALID_OPCODE);
	}
	return 0;
}

cpuInterr proc4F(Cpu *cpu_s){
	cpuFetchOS();

	switch (cpu_s->os_desc){
		case 0x0: {
			// Instruction: steq r32:regm1, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			if (cpuReadReg32(cpu_s->os_regm)==cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0x1: {
			// Instruction: stne r32:regm1, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			if (cpuReadReg32(cpu_s->os_regm)!=cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0x2: {
			// Instruction: stgt r32:regm1, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))>u32ToInt(cpuReadReg32(cpu_s->os_rego))){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0x3: {
			// Instruction: stlt r32:regm1, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))<u32ToInt(cpuReadReg32(cpu_s->os_rego))){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0x4: {
			// Instruction: stge r32:regm1, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))>=u32ToInt(cpuReadReg32(cpu_s->os_rego))){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0x5: {
			// Instruction: stle r32:regm1, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))<=u32ToInt(cpuReadReg32(cpu_s->os_rego))){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0x6: {
			// Instruction: stab r32:regm1, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			if (cpuReadReg32(cpu_s->os_regm)>cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0x7: {
			// Instruction: stbl r32:regm1, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			if (cpuReadReg32(cpu_s->os_regm)<cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0x8: {
			// Instruction: stae r32:regm1, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			if (cpuReadReg32(cpu_s->os_regm)>=cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0x9: {
			// Instruction: stbe r32:regm1, r32:regm2, r32:rego2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			if (cpuReadReg32(cpu_s->os_regm)<=cpuReadReg32(cpu_s->os_rego)){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0xA: {
			// Instruction: steqz r32:regm1, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			if (cpuReadReg32(cpu_s->os_regm)==0){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0xB: {
			// Instruction: stnez r32:regm1, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			if (cpuReadReg32(cpu_s->os_regm)!=0){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0xC: {
			// Instruction: stgtz r32:regm1, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))>0){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0xD: {
			// Instruction: stltz r32:regm1, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))<0){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0xE: {
			// Instruction: stgez r32:regm1, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))>=0){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0xF: {
			// Instruction: stlez r32:regm1, r32:regm2
			uint8 dest = cpu_s->os_regm;
			cpuFetchOS();
			if (u32ToInt(cpuReadReg32(cpu_s->os_regm))<=0){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		default: {
			cpu_s->iregs[0] = cpu_s->reg_lpc;
			cpu_s->iregs[1] = cpu_s->opcode;
			cpu_s->iregs[2] = cpu_s->os_desc;
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

