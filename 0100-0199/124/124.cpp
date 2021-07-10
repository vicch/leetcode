#include <algorithm>
#include <climits>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	// The current max sum, this value will keep getting updated while visiting nodes, it will
	// stop being updated when the root node of the final max path is being visited
	int maxSum;

	// Visit a node and its child nodes recursively. Return the max sum of nodes starting on
	// this node and ending on one of its child nodes.
	int visitNode(TreeNode* root) {
		if (!root)
			return 0;

		// Get max path of child nodes, if the value is smaller than 0, it should be discarded,
		// because it doesn't contribute to the max sum.
		int left = max(visitNode(root->left), 0);
		int right = max(visitNode(root->right), 0);

		// If this node is the root of the final result, the sum of it and its child nodes' max
		// sums should be larger than the current max sum
		maxSum = max(root->val + left + right, maxSum);

		// Return the max sum that could be achieved by starting on this ndoe and ending on one
		// of its child nodes.
		return max(left, right) + root->val;
	}
public:
	int maxPathSum(TreeNode* root) {
		// Init current max sum
		maxSum = INT_MIN;
		visitNode(root);
		return maxSum;
	}
};
