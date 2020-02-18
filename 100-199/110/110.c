#include <stdio.h>
#include <math.h>

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

bool isBalanced(struct TreeNode* root)
{
    int maxDepth(struct TreeNode* root);

    if (root == NULL)
        return 1;

    if (!isBalanced(root->left) || !isBalanced(root->right))
        return 0;

    int lmax = maxDepth(root->left);
    int rmax = maxDepth(root->right);

    return abs(lmax - rmax) <= 1;
}

int maxDepth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;

    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    return MAX(l, r) + 1;
}