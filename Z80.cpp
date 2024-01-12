#include <stdio.h>
#include <stdlib.h>

class CPU{

    using Byte = unsigned char;
    using Word = unsigned short;

    // 8-bit registers
    Word A; // Accumulator
    Word B; // 8-bit counter
    Word C; // used when you want to interface with hardware ports.
    Word D; 
    Word E; 
    Word F; // Flags
    Word H;
    Word L;
    Word I; // Interruption vector register. used by the calculator in the interrupt 2 mode
    Word R; // Refresh register. holds no specific purpose to the OS, can be used to generate random numbers
    Word IXH; // Higher (first) byte of the IX register
    Word IXL; // Lower (second) byte of the IX register
    Word IYH; // Higher byte of the IY register
    Word IYL; // The lower byte of the IX register

    // 16-bit registers
    Word AF; // Accumulator and flags
    Word BC; // 16-bit counter
    Word DE; // Memory pointer
    Word HL; // 16-bit register
    Word PC; // Program counter
    Word SP; // Stack pointer
    Word IX; // Index register
    Word IY; // Index register

};

int main()
{
    return 0;
}