#include <cstddef>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	bool isLeaf(TreeNode* root) {
		return root && !root->left && !root->right;
	}
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (!root)
			return 0;

		if (isLeaf(root->left))
			return root->left->val + sumOfLeftLeaves(root->right);
		else
			return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
	}
};