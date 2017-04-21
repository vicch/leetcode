// Problem:
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
// For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
// ugly numbers. Write a program to find the n-th ugly number. Note that 1 is
// typically treated as an ugly number, and n does not exceed 1690.

#include <stdio.h>
#include <string.h>

int nthUglyNumber(int n);

int main()
{
    printf("%d\n", nthUglyNumber(100));

    return 0;
}

/********** Solution **********/

int nthUglyNumber(int n)
{
    unsigned long two[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
    unsigned long three[] = {1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049, 177147, 531441, 1594323, 4782969, 14348907, 43046721, 129140163, 387420489, 1162261467};
    unsigned long five[] = {1, 5, 25, 125, 625, 3125, 15625, 78125, 390625, 1953125, 9765625, 48828125, 244140625, 1220703125};

    unsigned long num;

    char map[2123366401];
    memset(map, 0, sizeof(map));

    int i, j, k;

    for (i = 0; i < 31; i++)
        for (j = 0; j < 20; j++)
            for (k = 0; k < 14; k++)
                if ((num = two[i] * three[j] * five[k]) < 2123366401)
                    map[num] = 1;

    for (i = 1; n > 0; i++)
        if (map[i])
            n--;

    return i;
}