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
#define cpuReadBus8(adr) (busRead8(adr))
#define cpuWriteBus8(adr, data) {busWrite8(adr, data);}
#define cpuReadBus16(adr) ((busRead8(adr))|(busRead8(adr+1)<<8))
#define cpuWriteBus16(adr, data) {busWrite8(adr, (data)&0xFF); busWrite8(adr+1, (data>>8)&0xFF);}
#define cpuReadBus32(adr) ((busRead8(adr))|(busRead8(adr+1)<<8)|(busRead8(adr+2)<<16)|(busRead8(adr+3)<<24))
#define cpuWriteBus32(adr, data) {busWrite8(adr, (data)&0xFF); busWrite8(adr+1, (data>>8)&0xFF); busWrite8(adr+2, (data>>16)&0xFF); busWrite8(adr+3, (data>>24)&0xFF);}

extern cpuInterr _cpuReadMem8(uint32 adr);
#define cpuReadMem8(adr) {cpuTryExecute(_cpuReadMem8(adr))}

extern cpuInterr _cpuWriteMem8(uint32 adr, uint8 data);
#define cpuWriteMem8(adr, data) {cpuTryExecute(_cpuWriteMem8(adr, data))}

extern cpuInterr _cpuReadMem16(uint32 adr);
#define cpuReadMem16(adr) {cpuTryExecute(_cpuReadMem16(adr))}

extern cpuInterr _cpuWriteMem16(uint32 adr, uint16 data);
#define cpuWriteMem16(adr, data) {cpuTryExecute(_cpuWriteMem16(adr, data))}

extern cpuInterr _cpuReadMem32(uint32 adr);
#define cpuReadMem32(adr) {cpuTryExecute(_cpuReadMem32(adr))}

extern cpuInterr _cpuWriteMem32(uint32 adr, uint32 data);
#define cpuWriteMem32(adr, data) {cpuTryExecute(_cpuWriteMem32(adr, data))}

// Memory Stack Access
extern cpuInterr _cpuPop8();
#define cpuPop8() {cpuTryExecute(_cpuPop8())}

extern cpuInterr _cpuPush8(uint8 data);
#define cpuPush8(data) {cpuTryExecute(_cpuPush8(data))}

extern cpuInterr _cpuPop16();
#define cpuPop16() {cpuTryExecute(_cpuPop16())}

extern cpuInterr _cpuPush16(uint16 data);
#define cpuPush16(data) {cpuTryExecute(_cpuPush16(data))}

extern cpuInterr _cpuPop32();
#define cpuPop32() {cpuTryExecute(_cpuPop32())}

extern cpuInterr _cpuPush32(uint32 data);
#define cpuPush32(data) {cpuTryExecute(_cpuPush32(data))}

// Memory Code Access
extern cpuInterr _cpuFetch8();
#define cpuFetch8() {cpuTryExecute(_cpuFetch8())}

extern cpuInterr _cpuFetch16();
#define cpuFetch16() {cpuTryExecute(_cpuFetch16())}

extern cpuInterr _cpuFetch32();
#define cpuFetch32() {cpuTryExecute(_cpuFetch32())}

/*
	Code Speciallized Access
*/
// Fetch Instruction Opcode
extern cpuInterr _cpuFetchOpcode();
#define cpuFetchOpcode() _cpuFetchOpcode()

// Fetch Operand Specifier
extern cpuInterr _cpuFetchOS();
#define cpuFetchOS() {cpuTryExecute(_cpuFetchOS())}

// Fetch Index Specifier, Additional and Value for Memory Access
extern cpuInterr _cpuFetchMemIndex();
#define cpuFetchMemIndex() {cpuTryExecute(_cpuFetchMemIndex())}

// Fetch Immediate Value
extern cpuInterr _cpuFetchMV8();
#define cpuFetchMV8() {cpuTryExecute(_cpuFetchMV8())}

extern cpuInterr _cpuFetchMV16();
#define cpuFetchMV16() {cpuTryExecute(_cpuFetchMV16())}

extern cpuInterr _cpuFetchMV32();
#define cpuFetchMV32() {cpuTryExecute(_cpuFetchMV32())}


#endif