#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* arrayToTree(int* seq, int total, int index);
void printArray(int* array, int num);

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize);
int getChildren(struct TreeNode** cnodes, struct TreeNode** pnodes, int pcount);

int main()
{
    int seq[] = {1,2,3,4,5,-1,-1,8,9,10,11,-1,-1,-1,-1};
    struct TreeNode* root = arrayToTree(seq, 15, 1);

    int* columnSizes;
    int size;
    int** levels = levelOrder(root, &columnSizes, &size);

    printf("%d\n", size);

    int i;
    for (i = 0; i < size; i++) {
        printArray(*(levels + i), *(columnSizes + i));
    }

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

void printArray(int* array, int num)
{
    printf("[");
    while (num-- > 0) {
        printf((num > 0) ? "%d," : "%d", *array++);
    }
    printf("]\n");
}

int** levelOrder(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    int** results = malloc(sizeof(int*) * 10000);
    *columnSizes = malloc(sizeof(int) * 10000);

    if (root == NULL)
        return results;

    struct TreeNode** cnodes = malloc(sizeof(struct TreeNode*) * 10000);
    struct TreeNode** pnodes = malloc(sizeof(struct TreeNode*) * 10000);
    int pcount = 1, ccount;
    int i = 1, j;

    // First level
    *pnodes = root;
    *results = malloc(sizeof(int) * 1);
    **results = root->val;
    **columnSizes = 1;
    *returnSize = 1;

    // Lower levels
    while ((ccount = getChildren(cnodes, pnodes, pcount)) != 0) {
        *(results + i) = malloc(sizeof(int) * ccount);
        for (j = 0; j < ccount; j++) {
            *(*(results + i) + j) = (*(cnodes + j))->val;
        }
        *(*columnSizes + i) = ccount;
        *returnSize += 1;
        memcpy(pnodes, cnodes, 10000);
        pcount = ccount;
        i++;
    }

    return results;
}

int getChildren(struct TreeNode** cnodes, struct TreeNode** pnodes, int pcount)
{
    int ccount = 0, i;

    for (i = 0; i < pcount; i++) {
        if ((*(pnodes + i))->left != NULL) {
            *(cnodes + ccount) = (*(pnodes + i))->left;
            ccount++;
        }
        if ((*(pnodes + i))->right != NULL) {
            *(cnodes + ccount) = (*(pnodes + i))->right;
            ccount++;
        }
    }

    return ccount;
}