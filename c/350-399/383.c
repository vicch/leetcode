#include <stdio.h>

typedef int bool;

bool canConstruct(char* ransomNote, char* magazine);

int main()
{
    printf("%d\n", canConstruct("aa", "ab"));
    printf("%d\n", canConstruct("aa", "aab"));

    return 0;
}

bool canConstruct(char* ransomNote, char* magazine)
{
    int chars[256];
    int i;

    for (i = 0; i < 256; i++)
        chars[i] = 0;

    for (; *ransomNote != '\0'; ransomNote++)
        chars[*ransomNote]--;

    for (; *magazine != '\0'; magazine++)
        chars[*magazine]++;

    for (i = 0; i < 256; i++)
        if (chars[i] < 0)
            return 0;

    return 1;
}