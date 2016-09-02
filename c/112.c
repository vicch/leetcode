#include <stdio.h>

bool hasPathSum(struct TreeNode* root, int sum);

int main()
{
    return 0;
}

bool hasPathSum(struct TreeNode* root, int sum)
{
    if (root == NULL || root->val > sum)
        return 0;

    if (root->left == NULL && root->right == NULL && root->val == sum)
        return 1;

    sum -= root->val;

    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}