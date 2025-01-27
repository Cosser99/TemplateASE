			AREA asmfunct,CODE,READONLY
			EXPORT prova
			EXPORT ciao
prova FUNCTION
			PUSH {R4-R8,LR}
			MOV R0,#5
			POP {R4-R8,PC}
			ENDFUNC
			

ciao FUNCTION
			PUSH {R4-R8,LR}
			MOV R0,#1
			POP {R4-R8,PC}
			ENDFUNC
			
			END