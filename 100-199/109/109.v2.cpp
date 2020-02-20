#include <cstddef>

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
	// Pointer used to simulate inorder traversal
	ListNode* current;

	// Convert the given range of the sorted list to BST. The range is only virtual, as we can't
	// actually access the elements by index. The start/end numbers are only used for the end
	// case condition, i.e. return the recursive call when we have reached the leaf nodes.
	TreeNode* sortedListRangeToBST(int start, int end) {
		// If out of range
		if (start > end)
			return NULL;
		
		// Get the index to the middle element, because division result is truncated to int, use
		// +1 to make the left half bigger than the right half, if the length of the range is an
		// even number.
		int mid = (start + end + 1) / 2;
		
		// Inorder traversal step 1: visit left child tree
		TreeNode* left = sortedListRangeToBST(start, mid - 1);

		// Inorder traversal step 2: visit root node
		TreeNode* root = new TreeNode(current->val);
		
		// Move the pointer forward after assigning its value to root node
		current = current->next;
		
		// Inorder traversal step 3: visit right child tree
		TreeNode* right = sortedListRangeToBST(mid + 1, end);
		
		// Assemble the tree
		root->left = left;
		root->right = right;
		
		return root;
	}
public:
	TreeNode* sortedListToBST(ListNode* head) {
		int len;
		ListNode* ptr;
		
		// Get length of the linked list
		for (len = 0, ptr = head; ptr != NULL; len++, ptr = ptr->next);
		
		// Init the pointer
		current = head;

		return sortedListRangeToBST(0, len - 1);
	}
};
