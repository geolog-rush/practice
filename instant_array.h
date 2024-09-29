#include <array>
#include <barrier>
#include <functional>
#include <thread>

namespace practice {

// QUESTION:
//
// 3.	You have an array of numbers (or objects). You have to change all
// numbers on array, but difficulty should be less than О(1) (e.g
// [1,1,1,1,1,1,1] switch to [2,2,2,2,2,2,2]). You shouldn't use loops,
// conditions, etc
//
// also:
// 5.	Set the array with one value in O(C) time.

// SOLUTION:
//
// I have only one idea how this can be achived in terms of programming
// language, without any special hardware support: use separate thread for each
// array element.

template <typename ElemType, std::size_t arraySize>
class InstantArray {
   public:
    using ArrayType = std::array<ElemType, arraySize>;
    static constexpr std::size_t maxWorkThreads{1024}; // ...yes
    static_assert(arraySize < maxWorkThreads, "Input array is too big.");

   private:
    static constexpr std::size_t callerThreads{1};

   public:
    InstantArray(ArrayType&& sourceArray)
        : sourceArray_{std::move(sourceArray)},
          valueReady_(arraySize + callerThreads),
          allSet_(arraySize + callerThreads) {
        workers_.reserve(arraySize);
        for (auto& elem : sourceArray_)
            workers_.emplace_back(&InstantArray::setValueWorker, this,
                                  std::ref(elem));
    }
    ~InstantArray() {
        {
            stop_ = true;
            valueReady_.arrive_and_wait();
        }
    }

    // For testing
    const ArrayType& getSource() const { return sourceArray_; }

    // All changing value work starts here and finishes here,
    // so after this call the source array is already changed.
    void setValue(const ElemType& newValue) {
        newValue_ = newValue;
        valueReady_.arrive_and_wait();
        allSet_.arrive_and_wait();
    }

   private:
    const ElemType& getValue() const { return newValue_; }
    bool getStop() const { return stop_; }
    void setValueWorker(ElemType& source) {
        while (true) {
            valueReady_.arrive_and_wait();

            if (getStop()) return;
            source = getValue();

            allSet_.arrive_and_wait();
        }
    }

    ElemType newValue_{};
    ArrayType sourceArray_;

    // Syncs/notifies the new value can be set
    std::barrier<> valueReady_;
    // Syns/notifies the workers are ready
    std::barrier<> allSet_;
    std::vector<std::jthread> workers_;
    bool stop_{};
};

}  // namespace practice
