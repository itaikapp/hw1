#include "homework.hpp"
#include "io.hpp"

#include <cstdio>

void print_menu() {
    std::printf("1. print this menu.\n"
                "2. the fundamental theorem of arithmetic.\n"
                "3. power calculation.\n"
                "4. log calculation.\n"
                "5. square root calculation.\n"
                "6. reverse array.\n"
                "7. shuffle array.\n"
                "8. large integer's division check.\n"
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