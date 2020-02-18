#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize);

int main()
{
    int pre1[] = {1,2,4,5,3,6,7}
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    if (preorderSize == 0)
        return NULL;

    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = preorder[0];

    int pos;
    for (pos = 0; inorder[pos] != preorder[0]; pos++);
    root->left = buildTree(preorder+1, pos, inorder, pos);
    root->right = buildTree(preorder+pos+1, preorderSize-pos-1, inorder+pos+1, inorderSize-pos-1);

    return root;
}