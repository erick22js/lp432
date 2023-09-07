#ifndef EMU_CPU_PROCEDURES_H
#define EMU_CPU_PROCEDURES_H

#include "../interruption.h"
#include "../memory.h"


/*
	Procedures Typing
*/

typedef cpuInterr (*cpuProc)();


/*
	Procedures Related
*/

cpuInterr proc00();
cpuInterr proc01();
cpuInterr proc02();
cpuInterr proc03();
cpuInterr proc04();
cpuInterr proc05();
cpuInterr proc06();
cpuInterr proc07();
cpuInterr proc08();
cpuInterr proc09();
cpuInterr proc0A();
cpuInterr proc0B();
cpuInterr proc0C();
cpuInterr proc0D();
cpuInterr proc0E();
cpuInterr proc0F();

cpuInterr proc10();
cpuInterr proc11();
cpuInterr proc12();
cpuInterr proc13();
cpuInterr proc14();
cpuInterr proc15();
cpuInterr proc16();
cpuInterr proc17();
cpuInterr proc18();
cpuInterr proc19();
cpuInterr proc1A();
cpuInterr proc1B();
cpuInterr proc1C();
cpuInterr proc1D();
cpuInterr proc1E();
cpuInterr proc1F();

cpuInterr proc20();
cpuInterr proc21();
cpuInterr proc22();
cpuInterr proc23();
cpuInterr proc24();
cpuInterr proc25();
cpuInterr proc26();
cpuInterr proc27();
cpuInterr proc28();
cpuInterr proc29();
cpuInterr proc2A();
cpuInterr proc2B();
cpuInterr proc2C();
cpuInterr proc2D();
cpuInterr proc2E();
cpuInterr proc2F();

cpuInterr proc30();
cpuInterr proc31();
cpuInterr proc32();
cpuInterr proc33();
cpuInterr proc34();
cpuInterr proc35();
cpuInterr proc36();
cpuInterr proc37();
cpuInterr proc38();
cpuInterr proc39();
cpuInterr proc3A();
cpuInterr proc3B();
cpuInterr proc3C();
cpuInterr proc3D();
cpuInterr proc3E();
cpuInterr proc3F();

cpuInterr proc40();
cpuInterr proc41();
cpuInterr proc42();
cpuInterr proc43();
cpuInterr proc44();
cpuInterr proc45();
cpuInterr proc46();
cpuInterr proc47();
cpuInterr proc48();
cpuInterr proc49();
cpuInterr proc4A();
cpuInterr proc4B();
cpuInterr proc4C();
cpuInterr proc4D();
cpuInterr proc4E();
cpuInterr proc4F();

cpuInterr proc50();
cpuInterr proc51();
cpuInterr proc52();
cpuInterr proc53();
cpuInterr proc54();
cpuInterr proc55();
cpuInterr proc56();
cpuInterr proc57();
cpuInterr proc58();
cpuInterr proc59();
cpuInterr proc5A();
cpuInterr proc5B();
cpuInterr proc5C();
cpuInterr proc5D();
cpuInterr proc5E();
cpuInterr proc5F();

cpuInterr proc60();
cpuInterr proc61();
cpuInterr proc62();
cpuInterr proc63();
cpuInterr proc64();
cpuInterr proc65();
cpuInterr proc66();
cpuInterr proc67();
cpuInterr proc68();
cpuInterr proc69();
cpuInterr proc6A();
cpuInterr proc6B();
cpuInterr proc6C();
cpuInterr proc6D();
cpuInterr proc6E();
cpuInterr proc6F();

cpuInterr proc70();
cpuInterr proc71();
cpuInterr proc72();
cpuInterr proc73();
cpuInterr proc74();
cpuInterr proc75();
cpuInterr proc76();
cpuInterr proc77();
cpuInterr proc78();
cpuInterr proc79();
cpuInterr proc7A();
cpuInterr proc7B();
cpuInterr proc7C();
cpuInterr proc7D();
cpuInterr proc7E();
cpuInterr proc7F();

cpuInterr proc80();
cpuInterr proc81();
cpuInterr proc82();
cpuInterr proc83();
cpuInterr proc84();
cpuInterr proc85();
cpuInterr proc86();
cpuInterr proc87();
cpuInterr proc88();
cpuInterr proc89();
cpuInterr proc8A();
cpuInterr proc8B();
cpuInterr proc8C();
cpuInterr proc8D();
cpuInterr proc8E();
cpuInterr proc8F();

cpuInterr proc90();
cpuInterr proc91();
cpuInterr proc92();
cpuInterr proc93();
cpuInterr proc94();
cpuInterr proc95();
cpuInterr proc96();
cpuInterr proc97();
cpuInterr proc98();
cpuInterr proc99();
cpuInterr proc9A();
cpuInterr proc9B();
cpuInterr proc9C();
cpuInterr proc9D();
cpuInterr proc9E();
cpuInterr proc9F();

cpuInterr procA0();
cpuInterr procA1();
cpuInterr procA2();
cpuInterr procA3();
cpuInterr procA4();
cpuInterr procA5();
cpuInterr procA6();
cpuInterr procA7();
cpuInterr procA8();
cpuInterr procA9();
cpuInterr procAA();
cpuInterr procAB();
cpuInterr procAC();
cpuInterr procAD();
cpuInterr procAE();
cpuInterr procAF();

cpuInterr procB0();
cpuInterr procB1();
cpuInterr procB2();
cpuInterr procB3();
cpuInterr procB4();
cpuInterr procB5();
cpuInterr procB6();
cpuInterr procB7();
cpuInterr procB8();
cpuInterr procB9();
cpuInterr procBA();
cpuInterr procBB();
cpuInterr procBC();
cpuInterr procBD();
cpuInterr procBE();
cpuInterr procBF();

cpuInterr procC0();
cpuInterr procC1();
cpuInterr procC2();
cpuInterr procC3();
cpuInterr procC4();
cpuInterr procC5();
cpuInterr procC6();
cpuInterr procC7();
cpuInterr procC8();
cpuInterr procC9();
cpuInterr procCA();
cpuInterr procCB();
cpuInterr procCC();
cpuInterr procCD();
cpuInterr procCE();
cpuInterr procCF();

cpuInterr procD0();
cpuInterr procD1();
cpuInterr procD2();
cpuInterr procD3();
cpuInterr procD4();
cpuInterr procD5();
cpuInterr procD6();
cpuInterr procD7();
cpuInterr procD8();
cpuInterr procD9();
cpuInterr procDA();
cpuInterr procDB();
cpuInterr procDC();
cpuInterr procDD();
cpuInterr procDE();
cpuInterr procDF();

cpuInterr procE0();
cpuInterr procE1();
cpuInterr procE2();
cpuInterr procE3();
cpuInterr procE4();
cpuInterr procE5();
cpuInterr procE6();
cpuInterr procE7();
cpuInterr procE8();
cpuInterr procE9();
cpuInterr procEA();
cpuInterr procEB();
cpuInterr procEC();
cpuInterr procED();
cpuInterr procEE();
cpuInterr procEF();

cpuInterr procF0();
cpuInterr procF1();
cpuInterr procF2();
cpuInterr procF3();
cpuInterr procF4();
cpuInterr procF5();
cpuInterr procF6();
cpuInterr procF7();
cpuInterr procF8();
cpuInterr procF9();
cpuInterr procFA();
cpuInterr procFB();
cpuInterr procFC();
cpuInterr procFD();
cpuInterr procFE();
cpuInterr procFF();


/*
	Procedures Database
*/

extern cpuProc cpuProcedures[256];


#endif