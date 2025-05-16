#include "arrays.hpp"
#include "homework.hpp"
#include "io.hpp"

#include <cstdio>

int main() {
    print_menu();

    for (;;) {
        std::printf("\nWhat would you like me to do?\n");
        int n = get_int();

        switch (n) {
        case 1:
            print_menu();
            break;

        case 2:
            factorization();
            break;

        case 3:
            power_calculation();
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:

            break;

        case 7:
            break;

        case 8:
            break;

        case 9:
            std::printf("bye\n");
            return 0;

        default:
            std::printf("%d is an invalid selection, please choose a number between 1 to 9\n", n);
        }
    }
}
