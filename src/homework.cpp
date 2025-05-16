#include "homework.hpp"
#include "io.hpp"

#include <cstdio>
#include <cstddef>

void print_menu() {
    std::printf("1. print this menu.\n"
                "2. the fundamental theorem of arithmetic.\n"
                "3. power calculation.\n"
                "4. log calculation.\n"
                "5. square root calculation.\n"
                "6. reverse array.\n"
                "7. shuffle array.\n"
                "8. large integer's deviation check.\n"
                "9. exit.\n");
}

void factorization() {
    std::printf("please enter a positive integer for prime factorization:\n");
    int n = get_int();
    if (n > 0) {
        std::printf("%d = ", n);
        if (1 == n) {
            std::printf("%d", n);
        }
        for (int i = 2; i <= n; ++i) {
            int counter = 0;
            while (n % i == 0) {
                ++counter;
                n = n / i;
            }
            if (counter > 1) {
                std::printf("%d^%d", i, counter);
            } else if (1 == counter) {
                std::printf("%d", i);
            }
            if (n > 1 && counter > 0) {
                std::printf(" * ");
            }
        }
    } else {
        std::printf("%d is not a positive integer\n", n);
    }
    std::printf("\n");
}


static double power(double base, int exp){
    if (0 == base && 0 == exp) {
        return 0.0/0.0;
    }

    if (exp < 0) {
        exp = -exp;
        base = 1 / base;
    }

    double res = 1;
    while (exp > 0) {
        res = res * res;
        if (exp % 2 == 1) {
            res = res * base;
        }
        exp = exp / 2;
    }
    return res;
}


void power_calculation() {
    std::printf("please enter a base (decimal): ");
    double base = get_double();
    std::printf("please enter an exponent (integer): ");
    int exp = get_int();
    double res = power(base, exp);
    std::printf("%lf ^ %d = %lf\n", base, exp, res);
}

static int log_calc(double base, double n) {
    if (0 == base && 0 == exp) {
        return 0.0/0.0;
    }

    if (exp < 0) {
        exp = -exp;
        base = 1 / base;
    }

    double res = 1;
    while (exp > 0) {
        res = res * res;
        if (exp % 2 == 1) {
            res = res * base;
        }
        exp = exp / 2;
    }
    return res;
}

void log_calculation() {
    std::printf("please enter a base (decimal): ");
    double base = get_double();
    std::printf("please enter a number (decimal): ");
    double n = get_double();
    int res = log_calc(base, n);
    std::printf("log(%lf, %lf) = %d\n", base, n, res);
}

static int large_number_division_calc(const std::vector<int> &large_int, int divisor) {
    int reminder = 0;
    for(std::size_t i = 0; i < large_int.size(); i++) {
        reminder = reminder * 10;
        reminder += large_int[i];
        reminder %= divisor;
    }
    return reminder;
}

static int large_number_division_calc2(const std::vector<int> &large_int, int divisor) {
    int reminder = 0;
    for(int n : large_int) {
        reminder = reminder * 10;
        reminder += n;
        reminder %= divisor;
    }
    return reminder;
}

void large_number_division_check() {
    std::printf("please enter a large positive number (integer) as a divided: ");
    std::vector<int> large_int = get_large_integer();
    std::printf("please enter a positive number (decimal) as a divisor: ");
    int divisor = get_int();
    int res = large_number_division_calc(large_int, divisor);
    // std::printf("log(%lf, %lf) = %d\n", base, n, res);
}

