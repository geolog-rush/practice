#include "3_seeding_random.h"

#include <random>

namespace practice {

namespace {

unsigned int randomize(unsigned int maxNumber) {
    static std::random_device device;
    static std::mt19937 engine{device()};
    std::uniform_int_distribution<unsigned int> distr{1, maxNumber};
    return distr(engine);
}


void doGenerate(unsigned int minNumber, unsigned int maxNumber,
                ResultType& result) {
    if (minNumber == maxNumber) {
        result.push_back(minNumber);
        return;
    }

    unsigned int currentValue{randomize(maxNumber - minNumber + 1)};
    currentValue += minNumber - 1;
    result.push_back(currentValue);

    // go left
    if (currentValue > minNumber)
        doGenerate(minNumber, currentValue - 1, result);

    // go right
    if (maxNumber > currentValue)
        doGenerate(currentValue + 1, maxNumber, result);
}

}  // namespace

ResultType generateInRange(unsigned int maxNumber) {
    if (maxNumber == 0)
        return {};

    if (maxNumber == 1)
        return {1};

    std::vector<unsigned int> result;
    result.reserve(maxNumber);

    const unsigned int minNumber{1};
    doGenerate(minNumber, maxNumber, result);

    return result;
}

}  // namespace practice
