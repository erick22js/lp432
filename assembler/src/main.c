#include "assembler/assembler.h"



int main(int args, char** argv) {
	//const char* code = "";
	
	uint8* bin = null;
	uint32 bin_size = 0;

	char input[256], output[256];
	if (args>1){
		printf("%s\n", argv[1]);
		sprintf_s(input, sizeof(input)-1, "%s", argv[1]);
	}
	else {
		sprintf_s(input, sizeof(input)-1, "%s", "tests/main.asm");
	}
	sprintf_s(output, sizeof(output)-1, "%s", input);
	{
		int dot = -1;
		char *pc = output;
		while (*pc){
			if (*pc == '.'){
				dot = pc-output;
			}
			pc++;
		}
		if (dot==-1){
			*pc = '.';
			*(pc+1) = 'o';
			*(pc+2) = 0;
		}
		else {
			output[dot+1] = 'o';
			output[dot+2] = 0;
		}
	}

	remove(output);
	if (!asmAssemblyFile(input, &bin, &bin_size)){
		FILE *out = NULL;
		if (!fopen_s(&out, output, "wb")){
			fwrite(bin, 1, bin_size, out);
		}
	}

	// Dump hex code to preview
	log("\nOutput Binary\n");
	for (int l = 0; l<(int)bin_size; l += 16){
		for (int r = 0; (l+r)<(int)bin_size && r<16; r++){
			log("%s%.2X", (r!=0?" ":""), bin[l+r]);
		}
		log("\n");
	}

	system("pause");
	return 0;
}