#include "setup.h"


int main(int args, char** argv){
	vmSetup();
	vmReset();

	busWrite(0x0000, 0x0);
	busWrite(0x0001, 0x10);
	busWrite(0x0002, 0x73);
	busWrite(0x0003, 0x10);
	busWrite(0x0004, 0x55);
	busWrite(0x0005, 0x97);

	vmRun();

	system("pause");
	return 0;
}