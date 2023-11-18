# Instruction_Set_Simulator
The repo contains an instruction set simulator which is essentially a high-level application that mimics a custom processor / instruction set

The custom instruction set used for this simulator is:
![image](https://github.com/anr2311/Instruction_Set_Simulator/assets/72514473/a6db2e5f-490d-423b-a310-1372be330006)

The instruction set simulator works on the following program:
char a = 25; //The variable value is a representation. Ideally in your executable, treat 'a' and 'b' as a variable
char b = 40;
char c = 0; //initialize 'c' to '0'
if (a < b) c = 25;
if (a > b) c = 40;

The assembly equivalent of the above program (some considerations taken for ease of converting into machine level code):
       MOV R0, #25
       MOV R4, #25 ;storing the same data in a redundant register
       MOV R1, #40
       MOV R5, #40 ;storing the same data in a redundant register
       MOV R2, #5 ;storing the HCF of the above data in another register
Loop:  SUB R0, R2
       JZ R0, LESS
       SUB R1, R2
       JZ R1, GREAT
       JZ R3, Loop
LESS:  MOV 0x01, R4 ;if the comparison operation results in a < b, result stored in memory ‘c’
       STOP
GREAT: MOV 0x01, R5 ;if the comparison operation results in a > b, result stored in memory ‘c’
       STOP


The following machine instructions are part of the 'main' function to perform the above program:
![image](https://github.com/anr2311/Instruction_Set_Simulator/assets/72514473/dbc4d5ac-f52b-4250-b402-8435563463ad)

