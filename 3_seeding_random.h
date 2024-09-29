#include <vector>

// QUESTION:
//
// 3.Print all numbers from 1..N in random order so that each number appears
// exactly once, using function randomize(x) - that generates random number in
// range 1..x
// a. You need to describe the most effective algorithm.

// SOLUTION:
//
// Result of a call to randomize(x) is used to split the range 1..N into left and
// right sub ranges: 1..R and R..N.
// Recursive calls to randomize(R-1) for left and randomize(N) for right sub ranges
// generate unique numbers and only once for each number.
// So complexity is O(n).

namespace practice {

using ResultType = std::vector<unsigned int>;
ResultType generateInRange(unsigned int maxNumber);

}  // namespace practice
