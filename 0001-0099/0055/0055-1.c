#include <stdio.h>

typedef int bool;

bool canJump(int* nums, int numsSize);
bool canJumpSub(int* nums, int l, int r, int numsSize);

int main()
{
    int seq1[] = {2,3,1,1,4};
    printf("%d\n", canJump(seq1, 5));

    int seq2[] = {3,2,1,0,4};
    printf("%d\n", canJump(seq2, 5));

    int seq3[] = {2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
    printf("%d\n", canJump(seq3, 104));

    return 0;
}

bool canJump(int* nums, int numsSize)
{
    if (numsSize <= 1 || nums[0] >= numsSize - 1) return 1;
    if (nums[0] < 1) return 0;

    return canJumpSub(nums, 1, nums[0], numsSize);
}

bool canJumpSub(int* nums, int l, int r, int numsSize)
{
    int max = r;
    for (; l <= r; l++) {
        if (l + nums[l] >= numsSize - 1) return 1;
        if (l + nums[l] > max) max = l + nums[l];
    }
    if (max < r + 1) return 0;
    return canJumpSub(nums, r + 1, max, numsSize);
}