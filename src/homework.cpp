#include "homework.hpp"
#include "io.hpp"
#include "arrays.hpp"
#include "random.hpp"

#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>

void print_menu() {
    std::printf("1. print this menu.\n"
        "2. the fundamental theorem of arithmetic.\n"
        "3. power calculation.\n"
        "4. log calculation.\n"
        "5. square root calculation.\n"
        "6. reverse array.\n"
        "7. shuffle array.\n"
        "8. large integer's division check.\n"
        "9. exit.\n"
    );
}


void prime_factorization() {
    std::printf("please enter a positive integer for prime factorization:\n");
    int num = get_int();
    if (num < 1) {
        std::printf("%d is not a positive integer\n", num);
        return;
    }

    std::printf("%d = ", num);
    if (1 == num) {
        std::printf("1");
    }
    int factor = 2;
    while(num != 1) {
        int count = 0;
        while(num % factor == 0) {
            ++count;
            num /= factor;
        }
        if (count > 0) {
            if (1 == count) {
                std::printf("%d", factor);
            } else {
                std::printf("%d^%d", factor, count);
            }
            if (num != 1) {
                std::printf(" * ");
            }
        }
        ++factor;
    }
    std::printf("\n");
}

void reverse(int *arr, std::size_t size) {
    for (std::size_t i = 0, j = size - 1; i < size && i < j; ++i, --j) {
        swap(arr, i ,j);
    }
}

void shuffle(int *arr, std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        std::size_t j = rand_interval(0, size);
        swap(arr, i, j);
    }
}

void large_integer_division_check() {
    std::printf("please enter a large positive number\n");
    std::vector<int> large_integer = get_large_integer();

    std::printf("please enter a positive divisor\n");
    int divisor = get_int();

    int remainder = 0;
    for (int digit : large_integer) {
        std::cout << digit;
        remainder = (10 * remainder + digit) % divisor;
    }

    if (0 == remainder) {
        std::printf(" divides in %d without remainder.\n", divisor);
    } else {
        std::printf(" divides in %d with a remainder %d.\n", divisor, remainder);
    }
}

double power(double base, int exponent) {
    if (0 == base && exponent <= 0) {
        return 0.0 / 0.0;
    }

    if (exponent < 0) {
        base = 1.0 / base;
        exponent = -exponent;
    }

    double res = 1;
    double acc = base;
    int count = 1;
    while (exponent > 0) {
        if (count * 2 < exponent) {
            acc *= acc;
            count *= 2;
        } else {
            res *= acc;
            exponent -= count;
            count = 1;
            acc = base;
        }
    }
    return res;
}

static double eps = 1e-6;

double square_root(double num) {
    double lo;
    double hi;
    if (num < 1.0) {
        lo = 0;
        hi = 1;
    } else {
        lo = 1;
        hi =  num;
    }

    double res = (lo + hi) / 2;
    double square = res * res;
    while (std::abs(square - num) >= eps) {
        if (square > num) {
            hi = res;
        } else {
            lo = res;
        }
        res = (lo + hi) / 2;
        square = res * res;
    }
    return res;
}

int log(double number, double base) {
    if (base < 1 || number <= 0) {
        return -1;
    }
    int res = 0;
    while (power(base, res) < number) {
        res++;
    }
    return res;
}
