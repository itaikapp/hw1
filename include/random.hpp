#pragma once

#include <cstddef>
#include <limits>

int rand_int(int min = std::numeric_limits<int>::min(), int max = std::numeric_limits<int>::max());
std::size_t rand_interval(std::size_t lo, std::size_t hi);
