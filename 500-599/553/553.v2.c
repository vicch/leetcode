// Problem:
// Given a list of positive integers, the adjacent integers will perform the
// float division. For example, [2,3,4] -> 2/3/4. You can add any number of
// parenthesis at any position to change the priority of operations. Find out
// how to add parenthesis to get the maximum result, and return the
// corresponding expression in string format. Your expression should NOT
// contain redundant parenthesis.
// - The length of the input array is [1, 10].
// - Elements in the given array will be in range [2, 1000].
// - There is only one optimal division for each test case.
// 
// Example:
// Input: [1000,100,10,2]
// Output: "1000/(100/10/2)"
// 
// Solution:
// To maximize the result, it should multiply as much numbers as possible. No
// matter how the parenthesis are placed, the first number is always divided
// by the second number. So "n1 / (n2 / n3 / ...)" will be the max result
// possible.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* optimalDivision(int* nums, int numsSize);

int main()
{
    int nums1[] = {1000, 100, 10, 2};
    printf("%s\n", optimalDivision(nums1, 4));

    return 0;
}

/********** Solution **********/

char* itoa(int n);

char* optimalDivision(int* nums, int numsSize)
{
    int i;
    char* res = malloc(sizeof(char) * 100);

    for (i = 0; i < numsSize; i++) {
        if (i > 0)
            strcat(res, "/");
        if (i == 1 && numsSize > 2)
            strcat(res, "(");
        strcat(res, itoa(nums[i]));
    }

    if (numsSize > 2)
        strcat(res, ")");

    return res;
}

char* itoa(int n)
{
    // 4 digits plus null char
    char* s = malloc(sizeof(char) * 5);
    sprintf(s, "%d", n);
    return s;
}