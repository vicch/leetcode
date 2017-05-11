// Problem:
// Given a binary tree, each node has a third pointer "next". Populate each
// "next" pointer to point to its next right node. If there is no next right
// node, the next pointer should be set to NULL.
// 
// Example:
// Input: 1
//       / \
//      2   3
//     / \   \
//    4   5   7
// Output: 1-> NULL
//        / \
//       2-> 3-> NULL
//      / \   \
//     4-> 5-> 7-> NULL

#include <stdio.h>
#include <stdlib.h>

struct TreeLinkNode {
    int val;
    struct TreeLinkNode* left;
    struct TreeLinkNode* right;
    struct TreeLinkNode* next;
};

struct TreeLinkNode* makeTree(int* seq, int total, int index);
void connect(struct TreeLinkNode* root);

int main()
{
    int seq1[] = {2, 1, 3, 0, 7, 9, 1, 2, -1, 1, 0, -1, -1, 8, 8, -1, -1, -1, -1, -1, -1, 7};
    struct TreeLinkNode* tree1 = makeTree(seq1, 22, 1);
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

/********** Solution **********/

void connect(struct TreeLinkNode* root)
{
    return;
}