/*
 * kmp.cpp
 * Copyright (C) 2013 Yang Junyong <yanunon@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_next_array(char* T, int* next, int len){
	int i = 0;
	int j = -1;
	next[i] = -1;

	while(i < len - 1){
		if (j == -1 || T[i] == T[j]) {
			i++;
			j++;
			if (T[i] != T[j]) {
				next[i] = j;
			} else {
				next[i] = next[j];//???
			}
		}else {
			j = next[j];//???
		}
	}

}

int kmp_index(char* src, char* T, int start_idx){
	int t_len = strlen(T);
	int s_len = strlen(src);
	int* next = new int[t_len];
	get_next_array(T, next, t_len);
	int i = start_idx;
	int j = 0;
	while(i < s_len && j < t_len) {
		if( j == -1 || src[i] == T[j]){
			j++;
			i++;
		}else{
			j = next[j];
		}
	}

	delete[] next;
	if( j == t_len ){
		return i - j;
	}else{
		return -1;
	}

}

int main(int argc, char** argv) {
	char *src = "aabcabcebafabcabceabcaefabcacdabcab";
	char *T = "abac";
	int start_idx = 0;
	if (argc > 1) {
		T = argv[1];
	}

	if (argc > 2) {
		start_idx = atoi(argv[2]);
	}
	
	int idx = kmp_index(src, T, start_idx);
	printf("idx:%d\n", idx);
	return 0;
}

