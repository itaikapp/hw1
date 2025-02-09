#include "io.hpp"

#include <cstdio>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

int get_int() {
    std::fflush(stdout);
    int                  ret;
    [[maybe_unused]] int ignored = std::scanf("%d%*c", &ret);
    return ret;
}

double get_double() {
    std::fflush(stdout);
    double               ret;
    [[maybe_unused]] int ignored = std::scanf("%lf%*c", &ret);
    return ret;
}

std::vector<int> get_large_integer() {
    std::fflush(stdout);
    std::string num_str;
    std::getline(std::cin, num_str);
    std::vector<int> large_int;

    for (char c : num_str) {
        int ic    = (unsigned char)c;
        int digit = ic - '0';
        if (digit < 0 || digit > 9) {
            std::ostringstream out;
            out << "invalid number: " << num_str << "must be a non negative integer";
            throw std::invalid_argument(out.str());
        }
        large_int.push_back(digit);
    }
    return large_int;
}
