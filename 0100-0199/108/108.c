#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

struct TreeNode* sortedArrayToBST(int* nums, int numsSize);
struct TreeNode* sortedArrayRangeToBST(int* nums, int from, int to);

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
	return sortedArrayRangeToBST(nums, 0, numsSize - 1);
}

// Create a BST using numbers within the given range (defined by 2 indexes) of the given list of
// numbers
struct TreeNode* sortedArrayRangeToBST(int* nums, int from, int to) {
	if (from > to)
		return NULL;
	
	// Get the index to the middle element, because division result is truncated to int, use +1
	// to make the left half bigger than the right half, if the length of the range is an even
	// number.
	int mid = (from + to + 1) / 2;
	
	// Create the root node and left and right subtrees recursively
	struct TreeNode* root = malloc(sizeof(struct TreeNode));
	root->val = nums[mid];
	root->left = sortedArrayRangeToBST(nums, from, mid - 1);
	root->right = sortedArrayRangeToBST(nums, mid + 1, to);
	
	return root;
}
