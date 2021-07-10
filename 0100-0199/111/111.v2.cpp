#include <queue>

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
		
		// Init BFS queue
		queue<TreeNode*> nodes;
		nodes.push(root);
		
		// Init right-most node
		TreeNode* rightMost = root;

		// Init depth
		int depth = 1;
		
		while (!nodes.empty()) {
			// Get next node from queue
			TreeNode* node = nodes.front(); nodes.pop();
			
			// If this is a leaf node, job is done
			if (!node->left && !node->right)
				break;
			
			if (node->left)
				nodes.push(node->left);
			if (node->right)
				nodes.push(node->right);
			
			// If this node is the right-most node of current level, get the right-most node of
			// next level.
			if (node == rightMost) {
				rightMost = (node->right) ? node->right : node->left;

				// Right-most node visited, increment depth
				depth++;
			}
		}
		
		return depth;
	}
};
