#include "procedures.h"


cpuInterr procD0(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0: {
			// Instruction: fmvs r32:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			float32 data = (float32)cpu_s.fregs[cpu_s.os_regm];
			uint32 bdata = *((uint32*)(&data));
			cpuWriteReg32(dest, bdata);
		}
		break;
		case 0x1: {
			// Instruction: fmvs fpr:regm1, r32:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			uint32 data = cpuReadReg32(cpu_s.os_regm);
			float32 fdata = *((float32*)(&data));
			cpu_s.fregs[dest] = data;
		}
		break;
		case 0x2: {
			// Instruction: fmvs fpr:regm1, imm32:MV
			cpuFetchMV32();
			uint32 data = cpu_s.mv;
			float32 fdata = *((float32*)(&data));
			cpu_s.fregs[cpu_s.os_regm] = data;
		}
		break;
		case 0x3: {
			// Instruction: fmvs mem32, fpr:regm
			cpuFetchMemIndex();
			float32 data = (float32)cpu_s.fregs[cpu_s.os_regm];
			uint32 bdata = *((uint32*)(&data));
			cpuWriteMem32(cpu_s.mem_adr, bdata);
		}
		break;
		case 0x4: {
			// Instruction: fmvs fpr:regm, mem32
			cpuFetchMemIndex();
			cpuReadMem32(cpu_s.mem_adr);
			uint32 data = cpu_s.data;
			float32 fdata = *((float32*)(&data));
			cpu_s.fregs[cpu_s.os_regm] = data;
		}
		break;
		case 0x5: {
			// Instruction: fmvd r32:regm1, r32:regm2, fpr:rego2
			uint8 destl = cpu_s.os_regm;
			cpuFetchOS();
			float64 data = cpu_s.fregs[cpu_s.os_rego];
			uint32* bdata = (uint32*)(&data);
			cpuWriteReg32(destl, bdata[0]);
			cpuWriteReg32(cpu_s.os_regm, bdata[1]);
		}
		break;
		case 0x6: {
			// Instruction: fmvd fpr:regm1, r32:regm2, r32:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			uint32 data[2] = {cpuReadReg32(cpu_s.os_regm), cpuReadReg32(cpu_s.os_rego)};
			float64 fdata = *((float64*)(&data));
			cpu_s.fregs[dest] = fdata;
		}
		break;
		case 0x7: {
			// Instruction: fmvd mem64, fpr:regm
			cpuFetchMemIndex();
			float64 data = cpu_s.fregs[cpu_s.os_regm];
			uint32* bdata = (uint32*)(&data);
			cpuWriteMem32(cpu_s.mem_adr, bdata[0]);
			cpuWriteMem32(cpu_s.mem_adr+4, bdata[1]);
		}
		break;
		case 0x8: {
			// Instruction: fmvd fpr:regm, mem64
			cpuFetchMemIndex();
			uint32 data[2] = {0};
			cpuReadMem32(cpu_s.mem_adr);
			data[0] = cpu_s.data;
			cpuReadMem32(cpu_s.mem_adr+4);
			data[1] = cpu_s.data;
			float64 fdata = *((float64*)(&data));
			cpu_s.fregs[cpu_s.os_regm] = fdata;
		}
		break;
		case 0x9: {
			// Instruction: fpops fpr:regm
			cpuPop32();
			uint32 data = cpu_s.data;
			float32 fdata = *((float32*)(&data));
			cpu_s.fregs[cpu_s.os_regm] = data;
		}
		break;
		case 0xA: {
			// Instruction: fpopd fpr:regm
			uint32 data[2] = {0};
			cpuPop32();
			data[0] = cpu_s.data;
			cpuPop32();
			data[1] = cpu_s.data;
			float64 fdata = *((float64*)(&data));
			cpu_s.fregs[cpu_s.os_regm] = fdata;
		}
		break;
		case 0xB: {
			// Instruction: fpshs fpr:regm
			float32 data = (float32)cpu_s.fregs[cpu_s.os_regm];
			uint32 bdata = *((uint32*)(&data));
			cpuPush32(bdata);
		}
		break;
		case 0xC: {
			// Instruction: fpshd fpr:regm
			float64 data = cpu_s.fregs[cpu_s.os_regm];
			uint32* bdata = (uint32*)(&data);
			cpuPush32(bdata[1]);
			cpuPush32(bdata[0]);
		}
		break;
		case 0xD: {
			// Instruction xchg fpr:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			float64 temp = cpu_s.fregs[cpu_s.os_regm];
			cpuFetchOS();
			cpu_s.fregs[dest] = cpu_s.fregs[cpu_s.os_regm];
			cpu_s.fregs[cpu_s.os_regm] = temp;
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr procD1(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0: {
			// Instruction: fadc fpr:regm1, fpr:regm2, fpr:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = cpu_s.fregs[cpu_s.os_regm] + cpu_s.fregs[cpu_s.os_rego] + (cpu_s.reg_st&FLAG_CF?1.0:0.0);
			cpu_s.reg_st &= ~FLAG_CF;
		}
		break;
		case 0x1: {
			// Instruction: fadd fpr:regm1, fpr:regm2, fpr:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = cpu_s.fregs[cpu_s.os_regm] + cpu_s.fregs[cpu_s.os_rego];
		}
		break;
		case 0x2: {
			// Instruction: faddi fpr:regm1, fpr:regm2, r32:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = cpu_s.fregs[cpu_s.os_regm] + u32ToInt(cpuReadReg32(cpu_s.os_rego));
		}
		break;
		case 0x3: {
			// Instruction: fsbb fpr:regm1, fpr:regm2, fpr:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = cpu_s.fregs[cpu_s.os_regm] - cpu_s.fregs[cpu_s.os_rego] - (cpu_s.reg_st&FLAG_BF?1.0:0.0);
			cpu_s.reg_st &= ~FLAG_BF;
		}
		break;
		case 0x4: {
			// Instruction: fsub fpr:regm1, fpr:regm2, fpr:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = cpu_s.fregs[cpu_s.os_regm] - cpu_s.fregs[cpu_s.os_rego];
		}
		break;
		case 0x5: {
			// Instruction: fsubi fpr:regm1, fpr:regm2, r32:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpuFetchMV32();
			cpu_s.fregs[dest] = cpu_s.fregs[cpu_s.os_regm] - u32ToInt(cpuReadReg32(cpu_s.os_rego));
		}
		break;
		case 0x6: {
			// Instruction: fmul fpr:regm1, fpr:regm2, fpr:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = cpu_s.fregs[cpu_s.os_regm] * cpu_s.fregs[cpu_s.os_rego];
		}
		break;
		case 0x7: {
			// Instruction: fmadc fpr:regm1, fpr:regm2, fpr:rego2, fpr:regm3
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			uint8 fac1 = cpu_s.os_regm;
			uint8 fac2 = cpu_s.os_rego;
			cpuFetchOS();
			cpu_s.fregs[dest] = (cpu_s.fregs[fac1]*cpu_s.fregs[fac2]) + cpu_s.fregs[cpu_s.os_regm] + (cpu_s.reg_st&FLAG_CF?1.0:0.0);
			cpu_s.reg_st &= ~FLAG_CF;
		}
		break;
		case 0x8: {
			// Instruction: fmadd fpr:regm1, fpr:regm2, fpr:rego2, fpr:regm3
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			uint8 fac1 = cpu_s.os_regm;
			uint8 fac2 = cpu_s.os_rego;
			cpuFetchOS();
			cpu_s.fregs[dest] = (cpu_s.fregs[fac1]*cpu_s.fregs[fac2]) + cpu_s.fregs[cpu_s.os_regm];
		}
		break;
		case 0x9: {
			// Instruction: fdiv fpr:regm1, fpr:regm2, fpr:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = cpu_s.fregs[cpu_s.os_regm] / cpu_s.fregs[cpu_s.os_rego];
		}
		break;
		case 0xA: {
			// Instruction: fdsbb fpr:regm1, fpr:regm2, fpr:rego2, fpr:regm3
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			uint8 quocient = cpu_s.os_regm;
			uint8 divisor = cpu_s.os_rego;
			cpuFetchOS();
			cpu_s.fregs[dest] = (cpu_s.fregs[quocient]/cpu_s.fregs[divisor]) - cpu_s.fregs[cpu_s.os_regm] - (cpu_s.reg_st&FLAG_BF?1.0:0.0);
			cpu_s.reg_st &= ~FLAG_BF;
		}
		break;
		case 0xB: {
			// Instruction: fdsub fpr:regm1, fpr:regm2, fpr:rego2, fpr:regm3
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			uint8 quocient = cpu_s.os_regm;
			uint8 divisor = cpu_s.os_rego;
			cpuFetchOS();
			cpu_s.fregs[dest] = (cpu_s.fregs[quocient]/cpu_s.fregs[divisor]) - cpu_s.fregs[cpu_s.os_regm];
		}
		break;
		case 0xC: {
			// Instruction: fmod fpr:regm1, fpr:regm2, fpr:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = fmodl(cpu_s.fregs[cpu_s.os_regm], cpu_s.fregs[cpu_s.os_rego]);
		}
		break;
		case 0xD: {
			// Instruction: finc fpr:regm
			cpu_s.fregs[cpu_s.os_regm] = cpu_s.fregs[cpu_s.os_regm] + 1.0;
		}
		break;
		case 0xE: {
			// Instruction: fdec fpr:regm
			cpu_s.fregs[cpu_s.os_regm] = cpu_s.fregs[cpu_s.os_regm] - 1.0;
		}
		break;
		case 0xF: {
			// Instruction: fneg fpr:regm
			cpu_s.fregs[cpu_s.os_regm] = -cpu_s.fregs[cpu_s.os_regm];
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr procD2(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0: {
			// Instruction: fcmp r32:regm1, fpr:regm2, fpr:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			sint32 res = 0;
			if (cpu_s.fregs[cpu_s.os_regm] > cpu_s.fregs[cpu_s.os_rego]){
				res = 1;
			}
			else if (cpu_s.fregs[cpu_s.os_regm] < cpu_s.fregs[cpu_s.os_rego]){
				res = -1;
			}
			cpuWriteReg32(dest, res);
		}
		break;
		case 0x1: {
			// Instruction: fcmpi r32:regm1, fpr:regm2, r32:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			sint32 res = 0;
			if (cpu_s.fregs[cpu_s.os_regm] > u32ToInt(cpuReadReg32(cpu_s.os_rego))){
				res = 1;
			}
			else if (cpu_s.fregs[cpu_s.os_regm] < u32ToInt(cpuReadReg32(cpu_s.os_rego))){
				res = -1;
			}
			cpuWriteReg32(dest, res);
		}
		break;
		case 0x2: {
			// Instruction: fxam r32:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			uint32 type = -1; // UNKNOWN
			switch (fpclassify(cpu_s.fregs[cpu_s.os_regm])){
				case FP_ZERO: {
					type = 0; // ZERO
				}
				break;
				case FP_NORMAL: {
					type = 1; // NORMAL
				}
				break;
				case FP_SUBNORMAL: {
					type = 2; // SUBNORMAL
				}
				break;
				case FP_NAN: {
					type = 3; // NOT A NUMBER
				}
				break;
				case FP_INFINITE: {
					type = 4; // INFINITE
				}
				break;
			}
			cpuWriteReg32(dest, type);
		}
		break;
		case 0x3: {
			// Instruction: fsin fpr:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = sinl(cpu_s.fregs[cpu_s.os_regm]);
		}
		break;
		case 0x4: {
			// Instruction: fcos fpr:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = cosl(cpu_s.fregs[cpu_s.os_regm]);
		}
		break;
		case 0x5: {
			// Instruction: ftan fpr:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = tanl(cpu_s.fregs[cpu_s.os_regm]);
		}
		break;
		case 0x6: {
			// Instruction: fasin fpr:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = asinl(cpu_s.fregs[cpu_s.os_regm]);
		}
		break;
		case 0x7: {
			// Instruction: facos fpr:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = acosl(cpu_s.fregs[cpu_s.os_regm]);
		}
		break;
		case 0x8: {
			// Instruction: fatan fpr:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = atanl(cpu_s.fregs[cpu_s.os_regm]);
		}
		break;
		case 0x9: {
			// Instruction: fatan2 fpr:regm1, fpr:regm2, fpr:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = atan2l(cpu_s.fregs[cpu_s.os_regm], cpu_s.fregs[cpu_s.os_rego]);
		}
		break;
		case 0xA: {
			// Instruction: fsqrt fpr:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = sqrtl(cpu_s.fregs[cpu_s.os_regm]);
		}
		break;
		case 0xB: {
			// Instruction: fcbrt fpr:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = powl(cpu_s.fregs[cpu_s.os_regm], 1.0/3.0);
		}
		break;
		case 0xC: {
			// Instruction: f2xm1 fpr:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = powl(2.0, cpu_s.fregs[cpu_s.os_regm]) - 1.0;
		}
		break;
		case 0xD: {
			// Instruction: flog fpr:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = logl(cpu_s.fregs[cpu_s.os_regm]);
		}
		break;
		case 0xE: {
			// Instruction: flog2 fpr:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = log2l(cpu_s.fregs[cpu_s.os_regm]);
		}
		break;
		case 0xF: {
			// Instruction: flog2x fpr:regm1, fpr:regm2, fpr:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = log2l(cpu_s.fregs[cpu_s.os_regm]) * cpu_s.fregs[cpu_s.os_rego];
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr procD3(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0: {
			// Instruction: ffloor fpr:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = floorl(cpu_s.fregs[cpu_s.os_regm]);
		}
		break;
		case 0x1: {
			// Instruction: fceil fpr:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = ceill(cpu_s.fregs[cpu_s.os_regm]);
		}
		break;
		case 0x2: {
			// Instruction: fround fpr:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			cpu_s.fregs[dest] = roundl(cpu_s.fregs[cpu_s.os_regm]);
		}
		break;
		case 0x3: {
			// Instruction: fcvtb r8:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			uint8 data = (uint8)cpu_s.fregs[cpu_s.os_regm];
			cpuWriteReg8(dest, data);
		}
		break;
		case 0x4: {
			// Instruction: fcvth r16:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			uint16 data = (uint16)cpu_s.fregs[cpu_s.os_regm];
			cpuWriteReg16(dest, data);
		}
		break;
		case 0x5: {
			// Instruction: fcvtb r32:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			uint32 data = (uint32)cpu_s.fregs[cpu_s.os_regm];
			cpuWriteReg32(dest, data);
		}
		break;
		case 0x6: {
			// Instruction: fcvtsb r8:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			sint8 data = (sint8)cpu_s.fregs[cpu_s.os_regm];
			cpuWriteReg8(dest, data);
		}
		break;
		case 0x7: {
			// Instruction: fcvtsh r16:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			sint16 data = (sint16)cpu_s.fregs[cpu_s.os_regm];
			cpuWriteReg8(dest, data);
		}
		break;
		case 0x8: {
			// Instruction: fcvtsw r32:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			sint32 data = (sint32)cpu_s.fregs[cpu_s.os_regm];
			cpuWriteReg8(dest, data);
		}
		break;
		case 0x9: {
			// Instruction: fcvfb fpr:regm1, r8:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			uint8 data = cpuReadReg8(cpu_s.os_regm);
			cpu_s.fregs[dest] = data;
		}
		break;
		case 0xA: {
			// Instruction: fcvfh fpr:regm1, r16:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			uint16 data = cpuReadReg16(cpu_s.os_regm);
			cpu_s.fregs[dest] = data;
		}
		break;
		case 0xB: {
			// Instruction: fcvfb fpr:regm1, r32:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			uint32 data = cpuReadReg8(cpu_s.os_regm);
			cpu_s.fregs[dest] = data;
		}
		break;
		case 0xC: {
			// Instruction: fcvfsb fpr:regm1, r8:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			sint8 data = cpuReadReg8(cpu_s.os_regm);
			cpu_s.fregs[dest] = data;
		}
		break;
		case 0xD: {
			// Instruction: fcvfsh fpr:regm1, r16:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			sint16 data = cpuReadReg16(cpu_s.os_regm);
			cpu_s.fregs[dest] = data;
		}
		break;
		case 0xE: {
			// Instruction: fcvfsw fpr:regm1, r32:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			sint32 data = cpuReadReg16(cpu_s.os_regm);
			cpu_s.fregs[dest] = data;
		}
		break;
		case 0xF: {
			// Instruction: fdbtsg fpr:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			float32 single = (float32)cpu_s.fregs[cpu_s.os_regm];
			cpu_s.fregs[dest] = single;
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr procD7(){
	cpuFetchOS();

	switch (cpu_s.os_desc){
		case 0x0: {
			// Instruction fsteq r32:regm1, fpr:regm2, fpr:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			if (cpu_s.fregs[cpu_s.os_regm]==cpu_s.fregs[cpu_s.os_rego]){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0x1: {
			// Instruction fstne r32:regm1, fpr:regm2, fpr:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			if (cpu_s.fregs[cpu_s.os_regm]!=cpu_s.fregs[cpu_s.os_rego]){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0x2: {
			// Instruction fstgt r32:regm1, fpr:regm2, fpr:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			if (cpu_s.fregs[cpu_s.os_regm]>cpu_s.fregs[cpu_s.os_rego]){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0x3: {
			// Instruction fstle r32:regm1, fpr:regm2, fpr:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			if (cpu_s.fregs[cpu_s.os_regm]<cpu_s.fregs[cpu_s.os_rego]){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0x4: {
			// Instruction fstge r32:regm1, fpr:regm2, fpr:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			if (cpu_s.fregs[cpu_s.os_regm]>=cpu_s.fregs[cpu_s.os_rego]){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0x5: {
			// Instruction fstle r32:regm1, fpr:regm2, fpr:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			if (cpu_s.fregs[cpu_s.os_regm]<=cpu_s.fregs[cpu_s.os_rego]){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0x6: {
			// Instruction fsteqz r32:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			if (cpu_s.fregs[cpu_s.os_regm]==0.0){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0x7: {
			// Instruction fstreqz r32:regm1, fpr:regm2, fpr:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			if (0.0>=(cpu_s.fregs[cpu_s.os_regm]-cpu_s.fregs[cpu_s.os_rego]) && 0.0<=(cpu_s.fregs[cpu_s.os_regm]+cpu_s.fregs[cpu_s.os_rego])){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0x8: {
			// Instruction fstnez r32:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			if (cpu_s.fregs[cpu_s.os_regm]!=0.0){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0x9: {
			// Instruction fstrnez r32:regm1, fpr:regm2, fpr:rego2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			if (0.0<(cpu_s.fregs[cpu_s.os_regm]-cpu_s.fregs[cpu_s.os_rego]) || 0.0>(cpu_s.fregs[cpu_s.os_regm]+cpu_s.fregs[cpu_s.os_rego])){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0xA: {
			// Instruction fstgtz r32:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			if (cpu_s.fregs[cpu_s.os_regm]>0.0){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0xB: {
			// Instruction fstltz r32:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			if (cpu_s.fregs[cpu_s.os_regm]<0.0){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0xC: {
			// Instruction fstgez r32:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			if (cpu_s.fregs[cpu_s.os_regm]>=0.0){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0xD: {
			// Instruction fstlez r32:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			if (cpu_s.fregs[cpu_s.os_regm]<=0.0){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0xE: {
			// Instruction fstes r32:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			if (cpu_s.fregs[cpu_s.os_regm]>0.0 == eval(cpu_s.reg_st&FLAG_NF)){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		case 0xF: {
			// Instruction fstns r32:regm1, fpr:regm2
			uint8 dest = cpu_s.os_regm;
			cpuFetchOS();
			if (cpu_s.fregs[cpu_s.os_regm]>0.0 != eval(cpu_s.reg_st&FLAG_NF)){
				cpuWriteReg32(dest, 1);
			}
			else{
				cpuWriteReg32(dest, 0);
			}
		}
		break;
		default: {
			cpuThrowInterruption(INTR_INVALID_OPCODE);
		}
	}
	return 0;
}

cpuInterr procDD(){
	// Instruction: bswap r16
	uint16 data = cpuReadReg16(cpu_s.os_regm);
	data = ((data&0xFF00)>>8) | ((data&0x00FF)<<8);
	cpuWriteReg16(cpu_s.os_regm, data);
	return 0;
}

cpuInterr procDE(){
	// Instruction: bswap r32
	uint32 data = cpuReadReg32(cpu_s.os_regm);
	data = ((data&0xFF000000)>>24) | ((data&0x00FF0000)>>8) | ((data&0x0000FF00)<<8) | ((data&0x000000FF)<<24);
	cpuWriteReg32(cpu_s.os_regm, data);
	return 0;
}
