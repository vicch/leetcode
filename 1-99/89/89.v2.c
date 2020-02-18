#include <stdio.h>
#include <stdlib.h>

void printArray(int* array, int num);
int* grayCode(int n, int* returnSize);

int main()
{
    int s1;
    int* seq1 = grayCode(0, &s1);
    printArray(seq1, s1);

    int s2;
    int* seq2 = grayCode(1, &s2);
    printArray(seq2, s2);

    int s3;
    int* seq3 = grayCode(2, &s3);
    printArray(seq3, s3);

    int s4;
    int* seq4 = grayCode(3, &s4);
    printArray(seq4, s4);

    int s5;
    int* seq5 = grayCode(4, &s5);
    printArray(seq5, s5);

    return 0;
}

void printArray(int* array, int num)
{
    printf("[");
    while (num-- > 0)
        printf((num > 0) ? "%d," : "%d]\n", *array++);
}

/**
 * G(i) = i ^ (i / 2) // Seven gods, how did they notice this ...
 */
int* grayCode(int n, int* returnSize)
{
    *returnSize = 1 << n;
    int* seq = malloc(sizeof(int) * *returnSize);
    int i;
    for (i = 0; i < *returnSize; i++)
        seq[i] = i ^ (i / 2);
    return seq;
}