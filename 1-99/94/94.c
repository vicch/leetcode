#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* arrayToTree(int* seq, int total, int index);
void printArray(int* array, int num);

int* inorderTraversal(struct TreeNode* root, int* returnSize);

int main()
{
    // int seq1[] = {2,1,3};
    // struct TreeNode* tree1 = arrayToTree(seq1, 3, 1);
    // int size1;
    // int* order1 = inorderTraversal(tree1, &size1);
    // printArray(order1, size1);

    int seq2[] = {1,-1,2,-1,-1,3,-1};
    struct TreeNode* tree2 = arrayToTree(seq2, 7, 1);
    int size2;
    int* order2 = inorderTraversal(tree2, &size2);
    printArray(order2, size2);

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
    while (num-- > 0)
        printf((num > 0) ? "%d," : "%d]\n", *array++);
}

void printStack(struct TreeNode* stack[], int top)
{
    if (top >= 0) {
        int i;
        printf("[");
        for (i = 0; i <= top; i++)
            printf((i < top) ? "%d," : "%d]", stack[i]->val);
    }
    printf("\n");
}

/**
 * The flow is really delicate, hard to devise.
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;
    if (!root) return NULL;

    struct TreeNode* node = root;
    struct TreeNode* stack[1000];
    int top = -1;
    int* seq = malloc(sizeof(int) * 1000);

    while (node != NULL || top >= 0) {
        while (node != NULL) {
            stack[++top] = node;
            node = node->left;
        }
        node = stack[top--];
        seq[(*returnSize)++] = node->val;
        node = node->right;
    }

    return seq;
}