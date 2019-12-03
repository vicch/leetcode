#include <stdio.h>
#include <string.h>

#define bool int

#define MAX(a, b) ((a) > (b) ? (a) : (b))

bool wordBreak(char* s, char** wordDict, int wordDictSize);
bool inDict(char* s, int f, int t, char** dict, int dictSize);

int main()
{
    char s1[] = "leetcode";
    char* d1[2];
    d1[0] = "leet";
    d1[1] = "code";
    printf("%d\n", wordBreak(s1, d1, 2));

    char s2[] = "cars";
    char* d2[3];
    d2[0] = "car";
    d2[1] = "ca";
    d2[2] = "rs";
    printf("%d\n", wordBreak(s2, d2, 3));

    char s3[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    char* d3[10];
    d3[0] = "a";
    d3[1] = "aa";
    d3[2] = "aaa";
    d3[3] = "aaaa";
    d3[4] = "aaaaa";
    d3[5] = "aaaaaa";
    d3[6] = "aaaaaaa";
    d3[7] = "aaaaaaaa";
    d3[8] = "aaaaaaaaa";
    d3[9] = "aaaaaaaaaa";
    printf("%d\n", wordBreak(s3, d3, 10));

    char s4[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char* d4[10];
    d4[0] = "aa";
    d4[1] = "aaa";
    d4[2] = "aaaa";
    d4[3] = "aaaaa";
    d4[4] = "aaaaaa";
    d4[5] = "aaaaaaa";
    d4[6] = "aaaaaaaa";
    d4[7] = "aaaaaaaaa";
    d4[8] = "aaaaaaaaaa";
    d4[9] = "ba";
    printf("%d\n", wordBreak(s4, d4, 10));

    return 0;
}

bool wordBreak(char* s, char** wordDict, int wordDictSize)
{
    if (*s == '\0' || wordDictSize == 0)
        return 0;

    int i, j, l;

    // Find longest dict word length
    int maxLen = 0;
    for (i = 0; i < wordDictSize; i++) {
        l = strlen(wordDict[i]);
        maxLen = MAX(l, maxLen);
    }

    l = strlen(s);

    // Init "can arrive" list
    // e.g. string = helloworld, word = hello, then canArrive[5] = 1
    bool canArrive[l + 1];
    memset(canArrive, 0, sizeof(canArrive));
    canArrive[0] = 1;

    for (i = 1; i <= l; i++) {
        for (j = i-1; j >= MAX(i-maxLen, 0); j--) {
            // printf("j = %d, i = %d\n", j, i);
            // printf("can arrive %d = %d\n", j, canArrive[j]);
            // If can arrive at j, check if substring j to i-1 exists in dict
            if (canArrive[j] && inDict(s, j, i, wordDict, wordDictSize)) {
                // printf("can arrive %d = 1\n", i);
                canArrive[i] = 1;
                break;
            }
        }
    }

    return canArrive[l];
}

bool inDict(char* s, int f, int t, char** dict, int dictSize)
{
    int i, j;
    for (i = 0; i < dictSize; i++) {
        for (j = f; j < t && dict[i][j-f]; j++) {
            if (dict[i][j-f] != s[j])
                break;
        }
        if (j == t && dict[i][j-f] == '\0')
            return 1;
    }
    return 0;
}