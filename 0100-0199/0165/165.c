#include <stdio.h>

int compareVersion(char* version1, char* version2);
char* getVersion(int* v, char* start);

int main()
{
    // printf("%s, %s, %d\n", "1.0", "1.1", compareVersion("1.0", "1.1"));
    printf("%s, %s, %d\n", "1", "1.1", compareVersion("1", "1.1"));
    // printf("%s, %s, %d\n", "0.1", "1.0", compareVersion("0.1", "1.0"));

    return 0;
}

int compareVersion(char* version1, char* version2)
{
    int v1 = 0, v2 = 0;

    while (version1 != NULL || version2 != NULL) {
        version1 = getVersion(&v1, version1);
        version2 = getVersion(&v2, version2);
        if (v1 > v2)
            return 1;
        else if (v1 < v2)
            return -1;
    }

    return 0;
}

char* getVersion(int* v, char* str)
{
    char c;
    *v = 0;

    if (str == NULL)
        return 0;

    while ((c = *str) != '\0' && c != '.') {
        *v = *v * 10 + (c - '0');
        str++;
    }

    str = (c == '\0') ? NULL : str + 1;

    return str;
}