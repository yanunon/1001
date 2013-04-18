/*
 * sort.cpp
 * Copyright (C) 2013 Yang Junyong <yanunon@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void generate_random_array(int* array, int max, int n){
	srand(time(0));
	int* p = array;
	for(int i = 0; i < n; i++){
		*p++ = rand() % max;
	}
}

void print_array(int* array, int n, char* s){
	if (s != NULL){
		printf("%s:\n", s);
	}
	for(int i = 0; i < n; i++) {
		printf("%3d ", *array++);
		if (i % 10 == 9) {
			printf("\n");
		}
	}
	printf("\n");
}

void swap_array_element(int* array, int i, int j) {
	if (i == j) {
		return;
	}
	array[i] = array[i]^array[j];
	array[j] = array[i]^array[j];
	array[i] = array[i]^array[j];
}

void bubble_sort(int* array, int n){
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++) {
			if(array[i] > array[j]){
				swap_array_element(array, i, j);
			}
		}
	}
}


void quick_sort_sub(int* array, int left, int right){
	if(left >= right) {
		return;
	}
	int sleft = left;
	int sright = right;
	while(left < right) {
		if(array[left] < array[left+1]){
			swap_array_element(array, left+1, right);
			right--;
		}else{
			swap_array_element(array, left, left+1);
			left++;
		}
	}
	quick_sort_sub(array, sleft, left-1);
	quick_sort_sub(array, left+1, sright);
}

void quick_sort(int* array, int n){
	quick_sort_sub(array, 0, n - 1);
}

void insert_sort(int* array, int n){
	for(int i = 1; i < n; i++) {
		for(int j = i - 1; j > -1; j--) {
			if(array[j] > array[j+1]){
				swap_array_element(array, j+1, j);
			} else {
				break;
			}
		}
	}
}

void select_sort(int* array, int n) {
	int min;
	int min_idx;
	for(int i = 0; i < n; i++){
		min = array[i];
		min_idx = i;
		for(int j = i+1; j < n; j++){
			if(array[j] < min){
				min = array[j];
				min_idx = j;
			}
		}
		swap_array_element(array, i, min_idx);
	}
}

void heap_sift_down(int* array, int idx, int len){
	int son_idx = 2*idx + 1;
	while(son_idx < len) {
		if (son_idx + 1 < len && array[son_idx+1] > array[son_idx]){
			son_idx++;
		}
		if (array[idx] < array[son_idx]){
			swap_array_element(array, idx, son_idx);
			idx = son_idx;
			son_idx = 2*idx + 1;
		}else {
			break;
		}
	}
}

void heap_sort(int* array, int n) {
	for(int i = n/2; i > -1; i--) {
		heap_sift_down(array, i, n);
	}

	for(int i = 0; i < n - 1; i++) {
		swap_array_element(array, 0, n - 1 - i);

		heap_sift_down(array, 0, n - 1 - i);
	}
}

int main(int argc, char** argv){
	int max = 100;
	int n = 20;
	if(argc > 1) {
		max = atoi(argv[1]);
	}

	if(argc > 2) {
		n = atoi(argv[2]);
	}

	int *array = new int[n];
	generate_random_array(array, max, n);
	print_array(array, n, "random");

	int *tmp_array = new int[n];
	memcpy(tmp_array, array, sizeof(int)*n);
	bubble_sort(tmp_array, n);
	print_array(tmp_array, n, "bubble");

	memcpy(tmp_array, array, sizeof(int)*n);
	quick_sort(tmp_array, n);
	print_array(tmp_array, n, "quick");

	memcpy(tmp_array, array, sizeof(int)*n);
	insert_sort(tmp_array, n);
	print_array(tmp_array, n, "insert");

	memcpy(tmp_array, array, sizeof(int)*n);
	select_sort(tmp_array, n);
	print_array(tmp_array, n, "select");

	memcpy(tmp_array, array, sizeof(int)*n);
	heap_sort(tmp_array, n);
	print_array(tmp_array, n, "heap");

	delete[] tmp_array;
	delete[] array;
	return 0;
}
