// Z80 does not have an internal Memory
// Using the Hunter 8k nonvolatile memory map from the ZX81 Technical Reference Manual
#include <array>
#include "../includes/Memory.h"


// Hunter have 4 HM6116P-3 : 2048 x 8-bit static RAM chips
std::array<Memory::Byte, Memory::MEM_SIZE> Memory::SystemROM{};     // Block 0
std::array<Memory::Byte, Memory::MEM_SIZE> Memory::SynclairSys{};   // Block 1
std::array<Memory::Byte, Memory::MEM_SIZE> Memory::UserRAM1{};      // Block 2
std::array<Memory::Byte, Memory::MEM_SIZE> Memory::UserRAM2{};      // Block 3

// Block selection is done by A13 and A14
std::array<bool, 2> Memory::memorySelect = {false, false}; // A13 and A14

// Constructor
Memory::Memory(){reset();}
// Destructor
Memory::~Memory(){reset();}

// region[rgba(80, 200, 150, 0.05)]
// Methods
void Memory::selectBlock(int block){
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

void Memory::reset() const{
    for (int i = 0; i < MEM_SIZE; i++){
        SystemROM[i] = 0x00;
        SynclairSys[i] = 0x00;
        UserRAM1[i] = 0x00;
        UserRAM2[i] = 0x00;
    }
}
// endregion