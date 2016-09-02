#include <stdio.h>

int longestSub(char* s);

int main()
{
    char str[] = "abcadcbb";
    int longest;

    longest = longestSub(str);
    printf("%d\n", longest);

    return 0;
}

int longestSub(char* s)
{
    int chars[128];
    int i, c;
    int start, end; // Current longest substring start and end index
    int len;        // Length of current sub string without repeated character
    int longest;    // Longest length sub string without repeated character

    for (i = 0; i < 128; i++) {
        chars[i] = -1;
    }
    start = end = longest = 0;

    for (i = 0; (c = s[i]) != '\0'; i++) {
        if (chars[c] != -1 && start < chars[c] + 1) {
            start = chars[c] + 1;
        }
        chars[c] = end = i;

        len = end - start + 1;
        if (len > longest) {
            longest = len;
        }
    }

    return longest;
}