#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize);

int main()
{
    int pre1[] = {1,2,4,5,3,6,7}
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
    if (inorderSize == 0)
        return NULL;

    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize-1];

    int pos;
    for (pos = 0; inorder[pos] != root->val; pos++);
    root->left = buildTree(inorder, pos, postorder, pos);
    root->right = buildTree(inorder+pos+1, inorderSize-pos-1, postorder+pos, postorderSize-pos-1);

    return root;
}