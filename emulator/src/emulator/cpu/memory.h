#ifndef EMU_CPU_MEMORY_H
#define EMU_CPU_MEMORY_H

#include "interruption.h"
#include "../bus.h"


/*
	Memory Address Translation
*/

/*
	Memory Access and Code Fetching
*/

// Memory Data Access by Address
cpuInterr _cpuReadMem8(uint32 adr);
#define cpuReadMem8(adr) {cpuTryExecute(_cpuReadMem8(adr))}

cpuInterr _cpuWriteMem8(uint32 adr, uint8 data);
#define cpuWriteMem8(adr, data) {cpuTryExecute(_cpuWriteMem8(adr, data))}

cpuInterr _cpuReadMem16(uint32 adr);
#define cpuReadMem16(adr) {cpuTryExecute(_cpuReadMem16(adr))}

cpuInterr _cpuWriteMem16(uint32 adr, uint16 data);
#define cpuWriteMem16(adr, data) {cpuTryExecute(_cpuWriteMem16(adr, data))}

cpuInterr _cpuReadMem32(uint32 adr);
#define cpuReadMem32(adr) {cpuTryExecute(_cpuReadMem32(adr))}

cpuInterr _cpuWriteMem32(uint32 adr, uint32 data);
#define cpuWriteMem32(adr, data) {cpuTryExecute(_cpuWriteMem32(adr, data))}

// Memory Stack Access
cpuInterr _cpuPop8();
#define cpuPop8() {cpuTryExecute(_cpuPop8())}

cpuInterr _cpuPush8(uint8 data);
#define cpuPush8(data) {cpuTryExecute(_cpuPush8(data))}

cpuInterr _cpuPop16();
#define cpuPop16() {cpuTryExecute(_cpuPop16())}

cpuInterr _cpuPush16(uint16 data);
#define cpuPush16(data) {cpuTryExecute(_cpuPush16(data))}

cpuInterr _cpuPop32();
#define cpuPop32() {cpuTryExecute(_cpuPop32())}

cpuInterr _cpuPush32(uint32 data);
#define cpuPush32(data) {cpuTryExecute(_cpuPush32(data))}

// Memory Code Access
cpuInterr _cpuFetch8();
#define cpuFetch8() {cpuTryExecute(_cpuFetch8())}

cpuInterr _cpuFetch16();
#define cpuFetch16() {cpuTryExecute(_cpuFetch16())}

cpuInterr _cpuFetch32();
#define cpuFetch32() {cpuTryExecute(_cpuFetch32())}

/*
	Code Speciallized Access
*/
// Fetch Instruction Opcode
cpuInterr _cpuFetchOpcode();
#define cpuFetchOpcode() _cpuFetchOpcode()

// Fetch Operand Specifier
cpuInterr _cpuFetchOS();
#define cpuFetchOS() {cpuTryExecute(_cpuFetchOS())}

// Fetch Index Specifier, Additional and Value for Memory Access
cpuInterr _cpuFetchMemIndex();
#define cpuFetchMemIndex() {cpuTryExecute(_cpuFetchMemIndex())}

// Fetch Immediate Value
cpuInterr _cpuFetchMV8();
#define cpuFetchMV8() {cpuTryExecute(_cpuFetchMV8())}

cpuInterr _cpuFetchMV16();
#define cpuFetchMV16() {cpuTryExecute(_cpuFetchMV16())}

cpuInterr _cpuFetchMV32();
#define cpuFetchMV32() {cpuTryExecute(_cpuFetchMV32())}


#endif