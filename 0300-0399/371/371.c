#include <stdio.h>

int getSum(int a, int b);

int main()
{
    printf("%d+%d=%d\n", 1, 2, getSum(1, 2));
    printf("%d+%d=%d\n", 10, 20, getSum(10, 20));
    printf("%d+%d=%d\n", 100, 200, getSum(100, 200));

    return 0;
}

int getSum(int a, int b)
{
    int i;
    int ad, bd, sd; // Binary digits
    int carry = 0, sum = 0;

    for (i = 0; i < 32; i++, a >>= 1, b >>= 1) {
        ad = a & 0x1;
        bd = b & 0x1;

        // Get sum binary
        sd = (ad ^ bd) ^ carry;
        sd <<= i;
        sum |= sd;

        // Get carry binary
        carry = ((ad && bd) || (ad && carry) || (bd && carry));
    }

    return sum;
}