#include "assembler/assembler.h"



int main(int args, char** argv) {
	const char* code = "adc gl, bl\nadc eax, 9:Half";

	uint8* bin = null;
	uint32 bin_size = 0;

	asmAssemblyString(code, &bin, &bin_size);

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