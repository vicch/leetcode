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

int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize);

int main()
{
    int seq1[] = {5,4,8,11,-1,13,4,7,2,-1,-1,-1,-1,5,1};
    struct TreeNode* tree1 = makeTree(seq1, 15, 1);
    int* cols1;
    int size1;
    int** path1 = pathSum(tree1, 22, &cols1, &size1);
    printArrays(path1, cols1, size1);

    int seq2[] = {-2,-1,-3};
    struct TreeNode* tree2 = makeTree(seq2, 3, 1);
    int* cols2;
    int size2;
    int** path2 = pathSum(tree2, -5, &cols2, &size2);
    printArrays(path2, cols2, size2);

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
        printf((num > 0) ? "%d," : "%d", *array++);
    printf("]\n");
}

/**
 * Just plain recursion, joining paths of child nodes and attch root node value
 */
int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize)
{
    *returnSize = 0;
    *columnSizes = NULL;

    if (!root)
        return NULL;

    // Not leaf
    if (root->left || root->right) {
        sum -= root->val;

        int *lColSizes = NULL, *rColSizes = NULL;
        int lSize, rSize;
        int** lPath = pathSum(root->left, sum, &lColSizes, &lSize);
        int** rPath = pathSum(root->right, sum, &rColSizes, &rSize);

        if (lSize > 0 || rSize > 0) {
            *returnSize = lSize + rSize;

            int** path = malloc(sizeof(int*) * (*returnSize));
            *columnSizes = malloc(sizeof(int) * (*returnSize));

            int i, j;
            for (i = 0; i < lSize; i++) {
                (*columnSizes)[i] = lColSizes[i] + 1;

                path[i] = malloc(sizeof(int) * (*columnSizes)[i]);
                path[i][0] = root->val;
                for (j = 0; j < lColSizes[i]; j++)
                    path[i][j+1] = lPath[i][j];

                free(lPath[i]);
            }

            for (i = 0; i < rSize; i++) {
                (*columnSizes)[lSize+i] = rColSizes[i] + 1;

                path[lSize+i] = malloc(sizeof(int) * (*columnSizes)[lSize+i]);
                path[lSize+i][0] = root->val;
                for (j = 0; j < rColSizes[i]; j++)
                    path[lSize+i][j+1] = rPath[i][j];

                free(rPath[i]);
            }

            if (lColSizes) free(lColSizes);
            if (rColSizes) free(rColSizes);
            if (lPath) free(lPath);
            if (rPath) free(rPath);

            return path;
        }

    // Leaf
    } else if (root->val == sum) {
        *returnSize = 1;

        int** path = malloc(sizeof(int*));
        path[0] = malloc(sizeof(int));
        path[0][0] = root->val;

        *columnSizes = malloc(sizeof(int));
        (*columnSizes)[0] = 1;
        
        return path;
    }

    return NULL;
}