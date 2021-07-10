#include <stdio.h>

int firstUniqChar(char* s);

int main()
{
    printf("%d\n", firstUniqChar("leetcode"));
    printf("%d\n", firstUniqChar("loveleetcode"));
    printf("%d\n", firstUniqChar(""));
    printf("%d\n", firstUniqChar("aabbccdde"));

    return 0;
}

int firstUniqChar(char* s)
{
    int count[26];
    int i;

    for (i = 0; i < 26; i++)
        count[i] = 0;

    for (i = 0; s[i] != '\0'; i++)
        count[s[i] - 'a']++;

    for (i = 0; s[i] != '\0'; i++)
        if (count[s[i] - 'a'] == 1)
            return i;

    return -1;
}