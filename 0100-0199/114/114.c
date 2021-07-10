#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void flatten(struct TreeNode* root);
struct TreeNode* flattenSub(struct TreeNode* root);

int main()
{

}

void flatten(struct TreeNode* root)
{
    flattenSub(root);
    return;
}

/**
 * Recursively flatten left and right trees and concat them 
 */
struct TreeNode* flattenSub(struct TreeNode* root)
{
    if (!root) return NULL;
    if (!root->left && !root->right) return root;

    struct TreeNode* rTail = flattenSub(root->right);
    struct TreeNode* lTail = flattenSub(root->left);
    
    // Attach flattened right tree to the end of flattened left tree
    if (lTail) {
        lTail->right = root->right;
        root->right = root->left;
    }

    root->left = NULL;

    return rTail ? rTail : lTail;
}