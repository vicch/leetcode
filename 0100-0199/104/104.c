/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(a, b) ((a > b) ? a : b)

int maxDepth(struct TreeNode* root) {
	if (!root) {
		return 0;
	}

	int l = maxDepth(root->left);
	int r = maxDepth(root->right);

	return MAX(l, r) + 1;
}
