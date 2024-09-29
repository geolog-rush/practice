#include <string_view>

// QUESTION:
//
// 10. Write a function that returns true if the given string is a Palindrome

namespace practice {

inline bool isPalindrome(std::string_view source) {
    std::size_t middle{source.size() / 2};
    for (std::size_t i{0}; i < middle; ++i) {
        if (source[i] != source[(source.size() - i - 1)]) return false;
    }
    return true;
}

}  // namespace practice
