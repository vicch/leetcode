/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isValidBST(struct TreeNode* root);
bool isValidBSTRecursive(struct TreeNode* root, long min, long max);

bool isValidBST(struct TreeNode* root)
{
	// It's tricky if the tree may contain boundary values of the data type.
	// Here we use boundary values of LONG because the tests only contain INT
	// values.
	return isValidBSTRecursive(root, LONG_MIN, LONG_MAX);
}

// Check if the given tree is BST by checking if its value is within the given
// range, and if its child trees are BSTs.
bool isValidBSTRecursive(struct TreeNode* root, long min, long max)
{
	if (!root) {
		return true;
	}

	// Check root node's value against the range
	return root->val > min && root->val < max
		// Recursively check child trees
		&& isValidBSTRecursive(root->left, min, root->val)
		&& isValidBSTRecursive(root->right, root->val, max);
}
