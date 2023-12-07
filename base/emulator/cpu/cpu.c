#include "memory.h"
#include "procs/procedures.h"


/*
	State Properties of CPU
*/

//Cpu cpu_s;

/*
	Util Functions
*/

void cpuDebug(Cpu *cpu_s){
	log("A:0x%.8X;  D:0x%.8X;  C:0x%.8X;  B:0x%.8X;  E:0x%.8X;  H:0x%.8X;  G:0x%.8X;  F:0x%.8X\n", cpu_s->gregs[0], cpu_s->gregs[1], cpu_s->gregs[2], cpu_s->gregs[3], cpu_s->gregs[4], cpu_s->gregs[5], cpu_s->gregs[6], cpu_s->gregs[7]);
	log("X0:0x%.8X; X1:0x%.8X; X2:0x%.8X; X3:0x%.8X; SS:0x%.8X; SD:0x%.8X; SP:0x%.8X; FP:0x%.8X\n", cpu_s->gregs[8], cpu_s->gregs[9], cpu_s->gregs[10], cpu_s->gregs[11], cpu_s->gregs[12], cpu_s->gregs[13], cpu_s->gregs[14], cpu_s->gregs[15]);
	log("ST: 0x%.8X(%c%c%c%c%c%c%c%c%c%c)\n", cpu_s->reg_st, (cpu_s->reg_st&FLAG_CF?'C':'-'), (cpu_s->reg_st&FLAG_BF?'B':'-'), (cpu_s->reg_st&FLAG_VF?'V':'-'), (cpu_s->reg_st&FLAG_NF?'N':'-'), (cpu_s->reg_st&FLAG_ZF?'Z':'-'), (cpu_s->reg_st&FLAG_OF?'O':'-'), (cpu_s->reg_st&FLAG_PM?'P':'-'), (cpu_s->reg_st&FLAG_SE?'S':'-'), (cpu_s->reg_st&FLAG_PE?'G':'-'), (cpu_s->reg_st&FLAG_IE?'I':'-'));
	log("\n");
}

/*
	Control Functions for CPU
*/

// Program Flow Control

bool cpuRequestInterrupt(Cpu *cpu_s, uint16 port){
	if (!cpu_s->request_external){
		cpu_s->request_external = true;
		cpu_s->request_port = port;
		return true;
	}
	return false;
}

void cpuReset(Cpu *cpu_s){
	memset(&cpu_s->gregs, 0, sizeof(cpu_s->gregs));
	memset(&cpu_s->sregs, 0, sizeof(cpu_s->sregs));
	memset(&cpu_s->fregs, 0, sizeof(cpu_s->fregs));
	memset(&cpu_s->iregs, 0, sizeof(cpu_s->iregs));
	cpu_s->reg_pc = 0;
	cpu_s->reg_lpc = 0;
	cpu_s->reg_st = 0;
	cpu_s->reg_std = 0;
	cpu_s->reg_ptd = 0;
	cpu_s->reg_itd = 0;
	cpu_s->reg_isp = 0;
	cpu_s->request_external = false;
	cpu_s->request_port = 0;
	cpu_s->halted = false;
	cpu_s->waiting = false;
}

