.onmark
.mark


//
//	MACROS DEFINITION
//

//
//	Save Context for function execution
//
.macro _saveCtx
	psh eax
	psh edx
	psh ecx
	psh ebx
	psh eex
	psh ehx
	psh egx
	psh efx
	psh ex0
	psh ex1
	psh ex2
	psh ex3
	psh ess
	psh esd
.endmacro

//
//	Save Context for function return
//
.macro _restoreCtx
	pop esd
	pop ess
	pop ex3
	pop ex2
	pop ex1
	pop ex0
	pop efx
	pop egx
	pop ehx
	pop eex
	pop ebx
	pop ecx
	pop edx
	pop eax
.endmacro
