#ifndef EMU_CPU_MEMORY_H
#define EMU_CPU_MEMORY_H

#include "interruption.h"
#include "../bus.h"


/*
	Memory Address Translation
*/

#define SEG_ENABLED 0x01
#define SEG_READABLE 0x02
#define SEG_WRITEABLE 0x04
#define SEG_EXECUTABLE 0x08
#define SEG_PROTECTED 0x10
#define SEG_SCALE 0x40
#define SEG_APPEND 0x80

#define PAG_ENABLED 0x01
#define PAG_READABLE 0x02
#define PAG_WRITEABLE 0x04
#define PAG_EXECUTABLE 0x08
#define PAG_PROTECTED 0x10

/*
	Memory Access and Code Fetching
*/

// Memory Data Access by Address
#define cpuReadBus8(adr) (cpu_s->busRead(adr))
#define cpuWriteBus8(adr, data) {cpu_s->busWrite(adr, data);}
#define cpuReadBus16(adr) ((cpu_s->busRead(adr))|(cpu_s->busRead(adr+1)<<8))
#define cpuWriteBus16(adr, data) {cpu_s->busWrite(adr, (data)&0xFF); cpu_s->busWrite(adr+1, (data>>8)&0xFF);}
#define cpuReadBus32(adr) ((cpu_s->busRead(adr))|(cpu_s->busRead(adr+1)<<8)|(cpu_s->busRead(adr+2)<<16)|(cpu_s->busRead(adr+3)<<24))
#define cpuWriteBus32(adr, data) {cpu_s->busWrite(adr, (data)&0xFF); cpu_s->busWrite(adr+1, (data>>8)&0xFF); cpu_s->busWrite(adr+2, (data>>16)&0xFF); cpu_s->busWrite(adr+3, (data>>24)&0xFF);}

extern cpuInterr _cpuReadMem8(Cpu *cpu_s, uint32 adr);
#define cpuReadMem8(adr) {cpuTryExecute(_cpuReadMem8(cpu_s, adr))}

extern cpuInterr _cpuWriteMem8(Cpu *cpu_s, uint32 adr, uint8 data);
#define cpuWriteMem8(adr, data) {cpuTryExecute(_cpuWriteMem8(cpu_s, adr, data))}

extern cpuInterr _cpuReadMem16(Cpu *cpu_s, uint32 adr);
#define cpuReadMem16(adr) {cpuTryExecute(_cpuReadMem16(cpu_s, adr))}

extern cpuInterr _cpuWriteMem16(Cpu *cpu_s, uint32 adr, uint16 data);
#define cpuWriteMem16(adr, data) {cpuTryExecute(_cpuWriteMem16(cpu_s, adr, data))}

extern cpuInterr _cpuReadMem32(Cpu *cpu_s, uint32 adr);
#define cpuReadMem32(adr) {cpuTryExecute(_cpuReadMem32(cpu_s, adr))}

extern cpuInterr _cpuWriteMem32(Cpu *cpu_s, uint32 adr, uint32 data);
#define cpuWriteMem32(adr, data) {cpuTryExecute(_cpuWriteMem32(cpu_s, adr, data))}

// Memory Stack Access
extern cpuInterr _cpuPop8(Cpu *cpu_s);
#define cpuPop8() {cpuTryExecute(_cpuPop8(cpu_s))}

extern cpuInterr _cpuPush8(Cpu *cpu_s, uint8 data);
#define cpuPush8(data) {cpuTryExecute(_cpuPush8(cpu_s, data))}

extern cpuInterr _cpuPop16(Cpu *cpu_s);
#define cpuPop16() {cpuTryExecute(_cpuPop16(cpu_s))}

extern cpuInterr _cpuPush16(Cpu *cpu_s, uint16 data);
#define cpuPush16(data) {cpuTryExecute(_cpuPush16(cpu_s, data))}

extern cpuInterr _cpuPop32(Cpu *cpu_s);
#define cpuPop32() {cpuTryExecute(_cpuPop32(cpu_s))}

extern cpuInterr _cpuPush32(Cpu *cpu_s, uint32 data);
#define cpuPush32(data) {cpuTryExecute(_cpuPush32(cpu_s, data))}

// Memory Code Access
extern cpuInterr _cpuFetch8(Cpu *cpu_s);
#define cpuFetch8() {cpuTryExecute(_cpuFetch8(cpu_s))}

extern cpuInterr _cpuFetch16(Cpu *cpu_s);
#define cpuFetch16() {cpuTryExecute(_cpuFetch16(cpu_s))}

extern cpuInterr _cpuFetch32(Cpu *cpu_s);
#define cpuFetch32() {cpuTryExecute(_cpuFetch32(cpu_s))}

/*
	Code Speciallized Access
*/
// Fetch Instruction Opcode
extern cpuInterr _cpuFetchOpcode(Cpu *cpu_s);
#define cpuFetchOpcode() _cpuFetchOpcode(cpu_s)

// Fetch Operand Specifier
extern cpuInterr _cpuFetchOS(Cpu *cpu_s);
#define cpuFetchOS() {cpuTryExecute(_cpuFetchOS(cpu_s))}

// Fetch Index Specifier, Additional and Value for Memory Access
extern cpuInterr _cpuFetchMemIndex(Cpu *cpu_s);
#define cpuFetchMemIndex() {cpuTryExecute(_cpuFetchMemIndex(cpu_s))}

// Fetch Immediate Value
extern cpuInterr _cpuFetchMV8(Cpu *cpu_s);
#define cpuFetchMV8() {cpuTryExecute(_cpuFetchMV8(cpu_s))}

extern cpuInterr _cpuFetchMV16(Cpu *cpu_s);
#define cpuFetchMV16() {cpuTryExecute(_cpuFetchMV16(cpu_s))}

extern cpuInterr _cpuFetchMV32(Cpu *cpu_s);
#define cpuFetchMV32() {cpuTryExecute(_cpuFetchMV32(cpu_s))}


#endif