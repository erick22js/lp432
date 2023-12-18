#ifndef EMU_CPU_PROCEDURES_H
#define EMU_CPU_PROCEDURES_H

#include "../interruption.h"
#include "../memory.h"


/*
	Procedures Typing
*/

typedef cpuInterr (*cpuProc)(Cpu *cpu_s);


/*
	Procedures Related
*/

cpuInterr proc00(Cpu *cpu_s);
cpuInterr proc01(Cpu *cpu_s);
cpuInterr proc02(Cpu *cpu_s);
cpuInterr proc03(Cpu *cpu_s);
cpuInterr proc04(Cpu *cpu_s);
cpuInterr proc05(Cpu *cpu_s);
cpuInterr proc06(Cpu *cpu_s);
cpuInterr proc07(Cpu *cpu_s);
cpuInterr proc08(Cpu *cpu_s);
cpuInterr proc09(Cpu *cpu_s);
cpuInterr proc0A(Cpu *cpu_s);
cpuInterr proc0B(Cpu *cpu_s);
cpuInterr proc0C(Cpu *cpu_s);
cpuInterr proc0D(Cpu *cpu_s);
cpuInterr proc0E(Cpu *cpu_s);
cpuInterr proc0F(Cpu *cpu_s);

cpuInterr proc10(Cpu *cpu_s);
cpuInterr proc11(Cpu *cpu_s);
cpuInterr proc12(Cpu *cpu_s);
cpuInterr proc13(Cpu *cpu_s);
cpuInterr proc14(Cpu *cpu_s);
cpuInterr proc15(Cpu *cpu_s);
cpuInterr proc16(Cpu *cpu_s);
cpuInterr proc17(Cpu *cpu_s);
cpuInterr proc18(Cpu *cpu_s);
cpuInterr proc19(Cpu *cpu_s);
cpuInterr proc1A(Cpu *cpu_s);
cpuInterr proc1B(Cpu *cpu_s);
cpuInterr proc1C(Cpu *cpu_s);
cpuInterr proc1D(Cpu *cpu_s);
cpuInterr proc1E(Cpu *cpu_s);
cpuInterr proc1F(Cpu *cpu_s);

cpuInterr proc20(Cpu *cpu_s);
cpuInterr proc21(Cpu *cpu_s);
cpuInterr proc22(Cpu *cpu_s);
cpuInterr proc23(Cpu *cpu_s);
cpuInterr proc24(Cpu *cpu_s);
cpuInterr proc25(Cpu *cpu_s);
cpuInterr proc26(Cpu *cpu_s);
cpuInterr proc27(Cpu *cpu_s);
cpuInterr proc28(Cpu *cpu_s);
cpuInterr proc29(Cpu *cpu_s);
cpuInterr proc2A(Cpu *cpu_s);
cpuInterr proc2B(Cpu *cpu_s);
cpuInterr proc2C(Cpu *cpu_s);
cpuInterr proc2D(Cpu *cpu_s);
cpuInterr proc2E(Cpu *cpu_s);
cpuInterr proc2F(Cpu *cpu_s);

cpuInterr proc30(Cpu *cpu_s);
cpuInterr proc31(Cpu *cpu_s);
cpuInterr proc32(Cpu *cpu_s);
cpuInterr proc33(Cpu *cpu_s);
cpuInterr proc34(Cpu *cpu_s);
cpuInterr proc35(Cpu *cpu_s);
cpuInterr proc36(Cpu *cpu_s);
cpuInterr proc37(Cpu *cpu_s);
cpuInterr proc38(Cpu *cpu_s);
cpuInterr proc39(Cpu *cpu_s);
cpuInterr proc3A(Cpu *cpu_s);
cpuInterr proc3B(Cpu *cpu_s);
cpuInterr proc3C(Cpu *cpu_s);
cpuInterr proc3D(Cpu *cpu_s);
cpuInterr proc3E(Cpu *cpu_s);
cpuInterr proc3F(Cpu *cpu_s);

cpuInterr proc40(Cpu *cpu_s);
cpuInterr proc41(Cpu *cpu_s);
cpuInterr proc42(Cpu *cpu_s);
cpuInterr proc43(Cpu *cpu_s);
cpuInterr proc44(Cpu *cpu_s);
cpuInterr proc45(Cpu *cpu_s);
cpuInterr proc46(Cpu *cpu_s);
cpuInterr proc47(Cpu *cpu_s);
cpuInterr proc48(Cpu *cpu_s);
cpuInterr proc49(Cpu *cpu_s);
cpuInterr proc4A(Cpu *cpu_s);
cpuInterr proc4B(Cpu *cpu_s);
cpuInterr proc4C(Cpu *cpu_s);
cpuInterr proc4D(Cpu *cpu_s);
cpuInterr proc4E(Cpu *cpu_s);
cpuInterr proc4F(Cpu *cpu_s);

