#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool int

void printStrings(char** strs, int count);

bool wordBreak(char* s, char** wordDict, int wordDictSize);
int cmpLen(const void* a, const void* b);
bool wordBreakSub(char* s, char** wordDict, int wordDictSize);
int beginWith(char* s, char* w);

int main()
{
    // char s1[] = "leetcode";
    // char* d1[2];
    // d1[0] = "leet";
    // d1[1] = "code";
    // printf("%d\n", wordBreak(s1, d1, 2));

    // char s2[] = "cars";
    // char* d2[3];
    // d2[0] = "car";
    // d2[1] = "ca";
    // d2[2] = "rs";
    // printf("%d\n", wordBreak(s2, d2, 3));

    // char s3[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    // char* d3[10];
    // d3[0] = "a";
    // d3[1] = "aa";
    // d3[2] = "aaa";
    // d3[3] = "aaaa";
    // d3[4] = "aaaaa";
    // d3[5] = "aaaaaa";
    // d3[6] = "aaaaaaa";
    // d3[7] = "aaaaaaaa";
    // d3[8] = "aaaaaaaaa";
    // d3[9] = "aaaaaaaaaa";
    // printf("%d\n", wordBreak(s3, d3, 10));

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

void printStrings(char** strs, int count)
{
    while (count-- > 0)
        printf("%s\n", *(strs++));
}

bool wordBreak(char* s, char** wordDict, int wordDictSize)
{
    if (*s == '\0' || wordDictSize == 0) return 0;

    qsort(wordDict, wordDictSize, sizeof(char*), cmpLen);

    printf("dict =\n");
    printStrings(wordDict, wordDictSize);

    char* newDict[wordDictSize];
    int i, j;

    // If a dict word is breakable by previous dict words, it is redundant
    for (i = j = 0; i < wordDictSize; i++) {
        if (!wordBreakSub(wordDict[i], newDict, j))
            newDict[j++] = wordDict[i];
    }

    printf("new dict =\n");
    printStrings(newDict, j);

    return wordBreakSub(s, newDict, j);
}

int cmpLen(const void* a, const void* b)
{
    return (strlen(*(char**)a) - strlen(*(char**)b));
}

bool wordBreakSub(char* s, char** wordDict, int wordDictSize)
{
    // if (*s == '\0' || wordDictSize == 0) return 0;

    int i, l;
    for (i = 0; i < wordDictSize; i++) {
        l = beginWith(s, wordDict[i]);
        // String ends or sub-string is breakable
        if (l && (s[l] == '\0' || wordBreakSub(s + l, wordDict, wordDictSize)))
            return 1;
    }

    return 0;
}

int beginWith(char* s, char* w)
{
    int l;
    // printf("string=%s, word=%s\n", s, w);
    for (l = 0; *s && *w && *s == *w; l++, s++, w++);
    return (*w == '\0') ? l : 0;
}