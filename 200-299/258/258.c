#include <stdio.h>

int addDigits(int num);

int main()
{
    int i;
    for (i = 1; i <= 1000; i++) {
        printf("%d:%d\n", i, addDigits(i));
    }
}

int addDigits(int num)
{
    return num % 9;
}