cpuInterr proc50(Cpu *cpu_s);
cpuInterr proc51(Cpu *cpu_s);
cpuInterr proc52(Cpu *cpu_s);
cpuInterr proc53(Cpu *cpu_s);
cpuInterr proc54(Cpu *cpu_s);
cpuInterr proc55(Cpu *cpu_s);
cpuInterr proc56(Cpu *cpu_s);
cpuInterr proc57(Cpu *cpu_s);
cpuInterr proc58(Cpu *cpu_s);
cpuInterr proc59(Cpu *cpu_s);
cpuInterr proc5A(Cpu *cpu_s);
cpuInterr proc5B(Cpu *cpu_s);
cpuInterr proc5C(Cpu *cpu_s);
cpuInterr proc5D(Cpu *cpu_s);
cpuInterr proc5E(Cpu *cpu_s);
cpuInterr proc5F(Cpu *cpu_s);

cpuInterr proc60(Cpu *cpu_s);
cpuInterr proc61(Cpu *cpu_s);
cpuInterr proc62(Cpu *cpu_s);
cpuInterr proc63(Cpu *cpu_s);
cpuInterr proc64(Cpu *cpu_s);
cpuInterr proc65(Cpu *cpu_s);
cpuInterr proc66(Cpu *cpu_s);
cpuInterr proc67(Cpu *cpu_s);
cpuInterr proc68(Cpu *cpu_s);
cpuInterr proc69(Cpu *cpu_s);
cpuInterr proc6A(Cpu *cpu_s);
cpuInterr proc6B(Cpu *cpu_s);
cpuInterr proc6C(Cpu *cpu_s);
cpuInterr proc6D(Cpu *cpu_s);
cpuInterr proc6E(Cpu *cpu_s);
cpuInterr proc6F(Cpu *cpu_s);

cpuInterr proc70(Cpu *cpu_s);
cpuInterr proc71(Cpu *cpu_s);
cpuInterr proc72(Cpu *cpu_s);
cpuInterr proc73(Cpu *cpu_s);
cpuInterr proc74(Cpu *cpu_s);
cpuInterr proc75(Cpu *cpu_s);
cpuInterr proc76(Cpu *cpu_s);
cpuInterr proc77(Cpu *cpu_s);
cpuInterr proc78(Cpu *cpu_s);
cpuInterr proc79(Cpu *cpu_s);
cpuInterr proc7A(Cpu *cpu_s);
cpuInterr proc7B(Cpu *cpu_s);
cpuInterr proc7C(Cpu *cpu_s);
cpuInterr proc7D(Cpu *cpu_s);
cpuInterr proc7E(Cpu *cpu_s);
cpuInterr proc7F(Cpu *cpu_s);

cpuInterr proc80(Cpu *cpu_s);
cpuInterr proc81(Cpu *cpu_s);
cpuInterr proc82(Cpu *cpu_s);
cpuInterr proc83(Cpu *cpu_s);
cpuInterr proc84(Cpu *cpu_s);
cpuInterr proc85(Cpu *cpu_s);
cpuInterr proc86(Cpu *cpu_s);
cpuInterr proc87(Cpu *cpu_s);
cpuInterr proc88(Cpu *cpu_s);
cpuInterr proc89(Cpu *cpu_s);
cpuInterr proc8A(Cpu *cpu_s);
cpuInterr proc8B(Cpu *cpu_s);
cpuInterr proc8C(Cpu *cpu_s);
cpuInterr proc8D(Cpu *cpu_s);
cpuInterr proc8E(Cpu *cpu_s);
cpuInterr proc8F(Cpu *cpu_s);

cpuInterr proc90(Cpu *cpu_s);
cpuInterr proc91(Cpu *cpu_s);
cpuInterr proc92(Cpu *cpu_s);
cpuInterr proc93(Cpu *cpu_s);
cpuInterr proc94(Cpu *cpu_s);
cpuInterr proc95(Cpu *cpu_s);
cpuInterr proc96(Cpu *cpu_s);
cpuInterr proc97(Cpu *cpu_s);
cpuInterr proc98(Cpu *cpu_s);
cpuInterr proc99(Cpu *cpu_s);
cpuInterr proc9A(Cpu *cpu_s);
cpuInterr proc9B(Cpu *cpu_s);
cpuInterr proc9C(Cpu *cpu_s);
cpuInterr proc9D(Cpu *cpu_s);
cpuInterr proc9E(Cpu *cpu_s);
cpuInterr proc9F(Cpu *cpu_s);

cpuInterr procA0(Cpu *cpu_s);
cpuInterr procA1(Cpu *cpu_s);
cpuInterr procA2(Cpu *cpu_s);
cpuInterr procA3(Cpu *cpu_s);
cpuInterr procA4(Cpu *cpu_s);
cpuInterr procA5(Cpu *cpu_s);
cpuInterr procA6(Cpu *cpu_s);
cpuInterr procA7(Cpu *cpu_s);
cpuInterr procA8(Cpu *cpu_s);
cpuInterr procA9(Cpu *cpu_s);
cpuInterr procAA(Cpu *cpu_s);
cpuInterr procAB(Cpu *cpu_s);
cpuInterr procAC(Cpu *cpu_s);
cpuInterr procAD(Cpu *cpu_s);
cpuInterr procAE(Cpu *cpu_s);
cpuInterr procAF(Cpu *cpu_s);

