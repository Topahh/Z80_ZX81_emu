#include <stdio.h>
#include <stdlib.h>
#include <cstdint>
#include <array>

#include "includes/Memory.h"

class CPU{

    using Byte = uint8_t;
    using Word = uint16_t;

    // 8-bit registers
    Byte I; // Interruption vector register. used by the calculator in the interrupt 2 mode
    Byte R; // Refresh register. holds no specific purpose to the OS, can be used to generate random numbers

    // 16-bits registers
    Word AF; // Accumulator and flags
    Word BC; // 16-bit counter
    Word DE; // Memory pointer
    Word HL; // Address register

    // Shadow 16-bits registers
    Word AF_; // Accumulator and flags
    Word BC_; // 16-bit counter
    Word DE_; // Memory pointer
    Word HL_; // Address register

    // Other registers
    Word SP; // Stack pointer
    Word IX; // Index register
    Word IY; // Index register
    Word PC; // Program counter

    public:
    void start( Memory const& memory ){
        AF = DE = HL = 0x0000;
        BC = 0x7FFF; // RAM starting address, ZX81 specific
        AF_ = BC_ = DE_ = HL_ = 0x0000;
        IX = IY = 0x0000;
        PC = 0x0000;
        SP = 0xFFFF;
        I = R = 0x00;
        memory.reset();
    }

};

int main()
{
    CPU cpu;
    Memory hunter;
    cpu.start( hunter );
    return 0;
}