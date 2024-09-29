#pragma once

#include <numeric>
#include <vector>
#include <type_traits>

// QUESTION:
//
// 5. Have an array of size N-1 with different numbers in range 1..N in random order.
// (So one number from the range 1..N is missed)
// How can we find what number is missing?
// What if two numbers are missed?

// SOLUTION:
//
// One missing number from the known sequence is:
// missing_number = sum(known_sequence) - sum(actual_sequence)

namespace practice {

template <
    typename ArrayType,  //
    typename ValueType = std::remove_cvref_t<typename ArrayType::value_type>>
ValueType findOneMissingNumber(const ArrayType& input) {
    const ValueType expectedSize{static_cast<ValueType>(input.size() + 1)};
    const ValueType expectedSum{expectedSize * (ValueType{1} + expectedSize) /
                                ValueType{2}};

    const ValueType actualSum{std::accumulate(input.begin(),  //
                                              input.end(), ValueType{0})};
    return expectedSum - actualSum;
}

template <
    typename ArrayType,  //
    typename ValueType = std::remove_cvref_t<typename ArrayType::value_type>>
std::vector<ValueType> findMoreThanOneMissingNumber(const ArrayType&) {
    static_assert(true,
                  "There are several options which are too simple or I'm too "
                  "lazy to implement it now:\n"
                  "1) sort input array\n"
                  "2) put input values to set/unordered_set\n"
                  "3) search for non-complete pairs 1:(N-0), 2:(N-1), ...\n"
                  "4) some other tricky math");
    return {};
}

}  // namespace practice
