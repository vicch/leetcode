#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArray(int* array, int num);
void merge(int* nums1, int m, int* nums2, int n);

int main()
{
    int a1[8] = {1,2,3,4};
    int a2[4] = {2,3,4,5};

    merge(a1, 4, a2, 4);
    printArray(a1, 8);
    return 0;
}

void printArray(int* array, int num)
{
    while (num-- > 0) {
        printf((num > 0) ? "%d," : "%d\n", *array++);
    }
}

void merge(int* nums1, int m, int* nums2, int n)
{
    int* cpy1 = malloc(sizeof(int) * m);
    int i;

    memcpy(cpy1, nums1, sizeof(int) * m);
    i = 0;

    while (m > 0 && n > 0) {
        if (*cpy1 < *nums2) {
            nums1[i++] = *cpy1++;
            m--;
        } else {
            nums1[i++] = *nums2++;
            n--;
        }
    }

    while (m-- > 0)
        nums1[i++] = *cpy1++;

    while (n-- > 0)
        nums1[i++] = *nums2++;
}