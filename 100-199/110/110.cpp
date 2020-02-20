#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	// Get height of given tree, return -1 if tree is height-unbalanced
	int getHeight(TreeNode* root) {
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
			return max(ld, rd) + 1;
		// If not, current tree is unbalanced
		else
			return -1;
	}

public:
	bool isBalanced(TreeNode* root) {
		return getHeight(root) != -1;
	}
};
