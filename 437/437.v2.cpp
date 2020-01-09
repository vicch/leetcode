#include <cstdlib>
#include <unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
private:
	unordered_map<int, int> cache;
	int count; // Count of proper paths
	
	void visit(TreeNode* root, int total, int sum) {
		if (!root)
			return;
		
		total += root->val;
		
		// If paths ending on this node exist
		if (cache.find(total - sum) != cache.end()) {
			count += cache[total - sum];
		}
		
		cache[total] += 1;
		
		visit(root->left, total, sum);
		visit(root->right, total, sum);
		
		// Decrement the cache, because following DFS will be on a different route
		cache[total] -= 1;
	}
public:
	int pathSum(TreeNode* root, int sum) {
		// Init cache
		cache[0] = 1;

		visit(root, 0, sum);
		
		return count;
	}
};