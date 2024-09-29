#pragma once

namespace practice {

// QUESTION:
//
// 2.Implement multiply without *
// What is the complexity of the solution?
// (One of the expected solutions - bitwise multiplication)

// SOLUTION:
//
// Any integer number is a sum of pows of 2. E.g.:
// 7 = 2^0 + 2^1 + 2^2
// (7 * M) = (2^0 + 2^1 + 2^2)*M = M + (M << 1) + (M << 2)

unsigned int bitMultiply(unsigned int x, unsigned int y);

} // namespace practice
