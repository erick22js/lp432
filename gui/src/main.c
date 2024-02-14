#include "components/components.h"


IniObject *config;
IniObject *setup;

int main(int args, char** argv) {
	config = iniObjectLoad("config.ini");
	setup = iniObjectLoad("setup.ini");

	if (!config){
		config = iniObjectCreate();
		iniObjectSetKeyAsBool(config, "initialized", INI_TRUE);
		iniObjectSetKeyAsText(config, "default_rom_path", "");
		iniObjectSetKeyAsHex(config, "default_rom_offset", 0x8000);
		iniObjectSetKeyAsInteger(config, "default_rom_size", 0x100);
		iniObjectSave("config.ini", config);
	}
	if (!setup){
		setup = iniObjectCreate();
		iniObjectSetKeyAsInteger(setup, "ramsize", 1024*1024*8);
		iniObjectSetKeyAsText(setup, "rompath", "");
		iniObjectSetKeyAsHex(setup, "romoffset", 0x8000);
		iniObjectSetKeyAsHex(setup, "startadr", 0x8000);
		iniObjectSave("setup.ini", setup);
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
