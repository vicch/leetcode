#include <stdio.h>

typedef int bool;

void transIntRepeat(int n, int time);
int transInt(int n);
bool isHappy(int n);

int main()
{
    int i;

    // for (i = 0; i < 100; i++) {
    //     transIntRepeat(i, 20);
    // }

    for (i = 0; i < 100; i++) {
        printf("%d:%d\n", i, isHappy(i));
    }

    return 0;
}

void transIntRepeat(int n, int time)
{
    while (time-- > 0) {
        printf("%d->", n);
        n = transInt(n);
    }
    printf("\n");
}

int transInt(int n)
{
    int i = 0;

    while (n > 0) {
        i += (n % 10) * (n % 10);
        n /= 10;
    }

    return i;
}

bool isHappy(int n)
{
    while (n > 99) {
        n = transInt(n);
    }

    if (n < 20)
        return (n == 1 || n == 7 || n == 10 || n == 13 || n == 19);
    else if (n < 45)
        return (n == 23 || n == 28 || n == 31 || n == 32 || n == 44);
    else if (n < 80)
        return (n == 49 || n == 68 || n == 70 || n == 79);
    else
        return (n == 82 || n == 86 || n == 91 || n == 94 || n == 97);
}