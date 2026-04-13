ORG 0000H
	MOV A,#0FEH
	
	LOOP: MOV P1,A
	      ACALL DELAY
		  
		  RL A
		  SJMP LOOP
		  
	DELAY: MOV R1,#255
	       D1:MOV R2,#255
		   D2:DJNZ R2,D2
		   DJNZ R1,D1
		   RET
		   
END
