#include "components/components.h"


int main(int args, char** argv) {
	vmSetup();
	spInit();

	_Bool running = 1;
	while (running){
		if (spHandle()){
			running = 0;
		}
	}
	spEnd();
	return 0;
}
