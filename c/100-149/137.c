#include <stdio.h>

int singleNumber(int* nums, int numsSize);

int main()
{

}

int singleNumber(int* nums, int numsSize)
{
    int a = 0, b = 0, i;
    for (i = 0; i < numsSize; i++) {
        a = (a ^ nums[i]) & ~b;
        b = (b ^ nums[i]) & ~a;
    }
    return a;
}