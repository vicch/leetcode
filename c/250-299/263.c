#include <stdio.h>

typedef int bool;

bool isUgly(int num);

int main()
{
    int i;
    for (i = 1; i <= 100; i++) {
        printf("%d:%d\n", i, isUgly(i));
    }
}

bool isUgly(int num)
{
    while (num % 5 == 0) num /= 5;
    while (num % 3 == 0) num /= 3;
    while (num % 2 == 0) num /= 2;
    
    return (num == 1);

    // for (int i=2; i<6 && num; i++)
    //     while (num % i == 0)
    //         num /= i;
    // return num == 1;
}