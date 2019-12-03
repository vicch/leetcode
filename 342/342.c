#include <stdio.h>
#include <stdlib.h>

typedef int bool;

bool isPowerOfFour(long n);
int cmpLong(const void* a, const void* b);

int main()
{
    printf("%ld:%d\n", 64L, isPowerOfFour(64L));

    return 0;
}

bool isPowerOfFour(long n)
{
    long seq[] = {1,4,16,64,256,1024,4096,16384,65536,262144,1048576,4194304,16777216,67108864,268435456,1073741824};
    long* p = (long*) bsearch(&n, seq, 16, sizeof(long), cmpLong);
    return p != NULL;
}

int cmpLong(const void* a, const void* b)
{
    return (*(long*)a - *(long*)b);
}