#include <stdio.h>
#include <stdlib.h>

char* longestPalindrome(char* s);
char* getSubString(char *s, int f, int t);

int main()
{
    char str[] = "ccc";
    char *res;

    res = longestPalindrome(str);
    printf("%s\n", res);

    return 0;
}

char* longestPalindrome(char* s)
{
    char *longestsub;
    int i, j, len, longestlen;

    
    longestlen = 1;
    longestsub = getSubString(s, 0, 0);

    // For "abcba" style
    i = 0;
    while (s[i] != '\0' && i < 1000) {
        j = len = 1;
        while ((i - j >= 0) && (i + j < 1000) && (s[i-j] == s[i+j])) {
            len += 2;
            if (len > longestlen) {
                longestlen = len;
                longestsub = getSubString(s, i-j, i+j);
            }
            j++;
        }
        i++;
    }

    // For "abccba" style
    i = 0;
    while ((s[i] != '\0') && (s[i+1] != '\0') && (i + 1 < 1000)) {
        if (s[i+1] == s[i]) {
            len = 2;
            if (longestlen < len) {
                longestlen = len;
                longestsub = getSubString(s, i, i+1);
            }
            j = 1;
            while ((i - j >= 0) && (i + j + 1 < 1000) && (s[i-j] == s[i+j+1])) {
                len += 2;
                if (len > longestlen) {
                    longestlen = len;
                    longestsub = getSubString(s, i-j, i+j+1);
                }
                j++;
            }
        }
        i++;
    }

    return longestsub;
}

char* getSubString(char *s, int f, int t)
{
    char *sub = malloc(sizeof(char) * (t-f+2));
    int i;

    for (i = 0; i <= t-f; i++) {
        sub[i] = s[f+i];
    }
    sub[i] = '\0';

    return sub;
}