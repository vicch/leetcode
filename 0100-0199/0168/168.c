#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convertToTitle(int n);
char* strReverse(char* s);

int main()
{
    printf("%s\n", convertToTitle(1));
    printf("%s\n", convertToTitle(2));
    printf("%s\n", convertToTitle(26));
    printf("%s\n", convertToTitle(27));
    printf("%s\n", convertToTitle(28));

    return 0;
}

char* convertToTitle(int n)
{
    char* s = malloc(sizeof(char) * 10);
    int i = 0;

    while (n > 0) {
        s[i++] = ((n - 1) % 26) + 'A';
        n = (n - 1) / 26;
    }

    s[i] = '\0';

    return strReverse(s);
}

char* strReverse(char* s)
{
    int i, l = strlen(s);
    char* n = malloc(sizeof(s));

    for (i = 0; i < l; i++) {
        n[i] = s[l - i - 1];
    }
    n[l] = '\0';

    return n;
}