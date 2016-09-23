#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int* array, int num);

int* grayCode(int n, int* returnSize);
int* grayCodeSub(int start, int digit);
int powerTwo(int n);

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

int* grayCode(int n, int* returnSize)
{
    *returnSize = powerTwo(n);
    return grayCodeSub(0, n);
}

/**
 * start = 000, digit = 1, return: [000, 001]
 * start = 011, digit = 1, return: [011, 010]
 */
int* grayCodeSub(int start, int digit)
{
    int* seq;

    if (digit == 0) {
        seq = malloc(sizeof(int));
        *seq = start;

    } else {
        int hsize = powerTwo(digit-1);
        int* seq1 = grayCodeSub(start, digit-1);
        start = seq1[hsize-1] ^ hsize;
        int* seq2 = grayCodeSub(start, digit-1);

        seq = malloc(sizeof(int) * hsize * 2);
        memcpy(seq, seq1, sizeof(int) * hsize);
        memcpy(seq+hsize, seq2, sizeof(int) * hsize);

        free(seq1);
        free(seq2);
    }

    return seq;
}

int powerTwo(int n)
{
    int i = 1;
    i <<= n;
    return i;
}