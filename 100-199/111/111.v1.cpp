#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root)
			return 0;
		
		// If no left subtree, only check right subtree
		if (!root->left)
			return minDepth(root->right) + 1;
		
		// If no right subtree, only check left subtree
		if (!root->right)
			return minDepth(root->left) + 1;
		
		// Check both trees
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
};
