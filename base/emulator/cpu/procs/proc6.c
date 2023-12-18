#include "procedures.h"


cpuInterr proc60(Cpu *cpu_s){
	// Instruction: lea r8:regm, r32:rego
	cpuFetchOS();
	uint32 ea = cpuReadReg32(cpu_s->os_rego);
	cpuReadMem32(ea);
	cpuReadMem8(cpu_s->data);
	cpuWriteReg8(cpu_s->os_regm, cpu_s->data);
	return 0;
}

cpuInterr proc61(Cpu *cpu_s){
	// Instruction: lea r16:regm, r32:rego
	cpuFetchOS();
	uint32 ea = cpuReadReg32(cpu_s->os_rego);
	cpuReadMem32(ea);
	cpuReadMem16(cpu_s->data);
	cpuWriteReg16(cpu_s->os_regm, cpu_s->data);
	return 0;
}

cpuInterr proc62(Cpu *cpu_s){
	// Instruction: lea r32:regm, r32:rego
	cpuFetchOS();
	uint32 ea = cpuReadReg32(cpu_s->os_rego);
	cpuReadMem32(ea);
	cpuReadMem32(cpu_s->data);
	cpuWriteReg32(cpu_s->os_regm, cpu_s->data);
	return 0;
}

cpuInterr proc63(Cpu *cpu_s){
	cpuFetchOS();
	cpuFetchMemIndex();

	switch (cpu_s->os_desc){
		case 0x0:{
			// Instruction: lea r8:regm, mem8
			cpuReadMem32(cpu_s->mem_adr);
			cpuReadMem8(cpu_s->data);
			cpuWriteReg8(cpu_s->os_regm, cpu_s->data);
		}
		break;
		case 0x1:{
			// Instruction: lea r16:regm, mem16
			cpuReadMem32(cpu_s->mem_adr);
			cpuReadMem16(cpu_s->data);
			cpuWriteReg16(cpu_s->os_regm, cpu_s->data);
		}
		break;
		case 0x2:{
			// Instruction: lea r32:regm, mem32
			cpuReadMem32(cpu_s->mem_adr);
			cpuReadMem32(cpu_s->data);
			cpuWriteReg32(cpu_s->os_regm, cpu_s->data);
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

cpuInterr proc64(Cpu *cpu_s){
	// Instruction: lea r8:regm, r32:rego, imm16:MV
	cpuFetchOS();
	cpuFetchMV16();
	uint32 ea = cpuReadReg32(cpu_s->os_rego) + u16ToInt(cpu_s->mv);
	cpuReadMem32(ea);
	cpuReadMem8(cpu_s->data);
	cpuWriteReg8(cpu_s->os_regm, cpu_s->data);
	return 0;
}

cpuInterr proc65(Cpu *cpu_s){
	// Instruction: lea r16:regm, r32:rego, imm16:MV
	cpuFetchOS();
	cpuFetchMV16();
	uint32 ea = cpuReadReg32(cpu_s->os_rego) + u16ToInt(cpu_s->mv);
	cpuReadMem32(ea);
	cpuReadMem16(cpu_s->data);
	cpuWriteReg16(cpu_s->os_regm, cpu_s->data);
	return 0;
}

cpuInterr proc66(Cpu *cpu_s){
	// Instruction: lea r32:regm, r32:rego, imm16:MV
	cpuFetchOS();
	cpuFetchMV16();
	uint32 ea = cpuReadReg32(cpu_s->os_rego) + u16ToInt(cpu_s->mv);
	cpuReadMem32(ea);
	cpuReadMem32(cpu_s->data);
	cpuWriteReg32(cpu_s->os_regm, cpu_s->data);
	return 0;
}

cpuInterr proc67(Cpu *cpu_s){
	// Instruction: lea r8:regm, r32:rego, imm32:MV
	cpuFetchOS();
	cpuFetchMV16();
	uint32 ea = cpuReadReg32(cpu_s->os_rego) + u32ToInt(cpu_s->mv);
	cpuReadMem32(ea);
	cpuReadMem32(cpu_s->data);
	cpuWriteReg32(cpu_s->os_regm, cpu_s->data);
	return 0;
}

cpuInterr proc68(Cpu *cpu_s){
	// Instruction: sea r32:rego, r8:regm
	cpuFetchOS();
	uint32 ea = cpuReadReg32(cpu_s->os_rego);
	cpuReadMem32(ea);
	cpuWriteMem8(cpu_s->data, cpuReadReg8(cpu_s->os_regm));
	return 0;
}

cpuInterr proc69(Cpu *cpu_s){
	// Instruction: sea r32:rego, r16:regm
	cpuFetchOS();
	uint32 ea = cpuReadReg32(cpu_s->os_rego);
	cpuReadMem32(ea);
	cpuWriteMem16(cpu_s->data, cpuReadReg16(cpu_s->os_regm));
	return 0;
}

cpuInterr proc6A(Cpu *cpu_s){
	// Instruction: sea r32:rego, r32:regm
	cpuFetchOS();
	uint32 ea = cpuReadReg32(cpu_s->os_rego);
	cpuReadMem32(ea);
	cpuWriteMem32(cpu_s->data, cpuReadReg32(cpu_s->os_regm));
	return 0;
}

cpuInterr proc6B(Cpu *cpu_s){
	cpuFetchOS();
	cpuFetchMemIndex();

	switch (cpu_s->os_desc){
		case 0x0:{
			// Instruction: sea r8:regm, mem8
			cpuReadMem32(cpu_s->mem_adr);
			cpuWriteMem8(cpu_s->data, cpuReadReg8(cpu_s->os_regm));
		}
		break;
		case 0x1:{
			// Instruction: sea r16:regm, mem16
			cpuReadMem32(cpu_s->mem_adr);
			cpuWriteMem16(cpu_s->data, cpuReadReg16(cpu_s->os_regm));
		}
		break;
		case 0x2:{
			// Instruction: sea r32:regm, mem32
			cpuReadMem32(cpu_s->mem_adr);
			cpuWriteMem32(cpu_s->data, cpuReadReg32(cpu_s->os_regm));
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

cpuInterr proc6C(Cpu *cpu_s){
	// Instruction: sea r32:rego, imm16:MV, r8:regm
	cpuFetchOS();
	cpuFetchMV16();
	uint32 ea = cpuReadReg32(cpu_s->os_rego) + u16ToInt(cpu_s->mv);
	cpuReadMem32(ea);
	cpuWriteMem8(cpu_s->data, cpuReadReg8(cpu_s->os_regm));
	return 0;
}

cpuInterr proc6D(Cpu *cpu_s){
	// Instruction: sea r32:rego, imm16:MV, r16:regm
	cpuFetchOS();
	cpuFetchMV16();
	uint32 ea = cpuReadReg32(cpu_s->os_rego) + u16ToInt(cpu_s->mv);
	cpuReadMem32(ea);
	cpuWriteMem16(cpu_s->data, cpuReadReg16(cpu_s->os_regm));
	return 0;
}

cpuInterr proc6E(Cpu *cpu_s){
	// Instruction: sea r32:rego, imm16:MV, r32:regm
	cpuFetchOS();
	cpuFetchMV16();
	uint32 ea = cpuReadReg32(cpu_s->os_rego) + u16ToInt(cpu_s->mv);
	cpuReadMem32(ea);
	cpuWriteMem32(cpu_s->data, cpuReadReg32(cpu_s->os_regm));
	return 0;
}

cpuInterr proc6F(Cpu *cpu_s){
	// Instruction: sea r32:rego, imm32:MV, r32:regm
	cpuFetchOS();
	cpuFetchMV32();
	uint32 ea = cpuReadReg32(cpu_s->os_rego) + u32ToInt(cpu_s->mv);
	cpuReadMem32(ea);
	cpuWriteMem32(cpu_s->data, cpuReadReg32(cpu_s->os_regm));
	return 0;
}

