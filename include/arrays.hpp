#pragma once

#include <stddef.h>

void print_array(int *arr, size_t size);
long search(int *arr, long size, int num);
long binary_search(int *arr, long size, int num);
float sqrt(float num);
int *allocate_array(size_t size);
void deallocate_array(int *arr);
void reverse(int *arr, size_t size);
void shuffle(int *arr, size_t size);
int *generate_random_array(size_t size);
