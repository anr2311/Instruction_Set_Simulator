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
![image](https://github.com/anr2311/Instruction_Set_Simulator/assets/72514473/b93a83ec-51f6-4660-be46-2526fe6f2152)


The following machine instructions are part of the 'main' function to perform the above program:
![image](https://github.com/anr2311/Instruction_Set_Simulator/assets/72514473/dbc4d5ac-f52b-4250-b402-8435563463ad)

