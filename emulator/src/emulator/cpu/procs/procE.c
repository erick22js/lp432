#include "procedures.h"


#define procInc(v, sign, type) {\
	v++;\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_VF, v==sign);/* Overflow Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_ZF, ((type)v)==0);/* Zero Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_NF, v&sign);/* Negative Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_OF, v&1);/* Odd Flag Affecting */\
}
#define procInc8(v) procInc(v, 0x80, uint8)
#define procInc16(v) procInc(v, 0x8000, uint16)
#define procInc32(v) procInc(v, 0x80000000, uint32)

#define procDec(v, sign, type) {\
	v--;\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_VF, v==(sign-1));/* Overflow Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_ZF, ((type)v)==0);/* Zero Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_NF, v&sign);/* Negative Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_OF, v&1);/* Odd Flag Affecting */\
}
#define procDec8(v) procDec(v, 0x80, uint8)
#define procDec16(v) procDec(v, 0x8000, uint16)
#define procDec32(v) procDec(v, 0x80000000, uint32)

#define procNeg(v, sign, type) {\
	v = -v;\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_ZF, ((type)v)==0);/* Zero Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_NF, v&sign);/* Negative Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_OF, v&1);/* Odd Flag Affecting */\
}
#define procNeg8(v) procNeg(v, 0x80, uint8)
#define procNeg16(v) procNeg(v, 0x8000, uint16)
#define procNeg32(v) procNeg(v, 0x80000000, uint32)

#define procNot(v, sign, type) {\
	v = ~v;\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_ZF, ((type)v)==0);/* Zero Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_NF, v&sign);/* Negative Flag Affecting */\
	cpu_s.reg_st = setBit(cpu_s.reg_st, FLAG_OF, v&1);/* Odd Flag Affecting */\
}
#define procNot8(v) procNot(v, 0x80, uint8)
#define procNot16(v) procNot(v, 0x8000, uint16)
#define procNot32(v) procNot(v, 0x80000000, uint32)

cpuInterr procE0(){
	// Instruction: inc r8:regm
	cpuFetchOS();
	uint8 v = cpuReadReg8(cpu_s.os_regm);
	procInc8(v);
	cpuWriteReg8(cpu_s.os_regm, v);
	return 0;
}

cpuInterr procE1(){
	// Instruction: inc r16:regm
	cpuFetchOS();
	uint16 v = cpuReadReg16(cpu_s.os_regm);
	procInc16(v);
	cpuWriteReg16(cpu_s.os_regm, v);
	return 0;
}

cpuInterr procE2(){
	// Instruction: inc r32:regm
	cpuFetchOS();
	uint32 v = cpuReadReg32(cpu_s.os_regm);
	procInc32(v);
	cpuWriteReg32(cpu_s.os_regm, v);
	return 0;
}

cpuInterr procE4(){
	// Instruction: dec r8:regm
	cpuFetchOS();
	uint8 v = cpuReadReg8(cpu_s.os_regm);
	procDec8(v);
	cpuWriteReg8(cpu_s.os_regm, v);
	return 0;
}

cpuInterr procE5(){
	// Instruction: dec r16:regm
	cpuFetchOS();
	uint16 v = cpuReadReg16(cpu_s.os_regm);
	procDec16(v);
	cpuWriteReg16(cpu_s.os_regm, v);
	return 0;
}

cpuInterr procE6(){
	// Instruction: dec r32:regm
	cpuFetchOS();
	uint32 v = cpuReadReg32(cpu_s.os_regm);
	procDec32(v);
	cpuWriteReg32(cpu_s.os_regm, v);
	return 0;
}

cpuInterr procE8(){
	// Instruction: neg r8:regm
	cpuFetchOS();
	sint8 v = cpuReadReg8(cpu_s.os_regm);
	procNeg8(v);
	cpuWriteReg8(cpu_s.os_regm, v);
	return 0;
}

cpuInterr procE9(){
	// Instruction: neg r16:regm
	cpuFetchOS();
	sint16 v = cpuReadReg16(cpu_s.os_regm);
	procNeg16(v);
	cpuWriteReg16(cpu_s.os_regm, v);
	return 0;
}

cpuInterr procEA(){
	// Instruction: neg r32:regm
	cpuFetchOS();
	sint32 v = cpuReadReg32(cpu_s.os_regm);
	procNeg32(v);
	cpuWriteReg32(cpu_s.os_regm, v);
	return 0;
}

cpuInterr procEB(){
	// Prefix: CS
	cpu_s.prefix = true;
	cpu_s.seg_data = &cpu_s.sregs[SREG_CS];
	return 0;
}

cpuInterr procEC(){
	// Instruction: not r8:regm
	cpuFetchOS();
	uint8 v = cpuReadReg8(cpu_s.os_regm);
	procNot8(v);
	cpuWriteReg8(cpu_s.os_regm, v);
	return 0;
}

cpuInterr procED(){
	// Instruction: not r16:regm
	cpuFetchOS();
	uint16 v = cpuReadReg16(cpu_s.os_regm);
	procNot16(v);
	cpuWriteReg16(cpu_s.os_regm, v);
	return 0;
}

cpuInterr procEE(){
	// Instruction: not r32:regm
	cpuFetchOS();
	uint32 v = cpuReadReg32(cpu_s.os_regm);
	procNot32(v);
	cpuWriteReg32(cpu_s.os_regm, v);
	return 0;
}

cpuInterr procEF(){
	// Prefix: SS
	cpu_s.prefix = true;
	cpu_s.seg_data = &cpu_s.sregs[SREG_SS];
	return 0;
}

