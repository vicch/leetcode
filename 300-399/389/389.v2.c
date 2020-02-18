#include <stdio.h>

char findTheDifference(char* s, char* t);

int main()
{
    printf("%c\n", findTheDifference("abcd", "abcde"));
    printf("%c\n", findTheDifference("abcd", "abcdd"));

    return 0;
}

char findTheDifference(char* s, char* t)
{
    int i = 0;

    for (; *s != '\0'; s++) i ^= *s;
    for (; *t != '\0'; t++) i ^= *t;

    return i;
}