#include <stdio.h>

int strStr(char* haystack, char* needle);
int strLen(char* str);

int main()
{
    printf("%d\n", strStr("aaaa", "aaab"));

    return 0;
}

int strStr(char* haystack, char* needle)
{
    int i, j;

    if (needle[0] == '\0')
        return 0;

    if (haystack[0] == '\0')
        return -1;

    for (i = 0; haystack[i] != '\0'; i++) {
        if (strLen(haystack+i) < strLen(needle))
            return -1;
        for (j = 0; (needle[j] != '\0' && haystack[i+j] == needle[j]); j++) {
            if (needle[j+1] == '\0')
                return i;
        }
    }

    return -1;
}

int strLen(char* str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        ;

    return i;
}