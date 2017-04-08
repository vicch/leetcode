// Question:
// Given a non negative integer number num. For every numbers i in the range
// 0 ≤ i ≤ num calculate the number of 1's in their binary representation and
// return them as an array. Example: For num = 5 should return [0,1,1,2,1,2].
// 
// Solution:
// The numbers of 1's form a recursive sequence:
// 0
// 1(0+1)
// 1(0+1), 2(1+1)
// 1(0+1), 2(1+1), 2(1+1), 3(2+1)
// ...
// Use 2 cursors:
// - i runs from head to tail, setting value as s[j] + 1
// - j runs from head to middle (of full 2^n sequence), and returns to head to
// start again
//
// Improvement:
// j is actually i&(i-1)

#include <stdio.h>
#include <stdlib.h>

void printArray(int* seq, int count);
int* countBits(int num, int* returnSize);

int main()
{
    int s1;
    int* a1 = countBits(10, &s1);
    printArray(a1, s1);

    return 0;
}

void printArray(int* seq, int count)
{
    while (count-- > 0) {
        printf((count > 0) ? "%d," : "%d", *seq++);
    }
    printf("\n");
}

int* countBits(int num, int* returnSize)
{
    *returnSize = num + 1;
    int* array = malloc(sizeof(int) * *returnSize);
    int i, j;

    array[0] = 0;
    for (i = 1, j = 0; i < *returnSize; i++, j++) {
        if (j >= (i + 1) / 2)
            j = 0;
        array[i] = array[j] + 1;
    }

    return array;
}