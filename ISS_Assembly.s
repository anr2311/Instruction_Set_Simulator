	      MOV R0, #25
	      MOV R4, #25 ;storing the same data in a redundant register
	      MOV R1, #40
	      MOV R5, #40 ;storing the same data in a redundant register
        MOV R2, #5 ;storing the HCF of the above data in another register
Loop:   SUB R0, R2
        JZ R0, LESS
	      SUB R1, R2
	      JZ R1, GREAT
	      JZ R3, Loop
LESS:   MOV 0x01, R4 ;if the comparison operation results in a < b, result stored in memory ‘c’
	      STOP
GREAT:  MOV 0x01, R5 ;if the comparison operation results in a > b, result stored in memory ‘c’
	      STOP
