#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxArea(int* height, int heightSize);

int main()
{
    int seq[] = {3,5,1,2,4};
    printf("%ld\n", maxArea(seq, 5));

    return 0;
}

int maxArea(int* height, int heightSize)
{
    int* a = height;
    int* b = height + (heightSize - 1);
    int max = MIN(*a, *b) * (heightSize - 1);

    while (a < b) {
        if (*a < *b) a++;
        else b--;

        max = MAX(max, MIN(*a, *b) * (b - a));
    }

    return max;
}