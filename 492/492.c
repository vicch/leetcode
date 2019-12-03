// Problem:
// Given a specific rectangular area, design a rectangular web page, whose
// length L and width W satisfy the following requirements:
// - The area designed must equal to the given target area.
// - The width should not be larger than the length.
// - The difference between length and width should be as small as possible.
// 
// Example:
// Input: 4
// Output: [2, 2]
// 
// Solution:
// The width and length should be as close to the area's square root as
// possible. Decrease the width from the floor of the square root, when width
// is a factor of area (area % width == 0), the solution is found.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* constructRectangle(int area, int* returnSize);
void printArray(int* seq, int count);

int main()
{
    int rs1;
    printArray(constructRectangle(4, &rs1), 2);
    return 0;
}

void printArray(int* seq, int count)
{
    while (count-- > 0)
        printf((count > 0) ? "%d," : "%d", *seq++);
    printf("\n");
}

/********** Solution **********/

int* constructRectangle(int area, int* returnSize)
{
    int *ret, i;

    *returnSize = 2;
    ret = malloc(sizeof(int) * 2);

    for (i = sqrt(area); i > 0; i--)
        if (area % i == 0) {
            ret[0] = area / i, ret[1] = i;
            break;
        }

    return ret;
}