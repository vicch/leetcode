#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* makeTree(int* seq, int total, int index);
void printArrays(int** arrays, int* cols, int size);
void printArray(int* array, int num);

int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize);
int* zigzagSub(struct TreeNode** nodes, int size, int dir, struct TreeNode*** subNodes, int* subSize);

int main()
{
    int seq1[] = {3,9,20,-1,-1,15,7};
    struct TreeNode* tree1 = makeTree(seq1, 7, 1);
    int* cols1;
    int size1;
    int** zig1 = zigzagLevelOrder(tree1, &cols1, &size1);
    printArrays(zig1, cols1, size1);

    return 0;
}

struct TreeNode* makeTree(int* seq, int total, int index)
{
    if (seq[index - 1] == -1)
        return NULL;

    struct TreeNode* root = malloc(sizeof(struct TreeNode));

    root->val   = seq[index - 1];
    root->left  = NULL;
    root->right = NULL;

    if (index * 2 <= total)
        root->left = makeTree(seq, total, index * 2);

    if (index * 2 + 1 <= total)
        root->right = makeTree(seq, total, index * 2 + 1);

    return root;
}

void printArrays(int** arrays, int* cols, int size)
{
    for (; size > 0; size--, arrays++, cols++)
        printArray(*arrays, *cols);
}

void printArray(int* array, int num)
{
    printf("[");
    while (num-- > 0)
        printf((num > 0) ? "%d," : "%d]\n", *array++);
}

int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    *returnSize = 0;

    if (!root) {
        *columnSizes = NULL;
        return NULL;
    }

    // Max 100 layers
    int** levelNums = malloc(sizeof(int*) * 100);
    *columnSizes = malloc(sizeof(int) * 100);

    struct TreeNode **nodes, **subNodes;
    int size, subSize, dir;

    // Make a dummy node pointing to root
    struct TreeNode* dummy = malloc(sizeof(struct TreeNode));
    dummy->left = root;
    dummy->right = NULL;

    nodes = malloc(sizeof(struct TreeNode*));
    nodes[0] = dummy;
    size = dir = 1;

    while (size) {
        levelNums[*returnSize] = zigzagSub(nodes, size, dir, &subNodes, &subSize);
        (*columnSizes)[*returnSize] = subSize;
        (*returnSize)++;

        free(nodes);
        nodes = subNodes;
        size = subSize;
        dir = -dir;
    }

    // Last layer is empty
    (*returnSize)--;

    free(dummy);

    return levelNums;
}

int* zigzagSub(struct TreeNode** nodes, int size, int dir, struct TreeNode*** subNodes, int* subSize)
{
    int* nums = malloc(sizeof(int) * size * 2);
    *subNodes = malloc(sizeof(struct TreeNode*) * size * 2);
    *subSize = 0;

    int i;
    struct TreeNode* node;
    // Always iterating nodes backwardly
    for (i = size - 1; i >= 0; i--) {
        // Direction determines reading left or right node first
        node = (dir == 1) ? ((nodes[i]->left) ? nodes[i]->left : NULL) : ((nodes[i]->right) ? nodes[i]->right : NULL);
        if (node) (*subNodes)[*subSize] = node, nums[*subSize] = node->val, (*subSize)++;
        node = (dir == 1) ? ((nodes[i]->right) ? nodes[i]->right : NULL) : ((nodes[i]->left) ? nodes[i]->left : NULL);
        if (node) (*subNodes)[*subSize] = node, nums[*subSize] = node->val, (*subSize)++;
    }

    return nums;
}