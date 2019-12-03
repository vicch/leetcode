#include <stdio.h>

#define MAX(a, b) ((a > b) ? a : b);

int rob(int* nums, int numsSize);

int main()
{
    int seq1[] = {1};
    printf("%d\n", rob(seq1, 1));

    int seq2[] = {1,1};
    printf("%d\n", rob(seq2, 2));

    int seq3[] = {1,2};
    printf("%d\n", rob(seq3, 2));

    int seq4[] = {1,2,3};
    printf("%d\n", rob(seq4, 3));

    int seq5[] = {1,2,1,1};
    printf("%d\n", rob(seq5, 4));

    return 0;
}

int rob(int* nums, int numsSize)
{
    int a = 0, b = 0;
    int i;

    for (i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            a = MAX(a + nums[i], b);
        } else {
            b = MAX(b + nums[i], a);
        }
    }

    return MAX(a, b);
}