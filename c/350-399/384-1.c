// Problem:
// Shuffle a set of numbers without duplicates.
// 
// Example:
// // Init an array with set 1, 2, and 3.
// int[] nums = {1,2,3};
// Solution solution = new Solution(nums);
// 
// // Shuffle the array [1,2,3] and return its result. Any permutation of
// [1,2,3] must equally likely to be returned.
// solution.shuffle();
// 
// // Resets the array back to its original configuration [1,2,3].
// solution.reset();
// 
// // Returns the random shuffling of array [1,2,3].
// solution.shuffle();
// 
// Solution (NOT ACCEPTED: Time limit exceeded):
// - Store the number of permutations n.
// - Use a random number generator to get random number r.
// - Get m = r % n.
// - Get the mth permutation.
// 
// Example:
// 0: [1, 2, 3, 4] (original)
// 1: [2, 1, 3, 4] (swapped index 0 and 1)
// 2: [2, 3, 1, 4] (swapped index 1 and 2)
// 3: [2, 3, 4, 1] (swapped index 2 and 3)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int* nums;
    int size;
    long psize;
} Solution;

Solution* solutionCreate(int* nums, int size);
int* solutionReset(Solution* obj, int *returnSize);
int* solutionShuffle(Solution* obj, int *returnSize);
void solutionFree(Solution* obj);
void printArray(int* seq, int count);

int main()
{
    int nums1[] = {1, 2, 3, 4};
    Solution* obj1 = solutionCreate(nums1, 4);
    int *shuf1, size1;
    shuf1 = solutionShuffle(obj1, &size1);
    printArray(shuf1, size1);
    shuf1 = solutionShuffle(obj1, &size1);
    printArray(shuf1, size1);

    return 0;
}

void printArray(int* seq, int count)
{
    while (count-- > 0)
        printf((count > 0) ? "%d," : "%d", *seq++);
    printf("\n");
}

/********** Solution **********/

long factorial(int size);

Solution* solutionCreate(int* nums, int size)
{
    time_t t;

    Solution* obj = malloc(sizeof(Solution));
    obj->nums = malloc(sizeof(int) * size);
    memcpy(obj->nums, nums, sizeof(int) * size);
    obj->size = size;
    obj->psize = factorial(size);

    srand((unsigned) time(&t));

    return obj;
}

int* solutionReset(Solution* obj, int *returnSize)
{
    *returnSize = obj->size;
    return obj->nums;
}

int* solutionShuffle(Solution* obj, int *returnSize)
{
    *returnSize = obj->size;

    int i, j, tmp;
    int seed = rand() % obj->psize;

    int* nums = malloc(sizeof(int) * obj->size);
    memcpy(nums, obj->nums, sizeof(int) * obj->size);

    for (i = 0; i < seed; i++) {
        j = i % (obj->size - 1);
        tmp = nums[j], nums[j] = nums[j + 1], nums[j + 1] = tmp;
    }

    return nums;
}

void solutionFree(Solution* obj)
{
    free(obj->nums);
    free(obj);

    return;
}

long factorial(int size)
{
    long ret = 1;

    for (; size > 1; size--)
        ret *= size;

    return ret;
}