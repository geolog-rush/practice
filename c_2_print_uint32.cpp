#include <climits>
#include <cstdint>
#include <cstdlib>
#include <cstdio>

// QUESTION:
//
// write a function which will print the number (uint32_t) in binary format.

// SOLUTION:
//
// prints e.g. 45 as ' 00000000 00000000 00000000 00101101'
void printNumber(uint32_t value)
{
    printf("Source value: %d\n", value);
    const uint32_t bit_number = sizeof(uint32_t) * CHAR_BIT;
    const uint32_t mask = 1 << (bit_number - 1);
    for (unsigned int i = 0; i < bit_number; ++i)
    {
        // delimiter, nice
        if (!(i % 8)) putc(' ', stdout);

        char bit = '0';
        if (value & mask) bit = '1';
        putc(bit, stdout);

        value <<= 1;
    }
    putc('\n', stdout);
}

int main(int argc, char** args) {
    if (argc != 2) return 1;

    printNumber(atoi(args[1]));
    return 0;
}
