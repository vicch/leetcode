// Problem:
// Implement an iterator over a BST. The iterator will be initialized with the
// root node of a BST. Calling next() will return the next smallest number in
// the BST. next() and hasNext() should run in average O(1) time and uses O(h)
// memory, where h is the height of the tree.
// 
// Solution:
// Recursively push root and its left child nodes into a stack at beginning.
// To get next smallest node, pop from the stack and use its right child node
// as a root node and recursively push its left child nodes into stack. If
// stack is empty, there is no next node.

#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    stack<TreeNode*> nodeStack;

public:
    BSTIterator(TreeNode* root) {
        if (root)
            pushStack(root);
    }

    bool hasNext() {
        return !nodeStack.empty();
    }

    int next() {
        if (!hasNext())
            return 0;

        TreeNode* nextNode = nodeStack.top();
        nodeStack.pop();

        if (nextNode->right)
            pushStack(nextNode->right);

        return nextNode->val;
    }

private:
    void pushStack(TreeNode* root) {
        nodeStack.push(root);

        if (root->left)
            pushStack(root->left);

        return;
    }
};