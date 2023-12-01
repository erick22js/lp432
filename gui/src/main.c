#include "components/components.h"


IniObject *config;

int main(int args, char** argv) {
	config = iniObjectLoad("config.ini");

	if (!config){
		config = iniObjectCreate();
		iniObjectSetKeyAsBool(config, "initialized", INI_TRUE);
	}

	vmSetup();
	spInit();

	_Bool running = 1;
	while (running){
		if (spHandle()){
			running = 0;
		}
	}
	spEnd();

	cfgFlush();
	return 0;
}
