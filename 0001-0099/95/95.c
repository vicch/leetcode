#include <stdio.h>
#include <stdlib.h>

struct TreeNode** generateTrees(int n, int* returnSize);
struct TreeNode** subTrees(int from, int to, int* returnSize);
int approxSize(int n);

int main()
{
    return 0;
}

struct TreeNode** generateTrees(int n, int* returnSize)
{
    if (n <= 0) {
        *returnSize = 0;
        return NULL;
    } else
        return subTrees(1, n, returnSize);
}

struct TreeNode** subTrees(int from, int to, int* returnSize)
{
    struct TreeNode** trees;

    if (to < from) {
        trees = malloc(sizeof(struct TreeNode*));
        trees[0] = NULL;
        *returnSize = 1;

    } else {
        trees = malloc(sizeof(struct TreeNode*) * approxSize(to - from + 1));
        *returnSize = 0;

        int i, j, k;

        for (i = from; i <= to; i++) {
            int lSize, rSize;
            struct TreeNode** lTrees = subTrees(from, i-1, &lSize);
            struct TreeNode** rTrees = subTrees(i+1, to, &rSize);
            for (j = 0; j < lSize; j++) {
                for (k = 0; k < rSize; k++) {
                    struct TreeNode* root = malloc(sizeof(struct TreeNode));
                    root->val = i;
                    root->left = lTrees[j];
                    root->right = rTrees[k];
                    trees[(*returnSize)++] = root;
                }
            }
        }
    }

    return trees;
}

int approxSize(int n)
{
    if (n <= 1)
        return 1;
    int size = 2;
    for (n -= 2; n > 0; n--)
        size *= 3;
    return size;
}