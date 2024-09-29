#include <concepts>
#include <cstdint>
#include <iostream>
#include <string>

// QUESTION:
//
// 8.
// A. Which X number makes the below logical condition true, while X>0?
// [(X & (X-1)) == 0] answer: X is power of 2 number [X = 2^Y, while Y>=0]
// B. write a simple code that checks if uint8 X is power of 2 without using the
// trick from section a.
// C. use the code from section B + minimal code to check
// if uint32 X is power of 2.
// D. how can you check if uint8 X is power of 2 with
// complexity O (0)? You can use additional HW/Memory etc.

namespace {

template <typename T>
    requires std::same_as<T, std::uint8_t>  //
             || std::same_as<T, std::uint32_t>
bool isPow_shift(T value) {
    do {
        if ((value & 1) && (value >> 1)) return false;
    } while (value >>= 1);

    return true;
}

bool isPow_dumb(std::uint8_t value) {
    return !(value ^ 0x01)      //
           || !(value ^ 0x02)   //
           || !(value ^ 0x04)   //
           || !(value ^ 0x08)   //
           || !(value ^ 0x10)   //
           || !(value ^ 0x20)   //
           || !(value ^ 0x40)   //
           || !(value ^ 0x80);  //
}

[[maybe_unused]]
bool isPow_dumb(std::uint32_t value) {
    return !(value ^ 0x00000001) || !(value ^ 0x00000002) ||
           !(value ^ 0x00000004) || !(value ^ 0x00000008) ||
           !(value ^ 0x00000010) || !(value ^ 0x00000020) ||
           !(value ^ 0x00000040) || !(value ^ 0x00000080) ||
           !(value ^ 0x00000100) || !(value ^ 0x00000200) ||
           !(value ^ 0x00000400) || !(value ^ 0x00000800) ||
           !(value ^ 0x00001000) || !(value ^ 0x00002000) ||
           !(value ^ 0x00004000) || !(value ^ 0x00008000) ||
           !(value ^ 0x00010000) || !(value ^ 0x00020000) ||
           !(value ^ 0x00040000) || !(value ^ 0x00080000) ||
           !(value ^ 0x00100000) || !(value ^ 0x00200000) ||
           !(value ^ 0x00400000) || !(value ^ 0x00800000) ||
           !(value ^ 0x01000000) || !(value ^ 0x02000000) ||
           !(value ^ 0x04000000) || !(value ^ 0x08000000) ||
           !(value ^ 0x10000000) || !(value ^ 0x20000000) ||
           !(value ^ 0x40000000) || !(value ^ 0x80000000);
}

}  // namespace

int main(int argc, char** args) {
    if (argc != 2) return 1;

    const std::uint8_t value{static_cast<std::uint8_t>(std::stoi(args[1]))};
    std::cout << "Dumb says : " << isPow_dumb(value) << '\n';
    std::cout << "Shift says: " << isPow_shift(value) << '\n';

    return 0;
}
