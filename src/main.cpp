#include "io.hpp"
#include "arrays.hpp"

#include <stdio.h>
#include <memory>

void print_menu(){}
void prime_factorization();


int main() {

    int *arr = generate_random_array(10);
    print_array(arr, 10);
    reverse(arr, 10);
    print_array(arr, 10);

    deallocate_array(arr);

    print_menu();
    for(;;) {
        printf("What would you like me to do?\n");
        int selector = get_int();
        switch (selector)
        {
        case 1:
            print_menu();
            break;

        case 2:
            prime_factorization();
            break;

        case 3:
            // binary search
            break;

        case 4:
            // sqrt
            break;

        case 5:
            // reverse array
            break;

        case 6:
            // shuffle array
            break;

        case 7:
            // power calculation
            break;

        case 8:
            // log calculation
            break;

        case 9:
            // knn
            break;

        case 10:
            // division in num
            break;

        case 11:
            printf("bye\n");
            return 0;

        default:
            printf("%d is an invalid selection, please choose a number between 1 and 11\n", selector);
        }
    }
}


void prime_factorization() {
    printf("please enter a positive number for prime factorization:\n");
    int num = get_int();
    if (num < 1) {
        printf("%d is not a positive number\n", num);
    }

    printf("%d = ", num);
    if (1 == num) {
        printf("1");
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
                printf("%d", factor);
            } else {
                printf("%d^%d", factor, count);
            }
            if (num != 1) {
                printf(" * ");
            }
        }
        ++factor;
    }
    printf("\n");
}