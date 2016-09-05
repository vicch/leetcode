#include <stdio.h>

int main()
{

}

struct TreeNode* invertTree(struct TreeNode* root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return root;

    struct TreeNode* tmp = root->left;

    root->left = invertTree(root->right);
    root->right = invertTree(tmp);

    return root;
}