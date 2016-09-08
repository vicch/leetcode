#include <stdio.h>
#include <stdlib.h>

void printArray(int* seq, int count);
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
int cmpInt(const void * a, const void * b);

int main()
{
    int seq1[] = {54,93,21,73,84,60,18,62,59,89,83,89,25,39,41,55,78,27,65,82,94,61,12,38,76,5,35,6,51,48,61,0,47,60,84,9,13,28,38,21,55,37,4,67,64,86,45,33,41};
    int seq2[] = {17,17,87,98,18,53,2,69,74,73,20,85,59,89,84,91,84,34,44,48,20,42,68,84,8,54,66,62,69,52,67,27,87,49,92,14,92,53,22,90,60,14,8,71,0,61,94,1,22,84,10,55,55,60,98,76,27,35,84,28,4,2,9,44,86,12,17,89,35,68,17,41,21,65,59,86,42,53,0,33,80,20};
    int rc;
    int* r = intersection(seq1, 49, seq2, 82, &rc);
    printArray(r, rc);

    return 0;
}

void printArray(int* seq, int count)
{
    while (count-- > 0) {
        printf((count > 0) ? "%d," : "%d", *seq++);
    }
    printf("\n");
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    qsort(nums1, nums1Size, sizeof(int), cmpInt);
    qsort(nums2, nums2Size, sizeof(int), cmpInt);

    int* r = malloc(sizeof(int) * ((nums1Size > nums2Size) ? nums2Size : nums1Size));
    *returnSize = 0;

    while (nums1Size > 0 && nums2Size > 0) {
        if (*nums1 < *nums2) nums1++, nums1Size--;
        else if (*nums1 > *nums2) nums2++, nums2Size--;
        else {
            if (*returnSize == 0 || r[*returnSize - 1] != *nums1) {
                r[*returnSize] = *nums1;
                *returnSize += 1;
            }
            nums1++, nums1Size--;
            nums2++, nums2Size--;
        }
    }

    return r;
}

int cmpInt(const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}