#include <stdio.h>

bool isValidBST(struct TreeNode* root);
bool isValidBSTSub(struct TreeNode* root, int min, int max);

int main()
{
    // {}
    // {1,2,3}
    // {2,1,3}
    // {10,5,15,null,null,6,20}
    // {2147483647}
    // {2147483647, 2147483647}
    // {-2147483648}
    // {-2147483648,-2147483648}

    return 0;
}

bool isValidBST(struct TreeNode* root)
{
    return isValidBSTSub(root, -2147483648, 2147483647);
}

bool isValidBSTSub(struct TreeNode* root, int min, int max)
{
    if (!root) return 1;
    if (min != -2147483648 && root->val < min) return 0;
    if (max != 2147483647 && root->val > max) return 0;
    if (root->left && (root->val == -2147483648 || !isValidBSTSub(root->left, min, root->val-1))) return 0;
    if (root->right && (root->val == 2147483647 || !isValidBSTSub(root->right, root->val+1, max))) return 0;
    return 1;
}