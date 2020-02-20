struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define MIN(a, b) (a > b ? b : a)

int minDepth(struct TreeNode* root) {
	if (!root)
		return 0;

	// If no left child tree, only check right child tree
	if (!root->left)
		return minDepth(root->right) + 1;
	
	// If no right child tree, only check left child tree
	if (!root->right)
		return minDepth(root->left) + 1;
	
	// Check both trees
	return MIN(minDepth(root->left), minDepth(root->right)) + 1;
}
