#include "assembler/assembler.h"



int main(int args, char** argv) {
	const char* code = "mov eax, 175";

	uint8* bin = null;
	uint32 bin_size = 0;

	asmAssemblyString(code, &bin, &bin_size);

	// Dump hex code to preview
	log("\nOutput Binary\n");
	for (int l = 0; l<bin_size; l += 16){
		for (int r = 0; (l+r)<bin_size && r<16; r++){
			log(" %.2X", bin[l+r]);
		}
		log("\n");
	}

	system("pause");
	return 0;
}