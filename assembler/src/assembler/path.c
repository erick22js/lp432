#include "path.h"


//
//	PATH CORE
//

#define chrIsSeparator(chr) (chr=='/' || chr=='\\' || chr==0)

int pathWalk(bool abp, char* names, int *names_top, int* seeks, int *seeks_top, bool *shifted, char* in){
	// Split up the input path
	int ip = 0;
	
	if (chrIsSeparator(in[0])){
		if (abp){
			names[*names_top] = PATH_SEPARATOR;
			(*names_top)++;
			names[*names_top] = 0;
			(*names_top)++;
			(*seeks_top)++;
			seeks[*seeks_top] = *names_top;
			*shifted = true;
		}
		ip++;
	}
	
	while (in[ip]){
		do {
			int chr = in[ip];
			names[*names_top] = chr;
			ip++, (*names_top)++;
		} while(!chrIsSeparator(in[ip]));
		names[*names_top] = 0;
		(*names_top)++;
		
		// Detecting Directory name
		if (strcmp(&names[seeks[*seeks_top]], ".") == 0){
			seeks[*seeks_top] = *names_top;
		}
		else if (strcmp(&names[seeks[*seeks_top]], "..") == 0){
			if (*seeks_top>0){
				seeks[*seeks_top-1] = *names_top;
				(*seeks_top)--;
			}
		}
		else {
			(*seeks_top)++;
			seeks[*seeks_top] = *names_top;
		}
		
		if (in[ip]==0){
			break;
		}
		ip++;
	}
	
	return 0;
}

int pathBuild(char* names, int *names_top, int* seeks, int *seeks_top, bool shifted, char* out){
	int op = 0;
	//logo("directories: %d\n", *seeks_top);
	for (int ni=0; ni<*seeks_top; ni++){
		for (int ci=seeks[ni]; names[ci]; ci++){
			out[op] = names[ci];
			op++;
		}
		if (ni < ((*seeks_top)-1) && !(shifted && ni==0)){
			out[op] = PATH_SEPARATOR;
			op++;
		}
	}
	out[op] = 0;
	
	return 0;
}


//
//	PATH FUNCTIONS
//

void printEvery(char* txt, int size){
	for (int i=0; i<size; i++){
		printf("%c", txt[i]);
	}
	printf("\n");
}

bool pathIsAbsolute(PathPtr out) {
	if (out[0]=='/' || out[0]=='\\'){
		return true;
	}
	if (out[0]!=0 && out[1]==':' && (out[2]=='/' || out[2]=='\\')){
		return true;
	}
	return false;
}

// Rewrite walked path in "in" to "out"
int pathOpen(PathPtr out, char* in) {
	char names[(MAX_PATH_SIZE+1)*2];
	int name_top = 0;
	int seeks[MAX_PATH_SIZE] = {[0] = 0};
	int seek_top = 0;
	bool shifted = false;
	
	// Split up the input path
	pathWalk(true, names, &name_top, seeks, &seek_top, &shifted, in);
	
	// Join the split parts to output
	pathBuild(names, &name_top, seeks, &seek_top, shifted, out);
	
	return 0;
}

// Combine relative path in "in" to absolute "out"
int pathCombine(PathPtr out, char* in) {
	char names[(MAX_PATH_SIZE+1)*2];
	int name_top = 0;
	int seeks[MAX_PATH_SIZE] = {[0] = 0};
	int seek_top = 0;
	bool shifted = false;
	
	// Split up the input path
	pathWalk(true, names, &name_top, seeks, &seek_top, &shifted, out);
	pathWalk(false, names, &name_top, seeks, &seek_top, &shifted, in);
	
	// Join the split parts to output
	pathBuild(names, &name_top, seeks, &seek_top, shifted, out);
	
	return 0;
}
