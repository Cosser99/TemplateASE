	PRESERVE8
    THUMB
					
	AREA input_data, READONLY, ALIGN=4
    LTORG       ; Inserisce il literal pool qui
	ALIGN 2
DATA_IN  	DCB  0x0A,	0x01, 0x13, 0x02, 0x04, 0x06, 0x0F, 0x0A ; Dati definiti nel literal pool
	ALIGN 2
N 		 	DCD 8
	ALIGN 2

	AREA output_data, READWRITE, ALIGN=4
BEST_3 		DCB 0x0, 0x0, 0x0
	ALIGN 2
	
	EXPORT DATA_IN
	EXPORT N
	EXPORT BEST_3
		
	AREA asm_functions, CODE, READONLY	
	EXPORT  find_best_3
	EXPORT prova2

find_best_3 FUNCTION
	
	;RO = DATA_IN address last position
	;R1 = N 
	;R2 = BEST_3 address
	
		
	; save current SP for a faster access 
	; to parameters in the stack
	MOV   r12, sp
	; save volatile registers
	STMFD sp!,{r4-r8,r10-r11,lr}			
	
	MOV R10, R0
	MOV R11, R1
	
	LDRB R6, [R10], #1         ; Carica il primo elemento dell'array in R6 (massimo iniziale)
	SUBS R11, R11, #1          ; Decrementa la dimensione (R1 = dim - 1)
	BLE exitMax1              ; Se R1 <= 0, salta direttamente all'uscita
	MOV R12, #0 ;save position of max
	
loopMax1
	LDRB R4, [R10], #1         ; Carica l'elemento corrente in R4 e avanza il puntatore R0
	CMP R4, R6               ; Confronta l'elemento corrente (R4) con il massimo attuale (R6)
	MOVGT R6, R4             ; Se R4 > R6, aggiorna il massimo in R6
	MOVGT R12, R11
	SUBS R11, R11, #1          ; Decrementa il contatore R1
	BGT loopMax1              ; Ripeti finché R1 > 0

	
exitMax1
	STRB R6,[R2],#1
	
;part 2

	MOV R10, R0
	MOV R11, R1
	
	LDRB R6, [R10], #1         ; Carica il primo elemento dell'array in R6 (massimo iniziale)
	SUBS R11, R11, #1          ; Decrementa la dimensione (R1 = dim - 1)
	BLE exitMax2              ; Se R1 <= 0, salta direttamente all'uscita
	MOV R3, #0 ;save position of max
	
loopMax2
	LDRB R4, [R10], #1         ; Carica l'elemento corrente in R4 e avanza il puntatore R0
	TEQ R12,R11
	BEQ skipLoopMax2
	CMP R4, R6               ; Confronta l'elemento corrente (R4) con il massimo attuale (R6)
	MOVGT R6, R4             ; Se R4 > R6, aggiorna il massimo in R6
	MOVGT R3, R11
skipLoopMax2
	SUBS R11, R11, #1          ; Decrementa il contatore R1
	BGT loopMax2              ; Ripeti finché R1 > 0

	
exitMax2
	STRB R6,[R2],#1
	
;part 3
	MOV R10, R0
	MOV R11, R1
	
	LDRB R6, [R10], #1         ; Carica il primo elemento dell'array in R6 (massimo iniziale)
	SUBS R11, R11, #1          ; Decrementa la dimensione (R1 = dim - 1)
	BLE exitMax3              ; Se R1 <= 0, salta direttamente all'uscita
	MOV R9, #0 ;save position of max
	
loopMax3
	LDRB R4, [R10], #1         ; Carica l'elemento corrente in R4 e avanza il puntatore R0
	TEQ R12,R11
	BEQ skipLoopMax3
	CMP R3,R11
	BEQ skipLoopMax3
	CMP R4, R6               ; Confronta l'elemento corrente (R4) con il massimo attuale (R6)
	MOVGT R6, R4             ; Se R4 > R6, aggiorna il massimo in R6
	MOVGT R9, R11
skipLoopMax3
	SUBS R11, R11, #1          ; Decrementa il contatore R1
	BGT loopMax3              ; Ripeti finché R1 > 0

	
exitMax3
	STRB R6,[R2],#1
				
	; setup a value for R0 to return
	MOV	  R0, R1

	; restore volatile registers
	LDMFD sp!,{r4-r8,r10-r11,pc}				
	ENDFUNC					

prova2 FUNCTION
			PUSH {R4-R8,LR}
			MOV R0,#8
			POP {R4-R8,PC}
			ENDFUNC
			
	END	