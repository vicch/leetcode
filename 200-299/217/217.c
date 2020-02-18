#include <stdio.h>
#include <stdlib.h>

typedef int bool;

void printArray(int* seq, int count);
int cmpInt(const void * a, const void * b);
bool containsDuplicate(int* nums, int numsSize);

int main()
{
    int nums[] = {1,1,1};
    printf("%d\n", containsDuplicate(nums, 3));

    return 0;
}

void printArray(int* seq, int count)
{
    while (count-- > 0) {
        printf((count > 0) ? "%d," : "%d\n", *seq++);
    }
}

int cmpInt(const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize)
{
    if (numsSize < 2)
        return 0;

    qsort(nums, numsSize, sizeof(int), cmpInt);

    while (numsSize-- > 0) {
        if (*nums == *(nums + 1))
            return 1;
        nums++;
    }

    return 0;
}