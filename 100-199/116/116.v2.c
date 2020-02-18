#include <stdio.h>
#include <stdlib.h>

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
};

struct TreeLinkNode* makeTree(int* seq, int total, int index);

void connect(struct TreeLinkNode *root);
struct TreeLinkNode* connectSub(struct TreeLinkNode* head);

int main()
{
    int seq1[] = {1,2,3,4,5,6,7};
    struct TreeLinkNode* tree1 = makeTree(seq1, 7, 1);
    connect(tree1);

    return 0;
}

struct TreeLinkNode* makeTree(int* seq, int total, int index)
{
    if (seq[index - 1] == -1)
        return NULL;

    struct TreeLinkNode* root = malloc(sizeof(struct TreeLinkNode));

    root->val   = seq[index - 1];
    root->left  = NULL;
    root->right = NULL;
    root->next  = NULL;

    if (index * 2 <= total)
        root->left = makeTree(seq, total, index * 2);

    if (index * 2 + 1 <= total)
        root->right = makeTree(seq, total, index * 2 + 1);

    return root;
}

void connect(struct TreeLinkNode *root)
{
    if (!root || (!root->left && !root->right)) return;

    root->left->next = root->right;
    if (root->next)
        root->right->next = root->next->left;
    connect(root->left);
    connect(root->right);

    return;
}