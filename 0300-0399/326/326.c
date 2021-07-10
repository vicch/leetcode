#include <stdio.h>
#include <stdlib.h>

typedef int bool;

bool isPowerOfThree(int n);
int cmpInt(const void* a, const void* b);

int main()
{
    printf("%d:%d\n", 27, isPowerOfThree(27));
}

bool isPowerOfThree(int n)
{
    int seq[] = {1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907,43046721,129140163,387420489,1162261467};
    int* p = (int*) bsearch(&n, seq, 20, sizeof(int), cmpInt);
    return p != NULL;
}

int cmpInt(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

// bool isPowerOfThree(int n)
// {
//     if (n % 2 == 0 || n % 5 == 0)
//         return 0;
//     else if (n < 82)
//         return (n == 1 || n == 3 || n == 9 || n == 27 || n == 81);
//     else if (n < 6562)
//         return (n == 243 || n == 729 || n == 2187 || n == 6561);
//     else if (n < 531442)
//         return (n == 19683 || n == 59049 || n == 177147 || n == 531441);
//     else if (n < 43046722)
//         return (n == 1594323 || n == 4782969 || n == 14348907 || n == 43046721);
//     else
//         return (n == 129140163 || n == 387420489 || n == 1162261467);
// }