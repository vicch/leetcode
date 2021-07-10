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
    int chars[26];
    int i;

    for (i = 0; i < 26; i++)
        chars[i] = 0;

    for (; *s != '\0'; s++) chars[*s - 'a']--;
    for (; *t != '\0'; t++) chars[*t - 'a']++;

    for (i = 0; i < 26; i++)
        if (chars[i] == 1)
            return i + 'a';

    return 0;
}