void cpuStep(Cpu *cpu_s){
	// Disable prefixing for next fetch
	if (cpu_s->prefix){
		cpu_s->prefix = false;
	}
	else{
		// Reset modifiers
		cpu_s->reg_lpc = cpu_s->reg_pc;
	}

	// Querying for instruction opcode
	cpuFetchOpcode();
	// Logging debug info
	//log("%.8X: 0x%.2X\n", cpu_s->reg_pc-1, cpu_s->opcode);

	// Decoding opcode into procedure
	cpuProc proc = cpuProcedures[cpu_s->opcode];
	// Running procedure
	proc(cpu_s);

	// Timer handling
	while (cpu_s->reg_utv>=32){
		cpu_s->reg_utv -= 32;
		cpu_s->reg_ctv++;
	}
	if (cpu_s->reg_ctv >= cpu_s->reg_pit){
		if (cpu_s->reg_st&FLAG_TI && !cpu_s->interrupt){
			cpu_s->reg_ctv = 0;
			cpu_s->interrupt = INTR_TIMER_INTERRUPTION;
		}
	}

	// Skip execution on prefix detection
	if (!cpu_s->prefix){
		// Logging after info
		//log("A:0x%.8X;  D:0x%.8X;  C:0x%.8X;  B:0x%.8X;  E:0x%.8X;  H:0x%.8X;  G:0x%.8X;  F:0x%.8X\n", cpu_s->gregs[0], cpu_s->gregs[1], cpu_s->gregs[2], cpu_s->gregs[3], cpu_s->gregs[4], cpu_s->gregs[5], cpu_s->gregs[6], cpu_s->gregs[7]);
		//log("X0:0x%.8X; X1:0x%.8X; X2:0x%.8X; X3:0x%.8X; SS:0x%.8X; SD:0x%.8X; SP:0x%.8X; FP:0x%.8X\n", cpu_s->gregs[8], cpu_s->gregs[9], cpu_s->gregs[10], cpu_s->gregs[11], cpu_s->gregs[12], cpu_s->gregs[13], cpu_s->gregs[14], cpu_s->gregs[15]);
		//log("ST: 0x%.8X(%c%c%c%c%c%c%c%c%c%c)\n", cpu_s->reg_st, (cpu_s->reg_st&FLAG_CF?'C':'-'), (cpu_s->reg_st&FLAG_BF?'B':'-'), (cpu_s->reg_st&FLAG_VF?'V':'-'), (cpu_s->reg_st&FLAG_NF?'N':'-'), (cpu_s->reg_st&FLAG_ZF?'Z':'-'), (cpu_s->reg_st&FLAG_OF?'O':'-'), (cpu_s->reg_st&FLAG_PM?'P':'-'), (cpu_s->reg_st&FLAG_SE?'S':'-'), (cpu_s->reg_st&FLAG_PE?'G':'-'), (cpu_s->reg_st&FLAG_IE?'I':'-'));

		// Detects if has any available interruption request and handle it
		//log("Interruption %d\n", cpu_s->interrupt);
		if (cpu_s->interrupt){
			/*
			switch (cpu_s->interrupt){
				case INTR_DEBUGGER_INTERRUPTION:{
					log("Cpu Interruption: Debugger Interruption\n");
				}
				break;
				case INTR_DENIED_CODE_ACCESS:{
					log("Cpu Interruption: Denied Code Access\n");
				}
				break;
				case INTR_DENIED_DATA_ACCESS:{
					log("Cpu Interruption: Denied Data Access\n");
				}
				break;
				case INTR_DEVICE_UNAVAILABLE:{
					log("Cpu Interruption: Device Unavailable\n");
				}
				break;
				case INTR_DIRECTORY_FAULT:{
					log("Cpu Interruption: Directory Fault\n");
				}
				break;
				case INTR_DIVISION_BY_ZERO:{
					log("Cpu Interruption: Division by Zero\n");
				}
				break;
				case INTR_TIMER_INTERRUPTION:{
					log("Cpu Interruption: Timer interruption\n");
				}
				break;
				case INTR_INVALID_OPCODE:{
					log("Cpu Interruption: Invalid Opcode\n");
				}
				break;
				case INTR_PAGE_FAULT:{
					log("Cpu Interruption: Page Fault\n");
				}
				break;
				case INTR_PROTECTED_MODE_VIOLATION:{
					log("Cpu Interruption: Protected Mode Violation\n");
				}
				break;
				case INTR_SEGMENT_NOT_PRESENT:{
					log("Cpu Interruption: Segment not Available\n");
				}
				break;
				case INTR_SOFTWARE_INTERRUPTION:{
					log("Cpu Interruption: Software Interruption\n");
				}
				break;
			}
			*/
			cpuInterrupt(cpu_s);
			cpu_s->interrupt = INTR_NONE;
		}
		// Check for external available interruption
		else if (cpu_s->request_external && cpu_s->reg_st&FLAG_IE){
			cpu_s->interrupt = INTR_HARDWARE_INTERRUPTION;
			//log("Cpu Interruption: Hardware Interruption\n");
			cpuInterrupt(cpu_s);
			cpu_s->request_external = false;
		}
		//log("\n");
	}
}

