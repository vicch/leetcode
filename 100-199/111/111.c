#include <stdio.h>

#define MIN_POS(a, b) ((a < b) ? (a > 0 ? a : b) : (b > 0 ? b : a))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int main()
{
    return 0;
}

int minDepth(struct TreeNode* root)
{
    if (root == NULL)
        return 0;

    int l = minDepth(root->left);
    int r = minDepth(root->right);

    return MIN_POS(l, r) + 1;
}