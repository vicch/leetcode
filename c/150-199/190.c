#include <stdio.h>

void printBinary(unsigned long n);
unsigned long reverseBits(unsigned long n);

int main()
{
    unsigned long a = 1;
    printBinary(a);
    unsigned long b = reverseBits(a);
    printBinary(b);
    printf("%lu\n", b);

    return 0;
}

void printBinary(unsigned long n)
{
    char s[33];
    int i;

    for (i = 31; i >= 0; i--) {
        s[i] = n % 2 + '0';
        n /= 2;
    }
    s[32] = '\0';

    printf("%s\n", s);
}

unsigned long reverseBits(unsigned long n)
{
    unsigned long r = 0;
    int i;

    for (i = 0; i < 32; i++) {
        r = r * 2 + (n % 2);
        n /= 2;
    }

    return r;
}