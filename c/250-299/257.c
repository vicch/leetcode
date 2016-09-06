#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* arrayToTree(int* seq, int total, int index);
void printPaths(char** paths, int size);
char** binaryTreePaths(struct TreeNode* root, int* returnSize);
char** getPathsFromNode(struct TreeNode* root, char* prev, int* size);

int main()
{
    int seq[] = {1,2,3,4,5,-1,-1,8,9,10,11,-1,-1,-1,-1};
    struct TreeNode* root = arrayToTree(seq, 15, 1);
    int size;
    char** paths = binaryTreePaths(root, &size);

    printf("%d\n", size);
    printPaths(paths, size);

    return 0;
}

struct TreeNode* arrayToTree(int* seq, int total, int index)
{
    if (seq[index - 1] == -1)
        return NULL;

    struct TreeNode* root = malloc(sizeof(struct TreeNode));

    root->val   = seq[index - 1];
    root->left  = NULL;
    root->right = NULL;

    if (index * 2 <= total)
        root->left = arrayToTree(seq, total, index * 2);

    if (index * 2 + 1 <= total)
        root->right = arrayToTree(seq, total, index * 2 + 1);

    return root;
}

void printPaths(char** paths, int size)
{
    while (size-- > 0) {
        printf("%s\n", *paths++);
    }
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
    if (root == NULL)
        return NULL;

    return getPathsFromNode(root, "", returnSize);
}

char** getPathsFromNode(struct TreeNode* root, char* prev, int* size)
{
    char* base = malloc(sizeof(char) * 1000);
    sprintf(base, (*prev == '\0') ? "%s%d" : "%s->%d", prev, root->val);

    // Leaf node
    if (root->left == NULL && root->right == NULL) {
        *size = 1;
        char** paths = malloc(sizeof(char*));
        paths[0] = base;
        return paths;

    // Non-leaf node
    } else {
        int lsize = 0, rsize = 0;
        char** lpaths = (root->left != NULL) ? getPathsFromNode(root->left, base, &lsize) : NULL;
        char** rpaths = (root->right != NULL) ? getPathsFromNode(root->right, base, &rsize) : NULL;

        *size = lsize + rsize;
        char** paths = malloc(sizeof(char*) * (*size));

        if (lsize > 0)
            memcpy(paths, lpaths, sizeof(char*) * lsize);
        if (rsize > 0)
            memcpy(paths + lsize, rpaths, sizeof(char*) * rsize);

        return paths;
    }
}