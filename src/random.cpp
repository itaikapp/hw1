#include "random.hpp"

#include <random>
#include <limits>

int rand_int() {
    static std::random_device rd;  // a seed source for the random number engine
    static std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    static std::uniform_int_distribution<int> distribution(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

    // Use distribution to transform the random unsigned int
    // generated by gen into an int in [min, max]
    return distribution(rd);
}

size_t rand_interval(size_t lo, size_t hi) {
    static std::random_device rd;  // a seed source for the random number engine
    static std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    static std::uniform_int_distribution<int> distribution(lo, hi-1);

    // Use distribution to transform the random unsigned int
    // generated by gen into an int in [min, max]
    return distribution(rd);
}
