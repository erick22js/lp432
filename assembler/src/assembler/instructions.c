#include "base.h"


Instruction const isa[] = {
	{
		.mne = "adc",
		.encodes_len = 19,
		.encodes = {
			{
				.opcode = 0x80, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x81, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x82, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x83, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x83, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x83, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x83, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x83, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x83, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x83, .desc = 0x6,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x83, .desc = 0x7,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x83, .desc = 0x8,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x83, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x83, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x83, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x83, .desc = 0xC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x83, .desc = 0xD,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x83, .desc = 0xE,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x83, .desc = 0xF,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "add",
		.encodes_len = 19,
		.encodes = {
			{
				.opcode = 0x84, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x85, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x86, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x87, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x87, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x87, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x87, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x87, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x87, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x87, .desc = 0x6,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x87, .desc = 0x7,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x87, .desc = 0x8,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x87, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x87, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x87, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x87, .desc = 0xC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x87, .desc = 0xD,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x87, .desc = 0xE,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x87, .desc = 0xF,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "and",
		.encodes_len = 19,
		.encodes = {
			{
				.opcode = 0xB0, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xB1, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xB2, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xB3, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xB3, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0xB3, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0xB3, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xB3, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xB3, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xB3, .desc = 0x6,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xB3, .desc = 0x7,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xB3, .desc = 0x8,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0xB3, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xB3, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xB3, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xB3, .desc = 0xC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xB3, .desc = 0xD,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0xB3, .desc = 0xE,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xB3, .desc = 0xF,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "ba",
		.encodes_len = 4,
		.encodes = {
			{
				.opcode = 0x2B, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x2C, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x2D, .desc = COND_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x2E, .desc = CONDO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			}
		}
	},
	{
		.mne = "br",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x28, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x29, .desc = COND_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x2A, .desc = CONDO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "bsb",
		.encodes_len = 6,
		.encodes = {
			{
				.opcode = 0xBF, .desc = 0x6,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 }
				}
			},
			{
				.opcode = 0xBF, .desc = 0x7,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 }
				}
			},
			{
				.opcode = 0xBF, .desc = 0x8,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 }
				}
			},
			{
				.opcode = 0xBF, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 }
				}
			},
			{
				.opcode = 0xBF, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 }
				}
			},
			{
				.opcode = 0xBF, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 }
				}
			}
		}
	},
	{
		.mne = "bsf",
		.encodes_len = 6,
		.encodes = {
			{
				.opcode = 0xBF, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 }
				}
			},
			{
				.opcode = 0xBF, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 }
				}
			},
			{
				.opcode = 0xBF, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 }
				}
			},
			{
				.opcode = 0xBF, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 }
				}
			},
			{
				.opcode = 0xBF, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 }
				}
			},
			{
				.opcode = 0xBF, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 }
				}
			}
		}
	},
	{
		.mne = "bswap",
		.encodes_len = 2,
		.encodes = {
			{
				.opcode = 0xDD, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xDE, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "bt",
		.encodes_len = 6,
		.encodes = {
			{
				.opcode = 0xBE, .desc = 0x0,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xBE, .desc = 0x1,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xBE, .desc = 0x2,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xBE, .desc = 0x3,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_MEM8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xBE, .desc = 0x4,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_MEM16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xBE, .desc = 0x5,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_MEM32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "btc",
		.encodes_len = 2,
		.encodes = {
			{
				.opcode = 0xBE, .desc = 0x7,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xBE, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			}
		}
	},
	{
		.mne = "bts",
		.encodes_len = 2,
		.encodes = {
			{
				.opcode = 0xBE, .desc = 0x6,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xBE, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			}
		}
	},
	{
		.mne = "btt",
		.encodes_len = 2,
		.encodes = {
			{
				.opcode = 0xBE, .desc = 0x8,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xBE, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			}
		}
	},
	{
		.mne = "clrb",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x13, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "clrc",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x11, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "clri",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xF, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "clrn",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x17, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "clro",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x1B, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "clrt",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x3F, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "clrv",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x15, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "clrz",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x19, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "cmp",
		.encodes_len = 19,
		.encodes = {
			{
				.opcode = 0xA8, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xA9, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xAA, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xAB, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xAB, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0xAB, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0xAB, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xAB, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xAB, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xAB, .desc = 0x6,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xAB, .desc = 0x7,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xAB, .desc = 0x8,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0xAB, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xAB, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xAB, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xAB, .desc = 0xC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xAB, .desc = 0xD,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0xAB, .desc = 0xE,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xAB, .desc = 0xF,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "cvbth",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x4C, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x4D, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x4D, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			}
		}
	},
	{
		.mne = "cvbtw",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x48, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x49, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x49, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			}
		}
	},
	{
		.mne = "cvhtw",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x4A, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x4B, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x4B, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			}
		}
	},
	{
		.mne = "debug",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x2, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "dec",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0xE4, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xE5, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xE6, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "div",
		.encodes_len = 19,
		.encodes = {
			{
				.opcode = 0x98, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x99, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x9A, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x9B, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x9B, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x9B, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x9B, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x9B, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x9B, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x9B, .desc = 0x6,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x9B, .desc = 0x7,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x9B, .desc = 0x8,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x9B, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x9B, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x9B, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x9B, .desc = 0xC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x9B, .desc = 0xD,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x9B, .desc = 0xE,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x9B, .desc = 0xF,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "enter",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x34, .desc = NO_DESC,
				.params_len = 0
			},
			{
				.opcode = 0x35, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x36, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "f2xm1",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD2, .desc = 0xC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fadc",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD1, .desc = 0x0,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "fadd",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD1, .desc = 0x1,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "faddi",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD1, .desc = 0x2,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "facos",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD2, .desc = 0x7,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fasin",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD2, .desc = 0x6,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fatan",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD2, .desc = 0x8,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fatan2",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD2, .desc = 0x8,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "fcbrt",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD2, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fceil",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD3, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fcmp",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD2, .desc = 0x0,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "fcmpi",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD2, .desc = 0x1,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "fcos",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD2, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fcvfb",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD3, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fcvfh",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD3, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fcvfsb",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD3, .desc = 0xC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fcvfsh",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD3, .desc = 0xD,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fcvfsw",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD3, .desc = 0xE,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fcvfw",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD3, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fcvtb",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD3, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fcvth",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD3, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fcvtsb",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD3, .desc = 0x6,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fcvtsh",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD3, .desc = 0x7,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fcvtsw",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD3, .desc = 0x8,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fcvtw",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD3, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fdec",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD1, .desc = 0xE,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "fdiv",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD1, .desc = 0x9,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "fdsbb",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD1, .desc = 0xA,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO3 }
				}
			}
		}
	},
	{
		.mne = "fdsub",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD1, .desc = 0xB,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO3 }
				}
			}
		}
	},
	{
		.mne = "ffloor",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD3, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "finc",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD1, .desc = 0xD,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "flog",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD2, .desc = 0xD,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "flog2",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD2, .desc = 0xE,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "flog2x",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD2, .desc = 0xF,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "fmadc",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD1, .desc = 0x7,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO3 }
				}
			}
		}
	},
	{
		.mne = "fmadd",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD1, .desc = 0x8,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO3 }
				}
			}
		}
	},
	{
		.mne = "fmod",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD1, .desc = 0xC,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "fmul",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD1, .desc = 0x6,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "fmvd",
		.encodes_len = 4,
		.encodes = {
			{
				.opcode = 0xD0, .desc = 0x5,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0xD0, .desc = 0x6,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0xD0, .desc = 0x7,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_MEM64, .encode = ENCODE_MEM },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xD0, .desc = 0x8,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM64, .encode = ENCODE_MEM }
				}
			}
		}
	},
	{
		.mne = "fmvs",
		.encodes_len = 5,
		.encodes = {
			{
				.opcode = 0xD0, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0xD0, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0xD0, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0xD0, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xD0, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			}
		}
	},
	{
		.mne = "fneg",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD1, .desc = 0xF,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "fpopd",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD0, .desc = 0xA,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "fpops",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD0, .desc = 0x9,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "fpshd",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD0, .desc = 0xC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "fpshs",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD0, .desc = 0xB,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "fround",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD3, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fsbb",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD1, .desc = 0x3,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "fsin",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD2, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fsqrt",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD2, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fsub",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD1, .desc = 0x4,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "ftan",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD2, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "ftrunc",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD3, .desc = 0xF,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fxam",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD2, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fsteq",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD7, .desc = 0x0,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "fsteqz",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD7, .desc = 0x6,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fstreqz",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD7, .desc = 0x7,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "fstes",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD7, .desc = 0xE,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fstge",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD7, .desc = 0x4,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "fstgez",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD7, .desc = 0xC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fstgt",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD7, .desc = 0x2,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "fstgtz",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD7, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fstle",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD7, .desc = 0x5,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "fstlez",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD7, .desc = 0xD,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fstlt",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD7, .desc = 0x3,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "fstltz",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD7, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fstne",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD7, .desc = 0x1,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "fstnez",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD7, .desc = 0x8,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fstns",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD7, .desc = 0xF,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "fstrnez",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD7, .desc = 0x9,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "fsubi",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xD1, .desc = 0x5,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "halt",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xF8, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "hmul",
		.encodes_len = 2,
		.encodes = {
			{
				.opcode = 0x94, .desc = NO_DESC,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x95, .desc = NO_DESC,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			}
		}
	},
	{
		.mne = "hsmul",
		.encodes_len = 2,
		.encodes = {
			{
				.opcode = 0x96, .desc = NO_DESC,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x97, .desc = NO_DESC,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			}
		}
	},
	{
		.mne = "in",
		.encodes_len = 9,
		.encodes = {
			{
				.opcode = 0xF0, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xF1, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xF2, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xF3, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xF3, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xF3, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xF3, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0xF3, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0xF3, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "inc",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0xE0, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xE1, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xE2, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "int",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x32, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "iret",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x31, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "ja",
		.encodes_len = 4,
		.encodes = {
			{
				.opcode = 0x23, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x24, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x25, .desc = COND_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x26, .desc = CONDO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			}
		}
	},
	{
		.mne = "jr",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x20, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x21, .desc = COND_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x22, .desc = CONDO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "jadp",
		.encodes_len = 2,
		.encodes = {
			{
				.opcode = 0xA, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0xB, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "jads",
		.encodes_len = 2,
		.encodes = {
			{
				.opcode = 0x6, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x7, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "jaep",
		.encodes_len = 2,
		.encodes = {
			{
				.opcode = 0x8, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x9, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "jaes",
		.encodes_len = 2,
		.encodes = {
			{
				.opcode = 0x4, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x5, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "jasp",
		.encodes_len = 2,
		.encodes = {
			{
				.opcode = 0xC, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0xD, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "lea",
		.encodes_len = 10,
		.encodes = {
			{
				.opcode = 0x60, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x61, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x62, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x63, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x63, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x63, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x64, .desc = NO_DESC,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO },
					{ "", .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x65, .desc = NO_DESC,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO },
					{ "", .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x66, .desc = NO_DESC,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO },
					{ "", .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x67, .desc = NO_DESC,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO },
					{ "", .type = TYPE_IMMS32, .encode = ENCODE_MV32 }
				}
			}
		}
	},
	{
		.mne = "leave",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x37, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "lrot",
		.encodes_len = 12,
		.encodes = {
			{
				.opcode = 0xC8, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xC9, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xCA, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xCB, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xCB, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xCB, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xCB, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xCB, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xCB, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xCB, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xCB, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xCB, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			}
		}
	},
	{
		.mne = "lsh",
		.encodes_len = 12,
		.encodes = {
			{
				.opcode = 0xC0, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xC1, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xC2, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xC3, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xC3, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xC3, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xC3, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xC3, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xC3, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xC3, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xC3, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xC3, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			}
		}
	},
	{
		.mne = "mod",
		.encodes_len = 19,
		.encodes = {
			{
				.opcode = 0xA0, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xA1, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xA2, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xA3, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xA3, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0xA3, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0xA3, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xA3, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xA3, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xA3, .desc = 0x6,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xA3, .desc = 0x7,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xA3, .desc = 0x8,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0xA3, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xA3, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xA3, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xA3, .desc = 0xC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xA3, .desc = 0xD,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0xA3, .desc = 0xE,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xA3, .desc = 0xF,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "mov",
		.encodes_len = 21,
		.encodes = {
			{
				.opcode = 0x70, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x71, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x72, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x73, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x73, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x73, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x73, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x73, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x73, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x73, .desc = 0x6,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x73, .desc = 0x7,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x73, .desc = 0x8,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x73, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x73, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x73, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x73, .desc = 0xC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x73, .desc = 0xD,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x73, .desc = 0xE,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x77, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x77, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x77, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "mul",
		.encodes_len = 19,
		.encodes = {
			{
				.opcode = 0x90, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x91, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x92, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x93, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x93, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x93, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x93, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x93, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x93, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x93, .desc = 0x6,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x93, .desc = 0x7,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x93, .desc = 0x8,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x93, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x93, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x93, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x93, .desc = 0xC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x93, .desc = 0xD,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x93, .desc = 0xE,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x93, .desc = 0xF,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "mvab",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0x6,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0x6,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0x6,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "mvae",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0x8,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0x8,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0x8,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "mvbe",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0x9,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0x9,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0x9,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "mvbl",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0x7,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0x7,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0x7,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "mveq",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0x0,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0x0,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0x0,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "mveqz",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0xA,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0xA,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0xA,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "mvfir",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x3A, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IR, .encode = ENCODE_REGO }
				}
			}
		}
	},
	{
		.mne = "mvfisp",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x3C, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "mvge",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0x4,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0x4,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0x4,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "mvgez",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0xE,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0xE,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0xE,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "mvgt",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0x2,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0x2,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0x2,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "mvgtz",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0xC,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0xC,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0xC,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "mvle",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0x5,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0x5,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0x5,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "mvlez",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0xF,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0xF,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0xF,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "mvlt",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0x3,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0x3,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0x3,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "mvltz",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0xD,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0xD,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0xD,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "mvne",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0x1,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0x1,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0x1,
				.params_len = 4,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "mvnez",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0xB,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0xB,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0xB,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "mvtisp",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x3D, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "mvtitd",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x39, .desc = 0x2,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "mvtptd",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x39, .desc = 0x1,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "mvtsr",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x38, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_SR, .encode = ENCODE_REGO },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "mvtstd",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x39, .desc = 0x0,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "neg",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0xE8, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xE9, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xEA, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "nop",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x0, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "not",
		.encodes_len = 3,
		.encodes = {
			{
				.opcode = 0xEC, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xED, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xEE, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "out",
		.encodes_len = 9,
		.encodes = {
			{
				.opcode = 0xF4, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xF5, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xF6, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xF7, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xF7, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xF7, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xF7, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xF7, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xF7, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "or",
		.encodes_len = 19,
		.encodes = {
			{
				.opcode = 0xB4, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xB5, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xB6, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xB7, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xB7, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0xB7, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0xB7, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xB7, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xB7, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xB7, .desc = 0x6,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xB7, .desc = 0x7,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xB7, .desc = 0x8,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0xB7, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xB7, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xB7, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xB7, .desc = 0xC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xB7, .desc = 0xD,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0xB7, .desc = 0xE,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xB7, .desc = 0xF,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "pnop",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x1, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "pop",
		.encodes_len = 6,
		.encodes = {
			{
				.opcode = 0x50, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x51, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x52, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x53, .desc = 0x0,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x53, .desc = 0x1,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x53, .desc = 0x2,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			}
		}
	},
	{
		.mne = "poplst",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x5B, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "popst",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x5C, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "psh",
		.encodes_len = 9,
		.encodes = {
			{
				.opcode = 0x54, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x55, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x56, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x57, .desc = 0x0,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x57, .desc = 0x1,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x57, .desc = 0x2,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x58, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x59, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x5A, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			}
		}
	},
	{
		.mne = "pshlst",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x5D, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "pshst",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x5E, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "ret",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x30, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "rrot",
		.encodes_len = 12,
		.encodes = {
			{
				.opcode = 0xCC, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xCD, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xCE, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xCF, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xCF, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xCF, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xCF, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xCF, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xCF, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xC3, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xCF, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xCF, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			}
		}
	},
	{
		.mne = "rsh",
		.encodes_len = 12,
		.encodes = {
			{
				.opcode = 0xC4, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xC5, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xC6, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xC7, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xC7, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xC7, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xC7, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xC7, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xC7, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xC7, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xC7, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xC7, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			}
		}
	},
	{
		.mne = "sbb",
		.encodes_len = 19,
		.encodes = {
			{
				.opcode = 0x88, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x89, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x8A, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x8B, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x8B, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x8B, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x8B, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8B, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8B, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8B, .desc = 0x6,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x8B, .desc = 0x7,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x8B, .desc = 0x8,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x8B, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8B, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8B, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8B, .desc = 0xC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x8B, .desc = 0xD,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x8B, .desc = 0xE,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x8B, .desc = 0xF,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "sdiv",
		.encodes_len = 19,
		.encodes = {
			{
				.opcode = 0x9C, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x9D, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x9E, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x9F, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x9F, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x9F, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x9F, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x9F, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x9F, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x9F, .desc = 0x6,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x9F, .desc = 0x7,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x9F, .desc = 0x8,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x9F, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x9F, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x9F, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x9F, .desc = 0xC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x9F, .desc = 0xD,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x9F, .desc = 0xE,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x9F, .desc = 0xF,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "sea",
		.encodes_len = 10,
		.encodes = {
			{
				.opcode = 0x68, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x69, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x6A, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x6B, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x6B, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x6B, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x6C, .desc = NO_DESC,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO },
					{ "", .type = TYPE_IMMS16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x6D, .desc = NO_DESC,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO },
					{ "", .type = TYPE_IMMS16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x6E, .desc = NO_DESC,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO },
					{ "", .type = TYPE_IMMS16, .encode = ENCODE_MV16 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x67, .desc = NO_DESC,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO },
					{ "", .type = TYPE_IMMS32, .encode = ENCODE_MV32 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "setb",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x12, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "setc",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x10, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "seti",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xE, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "setn",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x16, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "seto",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x1A, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "sett",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x3E, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "setv",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x14, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "setz",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x18, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "smod",
		.encodes_len = 19,
		.encodes = {
			{
				.opcode = 0xA4, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xA5, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xA6, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xA7, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xA7, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0xA7, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0xA7, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xA7, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xA7, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xA7, .desc = 0x6,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xA7, .desc = 0x7,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xA7, .desc = 0x8,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0xA7, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xA7, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xA7, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xA7, .desc = 0xC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xA7, .desc = 0xD,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0xA7, .desc = 0xE,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xA7, .desc = 0xF,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "stab",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0x6,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "stae",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0x8,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "stbe",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0x9,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "stbl",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0x7,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "steq",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0x0,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "steqz",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "stge",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0x4,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "stgez",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0xE,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "stgt",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0x2,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "stgtz",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0xC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "stop",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xFA, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "stle",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0x5,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "stlez",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0xF,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "stlt",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0x3,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "stltz",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0xD,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "stne",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0x1,
				.params_len = 3,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "stnez",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "sub",
		.encodes_len = 19,
		.encodes = {
			{
				.opcode = 0x8C, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x8D, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x8E, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x8F, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x8F, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x8F, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x8F, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8F, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8F, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8F, .desc = 0x6,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x8F, .desc = 0x7,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x8F, .desc = 0x8,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x8F, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8F, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8F, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8F, .desc = 0xC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x8F, .desc = 0xD,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x8F, .desc = 0xE,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x8F, .desc = 0xF,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "togc",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x1C, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "togn",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x1D, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "togo",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x1F, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "togz",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x1E, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "updfp",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x5F, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "wait",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0xF9, .desc = NO_DESC,
				.params_len = 0
			}
		}
	},
	{
		.mne = "xbch",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x2F, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "xchg",
		.encodes_len = 7,
		.encodes = {
			{
				.opcode = 0x78, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x79, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x7A, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x7B, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x7B, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x7B, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0xD0, .desc = 0xD,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM1 },
					{ "", .type = TYPE_FPR, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "xjmp",
		.encodes_len = 1,
		.encodes = {
			{
				.opcode = 0x27, .desc = NO_DESC,
				.params_len = 1,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "xor",
		.encodes_len = 19,
		.encodes = {
			{
				.opcode = 0xB8, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xB9, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xBA, .desc = NO_DESC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0xBB, .desc = 0x0,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xBB, .desc = 0x1,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0xBB, .desc = 0x2,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0xBB, .desc = 0x3,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR8, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xBB, .desc = 0x4,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xBB, .desc = 0x5,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xBB, .desc = 0x6,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xBB, .desc = 0x7,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xBB, .desc = 0x8,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0xBB, .desc = 0x9,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR16, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xBB, .desc = 0xA,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xBB, .desc = 0xB,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0xBB, .desc = 0xC,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xBB, .desc = 0xD,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0xBB, .desc = 0xE,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0xBB, .desc = 0xF,
				.params_len = 2,
				.params = {
					{ "", .type = TYPE_GR32, .encode = ENCODE_REGM },
					{ "", .type = TYPE_MEMS16, .encode = ENCODE_MV16 }
				}
			}
		}
	}
};
int const isa_len = sizeof(isa)/sizeof(Instruction);
