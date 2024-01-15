
#include <array>
#include "../includes/Memory.h"

std::array<Memory::Byte, Memory::MEM_SIZE> Memory::SystemROM{};
std::array<Memory::Byte, Memory::MEM_SIZE> Memory::SynclairSys{};
std::array<Memory::Byte, Memory::MEM_SIZE> Memory::UserRAM1{};
std::array<Memory::Byte, Memory::MEM_SIZE> Memory::UserRAM2{};


std::array<bool, 2> Memory::memorySelect = {false, false}; // A13 and A14

// Constructor
Memory::Memory(){reset();}
// Destructor
Memory::~Memory(){reset();}

// region[rgba(80, 200, 150, 0.05)]

// Methods
// Select the memory block to use
void Memory::selectBlock(int block) const{
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

// Reset the memory
void Memory::reset() const{
    for (int i = 0; i < MEM_SIZE; i++){
        SystemROM[i] = 0x00;
        SynclairSys[i] = 0x00;
        UserRAM1[i] = 0x00;
        UserRAM2[i] = 0x00;
    }
}
// endregion