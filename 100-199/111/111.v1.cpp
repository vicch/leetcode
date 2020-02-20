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
		
		// If no left child tree, only check right child tree
		if (!root->left)
			return minDepth(root->right) + 1;
		
		// If no right child tree, only check left child tree
		if (!root->right)
			return minDepth(root->left) + 1;
		
		// Check both trees
		return min(minDepth(root->left), minDepth(root->right)) + 1;
	}
};
