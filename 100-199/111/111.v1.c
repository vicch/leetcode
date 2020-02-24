struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

#define MIN(a, b) (a > b ? b : a)

int minDepth(struct TreeNode* root) {
	if (!root)
		return 0;

	// If no left subtree, only check right subtree
	if (!root->left)
		return minDepth(root->right) + 1;
	
	// If no right subtree, only check left subtree
	if (!root->right)
		return minDepth(root->left) + 1;
	
	// Check both trees
	return MIN(minDepth(root->left), minDepth(root->right)) + 1;
}
