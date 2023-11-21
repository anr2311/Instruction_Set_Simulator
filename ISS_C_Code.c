#include <stdio.h>

unsigned short reg[16];
unsigned short pmem[256];
unsigned short dmem[256];

unsigned long int PC = 0;
int STOP = 0;

void execute(unsigned char nibble4, unsigned char nibble3, unsigned char nibble2, unsigned char nibble1)
{
    // printing the incoming instruction nibble by nibble
    printf("%d, %d, %d, %d\n\n", nibble4, nibble3, nibble2, nibble1);
    
    // Logic for executing the opcodes
    switch(nibble4)
    {
        case 0:
            // Rn = M(direct)
            reg[nibble3] = dmem[((nibble2 << 4) | nibble1)];
            break;
        case 1:
            // M(direct) = Rn
            dmem[((nibble2 << 4) | nibble1)] = reg[nibble3];
            break;
        case 2:
            // M(Rn) = Rm
            dmem[reg[nibble2]] = reg[nibble1];
            break;
        case 3:
            // Rn = immediate
            reg[nibble3] = ((nibble2 << 4) | nibble1);
            break;
        case 4:
            // Rn = Rn + Rm
            reg[nibble2] = reg[nibble2] + reg[nibble1];
            break;
        case 5:
            // Rn = Rn - Rm
            reg[nibble2] = reg[nibble2] - reg[nibble1];
            break;
        case 8:
            // PC = PC + relative only when Rn > 0
            if (reg[nibble3] == 0)
            {
                PC = PC + (signed char) ((nibble2 << 4) | nibble1);
            }
            break;
        case 15: // MSB nibble of 0xF is a STOP instruction
            STOP = 1;
            break;
        default:
            break;
    }
}

void init() {
    // Initialize registers and data memory
    for (int i = 0; i < (sizeof(reg) / sizeof(reg[0])); i++) {
        reg[i] = 0;
    }
    
    for (int i = 0; i < (sizeof(dmem) / sizeof(dmem[0])); i++) {
        dmem[i] = 0;
    }
}

void end() {
    printf("------------------------------------------------------------\n");
    printf("At the end of execution the register contents are:\n");
    
    for (int i = 0; i < (sizeof(reg) / sizeof(reg[0])); i++)
    {
        printf("register[%d] = %d\n", i, reg[i]);
    }
    
    printf("------------------------------------------------------------\n");
    printf("Data memory contents are (Only non-zero contents displayed):\n");
    
    for (int i = 0; i < (sizeof(dmem) / sizeof(dmem[0])); i++)
    {
        if (dmem [i] != 0)
        {
            printf("data memory[%d] = %d\n", i, dmem[i]);
        }
    }
    printf("------------------------------------------------------------\n");
}

void run() {
    while (!STOP) {
        //fetch
        unsigned short CIR = pmem[PC];
        ++PC;
        
        //decode
        unsigned short nibble4 = (CIR & 0xF000) >> 12;  // Get the MSB nibble
        unsigned short nibble3 = (CIR & 0x0F00) >> 8;   // Get the nibble3
        unsigned short nibble2 = (CIR & 0x00F0) >> 4;   // Get the nibble2
        unsigned short nibble1 = (CIR & 0x000F) ;       // Get the LSB nibble
        
        // execute
        execute(nibble4, nibble3, nibble2, nibble1);
    }
    // display the register and memory contents post execution
    end();
}

int main() {
    // run init
    init();
    
    // Load instructions into memory
    unsigned short program[] = {
        0b0011000000011001,
        0b0011010000011001,
        0b0011000100101000,
        0b0011010100101000,
        0b0011001000000101,
        0b0101000000000010,
        0b1000000000000011,
        0b0101000000010010,
        0b1000000100000011,
        0b1000001111111011,
        0b0001010000000001,
        0b1111000000000000,
        0b0001010100000001,
        0b1111000000000000
    };
    
    // The program memory can accept a maximum of 256 16-bit instructions
    for (int i = 0; i < (sizeof(program) / sizeof(program[0])); i++) {
        pmem[i] = program[i];
    }

    // feed the instructions to the processor
    run();
    return 0;
}



