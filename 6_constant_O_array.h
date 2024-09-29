#include <cassert>
#include <concepts>
#include <cstddef>
#include <limits>

// QUESTION:
//
// 6.Have a table something like int arr[N].
// Need to implement methods get, set, set_all with constant complexity.

// SOLUTION:
//
// Count each call to set() or set_all() to keep track
// which one was older to decide which value to return: common or individual.
// When the counter reaches its max() value: normalize() counts array, O(n)

namespace practice {

template <std::size_t array_size = 10, std::integral counter_type = std::size_t>
class Table {
   private:
    int array_[array_size]{};
    int commonValue_{};

    static constexpr counter_type startCount_{1};
    counter_type counter_{startCount_};
    counter_type counts_[array_size]{};
    counter_type commonValueCount_{startCount_};

   public:
    void set(std::size_t idx, int value) {
        assert(idx < array_size);

        array_[idx] = value;
        counts_[idx] = count();
    }
    constexpr int get(std::size_t idx) const {
        assert(idx < array_size);

        return counts_[idx] < commonValueCount_ ? commonValue_ : array_[idx];
    }
    void set_all(int value) {
        commonValueCount_ = count();
        commonValue_ = value;
    }

   private:
    counter_type count() {
        if (counter_ == std::numeric_limits<counter_type>::max()) normalize();

        return ++counter_;
    }

    // Reset counts of the values which are older than common value counter;
    // recount other counts starting from scratch.
    void normalize() {
        if (!commonValueCount_) return;

        counter_type localCount{startCount_};
        for (std::size_t i = 0; i < array_size; ++i)
            counts_[i] = counts_[i] < commonValueCount_ ? 0 : ++localCount;

        commonValueCount_ = counter_ = startCount_;
    }
};
}  // namespace practice

