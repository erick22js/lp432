#include "memory.h"



/*
	Memory Address Translation
*/

/*
	Memory Access and Code Fetching
*/

// Memory Data Access by Address
cpuInterr _cpuReadMem8(uint32 adr){
	// TODO: Address translation
	cpu_s.data = busRead8(adr);
	return 0;
}

cpuInterr _cpuWriteMem8(uint32 adr, uint8 data){
	// TODO: Address translation
	busWrite8(adr, data);
	return 0;
}

cpuInterr _cpuReadMem16(uint32 adr){
	// TODO: Address translation
	cpu_s.data = busRead8(adr)|(busRead8(adr+1)<<8);
	return 0;
}

cpuInterr _cpuWriteMem16(uint32 adr, uint16 data){
	// TODO: Address translation
	busWrite8(adr, (data)&0xFF);
	busWrite8(adr+1, (data>>8)&0xFF);
	return 0;
}

cpuInterr _cpuReadMem32(uint32 adr){
	// TODO: Address translation
	cpu_s.data = busRead8(adr)|(busRead8(adr+1)<<8)|(busRead8(adr+2)<<16)|(busRead8(adr+3)<<24);
	return 0;
}

cpuInterr _cpuWriteMem32(uint32 adr, uint32 data){
	// TODO: Address translation
	busWrite8(adr, (data)&0xFF);
	busWrite8(adr+1, (data>>8)&0xFF);
	busWrite8(adr+2, (data>>16)&0xFF);
	busWrite8(adr+3, (data>>24)&0xFF);
	return 0;
}

// Memory Stack Access
cpuInterr _cpuPop8(){
	uint32 adr = cpu_s.gregs[GREG_ESP];
	// TODO: Address translation
	uint8 data = busRead8(adr);
	cpu_s.gregs[GREG_ESP]++;
	cpu_s.data = data;
	return 0;
}

cpuInterr _cpuPush8(uint8 data){
	cpu_s.gregs[GREG_ESP]--;
	uint32 adr = cpu_s.gregs[GREG_ESP];
	// TODO: Address translation
	busWrite8(adr, data);
	return 0;
}

cpuInterr _cpuPop16(){
	uint32 adr = cpu_s.gregs[GREG_ESP];
	// TODO: Address translation
	uint16 data = busRead8(adr)|(busRead8(adr+1)<<8);
	cpu_s.gregs[GREG_ESP] += 2;
	cpu_s.data = data;
	return 0;
}

cpuInterr _cpuPush16(uint16 data){
	cpu_s.gregs[GREG_ESP] -= 2;
	uint32 adr = cpu_s.gregs[GREG_ESP];
	// TODO: Address translation
	busWrite8(adr, (data)&0xFF);
	busWrite8(adr+1, (data>>8)&0xFF);
	return 0;
}

cpuInterr _cpuPop32(){
	uint32 adr = cpu_s.gregs[GREG_ESP];
	// TODO: Address translation
	uint32 data = busRead8(adr)|(busRead8(adr+1)<<8)|(busRead8(adr+2)<<16)|(busRead8(adr+3)<<24);
	cpu_s.gregs[GREG_ESP] += 4;
	cpu_s.data = data;
	return 0;
}

cpuInterr _cpuPush32(uint32 data){
	cpu_s.gregs[GREG_ESP] -= 4;
	uint32 adr = cpu_s.gregs[GREG_ESP];
	// TODO: Address translation
	busWrite8(adr, (data)&0xFF);
	busWrite8(adr+1, (data>>8)&0xFF);
	busWrite8(adr+2, (data>>16)&0xFF);
	busWrite8(adr+3, (data>>24)&0xFF);
	return 0;
}

// Memory Code Access
cpuInterr _cpuFetch8(){
	uint32 adr = cpu_s.reg_pc;
	// TODO: Address translation
	uint8 code = busRead8(adr);
	cpu_s.reg_pc++;
	cpu_s.code = code;
	return 0;
}

cpuInterr _cpuFetch16(){
	uint32 adr = cpu_s.reg_pc;
	// TODO: Address translation
	uint16 code = busRead8(adr)|(busRead8(adr+1)<<8);
	cpu_s.reg_pc += 2;
	cpu_s.code = code;
	return 0;
}

cpuInterr _cpuFetch32(){
	uint32 adr = cpu_s.reg_pc;
	// TODO: Address translation
	uint32 code = busRead8(adr)|(busRead8(adr+1)<<8)|(busRead8(adr+2)<<16)|(busRead8(adr+3)<<24);
	cpu_s.reg_pc += 4;
	cpu_s.code = code;
	return 0;
}

/*
	Code Speciallized Access
*/
// Fetch Instruction Opcode
cpuInterr _cpuFetchOpcode(){
	cpuFetch8();
	cpu_s.opcode = cpu_s.code;
	return 0;
}

// Fetch Operand Specifier
cpuInterr _cpuFetchOS(){
	cpuFetch8();
	uint8 os = cpu_s.code;
	cpu_s.os_regm = os&0xF;
	cpu_s.os_rego = cpu_s.os_desc = (os>>4)&0xF;
	return 0;
}

