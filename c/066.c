#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize);

int main()
{
    int sizeNew;
    int seq[] = {9,9,9};
    int* seqNew = plusOne(seq, 3, &sizeNew);

    void printDigits(int* digits, int digitsSize);

    printf("%d\n", sizeNew);
    printDigits(seqNew, sizeNew);

    return 0;
}

void printDigits(int* digits, int digitsSize)
{
    int i;

    for (i = 0; i < digitsSize; i++) {
        printf("%d,", digits[i]);
    }
    printf("\n");
}

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int* new = (int*)malloc(sizeof(int) * (digitsSize+1));
    int i, carry;

    carry = 1;
    for (i = digitsSize-1; i >= 0; i--) {
        if (digits[i] == 9 && carry == 1) {
            new[i+1] = 0;
        } else {
            new[i+1] = digits[i] + carry;
            carry = 0;
        }
    }

    if (new[1] == 0 && carry == 1) {
        new[0] = 1;
        *returnSize = digitsSize + 1;
        return new;
    } else {
        *returnSize = digitsSize;
        return &new[1];
    }
}