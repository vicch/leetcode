#include <stdio.h>

#define MAX(a, b) ((a > b) ? a : b)

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int main()
{
    return 0;
}

int maxDepth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;

    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    return MAX(l, r) + 1;
}