#include <stdio.h>
#include <stdlib.h>
#include <cstdint>
#include <array>

#include "Memory.h"

class Memory{
    // Z80 does not have an internal Memory
    // Using the Hunter 8k nonvolatile memory map from the ZX81 Technical Reference Manual

    public:
    using Byte = uint8_t;
    using Word = uint16_t;
    static constexpr int MEM_SIZE = 2048;

    
    std::array<Memory::Byte, Memory::MEM_SIZE> Memory::SystemROM{};
    std::array<Memory::Byte, Memory::MEM_SIZE> Memory::SynclairSys{};
    std::array<Memory::Byte, Memory::MEM_SIZE> Memory::UserRAM1{};
    std::array<Memory::Byte, Memory::MEM_SIZE> Memory::UserRAM2{};

    std::array<bool, 2> memorySelect = {false, false}; // A13 and A14

    void selectBlock(int block){
        switch (block){
            case 0:
                memorySelect[0] = false;
                memorySelect[1] = false;
                break;
            case 1:
                memorySelect[0] = true;
                memorySelect[1] = false;
                break;
            case 2:
                memorySelect[0] = false;
                memorySelect[1] = true;
                break;
            case 3:
                memorySelect[0] = true;
                memorySelect[1] = true;
                break;
            default:
                memorySelect[0] = false;
                memorySelect[1] = false;
                break;
        }
    }

    void reset(){
        for (int i = 0; i < MEM_SIZE; i++){
            SystemROM[i] = 0x00;
            SynclairSys[i] = 0x00;
            UserRAM1[i] = 0x00;
            UserRAM2[i] = 0x00;
        }
    }

};


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
    void start( Memory& memory ){
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