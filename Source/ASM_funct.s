			AREA asmfunct,CODE,READONLY
			EXPORT prova
			EXPORT ciao
			EXPORT call_svc
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

call_svc  
		    MOV r0,r13
		    svc #0x000000FF
		    NOP
		    B .
		    ENDP
				
			END