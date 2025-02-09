#pragma once

#include <cstddef>

void print_array(int *arr, std::size_t size);
void print_array(const int *arr, std::size_t size);
long search(int *arr, long size, int num);
int *allocate_array(std::size_t size);
void deallocate_array(int *arr);
void swap(int *arr, std::size_t i, std::size_t j);
int *generate_random_array(std::size_t size, int min = -100, int max = 100);
