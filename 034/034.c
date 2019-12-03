#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize);
int bsStart(int* nums, int i, int j, int target);
int bsEnd(int* nums, int i, int j, int target);

int main()
{
    int seq[] = {1,2,3,4,5,5,6,7,8,9,10};
    int size;
    int* res = searchRange(seq, 11, 5, &size);
    printf("%d,%d\n", res[0], res[1]);

    return 0;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    *returnSize = 2;
    int* range = malloc(sizeof(int) * 2);

    if (numsSize == 0) {
        range[0] = -1;
        range[1] = -1;
    } else{
        range[0] = bsStart(nums, 0, numsSize-1, target);
        range[1] = bsEnd(nums, 0, numsSize-1, target);
    }

    return range;
}

int bsStart(int* nums, int i, int j, int target)
{
    int mid;
    while (i <= j) {
        mid = (i + j) / 2;
        if (nums[mid] == target && ((mid > i && nums[mid-1] < target) || mid == i))
            return mid;
        if (nums[mid] > target || (nums[mid] == target && mid > i && nums[mid-1] == target))
            j = mid - 1;
        else
            i = mid + 1;
    }
    return nums[i] == target ? i : -1;
}

int bsEnd(int* nums, int i, int j, int target)
{
    int mid;
    while (i <= j) {
        mid = (i + j) / 2;
        if (nums[mid] == target && ((mid < j && nums[mid+1] > target) || mid == j))
            return mid;
        if (nums[mid] < target || (nums[mid] == target && mid < j && nums[mid+1] == target))
            i = mid + 1;
        else
            j = mid - 1;
    }
    return nums[i] == target ? i : -1;
}