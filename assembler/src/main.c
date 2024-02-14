#include "assembler/asm.h"


int main(int argc, char *argv[]){
	// Setting up the assembly log to user and technical
	Path log;
	if (argc > 2){
		pathOpen(log, argv[2]);
		logInit(log, true, null, true);
	}
	else {
		logInit(null, true, null, true);
	}
	
	// Opening path for assembly source file
	Path src;
	if (argc > 1){
		pathOpen(src, argv[1]);
	}
	else {
		pathOpen(src, "C:/Users/erick/Documents/meus-projetos/c/lp432/tests/test_groupset/main.asm");
	}
	logUserInfo("Assembling input source: %s\n", src);

	// Opening path for output file
	Path out;
	pathOpen(out, src);
	{
		int dot = -1;
		char *pc = out;
		while (*pc){
			if (*pc == '.'){
				dot = pc-out;
			}
			pc++;
		}
		if (dot==-1){
			*pc = '.';
			*(pc+1) = 'o';
			*(pc+2) = 0;
		}
		else {
			out[dot+1] = 'o';
			out[dot+2] = 0;
		}
	}
	logUserInfo("Output file: %s\n", out);

	// Setting up the binary info holders and assembling source file
	u8* bin = null;
	u32 bin_size = 0;
	if (asmFile(src, &bin, &bin_size)){
		// Error in assembly
		// Flushing logs and waiting for user input to end
		logFlush();
		system("pause");
		return 0;
	}
	
	//	Outputing result binary file
	FILE *output = fopen(out, "wb");
	if (output){
		fwrite(bin, 1, bin_size, output);
		fclose(output);
	}
	else {
		logUserInfo("\nErr: Output file \"%s\" could not be open!\n", out);
	}

	// Printing the binary to console
	/*
	logUserInfo("\nBinary Output\n");
	for (int i=0; i<(int)bin_size; i+=16){
		for (int o=0; o<16 && (i+o)<(int)bin_size; o++){
			int val = bin[i+o];
			logUserInfo(o==0? "\t%.2X": " %.2X", val);
		}
		logUserInfo("\n");
	}
	*/
	
	// Flushing logs and waiting for user input to end
	logFlush();
	system("pause");
	return 0;
}