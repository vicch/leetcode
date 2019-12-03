// Problem:
// Given a binary search tree, write a function kthSmallest to find the kth
// smallest element in it. Assume k is always valid.
// 
// Solution:
// Recursively looking for the kth element by decreasing k while in-order
// traversing the tree. Whenever k becomes 1 after left child tree traversal,
// current root is the answer.

#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

struct Answer {
    int k;
    TreeNode* node;
};

class Solution {
    Answer* a;

public:
    Solution() {
        a = new Answer();
        a->k = 0;
        a->node = NULL;
    }

    int kthSmallest(TreeNode* root, int k) {
        a->k = k;
        kthRecursive(root);
        return a->node->val;
    }

    void kthRecursive(TreeNode* root) {
        // Traverse left child tree
        if (root->left)
            kthRecursive(root->left);

        // If kth element found in left child tree
        if (a->node)
            return;

        // kth element is current root
        if (a->k == 1) {
            a->node = root;
            return;
        }

        // Minus current root
        a->k -= 1;

        // Traverse right child tree
        if (root->right)
            kthRecursive(root->right);
        
        return;
    }
};