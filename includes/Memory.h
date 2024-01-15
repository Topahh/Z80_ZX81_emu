#ifndef MEMORY_H
#define MEMORY_H

#include <array>
#include <cstdint>

// Z80 does not have an internal Memory
// Using the Hunter 8k nonvolatile memory map from the ZX81 Technical Reference Manual
class Memory {
    public:
        using Byte = uint8_t;
        using Word = uint16_t;
        static constexpr int MEM_SIZE = 2048;

        // Hunter have 4 HM6116P-3 : 2048 x 8-bit static RAM chips
        static std::array<Byte, MEM_SIZE> SystemROM;   // Block 0, A13 = 0; A14 = 0
        static std::array<Byte, MEM_SIZE> SynclairSys; // Block 1, A13 = 1; A14 = 0
        static std::array<Byte, MEM_SIZE> UserRAM1;    // Block 2, A13 = 0; A14 = 1
        static std::array<Byte, MEM_SIZE> UserRAM2;    // Block 3, A13 = 1; A14 = 1

        // Block selection is done by A13 and A14
        static std::array<bool, 2> memorySelect; // A13 and A14

        Memory();
        ~Memory();
        void selectBlock(int block) const;
        void reset() const;
};

#endif // MEMORY_H