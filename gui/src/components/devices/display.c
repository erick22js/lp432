#include "display.h"
#include "vga_font.h"



/*
	Symbols Definition
*/

#define PIXELS_PER_TICK 32

#define CTRL_STATE self->api_data[0]
#define CTRL_CYCLES self->api_data[1]
#define CTRL_X_POS self->api_data[2]
#define CTRL_Y_POS self->api_data[3]

#define REG_WIDTH ((uint32*)self->regs)[2]
#define REG_HEIGHT ((uint32*)self->regs)[3]
#define REG_DATA_BASE ((uint32*)self->regs)[4]
#define REG_PAL_BASE ((uint32*)self->regs)[5]
#define REG_DFLAGS ((uint32*)self->regs)[6]


/*
	Handling Callback Functions
*/

uint8 dsRead(Device* self, uint8 reg){
	return self->regs[reg];
}

void dsWrite(Device* self, uint8 reg, uint8 data){
	if (reg >= 16){
		self->regs[reg] = data;
	}
}

void dsStep(Device* self, uint32 cycles){
	// CYCLE SYNC
	CTRL_CYCLES += cycles;
	if (CTRL_CYCLES < PIXELS_PER_TICK){
		return;
	}
	CTRL_CYCLES -= PIXELS_PER_TICK;

	// STOP STATE
	if (CTRL_STATE==0){
		return;
	}
	// PLOT STATE
	else if (CTRL_STATE==1){
		for (uint32 i = 0; i<PIXELS_PER_TICK; i++){
			uint32 x = CTRL_X_POS+i, y = CTRL_Y_POS;
			uint32 data_adr = REG_DATA_BASE + ((x/FONT_WIDTH) + (y/FONT_HEIGHT)*(REG_WIDTH/FONT_WIDTH))*4;
			uint32 data = devBusRead32(self, data_adr);

			uint8 chr1 = data&0xFF, chr2 = (data>>8)&0xFF;
			uint8 cdata_fore = (data>>16)&0xFF;
			uint8 pitchu_fore =  ((cdata_fore&0x80)?0x42:0);
			uint8 pitchd_fore =  ((cdata_fore&0x40)?0x11:0);
			uint32 color_fore = ((cdata_fore&0x20)?0x000088|(pitchd_fore):0)    |((cdata_fore&0x10)?0x000024|(pitchu_fore):0)|
				((cdata_fore&0x08)?0x008800|(pitchd_fore<<8):0) |((cdata_fore&0x04)?0x002400|(pitchu_fore<<8):0)|
				((cdata_fore&0x02)?0x880000|(pitchd_fore<<16):0)|((cdata_fore&0x01)?0x240000|(pitchu_fore<<16):0);
			uint8 cdata_back = (data>>24)&0xFF;
			uint8 pitchu_back =  ((cdata_back&0x80)?0x42:0);
			uint8 pitchd_back =  ((cdata_back&0x40)?0x11:0);
			uint32 color_back = ((cdata_back&0x20)?0x000088|(pitchd_back):0)    |((cdata_back&0x10)?0x000024|(pitchu_back):0)|
				((cdata_back&0x08)?0x008800|(pitchd_back<<8):0) |((cdata_back&0x04)?0x002400|(pitchu_back<<8):0)|
				((cdata_back&0x02)?0x880000|(pitchd_back<<16):0)|((cdata_back&0x01)?0x240000|(pitchu_back<<16):0);

			uint32 off_x = x%FONT_WIDTH, off_y = y%FONT_HEIGHT;
			uint32 pix_tile1 = vga_font[chr1*FONT_WIDTH*FONT_HEIGHT + off_y*FONT_WIDTH + off_x],
				pix_tile2 = vga_font[chr2*FONT_WIDTH*FONT_HEIGHT + off_y*FONT_WIDTH + off_x];

			((uint32*)(self->api_refs[0]))[y*REG_WIDTH + x] = pix_tile1? color_fore: color_back;
		}
		CTRL_X_POS += PIXELS_PER_TICK;
		if (CTRL_X_POS >= REG_WIDTH){
			CTRL_X_POS -= REG_WIDTH;
			CTRL_Y_POS++;

			if (CTRL_Y_POS >= REG_HEIGHT){
				CTRL_STATE = 2;
			}
		}
	}
	// IDLE STATE
	else if (CTRL_STATE==2){
		CTRL_X_POS += PIXELS_PER_TICK;
		if (CTRL_X_POS >= REG_WIDTH){
			CTRL_X_POS -= REG_WIDTH;
			CTRL_Y_POS++;

			if (CTRL_Y_POS >= REG_HEIGHT*2){
				CTRL_Y_POS = 0;
				CTRL_STATE = 1;
				self->api_data[15]++; // Index change used as indicator for frame update refresh
			}
		}
	}
}


/*
	Display Device Functions
*/

void dsSetup(Device *self, Monitor *mntr) {
	// Configure Device Object
	memset(self, 0, sizeof(self));
	self->read = dsRead;
	self->write = dsWrite;
	self->step = dsStep;
	self->active = true;

	// Configure Control Properties
	CTRL_STATE = 1; // State
	CTRL_CYCLES = 0; // Cycles Counter
	CTRL_X_POS = 0; // X counter
	CTRL_X_POS = 0; // Y counter
	self->api_refs[0] = mntr->buffer; // Host Pixels Buffer Pointer

	// Configure Registers
	self->regs[0] = 1; // Device Type
	self->regs[1] = 0;
	self->regs[2] = 0; // Device Version
	self->regs[3] = 0;
	self->regs[4] = 0; // Device Varyation
	self->regs[5] = 0; // Device Vendor
	self->regs[6] = 0; // Device Control Flags
	self->regs[7] = 0; // Ready State
	REG_WIDTH = mntr->buff_wid; // Display Width
	REG_HEIGHT = mntr->buff_hei; // Display Height
	REG_DATA_BASE = 0; // Data Buffer Base Address
	REG_PAL_BASE = 0; // Palette Buffer Base Address
	REG_DFLAGS = 0; // Display Flags
}

void dsDestroy(Device *dev) {

}

