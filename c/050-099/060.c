#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int* array, int num);

char* getPermutation(int n, int k);
int getNthNumber(int* nums, int size, int n);

int main()
{
    // char* p1 = getPermutation(2, 1);
    // printf("%s\n", p1);

    // char* p2 = getPermutation(3, 3);
    // printf("%s\n", p2);

    // char* p3 = getPermutation(4, 24);
    // printf("%s\n", p3);

    // char* p4 = getPermutation(6, 40);
    // printf("%s\n", p4);

    int i;
    for (i = 1; i <= 100; i++)
        printf("%d: %s\n", i, getPermutation(6, i));

    return 0;
}

void printArray(int* array, int num)
{
    printf("[");
    while (num-- > 0)
        printf((num > 0) ? "%d," : "%d]\n", *array++);
}

char* getPermutation(int n, int k)
{
    int fact[] = {1,1,2,6,24,120,720,5040,40320};
    char* ret = malloc(sizeof(char) * (n + 1));

    // Keep record of which number is taken
    int nums[n];
    memset(nums, 0, sizeof(nums));

    int i;
    for (i = 0, k -= 1; i < n - 1; i++) {
        ret[i] = getNthNumber(nums, n, k / fact[n-i-1]) + '0';
        k = k % fact[n-i-1];
    }
    // Last digit, whatever is left
    ret[n-1] = getNthNumber(nums, n, 0) + '0';
    ret[n] = '\0';

    return ret;
}

/**
 * Get the Nth number from left that is not taken
 * n == 0 means first
 */
int getNthNumber(int* nums, int size, int n)
{
    int i;
    for (i = 0; i < size; i++) {
        if (nums[i] == 0) {
            if (n == 0) {
                nums[i] = 1;
                return i + 1;
            }
            n--;
        }
    }
    return 0;
}