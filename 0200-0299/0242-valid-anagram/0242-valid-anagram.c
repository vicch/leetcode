#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;

int cmpChar(const void * a, const void * b);
bool isAnagram(char* s, char* t);

int main()
{
    printf("%s,%s:%d\n", "anagram", "nagaram", isAnagram("anagram", "nagaram"));
    printf("%s,%s:%d\n", "rat", "car", isAnagram("rat", "car"));

    return 0;
}

int cmpChar(const void * a, const void * b)
{
    return (*(char*)a - *(char*)b);
}

bool isAnagram(char* s, char* t)
{
    int sl = strlen(s);
    int tl = strlen(t);

    if (sl != tl)
        return 0;

    char* sc = malloc(sizeof(char) * sl);
    char* tc = malloc(sizeof(char) * tl);

    strcpy(sc, s);
    strcpy(tc, t);

    qsort(sc, sl, sizeof(char), cmpChar);
    qsort(tc, tl, sizeof(char), cmpChar);

    for (; *sc != '\0'; sc++, tc++) {
        if (*sc != *tc)
            return 0;
    }

    return 1;
}