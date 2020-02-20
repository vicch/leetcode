#include <stdio.h>
#include <math.h>

#define MAX(a, b) ((a > b) ? a : b)

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

bool isBalanced(struct TreeNode* root);
int getHeight(struct TreeNode* root);

bool isBalanced(struct TreeNode* root) {
	return getHeight(root) != -1;
}

// Get height of given tree, return -1 if tree is height-unbalanced
int getHeight(struct TreeNode* root) {
	if (!root)
		return 0;
	
	int ld = getHeight(root->left);
	// If left child tree is unbalanced, this tree is unbalanced
	if (ld == -1)
		return -1;
	
	int rd = getHeight(root->right);
	// If right child tree is unbalanced, this tree is unbalanced
	if (rd == -1)
		return -1;
	
	// If height diff is less than 1, return current tree's height
	if (abs(ld - rd) <= 1)
		return MAX(ld, rd) + 1;
	// If not, current tree is unbalanced
	else
		return -1;
}