cpuInterr procB0(Cpu *cpu_s);
cpuInterr procB1(Cpu *cpu_s);
cpuInterr procB2(Cpu *cpu_s);
cpuInterr procB3(Cpu *cpu_s);
cpuInterr procB4(Cpu *cpu_s);
cpuInterr procB5(Cpu *cpu_s);
cpuInterr procB6(Cpu *cpu_s);
cpuInterr procB7(Cpu *cpu_s);
cpuInterr procB8(Cpu *cpu_s);
cpuInterr procB9(Cpu *cpu_s);
cpuInterr procBA(Cpu *cpu_s);
cpuInterr procBB(Cpu *cpu_s);
cpuInterr procBC(Cpu *cpu_s);
cpuInterr procBD(Cpu *cpu_s);
cpuInterr procBE(Cpu *cpu_s);
cpuInterr procBF(Cpu *cpu_s);

cpuInterr procC0(Cpu *cpu_s);
cpuInterr procC1(Cpu *cpu_s);
cpuInterr procC2(Cpu *cpu_s);
cpuInterr procC3(Cpu *cpu_s);
cpuInterr procC4(Cpu *cpu_s);
cpuInterr procC5(Cpu *cpu_s);
cpuInterr procC6(Cpu *cpu_s);
cpuInterr procC7(Cpu *cpu_s);
cpuInterr procC8(Cpu *cpu_s);
cpuInterr procC9(Cpu *cpu_s);
cpuInterr procCA(Cpu *cpu_s);
cpuInterr procCB(Cpu *cpu_s);
cpuInterr procCC(Cpu *cpu_s);
cpuInterr procCD(Cpu *cpu_s);
cpuInterr procCE(Cpu *cpu_s);
cpuInterr procCF(Cpu *cpu_s);

cpuInterr procD0(Cpu *cpu_s);
cpuInterr procD1(Cpu *cpu_s);
cpuInterr procD2(Cpu *cpu_s);
cpuInterr procD3(Cpu *cpu_s);
cpuInterr procD4(Cpu *cpu_s);
cpuInterr procD5(Cpu *cpu_s);
cpuInterr procD6(Cpu *cpu_s);
cpuInterr procD7(Cpu *cpu_s);
cpuInterr procD8(Cpu *cpu_s);
cpuInterr procD9(Cpu *cpu_s);
cpuInterr procDA(Cpu *cpu_s);
cpuInterr procDB(Cpu *cpu_s);
cpuInterr procDC(Cpu *cpu_s);
cpuInterr procDD(Cpu *cpu_s);
cpuInterr procDE(Cpu *cpu_s);
cpuInterr procDF(Cpu *cpu_s);

cpuInterr procE0(Cpu *cpu_s);
cpuInterr procE1(Cpu *cpu_s);
cpuInterr procE2(Cpu *cpu_s);
cpuInterr procE3(Cpu *cpu_s);
cpuInterr procE4(Cpu *cpu_s);
cpuInterr procE5(Cpu *cpu_s);
cpuInterr procE6(Cpu *cpu_s);
cpuInterr procE7(Cpu *cpu_s);
cpuInterr procE8(Cpu *cpu_s);
cpuInterr procE9(Cpu *cpu_s);
cpuInterr procEA(Cpu *cpu_s);
cpuInterr procEB(Cpu *cpu_s);
cpuInterr procEC(Cpu *cpu_s);
cpuInterr procED(Cpu *cpu_s);
cpuInterr procEE(Cpu *cpu_s);
cpuInterr procEF(Cpu *cpu_s);

cpuInterr procF0(Cpu *cpu_s);
cpuInterr procF1(Cpu *cpu_s);
cpuInterr procF2(Cpu *cpu_s);
cpuInterr procF3(Cpu *cpu_s);
cpuInterr procF4(Cpu *cpu_s);
cpuInterr procF5(Cpu *cpu_s);
cpuInterr procF6(Cpu *cpu_s);
cpuInterr procF7(Cpu *cpu_s);
cpuInterr procF8(Cpu *cpu_s);
cpuInterr procF9(Cpu *cpu_s);
cpuInterr procFA(Cpu *cpu_s);
cpuInterr procFB(Cpu *cpu_s);
cpuInterr procFC(Cpu *cpu_s);
cpuInterr procFD(Cpu *cpu_s);
cpuInterr procFE(Cpu *cpu_s);
cpuInterr procFF(Cpu *cpu_s);


/*
	Procedures Utilities and Helpers
*/

#define procEnsureNotInProtectedMode() {\
	if (cpu_s->reg_st&FLAG_PM){\
		cpu_s->iregs[0] = cpu_s->reg_lpc;\
		cpuThrowInterruption(INTR_PROTECTED_MODE_VIOLATION);\
	}\
}


/*
	Procedures Database
*/

extern cpuProc cpuProcedures[256];


#endif