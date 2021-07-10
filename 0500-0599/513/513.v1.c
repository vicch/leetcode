// Problem:
// Given a binary tree, find the leftmost value in the last row of the tree.
// Assume the tree (i.e., the given root node) is not NULL.
// 
// Example:
// Input:
//     1
//    / \
//   2   3
//  /   / \
// 4   5   6
//    /
//   7
// Output: 7
// 
// Solution:
// Recursively get the leftmost value of each subtree with a depth returned.
// Return the one with larger depth.

#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int findBottomLeftValue(struct TreeNode* root);

int main()
{
    return 0;
}

/********** Solution **********/

int findBottomLeftValueSub(struct TreeNode* root, int dep, int* maxdep);

int findBottomLeftValue(struct TreeNode* root)
{
    int dep;
    return findBottomLeftValueSub(root, 0, &dep);
}

int findBottomLeftValueSub(struct TreeNode* root, int dep, int* maxdep)
{
    int lval, rval, ldep, rdep;

    lval = root->val;
    ldep = rdep = dep;

    if (root->left)
        lval = findBottomLeftValueSub(root->left, dep + 1, &ldep);
    if (root->right)
        rval = findBottomLeftValueSub(root->right, dep + 1, &rdep);

    if (rdep > ldep) {
        *maxdep = rdep;
        return rval;
    } else {
        *maxdep = ldep;
        return lval;
    }
}