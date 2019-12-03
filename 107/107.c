#include <stdio.h>
#include <stdlib.h>

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize);
void levelOrderSub(struct TreeNode* root, int** columnSizes, int* returnSize, int*** nums, int level);

int main()
{

}

/**
 * There seems no better solution than DFS adding values to 2D array, and
 * reverse the 2D array and column sizes at the end
 */
int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    *returnSize = 0;

    if (!root)
        return NULL;

    // Max 1000 levels
    int** nums = malloc(sizeof(int*) * 1000);
    *columnSizes = malloc(sizeof(int) * 1000);

    levelOrderSub(root, columnSizes, returnSize, &nums, 1);

    // Reverse numbers and column sizes
    int i, tmpSize;
    int* tmpNums;
    for (i = 0; i < *returnSize / 2; i++) {
        tmpSize = (*columnSizes)[i], (*columnSizes)[i] = (*columnSizes)[*returnSize-i-1], (*columnSizes)[*returnSize-i-1] = tmpSize;
        tmpNums = nums[i], nums[i] = nums[*returnSize-i-1], nums[*returnSize-i-1] = tmpNums;
    }

    return nums;
}

void levelOrderSub(struct TreeNode* root, int** columnSizes, int* returnSize, int*** nums, int level)
{
    if (!root) return;

    // New level
    if (*returnSize < level) {
        // Add level, start as one int, grow as needed
        (*nums)[level-1] = malloc(sizeof(int));
        (*columnSizes)[level-1] = 0;
        *returnSize = level;
    }

    // Grow to contain one more int
    (*nums)[level-1] = realloc((*nums)[level-1], sizeof(int) * ((*columnSizes)[level-1] + 1));
    (*nums)[level-1][((*columnSizes)[level-1])++] = root->val;

    // Recursive
    levelOrderSub(root->left, columnSizes, returnSize, nums, level+1);
    levelOrderSub(root->right, columnSizes, returnSize, nums, level+1);

    return;
}