// Fetch Index Specifier, Additional and Value for Memory Access
cpuInterr _cpuFetchMemIndex(){
	cpuFetch8();
	uint8 ns = cpu_s.code;
	uint8 regi = ns&0xF;
	uint8 adrm = (ns>>4)&0xF;

	// Switching over addrssing mode
	switch (adrm){
		case 0x0:{ // Absolute => [NV:u8]
			cpuFetch8();
			cpu_s.mem_adr = cpu_s.code;
		}
		break;
		case 0x1:{ // Absolute => [NV:u16]
			cpuFetch16();
			cpu_s.mem_adr = cpu_s.code;
		}
		break;
		case 0x2:{ // Absolute => [NV:u32]
			cpuFetch32();
			cpu_s.mem_adr = cpu_s.code;
		}
		break;
		case 0x3:{ // Pointer => [regi:u32]
			cpu_s.mem_adr = cpuReadReg32(regi);
		}
		break;
		case 0x4:{ // Indexed => [regi:u32 + NV:s8]
			cpuFetch8();
			cpu_s.mem_adr = cpuReadReg32(regi) + u8ToInt(cpu_s.code);
		}
		break;
		case 0x5:{ // Indexed => [regi:u32 + NV:s16]
			cpuFetch16();
			cpu_s.mem_adr = cpuReadReg32(regi) + u16ToInt(cpu_s.code);
		}
		break;
		case 0x6:{ // Indexed => [regi:u32 + NV:s32]
			cpuFetch32();
			cpu_s.mem_adr = cpuReadReg32(regi) + u32ToInt(cpu_s.code);
		}
		break;
		case 0x7:{ // Indexed Implicit => [regi:u32 + reg1:s32]
			cpuFetch8();
			uint8 na = cpu_s.code;
			uint8 reg1 = na&0xF;
			cpu_s.mem_adr = cpuReadReg32(regi) + cpuReadReg32(reg1);
		}
		break;
		case 0x8:{ // Indexed Implicit => [regi:u32 + reg1:s32 + NV:s8]
			cpuFetch8();
			uint8 na = cpu_s.code;
			uint8 reg1 = na&0xF;
			cpuFetch8();
			cpu_s.mem_adr = cpuReadReg32(regi) + cpuReadReg32(reg1) + u8ToInt(cpu_s.code);
		}
		break;
		case 0x9:{ // Indexed Implicit => [regi:u32 + reg1:s32 + NV:s16]
			cpuFetch8();
			uint8 na = cpu_s.code;
			uint8 reg1 = na&0xF;
			cpuFetch16();
			cpu_s.mem_adr = cpuReadReg32(regi) + cpuReadReg32(reg1) + u16ToInt(cpu_s.code);
		}
		break;
		case 0xA:{ // Indexed Implicit => [regi:u32 + reg1:s32 + NV:s32]
			cpuFetch8();
			uint8 na = cpu_s.code;
			uint8 reg1 = na&0xF;
			cpuFetch32();
			cpu_s.mem_adr = cpuReadReg32(regi) + cpuReadReg32(reg1) + u32ToInt(cpu_s.code);
		}
		break;
		case 0xB:{ // Dynamic => [regi:u32 + reg1:s32 * reg2:u32]
			cpuFetch8();
			uint8 na = cpu_s.code;
			uint8 reg1 = na&0xF;
			uint8 reg2 = (na>>4)&0xF;
			cpu_s.mem_adr = cpuReadReg32(regi) + u32ToInt(cpuReadReg32(reg1)) * cpuReadReg32(reg2);
		}
		break;
		case 0xC:{ // Dynamic Indexed => [regi:u32 + reg1:s32 * reg2:u32 + NV:s16]
			cpuFetch8();
			uint8 na = cpu_s.code;
			uint8 reg1 = na&0xF;
			uint8 reg2 = (na>>4)&0xF;
			cpuFetch16();
			cpu_s.mem_adr = cpuReadReg32(regi) + u32ToInt(cpuReadReg32(reg1)) * cpuReadReg32(reg2) + u16ToInt(cpu_s.code);
		}
		break;
		case 0xD:{ // Struct => [regi:u32 + reg1:s32 * NV:u8]
			cpuFetch8();
			uint8 na = cpu_s.code;
			uint8 reg1 = na&0xF;
			cpuFetch8();
			cpu_s.mem_adr = cpuReadReg32(regi) + u32ToInt(cpuReadReg32(reg1)) * cpu_s.code;
		}
		break;
		case 0xE:{ // Struct => [regi:u32 + reg1:s32 * NV:u16]
			cpuFetch8();
			uint8 na = cpu_s.code;
			uint8 reg1 = na&0xF;
			cpuFetch16();
			cpu_s.mem_adr = cpuReadReg32(regi) + u32ToInt(cpuReadReg32(reg1)) * cpu_s.code;
		}
		break;
		case 0xF:{ // Struct => [regi:u32 + reg1:s32 * NV:u32]
			cpuFetch8();
			uint8 na = cpu_s.code;
			uint8 reg1 = na&0xF;
			cpuFetch32();
			cpu_s.mem_adr = cpuReadReg32(regi) + u32ToInt(cpuReadReg32(reg1)) * cpu_s.code;
		}
		break;
	}
	return 0;
}

// Fetch Immediate Value
cpuInterr _cpuFetchMV8(){
	cpuFetch8();
	cpu_s.mv = cpu_s.code;
	return 0;
}

cpuInterr _cpuFetchMV16(){
	cpuFetch16();
	cpu_s.mv = cpu_s.code;
	return 0;
}

cpuInterr _cpuFetchMV32(){
	cpuFetch32();
	cpu_s.mv = cpu_s.code;
	return 0;
}
