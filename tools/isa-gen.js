const fs = require("fs");
let isa_j = JSON.parse(fs.readFileSync("../docs/isa.json", {"encoding": "utf-8"}));
let table = new Array(256);
let ordered = [];

let c_code = '#include "base.h"\n\n\nIst isa[] = {';
let mnes = '';

let first = true;
for (let name in isa_j){
	let mne = isa_j[name];
	mne.name = name;
	ordered.push(mne);
	mnes += name+' ';
	
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
		
		// Adding to table
		if (!table[Number(enc.opcode)]){
			table[Number(enc.opcode)] = [];
		}
		enc.mne = mne;
		table[Number(enc.opcode)].push(enc);
		
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
fs.writeFileSync('./mnemonics.txt', mnes, {"encoding": "utf-8"});

// Writing HTML datasheet
let datasheet = '<html><head></head><style>td{border:1px solid black; padding: 5px;}\n.content{width:70px; height:30px; font-size:10pt; overflow:hidden; user-select:none;}</style><body>';
datasheet += '<table line="10px">';

function mountEncode(enc){
	let args = '';
	for (let i=0; i<enc.args.length; i++){
		args += ' '+enc.args[i][0]+':'+enc.args[i][1];
	}
	return enc.mne.name+(enc.desc=="cond"? ".cf": enc.desc=="condo"? ".co": "")+args;
}

for (let h=-1; h<16; h++){
	datasheet += '<tr>';
	for (let l=-1; l<16; l++){
		if (h==-1 && l==-1){
			datasheet += '<td>-</td>';
		}
		else if (h==-1){
			datasheet += '<td style="background-color:green; font-weight:bold; color:white;">0x_'+l.toString(16).toUpperCase()+'</td>';
		}
		else if (l==-1){
			datasheet += '<td style="background-color:green; font-weight:bold; color:white;">0x'+h.toString(16).toUpperCase()+'_</td>';
		}
		else {
			let encs = table[(h<<4)|l];
			let list = '';
			if (encs){
				for (let i=0; i<encs.length; i++){
					list += mountEncode(encs[i])+'\n';
				}
			}
			datasheet += '<td title="'+list+'"><div class="content">'+(encs && encs.length? mountEncode(encs[0]):'')+'</div></td>';
		}
	}
	datasheet += '</tr>';
}
datasheet += '</table><br/><br/>';

// Write info for each instruction mnemonic
ordered.sort(function(a, b){return a.name-b.name;});
for (let mi=0; mi<ordered.length; mi++){
	let mne = ordered[mi];
	datasheet += '<h1>'+mne.name+'</h1>';
	datasheet += '<table><tr><td><b>Opcode</b></td><td><b>Encode</b></td><td><b>Instruction</b></td><td><b>Clocks</b></td><td><b>Description</b></td></tr>';
	for (let vi=0; vi<mne.encode.length; vi++){
		let enc = mne.encode[vi];
		let opcode = enc.opcode.substr(2, 2);
		let encode = '';
		let instruction = mne.name;
		let clocks = mne.cycles;
		let description = '';
		
		if (enc.desc=="cond"){
			opcode += " /c";
		}
		else if (enc.desc=="condo"){
			opcode += " /co";
		}
		else if (enc.desc){
			opcode += " "+enc.desc.substr(2, 1)+"_";
		}
		
		for (let ai=0; ai<enc.args.length; ai++){
			let arg = enc.args[ai];
			encode += ' '+arg[0]+':'+arg[2]+(ai==(enc.args.length-1)? '': ',');
			instruction += ' '+arg[0]+':'+arg[1]+(ai==(enc.args.length-1)? '': ',');
		}
		
		datasheet += '<tr><td>'+opcode+'</td><td>'+encode+'</td><td>'+instruction+'</td><td>'+clocks+'</td><td>'+description+'</td></tr>';
	}
	datasheet += '</table>';
	
	datasheet += '<h3>Description</h3>'+mne.description+'<br/>';
	
	let flags = '';
	for (let fn in mne.flags){
		flags += fn+' ';
	}
	datasheet += '<h3>Flags Affected</h3>'+(flags==''? 'None': flags)+'<br/>';
	
	datasheet += '<br/><hr/>';
}

datasheet += '</body></html>';
fs.writeFileSync('./datasheet.html', datasheet, {"encoding": "utf-8"});
console.log('Done!');
