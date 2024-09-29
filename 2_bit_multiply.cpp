#include "2_bit_multiply.h"

namespace practice {

unsigned int bitMultiply(unsigned int x, unsigned int y) {
    if (x == 1) return y;
    if (y == 1) return x;
    if (!x || !y) return 0;

    unsigned int powNumber{0};
    unsigned int result{x & 1 ? y : 0};
    while (x >>= 1) {
        ++powNumber;
        if (x & 1) result += (y << powNumber);
    }
    return result;
}
}  // namespace practice
