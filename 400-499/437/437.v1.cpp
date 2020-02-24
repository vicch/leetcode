#include <cstdlib>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	int pathSumContinuous(TreeNode* root, int sum) {
		if (!root)
			return 0;
		
		return
			(root->val == sum) +                             // Path ending on current node
			pathSumContinuous(root->left, sum - root->val) + // Paths starting from a previous
			                                                 // node and ending on any node in
			                                                 // left subtree
			pathSumContinuous(root->right, sum - root->val); // Paths starting from a previous
			                                                 // node and ending on any node in
			                                                 // right subtree
	}
public:
	int pathSum(TreeNode* root, int sum) {
		if (!root)
			return 0;
		return
			pathSumContinuous(root, sum) + // Paths starting from current node
			pathSum(root->left, sum) + // Paths starting from any node in left subtree
			pathSum(root->right, sum); // Paths starting from any node in right subtree
	}
};
