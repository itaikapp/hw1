#include "arrays.hpp"
#include "random.hpp"

#include <cstdio>
#include <cstdlib>

void print_array(const int *arr, std::size_t size){
    std::printf("{");
    for (std::size_t i = 0; i+1 < size;++i){
        std::printf("%d, ", arr[i]);
    }
    if(size > 0){
        std::printf("%d", arr[size-1]);
    }
    std::printf("}\n");
}

void print_array(int *arr, std::size_t size){
    print_array(const_cast<const int *>(arr), size);
}

long search(int *arr, long size, int num) {
    for (long i = 0; i < size; ++i) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1;
}

void swap(int *arr, std::size_t i, std::size_t j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int *allocate_array(std::size_t size) {
    return static_cast<int *>(std::malloc(size * sizeof(int)));
}

void deallocate_array(int *arr) {
    std::free(arr);
}

int *generate_random_array(std::size_t size, int min, int max) {
    int *arr = allocate_array(size);
    for (std::size_t i = 0; i < size; ++i) {
        arr[i] = rand_int(min, max);
    }
    return arr;
}