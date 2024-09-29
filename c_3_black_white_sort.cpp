#include "c_3_black_white_sort.h"

#include <cstdint>
#include <cstring>

// Complexity is O(n)
void sortBlackWhite(char source[])
{
    const char white = '0';
    const char black = '1';
    uint32_t expected_white = 0;
    for (uint32_t i = 0; i < strlen(source) ; ++i)
    {
        if (source[i] != white)
            continue;

        // swap
        if (expected_white < i)
        {
            source[expected_white] = white;
            source[i] = black;
        }

        ++expected_white;
    }
}
