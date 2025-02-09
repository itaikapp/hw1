#include "homework.hpp"
#include "io.hpp"
#include "arrays.hpp"

#include <cstdio>

int main() {
    print_menu();
    for(;;) {
        std::printf("\nWhat would you like me to do?\n");
        int selector = get_int();
        switch (selector)
        {
        case 1:
            print_menu();
            break;

        case 2:
            prime_factorization();
            break;

        case 3: {
            std::printf("please enter a base (decimal): ");
            double base = get_double();
            std::printf("please enter an exponent (integer): ");
            int exponent = get_int();
            std::printf("%lf^%d = %lf\n", base, exponent, power(base, exponent));
        }
            break;

        case 4: {
            std::printf("please enter a number (decimal): ");
            double number = get_double();
            std::printf("please enter a base (decimal): ");
            double base = get_double();
            std::printf("log(%lf, %lf) = %d\n", number, base, log(number, base));
        }
            break;

        case 5: {
            std::printf("please enter a non negative number (decimal): ");
            double number = get_double();
            if (number < 0) {
                std::printf("number (%lf) must be non negative\n", number);
            } else {
                std::printf("square_root(%lf) = %lf\n", number, square_root(number));
            }
        }
            break;

        case 6: {
            std::printf("please enter an array's size (non negative integer): ");
            std::size_t size = get_int();
            int *arr = generate_random_array(size);
            std::printf("\noriginal array: ");
            print_array(arr, size);
            reverse(arr, size);
            std::printf("\nreversed array: ");
            print_array(arr, size);
            deallocate_array(arr);
        }
            break;

        case 7: {
            std::printf("please enter an array's size (non negative integer): ");
            std::size_t size = get_int();
            int *arr = generate_random_array(size);
            std::printf("original array: ");
            print_array(arr, size);
            shuffle(arr, size);
            std::printf("\nshuffled array: ");
            print_array(arr, size);
            deallocate_array(arr);
        }
            break;

        case 8:
            large_integer_division_check();
            break;

        case 9:
            std::printf("bye\n");
            return 0;

        default:
            std::printf("%d is an invalid selection, please choose a number between 1 to 9\n", selector);
        }
    }
}
