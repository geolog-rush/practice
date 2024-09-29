#include <cassert>
#include <vector>

namespace practice {

// QUESTION:
//
// 4.	write a function that returns the Fibonacci series

template <typename FuncType>
concept SinkFunc = requires(FuncType f) { f(std::size_t{}, std::size_t{}); };

template <SinkFunc FuncType>
void getFibs(std::size_t toNumber, FuncType sink) {
    std::size_t first{0};
    std::size_t second{1};
    sink(1, second);
    for (std::size_t i = 2; i <= toNumber; ++i) {
        std::swap(first, second);
        second += first;
        sink(i, second);
    }
}

inline std::vector<std::size_t> getFibSeries(std::size_t number) {
    std::vector<std::size_t> result;
    getFibs(number, [&result](std::size_t, std::size_t value) {
        result.push_back(value);
    });
    return result;
}

}  // namespace practice
