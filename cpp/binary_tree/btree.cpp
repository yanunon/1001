/*
 * btree.cpp
 * Copyright (C) 2013 Yang Junyong <yanunon@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <stack>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct _TreeNode{
	struct _TreeNode* left;
	struct _TreeNode* right;
	int value;
}TreeNode;

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

TreeNode* search_tree(TreeNode* root, int value){
	if(root == NULL){
		return NULL;
	}
	if(root->value == value){
		return root;
	}else if(root->value > value){
		return search_tree(root->left, value);
	}else{
		return search_tree(root->right, value);
	}
}

void insert_to_tree(TreeNode* root, int value){
	if(root->value == value){
		return;
	}else if(root->value < value) {
		if (root->right) {
			insert_to_tree(root->right, value);
		}else {
			root->right = new TreeNode;
			root->right->right = NULL;
			root->right->left = NULL;
			root->right->value = value;
		}
	}else {
		if(root->left) {
			insert_to_tree(root->left, value);
		}else{
			root->left = new TreeNode;
			root->left->right = NULL;
			root->left->left = NULL;
			root->left->value = value;
		}
	}
}

void traversal_tree(TreeNode* root){
	std::stack<TreeNode*> st;
	while(root != NULL || !st.empty()){
		if(root != NULL){
			st.push(root);
			printf("%3d ", root->value);
			root = root->left;
		}else{
			root = st.top();
			st.pop();
			root = root->right;
		}
	}
	printf("\n");
}

TreeNode* build_search_tree(int* array, int n) {
	TreeNode* root = new TreeNode;
	root->left = NULL;
	root->right = NULL;
	root->value = array[0];

	for(int i = 1; i < n; i++){
		insert_to_tree(root, array[i]);
	}
	return root;
}

int main(int argc, char** argv){
	int n = 10;
	int max = 100;
	int* array = new int[n];
	generate_random_array(array, max, n);
	print_array(array, n, NULL);
	TreeNode* tree = build_search_tree(array, n);
	traversal_tree(tree);
}


