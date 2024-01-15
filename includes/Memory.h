#ifndef MEMORY_H
#define MEMORY_H

#include <array>
#include <cstdint>

class Memory {
    public:
        using Byte = uint8_t;
        using Word = uint16_t;
        static constexpr int MEM_SIZE = 2048;

        static std::array<Byte, MEM_SIZE> SystemROM;   // Block 0, A13 = 0; A14 = 0
        static std::array<Byte, MEM_SIZE> SynclairSys; // Block 1, A13 = 1; A14 = 0
        static std::array<Byte, MEM_SIZE> UserRAM1;    // Block 2, A13 = 0; A14 = 1
        static std::array<Byte, MEM_SIZE> UserRAM2;    // Block 3, A13 = 1; A14 = 1

        static std::array<bool, 2> memorySelect; // A13 and A14

        Memory();
        ~Memory();
        void selectBlock(int block);
        void reset() const;
};

#endif // MEMORY_H