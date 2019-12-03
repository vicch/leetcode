#include <stdio.h>

int sumNumbers(struct TreeNode* root);
int sumSub(struct TreeNode* root, int base);

int main()
{

}

int sumNumbers(struct TreeNode* root)
{
    return sumSub(root, 0);
}

int sumSub(struct TreeNode* root, int base)
{
    if (!root) return 0;
    base = base * 10 + root->val;
    int sums = sumSub(root->left, base) + sumSub(root->right, base);
    // If no children nodes (sums == 0), return base
    return (sums) ? sums : base;
}