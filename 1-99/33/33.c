#include <stdio.h>
#include <stdlib.h>

int search(int* nums, int numsSize, int target);
int findHead(int* nums, int size);
int findNum(int* nums, int size, int n);

int main()
{
    int seq1[] = {5,6,1,2,3,4};
    printf("%d\n", search(seq1, 6, 1));

    int seq2[] = {4,5,6,7,0,1,2};
    printf("%d\n", search(seq2, 7, 0));

    int seq3[] = {2,1};
    printf("%d\n", search(seq3, 2, 2));

    return 0;
}

int search(int* nums, int numsSize, int target)
{
    if (numsSize == 1) return (nums[0] == target) ? 0 : -1;
    int h = findHead(nums, numsSize);
    int p = findNum(nums, h, target);
    if (p != -1) return p;
    p = findNum(nums + h, numsSize - h, target);
    return (p == -1) ? -1 : p + h;
}

int findHead(int* nums, int size)
{
    int l = 0, r = size - 1, m;
    while (l < r) {
        m = (l + r) / 2;
        if (m > 0 && m < size - 1 && nums[m] < nums[m-1] && nums[m] < nums[m+1]) return m;
        else if (nums[r] < nums[m]) l = m + 1;
        else r = m - 1;
    }
    return l;
}

int findNum(int* nums, int size, int n)
{
    if (size == 0) return -1;
    int l = 0, r = size - 1, m;
    while (l < r) {
        m = (l + r) / 2;
        if (nums[m] == n) return m;
        else if (nums[m] > n) r = m - 1;
        else l = m + 1;
    }
    return (nums[l] == n) ? l : -1;
}