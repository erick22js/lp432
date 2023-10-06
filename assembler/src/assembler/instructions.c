#include "base.h"


Ist isa[] = {
	{
		.mne = "adc",
		.encodes_length = 19,
		.encodes = {
			{
				.opcode = 0x80, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM },
					{ .type = TYPE_R8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x81, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_R16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x82, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_R32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x83, .desc = 0x0,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x83, .desc = 0x1,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x83, .desc = 0x2,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x83, .desc = 0x3,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x83, .desc = 0x4,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x83, .desc = 0x5,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x83, .desc = 0x6,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x83, .desc = 0x7,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x83, .desc = 0x8,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x83, .desc = 0x9,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x83, .desc = 0xA,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x83, .desc = 0xB,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x83, .desc = 0xC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x83, .desc = 0xD,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x83, .desc = 0xE,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x83, .desc = 0xF,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEMS16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "add",
		.encodes_length = 19,
		.encodes = {
			{
				.opcode = 0x84, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM },
					{ .type = TYPE_R8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x85, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_R16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x86, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_R32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x87, .desc = 0x0,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x87, .desc = 0x1,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x87, .desc = 0x2,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x87, .desc = 0x3,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x87, .desc = 0x4,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x87, .desc = 0x5,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x87, .desc = 0x6,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x87, .desc = 0x7,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x87, .desc = 0x8,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x87, .desc = 0x9,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x87, .desc = 0xA,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x87, .desc = 0xB,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x87, .desc = 0xC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x87, .desc = 0xD,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x87, .desc = 0xE,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x87, .desc = 0xF,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEMS16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "ba",
		.encodes_length = 4,
		.encodes = {
			{
				.opcode = 0x2B, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x2C, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x2D, .desc = COND_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x2E, .desc = CONDO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			}
		}
	},
	{
		.mne = "br",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x28, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x29, .desc = COND_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x2A, .desc = CONDO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "clrb",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x13, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "clrc",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x11, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "clri",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0xF, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "clrn",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x17, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "clro",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x1B, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "clrv",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x15, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "clrz",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x19, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "debug",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x2, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "ja",
		.encodes_length = 4,
		.encodes = {
			{
				.opcode = 0x23, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x24, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x25, .desc = COND_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x26, .desc = CONDO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			}
		}
	},
	{
		.mne = "jr",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x20, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x21, .desc = COND_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x22, .desc = CONDO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "jadp",
		.encodes_length = 2,
		.encodes = {
			{
				.opcode = 0xA, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0xB, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "jads",
		.encodes_length = 2,
		.encodes = {
			{
				.opcode = 0x6, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x7, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "jaep",
		.encodes_length = 2,
		.encodes = {
			{
				.opcode = 0x8, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x9, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "jaes",
		.encodes_length = 2,
		.encodes = {
			{
				.opcode = 0x4, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x5, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "jasp",
		.encodes_length = 2,
		.encodes = {
			{
				.opcode = 0xC, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0xD, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "nop",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x0, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "pnop",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x1, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "sbb",
		.encodes_length = 19,
		.encodes = {
			{
				.opcode = 0x88, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM },
					{ .type = TYPE_R8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x89, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_R16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x8A, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_R32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x8B, .desc = 0x0,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x8B, .desc = 0x1,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x8B, .desc = 0x2,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x8B, .desc = 0x3,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8B, .desc = 0x4,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8B, .desc = 0x5,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8B, .desc = 0x6,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x8B, .desc = 0x7,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x8B, .desc = 0x8,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x8B, .desc = 0x9,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8B, .desc = 0xA,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8B, .desc = 0xB,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8B, .desc = 0xC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x8B, .desc = 0xD,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x8B, .desc = 0xE,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x8B, .desc = 0xF,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEMS16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "setb",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x12, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "setc",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x10, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "seti",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0xE, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "setn",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x16, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "seto",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x1A, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "setv",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x14, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "setz",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x18, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "sub",
		.encodes_length = 19,
		.encodes = {
			{
				.opcode = 0x8C, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM },
					{ .type = TYPE_R8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x8D, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_R16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x8E, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_R32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x8F, .desc = 0x0,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x8F, .desc = 0x1,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x8F, .desc = 0x2,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x8F, .desc = 0x3,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8F, .desc = 0x4,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8F, .desc = 0x5,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8F, .desc = 0x6,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x8F, .desc = 0x7,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x8F, .desc = 0x8,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x8F, .desc = 0x9,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8F, .desc = 0xA,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8F, .desc = 0xB,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x8F, .desc = 0xC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x8F, .desc = 0xD,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x8F, .desc = 0xE,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x8F, .desc = 0xF,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEMS16, .encode = ENCODE_MV16 }
				}
			}
		}
	},
	{
		.mne = "togc",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x1C, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "togn",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x1D, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "togo",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x1F, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "togz",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x1E, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "xbch",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x2F, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "xjmp",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x27, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM }
				}
			}
		}
	}
};
const int isa_length = sizeof(isa)/sizeof(Ist);
