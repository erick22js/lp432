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
		.mne = "cvbth",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x4C, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_R8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x4D, .desc = 0x0,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x4D, .desc = 0x1,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			}
		}
	},
	{
		.mne = "cvbtw",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x48, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_R8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x49, .desc = 0x0,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x49, .desc = 0x1,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			}
		}
	},
	{
		.mne = "cvhtw",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x4A, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_R16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x4B, .desc = 0x0,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x4B, .desc = 0x1,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
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
		.mne = "enter",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x34, .desc = NO_DESC,
				.params_length = 0
			},
			{
				.opcode = 0x35, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x36, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "int",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x32, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "iret",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x31, .desc = NO_DESC,
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
		.mne = "lea",
		.encodes_length = 10,
		.encodes = {
			{
				.opcode = 0x60, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM },
					{ .type = TYPE_R32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x61, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_R32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x62, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_R32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x63, .desc = 0x0,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x63, .desc = 0x1,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x63, .desc = 0x2,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x64, .desc = NO_DESC,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM },
					{ .type = TYPE_R32, .encode = ENCODE_REGO },
					{ .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x65, .desc = NO_DESC,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_R32, .encode = ENCODE_REGO },
					{ .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x66, .desc = NO_DESC,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_R32, .encode = ENCODE_REGO },
					{ .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x67, .desc = NO_DESC,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_R32, .encode = ENCODE_REGO },
					{ .type = TYPE_IMMS32, .encode = ENCODE_MV32 }
				}
			}
		}
	},
	{
		.mne = "leave",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x37, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "mov",
		.encodes_length = 21,
		.encodes = {
			{
				.opcode = 0x70, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM },
					{ .type = TYPE_R8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x71, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_R16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x72, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_R32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x74, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x75, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x76, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			},
			{
				.opcode = 0x73, .desc = 0x0,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x73, .desc = 0x1,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMMS16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x73, .desc = 0x2,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_IMMS8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x73, .desc = 0x3,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x73, .desc = 0x4,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x73, .desc = 0x5,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x73, .desc = 0x6,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x73, .desc = 0x7,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x73, .desc = 0x8,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x73, .desc = 0x9,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x73, .desc = 0xA,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x73, .desc = 0xB,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x77, .desc = 0x0,
				.params_length = 2,
				.params = {
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM },
					{ .type = TYPE_R8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x77, .desc = 0x1,
				.params_length = 2,
				.params = {
					{ .type = TYPE_MEM16, .encode = ENCODE_MEM },
					{ .type = TYPE_R16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x77, .desc = 0x2,
				.params_length = 2,
				.params = {
					{ .type = TYPE_MEM32, .encode = ENCODE_MEM },
					{ .type = TYPE_R32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "mvab",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0x6,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0x6,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0x6,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "mvae",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0x8,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0x8,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0x8,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "mvbe",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0x9,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0x9,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0x9,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "mvbl",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0x7,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0x7,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0x7,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "mveq",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0x0,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0x0,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0x0,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "mveqz",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0xA,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0xA,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0xA,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "mvfir",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x3A, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_IR, .encode = ENCODE_REGO }
				}
			}
		}
	},
	{
		.mne = "mvfisp",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x3C, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "mvge",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0x4,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0x4,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0x4,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "mvgez",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0xE,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0xE,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0xE,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "mvgt",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0x2,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0x2,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0x2,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "mvgtz",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0xC,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0xC,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0xC,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "mvle",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0x5,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0x5,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0x5,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "mvlez",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0xF,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0xF,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0xF,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "mvlt",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0x3,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0x3,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0x3,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "mvltz",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0xD,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0xD,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0xD,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "mvne",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0x1,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0x1,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0x1,
				.params_length = 4,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "mvnez",
		.encodes_length = 3,
		.encodes = {
			{
				.opcode = 0x44, .desc = 0xB,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x45, .desc = 0xB,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			},
			{
				.opcode = 0x46, .desc = 0xB,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_IMM32, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "mvtas",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x38, .desc = 0x3,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "mvtbs",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x38, .desc = 0x4,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "mvtcs",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x38, .desc = 0x0,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "mvtds",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x38, .desc = 0x2,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "mvtes",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x38, .desc = 0x5,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "mvtfs",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x38, .desc = 0x6,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "mvtgs",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x38, .desc = 0x7,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "mvtisp",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x3D, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "mvtitd",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x39, .desc = 0x2,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "mvtptd",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x39, .desc = 0x1,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "mvtss",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x38, .desc = 0x1,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM }
				}
			}
		}
	},
	{
		.mne = "mvtstd",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x39, .desc = 0x0,
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
		.mne = "pop",
		.encodes_length = 6,
		.encodes = {
			{
				.opcode = 0x50, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x51, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x52, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x53, .desc = 0x0,
				.params_length = 1,
				.params = {
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x53, .desc = 0x1,
				.params_length = 1,
				.params = {
					{ .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x53, .desc = 0x2,
				.params_length = 1,
				.params = {
					{ .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			}
		}
	},
	{
		.mne = "poplst",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x5B, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "popst",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x5C, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "psh",
		.encodes_length = 9,
		.encodes = {
			{
				.opcode = 0x54, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x55, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x56, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x57, .desc = 0x0,
				.params_length = 1,
				.params = {
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x57, .desc = 0x1,
				.params_length = 1,
				.params = {
					{ .type = TYPE_MEM16, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x57, .desc = 0x2,
				.params_length = 1,
				.params = {
					{ .type = TYPE_MEM32, .encode = ENCODE_MEM }
				}
			},
			{
				.opcode = 0x58, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_IMM8, .encode = ENCODE_MV8 }
				}
			},
			{
				.opcode = 0x59, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_IMM16, .encode = ENCODE_MV16 }
				}
			},
			{
				.opcode = 0x5A, .desc = NO_DESC,
				.params_length = 1,
				.params = {
					{ .type = TYPE_IMM32, .encode = ENCODE_MV32 }
				}
			}
		}
	},
	{
		.mne = "pshlst",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x5D, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "pshst",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x5E, .desc = NO_DESC,
				.params_length = 0
			}
		}
	},
	{
		.mne = "ret",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x30, .desc = NO_DESC,
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
		.mne = "sea",
		.encodes_length = 10,
		.encodes = {
			{
				.opcode = 0x68, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGO },
					{ .type = TYPE_R8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x69, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGO },
					{ .type = TYPE_R16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x6A, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGO },
					{ .type = TYPE_R32, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x6B, .desc = 0x0,
				.params_length = 2,
				.params = {
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM },
					{ .type = TYPE_R8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x6B, .desc = 0x1,
				.params_length = 2,
				.params = {
					{ .type = TYPE_MEM16, .encode = ENCODE_MEM },
					{ .type = TYPE_R16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x6B, .desc = 0x2,
				.params_length = 2,
				.params = {
					{ .type = TYPE_MEM32, .encode = ENCODE_MEM },
					{ .type = TYPE_R32, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x6C, .desc = NO_DESC,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGO },
					{ .type = TYPE_IMMS16, .encode = ENCODE_MV16 },
					{ .type = TYPE_R8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x6D, .desc = NO_DESC,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGO },
					{ .type = TYPE_IMMS16, .encode = ENCODE_MV16 },
					{ .type = TYPE_R16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x6E, .desc = NO_DESC,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGO },
					{ .type = TYPE_IMMS16, .encode = ENCODE_MV16 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x67, .desc = NO_DESC,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGO },
					{ .type = TYPE_IMMS32, .encode = ENCODE_MV32 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM }
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
		.mne = "stab",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0x6,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "stae",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0x8,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "stbe",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0x9,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "stbl",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0x7,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "steq",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0x0,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "steqz",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0xA,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "stge",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0x4,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "stgez",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0xE,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "stgt",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0x2,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "stgtz",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0xC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "stle",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0x5,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "stlez",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0xF,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "stlt",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0x3,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "stltz",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0xD,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
			}
		}
	},
	{
		.mne = "stne",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0x1,
				.params_length = 3,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 },
					{ .type = TYPE_R32, .encode = ENCODE_REGO2 }
				}
			}
		}
	},
	{
		.mne = "stnez",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x4F, .desc = 0xB,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM1 },
					{ .type = TYPE_R32, .encode = ENCODE_REGM2 }
				}
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
		.mne = "updfp",
		.encodes_length = 1,
		.encodes = {
			{
				.opcode = 0x5F, .desc = NO_DESC,
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
		.mne = "xchg",
		.encodes_length = 6,
		.encodes = {
			{
				.opcode = 0x78, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R8, .encode = ENCODE_REGM },
					{ .type = TYPE_R8, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x79, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R16, .encode = ENCODE_REGM },
					{ .type = TYPE_R16, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x7A, .desc = NO_DESC,
				.params_length = 2,
				.params = {
					{ .type = TYPE_R32, .encode = ENCODE_REGM },
					{ .type = TYPE_R32, .encode = ENCODE_REGO }
				}
			},
			{
				.opcode = 0x7B, .desc = 0x0,
				.params_length = 2,
				.params = {
					{ .type = TYPE_MEM8, .encode = ENCODE_MEM },
					{ .type = TYPE_R8, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x7B, .desc = 0x1,
				.params_length = 2,
				.params = {
					{ .type = TYPE_MEM16, .encode = ENCODE_MEM },
					{ .type = TYPE_R16, .encode = ENCODE_REGM }
				}
			},
			{
				.opcode = 0x7B, .desc = 0x2,
				.params_length = 2,
				.params = {
					{ .type = TYPE_MEM32, .encode = ENCODE_MEM },
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
