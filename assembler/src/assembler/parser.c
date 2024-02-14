#include "parser.h"


//
//	PARSER FUNCTIONS
//

Error psrParse(bool phase_two) {
	// Beggning of phase
	if (phase_two){
		logDevInfo("===========PHASE TWO=============\n\n");
	}
	else {
		logDevInfo("===========PHASE ONE=============\n\n");
	}
	asm_info.phase_two = phase_two;
	asm_info.static_exp = false;
	asm_info.bs = asm_info.ps = 0;
	scopeRestart();
	markReset();
	
	// Parsing loop
	Token tk;
	seekCreate();
	while (lexDepth()>0){
		err_offset = lexTell();
		errTryCatch(
			tkrFetch(&tk)
		);
		seekSave();
		
		// End-of-line continue loop fetch
		if (tk.type == TOKEN_EOL){
			// Detect if the current lexer has ended, if did, close it
			if (lexEnded()){
				if (scopeCurrent()->datas[0]!=lexCurrent()->datas[0]){
					// TODO: Error => Unmatched scope location
					err_offset = tk.position;
					errThrow(ERROR_UNMATCHED_SCOPE_LOCATION);
				}
				// Its a macro fragment
				if (lexCurrent()->datas[0]){
					if (scopeDepth()>1){
						scopeLeave();
					}
					else {
						// TODO: Error => Trying to leave the global scope
						err_offset = tk.position;
						errThrow(ERROR_LEAVING_GLOBAL_SCOPE);
					}
					logDevInfo("PSR: Closing macro \"%s\" invokation\n", ((Macro*)lexCurrent()->refs[0])->name);
				}
				// Its a file fragment
				else {
					logDevInfo("PSR: Closing src file at \"%s\"\n", lexCurrent()->path);
				}
				lexClose();
			}
			continue;
		}
		// Any name started statement
		else if (tk.type == TOKEN_NAME){
			char* name = tk.value.str;
			u32 off_name = tk.position;
			
			// Label definition
			errTryCatch(
				tkrFetch(&tk)
			);
			if (tkIsSymbol(tk, ':')){
				// Ignore on second phase
				if (asm_info.phase_two) {
					continue;
				}
				if (symvHasInCurrentScope(name)){
					// TODO: Error => Symbol with given name is already declarated
					err_offset = off_name;
					errThrow(ERROR_SYMBOL_ALREADY_DEFINED);
				}
				logDevInfo("SYM: Declaring label with name \"%s\" with value 0x%X\n", name, asm_info.ps);
				labelStore(name, asm_info.ps);
				continue;
			}
			seekRestore();
			
			// Instruction statement
			Instruction *instr = null;
			if ((instr = instrFindByName(name))){
				logDevInfo("PSR: Mnemonic \"%s\"\n", name);
				
				// Trying to fetch sufix descriptor
				int sufix = -1;
				bool sufix_o = false;
				seekSave();
				errTryCatch(
					tkrFetch(&tk)
				);
				if (tkIsSymbol(tk, '.')){
					errTryCatch(
						tkrFetch(&tk)
					);
					if (tk.type!=TOKEN_NAME || ((sufix = instrFindSufix(tk.value.str, &sufix_o))<0)){
						// TODO: Error => Expected a instruction sufix name
						err_offset = tk.position;
						errThrow(ERROR_EXPECTED_INSTRUCTION_SUFIX);
					}
					logDevInfo("PSR: Suffix \"%s\" detected\n", tk.value.str)
				}
				else {
					seekRestore();
				}
				
				// Fetching every instruction parameter
				Value args[MAX_CMD_PARAMS];
				int args_len = 0;
				errTryCatch(
					expArgumentsFetch(args, &args_len)
				);
				
				// Matching up every encoding combination
				InstrEncode *encode = null;
				for (int i=0; i<instr->encodes_len; i++){
					InstrEncode *enc = &instr->encodes[i];
					if (enc->params_len!=args_len){
						continue;
					}
					if (!paramMatches(enc->params, args, args_len)){
						continue;
					}
					//logDevInfo("CMP: Matched arguments! encode {%d}\n", i);
					if (enc->desc == NO_DESC && sufix>=0){
						continue;
					}
					//logDevInfo("CMP: Matched no description!\n");
					if (enc->desc != NO_DESC){
						if ((enc->desc == COND_DESC || enc->desc == CONDO_DESC) && sufix<0){
							continue;
						}
						//logDevInfo("CMP: Matched no conditional!\n");
						if (((enc->desc == COND_DESC) && sufix_o) || ((enc->desc == CONDO_DESC) && !sufix_o)){
							continue;
						}
					}
					//logDevInfo("CMP: Matched encode!\n");
					logDevInfo("CMP: Matched encode {%d}\n", i);
					encode = enc;
					break;
				}
				
				if (encode){
					encInstruction(encode, args, sufix);
					continue;
				}
				// No any pattern matched
				else {
					// TODO: Error => No any parameter pattern matched
					err_offset = off_name;
					errThrow(ERROR_INSTRUCTION_NO_PATTERN);
				}
			}
			
			// Macro invokation
			Macro *macro = null;
			if ((macro = macroFind(name))){
				logDevInfo("PSR: Macro invokation \"%s\"\n", name);
				
				Value args[MAX_CMD_PARAMS];
				int args_len;
				errTryCatch(
					expArgumentsFetch(args, &args_len)
				);
				
				// Checking for variable matching
				if (args_len!=macro->params_len || !paramMatches(macro->params, args, args_len)){
					// TODO: Error => Macro parameters pattern not matched
					err_offset = off_name;
					errThrow(ERROR_MACRO_NO_PATTERN);
				}
				
				// Opening macro context
				Lexer *lex = lexOpenStream(macro->src, macro->src_len);
				pathOpen(lex->path, macro->path);
				lex->datas[0] = true;
				lex->refs[0] = macro;
				scopeEnter()->datas[0] = true;
				for (int i=0; i<args_len; i++){
					constStore((char*)macro->params[i].name, args[i]);
				}
				
				continue;
			}
			
			// TODO: Error => Unexpected name
			err_offset = off_name;
			errThrow(ERROR_UNEXPECTED_NAME);
		}
		// Begin of processor command
		else if (tkIsSymbol(tk, '.')){
			u32 off_cmd = tk.position;
			errTryCatch(
				tkrFetch(&tk)
			);
			if (tk.type != TOKEN_NAME){
				// TODO: Error => Expected a processor command
				err_offset = tk.position;
				errThrow(ERROR_EXPECTED_COMMAND);
			}
			
			// Command: Including a src file
			if (strcmp(tk.value.str, "include")==0){
				errTryCatch(
					tkrFetch(&tk)
				);
				if (tk.type != TOKEN_STRING){
					// TODO: Error => Expected string value
					err_offset = tk.position;
					errThrow(ERROR_EXPECTED_STRING);
				}
				
				Path path;
				pathOpen(path, lexCurrent()->path);
				pathCombine(path, "..");
				pathCombine(path, tk.value.str);
				logDevInfo("PSR: Opening src file at \"%s\"\n", path);
				errTryCatch(
					tkrFetch(&tk)
				);
				if (tk.type != TOKEN_EOL){
					// TODO: Error => Expected end of line
					err_offset = tk.position;
					errThrow(ERROR_EXPECTED_EOL);
				}
				if (!lexOpenFile(path)){
					// TODO: Error => Src file could not be opened
					err_offset = off_cmd;
					errThrow(ERROR_SRC_FILE_NOT_OPEN);
				}
				// Current lexer are not a macro invokation
				lexCurrent()->datas[0] = false;
				continue;
			}
			// Command: File mark
			else if (strcmp(tk.value.str, "mark")==0 || strcmp(tk.value.str, "onmark")==0 || strcmp(tk.value.str, "nonmark")==0 || strcmp(tk.value.str, "unmark")==0){
				char* cmd = tk.value.str;
				seekSave();
				errTryCatch(
					tkrFetch(&tk)
				);
				
				char* mark = null;
				if (tk.type == TOKEN_STRING || tk.type == TOKEN_NAME){
					mark = tk.value.str;
				}
				else {
					mark = reuseName(lexCurrent()->path);
					seekRestore();
				}
				
				if (strcmp(cmd, "mark")==0){
					logDevInfo("MRK: Marking with id \"%s\"\n", mark);
					if (!markFind(mark)){
						markStore(mark);
					}
				}
				if (strcmp(cmd, "onmark")==0){
					if (markFind(mark)){
						logDevInfo("MRK: Skipping file with mark id \"%s\"\n", mark);
						lexClose();
						continue;
					}
					else {
						logDevInfo("MRK: Following file with mark id \"%s\"\n", mark);
					}
				}
				if (strcmp(cmd, "nonmark")==0){
					if (markFind(mark)){
						logDevInfo("MRK: Following file without mark id \"%s\"\n", mark);
					}
					else {
						logDevInfo("MRK: Skipping file without mark id \"%s\"\n", mark);
						lexClose();
						continue;
					}
				}
				if (strcmp(cmd, "unmark")==0){
					logDevInfo("MRK: Unmarking with id \"%s\"\n", mark);
					if (markFind(mark)){
						markRemove(mark);
					}
				}
			}
			// Command: Literal data
			else if (strcmp(tk.value.str, "byte")==0 || strcmp(tk.value.str, "half")==0 || strcmp(tk.value.str, "word")==0 || strcmp(tk.value.str, "dword")==0){
				int size = strcmp(tk.value.str, "byte")==0? 1: strcmp(tk.value.str, "half")==0? 2: strcmp(tk.value.str, "word")==0? 4: 8;
				while (!lexEnded()){
					Value val;
					expFetch(&val);
					if (size==1){
						encOut8((u8)val.val.lit);
					}
					if (size==2){
						encOut16((u16)val.val.lit);
					}
					if (size==4){
						encOut32((u32)val.val.lit);
					}
					if (size==8){
						encOut64(val.val.lit);
					}
					seekSave();
					
					errTryCatch(
						tkrFetch(&tk)
					);
					if (!tkIsSymbol(tk, ',')){
						seekRestore();
						break;
					}
				}
			}
			// Command: Literal text
			else if (strcmp(tk.value.str, "text")==0){
				errTryCatch(
					tkrFetch(&tk)
				);
				if (tk.type != TOKEN_STRING){
					// TODO: Error => Expected string value
					err_offset = tk.position;
					errThrow(ERROR_EXPECTED_STRING);
				}
				
				for (int i=0; i<(int)tk.length; i++){
					encOut8(tk.value.str[i]);
				}
			}
			// Command: Change of seek from program address or binary position
			else if (strcmp(tk.value.str, "address")==0 || strcmp(tk.value.str, "seek")==0){
				u32 off_val = lexTell();
				asm_info.static_exp = true;
				Value val = {0};
				errTryCatch(
					expFetch(&val)
				);
				asm_info.static_exp = false;
				if (!typeIsImm(val.type)){
					// TODO: Error => Expected a immediate constant expression
					err_offset = off_val;
					errThrow(ERROR_EXPECTED_IMMEDIATE);
				}
				if (strcmp(tk.value.str, "address")==0){
					asm_info.ps = (u32)val.val.lit;
					logDevInfo("PSR: Changing address of program to 0x%X\n", (u32)val.val.lit);
				}
				else {
					asm_info.bs = (u32)val.val.lit;
					logDevInfo("PSR: Changing position of binary to 0x%X\n", (u32)val.val.lit);
				}
			}
			// Command: Align binary and adjust program position to it
			else if (strcmp(tk.value.str, "align")==0){
				errTryCatch(
					tkrFetch(&tk)
				);
				Castname *cn = null;
				if (tk.type!=TOKEN_NAME || !(cn = baseFindCastname(tk.value.str))){
					// TODO: Error => Expected a cast name
					err_offset = tk.position;
					errThrow(ERROR_EXPECTED_CASTNAME);
				}
				int size = cn->size;
				
				u32 lps = asm_info.ps;
				asm_info.ps = lps&(size-1)? (lps&(~(size-1))) + size: lps;
				asm_info.bs += asm_info.ps-lps;
				logDevInfo("PSR: Aligning position of binary to 0x%X\n", asm_info.bs);
				logDevInfo("PSR: Adjusting address of program to 0x%X\n", asm_info.ps);
			}
			// Command: Constant declaration
			else if (strcmp(tk.value.str, "const")==0){
				errTryCatch(
					tkrFetch(&tk)
				);
				if (tk.type != TOKEN_NAME){
					// TODO: Error => Expected constant name
					err_offset = tk.position;
					errThrow(ERROR_EXPECTED_NAME);
				}
				char* name = tk.value.str;
				
				if (!asm_info.phase_two){
					logDevInfo("SYM: Declaring const with name \"%s\"\n", name);
				}
				asm_info.static_exp = true;
				Value val = {0};
				errTryCatch(
					expFetch(&val)
				);
				asm_info.static_exp = false;
				
				if (!asm_info.phase_two){
					if (symvHasInCurrentScope(name)){
						// TODO: Error => Trying to declare already declarated constant
						err_offset = off_cmd;
						errThrow(ERROR_SYMBOL_ALREADY_DEFINED);
					}
					constStore(name, val);
				}
			}
			// Command: Scope entering
			else if (strcmp(tk.value.str, "scope")==0){
				seekSave();
				errTryCatch(
					tkrFetch(&tk)
				);
				if (tk.type == TOKEN_NAME){
					char* name = tk.value.str;
					if (!asm_info.phase_two) {
						if (symvHasInCurrentScope(name)){
							// TODO: Error => Symbol with given name is already declarated
							err_offset = off_cmd;
							errThrow(ERROR_SYMBOL_ALREADY_DEFINED);
						}
						logDevInfo("SYM: Declaring label with name \"%s\" with value 0x%X\n", name, asm_info.ps);
						labelStore(name, asm_info.ps);
					}
				}
				else {
					seekRestore();
				}
				Scope *scope = scopeEnter();
				scope->datas[0] = false; // Current scope is owned by macro
				scope->refs[0] = null;
			}
			// Command: Scope leaving
			else if (strcmp(tk.value.str, "endscope")==0){
				if (scopeDepth()>1){
					if (scopeCurrent()->datas[0]){
						// TODO: Error => Cannot leave a macro scope
						err_offset = off_cmd;
						errThrow(ERROR_LEAVING_MACRO_SCOPE);
					}
					scopeLeave();
				}
				else {
					// TODO: Error => Trying to leave the global scope
					err_offset = off_cmd;
					errThrow(ERROR_LEAVING_GLOBAL_SCOPE);
				}
			}
			// Command: Macro declaration
			else if (strcmp(tk.value.str, "macro")==0){
				errTryCatch(
					tkrFetch(&tk)
				);
				if (tk.type != TOKEN_NAME){
					// TODO: Error => Expected macro name
					err_offset = tk.position;
					errThrow(ERROR_EXPECTED_NAME);
				}
				char* name = tk.value.str;
				
				// Fetching the params of macro
				Param params[MAX_CMD_PARAMS];
				int params_len = 0;
				seekSave();
				for (int i=0; i<MAX_CMD_PARAMS; i++){
					// Gathering param name
					errTryCatch(
						tkrFetch(&tk)
					);
					if (tk.type!=TOKEN_NAME){
						break;
					}
					params[i].name = tk.value.str;
					params[i].type = TYPE_VARIABLE;
					params_len++;
					seekSave();
					
					// Gathering param type
					errTryCatch(
						tkrFetch(&tk)
					);
					if (tkIsSymbol(tk, ':')){
						errTryCatch(
							tkrFetch(&tk)
						);
						if (tk.type!=TOKEN_NAME){
							// TODO: Error => Expected datatype name
							err_offset = tk.position;
							errThrow(ERROR_EXPECTED_DATANAME);
						}
						Typename *tn = baseFindTypename(tk.value.str);
						if (tn){
							params[i].type = tn->type;
						}
						else {
							// TODO: Error => Expected datatype name
							err_offset = tk.position;
							errThrow(ERROR_EXPECTED_DATANAME);
						}
						seekSave();
					}
					else {
						seekRestore();
					}
					
					// Expecting for argument comma separator in case of any other param
					errTryCatch(
						tkrFetch(&tk)
					);
					if (tkIsSymbol(tk, ',')){
						seekSave();
					}
					else {
						break;
					}
				}
				seekRestore();
				
				if (tk.type != TOKEN_EOL){
					// TODO: Error => Expected end of line
					err_offset = tk.position;
					errThrow(ERROR_EXPECTED_EOL);
				}
				
				u32 start = lexTell();
				u32 end = lexTell();
				u32 line = 1, collumn = 1;
				if (!asm_info.phase_two){
					lexPosition(start, &line, &collumn);
				}
				logDevInfo("PSR: Declaration of macro \"%s\" at offset %d\n", name, start);
				while (!lexEnded()){
					tkrConsumeLeftLine();
					end = lexTell();
					errTryCatch(
						tkrFetch(&tk)
					);
					if (tkIsSymbol(tk, '.')){
						u32 off_scmd = tk.position;
						errTryCatch(
							tkrFetch(&tk)
						);
						if (tk.type==TOKEN_NAME && strcmp(tk.value.str, "endmacro")==0){
							break;
						}
						if (tk.type==TOKEN_NAME && strcmp(tk.value.str, "macro")==0){
							// TODO: Error => Cannot declare a macro inside a macro declaration
							err_offset = off_scmd;
							errThrow(ERROR_MACRO_INSIDE_MACRO);
						}
						if (tk.type==TOKEN_NAME && (strcmp(tk.value.str, "onmark")==0 || strcmp(tk.value.str, "nonmark")==0)){
							// TODO: Error => Cannot skip file by mark inside a macro
							err_offset = off_scmd;
							errThrow(ERROR_SKIP_INSIDE_MACRO);
						}
					}
				}
				logDevInfo("PSR: End of the declaration of macro \"%s\" at offset %d\n", name, end);
				if (!asm_info.phase_two){
					if (macroFindInScope(name, scopeCurrent())){
						// TODO: Error => Declaring a macro with same name as defined previously
						err_offset = off_cmd;
						errThrow(ERROR_MACRO_SAME_NAME);
					}
					Macro *macro = macroStore(name, (u8*)lexCopyBuffer(start, end-start), end-start, params, params_len);
					macro->line = line-1;
					pathOpen(macro->path, lexCurrent()->path);
					logDevInfo("$MACRO:\n");
					for (int i=0; i<(int)macro->src_len; i++){
						logDevInfo("%c", macro->src[i]);
					}
					logDevInfo("$ENDMACRO\n");
				}
			}
			// Command: Print a debug message to output
			else if (strcmp(tk.value.str, "print")==0){
				errTryCatch(
					tkrFetch(&tk)
				);
				if (tk.type != TOKEN_STRING){
					// TODO: Error => Expected string value
					err_offset = tk.position;
					errThrow(ERROR_EXPECTED_STRING);
				}
				logUserInfo("Message: %s\n", tk.value.str);
			}
			else {
				// TODO: Error => Expected a processor command
				err_offset = tk.position;
				errThrow(ERROR_EXPECTED_COMMAND);
			}
			
			// Expecting for end-of-line after command
			errTryCatch(
				tkrFetch(&tk)
			);
			if (tk.type != TOKEN_EOL){
				// TODO: Error => Expected end of line
				err_offset = tk.position;
				errThrow(ERROR_EXPECTED_EOL);
			}
		}
		// Any other unexpected token
		else {
			// TODO: Error => Unexpected token
			err_offset = tk.position;
			errThrow(ERROR_UNEXPECTED_TOKEN);
		}
	}
	
	// Ending of phase
	if (phase_two){
		logDevInfo("\nEnding of phase 2\n\n\n");
	}
	else {
		asm_info.bin = mem_alloc(asm_info.bin_size);
		memset(asm_info.bin, 0, asm_info.bin_size);
		logDevInfo("\nEnding of phase 1\n\n\n");
	}
	
	return ERROR_NONE;
}

