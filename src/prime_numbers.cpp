#include "prime_numbers.hpp"

bool is_prime(int num){
    if(0 == num || 1==num ){
        return false;
    }
    for(int i = 2; i*i <= num; ++i) {
        if(num % i == 0){
            return false;
        }
    }
    return true;
}
