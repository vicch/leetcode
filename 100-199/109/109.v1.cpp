#include <cstddef>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	// Create a BST using numbers within the given range (defined by 2 indexes) of the given
	// list of numbers
	TreeNode* sortedArrayRangeToBST(vector<int>& nums, int from, int to) {
		// If out of range
		if (from > to)
			return NULL;
		
		// Get the index to the middle element, because division result is truncated to int, use
		// +1 to make the left half bigger than the right half, if the length of the range is an
		// even number.
		int mid = (from + to + 1) / 2;

		// Create the root node and left and right child trees recursively
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = sortedArrayRangeToBST(nums, from, mid - 1),
		root->right = sortedArrayRangeToBST(nums, mid + 1, to);
		
		return root;
	}
public:
	TreeNode* sortedListToBST(ListNode* head) {
		vector<int> list;

		// Convert the linked list to vector
		for (; head != NULL; head = head->next) {
			list.push_back(head->val);
		}
		
		return sortedArrayRangeToBST(list, 0, list.size() - 1);
	}
};
