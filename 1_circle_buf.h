#pragma once

// QUESTION:
//
// 1.Implement queue
// a.	 for data we have e.g int arr[1000]. Implement methods push/pop
// b.	(expect to see cycled buffer)

// SOLUTION:
// Circled buffer. Not so cozy as boost but works.

#include <cstddef>

template <typename T = int, std::size_t max_size = 1000>
class CircleBuf {
   private:
    T buf[max_size]{};
    std::size_t position_{};
    std::size_t size_{};

   public:
    void push(T value) {
        ++position_;
        if (position_ == max_size)
            position_ = 0;

        if (size_ != max_size)
            ++size_;

        buf[position_] = value;
    }

    T pop() {
        if (empty()) return {};

        T result{buf[position_]};
        if (position_ == 0)
            position_ = max_size - 1;
        else
            --position_;

        --size_;

        return result;
    }

    bool empty() const { return size_ == 0; }
    std::size_t size() const { return size_; }
};

