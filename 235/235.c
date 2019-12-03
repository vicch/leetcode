#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q);

int main()
{

}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    if (p->val == root->val || q->val == root->val)
        return root;
    else if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    else if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    else
        return root;
}