#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseString(char* s);

int main()
{
    char* str1 = malloc(sizeof(char) * 6);
    strcpy(str1, "hello");
    printf("%s\n", reverseString(str1));

    return 0;
}

char* reverseString(char* s)
{
    int l = strlen(s), i;
    char tmp;

    for (i = 0; i < l / 2; i++) {
        tmp = s[i];
        s[i] = s[l-i-1];
        s[l-i-1] = tmp;
    }

    return s;
}