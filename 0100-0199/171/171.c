#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int titleToNumber(char* s);

int main()
{
    printf("%d\n", titleToNumber("A"));
    printf("%d\n", titleToNumber("B"));
    printf("%d\n", titleToNumber("Z"));
    printf("%d\n", titleToNumber("AA"));
    printf("%d\n", titleToNumber("AB"));
    printf("%d\n", titleToNumber("BA"));

    return 0;
}

int titleToNumber(char* s)
{
    int n = 0;

    while (*s != '\0') {
        n = n * 26 + (*s++ - 'A' + 1);
    }

    return n;
}