#include <stdio.h>
#include <stdlib.h>

char* countAndSay(int n);
char* convert(char* str);

int main()
{
    printf("%s\n", countAndSay(30));

    return 0;
}

char* countAndSay(int n)
{
    char* str = NULL;

    for (; n > 0; n--) {
        str = convert(str);
    }

    return str;
}

char* convert(char* str)
{
    int i, j, k;
    char c;
    char* new = malloc(10000);

    if (str == NULL)
        return "1";

    c = str[0];
    j = 1;
    k = 0;
    for (i = 1; str[i] != '\0'; i++) {
        if (str[i] == c) {
            j++;
        } else {
            new[k++] = '0' + j;
            new[k++] = c;
            c = str[i];
            j = 1;
        }
    }
    new[k++] = '0' + j;
    new[k++] = c;
    new[k] = '\0';

    return new;
}