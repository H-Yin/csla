/*
112. Path Sum

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,

		5
	   / \
	  4   8
	 /   / \
	11  13  4
    / \      \
   7   2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// #define A112
#ifdef A112


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool hasPathSum(struct TreeNode* root, int sum) {
	if (root == NULL){
		return false;
	}
	if (root->left == NULL && root->right == NULL && root->val == sum){
		return true;
	}
	return  hasPathSum(root->left, sum - (root->val)) || hasPathSum(root->right, sum - (root->val));
}

int main(){
	return 0;
}

#endif

