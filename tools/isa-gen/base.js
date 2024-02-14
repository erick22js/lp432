const isa_j = {
	"adc": {
		"description": "Adds src value with carry to dest",
		"cycles": 1,
		"flags": {"CF":2, "VF":2, "ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0x80",
				"args": [
					["dest", "gr8", "regm"],
					["src", "gr8", "rego"]
				]
			},
			{
				"opcode": "0x81",
				"args": [
					["dest", "gr16", "regm"],
					["src", "gr16", "rego"]
				]
			},
			{
				"opcode": "0x82",
				"args": [
					["dest", "gr32", "regm"],
					["src", "gr32", "rego"]
				]
			},
			{
				"opcode": "0x83",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x83",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x83",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0x83",
				"desc": "0x3",
				"args": [
					["dest", "gr8", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x83",
				"desc": "0x4",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0x83",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem32", "mem"]
				]
			},
			{
				"opcode": "0x83",
				"desc": "0x6",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x83",
				"desc": "0x7",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x83",
				"desc": "0x8",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x83",
				"desc": "0x9",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x83",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x83",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0x83",
				"desc": "0xC",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms8", "mv8"]
				]
			},
			{
				"opcode": "0x83",
				"desc": "0xD",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms16", "mv16"]
				]
			},
			{
				"opcode": "0x83",
				"desc": "0xE",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems8", "mv8"]
				]
			},
			{
				"opcode": "0x83",
				"desc": "0xF",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems16", "mv16"]
				]
			}
		]
	},
	"add": {
		"description": "Adds src value to dest",
		"cycles": 1,
		"flags": {"CF":2, "VF":2, "ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0x84",
				"args": [
					["dest", "gr8", "regm"],
					["src", "gr8", "rego"]
				]
			},
			{
				"opcode": "0x85",
				"args": [
					["dest", "gr16", "regm"],
					["src", "gr16", "rego"]
				]
			},
			{
				"opcode": "0x86",
				"args": [
					["dest", "gr32", "regm"],
					["src", "gr32", "rego"]
				]
			},
			{
				"opcode": "0x87",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x87",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x87",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0x87",
				"desc": "0x3",
				"args": [
					["dest", "gr8", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x87",
				"desc": "0x4",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0x87",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem32", "mem"]
				]
			},
			{
				"opcode": "0x87",
				"desc": "0x6",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x87",
				"desc": "0x7",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x87",
				"desc": "0x8",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x87",
				"desc": "0x9",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x87",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x87",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0x87",
				"desc": "0xC",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms8", "mv8"]
				]
			},
			{
				"opcode": "0x87",
				"desc": "0xD",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms16", "mv16"]
				]
			},
			{
				"opcode": "0x87",
				"desc": "0xE",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems8", "mv8"]
				]
			},
			{
				"opcode": "0x87",
				"desc": "0xF",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems16", "mv16"]
				]
			}
		]
	},
	"and": {
		"description": "Do bitwise operation 'and' between src and dest",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0xB0",
				"args": [
					["dest", "gr8", "regm"],
					["src", "gr8", "rego"]
				]
			},
			{
				"opcode": "0xB1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "gr16", "rego"]
				]
			},
			{
				"opcode": "0xB2",
				"args": [
					["dest", "gr32", "regm"],
					["src", "gr32", "rego"]
				]
			},
			{
				"opcode": "0xB3",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xB3",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0xB3",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0xB3",
				"desc": "0x3",
				"args": [
					["dest", "gr8", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xB3",
				"desc": "0x4",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0xB3",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem32", "mem"]
				]
			},
			{
				"opcode": "0xB3",
				"desc": "0x6",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xB3",
				"desc": "0x7",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xB3",
				"desc": "0x8",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0xB3",
				"desc": "0x9",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xB3",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xB3",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0xB3",
				"desc": "0xC",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms8", "mv8"]
				]
			},
			{
				"opcode": "0xB3",
				"desc": "0xD",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms16", "mv16"]
				]
			},
			{
				"opcode": "0xB3",
				"desc": "0xE",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems8", "mv8"]
				]
			},
			{
				"opcode": "0xB3",
				"desc": "0xF",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems16", "mv16"]
				]
			}
		]
	},
	"ba": {
		"Description": "Saves current address to stack and branches to a absolute address",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x2B",
				"args": [
					["offset", "gr32", "regm"]
				]
			},
			{
				"opcode": "0x2C",
				"args": [
					["offset", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0x2D",
				"desc": "cond",
				"args": [
					["offset", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0x2E",
				"desc": "condo",
				"args": [
					["comparator", "gr32", "regm"],
					["offset", "imm32", "mv32"]
				]
			}
		]
	},
	"br": {
		"Description": "Saves current address to stack and branches by a relative offset",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x28",
				"args": [
					["offset", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x29",
				"desc": "cond",
				"args": [
					["offset", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x2A",
				"desc": "condo",
				"args": [
					["comparator", "gr32", "regm"],
					["offset", "imm16", "mv16"]
				]
			}
		]
	},
	"bsb": {
		"description": "Scans from back for bit set in operand value and retrives the ammount of clear bits",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0xBF",
				"desc": "0x6",
				"args": [
					["bits", "gr8", "rego2"],
					["operand", "gr32", "regm1"]
				]
			},
			{
				"opcode": "0xBF",
				"desc": "0x7",
				"args": [
					["bits", "gr16", "rego2"],
					["operand", "gr32", "regm1"]
				]
			},
			{
				"opcode": "0xBF",
				"desc": "0x8",
				"args": [
					["bits", "gr32", "rego2"],
					["operand", "gr32", "regm1"]
				]
			},
			{
				"opcode": "0xBF",
				"desc": "0x9",
				"args": [
					["bits", "mem8", "mem"],
					["operand", "gr32", "regm1"]
				]
			},
			{
				"opcode": "0xBF",
				"desc": "0xA",
				"args": [
					["bits", "mem16", "mem"],
					["operand", "gr32", "regm1"]
				]
			},
			{
				"opcode": "0xBF",
				"desc": "0xB",
				"args": [
					["bits", "mem32", "mem"],
					["operand", "gr32", "regm1"]
				]
			}
		]
	},
	"bsf": {
		"description": "Scans from front for bit set in operand value and retrives the ammount of clear bits",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0xBF",
				"desc": "0x0",
				"args": [
					["bits", "gr8", "rego2"],
					["operand", "gr32", "regm1"]
				]
			},
			{
				"opcode": "0xBF",
				"desc": "0x1",
				"args": [
					["bits", "gr16", "rego2"],
					["operand", "gr32", "regm1"]
				]
			},
			{
				"opcode": "0xBF",
				"desc": "0x2",
				"args": [
					["bits", "gr32", "rego2"],
					["operand", "gr32", "regm1"]
				]
			},
			{
				"opcode": "0xBF",
				"desc": "0x3",
				"args": [
					["bits", "mem8", "mem"],
					["operand", "gr32", "regm1"]
				]
			},
			{
				"opcode": "0xBF",
				"desc": "0x4",
				"args": [
					["bits", "mem16", "mem"],
					["operand", "gr32", "regm1"]
				]
			},
			{
				"opcode": "0xBF",
				"desc": "0x5",
				"args": [
					["bits", "mem32", "mem"],
					["operand", "gr32", "regm1"]
				]
			}
		]
	},
	"bswap": {
		"description": "Swap bytes order in operand",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xDD",
				"args": [
					["operand", "gr16", "regm"]
				]
			},
			{
				"opcode": "0xDE",
				"args": [
					["operand", "gr32", "regm"]
				]
			}
		]
	},
	"bt": {
		"description": "Do a bit test operation on operand",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0xBE",
				"desc": "0x0",
				"args": [
					["operand", "gr8", "regm"]
				]
			},
			{
				"opcode": "0xBE",
				"desc": "0x1",
				"args": [
					["operand", "gr16", "regm"]
				]
			},
			{
				"opcode": "0xBE",
				"desc": "0x2",
				"args": [
					["operand", "gr32", "regm"]
				]
			},
			{
				"opcode": "0xBE",
				"desc": "0x3",
				"args": [
					["operand", "mem8", "regm"]
				]
			},
			{
				"opcode": "0xBE",
				"desc": "0x4",
				"args": [
					["operand", "mem16", "regm"]
				]
			},
			{
				"opcode": "0xBE",
				"desc": "0x5",
				"args": [
					["operand", "mem32", "regm"]
				]
			}
		]
	},
	"btc": {
		"description": "Clears the bit of operand",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xBE",
				"desc": "0x7",
				"args": [
					["operand", "gr32", "regm"],
					["bit", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xBE",
				"desc": "0xA",
				"args": [
					["operand", "gr32", "regm"],
					["bit", "gr32", "rego"]
				]
			}
		]
	},
	"bts": {
		"description": "Sets the bit of operand",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xBE",
				"desc": "0x6",
				"args": [
					["operand", "gr32", "regm"],
					["bit", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xBE",
				"desc": "0x9",
				"args": [
					["operand", "gr32", "regm"],
					["bit", "gr32", "rego"]
				]
			}
		]
	},
	"btt": {
		"description": "Toggles the bit of operand",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0xBE",
				"desc": "0x8",
				"args": [
					["operand", "gr32", "regm"],
					["bit", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xBE",
				"desc": "0xB",
				"args": [
					["operand", "gr32", "regm"],
					["bit", "gr32", "rego"]
				]
			}
		]
	},
	"clrb": {
		"description": "Disables flag Borrow",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x13",
				"args": []
			}
		]
	},
	"clrc": {
		"description": "Disables flag Carry",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x11",
				"args": []
			}
		]
	},
	"clri": {
		"description": "Disables external interruptions",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x0F",
				"args": []
			}
		]
	},
	"clrn": {
		"description": "Disables flag Negative",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x17",
				"args": []
			}
		]
	},
	"clro": {
		"description": "Disables flag Odd",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x1B",
				"args": []
			}
		]
	},
	"clrt": {
		"description": "Disables timer interruption",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x3F",
				"args": []
			}
		]
	},
	"clrv": {
		"description": "Disables flag Overflow",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x15",
				"args": []
			}
		]
	},
	"clrz": {
		"description": "Disables flag Zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x19",
				"args": []
			}
		]
	},
	"cmp": {
		"description": "Compares src value to dest",
		"cycles": 1,
		"flags": {"BF":2, "VF":2, "ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0xA8",
				"args": [
					["dest", "gr8", "regm"],
					["src", "gr8", "rego"]
				]
			},
			{
				"opcode": "0xA9",
				"args": [
					["dest", "gr16", "regm"],
					["src", "gr16", "rego"]
				]
			},
			{
				"opcode": "0xAA",
				"args": [
					["dest", "gr32", "regm"],
					["src", "gr32", "rego"]
				]
			},
			{
				"opcode": "0xAB",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xAB",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0xAB",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0xAB",
				"desc": "0x3",
				"args": [
					["dest", "gr8", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xAB",
				"desc": "0x4",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0xAB",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem32", "mem"]
				]
			},
			{
				"opcode": "0xAB",
				"desc": "0x6",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xAB",
				"desc": "0x7",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xAB",
				"desc": "0x8",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0xAB",
				"desc": "0x9",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xAB",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xAB",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0xAB",
				"desc": "0xC",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms8", "mv8"]
				]
			},
			{
				"opcode": "0xAB",
				"desc": "0xD",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms16", "mv16"]
				]
			},
			{
				"opcode": "0xAB",
				"desc": "0xE",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems8", "mv8"]
				]
			},
			{
				"opcode": "0xAB",
				"desc": "0xF",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems16", "mv16"]
				]
			}
		]
	},
	"cvbth": {
		"description": "Converts a byte value to half by signal extension",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x4C",
				"args": [
					["dest", "gr16", "regm"],
					["src", "gr8", "rego"]
				]
			},
			{
				"opcode": "0x4D",
				"desc": "0x0",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x4D",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem8", "mem"]
				]
			}
		]
	},
	"cvbtw": {
		"description": "Converts a byte value to word by signal extension",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x48",
				"args": [
					["dest", "gr32", "regm"],
					["src", "gr8", "rego"]
				]
			},
			{
				"opcode": "0x49",
				"desc": "0x0",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x49",
				"desc": "0x1",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem8", "mem"]
				]
			}
		]
	},
	"cvhtw": {
		"description": "Converts a half value to word by signal extension",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x4A",
				"args": [
					["dest", "gr32", "regm"],
					["src", "gr16", "rego"]
				]
			},
			{
				"opcode": "0x4B",
				"desc": "0x0",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x4B",
				"desc": "0x1",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem16", "mem"]
				]
			}
		]
	},
	"debug": {
		"description": "Do a Debug Interruption",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x02",
				"args": []
			}
		]
	},
	"dec": {
		"description": "Decrements value in operand",
		"cycles": 1,
		"flags": {"VF":2, "ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0xE4",
				"args": [
					["operand", "gr8", "regm"]
				]
			},
			{
				"opcode": "0xE5",
				"args": [
					["operand", "gr16", "regm"]
				]
			},
			{
				"opcode": "0xE6",
				"args": [
					["operand", "gr32", "regm"]
				]
			}
		]
	},
	"div": {
		"description": "Divides src value to dest",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0x98",
				"args": [
					["dest", "gr8", "regm"],
					["src", "gr8", "rego"]
				]
			},
			{
				"opcode": "0x99",
				"args": [
					["dest", "gr16", "regm"],
					["src", "gr16", "rego"]
				]
			},
			{
				"opcode": "0x9A",
				"args": [
					["dest", "gr32", "regm"],
					["src", "gr32", "rego"]
				]
			},
			{
				"opcode": "0x9B",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x9B",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x9B",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0x9B",
				"desc": "0x3",
				"args": [
					["dest", "gr8", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x9B",
				"desc": "0x4",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0x9B",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem32", "mem"]
				]
			},
			{
				"opcode": "0x9B",
				"desc": "0x6",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x9B",
				"desc": "0x7",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x9B",
				"desc": "0x8",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x9B",
				"desc": "0x9",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x9B",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x9B",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0x9B",
				"desc": "0xC",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms8", "mv8"]
				]
			},
			{
				"opcode": "0x9B",
				"desc": "0xD",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms16", "mv16"]
				]
			},
			{
				"opcode": "0x9B",
				"desc": "0xE",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems8", "mv8"]
				]
			},
			{
				"opcode": "0x9B",
				"desc": "0xF",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems16", "mv16"]
				]
			}
		]
	},
	"enter": {
		"description": "Creates and enters in a procedure frame",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x34",
				"args": []
			},
			{
				"opcode": "0x35",
				"args": [
					["size", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x36",
				"args": [
					["size", "gr16", "regm"]
				]
			}
		]
	},
	"f2xm1": {
		"Description": "Floating point, calculates 2 to the power of x minus 1",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD2",
				"desc": "0xC",
				"args": [
					["dest", "fpr", "regm1"],
					["x", "fpr", "regm2"]
				]
			}
		]
	},
	"fadc": {
		"Description": "Floating point, adds opr1 with opr2 to dest with carry",
		"cycles": 1,
		"flags": {"CF": 0},
		"encode": [
			{
				"opcode": "0xD1",
				"desc": "0x0",
				"args": [
					["dest", "fpr", "regm1"],
					["opr1", "fpr", "regm2"],
					["opr2", "fpr", "rego2"]
				]
			}
		]
	},
	"fadd": {
		"Description": "Floating point, adds opr1 with opr2 to dest",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD1",
				"desc": "0x1",
				"args": [
					["dest", "fpr", "regm1"],
					["opr1", "fpr", "regm2"],
					["opr2", "fpr", "rego2"]
				]
			}
		]
	},
	"faddi": {
		"Description": "Floating point, adds opr1 with integer opr2 to dest",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD1",
				"desc": "0x2",
				"args": [
					["dest", "fpr", "regm1"],
					["opr1", "fpr", "regm2"],
					["opr2", "gr32", "rego2"]
				]
			}
		]
	},
	"facos": {
		"Description": "Floating point, calculates arccossine of fp",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD2",
				"desc": "0x7",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "fpr", "regm2"]
				]
			}
		]
	},
	"fasin": {
		"Description": "Floating point, calculates arcsine of fp",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD2",
				"desc": "0x6",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "fpr", "regm2"]
				]
			}
		]
	},
	"fatan": {
		"Description": "Floating point, calculates arctangent of fp",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD2",
				"desc": "0x8",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "fpr", "regm2"]
				]
			}
		]
	},
	"fatan2": {
		"Description": "Floating point, calculates arctangent in bidimensional vector of fp",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD2",
				"desc": "0x8",
				"args": [
					["dest", "fpr", "regm1"],
					["y", "fpr", "regm2"],
					["x", "fpr", "rego2"]
				]
			}
		]
	},
	"fcbrt": {
		"Description": "Floating point, calculates cubic root of value",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD2",
				"desc": "0xB",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "fpr", "regm2"]
				]
			}
		]
	},
	"fceil": {
		"Description": "Floating point, round up operand to nearest integer",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD3",
				"desc": "0x1",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "fpr", "regm2"]
				]
			}
		]
	},
	"fcmp": {
		"Description": "Floating point, compares opr1 with opr2, if greater stores 1, if lesser stores -1, otherwise stores zero in dest",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD2",
				"desc": "0x0",
				"args": [
					["dest", "gr32", "regm1"],
					["opr1", "fpr", "regm2"],
					["opr2", "fpr", "rego2"]
				]
			}
		]
	},
	"fcmpi": {
		"Description": "Floating point, compares opr1 with integer opr2, if greater stores 1, if lesser stores -1, otherwise stores zero in dest",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD2",
				"desc": "0x1",
				"args": [
					["dest", "gr32", "regm1"],
					["opr1", "fpr", "regm2"],
					["opr2", "gr32", "rego2"]
				]
			}
		]
	},
	"fcos": {
		"Description": "Floating point, calculates cossine of fp",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD2",
				"desc": "0x4",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "fpr", "regm2"]
				]
			}
		]
	},
	"fcvfb": {
		"Description": "Floating point, convert integer byte to fp",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD3",
				"desc": "0x9",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "gr8", "regm2"]
				]
			}
		]
	},
	"fcvfh": {
		"Description": "Floating point, convert integer half to fp",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD3",
				"desc": "0xA",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "gr16", "regm2"]
				]
			}
		]
	},
	"fcvfsb": {
		"Description": "Floating point, convert signed byte to fp",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD3",
				"desc": "0xC",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "gr8", "regm2"]
				]
			}
		]
	},
	"fcvfsh": {
		"Description": "Floating point, convert signed half to fp",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD3",
				"desc": "0xD",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "gr16", "regm2"]
				]
			}
		]
	},
	"fcvfsw": {
		"Description": "Floating point, convert signed word to fp",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD3",
				"desc": "0xE",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "gr32", "regm2"]
				]
			}
		]
	},
	"fcvfw": {
		"Description": "Floating point, convert integer word to fp",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD3",
				"desc": "0xB",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "gr32", "regm2"]
				]
			}
		]
	},
	"fcvtb": {
		"Description": "Floating point, convert fp to integer byte",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD3",
				"desc": "0x3",
				"args": [
					["dest", "gr8", "regm1"],
					["source", "fpr", "regm2"]
				]
			}
		]
	},
	"fcvth": {
		"Description": "Floating point, convert fp to integer half",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD3",
				"desc": "0x4",
				"args": [
					["dest", "gr16", "regm1"],
					["source", "fpr", "regm2"]
				]
			}
		]
	},
	"fcvtsb": {
		"Description": "Floating point, convert fp to signed byte",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD3",
				"desc": "0x6",
				"args": [
					["dest", "gr8", "regm1"],
					["source", "fpr", "regm2"]
				]
			}
		]
	},
	"fcvtsh": {
		"Description": "Floating point, convert fp to signed half",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD3",
				"desc": "0x7",
				"args": [
					["dest", "gr16", "regm1"],
					["source", "fpr", "regm2"]
				]
			}
		]
	},
	"fcvtsw": {
		"Description": "Floating point, convert fp to signed word",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD3",
				"desc": "0x8",
				"args": [
					["dest", "gr32", "regm1"],
					["source", "fpr", "regm2"]
				]
			}
		]
	},
	"fcvtw": {
		"Description": "Floating point, convert fp to integer word",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD3",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm1"],
					["source", "fpr", "regm2"]
				]
			}
		]
	},
	"fdec": {
		"Description": "Floating point, decrements operand",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD1",
				"desc": "0xE",
				"args": [
					["operand", "fpr", "regm"]
				]
			}
		]
	},
	"fdiv": {
		"Description": "Floating point, divides opr1 by opr2 to dest",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD1",
				"desc": "0x9",
				"args": [
					["dest", "fpr", "regm1"],
					["opr1", "fpr", "regm2"],
					["opr2", "fpr", "rego2"]
				]
			}
		]
	},
	"fdsbb": {
		"Description": "Floating point, divides opr1 by opr2, and subtracts opr3 with borrow to dest",
		"cycles": 1,
		"flags": {"BF": 0},
		"encode": [
			{
				"opcode": "0xD1",
				"desc": "0xA",
				"args": [
					["dest", "fpr", "regm1"],
					["opr1", "fpr", "regm2"],
					["opr2", "fpr", "rego2"],
					["opr3", "fpr", "rego3"]
				]
			}
		]
	},
	"fdsub": {
		"Description": "Floating point, divides opr1 by opr2, and subtracts opr3 to dest",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD1",
				"desc": "0xB",
				"args": [
					["dest", "fpr", "regm1"],
					["opr1", "fpr", "regm2"],
					["opr2", "fpr", "rego2"],
					["opr3", "fpr", "rego3"]
				]
			}
		]
	},
	"ffloor": {
		"Description": "Floating point, round down operand to nearest integer",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD3",
				"desc": "0x0",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "fpr", "regm2"]
				]
			}
		]
	},
	"finc": {
		"Description": "Floating point, increments operand",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD1",
				"desc": "0xD",
				"args": [
					["operand", "fpr", "regm"]
				]
			}
		]
	},
	"flog": {
		"Description": "Floating point, calculates natural logarithm",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD2",
				"desc": "0xD",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "fpr", "regm2"]
				]
			}
		]
	},
	"flog2": {
		"Description": "Floating point, calculates logarithm of base 2",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD2",
				"desc": "0xE",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "fpr", "regm2"]
				]
			}
		]
	},
	"flog2x": {
		"Description": "Floating point, calculates logarithm of base 2 and multiplies by x",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD2",
				"desc": "0xF",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "fpr", "regm2"],
					["x", "fpr", "rego2"]
				]
			}
		]
	},
	"fmadc": {
		"Description": "Floating point, multiplies opr1 with opr2, and adds opr3 with carry to dest",
		"cycles": 1,
		"flags": {"CF": 0},
		"encode": [
			{
				"opcode": "0xD1",
				"desc": "0x7",
				"args": [
					["dest", "fpr", "regm1"],
					["opr1", "fpr", "regm2"],
					["opr2", "fpr", "rego2"],
					["opr3", "fpr", "rego3"]
				]
			}
		]
	},
	"fmadd": {
		"Description": "Floating point, multiplies opr1 with opr2, and adds opr3 to dest",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD1",
				"desc": "0x8",
				"args": [
					["dest", "fpr", "regm1"],
					["opr1", "fpr", "regm2"],
					["opr2", "fpr", "rego2"],
					["opr3", "fpr", "rego3"]
				]
			}
		]
	},
	"fmod": {
		"Description": "Floating point, gets remainder from division of opr1 by opr2 and stores in dest",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD1",
				"desc": "0xC",
				"args": [
					["dest", "fpr", "regm1"],
					["opr1", "fpr", "regm2"],
					["opr2", "fpr", "rego2"]
				]
			}
		]
	},
	"fmul": {
		"Description": "Floating point, multiplies opr1 with opr2 to dest",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD1",
				"desc": "0x6",
				"args": [
					["dest", "fpr", "regm1"],
					["opr1", "fpr", "regm2"],
					["opr2", "fpr", "rego2"]
				]
			}
		]
	},
	"fmvd": {
		"Description": "Floating point, moves raw data of double precision",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD0",
				"desc": "0x5",
				"args": [
					["desthi", "gr32", "regm2"],
					["destlo", "gr32", "regm1"],
					["source", "fpr", "rego2"]
				]
			},
			{
				"opcode": "0xD0",
				"desc": "0x6",
				"args": [
					["dest", "fpr", "regm1"],
					["sourcehi", "gr32", "rego2"],
					["sourcelo", "gr32", "regm2"]
				]
			},
			{
				"opcode": "0xD0",
				"desc": "0x7",
				"args": [
					["dest", "mem64", "mem"],
					["source", "fpr", "regm"]
				]
			},
			{
				"opcode": "0xD0",
				"desc": "0x8",
				"args": [
					["dest", "fpr", "regm"],
					["source", "mem64", "mem"]
				]
			}
		]
	},
	"fmvs": {
		"Description": "Floating point, moves raw data of single precision",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD0",
				"desc": "0x0",
				"args": [
					["dest", "gr32", "regm1"],
					["source", "fpr", "regm2"]
				]
			},
			{
				"opcode": "0xD0",
				"desc": "0x1",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "gr32", "regm2"]
				]
			},
			{
				"opcode": "0xD0",
				"desc": "0x2",
				"args": [
					["dest", "fpr", "regm"],
					["source", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0xD0",
				"desc": "0x3",
				"args": [
					["dest", "mem32", "mem"],
					["source", "fpr", "regm"]
				]
			},
			{
				"opcode": "0xD0",
				"desc": "0x4",
				"args": [
					["dest", "fpr", "regm"],
					["source", "mem32", "mem"]
				]
			}
		]
	},
	"fneg": {
		"Description": "Floating point, inverts signal of operand",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD1",
				"desc": "0xF",
				"args": [
					["operand", "fpr", "regm"]
				]
			}
		]
	},
	"fpopd": {
		"Description": "Floating point, pops double precision raw data from stack",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD0",
				"desc": "0xA",
				"args": [
					["dest", "fpr", "regm"]
				]
			}
		]
	},
	"fpops": {
		"Description": "Floating point, pops single precision raw data from stack",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD0",
				"desc": "0x9",
				"args": [
					["dest", "fpr", "regm"]
				]
			}
		]
	},
	"fpshd": {
		"Description": "Floating point, pushes double precision raw data to stack",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD0",
				"desc": "0xC",
				"args": [
					["source", "fpr", "regm"]
				]
			}
		]
	},
	"fpshs": {
		"Description": "Floating point, pushes single precision raw data to stack",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD0",
				"desc": "0xB",
				"args": [
					["source", "fpr", "regm"]
				]
			}
		]
	},
	"fround": {
		"Description": "Floating point, round operand to most nearest integer",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD3",
				"desc": "0x2",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "fpr", "regm2"]
				]
			}
		]
	},
	"fsbb": {
		"Description": "Floating point, subtracts opr2 from opr1 to dest with borrow",
		"cycles": 1,
		"flags": {"BF": 0},
		"encode": [
			{
				"opcode": "0xD1",
				"desc": "0x3",
				"args": [
					["dest", "fpr", "regm1"],
					["opr1", "fpr", "regm2"],
					["opr2", "fpr", "rego2"]
				]
			}
		]
	},
	"fsin": {
		"Description": "Floating point, calculates sine of fp",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD2",
				"desc": "0x3",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "fpr", "regm2"]
				]
			}
		]
	},
	"fsqrt": {
		"Description": "Floating point, calculates square root of operand",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD2",
				"desc": "0xA",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "fpr", "regm2"]
				]
			}
		]
	},
	"fsub": {
		"Description": "Floating point, subtracts opr2 from opr1 to dest",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD1",
				"desc": "0x4",
				"args": [
					["dest", "fpr", "regm1"],
					["opr1", "fpr", "regm2"],
					["opr2", "fpr", "rego2"]
				]
			}
		]
	},
	"ftan": {
		"Description": "Floating point, calculates tangent of fp",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD2",
				"desc": "0x5",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "fpr", "regm2"]
				]
			}
		]
	},
	"ftrunc": {
		"Description": "Floating point, truncates value of fp, from double precision to single",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD3",
				"desc": "0xF",
				"args": [
					["dest", "fpr", "regm1"],
					["source", "fpr", "regm2"]
				]
			}
		]
	},
	"fxam": {
		"Description": "Floating point, examinates the content of fp register, stores zero if is equal to zero, 1 if normal, 2 if subnormal, 3 if not-a-number or 4 if infinite to dest",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD2",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm1"],
					["operand", "fpr", "regm2"]
				]
			}
		]
	},
	"fsteq": {
		"description": "Floating point, sets the register value to 1 if reg1 is equal to reg2, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD7",
				"desc": "0x0",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "fpr", "regm2"],
					["reg2", "fpr", "rego2"]
				]
			}
		]
	},
	"fsteqz": {
		"description": "Floating point, sets the register value to 1 if operand is equal to zero, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD7",
				"desc": "0x6",
				"args": [
					["dest", "gr32", "regm1"],
					["operand", "fpr", "regm2"]
				]
			}
		]
	},
	"fstreqz": {
		"description": "Floating point, sets the register value to 1 if reg1 is nearly rounded by reg2 equal to zero, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD7",
				"desc": "0x7",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "fpr", "regm2"],
					["reg2", "fpr", "rego2"]
				]
			}
		]
	},
	"fstes": {
		"description": "Floating point, sets the register value to 1 if operand signal is equivalent to negative flag, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD7",
				"desc": "0xE",
				"args": [
					["dest", "gr32", "regm1"],
					["operand", "fpr", "regm2"]
				]
			}
		]
	},
	"fstge": {
		"description": "Floating point, sets the register value to 1 if reg1 is greater or equal to reg2, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD7",
				"desc": "0x4",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "fpr", "regm2"],
					["reg2", "fpr", "rego2"]
				]
			}
		]
	},
	"fstgez": {
		"description": "Floating point, sets the register value to 1 if operand is greater or equal to zero, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD7",
				"desc": "0xC",
				"args": [
					["dest", "gr32", "regm1"],
					["operand", "fpr", "regm2"]
				]
			}
		]
	},
	"fstgt": {
		"description": "Floating point, sets the register value to 1 if reg1 is greater than reg2, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD7",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "fpr", "regm2"],
					["reg2", "fpr", "rego2"]
				]
			}
		]
	},
	"fstgtz": {
		"description": "Floating point, sets the register value to 1 if operand is greater than zero, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD7",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm1"],
					["operand", "fpr", "regm2"]
				]
			}
		]
	},
	"fstle": {
		"description": "Floating point, sets the register value to 1 if reg1 is lesser or equal to reg2, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD7",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "fpr", "regm2"],
					["reg2", "fpr", "rego2"]
				]
			}
		]
	},
	"fstlez": {
		"description": "Floating point, sets the register value to 1 if operand is lesser or equal to zero, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD7",
				"desc": "0xD",
				"args": [
					["dest", "gr32", "regm1"],
					["operand", "fpr", "regm2"]
				]
			}
		]
	},
	"fstlt": {
		"description": "Floating point, sets the register value to 1 if reg1 is lesser than reg2, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD7",
				"desc": "0x3",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "fpr", "regm2"],
					["reg2", "fpr", "rego2"]
				]
			}
		]
	},
	"fstltz": {
		"description": "Floating point, sets the register value to 1 if operand is greater than zero, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD7",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm1"],
					["operand", "fpr", "regm2"]
				]
			}
		]
	},
	"fstne": {
		"description": "Floating point, sets the register value to 1 if reg1 is not equal to reg2, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD7",
				"desc": "0x1",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "fpr", "regm2"],
					["reg2", "fpr", "rego2"]
				]
			}
		]
	},
	"fstnez": {
		"description": "Floating point, sets the register value to 1 if operand is not equal to zero, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD7",
				"desc": "0x8",
				"args": [
					["dest", "gr32", "regm1"],
					["operand", "fpr", "regm2"]
				]
			}
		]
	},
	"fstns": {
		"description": "Floating point, sets the register value to 1 if operand signal is not equivalent to negative flag, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD7",
				"desc": "0xF",
				"args": [
					["dest", "gr32", "regm1"],
					["operand", "fpr", "regm2"]
				]
			}
		]
	},
	"fstrnez": {
		"description": "Floating point, sets the register value to 1 if reg1 is nearly rounded by reg2 not equal to zero, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD7",
				"desc": "0x9",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "fpr", "regm2"],
					["reg2", "fpr", "rego2"]
				]
			}
		]
	},
	"fsubi": {
		"Description": "Floating point, subtracts integer opr2 from opr1 to dest",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xD1",
				"desc": "0x5",
				"args": [
					["dest", "fpr", "regm1"],
					["opr1", "fpr", "regm2"],
					["opr2", "gr32", "rego2"]
				]
			}
		]
	},
	"halt": {
		"description": "Stops the processor",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xF8",
				"args": []
			}
		]
	},
	"hmul": {
		"description": "Multiplies src value to dest and stores high product part",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0x94",
				"args": [
					["dest", "gr32", "regm1"],
					["high", "gr32", "rego1"],
					["src", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x95",
				"args": [
					["dest", "gr32", "regm"],
					["high", "gr32", "rego"],
					["src", "mem32", "mem"]
				]
			}
		]
	},
	"hsmul": {
		"description": "Multiplies with sign extension to 64-bit src value to dest and stores high product part",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0x96",
				"args": [
					["dest", "gr32", "regm1"],
					["high", "gr32", "rego1"],
					["src", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x97",
				"args": [
					["dest", "gr32", "regm"],
					["high", "gr32", "rego"],
					["src", "mem32", "mem"]
				]
			}
		]
	},
	"in": {
		"description": "Reads value from device port to register",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0xF0",
				"args": [
					["dest", "gr8", "regm"],
					["port", "gr16", "regm"]
				]
			},
			{
				"opcode": "0xF1",
				"args": [
					["dest", "gr16", "regm"],
					["port", "gr16", "regm"]
				]
			},
			{
				"opcode": "0xF2",
				"args": [
					["dest", "gr32", "regm"],
					["port", "gr16", "regm"]
				]
			},
			{
				"opcode": "0xF3",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm"],
					["port", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xF3",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["port", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xF3",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm"],
					["port", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xF3",
				"desc": "0x3",
				"args": [
					["dest", "gr8", "regm"],
					["port", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0xF3",
				"desc": "0x4",
				"args": [
					["dest", "gr16", "regm"],
					["port", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0xF3",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm"],
					["port", "imm16", "mv16"]
				]
			}
		]
	},
	"inc": {
		"description": "Increments value in operand",
		"cycles": 1,
		"flags": {"VF":2, "ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0xE0",
				"args": [
					["operand", "gr8", "regm"]
				]
			},
			{
				"opcode": "0xE1",
				"args": [
					["operand", "gr16", "regm"]
				]
			},
			{
				"opcode": "0xE2",
				"args": [
					["operand", "gr32", "regm"]
				]
			}
		]
	},
	"int": {
		"description": "Calls for a Software Interruption",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x32",
				"args": []
			}
		]
	},
	"iret": {
		"description": "Returns from a interruption call",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x31",
				"args": []
			}
		]
	},
	"ja": {
		"Description": "Jumps to a absolute address",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x23",
				"args": [
					["offset", "gr32", "regm"]
				]
			},
			{
				"opcode": "0x24",
				"args": [
					["offset", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0x25",
				"desc": "cond",
				"args": [
					["offset", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0x26",
				"desc": "condo",
				"args": [
					["comparator", "gr32", "regm"],
					["offset", "imm32", "mv32"]
				]
			}
		]
	},
	"jr": {
		"Description": "Jumps by a relative offset",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x20",
				"args": [
					["offset", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x21",
				"desc": "cond",
				"args": [
					["offset", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x22",
				"desc": "condo",
				"args": [
					["comparator", "gr32", "regm"],
					["offset", "imm16", "mv16"]
				]
			}
		]
	},
	"jadp": {
		"description": "Jumps to a absolute address and disable pagining",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x0A",
				"args": [
					["address", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0x0B",
				"args": [
					["address", "gr32", "regm"]
				]
			}
		]
	},
	"jads": {
		"description": "Jumps to a absolute address and disable segmentation",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x06",
				"args": [
					["address", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0x07",
				"args": [
					["address", "gr32", "regm"]
				]
			}
		]
	},
	"jaep": {
		"description": "Jumps to a absolute address and enable pagining",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x08",
				"args": [
					["address", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0x09",
				"args": [
					["address", "gr32", "regm"]
				]
			}
		]
	},
	"jaes": {
		"description": "Jumps to a absolute address and enable segmentation",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x04",
				"args": [
					["address", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0x05",
				"args": [
					["address", "gr32", "regm"]
				]
			}
		]
	},
	"jasp": {
		"description": "Jumps to a absolute address and enable security protection",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x0C",
				"args": [
					["address", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0x0D",
				"args": [
					["address", "gr32", "regm"]
				]
			}
		]
	},
	"lea": {
		"Description": "Loads the value at address pointed in memory indirect address to register",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x60",
				"args": [
					["dest", "gr8", "regm"],
					["base", "gr32", "rego"]
				]
			},
			{
				"opcode": "0x61",
				"args": [
					["dest", "gr16", "regm"],
					["base", "gr32", "rego"]
				]
			},
			{
				"opcode": "0x62",
				"args": [
					["dest", "gr32", "regm"],
					["base", "gr32", "rego"]
				]
			},
			{
				"opcode": "0x63",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm"],
					["base", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x63",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["base", "mem16", "mem"]
				]
			},
			{
				"opcode": "0x63",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm"],
					["base", "mem32", "mem"]
				]
			},
			{
				"opcode": "0x64",
				"args": [
					["dest", "gr8", "regm"],
					["base", "gr32", "rego"],
					["offset", "imms16", "mv16"]
				]
			},
			{
				"opcode": "0x65",
				"args": [
					["dest", "gr16", "regm"],
					["base", "gr32", "rego"],
					["offset", "imms16", "mv16"]
				]
			},
			{
				"opcode": "0x66",
				"args": [
					["dest", "gr32", "regm"],
					["base", "gr32", "rego"],
					["offset", "imms16", "mv16"]
				]
			},
			{
				"opcode": "0x67",
				"args": [
					["dest", "gr32", "regm"],
					["base", "gr32", "rego"],
					["offset", "imms32", "mv32"]
				]
			}
		]
	},
	"leave": {
		"description": "Leaves the current procedure frame",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x37",
				"args": []
			}
		]
	},
	"lrot": {
		"description": "Left rotate dest operand by source",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0xC8",
				"args": [
					["dest", "gr8", "regm"],
					["src", "gr8", "rego"]
				]
			},
			{
				"opcode": "0xC9",
				"args": [
					["dest", "gr16", "regm"],
					["src", "gr16", "rego"]
				]
			},
			{
				"opcode": "0xCA",
				"args": [
					["dest", "gr32", "regm"],
					["src", "gr32", "rego"]
				]
			},
			{
				"opcode": "0xCB",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xCB",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xCB",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xCB",
				"desc": "0x3",
				"args": [
					["dest", "gr8", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xCB",
				"desc": "0x4",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0xCB",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem32", "mem"]
				]
			},
			{
				"opcode": "0xCB",
				"desc": "0x9",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xCB",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xCB",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem16", "mem"]
				]
			}
		]
	},
	"lsh": {
		"description": "Left shift dest operand by source",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0xC0",
				"args": [
					["dest", "gr8", "regm"],
					["src", "gr8", "rego"]
				]
			},
			{
				"opcode": "0xC1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "gr16", "rego"]
				]
			},
			{
				"opcode": "0xC2",
				"args": [
					["dest", "gr32", "regm"],
					["src", "gr32", "rego"]
				]
			},
			{
				"opcode": "0xC3",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xC3",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xC3",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xC3",
				"desc": "0x3",
				"args": [
					["dest", "gr8", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xC3",
				"desc": "0x4",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0xC3",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem32", "mem"]
				]
			},
			{
				"opcode": "0xC3",
				"desc": "0x9",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xC3",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xC3",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem16", "mem"]
				]
			}
		]
	},
	"mod": {
		"description": "Gets the division remainder from src value to dest",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0xA0",
				"args": [
					["dest", "gr8", "regm"],
					["src", "gr8", "rego"]
				]
			},
			{
				"opcode": "0xA1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "gr16", "rego"]
				]
			},
			{
				"opcode": "0xA2",
				"args": [
					["dest", "gr32", "regm"],
					["src", "gr32", "rego"]
				]
			},
			{
				"opcode": "0xA3",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xA3",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0xA3",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0xA3",
				"desc": "0x3",
				"args": [
					["dest", "gr8", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xA3",
				"desc": "0x4",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0xA3",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem32", "mem"]
				]
			},
			{
				"opcode": "0xA3",
				"desc": "0x6",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xA3",
				"desc": "0x7",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xA3",
				"desc": "0x8",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0xA3",
				"desc": "0x9",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xA3",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xA3",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0xA3",
				"desc": "0xC",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms8", "mv8"]
				]
			},
			{
				"opcode": "0xA3",
				"desc": "0xD",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms16", "mv16"]
				]
			},
			{
				"opcode": "0xA3",
				"desc": "0xE",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems8", "mv8"]
				]
			},
			{
				"opcode": "0xA3",
				"desc": "0xF",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems16", "mv16"]
				]
			}
		]
	},
	"mov": {
		"description": "Moves a value from a operand to another",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x70",
				"args": [
					["dest", "gr8", "regm"],
					["source", "gr8", "rego"]
				]
			},
			{
				"opcode": "0x71",
				"args": [
					["dest", "gr16", "regm"],
					["source", "gr16", "rego"]
				]
			},
			{
				"opcode": "0x72",
				"args": [
					["dest", "gr32", "regm"],
					["source", "gr32", "rego"]
				]
			},
			{
				"opcode": "0x73",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm"],
					["source", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x73",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["source", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x73",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm"],
					["source", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0x73",
				"desc": "0x3",
				"args": [
					["dest", "gr32", "regm"],
					["source", "imms8", "mv8"]
				]
			},
			{
				"opcode": "0x73",
				"desc": "0x4",
				"args": [
					["dest", "gr32", "regm"],
					["source", "imms16", "mv16"]
				]
			},
			{
				"opcode": "0x73",
				"desc": "0x5",
				"args": [
					["dest", "gr16", "regm"],
					["source", "imms8", "mv8"]
				]
			},
			{
				"opcode": "0x73",
				"desc": "0x6",
				"args": [
					["dest", "gr8", "regm"],
					["source", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x73",
				"desc": "0x7",
				"args": [
					["dest", "gr16", "regm"],
					["source", "mem16", "mem"]
				]
			},
			{
				"opcode": "0x73",
				"desc": "0x8",
				"args": [
					["dest", "gr32", "regm"],
					["source", "mem32", "mem"]
				]
			},
			{
				"opcode": "0x73",
				"desc": "0x9",
				"args": [
					["dest", "gr16", "regm"],
					["source", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x73",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm"],
					["source", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x73",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm"],
					["source", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x73",
				"desc": "0xC",
				"args": [
					["dest", "gr16", "regm"],
					["source", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x73",
				"desc": "0xD",
				"args": [
					["dest", "gr32", "regm"],
					["source", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x73",
				"desc": "0xE",
				"args": [
					["dest", "gr32", "regm"],
					["source", "mem16", "mem"]
				]
			},
			{
				"opcode": "0x77",
				"desc": "0x0",
				"args": [
					["dest", "mem8", "mem"],
					["source", "gr8", "regm"]
				]
			},
			{
				"opcode": "0x77",
				"desc": "0x1",
				"args": [
					["dest", "mem16", "mem"],
					["source", "gr16", "regm"]
				]
			},
			{
				"opcode": "0x77",
				"desc": "0x2",
				"args": [
					["dest", "mem32", "mem"],
					["source", "gr32", "regm"]
				]
			}
		]
	},
	"mul": {
		"description": "Multiplies src value to dest",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0x90",
				"args": [
					["dest", "gr8", "regm"],
					["src", "gr8", "rego"]
				]
			},
			{
				"opcode": "0x91",
				"args": [
					["dest", "gr16", "regm"],
					["src", "gr16", "rego"]
				]
			},
			{
				"opcode": "0x92",
				"args": [
					["dest", "gr32", "regm"],
					["src", "gr32", "rego"]
				]
			},
			{
				"opcode": "0x93",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x93",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x93",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0x93",
				"desc": "0x3",
				"args": [
					["dest", "gr8", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x93",
				"desc": "0x4",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0x93",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem32", "mem"]
				]
			},
			{
				"opcode": "0x93",
				"desc": "0x6",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x93",
				"desc": "0x7",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x93",
				"desc": "0x8",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x93",
				"desc": "0x9",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x93",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x93",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0x93",
				"desc": "0xC",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms8", "mv8"]
				]
			},
			{
				"opcode": "0x93",
				"desc": "0xD",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms16", "mv16"]
				]
			},
			{
				"opcode": "0x93",
				"desc": "0xE",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems8", "mv8"]
				]
			},
			{
				"opcode": "0x93",
				"desc": "0xF",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems16", "mv16"]
				]
			}
		]
	},
	"mvab": {
		"description": "Move immediate data to register if the reg1 is above than reg2",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x44",
				"desc": "0x6",
				"args": [
					["dest", "gr8", "regm1"],
					["data", "imm8", "mv8"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x45",
				"desc": "0x6",
				"args": [
					["dest", "gr16", "regm1"],
					["data", "imm16", "mv16"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x46",
				"desc": "0x6",
				"args": [
					["dest", "gr32", "regm1"],
					["data", "imm32", "mv16"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			}
		]
	},
	"mvae": {
		"description": "Move immediate data to register if the reg1 is above or equal to reg2",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x44",
				"desc": "0x8",
				"args": [
					["dest", "gr8", "regm1"],
					["data", "imm8", "mv8"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x45",
				"desc": "0x8",
				"args": [
					["dest", "gr16", "regm1"],
					["data", "imm16", "mv16"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x46",
				"desc": "0x8",
				"args": [
					["dest", "gr32", "regm1"],
					["data", "imm32", "mv16"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			}
		]
	},
	"mvbe": {
		"description": "Move immediate data to register if the reg1 is below or equal to reg2",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x44",
				"desc": "0x9",
				"args": [
					["dest", "gr8", "regm1"],
					["data", "imm8", "mv8"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x45",
				"desc": "0x9",
				"args": [
					["dest", "gr16", "regm1"],
					["data", "imm16", "mv16"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x46",
				"desc": "0x9",
				"args": [
					["dest", "gr32", "regm1"],
					["data", "imm32", "mv16"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			}
		]
	},
	"mvbl": {
		"description": "Move immediate data to register if the reg1 is below than reg2",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x44",
				"desc": "0x7",
				"args": [
					["dest", "gr8", "regm1"],
					["data", "imm8", "mv8"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x45",
				"desc": "0x7",
				"args": [
					["dest", "gr16", "regm1"],
					["data", "imm16", "mv16"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x46",
				"desc": "0x7",
				"args": [
					["dest", "gr32", "regm1"],
					["data", "imm32", "mv16"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			}
		]
	},
	"mveq": {
		"description": "Move immediate data to register if the reg1 and reg2 are equal",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x44",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm1"],
					["data", "imm8", "mv8"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x45",
				"desc": "0x0",
				"args": [
					["dest", "gr16", "regm1"],
					["data", "imm16", "mv16"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x46",
				"desc": "0x0",
				"args": [
					["dest", "gr32", "regm1"],
					["data", "imm32", "mv16"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			}
		]
	},
	"mveqz": {
		"description": "Move immediate data to register if the reg1 is equal to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x44",
				"desc": "0xA",
				"args": [
					["dest", "gr8", "regm1"],
					["data", "imm8", "mv8"],
					["reg1", "gr32", "regm2"]
				]
			},
			{
				"opcode": "0x45",
				"desc": "0xA",
				"args": [
					["dest", "gr16", "regm1"],
					["data", "imm16", "mv16"],
					["reg1", "gr32", "regm2"]
				]
			},
			{
				"opcode": "0x46",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm1"],
					["data", "imm32", "mv16"],
					["reg1", "gr32", "regm2"]
				]
			}
		]
	},
	"mvfir": {
		"description": "Moves data from Interruption Register to General Purpose Registers",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x3A",
				"args": [
					["dest", "gr32", "regm"],
					["source", "ir", "rego"]
				]
			}
		]
	},
	"mvfisp": {
		"description": "Move Interruption Stack Pointer register data to a General Purpose Register",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x3C",
				"args": [
					["dest", "gr32", "regm"]
				]
			}
		]
	},
	"mvge": {
		"description": "Move immediate data to register if the reg1 is greater or equal to reg2",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x44",
				"desc": "0x4",
				"args": [
					["dest", "gr8", "regm1"],
					["data", "imm8", "mv8"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x45",
				"desc": "0x4",
				"args": [
					["dest", "gr16", "regm1"],
					["data", "imm16", "mv16"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x46",
				"desc": "0x4",
				"args": [
					["dest", "gr32", "regm1"],
					["data", "imm32", "mv16"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			}
		]
	},
	"mvgez": {
		"description": "Move immediate data to register if the reg1 is greater or equal to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x44",
				"desc": "0xE",
				"args": [
					["dest", "gr8", "regm1"],
					["data", "imm8", "mv8"],
					["reg1", "gr32", "regm2"]
				]
			},
			{
				"opcode": "0x45",
				"desc": "0xE",
				"args": [
					["dest", "gr16", "regm1"],
					["data", "imm16", "mv16"],
					["reg1", "gr32", "regm2"]
				]
			},
			{
				"opcode": "0x46",
				"desc": "0xE",
				"args": [
					["dest", "gr32", "regm1"],
					["data", "imm32", "mv16"],
					["reg1", "gr32", "regm2"]
				]
			}
		]
	},
	"mvgt": {
		"description": "Move immediate data to register if the reg1 is greater than reg2",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x44",
				"desc": "0x2",
				"args": [
					["dest", "gr8", "regm1"],
					["data", "imm8", "mv8"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x45",
				"desc": "0x2",
				"args": [
					["dest", "gr16", "regm1"],
					["data", "imm16", "mv16"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x46",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm1"],
					["data", "imm32", "mv16"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			}
		]
	},
	"mvgtz": {
		"description": "Move immediate data to register if the reg1 is greater than zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x44",
				"desc": "0xC",
				"args": [
					["dest", "gr8", "regm1"],
					["data", "imm8", "mv8"],
					["reg1", "gr32", "regm2"]
				]
			},
			{
				"opcode": "0x45",
				"desc": "0xC",
				"args": [
					["dest", "gr16", "regm1"],
					["data", "imm16", "mv16"],
					["reg1", "gr32", "regm2"]
				]
			},
			{
				"opcode": "0x46",
				"desc": "0xC",
				"args": [
					["dest", "gr32", "regm1"],
					["data", "imm32", "mv16"],
					["reg1", "gr32", "regm2"]
				]
			}
		]
	},
	"mvle": {
		"description": "Move immediate data to register if the reg1 is lesser or equal to reg2",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x44",
				"desc": "0x5",
				"args": [
					["dest", "gr8", "regm1"],
					["data", "imm8", "mv8"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x45",
				"desc": "0x5",
				"args": [
					["dest", "gr16", "regm1"],
					["data", "imm16", "mv16"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x46",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm1"],
					["data", "imm32", "mv16"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			}
		]
	},
	"mvlez": {
		"description": "Move immediate data to register if the reg1 is lesser or equal to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x44",
				"desc": "0xF",
				"args": [
					["dest", "gr8", "regm1"],
					["data", "imm8", "mv8"],
					["reg1", "gr32", "regm2"]
				]
			},
			{
				"opcode": "0x45",
				"desc": "0xF",
				"args": [
					["dest", "gr16", "regm1"],
					["data", "imm16", "mv16"],
					["reg1", "gr32", "regm2"]
				]
			},
			{
				"opcode": "0x46",
				"desc": "0xF",
				"args": [
					["dest", "gr32", "regm1"],
					["data", "imm32", "mv16"],
					["reg1", "gr32", "regm2"]
				]
			}
		]
	},
	"mvlt": {
		"description": "Move immediate data to register if the reg1 is lesser than reg2",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x44",
				"desc": "0x3",
				"args": [
					["dest", "gr8", "regm1"],
					["data", "imm8", "mv8"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x45",
				"desc": "0x3",
				"args": [
					["dest", "gr16", "regm1"],
					["data", "imm16", "mv16"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x46",
				"desc": "0x3",
				"args": [
					["dest", "gr32", "regm1"],
					["data", "imm32", "mv16"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			}
		]
	},
	"mvltz": {
		"description": "Move immediate data to register if the reg1 is lesser than zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x44",
				"desc": "0xD",
				"args": [
					["dest", "gr8", "regm1"],
					["data", "imm8", "mv8"],
					["reg1", "gr32", "regm2"]
				]
			},
			{
				"opcode": "0x45",
				"desc": "0xD",
				"args": [
					["dest", "gr16", "regm1"],
					["data", "imm16", "mv16"],
					["reg1", "gr32", "regm2"]
				]
			},
			{
				"opcode": "0x46",
				"desc": "0xD",
				"args": [
					["dest", "gr32", "regm1"],
					["data", "imm32", "mv16"],
					["reg1", "gr32", "regm2"]
				]
			}
		]
	},
	"mvne": {
		"description": "Move immediate data to register if the reg1 and reg2 are not equal",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x44",
				"desc": "0x1",
				"args": [
					["dest", "gr8", "regm1"],
					["data", "imm8", "mv8"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x45",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm1"],
					["data", "imm16", "mv16"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			},
			{
				"opcode": "0x46",
				"desc": "0x1",
				"args": [
					["dest", "gr32", "regm1"],
					["data", "imm32", "mv16"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			}
		]
	},
	"mvnez": {
		"description": "Move immediate data to register if the reg1 is not equal to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x44",
				"desc": "0xB",
				"args": [
					["dest", "gr8", "regm1"],
					["data", "imm8", "mv8"],
					["reg1", "gr32", "regm2"]
				]
			},
			{
				"opcode": "0x45",
				"desc": "0xB",
				"args": [
					["dest", "gr16", "regm1"],
					["data", "imm16", "mv16"],
					["reg1", "gr32", "regm2"]
				]
			},
			{
				"opcode": "0x46",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm1"],
					["data", "imm32", "mv16"],
					["reg1", "gr32", "regm2"]
				]
			}
		]
	},
	"mvtisp": {
		"description": "Move General Purpose Register data to Interruption Stack Pointer register",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x3D",
				"args": [
					["source", "gr32", "regm"]
				]
			}
		]
	},
	"mvtitd": {
		"description": "Move register data to register Interruption Table Descriptor",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x39",
				"desc": "0x2",
				"args": [
					["source", "gr32", "regm"]
				]
			}
		]
	},
	"mvtptd": {
		"description": "Move register data to register Pagining Table Descriptor",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x39",
				"desc": "0x1",
				"args": [
					["source", "gr32", "regm"]
				]
			}
		]
	},
	"mvtsr": {
		"description": "Move register data to register segment SS",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x38",
				"args": [
					["dest", "sr", "rego"],
					["source", "gr8", "regm"]
				]
			}
		]
	},
	"mvtstd": {
		"description": "Move register data to register Segment Table Descriptor",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x39",
				"desc": "0x0",
				"args": [
					["source", "gr32", "regm"]
				]
			}
		]
	},
	"neg": {
		"description": "Inverts value signal in operand",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0xE8",
				"args": [
					["operand", "gr8", "regm"]
				]
			},
			{
				"opcode": "0xE9",
				"args": [
					["operand", "gr16", "regm"]
				]
			},
			{
				"opcode": "0xEA",
				"args": [
					["operand", "gr32", "regm"]
				]
			}
		]
	},
	"nop": {
		"description": "Don't do any operation",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x00",
				"args": []
			}
		]
	},
	"not": {
		"description": "Inverts value bits in operand",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0xEC",
				"args": [
					["operand", "gr8", "regm"]
				]
			},
			{
				"opcode": "0xED",
				"args": [
					["operand", "gr16", "regm"]
				]
			},
			{
				"opcode": "0xEE",
				"args": [
					["operand", "gr32", "regm"]
				]
			}
		]
	},
	"out": {
		"description": "Writes register value to device port",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0xF4",
				"args": [
					["port", "gr16", "regm"],
					["source", "gr8", "regm"]
				]
			},
			{
				"opcode": "0xF5",
				"args": [
					["port", "gr16", "regm"],
					["source", "gr16", "regm"]
				]
			},
			{
				"opcode": "0xF6",
				"args": [
					["port", "gr16", "regm"],
					["source", "gr32", "regm"]
				]
			},
			{
				"opcode": "0xF7",
				"desc": "0x0",
				"args": [
					["port", "imm8", "mv8"],
					["source", "gr8", "regm"]
				]
			},
			{
				"opcode": "0xF7",
				"desc": "0x1",
				"args": [
					["port", "imm8", "mv8"],
					["source", "gr16", "regm"]
				]
			},
			{
				"opcode": "0xF7",
				"desc": "0x2",
				"args": [
					["port", "imm8", "mv8"],
					["source", "gr32", "regm"]
				]
			},
			{
				"opcode": "0xF7",
				"desc": "0x3",
				"args": [
					["port", "imm16", "mv16"],
					["source", "gr8", "regm"]
				]
			},
			{
				"opcode": "0xF7",
				"desc": "0x4",
				"args": [
					["port", "imm16", "mv16"],
					["source", "gr16", "regm"]
				]
			},
			{
				"opcode": "0xF7",
				"desc": "0x5",
				"args": [
					["port", "imm16", "mv16"],
					["source", "gr32", "regm"]
				]
			}
		]
	},
	"or": {
		"description": "Do bitwise operation 'or' between src and dest",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0xB4",
				"args": [
					["dest", "gr8", "regm"],
					["src", "gr8", "rego"]
				]
			},
			{
				"opcode": "0xB5",
				"args": [
					["dest", "gr16", "regm"],
					["src", "gr16", "rego"]
				]
			},
			{
				"opcode": "0xB6",
				"args": [
					["dest", "gr32", "regm"],
					["src", "gr32", "rego"]
				]
			},
			{
				"opcode": "0xB7",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xB7",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0xB7",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0xB7",
				"desc": "0x3",
				"args": [
					["dest", "gr8", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xB7",
				"desc": "0x4",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0xB7",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem32", "mem"]
				]
			},
			{
				"opcode": "0xB7",
				"desc": "0x6",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xB7",
				"desc": "0x7",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xB7",
				"desc": "0x8",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0xB7",
				"desc": "0x9",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xB7",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xB7",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0xB7",
				"desc": "0xC",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms8", "mv8"]
				]
			},
			{
				"opcode": "0xB7",
				"desc": "0xD",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms16", "mv16"]
				]
			},
			{
				"opcode": "0xB7",
				"desc": "0xE",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems8", "mv8"]
				]
			},
			{
				"opcode": "0xB7",
				"desc": "0xF",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems16", "mv16"]
				]
			}
		]
	},
	"pnop": {
		"description": "Don't do any operation, but interrupt if program is in Protected Mode",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x01",
				"args": []
			}
		]
	},
	"pop": {
		"description": "Pops a value from stack",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x50",
				"args": [
					["dest", "gr8", "regm"]
				]
			},
			{
				"opcode": "0x51",
				"args": [
					["dest", "gr16", "regm"]
				]
			},
			{
				"opcode": "0x52",
				"args": [
					["dest", "gr32", "regm"]
				]
			},
			{
				"opcode": "0x53",
				"desc": "0x0",
				"args": [
					["dest", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x53",
				"desc": "0x1",
				"args": [
					["dest", "mem16", "mem"]
				]
			},
			{
				"opcode": "0x53",
				"desc": "0x2",
				"args": [
					["dest", "mem32", "mem"]
				]
			}
		]
	},
	"poplst": {
		"description": "Pops the lesser half of Program Status Register from stack",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x5B",
				"args": []
			}
		]
	},
	"popst": {
		"description": "Pops the entire Program Status Register from stack",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x5C",
				"args": []
			}
		]
	},
	"psh": {
		"description": "Pushes a value to stack",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x54",
				"args": [
					["source", "gr8", "regm"]
				]
			},
			{
				"opcode": "0x55",
				"args": [
					["source", "gr16", "regm"]
				]
			},
			{
				"opcode": "0x56",
				"args": [
					["source", "gr32", "regm"]
				]
			},
			{
				"opcode": "0x57",
				"desc": "0x0",
				"args": [
					["source", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x57",
				"desc": "0x1",
				"args": [
					["source", "mem16", "mem"]
				]
			},
			{
				"opcode": "0x57",
				"desc": "0x2",
				"args": [
					["source", "mem32", "mem"]
				]
			},
			{
				"opcode": "0x58",
				"args": [
					["source", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x59",
				"args": [
					["source", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x5A",
				"args": [
					["source", "imm32", "mv32"]
				]
			}
		]
	},
	"pshlst": {
		"description": "Pushes the lesser half of Program Status Register to stack",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x5D",
				"args": []
			}
		]
	},
	"pshst": {
		"description": "Pushes the entire Program Status Register to stack",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x5E",
				"args": []
			}
		]
	},
	"ret": {
		"description": "Returns from a branched jump",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x30",
				"args": []
			}
		]
	},
	"rrot": {
		"description": "Right rotate dest operand by source",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0xCC",
				"args": [
					["dest", "gr8", "regm"],
					["src", "gr8", "rego"]
				]
			},
			{
				"opcode": "0xCD",
				"args": [
					["dest", "gr16", "regm"],
					["src", "gr16", "rego"]
				]
			},
			{
				"opcode": "0xCE",
				"args": [
					["dest", "gr32", "regm"],
					["src", "gr32", "rego"]
				]
			},
			{
				"opcode": "0xCF",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xCF",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xCF",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xCF",
				"desc": "0x3",
				"args": [
					["dest", "gr8", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xCF",
				"desc": "0x4",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0xCF",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem32", "mem"]
				]
			},
			{
				"opcode": "0xC3",
				"desc": "0x9",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xCF",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xCF",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem16", "mem"]
				]
			}
		]
	},
	"rsh": {
		"description": "Right shift dest operand by source",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0xC4",
				"args": [
					["dest", "gr8", "regm"],
					["src", "gr8", "rego"]
				]
			},
			{
				"opcode": "0xC5",
				"args": [
					["dest", "gr16", "regm"],
					["src", "gr16", "rego"]
				]
			},
			{
				"opcode": "0xC6",
				"args": [
					["dest", "gr32", "regm"],
					["src", "gr32", "rego"]
				]
			},
			{
				"opcode": "0xC7",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xC7",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xC7",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xC7",
				"desc": "0x3",
				"args": [
					["dest", "gr8", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xC7",
				"desc": "0x4",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0xC7",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem32", "mem"]
				]
			},
			{
				"opcode": "0xC7",
				"desc": "0x9",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xC7",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xC7",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem16", "mem"]
				]
			}
		]
	},
	"sbb": {
		"description": "Subtracts src value with borrow from dest",
		"cycles": 1,
		"flags": {"BF":2, "VF":2, "ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0x88",
				"args": [
					["dest", "gr8", "regm"],
					["src", "gr8", "rego"]
				]
			},
			{
				"opcode": "0x89",
				"args": [
					["dest", "gr16", "regm"],
					["src", "gr16", "rego"]
				]
			},
			{
				"opcode": "0x8A",
				"args": [
					["dest", "gr32", "regm"],
					["src", "gr32", "rego"]
				]
			},
			{
				"opcode": "0x8B",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x8B",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x8B",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0x8B",
				"desc": "0x3",
				"args": [
					["dest", "gr8", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x8B",
				"desc": "0x4",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0x8B",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem32", "mem"]
				]
			},
			{
				"opcode": "0x8B",
				"desc": "0x6",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x8B",
				"desc": "0x7",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x8B",
				"desc": "0x8",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x8B",
				"desc": "0x9",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x8B",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x8B",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0x8B",
				"desc": "0xC",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms8", "mv8"]
				]
			},
			{
				"opcode": "0x8B",
				"desc": "0xD",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms16", "mv16"]
				]
			},
			{
				"opcode": "0x8B",
				"desc": "0xE",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems8", "mv8"]
				]
			},
			{
				"opcode": "0x8B",
				"desc": "0xF",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems16", "mv16"]
				]
			}
		]
	},
	"sdiv": {
		"description": "Divides with sign extension src value to dest",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0x9C",
				"args": [
					["dest", "gr8", "regm"],
					["src", "gr8", "rego"]
				]
			},
			{
				"opcode": "0x9D",
				"args": [
					["dest", "gr16", "regm"],
					["src", "gr16", "rego"]
				]
			},
			{
				"opcode": "0x9E",
				"args": [
					["dest", "gr32", "regm"],
					["src", "gr32", "rego"]
				]
			},
			{
				"opcode": "0x9F",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x9F",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x9F",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0x9F",
				"desc": "0x3",
				"args": [
					["dest", "gr8", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x9F",
				"desc": "0x4",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0x9F",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem32", "mem"]
				]
			},
			{
				"opcode": "0x9F",
				"desc": "0x6",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x9F",
				"desc": "0x7",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x9F",
				"desc": "0x8",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x9F",
				"desc": "0x9",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x9F",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x9F",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0x9F",
				"desc": "0xC",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms8", "mv8"]
				]
			},
			{
				"opcode": "0x9F",
				"desc": "0xD",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms16", "mv16"]
				]
			},
			{
				"opcode": "0x9F",
				"desc": "0xE",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems8", "mv8"]
				]
			},
			{
				"opcode": "0x9F",
				"desc": "0xF",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems16", "mv16"]
				]
			}
		]
	},
	"sea": {
		"Description": "Stores register value to address pointed in memory indirect address",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x68",
				"args": [
					["base", "gr32", "rego"],
					["dest", "gr8", "regm"]
				]
			},
			{
				"opcode": "0x69",
				"args": [
					["base", "gr32", "rego"],
					["dest", "gr16", "regm"]
				]
			},
			{
				"opcode": "0x6A",
				"args": [
					["base", "gr32", "rego"],
					["dest", "gr32", "regm"]
				]
			},
			{
				"opcode": "0x6B",
				"desc": "0x0",
				"args": [
					["base", "mem8", "mem"],
					["dest", "gr8", "regm"]
				]
			},
			{
				"opcode": "0x6B",
				"desc": "0x1",
				"args": [
					["base", "mem16", "mem"],
					["dest", "gr16", "regm"]
				]
			},
			{
				"opcode": "0x6B",
				"desc": "0x2",
				"args": [
					["base", "mem32", "mem"],
					["dest", "gr32", "regm"]
				]
			},
			{
				"opcode": "0x6C",
				"args": [
					["base", "gr32", "rego"],
					["offset", "imms16", "mv16"],
					["dest", "gr8", "regm"]
				]
			},
			{
				"opcode": "0x6D",
				"args": [
					["base", "gr32", "rego"],
					["offset", "imms16", "mv16"],
					["dest", "gr16", "regm"]
				]
			},
			{
				"opcode": "0x6E",
				"args": [
					["base", "gr32", "rego"],
					["offset", "imms16", "mv16"],
					["dest", "gr32", "regm"]
				]
			},
			{
				"opcode": "0x67",
				"args": [
					["base", "gr32", "rego"],
					["offset", "imms32", "mv32"],
					["dest", "gr32", "regm"]
				]
			}
		]
	},
	"setb": {
		"description": "Enables flag Borrow",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x12",
				"args": []
			}
		]
	},
	"setc": {
		"description": "Enables flag Carry",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x10",
				"args": []
			}
		]
	},
	"seti": {
		"description": "Enables external interruptions",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x0E",
				"args": []
			}
		]
	},
	"setn": {
		"description": "Enables flag Negative",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x16",
				"args": []
			}
		]
	},
	"seto": {
		"description": "Enables flag Odd",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x1A",
				"args": []
			}
		]
	},
	"sett": {
		"description": "Enables timer interruption",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x3E",
				"args": []
			}
		]
	},
	"setv": {
		"description": "Enables flag Overflow",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x14",
				"args": []
			}
		]
	},
	"setz": {
		"description": "Enables flag Zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x18",
				"args": []
			}
		]
	},
	"smod": {
		"description": "Gets the division remainder with sign extension from src value to dest",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0xA4",
				"args": [
					["dest", "gr8", "regm"],
					["src", "gr8", "rego"]
				]
			},
			{
				"opcode": "0xA5",
				"args": [
					["dest", "gr16", "regm"],
					["src", "gr16", "rego"]
				]
			},
			{
				"opcode": "0xA6",
				"args": [
					["dest", "gr32", "regm"],
					["src", "gr32", "rego"]
				]
			},
			{
				"opcode": "0xA7",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xA7",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0xA7",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0xA7",
				"desc": "0x3",
				"args": [
					["dest", "gr8", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xA7",
				"desc": "0x4",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0xA7",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem32", "mem"]
				]
			},
			{
				"opcode": "0xA7",
				"desc": "0x6",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xA7",
				"desc": "0x7",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xA7",
				"desc": "0x8",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0xA7",
				"desc": "0x9",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xA7",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xA7",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0xA7",
				"desc": "0xC",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms8", "mv8"]
				]
			},
			{
				"opcode": "0xA7",
				"desc": "0xD",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms16", "mv16"]
				]
			},
			{
				"opcode": "0xA7",
				"desc": "0xE",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems8", "mv8"]
				]
			},
			{
				"opcode": "0xA7",
				"desc": "0xF",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems16", "mv16"]
				]
			}
		]
	},
	"stab": {
		"description": "Sets the register value to 1 if reg1 is above than reg2, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x4F",
				"desc": "0x6",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			}
		]
	},
	"stae": {
		"description": "Sets the register value to 1 if reg1 is above or equal to reg2, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x4F",
				"desc": "0x8",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			}
		]
	},
	"stbe": {
		"description": "Sets the register value to 1 if reg1 is below or equal to reg2, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x4F",
				"desc": "0x9",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			}
		]
	},
	"stbl": {
		"description": "Sets the register value to 1 if reg1 is below than reg2, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x4F",
				"desc": "0x7",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			}
		]
	},
	"steq": {
		"description": "Sets the register value to 1 if reg1 is equal to reg2, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x4F",
				"desc": "0x0",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			}
		]
	},
	"steqz": {
		"description": "Sets the register value to 1 if reg1 is equal to zero, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x4F",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "gr32", "regm2"]
				]
			}
		]
	},
	"stge": {
		"description": "Sets the register value to 1 if reg1 is greater or equal to reg2, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x4F",
				"desc": "0x4",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			}
		]
	},
	"stgez": {
		"description": "Sets the register value to 1 if reg1 is greater or equal to zero, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x4F",
				"desc": "0xE",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "gr32", "regm2"]
				]
			}
		]
	},
	"stgt": {
		"description": "Sets the register value to 1 if reg1 is greater than reg2, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x4F",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			}
		]
	},
	"stgtz": {
		"description": "Sets the register value to 1 if reg1 is greater than zero, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x4F",
				"desc": "0xC",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "gr32", "regm2"]
				]
			}
		]
	},
	"stop": {
		"description": "Stops the processor and sends signal to stop the entire system",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xFA",
				"args": []
			}
		]
	},
	"stle": {
		"description": "Sets the register value to 1 if reg1 is lesser or equal to reg2, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x4F",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			}
		]
	},
	"stlez": {
		"description": "Sets the register value to 1 if reg1 is lesser or equal to zero, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x4F",
				"desc": "0xF",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "gr32", "regm2"]
				]
			}
		]
	},
	"stlt": {
		"description": "Sets the register value to 1 if reg1 is lesser than reg2, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x4F",
				"desc": "0x3",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			}
		]
	},
	"stltz": {
		"description": "Sets the register value to 1 if reg1 is lesser than zero, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x4F",
				"desc": "0xD",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "gr32", "regm2"]
				]
			}
		]
	},
	"stne": {
		"description": "Sets the register value to 1 if reg1 is not equal to reg2, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x4F",
				"desc": "0x1",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "gr32", "regm2"],
					["reg2", "gr32", "rego2"]
				]
			}
		]
	},
	"stnez": {
		"description": "Sets the register value to 1 if reg1 is not equal to zero, otherwise sets to zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x4F",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm1"],
					["reg1", "gr32", "regm2"]
				]
			}
		]
	},
	"sub": {
		"description": "Subtracts src value from dest",
		"cycles": 1,
		"flags": {"BF":2, "VF":2, "ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0x8C",
				"args": [
					["dest", "gr8", "regm"],
					["src", "gr8", "rego"]
				]
			},
			{
				"opcode": "0x8D",
				"args": [
					["dest", "gr16", "regm"],
					["src", "gr16", "rego"]
				]
			},
			{
				"opcode": "0x8E",
				"args": [
					["dest", "gr32", "regm"],
					["src", "gr32", "rego"]
				]
			},
			{
				"opcode": "0x8F",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x8F",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x8F",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0x8F",
				"desc": "0x3",
				"args": [
					["dest", "gr8", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x8F",
				"desc": "0x4",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0x8F",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem32", "mem"]
				]
			},
			{
				"opcode": "0x8F",
				"desc": "0x6",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x8F",
				"desc": "0x7",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0x8F",
				"desc": "0x8",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0x8F",
				"desc": "0x9",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x8F",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0x8F",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0x8F",
				"desc": "0xC",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms8", "mv8"]
				]
			},
			{
				"opcode": "0x8F",
				"desc": "0xD",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms16", "mv16"]
				]
			},
			{
				"opcode": "0x8F",
				"desc": "0xE",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems8", "mv8"]
				]
			},
			{
				"opcode": "0x8F",
				"desc": "0xF",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems16", "mv16"]
				]
			}
		]
	},
	"togc": {
		"description": "Toggles flag Carry",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x1C",
				"args": []
			}
		]
	},
	"togn": {
		"description": "Toggles flag Negative",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x1D",
				"args": []
			}
		]
	},
	"togo": {
		"description": "Toggles flag Odd",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x1F",
				"args": []
			}
		]
	},
	"togz": {
		"description": "Toggles flag Zero",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x1E",
				"args": []
			}
		]
	},
	"updfp": {
		"description": "Updates the Frame Pointer register with the Stack Pointer register",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x5F",
				"args": []
			}
		]
	},
	"wait": {
		"description": "Wait for interruption signal",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0xF9",
				"args": []
			}
		]
	},
	"xbch": {
		"Description": "Saves current program address and exchanges register value by program address",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x2F",
				"args": [
					["operand", "gr32", "regm"]
				]
			}
		]
	},
	"xchg": {
		"Description": "Exchanges the value between operands",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x78",
				"args": [
					["opr1", "gr8", "regm"],
					["opr2", "gr8", "rego"]
				]
			},
			{
				"opcode": "0x79",
				"args": [
					["opr1", "gr16", "regm"],
					["opr2", "gr16", "rego"]
				]
			},
			{
				"opcode": "0x7A",
				"args": [
					["opr1", "gr32", "regm"],
					["opr2", "gr32", "rego"]
				]
			},
			{
				"opcode": "0x7B",
				"desc": "0x0",
				"args": [
					["opr1", "mem8", "mem"],
					["opr2", "gr8", "regm"]
				]
			},
			{
				"opcode": "0x7B",
				"desc": "0x1",
				"args": [
					["opr1", "mem16", "mem"],
					["opr2", "gr16", "regm"]
				]
			},
			{
				"opcode": "0x7B",
				"desc": "0x2",
				"args": [
					["opr1", "mem32", "mem"],
					["opr2", "gr32", "regm"]
				]
			},
			{
				"opcode": "0xD0",
				"desc": "0xD",
				"args": [
					["opr1", "fpr", "regm1"],
					["opr2", "fpr", "regm2"]
				]
			}
		]
	},
	"xjmp": {
		"Description": "Exchanges register value by program address",
		"cycles": 1,
		"flags": {},
		"encode": [
			{
				"opcode": "0x27",
				"args": [
					["operand", "gr32", "regm"]
				]
			}
		]
	},
	"xor": {
		"description": "Do bitwise operation 'xor' between src and dest",
		"cycles": 1,
		"flags": {"ZF":2, "NF":2, "OF":2},
		"encode": [
			{
				"opcode": "0xB8",
				"args": [
					["dest", "gr8", "regm"],
					["src", "gr8", "rego"]
				]
			},
			{
				"opcode": "0xB9",
				"args": [
					["dest", "gr16", "regm"],
					["src", "gr16", "rego"]
				]
			},
			{
				"opcode": "0xBA",
				"args": [
					["dest", "gr32", "regm"],
					["src", "gr32", "rego"]
				]
			},
			{
				"opcode": "0xBB",
				"desc": "0x0",
				"args": [
					["dest", "gr8", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xBB",
				"desc": "0x1",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0xBB",
				"desc": "0x2",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm32", "mv32"]
				]
			},
			{
				"opcode": "0xBB",
				"desc": "0x3",
				"args": [
					["dest", "gr8", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xBB",
				"desc": "0x4",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0xBB",
				"desc": "0x5",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem32", "mem"]
				]
			},
			{
				"opcode": "0xBB",
				"desc": "0x6",
				"args": [
					["dest", "gr16", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xBB",
				"desc": "0x7",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm8", "mv8"]
				]
			},
			{
				"opcode": "0xBB",
				"desc": "0x8",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imm16", "mv16"]
				]
			},
			{
				"opcode": "0xBB",
				"desc": "0x9",
				"args": [
					["dest", "gr16", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xBB",
				"desc": "0xA",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem8", "mem"]
				]
			},
			{
				"opcode": "0xBB",
				"desc": "0xB",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mem16", "mem"]
				]
			},
			{
				"opcode": "0xBB",
				"desc": "0xC",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms8", "mv8"]
				]
			},
			{
				"opcode": "0xBB",
				"desc": "0xD",
				"args": [
					["dest", "gr32", "regm"],
					["src", "imms16", "mv16"]
				]
			},
			{
				"opcode": "0xBB",
				"desc": "0xE",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems8", "mv8"]
				]
			},
			{
				"opcode": "0xBB",
				"desc": "0xF",
				"args": [
					["dest", "gr32", "regm"],
					["src", "mems16", "mv16"]
				]
			}
		]
	}
}