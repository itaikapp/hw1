#include "arrays.hpp"
#include "random.hpp"

#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, size_t size){
    printf("{");
    for (size_t i = 0; i+1 < size;++i){
        printf("%d, ", arr[i]);
    }
    if(size > 0){
        printf("%d", arr[size-1]);
    }
    printf("}\n");
}

static void swap(int *arr, size_t i, size_t j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

long binary_search(int *arr, long size, int num) {
    long lo = 0;
    long hi = size;
    while (lo < hi) {
        long mid= (lo + hi) / 2;
        if (arr[mid] == num) {
            return mid;
        } else if (arr[mid] > num) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return -1;
}

int *allocate_array(size_t size) {
    return (int *)malloc(size * sizeof(int));
}

void deallocate_array(int *arr) {
    free(arr);
}

int *generate_random_array(size_t size) {
    int *arr = allocate_array(size);
    for (size_t i = 0; i < size; ++i) {
        arr[i] = rand_int();
    }
    return arr;
}

void reverse(int *arr, size_t size) {
    for (size_t i = 0, j = size - 1; i < size && i < j; ++i, --j) {
        swap(arr, i ,j);
    }
}

void shuffle(int *arr, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        size_t j = rand_interval(0, size);
        swap(arr, i, j);
    }
}
