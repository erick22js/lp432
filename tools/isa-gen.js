const fs = require("fs");
let isa_j = JSON.parse(fs.readFileSync("../docs/isa.json", {"encoding": "utf-8"}));

let c_code = '#include "base.h"\n\n\nIst isa[] = {';

let first = true;
for (let name in isa_j){
	let mne = isa_j[name];
	
	if (first){
		first = false;
		c_code += '\n';
	}
	else {
		c_code += ',\n';
	}
	c_code += '\t{\n';
	c_code += '\t\t.mne = "'+name+'",\n';
	c_code += '\t\t.encodes_length = '+mne.encode.length+',\n';
	c_code += '\t\t.encodes = {';
	
	for (let e=0; e<mne.encode.length; e++){
		let enc = mne.encode[e];
		
		if (e==0){
			c_code += '\n';
		}
		else {
			c_code += ',\n';
		}
		c_code += '\t\t\t{\n';
		c_code += '\t\t\t\t.opcode = 0x'+Number(enc.opcode).toString(16).toUpperCase()+
			', .desc = '+(typeof(enc.desc) === 'undefined'? 'NO_DESC':
				enc.desc=="cond"? 'COND_DESC':
				enc.desc=="condo"? 'CONDO_DESC': '0x'+Number(enc.desc).toString(16).toUpperCase())+',\n';
		c_code += '\t\t\t\t.params_length = '+enc.args.length;
		
		if (enc.args.length){
			c_code += ',\n\t\t\t\t.params = {';
			
			for (let p=0; p<enc.args.length; p++){
				let param = enc.args[p];
				if (p==0){
					c_code += '\n';
				}
				else {
					c_code += ',\n';
				}
				let type = 'TYPE_'+param[1].toUpperCase();
				let encode = 'ENCODE_'+param[2].toUpperCase();
				c_code += '\t\t\t\t\t{ .type = '+type+', .encode = '+encode+' }';
			}
			
			c_code += '\n\t\t\t\t}\n';
		}
		else {
			c_code += '\n';
		}
		
		c_code += '\t\t\t}';
	}
	
	c_code += '\n\t\t}\n';
	c_code += '\t}';
}

c_code += '\n};\nconst int isa_length = sizeof(isa)/sizeof(Ist);\n';
fs.writeFileSync('../assembler/src/assembler/instructions.c', c_code, {"encoding": "utf-8"});
