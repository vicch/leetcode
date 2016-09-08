#include <stdio.h>
#include <stdlib.h>

void printArray(long* seq, int count);
long* intersect(long* nums1, int nums1Size, long* nums2, int nums2Size, int* returnSize);
int cmpLong(const void* a, const void* b);

int main()
{
    // long seq1[] = {54,93,21,73,84,60,18,62,59,89,83,89,25,39,41,55,78,27,65,82,94,61,12,38,76,5,35,6,51,48,61,0,47,60,84,9,13,28,38,21,55,37,4,67,64,86,45,33,41};
    // long seq2[] = {17,17,87,98,18,53,2,69,74,73,20,85,59,89,84,91,84,34,44,48,20,42,68,84,8,54,66,62,69,52,67,27,87,49,92,14,92,53,22,90,60,14,8,71,0,61,94,1,22,84,10,55,55,60,98,76,27,35,84,28,4,2,9,44,86,12,17,89,35,68,17,41,21,65,59,86,42,53,0,33,80,20};
    // int rc;
    // long* r = intersect(seq1, 49, seq2, 82, &rc);
    // printArray(r, rc);

    long seq1[] = {-2147483648,1,2,3};
    long seq2[] = {1,-2147483648,-2147483648};
    int rc;
    long* r = intersect(seq1, 4, seq2, 3, &rc);
    printArray(r, rc);

    return 0;
}

void printArray(long* seq, int count)
{
    while (count-- > 0) {
        printf((count > 0) ? "%ld," : "%ld", *seq++);
    }
    printf("\n");
}

long* intersect(long* nums1, int nums1Size, long* nums2, int nums2Size, int* returnSize)
{
    qsort(nums1, nums1Size, sizeof(long), cmpLong);
    qsort(nums2, nums2Size, sizeof(long), cmpLong);

    long* r = malloc(sizeof(long) * ((nums1Size > nums2Size) ? nums2Size : nums1Size));
    *returnSize = 0;

    while (nums1Size > 0 && nums2Size > 0) {
        if (*nums1 < *nums2) nums1++, nums1Size--;
        else if (*nums1 > *nums2) nums2++, nums2Size--;
        else {
            r[(*returnSize)++] = *nums1;
            nums1++, nums1Size--;
            nums2++, nums2Size--;
        }
    }

    return r;
}

int cmpLong(const void* a, const void* b)
{
    if (*(long*)a == -2147483648) return -1;
    if (*(long*)b == -2147483648) return 1;
    return (*(long*)a - *(long*)b);
}